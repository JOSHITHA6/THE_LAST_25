//Better soln: TC:O(m*n); SC:O(n)+O(m)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> zerosone(vector<vector<int>> &matrix, int m, int n){
    int col[n]={0};
    int row[m]={0};
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]||col[j]){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}
int main(){
   
    int m, n;
    cout<<"Enter row size:";
    cin>>m;
    cout<<"Enter column size:";
    cin>>n;
    vector<vector<int>> matrix(m, vector<int> (n));
    cout<<"Enter the elements in the matrix:";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> ans= zerosone(matrix, m,n);

    cout<<"The output matrix is:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


}