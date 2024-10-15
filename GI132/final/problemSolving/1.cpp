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