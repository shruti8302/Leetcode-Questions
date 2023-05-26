//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution
{   
    public:
    
    ll firstIndex(vector<long long> v, long long x){
        ll si = 0;
        ll ei = v.size()-1;
        ll idx = -1;
        
        while(si <= ei){
            ll mid = si + (ei-si)/2;
            if(x == v[mid]){
                idx = mid;
                ei = mid-1;
            }else if(x < v[mid]){
                ei = mid-1;
            }else{
                si = mid+1;
            }
        }
        return idx;
    }
    
    ll lastIndex(vector<long long> v, long long x){
        ll si = 0;
        ll ei = v.size()-1;
        ll idx = -1;
        
        while(si <= ei){
            ll mid = si + (ei-si)/2;
            if(x == v[mid]){
                idx = mid;
                si = mid+1;
            }else if(x < v[mid]){
                ei = mid-1;
            }else{
                si = mid+1;
            }
        }
        return idx;
    }
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        pair<long, long> p;
        
        ll firstIdx = firstIndex(v, x);
        ll lastIdx = lastIndex(v, x);
        
        p.first = firstIdx;
        p.second = lastIdx;
        
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends