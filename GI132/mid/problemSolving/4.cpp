#include <iostream>

using namespace std;

int genPower(int index){
    //index = 1 => 2 
    //index = 2 => 4 ...

    return index  * 2 ;
}
int calcPower(int x , int power){
        int temp = 1; // بيش الأس كان صفر وملفتش الحلقة يخلي القيمة 1
        for(int po = 0 ; po < power ; po++){ //لو الأس صفر الحلقة هذي مش حتخدم
            temp *= x; // نضربو القيمة ف أكس
        }
        return temp; 
}
int getSum(int x   , int y ,int   X ){
    //بدينا من ال 100 يلي قال عليها ف أكس 
   int sum = X ;
   // بدينا من ال 1 لان مش محتاجين لما تكون 0
   // بنوقفو قبل ما ال الأي تساوي اكس لان فالمتستسلة مجموع طرحها من الأكس فلأخير لازم يساوي 1
   for(int i = 1 ; i < x ;i++){
     int  first = x - i ;
     //نجيبو كم قيمة الأس
     int power = genPower( i);
     // قيمة أول حد من العملية
      first = calcPower(first,power);
     // قيمة ثاني حد مرفوع لأس اعلى من اس اول حد بواحد
     int second = calcPower(y ,power+1);
     // نزيدو ناتج جمعهم ع المجموع
     sum += (first + second);
   }
   //نرجعو المجموع للماين
   return sum;
}
int main(){
    // c++ حساسة لحالة لحروف
    // X != x
    int sum  , X= 100 , x ,y ;
    cin >> x >> y ;

    sum = getSum(x,y,X);
    cout << sum ;
    


    return 0;
}