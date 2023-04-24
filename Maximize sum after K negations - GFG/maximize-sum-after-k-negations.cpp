//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        int i;
        int count=0;
        for(i=0;i<n;i++){
            if(a[i]<0)
            count++;
        }
        if(count > k) {
            for(i=0;i<k;i++)
            a[i]=abs(a[i]);
        }
        
        else {
            for(i=0;i<count;i++)
            a[i]=abs(a[i]);
            
            k = k - count;
            sort(a,a+n);
            
            if(k&1)
            a[0]=-a[0];
            
        }
        
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends