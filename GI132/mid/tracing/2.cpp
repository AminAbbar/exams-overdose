#include <iostream>

using namespace std;

int main(){
   int f,n,m,i,j ,a[1000];
   f=4;n=5;m=6;
   
   for(i=0;i<n;i++){
     n++;
     f=m;
     a[i]=f;
     for(j=i;j<i+1;j++){
        m=m+j;
        n--;
     }
   }
   for(i=0;i<n;i++){
     cout<<a[i]<<" ";
   }

    

    return 0;
}