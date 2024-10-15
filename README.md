<div align="center">
    <h3 align="center">أسئلة امتحانات سابقة مع الحل</h3>
    <p align="center">
      لو عندك اسئلة زيادة او لاحظت خطأ تقدر تصلحه مباشرة او قوللنا ويتصلح
      <br />
      <a href="https://t.me/yourSpaece">قناة التلغرام</a>
      ·
      <a href="https://t.me/itstudents2024">قروب التلغرام</a>
    </p>
  </div>
    <h1>المواد :</h1>
    <ol dir="rtl">
      <li ><h3 ><a  href="#GI131"><b >برمجة 1</b></a></h3></li>
<li ><h3 ><a  href="#GI132"><b >برمجة 2</b></a></h3></li>
    </ol>
    <br id="GI131" />    <details>      <summary dir="rtl"><h1>برمجة 1</h1></summary>            <ul>                          <li>            <summary><b>أسئلة النهائي</b></summary>              <br />                        <ul>              <li><summary><a href="#GI131_final_Trace"><b>أسئلة التتبع</b></a></summary></li>              <li><summary><a href="#GI131_final_Problem"><b>أسئلة المقالي</b></a></summary></li>            </ul>         </li>      </ul> 
      <br id="GI131_final_Trace">
<details>      <summary dir="rtl"><h3>نهائي - أسئلة التتبع :</h3></summary>

![](./GI131/final/tracing/1.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){
    
    int i , j , m;

    i = 0 ; j = 1;
    m = ++j + ++i + i++;
    cout << j++ << ++j << i << m;


    return 0;
}  
```
![](./GI131/final/tracing/10.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){
    
   for(int i = 1; i<=5;i++){

    for(int j=i; j<=5;j++)
       cout << j << " ";
    cout << endl;  
   }

    return 0;
}  
```
![](./GI131/final/tracing/11.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

   int x=12;

   do{
       cout << x << " ";
       x++;
       
   }while(x<=10);

   while(x<=15){
    cout << x << " ";
    x++;
   }

    return 0;
}  
```
![](./GI131/final/tracing/12.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

    for(int i = 1;  i<= 5;i++){

        for(int j=i; j<=5;j++)
           cout << j << " ";

        cout << endl;
    }

  
    return 0;
}  
```
![](./GI131/final/tracing/13.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){
    
    float r ,s,t,v;

    r=0.1;
    s=0.2;
    t=0.3;
    for(r=0.2; r<=(0.1*10) ; r+=0.1)
        v=s+r;

    cout  <<  r   <<  s   <<  t   << v;


    return 0;
}  
```
![](./GI131/final/tracing/14.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

    int n=6, i , j;

    int b[20] = {11 ,12,13,14,15,16};
    
    for(i=0;i<n-2;i=i+3)
     b[i] = b[i+1]*2;
    
    for(i = 0 ; i<n;i++)
        if(i<n-3)
         b[i] = b[i+1];
    
    i++;

    for(j=n ; j>n;j--)
      b[j] = b[j];
    
    for(i=0; i<n;i++)
      cout << b[i] << " ";

    return 0;
}  
```
![](./GI131/final/tracing/15.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

     // int a = {4,6,6,3,33,24}; ///  خطأ بيخلي الكود كله ميخدمش الجواب لايطبع شيء
     

    return 0;
}  
```
![](./GI131/final/tracing/16.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

    int i=1, j=1,t=6,n=7;

    t= ++i+t;
    i = i+t;
    j+=n;

    if(t+t >=12 && j+j>=15)
      cout<< t << i << j << n;
    
    else 
      cout << t ;

    return 0;
}  
```
![](./GI131/final/tracing/17.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

    int i , j , m;

    i = 0 ; j = 1;

    m = ++j + ++i + i++;

    cout << j++ << ++j << i << m;

    return 0;
}  
```
![](./GI131/final/tracing/18.png) 

 ```cpp 
