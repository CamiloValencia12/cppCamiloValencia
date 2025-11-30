#include <iostream>
using namespace std;
 // Parte 1.1 

class Vehiculo{
    private:
      string marca;
      string modelo;
      int año;
      double velocidadMaxima;
      
    public: //constructor
     Vehiculo(string mar,string mod, int a, double vM){
         marca=mar;
         modelo=mod;
         año= a;
         velocidadMaxima=vM;
     }
    //getter
    string getMarca(){
        return marca;
    }
    string getModelo(){
        return modelo;
    }
    int getAño(){
        return año;
    }
    double getVelocidadMaxima(){
        return velocidadMaxima;
    }
    
    //setter
    void setMarca(string mar){
        marca=mar;
    }
    void setModelo(string mod){
        modelo=mod;
    }
    void setAño(int a){
        año=a;
    }
    void setAcelerar(double vM){
        velocidadMaxima=vM;
    }
    
     void mostrarInfo(){
        cout << "============ informacion del vehiculo ==========" <<endl;
        cout<<"Marca: "<<marca<<endl;
        cout<<"Modelo: "<<modelo<<endl;
        cout<<"Año: "<<año<<endl;
        cout<<"velocidad Maxima: "<<velocidadMaxima<<endl;
    }
};
// Parte 1.2:

class Producto{
    private:
      string codigo;
      string nombre;
      double precio;
      int cantidad;
      
    public: //constructor
     Producto(string cod,string nom, double pre, int can){
         codigo=cod;
         nombre=nom;
         precio=pre;
         cantidad=can;
     }
    //getter
    string getCodigo(){
        return codigo;
    }
    string getNombre(){
        return nombre;
    }
    int getPrecio(){
        return precio;
    }
    double getCantidad(){
        return cantidad;
    }
    
    //setter
    void setCodigo(string cod){
        codigo=cod;
    }
    void setNombre(string nom){
        nombre=nom;
    }
    void setPrecio(double pre){
        precio=pre;
    }
    void setCantidad(int can){
        cantidad=can;
    }
    void mostrarINfo(){
        cout<<"========== Informacion del producto =========="<<endl;
        cout<<"Codigo: "<<codigo<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Precio: "<<precio<<endl;
        cout<<"Cantidad: "<<cantidad<<endl;
    }
};
int main(){
    //por teclado
    string marca1,modelo1;
    int año1;
    double velocidadMaxima1;
    cout<<"======= Datos del primer vehiculo======";
    cout<<"\nMarca: ";
    getline(cin,marca1);
    cout<<"Modelo: ";
    getline(cin,modelo1);
    cout<<"Año, 'debe ser mayor a 1886': ";
    cin>>año1;
    while(año1<1886 || año1> 2027){
        cout<<"El año no es correcto"<<endl;
        cout<<"ingrese el año correcto del vehiculo: ";cin>>año1;
    }
    cout<<"Velocidad Maxima: ";cin>>velocidadMaxima1;
    //creo un vehiculo
    Vehiculo v1(marca1,modelo1,año1,velocidadMaxima1);
    //muestro la informacion
    v1.mostrarInfo();

    
    cout << "============ incremento de velocidad maxima ==========" <<endl;
    double incremento;
    double nuevaVelocidadM;
    cout<<"cual es el incremento a la velocidad maxima?: ";cin>>incremento;
    nuevaVelocidadM=velocidadMaxima1+incremento;
    cout<<"\n==== datos del vehiculo con la velocidad maxima redefinida ===="<<endl;
    v1.setAcelerar(nuevaVelocidadM);
    v1.mostrarInfo();
    
    //con valores ya definidos 
    cout<<"== DATOS DEL VEHICULO YA DEFINIDOS =="<<endl;
    Vehiculo v2("bmw","m2 competition",2025,250);
    double velocidad_M=250;
    v2.mostrarInfo();
    double incremento1=30;
    double nuevaVelocidadM1 = velocidad_M+incremento1;
    v2.setAcelerar(nuevaVelocidadM1);
    v2.mostrarInfo();

//Parte 1.2:

    string codigo1,nombre1;
    double precio1;
    int cantidad1;
    cout<<"======== Datos del primer producto======="<<endl;
    cout<<"\nCodigo: ";cin>>codigo1; 
    cout<<"Nombre: ";cin>>nombre1;
    cout<<"Precio: ";cin>>precio1;
    cout<<"Cantidad: ";cin>>cantidad1;
    
    //creo un producto
    Producto p1(codigo1,nombre1,precio1,cantidad1);
    p1.mostrarINfo();
    
    cout<<"\n ======= Precio con descuento ======"<<endl;
    double porcentaje,descuentoT,valorT;
    cout<<"cual es el porcentaje a descontar?: ";cin>> porcentaje;
    descuentoT= precio1-(porcentaje/100*precio1);
    valorT= precio1*cantidad1;
    cout<<"==== Producto con descuento y valor total ==="<<endl;
    p1.mostrarINfo();
    cout<<"Precio con descuento: "<<descuentoT<<endl;
    cout<<"Valor total: "<<valorT<<endl;

}


