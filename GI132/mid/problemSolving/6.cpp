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

void swabMainD( int F[][100], int n){
   int x ;
   cin >> x;
   //بنقصو من المدخلات 1 بيش لو دخل المتسخدم واحد فالمصفوفة يكون 0 
   //لان اول عمود فالمصفوفة 0
   x -= 1;
   // هنا بنلفو ع الصفوف
   for(int i = 0; i < n; i++)
        //وهنا ع كل عمود فالصف الواحد 
        for(int j = 0; j < n; j++)
             //لو الصف يساوي العمود معناها حني فالقطر الرئيسي
            if(j == i ){
                 //عملية تبديل بين العنصر يلي فالصف الحالي فالقطر الرئيسي 
                 // و العنصر فالصف الحالي فالعمود المطلوب
                 int temp = F[i][x];
                 F[i][x] = F[i][j] ;
                 F[i][j] = temp;
            }
}
int sumHalfArray( int F[][100], int n){

   int sum = 0;

   for(int i = 0; i < n; i++)
        // هكي بنوقفو فنص المصفوفة يعني العناصر يلي ع ليسار بس
        for(int j = 0; j < (n / 2); j++)
             //نضيفو العنصر للمجموع
           
                 sum += F[i][j];
            
    return sum;
} 

int findSmallestNumberInSubD ( int F[][100] , int n){
    //نفترضو ان اول قيمة فالقطر الفرعي هي اصغر قيمة
    int smallest = F[0 ][n - 1]; 

    for(int i = 0 ; i < n ; i++) 
        for(int j = 0 ; j < n ; j++)
            // القطر الفرعي هو لما مجموع الصف زائد العمود يساوي طول المصفوفة زائد 1
            //لكن بما اننا فبرمجة مش رياضة  المصفوفة عندنا تبدا من 0 مش 1
            //ف بيش نوازنو المعادلة جمعنا الصف مع العمود و تحققنا هل يساوو الطول ناقص 1
            //مثال
            // في الرياضة 3+1 = 4 في حالة المصفوفة طولها 3
            // في البرمجة 2+0 = 2 في حالة المصفوفة طولها 3

            //ولو تحقق الشرط نشوفو هل اصغر من اخر اصغر قيمة عندنا
            if((i+j) == n-1  && F[i][j] < smallest)
                smallest = F[i][j];

  
    return smallest;
}
void calcD (int F[][100] , int D[][100] , int n){
      int x;
      // ناخدو قيمة x 
      cin >> x;

      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
             // الصف الثاني نضربو القيمة ف أكس
             if(i == 1)
              D[i][j] = F[i][j] * x;
             else
              // لو اي صف ثاني نحطوها كيف ماهيا
              D[i][j] = F[i][j];
}

int main(){

   int n ;
   int F[100][100]  , D[100][100];
   //ناخدو ابعاد المصفوفة
   cin >> n;
   //نبعتو للدالة المصفوفة و عدد اعمدتها و عدد صفوفها
   read2DArray(F , n , n);
   //طباعة المصفوفة
   print2DArray(F,n,n);
   //المطلوب الأول
   // تبديل عمود بالقطر الرئيسي
   swabMainD(F , n);
   print2DArray(F,n,n);
   //المطلوب الثاني
   int sum = sumHalfArray(F , n);
   cout << sum;
   //المطلوب الثالث
   //واخد راحتي فلاسماء شوية مش مهم :)
   // هذا بيلقى اصغر قيمة فالقطر الفرعي
   int smallestValue = findSmallestNumberInSubD(F , n);
   cout << smallestValue;
   //المطلوب الرابع
   calcD(F ,D, n);
   print2DArray(D , n , n);

    return 0;
}