#include <iostream>
#include <string.h> // بيش ننادو ال strlen
using namespace std;
int main(){
     //strlen دالة بتعد طول السلسلة بس 
     //ملاحظة مش مقررة علينا
  

     char a[100] = "Ahmed Ali";

     int L= strlen(a);

     a[7] = 'M';
     
     cout<<a<<L;

    return 0;
}  
```
![](./GI131/final/tracing/19.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

   int a[5];
   int n=5, i , j , f=0;

   //a[5] = {10 ,20,30,40,50};  ///  خطأ بيخلي الكود كله ميخدمش الجواب لايطبع شيء

   


    return 0;
}  
```
![](./GI131/final/tracing/2.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

     int n = 5 , i , j;

     int a[5] = {2 ,4,5,6,7};

     for(i = 0; i <n-1;i=i+2)
       a[i]= a[i] * 2;

     for(i = 1 ; i < n-2;i++)
      cout <<a[i] << " " ;
     

    return 0;
}  
```
![](./GI131/final/tracing/20.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

     int n=5, i ,j;

     int a[5]= {2,4,5,6,7};

     for(i = 0 ; i<n-1;i=i+2)
      a[i] = a[i] *2;

     for(i = 1; i < n-2 ; i++)
      cout << a[i] << " ";


    return 0;
}  
```
![](./GI131/final/tracing/3.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

   float r,s,t,v;

   r=0.1;s=0.2; t=0.3;

   for(r=0.2;r<(0.1*10);r+=0.1)
    v=s+r;
    
   cout << r << s << t <<v;

    return 0;
}  
```
![](./GI131/final/tracing/4.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

   int a[5]; int  n=5 , i ,j,f=0;

   //a[5] = {10, 20,30,40,50};  ///  خطأ بيخلي الكود كله ميخدمش الجواب لايطبع شيء
   

    return 0;
}  
```
![](./GI131/final/tracing/5.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){
         
     // int a = {4,6,6,3,33,24}; ///  خطأ بيخلي الكود كله ميخدمش الجواب لايطبع شيء

    return 0;
}  
```
![](./GI131/final/tracing/6.png) 

 ```cpp 
#include <iostream>
#include <string.h> // بيش ننادو ال strlen
using namespace std;
int main(){
     //strlen دالة بتعد طول السلسلة بس 
     //ملاحظة مش مقررة علينا
    char a[100] = "Ahmed Ali";
    int L = strlen(a);
    a[7] = 'M';
    cout << a << L;

    return 0;
}  
```
![](./GI131/final/tracing/7.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

    int x =12;

    do{

        cout << x << " ";
        x++;
    }while(x<=10);
    

    while(x<=15){
        cout << x << " ";
        x++;
    }

    return 0;
}  
```
![](./GI131/final/tracing/8.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){
      int i = 1, j=1,t=6,n=7;

      t=++i+t;
      i=i+t;
      j+=n;
      if(t+t >= 12 && j+j>=15)
        cout << t << i << j << n;
      else
       cout<<t;
      


    return 0;
}  
```
![](./GI131/final/tracing/9.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){



 int n = 6 , i , j;

 int b[20]={11,12,13,14,15,16};


 for(i=0;i<n-2;i=i+3)
  b[i] = b[i+1] *2;

 for(i=0;i<n;i++)
  if(i<n-3)
    b[i]=b[i+1];

 i++;

 for(j=n;j>n ; j--)
    b[j]=b[j];
    
 for (i=0;i<n;i++)
    cout << b[i] << " ";





    return 0;
}  
```
</details>
<br id="GI131_final_Problem">
<details>      <summary dir="rtl"><h3>نهائي - الأسئلة المقالية :</h3></summary>
      
