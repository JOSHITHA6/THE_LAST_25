#include<bits/stdc++.h>
using namespace std;

bool meetingroom(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end());
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<intervals[i-1][1])
        return false;
    }
    return true;
}

int main(){
    int n;

    cout<<"Enter no of rows:";
    cin>>n;

    vector<vector<int>> intervals(n, vector<int> (2));
    for(int i=0;i<intervals.size();i++){
        cout<<"Enter start and end time of " << i+1 <<" meeting: ";
        cin>>intervals[i][0]>>intervals[i][1];
    }
    cout<<(meetingroom(intervals)?"true":"false")<<endl;

}