//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans;
        int minCost=0;
        int maxCost=0;
        
        sort(candies,candies+N);
        
        int count=0;
        int i=0;
        while(count<N){
            minCost+=candies[i];
            count++;
            
            if(count==N)
            break; 
            
            else 
            count+=K;
            
            i++;
        }
        
        count=0;
        i=N-1;
        while(count<N){
            maxCost+=candies[i];
            count++;
            
            if(count==N)
            break; 
            
            else 
            count+=K;
            
            i--;
        }
        
        ans.push_back(minCost);
        ans.push_back(maxCost);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends