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