![](./GI131/final/problemSolving/1.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

     int A[1000] , N;

     cin >> N;

     for(int i = 0; i < N; i++) 
        cin >> A[i];

    for(int i = 0; i < N; i++)
        cout  << A[i] ;
    
    for(int i = 0; i < N; i++)
       if(i % 2 == 0) // لو الموقع الحالي زوجي
         A[i] *= 2; // يضرب قيمة عنصر الموقع الحالي ف 2

    for(int i = 0; i < N; i++)
        cout  << A[i];// طباعة المصفوفة بالقيم الجديدة


    return 0;
}  
```
![](./GI131/final/problemSolving/10.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

    int sum = 0;

    for( int i= 501 ; i < 5000 ;i++)
      if(i%2 !=0)
        sum += i;
    

    cout << sum ;


    return 0;
}  
```
![](./GI131/final/problemSolving/11.png) 

 ```cpp 
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
```
![](./GI131/final/problemSolving/12.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){


    int a ; // درجة الطالب

    cin >> a;

    int requ  = 120 * 0.75 ; // بيش نعرفو كم درجة 75% من 120 بنضربوها ف 75 على 100 يلي هي 0.75
    
    if(a >=requ){
        cout << "accepted"; // مدرناهاش بالعربي لان مشاكل طباعة بالعربي بس

    }else{
        cout << "rejected";
    }
    
    return 0;
}  
```
![](./GI131/final/problemSolving/2.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){
    

    int B[1000] , C[1000] , N;
 
    
    cin >> N;


    for(int i = 0 ; i < N; i++)
     cin >> B[i];

    for(int i = 0 ; i < N; i++)
     cout << B[i] << " ";

    cout << endl;

    int tracker = 0; // بنتبعو بيه كم عنصر نقلنا
    int newSize = N; // بعد ننقلو العناصر B حجم المصفوفة 

    // B حلقة نبوها تلف ع النص الاول بس من المصفوفة 
    for(int i = 0 ; i < (N / 2) ; i++){

         
        // هنا درنا i - tracker
        // ك اينديكس للمصفوفات لان بعد نبدو نبلدو لازم نحسبو حساب العناصر يلي حولناها

        if(B[i-tracker] > 50 ){ // نتحققو هل العنصر الحالي اكبر من خمسين لان هذا شرط النقل
          //مثال
          //C[0]       B[0-0] 
          C[tracker] = B[i-tracker]; 
          // C بما اننا لقينا عنصر اكبر من خمسين ونسخناه ف 
          // لان قال نقل مش نسخ B لازم نحولوه من 
          // بنديروها بحلقة تعاود الترتيب بداية من العنصر يلي نقلناه لعند نهاية المصفوفة بحجمها بعد النقل
         
          newSize--; // ننقصو من الحجم الجديد 1

          for(int j = (i-tracker); j < newSize; j++) 
            B[j] = B[j+1]; // نخلو قيمة العنصر الحالي يلي تساوي يلي بعده 

          // وهكي هنا بنكونو سحبنا العنصر يلي نقلناه من للمصفوفة الجديدة
          
          //مثال 
          // B = [ 3 , 66  , 58 , 33] => B = [3 , 58, 33]
          // C = [] => C = [ 66]
             
          

          tracker++; // نزيدو متغير التتبع متاع النقل 1
       
        }
        
    }
     for(int i = 0 ; i < newSize; i++) // B نستخدمو الحجم الجديد ف طباعة المصفوفة 
     cout << B[i] << " ";
   
    cout << endl;
     
      for(int i = 0 ; i < tracker; i++) // C نستخدمو المتغير يلي حسبنا بيه عمليات النقل لان هذا حجم مصفوفة 
     cout << C[i] <<  " ";

    cout << endl;

    return 0;
}  
```
![](./GI131/final/problemSolving/3.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

    int B[1000] , C[1000] , n ;

     cin >> n;


    for(int i = 0 ; i < n; i++)
     cin >> B[i];

    for(int i = 0 ; i < n; i++)
     cout << B[i] << " ";

    cout << endl;



    int tracker = 0; // بنتبعو بيه كم عنصر نقلنا
    int newSize = n; // بعد ننقلو العناصر B حجم المصفوفة 

    // B حلقة نبوها تلف ع النص الثاني بس من المصفوفة 
    for(int i = (n / 2) ; i < n ; i++){
  
        // هنا درنا i - tracker
        // ك اينديكس للمصفوفات لان بعد نبدو نبلدو لازم نحسبو حساب العناصر يلي حولناها

        if(B[i - tracker] > 10){
           //مثال
          //C[0]        B[2-0] 
            C[tracker] = B[i-tracker];

           // C بما اننا لقينا عنصر اكبر من عشرة ونسخناه ف 
          // لان قال نقل مش نسخ B لازم نحولوه من 
          // بنديروها بحلقة تعاود الترتيب بداية من العنصر يلي نقلناه لعند نهاية المصفوفة بحجمها بعد النقل
         
            

            newSize--; // ننقصو من الحجم الجديد 1

           for(int j = (i-tracker); j < newSize; j++) 
            B[j] = B[j+1]; // نخلو قيمة العنصر الحالي يلي تساوي يلي بعده 
 
          // وهكي هنا بنكونو سحبنا العنصر يلي نقلناه من للمصفوفة الجديدة
          
          //مثال 
          // B = [ 3 , 13  , 15 , 3] => B = [3 , 13, 3]
          // C = [] => C = [ 15]

            tracker++;

        }
    }


    for(int i = 0 ; i < newSize; i++) // B نستخدمو الحجم الجديد ف طباعة المصفوفة 
     cout << B[i] << " ";
   
    cout << endl;
     
      for(int i = 0 ; i < tracker; i++) // C نستخدمو المتغير يلي حسبنا بيه عمليات النقل لان هذا حجم مصفوفة 
     cout << C[i] <<  " ";

    cout << endl;

    return 0;
}  
```
![](./GI131/final/problemSolving/4.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

    int number = 0 , n  , positiveSum = 0 , positiveCount = 0 ,
        negativeCount = 0 , negativeSum = 0;

    cin >> n;

    for(int i = 0 ; i< n ; i++){
        cin >> number;
         // ملاحظة استثنينا الصفر لان مش عدد صحيح و في السؤال مطلوب عدد صحيح
         if(number != 0) 
           
            if(number > 0){
               positiveCount++;
               positiveSum += number;

            }else{
               negativeCount++;
               negativeSum += number;
            }

       
    }
    //طريقة العرض مش مهمة بما انه نظري
    cout <<  positiveCount << positiveSum << negativeCount << negativeSum;



    return 0;
}  
```
![](./GI131/final/problemSolving/5.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

    char nam[1000];
 
   cin >> nam; // لكن بما اننا مخديناهاش فلنظري بنستخدمو العادية cin.get() لو نبو ناخدو حتى المسافات فلأدخال لازم 
  
  
    // بنحسبو طولها بروحنا لان مرات يقول لاستاذ الدوال الجاهزة كلها لا 
    int length = 0;
    // null بيستمر يزيد الطول واحد ليلقى قيمة فاضية
    while (nam[length] != '\0') {
        length++;
    }

    // نضيفو المطلوب بعد يلي دخله المستخدم بعد حسبنا طوله
    nam[length] = ' '; // لان قال خلي مسافة 
    nam[length + 1] = '#';
    nam[length + 2] = '@';
    nam[length + 3] = '#';
    nam[length + 4] = '\0'; // بيش يعرف ان وقفنا هنا وميعطيش باقي العناصر الفاضية قيم عشوائية
    cout << nam << endl;
    
    return 0;
}  
```
![](./GI131/final/problemSolving/6.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    for (int i = 101; i < 1000 ; i++){
        if (i % 5 == 0) { // لو قبل القسمة عليه يعني من مضاعفاته
            sum += i;
        }
    }    
    cout << sum << endl;

    return 0;
}  
```
![](./GI131/final/problemSolving/7.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){
    float w = 0  , n;

    cin >> n;
    
    for(int i = 0 ; i < 20 ; i++){ // حلقة بتلف 20 مره لان قال عشرين حد
        float first = n- (i*2) ; //  البسط

        float copy = first; // ناخدو منه نسخة بيش نرفعوله الأس
        first = 1; // بيش الأس كان صفر وملفتش الحلقة يخلي البسط 1
        for(int po = 0 ; po < ( (i*2) + 2) ; po++){ // زائد 2 n الأس عبارة عن العدد المطروح من 
            first *= copy; // نضربو البسط فنفسه
        }

        float second = n - (i*2) ; //المقام

        int mul = 1; // متغير نحسبو فيه المضروب
        for (int i = second ; i > 1; i--){ // نبدو من قيمة المقام ونقعدو ننزلو كل حلقة  لعند 2
            mul *= i ;  // i نضربو قيمة المضروب الحالية ف 
        }

        second = mul; // بعد طلعنا المضروب نرجعوه للمقام

       
       w += first / second ; // w نظيفو النتيجة للمتغير 


    }
      cout << w << endl;



    return 0;
}  
```
![](./GI131/final/problemSolving/8.png) 

 ```cpp 
