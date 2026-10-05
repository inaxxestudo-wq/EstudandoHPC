#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

int main() {
   int16_t n;
    cin>>n;
    string linha;
    int i1;
    bool reduzir = true;
    cin.ignore();
    for (int i =0;i<n ;i++ ) {

getline(cin,linha);
       
char c;
        for (int j =0;j<linha.size() &&reduzir ;j++ ) {
c = linha[j];

 if (c == '{') {
     i1++;
 }     
  else if(c=='}')i1--;      

   if (i1==-1) {
       reduzir = false;
       break;
   }         
        }
    }


    if (i1==0) {
       cout<<"S"<<endl;
           
    }
        else cout<<"N"<<endl;

  
        return 0;
}