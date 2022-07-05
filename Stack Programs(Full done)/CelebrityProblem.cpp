// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //M[a][b]=1 means a knows b
        
        int len=M.size();
        stack<int>s;
        for(int i=0;i<len;i++)
            s.push(i);
        while(s.size()>=2)
        {
            int i=s.top();
            s.pop();
            int j=s.top();
            s.pop();
            if(M[i][j]==1)
            {
                //i knows j
                //so eliminate i
                s.push(j);
            }
            else if(M[j][i]==1)
            {
                //j knows i
                //so eliminate j
                s.push(i);
            }
        }
        int t=s.top();
        for(int i=0;i<len;i++)
        {
            if(i!=t)
            {
                if(M[i][t]==0 || M[t][i]==1)
                    return -1;
            }
        }
        return t;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends


// I/O

// N = 3
// M[][] = {{0 1 0},
//          {0 0 0}, 
//          {0 1 0}}
// Output: 1