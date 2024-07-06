#include <iostream>

using namespace std;

int main(){



 int n = 6 , i , j;

 int b[20]={11,12,13,14,15,16};


 for(i=0;i<n-2;i=i+3)
  b[i] = b[i+1] *2;

 for(i=0;i<n;i++)
  if(i<n-3)
    b[i]=b[i+1];

 i++;

 for(j=n;j>n ; j--)
    b[j]=b[j];
    
 for (i=0;i<n;i++)
    cout << b[i] << " ";





    return 0;
}