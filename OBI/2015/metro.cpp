#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
using namespace std;
#include <string>
int main() {

int16_t n,m;
cin>>n>>m;
queue<int16_t> filaNos;
int centro =0;
vector<vector<int16_t>> matriz(n);

    for (int16_t i =0;i<m ;i++ ) {
      int16_t v1,v2;
        cin>>v1>>v2;
matriz[v2-1].push_back(v1-1);
matriz[v1-1].push_back(v2-1);
if (centro<matriz[v2-1].size()&&matriz[v2-1].size()<matriz[v1-1].size()) {
    centro = v1-1;
}        
        else if (centro<matriz[v2-1].size()&&matriz[v2-1].size()>matriz[v1-1].size()) {
          centro = v2-1;  
        } 
    }

vector<int16_t> pai(n,-1);
filaNos.push(centro);
vector<pair<int16_t,int16_t>> paiFilho;
vector<bool> visitado(n);
    while(!filaNos.empty()){
int16_t frente = filaNos.front();
filaNos.pop();
visitado[frente] = true;

        for(int16_t i=0;i<matriz[frente].size();i++){
int16_t valorAtual = matriz[frente][i];

            if (!visitado[valorAtual]) {

                filaNos.push(valorAtual);
               
                pai[valorAtual] = frente;
                visitado[valorAtual] = true;

            }
           else if (visitado[valorAtual] && pai[valorAtual]!=frente) {

               if (pai[frente]!=-1&&frente!=centro&&valorAtual!=centro) {
                 paiFilho.push_back({frente,valorAtual});  
               }
 
               
                
            }
        }
        

    
    }
    //cout<<"centro: "<<centro<<endl;
cout<<paiFilho.size()/2<<endl;
    
    return 0;
}