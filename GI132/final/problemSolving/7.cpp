#include <iostream>

using namespace std;

void read2DArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            cin >> array[i][j];
} 
void print2DArray(int array[][100] , int rows , int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++)
            cout << array[i][j] << " ";

        cout << endl;
    }
}

void calculateD(int C[][100] , int D[][100], int rows , int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(j % 2 == 0) // لو العمود زوجي
                D[i][j] = C[i][j];
            else // مش واضحة الصورة اظن انها 4 🥸
                D[i][j] = 4;
        }
    }
}
void sort2DArrayRows(int array[][100], int rows , int columns){
    int temp;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns - 1; j++)
           // نفس ترتيب اي مصفوفة احادية ودرناها فأسئلة النصفي 
            for (int s = 0; s < columns - 1; s++)
                if (array[i][s] > array[i][s + 1])
                {
                    temp = array[i][s];
                    array[i][s] = array[i][s + 1];
                    array[i][s + 1] = temp;
                }    
}
void calculateE(int C[][100] , int D[][100] , int E[][100], int rows , int columns){
    for(int i = 0; i < rows ; i++)
        for(int j = 0; j < columns; j++)
            //نجمعوهم ببساطة سؤال هدية
            E[i][j] = C[i][j] + D[i][j] + 4;
        
}
int main(){
     int cRows , cCols;
     int C[100][100] , D[100][100] , E[100][100];
     
     cin >> cRows >> cCols;
     read2DArray(C , cRows , cCols);
     //أ
     calculateD(C , D , cRows , cCols);
     print2DArray(D , cRows , cCols);
     //ب
     calculateE(C , D , E , cRows , cCols);
     print2DArray(E , cRows , cCols);
     //ج
     sort2DArrayRows(C , cRows , cCols);
     print2DArray(C , cRows , cCols);

    return 0;
}