//============= parte 2.1============
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class Vehiculo {
private:
    string marca;
    string modelo;
    int año;
    double velocidadMaxima;

public:
    // Constructor
    Vehiculo(string mar, string mod, int a, double vM) {
        marca = mar;
        modelo = mod;
        año = a;
        velocidadMaxima = vM;
    }

    // Getters
    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    int getAño() { return año; }
    double getVelocidadMaxima() { return velocidadMaxima; }

    // Setters
    void setMarca(string mar) { marca = mar; }
    void setModelo(string mod) { modelo = mod; }
    void setAño(int a) { año = a; }
    void setAcelerar(double vM) { velocidadMaxima = vM; }

    // Mostrar información
    virtual void mostrarInfo() {
        cout << "============ Informacion del Vehiculo ==========\n";
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << año << endl;
        cout << "Velocidad Maxima: " << velocidadMaxima << endl;
    }

    virtual ~Vehiculo() {}
};

//Clase derivada Auto 

class Auto : public Vehiculo {
private:
    int numeroPuertas;
    string tipoCombustible;

public:
    // Constructor
    Auto(string mar, string mod, int a, double vM, int nP, string tC)
        : Vehiculo(mar, mod, a, vM)
    {
        numeroPuertas = nP;
        tipoCombustible = tC;
    }

    // Getters
    int getNumeroPuertas() { return numeroPuertas; }
    string getTipoCombustible() { return tipoCombustible; }

    // Setters
    void setNumeroPuertas(int nP) { numeroPuertas = nP; }
    void setTipoCombustible(string tC) { tipoCombustible = tC; }

    // Sobrescribir método mostrarinfo()
    void mostrarInfo() override {
        cout << "============ Informacion del Auto ==========\n";
        Vehiculo::mostrarInfo();
        cout << "Numero de puertas: " << numeroPuertas << endl;
        cout << "Tipo de combustible: " << tipoCombustible << endl;
    }
};

// Clase derivada Motocicleta 

class Motocicleta : public Vehiculo {
private:
    bool tieneAleron;
    int cilindrada;

public:
    // Constructor
    Motocicleta(string mar, string mod, int a, double vM, bool aleron, int cil)
        : Vehiculo(mar, mod, a, vM)
    {
        tieneAleron = aleron;
        cilindrada = cil;
    }

    // Getters
    bool getTieneAleron() { return tieneAleron; }
    int getCilindrada() { return cilindrada; }

    // Setters
    void setTieneAleron(bool aleron) { tieneAleron = aleron; }
    void setCilindrada(int cil) { cilindrada = cil; }

