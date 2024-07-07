#include <iostream>

using namespace std;

int main(){


    for (int i = 1001; i < 10000 ; i++){
        if (i % 9 == 0) { // لو قبل القسمة عليه يعني من مضاعفاته
            cout << i << endl;
        }
    } 


    return 0;
}