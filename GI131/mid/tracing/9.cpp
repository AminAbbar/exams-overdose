#include <iostream>

using namespace std;
int main(){ 
    int i = 1,n=5 ,x=1 , s=2;
     
    if(i<n){
        i++;
        if(x<i){

             s=x+i;
            
             if(i<s)
               i++;
        }else
          s++;
    }else
     if(x>i){
        i=i+s;
        i++;
     }else
      if(i>s){
        i=x+i+s;
      }
    
    cout << i << endl << x << endl << s << endl;
    return 0;
}