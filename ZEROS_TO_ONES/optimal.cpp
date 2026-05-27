//Same as better, but then, here we will be using O(1) space, i.e. we will be using the first row and first column of the matrix to store the information about which row and column has 0, and then we will be updating the matrix accordingly.
//i.e instead of taking extra row and column, we will use in-place. 
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> zerosone(vector<vector<int>> &matrix, int m, int n){
    int col0=1;
    //matrix[0][...]--col matrix
    //matrix[..][0]-- row matrix


for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(matrix[i][j]==0){
            matrix[0][j]=0;
            if(j!=0){
               matrix[i][0]=0;
            }
            else{
               col0=0;
            }
        }
    }
}
//except 1st row and 1st colum, we will uodate remaining eleements
for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
        if(matrix[0][j]==0 || matrix[i][0]==0){
            matrix[i][j]=0;
        }
    }
}
//update 1st row and 1st column
if(matrix[0][0]==0){
    for(int j=0;j<n;j++){
        matrix[0][j]=0;
    }
    if(col0==0){
        for(int i=0;i<m;i++){
            matrix[i][0]=0;
        }
    }
}
return matrix;
}
int main(){
    int m,n;
    cout<<"Enter row size:";
    cin>>m;
    cout<<"Enter col size:";
    cin>>n;
    vector<vector<int>> matrix(m, vector<int> (n));
    cout<<"Enter matrix eeleemnts:";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    vector<vector<int>> ans= zerosone(matrix, m,n);

    cout<<"The matrix eleemts after conversion are:";;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}