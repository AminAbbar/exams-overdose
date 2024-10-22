#include <iostream>

using namespace std;

int main(){

     int f,n,m,i,j;

     f=4;n=5;m=6;

     for(i=0;i<n;i++){
        m--;
        f++;
     }
     i++;
     n--;
     for(i=0;i<n;i++)
      cout << m << " " << f <<" "<< i << endl;


    return 0;
}