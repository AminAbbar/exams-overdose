#include <iostream>

using namespace std;
int main(){ 
    int i = 1, n=4 , x=0 , j;

    n=n+i;

    while(i<n){
      x=x+i;
      i++;
    }
    j=x;
    do{
      cout << i << "  ";
      i--;
      j--;
    }while(i>=1);
    
    cout << endl << i << " " << j;

    
  
    return 0;
}