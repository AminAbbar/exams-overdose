#include <iostream>
#include <string.h> // بيش ننادو ال strlen

using namespace std;

int findSpaceIndex(char name[100]){
      //طول الإسم
      int n = strlen(name);
      // لشرط بس
      int i = 0;
      while (i < n){
         // لو لقي المسافة يطلع من الدالة ويرجع موقعها
        if (name[i] == ' ')
          return i;
        i++;
      }
      // لو تم الإسم وملقاهاش يرجع -1 لان لازم نرجعو شي
      return -1;
      
}
void copy( char A[100] , char B[100]){
    // الطول الجديد
    int n = strlen(A);
    // نقل عناصر زي اي مصفوفة
    for(int i = 0 ; i < n ; i++){
     
        B[i] = A[i];
    }
    // نحددو ان هذي نهاية المتغير المنسوخ الجديدة
    B[n] = '\0';
}
void appendFatherName(char name[100] , char father[100]){
    // بنجمعو الاسم هنا مؤقتا
    char fullName[100];
    // نعرفو طول الاسم و اللقب بدالة المسموحة
    int n = strlen(name);
    // طول اسم الأب
    int fatherNameLength = strlen(father);
    // بيش نعرفو طول الاسم بروحه و طول اللقب بروحه 
    //الدالة هذي بتلقا المسافة يلي بيناتهم وتعطينا موقعها
    //يلي قبلها الأسم ويلي بعدها هو اللقب
    int spaceIndex = findSpaceIndex(name);
    // بيش نعرفو وين بيتم اسم الأب جمعنا طول اسم الأب مع موقع المسافة
    // ملاحظة ان موقع المسافة بعد الأسم الاول ب 1
    // يعني هكي حسبتنا صح لان الطول لازم يكون زايد ب 1
    int fatherEndIndex = fatherNameLength + spaceIndex ;

    // نبدو تكوين الاسم الجديد
    //في المصفوفات N هذا الإسم الأول بنوقفو زي مقلنا قبل موقع المسافة نقدرو نعتبروه 
    for(int i = 0 ; i < spaceIndex ; i++){
        fullName[i] = name[i];
    }
    // توا مكان المسافة الاولى بنحطو مسافة بيش متلصقش الدنيا
    fullName[spaceIndex] = ' ';
    // توا بنضيفو اسم الأب
    //بنبدو من اول موقع بعد المسافة يلي ضفناها
    // وبنوقفو فنهاية اسم الأب لاحظ ان اصغر من او يساوي لان نبو كل حرف
    for(int i = spaceIndex + 1 ; i <= fatherEndIndex; i++){
                      // المبدئية i هتا بيش تبدو من بداية اسم الأب لغينا قيمة 
                      //يعني بيكون هكي father[0] , father[1] ...
        fullName[i] = father[i - spaceIndex - 1];
    }
    // توا بعد الإسم متاع الاب بنزيدو مسافة
    fullName[fatherEndIndex + 1] = ' ';
    // (n) نحددو موقع نهاية المصفوفة يعني بالعربي طولها الجديد 
    // الزائد 1 هذي بسبب اننا زدنا مسافة بين اسم الأب و الإسم الأول
    int fullNameEnd = n + fatherNameLength + 1;
    // بنبدو نضيفو اللقب وبنبدو من بعد اخر مسافة ضفناها
    // n ونوقفو قبل الطول الجديد يعني كأنها 
    for(int i = fatherEndIndex + 2 ; i < fullNameEnd ;i++){
                      //نبو نرجعو للقب فالمتغير الاول
                      //فنقصنا يلي زدناه ويلي هو 1 متاع المسافة و طول اسم الأب
        fullName[i] = name[i - fatherNameLength - 1];
    }
    //نقولو للكومبايلر ان هذي نهاية الإسم
    fullName[fullNameEnd] = '\0';
    // توا ننسخو الاسم الكامل للإسم الأول لان الإسم الكامل مؤقت بس
    // اعلنا عليه هنا ف بينحذف اول متتم الدالة هذي
    copy(fullName , name);
}


int main(){
    char name[100];
    char father[100];

    // ناخدو الاسم و اللقب
    cin.getline(name, 100);
    //طبعناهم زي مطلب فسؤال
    cout << name << endl;
    //ناخدو اسم الأب
    cin.get(father,100);
    // نضيفو اسم الأب بين اللقب و الاسم
    appendFatherName(name , father );
    // نطبعو الإسم الكامل
    cout << name << endl;
    return 0;
}