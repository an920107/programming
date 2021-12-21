#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, input, res, cur;
    cin >> n >> input;
    res = input;
    cur = input;
    for (int i = 1; i < n; i ++) {
        cin >> input;
        cur = max(input + cur, input);
        res = max(res, cur);
    }
    cout << res << "\n";
    return 0;
}

/**
 * 此題使用到 動態規劃 (Dynamic Programming)
 * 
 * 若知道 arr[0] ~ arr[i - 1] 的最大區間和
 * 則應該能推得 arr[0] ~ arr[i] 的最大區間和
 * 
 * 此時分成兩種情況：
 *      1. 這個最大區間不包含 arr[i]
 *      2. 這個最大區間包含 arr[i]
 * 
 * 情況 1. 即 arr[0] 到 arr[i - 1] 的最大區間和，為已知條件。
 * 情況 2. 此時必須先知道前一步的 arr[i - 1] 是否包含於最大區間，
 *      那又必須再往回推...（數學歸納法的感覺），同時將 arr[i] 設為新的開始。
 *      為了不要每次都從頭開始計算最大區間和是多少，可以從最一開始就比較每一個區間，
 *      將截至當前 arr[i] 為止的最大區間和記錄下來。
 * 
 * 因此回到最一開始，當 i = 0 時，最大區間和當然為 arr[0]，
 * 當 i = 1 時，依以下步驟進行：
 *      1. 原最大區間和為 arr[0]，因此比較加上 arr[1] 後 arr[0] ~ arr[1] 是否比 arr[1] 大，
 *          若「是」則為上述「情況 1」；
 *          若「否」則為上述「情況 2」，於是將此 arr[1] 設為新的最大區間的開始。
 *      2. 比較當前最大區間和與過去的最大區間和，將最大值取代掉原最大區間和。
 * 
 * 而後以此類推，最後即可得到最大區間和。
 * 
 * 以 arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4} 為例：
 * 設 cur 為當前最大區間和、res 為截至當前為止全部的最大區間和
 * i = 0, arr[0] = -2:
 *      res = -2, cur = -2
 * i = 1, arr[1] = 1:
 *      cur + arr[1] = -1 > cur
 *          => cur := cur + arr[1] = -1
 *      cur > res
 *          => res := cur
 * i = 2, arr[2] = -3:
 *      cur +
 */