    // Sobrescribir mostrarInfo()
    void mostrarInfo() override {
        cout << "============ Informacion de la Motocicleta ==========\n";
        Vehiculo::mostrarInfo();
        cout << "Tiene aleron: " << (tieneAleron ? "Sí" : "No") << endl;
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
};

int main() {

    Auto miAuto("Toyota", "Supra", 1993, 250, 2, "gasolina");
    Motocicleta miMoto("BMW", "S1000RR", 2025, 314, true, 999);
    cout << endl;
    miAuto.mostrarInfo();
    cout << endl;
    miMoto.mostrarInfo();

    return 0;
}


// ===================== parte 2.2=============

#include <iostream>
#include <string>
using namespace std;

// Clase base 
class Empleado {
protected:
    string nombreCompleto;
    string numeroEmpleado;
    double salarioBase;

public:
    // Constructor
    Empleado(string nombre, string numero, double salario)
        : nombreCompleto(nombre), numeroEmpleado(numero), salarioBase(salario) {}

    // Getters
    string getNombre() { return nombreCompleto; }
    string getNumeroEmpleado() { return numeroEmpleado; }
    double getSalarioBase() { return salarioBase; }

    // Setters
    void setNombre(string nombre) { nombreCompleto = nombre; }
    void setNumeroEmpleado(string numero) { numeroEmpleado = numero; }
    void setSalarioBase(double salario) { salarioBase = salario; }

    // Métodos virtuales
    virtual double calcularSalarioTotal() = 0;  
    virtual void mostrarInfo() {
        cout << "=============== Empleado ====================\n";
        cout << "Nombre: " << nombreCompleto << endl;
        cout << "Numero de empleado: " << numeroEmpleado << endl;
        cout << "Salario base: $" << salarioBase << endl;
    }

    virtual ~Empleado() {}
};

// Derivada EmpleadoTiempoCompleto 
class EmpleadoTiempoCompleto : public Empleado {
private:
    string beneficios;
    double bono;

public:
    // Constructor
    EmpleadoTiempoCompleto(string nombre, string numero, double salario,
                           string beneficios, double bono)
        : Empleado(nombre, numero, salario), beneficios(beneficios), bono(bono) {}

    double calcularSalarioTotal() override {
        return salarioBase + bono;
    }

    void mostrarInfo() override {
        cout << "======= Empleado de Tiempo Completo ==========\n";
        Empleado::mostrarInfo();
        cout << "Beneficios: " << beneficios << endl;
        cout << "Bono: $" << bono << endl;
    }
};

// ===================== Derivada EmpleadoPorHoras ==================
class EmpleadoPorHoras : public Empleado {
private:
    int horasTrabajadas;
    double tarifaPorHora;

public:
    // Constructor
    EmpleadoPorHoras(string nombre, string numero, double salarioBase,
                     int horas, double tarifa)
        : Empleado(nombre, numero, salarioBase),
          horasTrabajadas(horas), tarifaPorHora(tarifa) {}

    double calcularSalarioTotal() override {
        return horasTrabajadas * tarifaPorHora;
    }

    void mostrarInfo() override {
        cout << "============ Empleado por Horas ============\n";
        Empleado::mostrarInfo();
        cout << "\nHoras trabajadas: " << horasTrabajadas << endl;
        cout << "Tarifa por hora: $" << tarifaPorHora << endl;
    }
};

int main() {

    EmpleadoTiempoCompleto emp1("caamilo valencia", "0011", 35000, "Seguro medico", 5000);
    EmpleadoPorHoras emp2("luis martinez", "0029", 0, 48, 5500);

    emp1.mostrarInfo();
    cout << "Salario Total: $" << emp1.calcularSalarioTotal() << "\n\n";

    emp2.mostrarInfo();
    cout << "Salario Total: $" << emp2.calcularSalarioTotal() << "\n";

    return 0;
}

//==================== parte 3.1 ==========
#include <iostream>
#include <string>
using namespace std;

// CLASE BASE ANIMAL
class Animal {
protected:
    string nombre;
    int edad;
    double peso;

public:
    Animal(string n, int e, double p)
        : nombre(n), edad(e), peso(p) {}

