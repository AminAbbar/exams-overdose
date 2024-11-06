#include <iostream>

using namespace std;
int main(){
    int  f = 4 , n=5,m=6;

    for(int i = 0; i < n; i++){

        for(int j = f; j < m; j++){
            f = i + j;
            f++;
            i++;
            cout << f << " ";
        }
        cout << endl << "*";
    }
    return 0;
}