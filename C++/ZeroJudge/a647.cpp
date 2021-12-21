#include <iostream>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m, p;
    float rate;
    while (cin >> n) {
        for (int i = 0; i < n; i ++) {
            cin >> m >> p;
            rate = 100.0 * (p - m) / m;
            // 疑似是浮點數的誤差 要修正
            if (rate > 0.0)
                rate += 0.00001;
            else if (rate < 0.0)
                rate -= 0.00001;
            printf("%.2f%% ", rate);
            if (rate <= -7.0 || rate >= 10.0)
                printf("dispose\n");
            else
                printf("keep\n");
        }
    }
    return 0;
}