    // Getters
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    double getPeso() { return peso; }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    void setPeso(double p) { peso = p; }

    // Métodos virtuales
    virtual void hacerSonido() {
        cout << nombre << " hace un sonido desconocido" << endl;
    }

    virtual void mostrarInfo() {
        cout << "==================== ANIMAL ====================\n";
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Peso: " << peso << " kg" << endl;
    }

    virtual ~Animal() {}
};

// clase mamifero
class Mamifero : public Animal {
protected:
    bool tieneColaMamifero;

public:
    Mamifero(string n, int e, double p, bool cola)
        : Animal(n, e, p), tieneColaMamifero(cola) {}

    void mostrarInfo() override {
        cout << "=============== MAMIFERO ===============\n";
        Animal::mostrarInfo();
        cout << "Tiene cola: " << (tieneColaMamifero ? "Si" : "No") << endl;
    }

    // sonido general de mamifero
    void hacerSonido() override {
        cout << nombre << " emite un sonido de mamifero." << endl;
    }
};


class Ave : public Animal {
protected:
    double envergaduraAlas;

public:
    Ave(string n, int e, double p, double alas)
        : Animal(n, e, p), envergaduraAlas(alas) {}

    void mostrarInfo() override {
        cout << "==================== AVE ====================\n";
        Animal::mostrarInfo();
        cout << "envergadura de alas: " << envergaduraAlas << " m" << endl;
    }

    
    void hacerSonido() override {
        cout << nombre << " emite un sonido de ave" << endl;
    }
};



// Perro 
class Perro : public Mamifero {
public:
    Perro(string n, int e, double p, bool cola)
        : Mamifero(n, e, p, cola) {}

    void hacerSonido() override {
        cout << nombre << " dice: Guau guau!" << endl;
    }

    void mostrarInfo() override {
        cout << "=============== PERRO ====================\n";
        Mamifero::mostrarInfo();
    }
};

//Gato
class Gato : public Mamifero {
public:
    Gato(string n, int e, double p, bool cola)
        : Mamifero(n, e, p, cola) {}

    void hacerSonido() override {
        cout << nombre << " dice: Miau" << endl;
    }

    void mostrarInfo() override {
        cout << "=================== GATO ====================\n";
        Mamifero::mostrarInfo();
    }
};

// ------- Loro -------
class Loro : public Ave {
public:
    Loro(string n, int e, double p, double alas)
        : Ave(n, e, p, alas) {}

    void hacerSonido() override {
        cout << nombre << " dice: cacao!!" << endl;
    }

    void mostrarInfo() override {
        cout << "=================== LORO ====================\n";
        Ave::mostrarInfo();
    }
};

//Aguila 
class Aguila : public Ave {
public:
    Aguila(string n, int e, double p, double alas)
        : Ave(n, e, p, alas) {}

    void hacerSonido() override {
        cout << nombre << "dice: aaaaaa!!!!!" << endl;
    }

    void mostrarInfo() override {
        cout << "==================== AGUILA ====================\n";
        Ave::mostrarInfo();
    }
};

int main() {

    Perro perro("perla", 2, 20, true);
    Gato gato("michi", 3, 4, false);
    Loro loro("paco", 2, 0.7, 0.3);
    Aguila aguila("ski", 4, 6.2, 1.2);

    perro.mostrarInfo();
    perro.hacerSonido();
    cout << endl;

    gato.mostrarInfo();
    gato.hacerSonido();
    cout << endl;

    loro.mostrarInfo();
    loro.hacerSonido();
    cout << endl;

    aguila.mostrarInfo();
    aguila.hacerSonido();

    return 0;
}

//================ parte 3.2=============

#include <iostream>
#include <string>
using namespace std;

// clase base cuenta
class Cuenta {
protected:
    string numeroCuenta;
    string propietario;
    double saldo;

public:
    Cuenta(string num, string prop, double sal)
        : numeroCuenta(num), propietario(prop), saldo(sal > 0 ? sal : 0) {}

