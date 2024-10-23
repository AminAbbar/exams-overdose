#include <iostream>

using namespace std;

int main(){
   int f,n,m,i ,a[1000];

   f=4;n=5;m=6;
   for(i = 0 ; i<n;i++){
    a[i]=f;
    f++;
   }
   for(i = 0 ; i<n;i++){
    a[i]=f;
    i++;
   }
   n--;
   for(i=n;i>0;i--){
    cout << a[i] << " ";
   }


    return 0;
}