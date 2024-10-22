#include <iostream>
#include <string.h> // بيش ننادو ال strlen

using namespace std;

void removeCharacter( char name[100] , char character    ){
    //هنا نبيك تركز معايا **********
    //جبنا طول الاسم بدالة الجاهزة المسموحة
    int n = strlen( name );
    //بنلفو ع حروف الأسم
    for (int i = 0; i < n; i++)
      // لو الحرف الحالي مساوي للحرف يلي بنحذفوه
      if( name[i] == character)
      {
        //بنوخرو كل الحروف يلي بعده خطوة بحيث انه الحرف يلي بعده بياخد مكانه
        for ( int j = i ; j < n - 1 ; j++ )
           name[j] = name[j+1];

        // هنا الجزء المهم

        // هنا قلنا للكومبايلر ان الموقع يلي كان اخر حرف فلأسم ولا نهايتها
        // \0 نهاية النص فشار بتكون 
        name[n - 1] = '\0';
        //بنعاودو ننادو الدالة بنفس المدخلات لكن بعد نقص الطول 1 
        return removeCharacter(name , character );
      }
}
int main(){
    char name[100] , character;
   
    //خدينا من المستخدم الاسم
    cin.getline(name, 100);
    //طبعنا الاسم زي مقال فسؤال
    cout << name << endl;
    //بنجيبو الحرف يلي المستخدم يبي يحذفه
    cin >> character;
    //بنحذفو الحرف من الاسم مهما كان عدد المرات يلي تكرر فيها
    removeCharacter( name , character  );
    //نطبعو النتيجة
    cout << name;

    return 0;
}