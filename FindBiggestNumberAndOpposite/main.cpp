#include <ctime>
#include <iostream>
#include <algorithm>

/* Global Variable */
int N;
int Length;
int Arr[100000];
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
    std::cin >> Length;
    for (int i = 0; i < Length; i++) {
        std::cin >> Arr[i];
    }
}

void solve() {
    std::sort(Arr, Arr + Length);
    Result = 0;
    for (int i = 0; i < Length; i++) {
        int *p = std::find(Arr + i + 1, Arr + Length, -Arr[i]);
        if (p != Arr + Length) {
            Result = *p;
            return;
        }
    }
}

void output() {
    std::cout << Result << std::endl;
}