#include <iostream>

using namespace std;

int main(){

float w = 0  , n;

    cin >> n;
    
    for(int i = 0 ; i < 20 ; i++){ // حلقة بتلف 20 مره لان قال عشرين حد
        float first = n - (i * 2) ; //  البسط

        float copy = first; // ناخدو منه نسخة بيش نرفعوله الأس
        first = 1; // بيش الأس كان صفر وملفتش الحلقة يخلي البسط 1
        for(int po = 0 ; po < ( i + 2) ; po++){ // 2 زائد  i  الأس عبارة عن 
            first *= copy; // نضربو البسط فنفسه
        }

        float second = n - (i*2) ; //المقام

        int mul = 1; // متغير نحسبو فيه المضروب
        for (int i = second ; i > 1; i--){ // نبدو من قيمة المقام ونقعدو ننزلو كل حلقة  لعند 2
            mul *= i ;  // i نضربو قيمة المضروب الحالية ف 
        }

        second = mul; // بعد طلعنا المضروب نرجعوه للمقام

       
       w += first / second ; // w نظيفو النتيجة للمتغير 


    }
    cout << w << endl;

    return 0;
}  
```
![](./GI131/final/problemSolving/9.png) 

 ```cpp 
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
```
</details>
    
</details>
  
<br id="GI132" />    <details>      <summary dir="rtl"><h1>برمجة 2</h1></summary>            <ul>                          <li>            <summary><b>أسئلة النهائي</b></summary>              <br />                        <ul>              <li><summary><a href="#GI132_final_Trace"><b>أسئلة التتبع</b></a></summary></li>              <li><summary><a href="#GI132_final_Problem"><b>أسئلة المقالي</b></a></summary></li>            </ul>         </li>      </ul> 
      <br id="GI132_final_Trace">
<details>      <summary dir="rtl"><h3>نهائي - أسئلة التتبع :</h3></summary>


</details>
<br id="GI132_final_Problem">
<details>      <summary dir="rtl"><h3>نهائي - الأسئلة المقالية :</h3></summary>
      
![](./GI132/final/problemSolving/1.png) 

 ```cpp 
