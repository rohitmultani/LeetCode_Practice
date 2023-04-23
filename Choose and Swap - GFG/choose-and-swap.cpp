//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        int i,j;
        int chk[26];
        int n = a.length();
        
        for(int i=0;i<26;i++){
            chk[i]=-1;
        }
        
        for(int i=0;i<n;i++){
            if(chk[a[i]-'a']==-1)
            chk[a[i]-'a']=i;
        }
        
        for(i=0;i<n;i++){
            bool flag=false;
            for( j=0;j<a[i]-'a';j++){
                if(chk[j]>chk[a[i]-'a']){
                    flag=true;
                    break;
                }
            }
            
            if(flag)
            break;
        }
        
        
        if(i<n-1){
            char ch1=a[i];
            char ch2=char(j+'a');
            for(int i=0;i<n;i++){
                if(a[i]==ch1){
                    a[i]=ch2;
                }
                else if(a[i]==ch2)
                a[i]=ch1;
            }
        }
        return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends