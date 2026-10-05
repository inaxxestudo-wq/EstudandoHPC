#include <iostream>
#include <vector>
#include <cstdint>
#include <queue>
#include <utility>
using namespace std;
int main() {
    int n;
    cin>>n;

vector<vector<int8_t>> matriz(n,vector<int8_t>(n));
queue<pair<int,int>> fila;
    for (int i =0;i<n ;i++ ) {
string c;
cin>>c;
        
        for(int j=0;j<n;j++){

if(c[j]=='*')matriz[i][j]=-1;
else{ matriz[i][j]=0;
      
    fila.push({i,j});
    }
        }
    }

while(!(fila.empty())){
    
int i = fila.front().first;
int j = fila.front().second;
fila.pop();

    if (i<n-1&&(matriz[i+1][j]==-1||(matriz[i+1][j]>(matriz[i][j]+1)&&matriz[i][j]!=-1) )) {
        if (matriz[i][j]<9) {
            matriz[i+1][j] =matriz[i][j]+1;
        }
       else matriz[i+1][j]=9;


        fila.push({i+1,j});
    }
    if (i>0&&(matriz[i-1][j]==-1||(matriz[i-1][j]>(matriz[i][j]+1)&&matriz[i][j]!=-1) )) {
        if (matriz[i][j]<9) {
            matriz[i-1][j] =matriz[i][j]+1;
        }
       else matriz[i-1][j]=9;

         fila.push({i-1,j});
    }
    if (j>0&&(matriz[i][j-1]==-1||(matriz[i][j-1]>(matriz[i][j]+1)&&matriz[i][j]!=-1 ))) {
        if (matriz[i][j]<9) {
            matriz[i][j-1] =matriz[i][j]+1;
        }
       else matriz[i][j-1]=9;

         fila.push({i,j-1});
    }
    if (j<n-1&&(matriz[i][j+1]==-1||(matriz[i][j+1]>(matriz[i][j]+1) &&matriz[i][j]!=-1))) {
        if (matriz[i][j]<9) {
            matriz[i][j+1] =matriz[i][j]+1;
        }
       else matriz[i][j+1]=9;

         fila.push({i,j+1});
    }
    



    
}


    for (int i =0;i<n;i++) {

        for (int j=0;j<n ;j++ ) {
            cout<<(int) matriz[i][j];
        }
        cout<<endl;
    }

    return 0;
}