#include<bits/stdc++.h>
using namespace std;
vector<int> spiralmatrix(vector<vector<int>> &mat){
    int m= mat.size();
    int n=mat[0].size();
    vector<int> ans;
    int top=0, bottom=m-1;
    int left= 0, right= n-1;

    while(left<=right && top<=bottom){
        //STEP-1: LEFT TO RIGHT
        for(int i=left; i<=right; i++){
            ans.push_back(mat[top][i]);
        }
        top++;

        //STEP-2: TOP TO BOTTOM
        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;
    

    //STEP-3: RIGHT TO LEFT
    if(top<=bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(mat[bottom][i]);
        }
    
    bottom--;
    }

    //STEP-4: BOTTOM TO TOP
    if(left<=right){//when there is no top
    for(int i=bottom;i>=top;i--){
        ans.push_back(mat[i][left]);
    }
left++;
    }
}
    return ans;

}

int main(){
    int n,m;
    cout<<"Enter row size and column size of the matrix: ";
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<int> result;
    cout<<"Enter the elements of the matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    result=spiralmatrix(mat);

    cout<<"The spiral matrix eleemnts are:";
    for(int i:result){
        cout<<i<<" ";
    }
    return 0;
    }

