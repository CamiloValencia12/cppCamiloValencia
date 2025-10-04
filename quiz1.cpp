#include <iostream>
#include <iomanip>
using namespace std;
#include <string>


int main()
{
    //1.1 
    int a=5;
    int b= 7;
    float c=3.5;
    float d=4.3;
    char e[]= "hola";
    
    cout<<a<<" \n";
    cout<<b<<" \n";
    cout<<c<<" \n";
    cout<<d<<" \n";
    cout<<e<<" \n";
   
   //1.2
   /*se usa int cuando el valor es entero y se recomieda usar 
   cuando son operaciones basicas o cuado los numeros de esas operaciones son exactos
   como numero de personas de un lugar, numero de hermanos etc.
   
   se usa float, cuando se necesita trabajar con numeros decimales, por ejemplo las notas de 
   estudiantes, resultados de divisiones que no son exactas etc.
   
   se usa char, cuando el contenido de la variable sea un texto, o caracteres que no sean numericos, 
   con este tipo no se pueden gacer operaciones matematicas, ejemplo el nombre de alguien,su color favorito, 
   algun tipo de codigo que contenga *,#,/ etc. */
   
    //2 suma, resta 
    int n1;    
    int n2;
    cout<<"ingrese el primer numero: ";cin>>n1;
    cout<<"ingrese el segundo numero: ";cin>>n2;
   
    cout<<"la suma es: "<<n1+n2<<"\n";
    cout<<"la resta es: "<<n1-n2<<"\n";
    cout<<"la multiplicacion es: "<<n1*n2<<"\n";
   
    if (n2==0){cout<<"la divivsion entre cero no esta definida";}
    else {
        cout<<"la division es: "<<n1/n2<<"\n";
        cout<<"el modulo es: "<<n1 % n2<<" \n";}
      

     /*2.2
     == significa igual
    != significa diferenre 
    esto lo podemos ver normalmente en las condiciones 
    ejemplo: si a es igual a 0 hacer una funcion
    if(a== 0){c<<"a es igual a cero"
    ejemplo: si a es diferente a 0 hacer una funcion
    if(a!= 0){c<<"a no es  cero"
    
    
    2.3 
    && significa que todas las condiciones se deben cumplir 
    or significa que cualquiera de las condiciones se deben cumplir 
    ! significa que no puede estar lo que le pongamos !
    ejeplo: a == 1 && a != 0  a debe ser = 1 y 0
    ejeplo: a == 1 OR a != 0 a debe ser = 1 o 0
    ejeplo: a !1  a no puede ser = n1*/
    
    //3.1 
    int edad;
    cout<<"ingrese su edad: ";cin>>edad;
    if (edad>=18){cout<<"usted es mayor de edad";}
    else{cout<<"usted es menor de edad";}
    
    //3.2
    /* else if funciona para si no se cumple el primer if siga evaluando 
    otra condicion que le podemos
    
    */
    for (int i=0;i<= 10;i++){cout<<i<<"\n";}

}