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
    for (int i = 0 ; i < n/2 ; i++) 
      if(A[i] < 50){

        B[bSize] = A[i];
        bSize++;
      }
    return bSize;
}

//في حالة نسخ مش نقل متدورهاش الدالة هذي
int reFormatArray(int A[] , int n){
    for(int i = 0 ; i < n/2 ; i++)
        if(A[i] < 50){
           for(int j = i ; j < n ;j++)
            A[j] = A[j+1];
           
           return reFormatArray(A , n-1);
        }
    
    return n;
} 
int main(){

    int n ,A[1000] , B[1000] , bSize= 0;
    
    cin >> n;

    readArray(A,n);
    bSize = Trans(A , B, n , bSize);
    n = reFormatArray(A,n);
    print(A,n);
    print(B,bSize);
    



    return 0;
}