    // Getters
    string getNumeroCuenta() { return numeroCuenta; }
    string getPropietario() { return propietario; }
    double getSaldo() { return saldo; }

    // Setters 
    void setPropietario(string p) { propietario = p; }
    void setSaldo(double s) {
        if (s >= 0) saldo = s;
    }

    
    virtual void depositar(double monto) {
        if (monto > 0) saldo += monto;
    }

    virtual void retirar(double monto) {
        if (monto > 0 && monto <= saldo) saldo -= monto;
    }

    virtual void mostrarInfo() {
        cout << "==================== CUENTA ======================\n";
        cout << "Numero de cuenta: " << numeroCuenta << endl;
        cout << "Propietario: " << propietario << endl;
        cout << "Saldo: $" << saldo << endl;
    }

    virtual ~Cuenta() {}
};

// cuenta ahorro
class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;  

public:
    CuentaAhorro(string num, string prop, double sal, double tasa)
        : Cuenta(num, prop, sal), tasaInteres(tasa) {}

    void generarInteres() {
        double interes = saldo * tasaInteres;
        saldo += interes;
        cout << "Interes generado: $" << interes << endl;
    }

    void depositar(double monto) override {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito exitoso en ahorro.\n";
        }
    }

    void retirar(double monto) override {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            cout << "Retiro realizado de ahorro.\n";
        } else {
            cout << "Fondos insuficientes en ahorro.\n";
        }
    }

    void mostrarInfo() override {
        cout << "==================CUENTA DE AHORRO ==================\n";
        Cuenta::mostrarInfo();
        cout << "Tasa de interes: " << tasaInteres * 100 << "%\n";
    }
};

// cuenta corriente
class CuentaCorriente : public Cuenta {
private:
    double limiteDescubierto;

public:
    CuentaCorriente(string num, string prop, double sal, double limite)
        : Cuenta(num, prop, sal), limiteDescubierto(limite) {}

    void solicitarDescubierto(double monto) {
        if (monto <= limiteDescubierto) {
            saldo -= monto;
            cout << "Descubierto utilizado: $" << monto << endl;
        } else {
            cout << "Limite de descubierto excedido.\n";
        }
    }

    void retirar(double monto) override {
        if (monto <= saldo) {
            saldo -= monto;
            cout << "Retiro exitoso de corriente.\n";
        } else if (monto <= saldo + limiteDescubierto) {
            double extra = monto - saldo;
            saldo = 0;
            solicitarDescubierto(extra);
        } else {
            cout << "No es posible retirar, excede el limite total.\n";
        }
    }

    void depositar(double monto) override {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito exitoso en corriente.\n";
        }
    }

    void mostrarInfo() override {
        cout << "================= CUENTA CORRIENTE==================\n";
        Cuenta::mostrarInfo();
        cout << "Limite de descubierto: $" << limiteDescubierto << endl;
    }
};


int main() {

    CuentaAhorro ahorros("123456", "Carlos", 5000, 0.02);
    CuentaCorriente corriente("789235", "luis", 2000, 1000);

    ahorros.depositar(1000);
    ahorros.mostrarInfo();
    ahorros.generarInteres();
    ahorros.mostrarInfo();

    cout << endl;

    corriente.retirar(2500); 
    corriente.mostrarInfo();

    return 0;
}

//================ parte 4.1 ============

#include <iostream>
#include <vector>
using namespace std;

// calese base Persona
class Persona {
protected:
    string nombre;
    int edad;
    string cedula;

public:
    Persona(string n, int e, string c)
        : nombre(n), edad(e), cedula(c) {}

