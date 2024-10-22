#include <iostream>

using namespace std;

void read2DArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){ 
             // *(array + i) == array[i]
             // *(*(array + i) + j) == array[i][j]
            cin >> *( *(array + i) + j);
        }
    }

}

void print2DArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            cout << array[i][j] << " ";

    
        cout << endl;
        
    

}

void print1DArray(int array[] , int columns){

        for(int i = 0; i < columns; i++)
            cout << array[i]<< " ";

        cout << endl;

}

void Throw (int array[][100] , int rows , int columns ) {

    int result[100];
    // طول المصفوفة الاحادية
    int tracker = 0;

    for(int i = 0; i < rows; i++){
       // نضيفو للمصفوفة الاحادية العنصر الحالي من الصف الأخير
       // results[tracker] = array[columns - 1][i];
       *(result + tracker) = *(*(array  + columns - 1) + i );
        //نزيدو طولها
        tracker++;
    }
   // نطبعو المصفوفة الثنائية
   print2DArray(array, rows , columns);
   cout << endl;
   //  نطبعو المصفوفة الجديدة الاحادية
   print1DArray(result, columns);

}
int main(){ 

    // لو مش فاهم المؤشرات شوف الملاحظة ف سؤال 3

    int array[100][100] , rows , columns;
    cin >> rows >> columns;
    
    read2DArray(array , rows , columns);
     
    Throw(array , rows , columns);

    return 0;
}