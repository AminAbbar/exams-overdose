#include <iostream>

using namespace std;
int main(){
    int i =  1 , j=2; // افترضت ان الفاصلة المنقوطة يلي حاطها الاستاذ خطأ مطبعي
    // لو مش خطأ مطبعي الكود كله غلط و الجواب لايطبع شيء
    do{
        cout << endl << i << endl;
        i +=2;
        while (j<=6)
        {
            cout << j << " ";
            j++;
        }
        i++;       

    }while(i<6);
    
    return 0;
}