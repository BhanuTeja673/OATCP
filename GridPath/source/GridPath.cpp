#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll f(int i, int j, vector<vector<char>>& grid, int n,vector<vector<int>> &dp) {
    if (i < 0 || j < 0 || i >= n || j >= n) {
        return 0;
    }
    if (grid[i][j]=='*') {
        return 0; 
    }
    if (i == n-1 && j == n-1) {
        return 1; 
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    ll right = f(i,j + 1,grid,n,dp)%mod;
    ll down = f(i + 1,j,grid,n,dp)%mod;
    
    return dp[i][j] = (down+right)%mod;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input2.txt");
    ofstream cout("../output/output2.txt"); 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<vector<char>> grid(n,vector<char> (n,'0'));
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char c;
                cin >> c;
                grid[i][j] =c;
            }
        }
        ll ans = f(0,0,grid,n,dp);
        cout << ans << endl;

    }
    return 0;
}
