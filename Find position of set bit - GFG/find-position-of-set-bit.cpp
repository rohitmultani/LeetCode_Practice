//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int isPowerOfTwo(int n)
{
    return n && (!(n & (n - 1)));
}
    int findPosition(int N) {
        if(!isPowerOfTwo(N))
        return -1;
        int count=1;
        while(!(N&1)){
            N=N>>1;
            count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends