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