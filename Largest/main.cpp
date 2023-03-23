#include <ctime>
#include <iostream>
#include <algorithm>
#include <cmath>

/* Global Variable */
int N;
int MSquares;
int NSquares;
int Result;

/* Function prototype */
void input();
void solve();
void output();

/* Source code */
int main() {
    clock_t tStart = clock();
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int T;
    std::cin >> T;
    N = T;
    while (T--) {
        input();
        solve();
        output();
    }
    printf("Time taken:%.10fs\r\n",
           (double)(clock() - tStart) / CLOCKS_PER_SEC);
    fclose(stdin);
    fclose(stdout);
    return (0);
}

void input() {
    std::cin >> MSquares >> NSquares;
}

void solve() {
    Result = 0;
    int FixedArea = NSquares * 4;
    int MaxArea = FixedArea + MSquares * 1;
    int root = (int)sqrt(MaxArea);
    int FixedRoot = (int)sqrt(NSquares);
    int start = 0;
    if ((FixedRoot + 1) * (FixedRoot + 1) * 4 == MaxArea) {
        Result = (FixedRoot + 1) * 2;
        return;
    } else if ((FixedRoot + 1) * (FixedRoot + 1) * 4 >  MaxArea) {
        MaxArea -= (NSquares - FixedRoot*FixedRoot) * 4;
        start = FixedRoot*2;
    } else {
        start = FixedRoot*2;
    }
    for (int i = start; i < root + 2; i++) {
        if (MaxArea == i*i) {
            Result = i;
            return;
        } else if (MaxArea < i*i) {
            Result = i - 1;
            return;
        }
    }
}

void output() {
    std::cout << Result << std::endl;
}
