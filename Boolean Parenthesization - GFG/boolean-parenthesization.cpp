//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mod = 1003;
long long f(int i,int j, int isTrue,string &exp,vector<vector<vector<long long>>> &dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue){
            return exp[i]=='T';
        }
        else return exp[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1)
    return dp[i][j][isTrue];
    long long ways=0;
    for(int ind = i+1;ind<=j-1;ind+=2){
        long long LT = f(i,ind-1,1,exp,dp);
        long long RT = f(ind+1,j,1,exp,dp);
        long long LF = f(i,ind-1,0,exp,dp);
        long long RF = f(ind+1,j,0,exp,dp);

        if(exp[ind]=='&'){
            if(isTrue)
            ways=(ways+(RT*LT)%mod)%mod;
            else
            ways = (ways + (RT*LF)%mod + (RF*LT)%mod + (RF*LF)%mod)%mod;
        }
        else if(exp[ind]=='|'){
            if(isTrue)
            ways=(ways+(RT*LT)%mod + (LT*RF)%mod + (LF*RT)%mod )%mod;
            else
            ways = (ways + (RF*LF)%mod)%mod;
        }
        else {
            if(isTrue)
            ways=(ways+(RT*LF)%mod +  (LT*RF)%mod )%mod;
            else
            ways = (ways + (RT*LT)%mod + (RF*LF)%mod)%mod;
        }
    }
    return dp[i][j][isTrue]=ways;
}

    int countWays(int N, string exp){
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
    return f(0,exp.size()-1,1,exp,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends