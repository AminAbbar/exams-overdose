#include <iostream>

using namespace std;
void read2DArray(int array[][100] , int rows , int columns){
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            cin >> array[i][j];
}
void print2DArray(int array[][100] , int rows , int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++)
            cout <<array[i][j] << " ";
        cout << endl;
    }
}
void swabColumns(int B[][100], int rows , int columns ){
   int x ,y;
   //ناخدو قيمة x و y 
   //يلي هما مواقع الاعمدة يلي بنبدلو بيناتهم
   cin >> x >> y ;
   //بنقصو من المدخلات 1 بيش لو دخل المتسخدم واحد فالمصفوفة يكون 0 
   //لان اول عنصر فالمصفوفة 0
   x -= 1;
   y -= 1;

   // هنا بنلفو ع الصفوف
   for(int i = 0 ; i < rows ; i++) 
      //وهنا ع كل عمود فالصف الواحد 
      for(int j = 0 ; j < columns ; j++)
         // لو العنصر الحالي جزء من العمود يلي نبو نبدلوه يعني عموده يساوي أكس
         if(j == x) {
             //عملية تبديل متغيرين طبيعية
             int temp = B[i][x];
             B[i][x] = B[i][y];
             B[i][y] = temp;
         }
   
}

void sort2DArray(int B[][100], int rows , int columns ){
   
   // هنا بنلفو ع الصفوف
   for(int i = 0 ; i < rows ; i++) 
      //وهنا ع كل عمود فالصف الواحد اي كل عنصر فالصف
      // بما اننا بنغيرو العنصر الحالي ب يلي قدامها فحالة كان الحالي اصغر
      // فدرنا الفور الاولى توقف قبل اخر عنصر ب 1
      // لان لو مدرناهاش اخر عنصر بيتقارن مع عنصر غير معروف مش جزء من المصفوفة
      for(int j = 0 ; j < columns - 1 ; j++)
         //هنا بنقارنو العنصر الحالي يلي هو جي بكل العناصر الباقية فالصف هذا
         for (int s = 0; s < columns - 1; s++)
            // درنا لو العنصر الحالي اصغر من يلي بعده لان قال ترتيب تنازلي مش تصاعدي
                if (B[i][s] < B[i][s + 1])
                {
                    //عملية تبديل طبيعية
                    int temp = B[i][s];
                    B[i][s] = B[i][s + 1];
                    B[i][s + 1] = temp;
                }
}
int getSmallestNumberIn2DArray(int B[][100], int rows , int columns ){
    //نفترضو اول عنصر هو اصغر عنصر
   int smallest = B[0][0];
   // هنا بنلفو ع الصفوف
   for(int i = 0 ; i < rows ; i++) 
      //وهنا ع كل عمود فالصف الواحد 
      for(int j = 0 ; j < columns ; j++)
        // لو العنصر الحالي اكبر من اخر اصغر قيمة نخلوه هو اصغر قيمة
        if(B[i][j] > smallest)
            smallest = B[i][j];

   return smallest;
} 
//خدينا طول الصفوف بس لان هي مصفوفة مربعة يعني عدد الصفوف هو عدد الاعمدة
void calcE(int B[][100] , int X[][100] , int E[][100] , int rows){
  
   // هنا بنلفو ع الصفوف
  for(int i = 0 ; i < rows ; i++) 
      //وهنا ع كل عمود فالصف الواحد 
      for(int j = 0 ; j < rows ; j++)
        E[i][j] = B[i][j] + X[i][j];

}
int main(){
     
   int n ;
   int B[100][100] , X[100][100] , E[100][100];
   //ناخدو ابعاد المصفوفة
   cin >> n;
   //نبعتو للدالة المصفوفة و عدد اعمدتها و عدد صفوفها
   read2DArray(B , n , n);
   //طباعة المصفوفة
   print2DArray(B,n,n);
   //المطلوب الأول
   swabColumns(B , n , n );
   print2DArray(B,n,n);
   //المطلوب الثاني
   sort2DArray(B , n , n );
   print2DArray(B,n,n);
   //المطلوب الثالث
   int smallestNumber = getSmallestNumberIn2DArray(B , n , n);
   cout << smallestNumber << endl;
   //المطلوب الرابع
   //ناخدو عناصر X
   read2DArray(X , n , n);
   //حساب E
   calcE(B , X , E, n);
   // طباعة E
   print2DArray(E,n,n);





    return 0;
}