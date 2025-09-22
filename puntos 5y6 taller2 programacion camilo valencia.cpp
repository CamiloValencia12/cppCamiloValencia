#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

    //====== 5. algoritmo de ordenamiento por seleccion ========

void selectionSort(int arr3[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int a = i;
        for (int j = i + 1; j < n; j++) {
            if (arr3[j] < arr3[a]) {
                a = j;
            }
        }
        int b = arr3[i];
        arr3[i] = arr3[a];
        arr3[a] = b;
    }
}
int main() {
    int arr3[] = {9,3,11,2,7};
    int n = sizeof(arr3) / sizeof(arr3[0]);

    cout << "array original: ";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << endl;

    selectionSort(arr3, n);

    cout << "array ordenado: ";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << endl;
    
    // 6. ======= programa para encontrar elementos duplicados =======
    
    int arr[8]={1,4,2,4,7,1,3,8};
    int num= sizeof(arr)/sizeof(arr[0]);
    cout<<"\n\narray: ";
    for(int i=0;i<8;i++ )cout<<arr[i]<<" ";
    cout<<"\nelementos duplicados en el array: \n";
    bool duplicados= false;
    for (int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(arr[i]==arr[j]){
                cout<<arr[i]<<" ";
                duplicados=true;
                break;
            }
        }
    }
    if (!duplicados){
        cout<<"no hay elementos duplicados ";
    }
    cout <<endl;
    
}