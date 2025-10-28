//punto 1,2,3:
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct Producto {
    string nombre;
    double precio;
    int stock;
    
    Producto(const string& n, double p=0.0, int s=0): nombre(n), precio(p), stock(s){}
    
     bool disponible() const { return stock > 0; }
    bool esValido() const { return !nombre.empty() && precio >= 0.0; }


    static string toLower(string str) {
        transform(str.begin(), str.end(), str.begin(),
                  [](unsigned char c) { return tolower(c); });
        return str;
    }

    bool operator==(const Producto& other) const {
        return toLower(nombre) == toLower(other.nombre);
    }

    bool operator<(const Producto& other) const {
        if (precio != other.precio)
            return precio < other.precio;
        return nombre < other.nombre;
    }
};


int main() {
    
    
    Producto p1("arroz ",2300,34);
    Producto p2("panela");
    Producto p3("aceite",5900,23);
    Producto p4("cafe  ");
    
    cout<<"-Nombre producto: "<<p1.nombre<<"  -$ "<<p1.precio<< "  -stock: "<<p1.stock<<"\n";
    cout<<"-Nombre producto: "<<p2.nombre<<"  -$ "<<p2.precio<< "  -stock: "<<p2.stock<<"\n";
    cout<<"-Nombre producto: "<<p3.nombre<<"  -$ "<<p3.precio<< "  -stock: "<<p3.stock<<"\n";
    cout<<"-Nombre producto: "<<p4.nombre<<"  -$ "<<p4.precio<< "  -stock: "<<p4.stock<<"\n\n";
    
    
     vector<Producto> productos = {
        {"panela", 6000, 10},
        {"arroz", 2300, 34},
        {"aceite", 5900, 23},
        {"cafe",7800,33}
    };

    sort(productos.begin(), productos.end());

    cout << "productos ordenados:\n";
    for (const auto& p : productos)
        cout << " - " << p.nombre << " $" << p.precio << "\n";

    
    Producto buscado{"ArRoZ"};
    auto it = find(productos.begin(), productos.end(), buscado);
    

    if (it != productos.end())
        cout << "\nencontrado: " << it->nombre << " $" << it->precio << "\n";
    else
        cout << "\nno encontrado.\n";
    
}

// punto 4

#include <iostream>
#include <cmath>
using namespace std;

struct Termino{
    double coef = 0.0;
    int exp = 0;
};

struct Polinomio{
    Termino partes[100];
    int numTerminos;
};

int main(){
    Polinomio miPoli;
    miPoli.numTerminos = 5;

    for(int i = 0; i < miPoli.numTerminos; i++){
        double valor = i * 2.5 - 3;
        miPoli.partes[i].coef = valor;
        miPoli.partes[i].exp = i + 1; 
    }
    cout << "Polinomio:\n";
    bool primer = true;

    for(int i = miPoli.numTerminos - 1; i >= 0; i--){
        double c = miPoli.partes[i].coef;
        int e = miPoli.partes[i].exp;
        if(c == 0) continue;
        if(primer){
            if(c < 0) cout << "-";
            primer = false;
        }else{
            cout << (c < 0 ? " - " : " + ");
        }
        c = abs(c);
        if(e == 0){
            cout << c;
        }else if(e == 1){
            if(c == 1) cout << "x";
            else cout << c << "x";
        }else{
            if(c == 1) cout << "x^" << e;
            else cout << c << "x^" << e;
        }
    }
}

// puntos 5,6,7

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Producto {
    string nombre;
    double precio;
    int stock;

    Producto(string n = "", double p = 0.0, int s = 0) {
        nombre = n;
        precio = p;
        stock = s;
    }

    bool disponible() const {
        return stock > 0;
    }

    bool esValido() const {
        return !nombre.empty() && precio >= 0;
    }
};

int main() {
    cout << "=== inventario ===" << endl;

    vector<Producto> inventario;
    inventario.push_back(Producto("manzana", 2000, 10));
    inventario.push_back(Producto("coco", 2300.20, 0));
    inventario.push_back(Producto("", 1500, 5));

    cout << "productos disponibles:" << endl;
    for (auto& p : inventario) {
        if (p.esValido() && p.disponible()) {
            cout<< p.nombre << " $" << p.precio << ", stock: " << p.stock << endl;
        }
    }
    cout << "\n==== fracciones ===" << "\n";

    struct Fraccion {
        int num;
        int den;

        Fraccion(int n = 0, int d = 1) {
            num = n;
            den = d;
            normalizar();
        }

        int mcd(int a, int b) { 
            while (b != 0) {
                int t = b;
                b = a % b;
                a = t;
            }
            return a;
        }

        void normalizar() {
            if (den == 0) den = 1;
            int g = mcd(num, den);
            num /= g;
            den /= g;
            if (den < 0) {
                den = -den;
                num = -num;
            }
        }

        void mostrar() const {
            cout << num << "/" << den;
        }
    };

    Fraccion f1(2, 4);
    Fraccion f2(3, 9);
    cout << "fracción 1: "; f1.mostrar(); cout << endl;
    cout << "fracción 2: "; f2.mostrar(); cout << endl;


    cout << "\n=== lista de contactos ===" << endl;

    struct Contacto {
        string nombre;
        string telefono;

        bool esValido() const {
            return !nombre.empty() && !telefono.empty();
        }
    };

    vector<Contacto> contactos = {
        {"camilo valencia", "311799"},
        {"pepito perez", ""},
        {"carlos martinez", "320781"}
    };

    cout << "contactos validos:" << endl;
    for (auto& c : contactos) {
        if (c.esValido()) {
            cout << "- " << c.nombre << " | Tel: " << c.telefono << endl;
        }
    }
}