#include <iostream>

using namespace std;
void readTwoDimensionalArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin >> array[i][j];
        }
    }

}
void calculateA (int A[][100] , int rows , int columns){

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            if(i % 2 == 0 && A[i][j] % 2 != 0)
                A[i][j] *= 5;
            
             
}

void printTwoDimensionalArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++)
            cout << array[i][j] << " ";

    
        cout << endl;
        
    }

}

int main(){
    

    int A[100][100] ;
    int N , M;
    cin >> N >> M;
    readTwoDimensionalArray(A , N,M);
    calculateA(A , N , M);
    printTwoDimensionalArray(A , N , M);


    return 0;
}  
```
![](./GI132/final/problemSolving/2.png) 

 ```cpp 
#include <iostream>

using namespace std;
void print(int A[] , int n){
    
    for(int i = 0 ; i < n ; i++) 
        cout << A[i] << " ";
    
    cout << endl;
 
}

void readArray(int A[] , int n){
    
    for(int i = 0 ; i < n ; i++) 
        cin >> A[i];
}

int Trans(int A[] , int B[] , int n , int bSize){
    for (int i = 0 ; i < n/2 ; i++) 
      if(A[i] < 50){

        B[bSize] = A[i];
        bSize++;
      }
    return bSize;
}

//في حالة نسخ مش نقل متدورهاش الدالة هذي
int reFormatArray(int A[] , int n){
    for(int i = 0 ; i < n/2 ; i++)
        if(A[i] < 50){
           for(int j = i ; j < n ;j++)
            A[j] = A[j+1];
           
           return reFormatArray(A , n-1);
        }
    
    return n;
} 
int main(){

    int n ,A[1000] , B[1000] , bSize= 0;
    
    cin >> n;

    readArray(A,n);
    bSize = Trans(A , B, n , bSize);
    n = reFormatArray(A,n);
    print(A,n);
    print(B,bSize);
    



    return 0;
}  
```
![](./GI132/final/problemSolving/3.png) 

 ```cpp 
