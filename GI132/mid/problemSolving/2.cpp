#include <iostream>

using namespace std;
float fect(float x ){
    // بنخزنو الناتج التراكمي هنا
    float mul = 1;
    for(float i = x ; i > 1 ; i--)
      // لو اكس 5 بينضرب ف 5 بتولي مول 25 بعدين 25 ف 4 وهكذا لتوصل ال الأي 1 بنطلعو
      mul *= i;

    return mul;
}
//بناخدو قيمة اكس و الترتيب متاع المعادلة الحالية 
//ونطلعو منه البسط و المقام لانهم نفس المعادلة (بدون تربيع او مضروب)
float genFormula(float x , float index){
    //index = 0 => x-1
    //index = 1 => x-2 ...
    return x - index + 1;
}
float genPower(float index){
    //index = 0 => 1 
    //index = 1 => 3 ...
    if(index == 0) return 1;
    return index + 2 ;
}
float calcPower(float x , int power){
        float temp = 1; // بيش الأس كان صفر وملفتش الحلقة يخلي القيمة 1
        for(float po = 0 ; po < power ; po++){ //لو الأس صفر الحلقة هذي مش حتخدم
            temp *= x; // نضربو القيمة ف أكس
        }
        return temp; 
}
float getSum(float x   , float n ){
   float sum = 0 ;
   //الإن محسوبة معانا هذا ليش درنا او يساوي 
   //ايه في خطأ مطبعي فصورة السؤال البسط و المقام إن
   for(int i = 0 ; i <= n ;i++){
    // نجيبو المعادلة
     float foumula =  genFormula(x , i);
     //نجيبو كم قيمة الأس
     float power = genPower( i);
     // قيمة البسط بعد رفع المعادلة للأس يلي حصلناه
     float  first = calcPower(foumula,power);
     //نجيبو المقام بأننا نجيبو مضروب المعادلة
     float second = fect(foumula);
     // نزيدو ناتج قسمتهم ع المجموع
     sum += (first / second);
   }
   //نرجعو المجموع للماين
   return sum;
}
int main(){
     
    float x  ,n ,sum ;
    cin >> x >> n;
    //نجيبو قيمة المتسلسلة
    sum = getSum(x , n);
    cout << sum;
    return 0;
}