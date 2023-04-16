// boj 1107 리모컨
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_possible(int channel, const vector<bool>& broken_buttons) {
    if (channel == 0) {
        return !broken_buttons[0];
    }
    
    while (channel > 0) {
        int digit = channel % 10;
        if (broken_buttons[digit]) {
            return false;
        }
        channel /= 10;
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> broken_buttons(10, false);
    for (int i = 0; i < M; i++) {
        int button;
        cin >> button;
        broken_buttons[button] = true;
    }

    int ans = abs(N - 100);
    for (int channel = 0; channel <= 1000000; channel++) {
        if (is_possible(channel, broken_buttons)) {
            int cost = to_string(channel).size() + abs(N - channel);
            ans = min(ans, cost);
        }
    }

    cout << ans << endl;
    return 0;
}
/*
문제 풀이
이 문제는 브루트 포스 알고리즘을 사용하여 모든 가능한 경우를 탐색하며 해결할 수 있습니다. 다음과 같은 방법으로 해결해볼 수 있습니다.

1.고장난 버튼을 입력 받아서 사용 가능한 버튼만 따로 저장합니다.
2. 수빈이가 이동하려고 하는 채널 N과 현재 채널 100의 차이를 구합니다. 이 차이만큼 +와 - 버튼을 눌러 이동할 수 있으므로, 이 값을 초기 답으로 설정합니다.
3. 모든 채널에 대해 반복문을 돌면서, 각 채널에 대해 다음 작업을 수행합니다.
    a. 채널 번호를 문자열로 변환하고, 모든 문자(숫자)에 대해 사용 가능한 버튼인지 확인합니다. 사용할 수 없는 버튼이 있다면, 이 채널로 이동할 수 없으므로 다음 채널로 넘어갑니다.
    b. 이 채널로 이동할 수 있다면, 이 채널로 이동하기 위해 숫자 버튼을 누른 횟수(문자열의 길이)와 이 채널에서 목표 채널까지 + 또는 - 버튼을 누른 횟수의 합을 구합니다.
    c. 이 값이 현재까지 구한 답보다 작으면, 답을 업데이트합니다.
4. 최종적으로 구한 답을 출력합니다.
이 방법을 사용하면 모든 가능한 경우를 확인하여 문제를 해결할 수 있습니다. 시간 복잡도는 채널의 개수(500,000)에 비례하며, 충분히 계산 가능한 범위입니다.
*/
