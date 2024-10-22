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
     // n النصف الاول ف بنوقفو عن نص 
    for (int i = 0 ; i < n/2 ; i++) 
      // لو العنصر الحالي اصغر من 50
      if(A[i] < 50){
        // B ننسخوه ل 
        B[bSize] = A[i];
        //واحد B نزيدو حجم 
        bSize++;
      }
    //نرجعو الحجم الجديد
    return bSize;
}

//في حالة نسخ مش نقل متدورهاش الدالة هذي
int reFormatArray(int A[] , int n){
    //مع اضافة بسيطة Trans نفس الكلام متاع دالة 
    for(int i = 0 ; i < n/2 ; i++)
        if(A[i] < 50){
           for(int j = i ; j < n ;j++)
            A[j] = A[j+1];
            //تقريبا شرحتها فأسئلة النصفي الفكرة
           //بنقعدو كل ما ننقلو ننقصو من الطول 1 والدالة بتعاود تنادي نفسها
           // بيش تبدا من جديد بالطول الجديد
           return reFormatArray(A , n-1);
        }
    // لو ملقتش ولا واحد يعني نقلتهم كلهم ترجع الحجم الجديد
    return n;
} 
int main(){

    int n ,A[1000] , B[1000] , bSize= 0;
    
    cin >> n;

    readArray(A,n);
    // الجديد B ونرجعو حجم  B ل A  ننقلو العناصر من 
    bSize = Trans(A , B, n , bSize);
    // ونرجعو حجمها الجديد A نحولو العناصر يلي نقلناهم من 
    n = reFormatArray(A,n);
    // A نطبعو
    print(A,n);
    // B نطبعو
    print(B,bSize);
    



    return 0;
}