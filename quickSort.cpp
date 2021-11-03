#include <iostream>
using namespace std;

void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i << "  ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[right]; // last element pivot
    cout << "Pivot element : " << pivot << endl;

    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        cout << "i = " << i << " j = " << j << " ";
        if (arr[j] < pivot)
        {
            cout << "arr[" << j << "] < " << pivot << ": True\n";
            i = i + 1;
            cout << "i = i + 1\n swap (arr[i] , arr[j])\n";
            swap(arr[i], arr[j]);
        }
        else
            cout << "arr[" << j << "] < " << pivot << ": False\n";
        cout << "\n";
        Display(arr, right + 1);
        cout << "\n";
    }
    cout << "(arr[i+1] , arr[right])\n";
    swap(arr[i + 1], arr[right]);

    cout << "\n";
    Display(arr, right + 1);
    cout << "\n";
    cout << "\n--------------\n\n";
    return i + 1;
}

void QuickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int q = Partition(arr, left, right);
        cout << "Partion position : " << q << endl;
        cout << "QuickSort(arr, " << left << ", " << q - 1 << ")" << endl;
        QuickSort(arr, left, q - 1);
        cout << "QuickSort(arr, " << q + 1 << ", " << right << ")" << endl;
        QuickSort(arr, q + 1, right);
    }
    
}

int main()
{
    int arr[] = {23, 12, -7, 16, 18, 35, 35, 28, 5};
    cout << "Initial Array\n";
    Display(arr, 9);

    cout << endl
         << "--------------  Quick Sort  --------------" << endl;

    cout << "\n\tQuickSort(arr, 0, 8) \n";
    QuickSort(arr, 0, 8);

    cout << "--------------  Quick Sort Completed -------------- \nFinal Array\n";
    Display(arr, 9);

    return 0;
}