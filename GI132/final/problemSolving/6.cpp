#include <iostream>
#include <string.h> // بيش ننادو ال strlen
using namespace std;


void readNames(char names[][100] ,int n){
    //نحولو اي مسافة فالكونسل بيش ميحسبهاش ادخال 
    cin.ignore();
        //ناخدو الاسماء
    for(int i = 0 ; i < n ; i++){
        cin.getline(names[i] , 100);
       
    }
      
    
}
void mergeCodes(char name[100] ,char code[100]){
    //نجيبو طول الاسم و الكود
    int n = strlen(name);
    int m = strlen(code);
    name[n] = ' ';
    for (int i = 0 ; i < m ; i++)
      // نحطو الكود فنهاية الإسم
      name[i+n+1] = code[i];
    //نحددو نهاية الإسم الجديدة
    name[m +n+1] = '\0';
}
void readCodes(char names[][100] , int n ){
    for(int i = 0 ; i < n ; i++){
        //متغير مؤقت للكود
        char code[50];
        cin.getline(code , 100);
        //ندمجو الإسم و الكود
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
    // ناخدو الأسماء من المستخدم
    readNames(names, n);
    //  بعدها الأكواد متاع المواد ويدمجهم مع اسم المادة
    readCodes(names, n);
    // نطبعو النتيجة
    printNames(names, n);
    
    return 0;
}