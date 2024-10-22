#include <iostream>

using namespace std;

int main(){
     int f,n,m,a[100][100],i,j;

     f=4;n=5;m=6;
     
     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            a[i][j]=i+1;
            f++;
        }
     }
     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout << " " << "*" << endl;
     }

    return 0;
}