#include <iostream>

using namespace std;

void readTwoDimensionalArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin >> *(*(array + i) + j);
        }
    }

}


void printCurrentRow(int array[][100] , int row , int columns ){
     for(int i = 0; i < columns; i++)
       cout <<  *(*(array + row) + i) << " ";
     cout << endl;
 
}

void Search(int array[][100] , int rows , int columns , int x){
   
   for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            if( *(*(array + i) + j) == x)
             return printCurrentRow(array , i , columns);
        
    cout << "NO" ;


}


int main(){

    int A[100][100];

     int rows , cols , x ;

     cin >> rows >> cols >> x ;

    readTwoDimensionalArray(A,rows,cols);
     Search(A,rows,cols ,x);



    return 0;
}  
```
![](./GI132/final/problemSolving/4.png) 

 ```cpp 
#include <iostream>

using namespace std;

void read2DArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin >> *(*(array + i) + j);
        }
    }

}

void print2DArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++)
            cout << array[i][j] << " ";

    
        cout << endl;
        
    }

}

void print1DArray(int array[] , int columns){

        for(int i = 0; i < columns; i++)
            cout << array[i]<< " ";

        cout << endl;

}

void Throw (int array[][100] , int rows , int columns ) {

    int result[100];

    int tracker = 0;

    for(int i = 0; i < rows; i++){

       *(result + tracker) = *(*(array  + columns - 1) + i );
        tracker++;
    }

   print2DArray(array, rows , columns);
   cout << endl;
   print1DArray(result, columns);

}
int main(){
    int array[100][100] , rows , columns;
    cin >> rows >> columns;
    read2DArray(array , rows , columns);
    Throw(array , rows , columns);

    return 0;
}  
```
![](./GI132/final/problemSolving/5.png) 

 ```cpp 
#include <iostream>

using namespace std;


void print2DArray(int array[][500] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++)
            cout <<*( *(array+i)+j) << " ";

    
        cout << endl;
        
    }

}

