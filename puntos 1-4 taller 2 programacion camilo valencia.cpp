#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    // 1. mediana del array ===========
    int array1 [5]={2,4,1,3,5};
    int n= sizeof(array1)/sizeof(array1[0]);
    sort(array1,array1+n);
   
    double mediana = array1[n/2];
    cout<<"la mediana es: "<<mediana<<" \n\n";
   
    // 2. =========buscar un elemento del array========
    int array2[9]={1,4,6,7,23,8,3,11,12};
    int buscar;
    cout<<"el arreglo es: [ ";
    for (int i=0;i<9;i++){cout<<array2[i]<<", ";}
    cout<<"]";
    cout<<"\nQue elemento quieres buscar?: "; cin>>buscar;
   
    bool encontrado= false;
    int posicion =-1;
    for(int i = 0; i<9; i++){
       if (array2[i]== buscar){
           encontrado = true;
           posicion=i;
           break;
       }
    }
    if (encontrado){
        cout<<"El elemento "<<buscar<<" esta en la posicion "<<posicion+1<<" del array.";//le sume 1 a la posicion para evitar confusiones.
    } else{
        cout<<"el elemento "<<buscar<<" no esta en el array.";
    }
    cout<<"\n\n";
    // 3. ======== transpuesta de una matriz ========
    int filas=2, columnas=3;
    int matriz[2][3]={{1,2,3},{4,5,6}};
    int matrizT[3][2];
    
    for (int i=0; i< filas ;i++){
        for (int j=0; j< columnas; j++){
            matrizT [j][i]= matriz [i][j];
        }
    }
    cout<<"matriz: \n";
    for (int i=0; i< filas ;i++){
        for (int j=0; j< columnas; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n Matriz transpuesta: \n";
    for (int i=0; i< columnas ;i++){
        for (int j=0; j< filas; j++){
            cout<<matrizT [i][j]<<" ";
        }
        cout<< endl;
    }
    
    //======== 4. sistema de inventario simple con array =========
    
    const int max = 50; //
    string nombres[max];
    int cantidades[max];
    double precios[max];
    int totalProductos = 0;
    int opcion;

    do {
        cout << "\n=== SISTEMA DE INVENTARIO ===\n";
        cout << "1 Agregar producto\n";
        cout << "2 Mostrar inventario\n";
        cout << "3 Buscar producto\n";
        cout << "4 Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            if (totalProductos < max) {
                cout << "Nombre del producto: ";cin >> nombres[totalProductos];
                cout << "Cantidad: ";cin >> cantidades[totalProductos];
                cout << "Precio: ";cin >> precios[totalProductos];
                totalProductos++;
                cout << "Producto agregado.\n";
            } else {
                cout << "Inventario lleno.\n";
            }
        }
        else if (opcion == 2) {
            cout << "\n=== INVENTARIO ===\n";
            for (int i = 0; i < totalProductos; i++) {
                cout << i+1 << ". " << nombres[i] 
                     << " | Cantidad: " << cantidades[i] 
                     << " | Precio: $" << precios[i] << endl;
            }
            if (totalProductos == 0) cout << "Inventario vacio.\n";
        }
        else if (opcion == 3) {
            string buscar;
            cout << "Ingrese el nombre del producto a buscar: ";cin >> buscar;
            bool encontrado = false;
            for (int i = 0; i < totalProductos; i++) {
                if (nombres[i] == buscar) {
                    cout << "Producto encontrado: " << nombres[i] 
                         << " | Cantidad: " << cantidades[i] 
                         << " | Precio: $" << precios[i] << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Producto no encontrado.\n";
            }
        }
        else if (opcion == 4) {
            cout << "Saliendo del sistema...\n";
        }
        else {
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);

}