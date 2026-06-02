#include<bits/stdc++.h>
using namespace std;


int minimumelements(vector<int> &arr,int target){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int T=0;T<=target;T++){
        
                if(T%arr[0]==0){
                    dp[0][T]=T/arr[0];
                }
                else{
                    dp[0][T]=1e9;
                }
            }
            for(int ind =1;ind<n;ind++){
                for(int T=0;T<=target;T++) {
                    int notpick=0+dp[ind-1][T];
                    int take=1e9;
                    if(arr[ind]<=T){
                        take=1+dp[ind][T-arr[ind]];
                    }
                    dp[ind][T]=min(notpick,take);
                }
                        
            }
    
    int ans= dp[n-1][target];
    if(ans>=1e9){
        return -1;
    }
    else{
        return ans;
    }
}
int main(){
    int n; 
    cout<<"Enter n:";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<":";
        cin>>arr[i];

    }
    int target;
    cout<<"Enter target:";
    cin>>target;

    int ans=minimumelements(arr,target);
    cout<<"Minimum coin change is:"<<ans<<endl;
}