//Rotate image by 90 degree
#include<bits/stdc++.h>
using namespace std;
void rotatematrix(vector<vector<int>> &mat){
    int n=mat.size();
for(int i=0;i<=n-2;i++){
    for(int j=i+1;j<=n-1;j++){
        swap(mat[i][j], mat[j][i]);
    }
}

for(int i=0;i<n;i++){
    reverse(mat[i].begin(), mat[i].end());
}

}

int main(){
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    vector<vector<int>> mat(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    rotatematrix(mat);
 for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}