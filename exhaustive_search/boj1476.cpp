// boj 1476 날짜 계산
#include <iostream>

using namespace std;

int main() {
    int e = 1, s = 1, m = 1, year = 1;
    int E, S, M;

    cin >> E >> S >> M;

    while (true) {
        if (e == E && s == S && m == M) {
            break;
        }
        year++;
        e = (e % 15) + 1;
        s = (s % 28) + 1;
        m = (m % 19) + 1;
    }
    cout << year;
    return 0;
}
