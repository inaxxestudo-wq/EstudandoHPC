### start cor.cpp
Para criar o problema "lápis de cor", eu pensei primeiramente em criar uma matriz de string, colocando todos os elementos primeiramente.
Após a criação, tentei fazer para cada "0" fazer a Distância de Manhattan percorrendo toda a matriz. Porém percebi que ficava inviável pois a complexidade assintótica seria de O(n^4) tendo em vista que eu verificaria, no pior dos casos, n² "0" e varreria novamente a matriz, sendo assim O(n²*n²) = O(n^4).


Depois de várias tentativas, encontrei uma maneira bem mais otimizada de calcular a distancia a partir de um "0" qualquer, diminuindo de O(n^4) para O(n^2). Essa foi a otimização =>
Troquei toda a busca matricial de cada 0 por BFS (Breadth-First Search). A cada elemento, como os vizinhos seria o valor da distância dele do "0" +1, ou seja, acrescentando uma distância fixa, conseguimos pegar o elemento central e comparar com  as 4 células adjacentes a ele: i+1, i-1, j+1,j-1.


Lembrando que o problema afirma que o maior número relacionado a cor é 9, então todo número>9 iremos substituir esses números por 9.

Algumas considerações importantes: utilizei o tipo int8_t para tornar consideravelmente mais leve o código, tendo em vista que o inte são 4 bytes e o tipo que eu utilizei é 1 byte apenas. Parece pouca a diferença, certo? mas 4*1000² = 4.000.000 de bytes vs 1.000.000 mi.
E como a questão me afirma que o maior número será 9, consigo usar com segurança esse tipo de dado.

Tendo em vista o problema e o pensamento feito, aqui está o código:
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

###end cor.cpp 

