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