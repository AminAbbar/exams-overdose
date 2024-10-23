#include <iostream>

using namespace std;

int main(){
    int f,n,m,i,x;

    f=4; n=5; m=6;

    for(i=0;i<n;i++){
        m=n+i;
        f++;
    }
    x=i+n+m+f;
    cout << x << endl;



    return 0;
}