#include <iostream>

using namespace std;
int main(){

    int n=9,s=4 , i;  // لان لاستاذ مقايل اعتبرو كل المتغيرات المستخدمه معرفه i عرفنا ال

    for( i = 0 ; i<=n ; i++){
        s= s+i;
        i++;
        cout << s << " ";
    }
    return 0;
}