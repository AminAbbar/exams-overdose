#include <iostream>

using namespace std;

int main(){

   float r,s,t,v;
   r=0.1;s=0.2; t=0.3;
   for(r=0.2;r<(0.1*10);r+=0.1)
    v=s+r;
   cout << r << s << t <<v;

    return 0;
}