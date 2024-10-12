#include <iostream>

using namespace std;

int main(){

   float grams  ;
   int choice; // متغير للخيار

   cin >> grams;

   cin >> choice;

   switch (choice)
   {
   case 1: // من الجرام للكيلو
    grams /= 1000;
    cout <<  grams << " kilogram" << endl;

    break;
   case 2: //الى الطن
    grams /= (1000*1000);
    cout <<  grams << " ton" << endl;

    break;
   case 3:// للباوند
    grams /= 453;
    cout <<  grams << " pound" << endl;

    break;
   case 4: // للأونصة
    grams /= 28;
    cout <<  grams << "  ounce" << endl;
    break;
   
   default:
    cout << "EXIT!";
   }


    return 0;
}