#include <iostream>

using namespace std;
int main(){
    // تحويل الخوارزمية لكود
    ////////////////الكود هذا بيش نضمن ان الحل صح بس متدوروهش////////////
    int a = 2 ,b=3,c = 4 , d = 0;
    
    do{
        do{
            d = a + b + d;
            a = a + 1;
        }
        while(a  <= 5 );

        cout << "b=" <<  b << endl;

    }while (d <= 15);

    cout << "d=" << d << endl;
    cout << "a=" << a << endl;
    cout << "c=" << c << endl;
    
 



    return 0;
}