void Add(int arrayA[][100], int aRows , int aCols , int arrayB[][100], int bRows , int bCols){
    int result[500][500];
    int biggestRows =aRows , biggestCols =aCols;
    if(aRows < bRows)
      biggestRows = bRows;
    if(aCols < bCols)
      biggestCols = bCols;

    for(int i = 0; i < biggestRows; i++){
        for(int j = 0; j < biggestCols; j++){
            int sum = 0;

            if(i < aRows && j < aCols)
              sum += *( *(arrayA+i)+j) ;

            if(i < bRows && j < bCols)
              sum += *( *(arrayB+i)+j);

           *( *(result+i)+j) = sum;
        }
    }
    print2DArray(result , biggestRows , biggestCols);
}
void read2DArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin >> *(*(array + i) + j);
        }
    }

}
int main(){
    int aArray[100][100] , bArray[100][100] , aRows,aCols,bRows,bCols;

    cin >> aRows >> aCols >> bRows >> bCols;

    read2DArray(aArray,  aRows, aCols);
    read2DArray(bArray,  bRows, bCols);
    Add(aArray, aRows, aCols, bArray, bRows, bCols);




    return 0;
}  
```
![](./GI132/final/problemSolving/6.png) 

 ```cpp 
#include <iostream>
#include <string.h> // بيش ننادو ال strlen
using namespace std;


void readNames(char names[][100] ,int n){
    
        cin.ignore();
    for(int i = 0 ; i < n ; i++){
        cin.getline(names[i] , 100);
       
    }
      
   
}
void mergeCodes(char name[100] ,char code[100]){
    int n = strlen(name);
    int m = strlen(code);
    for (int i = 0 ; i < m ; i++)
      name[i+n] = code[i];
}
void readCodes(char names[][100] , int n ){

       cin.ignore();
    for(int i = 0 ; i < n ; i++){
        char code[50];
        cin.getline(code , 100);
        mergeCodes(names[i],code);
       
    }
}

void printNames(char names[][100], int n){

    for(int i = 0 ; i < n ; i++){
        cout << names[i] << endl;
    }
}
int main(){
    char names[100][100]  , codes[100][100];
    int n;

    cin >> n;
    readNames(names, n);
    readCodes(names, n);
    printNames(names, n);
    
    return 0;
}  
```
![](./GI132/final/problemSolving/7.png) 

 ```cpp 
#include <iostream>

using namespace std;

void readTwoDimensionalArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin >> array[i][j];
        }
    }

}
void printTwoDimensionalArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++)
            cout << array[i][j] << " ";

    
        cout << endl;
        
    }

}

void calculateD(int C[][100] , int D[][100], int rows , int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(j % 2 == 0)
                D[i][j] = C[i][j];
            else
                D[i][j] = 4;
        }
    }
}
void sortTwoDimensionalArrayRows(int array[][100], int rows , int columns){
    int temp;
   
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns - 1; j++)
            for (int s = 0; s < columns - j - 1; s++)
                if (array[i][s] > array[i][s + 1])
                {
                    temp = array[i][s];
                    array[i][s] = array[i][s + 1];
                    array[i][s + 1] = temp;
                }
        
    
}
void calculateE(int C[][100] , int D[][100] , int E[][100], int rows , int columns){
    for(int i = 0; i < rows ; i++){
        for(int j = 0; j < columns; j++){
            E[i][j] = C[i][j] + D[i][j] + 4;
        }
    }
}
int main(){
     int cRows , cCols;
     int C[100][100] , D[100][100] , E[100][100];
     
     cin >> cRows >> cCols;
     readTwoDimensionalArray(C , cRows , cCols);
    //  //أ
    //  calculateD(C , D , cRows , cCols);
    //  printTwoDimensionalArray(D , cRows , cCols);
    //  //ب
    //  calculateE(C , D , E , cRows , cCols);
    //  printTwoDimensionalArray(E , cRows , cCols);
    //  //ج
     sortTwoDimensionalArrayRows(C , cRows , cCols);
     printTwoDimensionalArray(C , cRows , cCols);

 
    return 0;
}  
```
</details>
    
</details>
  
  