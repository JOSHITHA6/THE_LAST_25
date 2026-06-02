#include<bits/stdc++.h>
using namespace std;
int f(vector<int> &arr, int ind, int T, vector<vector<int>> &dp){
    if(ind==0){
    if(T%arr[0]==0){
        return T/arr[0];
    }
    else{
        return 1e9;
    }
}
if(dp[ind][T]!=-1){
    return dp[ind][T];
}
    int notpick=0+f(arr,ind-1,T,dp);
    int pick=INT_MAX;
    if(arr[ind]<=T){
        pick=1+f(arr,ind,T-arr[ind],dp);
    }
    return dp[ind][T]=min(pick,notpick);

}

int minimumelements(vector<int> &arr,int T){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(T+1,-1));
    int ans= f(arr,n-1,T,dp);
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