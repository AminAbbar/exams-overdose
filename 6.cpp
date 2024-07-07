#include <iostream>

using namespace std;

int main(){

    for (int i = 101; i < 1000 ; i++){
        if (i % 5 == 0) { // لو قبل القسمة عليه يعني من مضاعفاته
            cout << i << endl;
        }
    }    

    return 0;
}