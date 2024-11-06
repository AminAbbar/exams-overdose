#include <iostream>

using namespace std;
int main(){ 
    int i = 1, x=2  , n=5;

    for(i=0;i<n;i++){
      x=n-i;
      do{
        cout << "*" << " ";
        i++;
      }while(i<x);
      x= i + x ;
    }
    cout << x;
     
  
    return 0;
}