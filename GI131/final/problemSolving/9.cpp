#include <iostream>

using namespace std;

int main(){

    int sum = 0;
    for (int i = 1001; i < 10000 ; i++){
        if (i % 9 == 0) { // لو قبل القسمة عليه يعني من مضاعفاته
            sum += i;
        }
    } 
    cout << sum << endl;


    return 0;
}