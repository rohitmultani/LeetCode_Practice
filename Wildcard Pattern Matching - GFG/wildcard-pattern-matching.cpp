//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string text)
    {
        int n = pattern.size();
   int m = text.size();
   // vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
   vector<bool> prev(m+1,false);
   vector<bool> curr(m+1,false);

   prev[0]=true;

   for(int j=1;j<=m;j++)
   prev[j]=false;

   // for(int i=1;i<=n;i++){
   //    bool flag=true;
   //   for (int ii = 1; ii <= i; ii++) {
   //     if (pattern[ii-1] != '*'){
   //       flag=false;
   //       break;
   //     }
   //   }
   //   dp[i][0]=flag;
   // }

   for(int i=1;i<=n;i++){

      bool flag=true;
     for (int ii = 1; ii <= i; ii++) {
       if (pattern[ii-1] != '*'){
         flag=false;
         break;
       }
     }
     curr[0]=flag;
   


      for(int j=1;j<=m;j++){
         if(pattern[i-1]==text[j-1] || pattern[i-1] == '?'){
             curr[j]=prev[j-1];
            }

            else if(pattern[i-1]=='*'){
               curr[j] = prev[j] | curr[j-1];
            }

           else curr[j]=false;
      }
      prev=curr;
   }
   return prev[m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends