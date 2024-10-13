#include <iostream>

using namespace std;

void getArrayValues(int n, int array[])
{

    for (int i = 0; i < n; i++)
        cin >> array[i];
}

int getXLocation(int n, int array[])
{
    int x;
    cin >> x;
    for (int i = 0; i < n; i++)
        if (array[i] == x)
            return i;

    return -1;
}

void bubbleSort(int v[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)

            if (v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
}

int countX(int n, int array[])
{
    int tracker = 0;
    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
        if (array[i] == x)
            tracker++;

    return tracker;
}

void printFirstAndSecondAndLast(int n, int array[])
{
    cout << "first : " << array[0] << endl;
    cout << "second :" << array[1] << endl;
    cout << "last : " << array[n - 1] << endl;
}

void printArrayFromBothSides(int n, int array[])
{
    cout << "from beginning : " << endl;
    for (int i = 0; i < n; i++)
        cout << array[i] << endl;

    cout << "from end :" << endl;
    for (int i = n - 1; i >= 0; i--)
        cout << array[i] << endl;
}
int main()
{

    int n;
    int array[10000];
    cin >> n;
    getArrayValues(n, array);

    int result = getXLocation(n, array);

    if (result == -1)
        cout << "NO" << endl;
    else
        cout << "x location is : " << result << endl;

    /////////////////////////////////////////////////////////////

    bubbleSort(array, n);

    result = getXLocation(n, array);

    if (result == -1)
        cout << "NO" << endl;
    else
        cout << "x order is : " << result + 1 << endl;

    /////////////////////////////////////////////////////////////

    result = countX(n, array);

    if (result == 0)
        cout << "NO" << endl;
    else
        cout << "x repeated for " << result << " times" << endl;

    ////////////////////////////////

    printFirstAndSecondAndLast(n, array);

    ///////////////////////////////

    printArrayFromBothSides(n, array);

    return 0;
}