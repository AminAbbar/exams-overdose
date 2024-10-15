#include <iostream>
#include <string.h> // بيش ننادو ال strlen
using namespace std;


void readNames(char names[][100] ,int n){
    
        cin.ignore();
    for(int i = 0 ; i < n ; i++){
        cin.getline(names[i] , 100);
       
    }
      
   
}
void mergeCodes(char name[100] ,char code[100]){
    int n = strlen(name);
    int m = strlen(code);
    for (int i = 0 ; i < m ; i++)
      name[i+n] = code[i];
}
void readCodes(char names[][100] , int n ){

       cin.ignore();
    for(int i = 0 ; i < n ; i++){
        char code[50];
        cin.getline(code , 100);
        mergeCodes(names[i],code);
       
    }
}

void printNames(char names[][100], int n){

    for(int i = 0 ; i < n ; i++){
        cout << names[i] << endl;
    }
}
int main(){
    char names[100][100]  , codes[100][100];
    int n;

    cin >> n;
    readNames(names, n);
    readCodes(names, n);
    printNames(names, n);
    
    return 0;
}