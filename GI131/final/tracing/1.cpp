#include <iostream>

using namespace std;

int main(){
    
    int i , j , m;

    i = 0 ; j = 1;
    m = ++j + ++i + i++;
    cout << j++ << ++j << i << m;


    return 0;
}