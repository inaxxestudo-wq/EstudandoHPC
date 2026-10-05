#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
using namespace std;

int main() {
bool a,b,ai,bi;
    cin>>a>>b>>ai>>bi;
int i =0;
while(a!=ai||b!=bi){

if (b!=bi) {
   a=!a;
    b=!b;
    i++;
}
if (a!=ai&&b==bi) {
    a=!a;
    i++;
}
}
    cout<<i<<endl;
    return 0;
}