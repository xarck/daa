#include <bits/stdc++.h>
using namespace std;

int lcs(string x,string y,int m,int n, vector<vector<int>> dp){
    if(n==0||m==0)
        return 0;
    if(dp[m][n]!=-1)
        return dp[m][n];
    if(x[m-1]==y[n-1]){
        dp[m-1][n-1] = 1+ lcs(x,y,m-1,n-1,dp);
        return dp[m-1][n-1];
    }
    else{
        dp[m-1][n-1] = max(lcs(x,y,m-1,n,dp),lcs(x,y,m,n-1,dp));
        return dp[m-1][n-1];
    }
}

int main(){
    string h = "hello";
    string w = "world";
    int m = h.size(),n=w.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    cout<< lcs(h,w,m,n,dp);
}