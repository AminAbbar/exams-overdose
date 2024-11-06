#include <iostream>

using namespace std;
int main(){ 
    int i = 1,j=2,n=5 ,x;
    for(i=2;i<n;i++){
        ++j;
        x= n + j + i++;
        if(i<n)
          x++;
    }
    cout << "x = " << x << endl;
    return 0;
}