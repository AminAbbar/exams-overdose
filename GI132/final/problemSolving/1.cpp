#include <iostream>

using namespace std;
void read2DArray(int array[][100] , int rows , int columns){
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            cin >> array[i][j];
}
void calculateA (int A[][100] , int rows , int columns){
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            //لو الصف زوجي و العنصر فردي
            if(i % 2 == 0 && A[i][j] % 2 != 0)
                A[i][j] *= 5;
            
             
}

void print2DArray(int array[][100] , int rows , int columns){
    
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
    read2DArray(A , N,M);
    calculateA(A , N , M);
    print2DArray(A , N , M);


    return 0;
}