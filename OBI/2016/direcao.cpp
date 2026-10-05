#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
using namespace std;

int main() {
string a,b;
string v[] = {"norte","leste","sul","oeste"};
    cin>>a>>b;

int v1,v2;
    for (int i =0;i<4 ;i++ ) {


        if (a==v[i]) {
          v1 = i;  
            
        }
        if (b==v[i]){v2=i;
                   }
    }
   
   
if (abs(v1-v2) ==2) {
    cout<<"180"<<endl;
}
    else if(v1-v2 ==0)cout<<0<<endl;
    else cout<<90<<endl;
    return 0;
}   