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
    // نفترضو اكبر صف و عمود هم متاع اول مصفوفة
    int biggestRows =aRows , biggestCols =aCols;
    //  اكبر يخليهم هم الاكبر b لو طول اعمدة او صفوف 
    if(aRows < bRows)
      biggestRows = bRows;
    if(aCols < bCols)
      biggestCols = bCols;

    //بنديرو حلقتنا ع اساس الاكبر
    for(int i = 0; i < biggestRows; i++){
        for(int j = 0; j < biggestCols; j++){
            int sum = 0;
            // ف حالة كانت هي اصغر a نتأكدو اننا مطلعناش من طول المصفوفة 
            if(i < aRows && j < aCols)
              sum += *( *(arrayA+i)+j) ;
            // ف حالة كانت هي اصغر b نتأكدو اننا مطلعناش من طول المصفوفة 
            if(i < bRows && j < bCols)
              sum += *( *(arrayB+i)+j);
           // نخزنو نتيجة جمعهم فالمصفوفة الجديدة
           *( *(result+i)+j) = sum;
        }
    }
    // نطبعو مصفوفة المجموع
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
    // لو مش فاهم المؤشرات شوف الملاحظة ف سؤال 3

    int aArray[100][100] , bArray[100][100] , aRows,aCols,bRows,bCols;

    cin >> aRows >> aCols >> bRows >> bCols;
    // نطبعو كل مصفوفة ب ابعادها
    read2DArray(aArray,  aRows, aCols);
    read2DArray(bArray,  bRows, bCols);

    Add(aArray, aRows, aCols, bArray, bRows, bCols);




    return 0;
}