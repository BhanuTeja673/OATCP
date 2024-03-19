#include <bits/stdc++.h>
using namespace std;

int countCompatiblePairs(int boyIndex, int girlIndex, vector<int> &boys, vector<int> &girls, int boysCount, int girlsCount, vector<vector<int>>&dp){
    if (boyIndex >= boysCount || girlIndex >= girlsCount) {
        return 0;
    }
    if (dp[boyIndex][girlIndex] != -1) return dp[boyIndex][girlIndex];
    int takingThisPair = INT_MIN, notTakingThisPair;
    if (boys[boyIndex] == girls[girlIndex] || abs(boys[boyIndex] - girls[girlIndex]) == 1) {
        takingThisPair = 1 + countCompatiblePairs(boyIndex + 1, girlIndex + 1, boys, girls, boysCount, girlsCount, dp);
    }
    int moveBoy = countCompatiblePairs(boyIndex + 1, girlIndex, boys, girls, boysCount, girlsCount, dp);
    int moveGirl = countCompatiblePairs(boyIndex, girlIndex + 1, boys, girls, boysCount, girlsCount, dp);
    notTakingThisPair = max(moveBoy, moveGirl);
    return dp[boyIndex][girlIndex] = max(takingThisPair, notTakingThisPair); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream inputFile("input.txt");
    ofstream outputFile("../output/output.txt");
    int boysCount;
    cin >> boysCount;
    vector<int> boys, girls;
    for (int i = 0; i < boysCount; i++) {
        int x;
        cin >> x;
        boys.push_back(x);
    }
    int girlsCount;
    cin >> girlsCount;
    for (int i = 0; i < girlsCount; i++) {
        int x;
        cin >> x;
        girls.push_back(x);
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    vector<vector<int>> dp(boysCount + 1, vector<int>(girlsCount + 1, -1));
    int ans = countCompatiblePairs(0, 0, boys, girls, boysCount, girlsCount, dp);
    cout << ans;
    return 0;
}