    virtual void mostrarInfo() {
        cout << "==========PERSONA ==========\n";
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Cedula: " << cedula << endl;
    }

    virtual ~Persona() {}
};

// estudiante
class Estudiante : public Persona {
public:
    class Curso {
    public:
        string codigo;
        string nombreCurso;
        int creditos;
        string profesor;
        double calificacion;

        Curso(string c, string n, int cr, string p, double cal)
            : codigo(c), nombreCurso(n), creditos(cr),
              profesor(p), calificacion(cal) {}
    };

private:
    string carrera;
    double promedio;
    int semestre;
    vector<Curso> cursos;

public:
    Estudiante(string n, int e, string c, string carr, int sem)
        : Persona(n, e, c), carrera(carr), semestre(sem), promedio(0) {}

    void matricularCurso(Curso c) {
        cursos.push_back(c);
        cout << "curso matriculado: " << c.nombreCurso << endl;
    }

    double calcularPromedioActual() {
        if (cursos.empty()) return 0;

        double suma = 0;
        for (const auto &c : cursos)
            suma += c.calificacion;

        promedio = suma / cursos.size();
        return promedio;
    }

    void mostrarInfo() override {
        cout << "=========ESTUDIANTE ==========\n";
        Persona::mostrarInfo();
        cout << "Carrera: " << carrera << endl;
        cout << "Semestre: " << semestre << endl;
        cout << "Promedio actual: " << promedio << endl;

        cout << "\nCursos inscritos:\n";
        for (auto &c : cursos) {
            cout << " - " << c.nombreCurso 
                << " (" << c.codigo << "), "
                << "Creditos: " << c.creditos
                << ", Prof: " << c.profesor
                << ", Prom: " << c.calificacion << endl;
        }
    }
};

// clase profesor
class Profesor : public Persona {
private:
    string especialidad;
    int experiencia;
    int numeroEstudiantes;

public:
    Profesor(string n, int e, string c, string esp, int exp, int numEst)
        : Persona(n, e, c), especialidad(esp),
          experiencia(exp), numeroEstudiantes(numEst) {}

    bool estaDisponible(int hora) {
        return hora >= 8 && hora <= 16;
    }

    void mostrarInfo() override {
        cout << "========== PROFESOR ==========\n";
        Persona::mostrarInfo();
        cout << "Especialidad: " << especialidad << endl;
        cout << "Años experiencia: " << experiencia << endl;
        cout << "Número de estudiantes: " << numeroEstudiantes << endl;
    }
};

//clase persona1
class Personal : public Persona {
private:
    string puesto;
    string departamento;
    double salario;

public:
    Personal(string n, int e, string c, string p, string d, double s)
        : Persona(n, e, c), puesto(p), departamento(d), salario(s) {}

    double calcularSalarioMensual() {
        return salario;
    }

    void mostrarInfo() override {
        cout << "========== PERSONAL ==========\n";
        Persona::mostrarInfo();
        cout << "Puesto: " << puesto << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Salario mensual: $" << salario << endl;
    }
};

int main() {

    // Estudiante
    Estudiante est("camilo", 17, "1113784480", "d. sofware", 2);
    est.matricularCurso(Estudiante::Curso("MAT101", "Calculo", 4, "juan ", 45));
    est.matricularCurso(Estudiante::Curso("PROG1", "Programación", 3, "pedro", 42));

    est.calcularPromedioActual();
    est.mostrarInfo();

    cout << endl;

    // Profesor
    Profesor prof("juan", 45, "987654", "calculo", 20, 150);
    prof.mostrarInfo();
    cout << "¿Disponible a las 10? " << (prof.estaDisponible(10) ? "Sí" : "No") << endl;

    cout << endl;

    // Personal
    Personal per("marcos", 35, "456789", "Secretario", "Administracion", 1200);
    per.mostrarInfo();
    cout << "Salario mensual: $" << per.calcularSalarioMensual() << endl;

    return 0;
}