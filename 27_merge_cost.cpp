#include <bits/stdc++.h>
using namespace std;


int minMergeCost(int i,int j,vector<int> arr,vector<vector<int>> &dp,vector<vector<int>> &v){
    if (i == j)
        return 0;

    if (v[i][j])
        return dp[i][j];

    v[i][j] = 1;
    int& x = dp[i][j];

    x = INT_MAX;

    int tot = 0;
    for (int k = i; k <= j; k++)
        tot += arr[k];

    for (int k = i + 1; k <= j; k++) {
        x = min(x, tot + minMergeCost(i, k - 1, arr,dp,v)
                       + minMergeCost(k, j, arr,dp,v));
    }

    return x;
}

int main(){
    int n,y;
    cin>> n;
    vector<vector<int>> dp(n,vector<int>(n));
    vector<vector<int>> v(n,vector<int>(n));
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>> y;
        arr.push_back(y);
    }
    cout<< minMergeCost(0,n-1,arr,dp,v);
}