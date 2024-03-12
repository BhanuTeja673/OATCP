#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

ll countWays(ll target, ll sum, vector<int> &memo) {
    if (target == sum) {
        return 1;
    }
    if (memo[sum] != -1) {
        return memo[sum];
    }
    ll ways = 0;
    for (int i = 1; i <= 6; i++) {
        if ((sum + i) <= target) {
            ways += countWays(target, sum + i, memo) % MOD;
        } else {
            break;
        }
    }
    return memo[sum] = ways % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");

    ll testCases;
    cin >> testCases;

    while (testCases--) {
        ll target;
        cin >> target;

        vector<int> memo(target + 1, -1);

        if (target > 0) {
            ll ways = countWays(target, 0, memo);
            cout << ways << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
