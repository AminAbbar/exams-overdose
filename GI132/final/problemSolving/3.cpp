#include <iostream>

using namespace std;

void read2DArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){ 
             // الكلام الجديد هنا
             // *(array + i) == array[i]
             // *(*(array + i) + j) == array[i][j]
            cin >> *( *(array + i) + j);
        }
    }

}

 
void printCurrentRow(int array[][100] , int row , int columns ){
     for(int i = 0; i < columns; i++)
        //  *( *(array + row) + i) == array[row][i]
       cout <<  *(*(array + row) + i) << " ";
     cout << endl;
 
}

void Search(int array[][100] , int rows , int columns , int x){
   
   for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            // x لو العنصر لحالي يساوي 
            // نطبعو الصف متاعها كامل
            if( *( *(array + i) + j) == x)
             return printCurrentRow(array , i , columns);
    // لو ملقيناهش
    cout << "NO" ;


}


int main(){

    int A[100][100];

     int rows , cols , x ;

     cin >> rows >> cols >> x ;
     // نقرو المصفوفة بالمؤشرات
     // ببساطة بنوصلو لعناصر المصفوفة عن طريق نقطة معينة فالمصفوفة
     // بينهم مسافة ثابتة ع حسب نوع متغيراتها (stack) لان المصفوفات عناصرهم مواقعهم فذاكرة  
     //قبل متكمل فباقي الأسئلة متاعهم (pointers) مش احسن شرح لكن لازم تكون فاهم المؤشرات   
    read2DArray(A,rows,cols);
    
    Search(A,rows,cols ,x);



    return 0;
}