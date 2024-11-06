#include <iostream>

using namespace std;
int main(){ 
    int i = 1,s=2,n=4 ,x=1 , w ,z;
    
    do{
        x++;
        s=s++ + x++;
        for(i = 2 ;i<n;i++){
            z=i+n;
            w=++z;
        }
        x--;
    }while (x<=n);
    cout << i << endl << s << endl << z << endl;
    cout << w << endl << x << endl;
    
    return 0;
}