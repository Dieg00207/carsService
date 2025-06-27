#include<iostream>
#include<string>
#include<cctype>
#include<fstream>
#include<algorithm>
#include<limits>
#include<ctime>
using namespace std;

struct cliente {
    string nombre;
    string ident;
    char sexo;
    int fechas[3];
} clientes[20];
int contCl=0;

struct carro {
    string placa;
    string marca;
    string modelo;
    int year;
    string color;
    int tipo;
    string tipos[6]={"Camioneta", "Sedan", " Pick Up", "Camion", "Autobus", "Moto"};
}carros[20];
int contcar=0;

struct servicio {
    int horaentr[2];
    int horasalid[2];
    int servicio[4];    
}servicios[20];
int contserv=0;

struct fact {
    cliente datosCl;
    carro datosCar;
    servicio datosServ;
}facturas[20];
int contfacts=0;

void agregardatosfichero(int num_cl, int &numserv) {
    ofstream fichE("Fichero1.txt");
        if (!fichE) {
            cout << "ERROR AL ABRIR EL FICHERO\n";
            exit(EXIT_FAILURE);
        } else {
            for (int i = 0; i < num_cl; i++) {
                fichE << clientes[i].ident << endl;
                fichE << clientes[i].nombre << endl;
                fichE << carros[i].placa << endl;
                fichE << clientes[i].sexo << endl;
                for(int j=0;j<3;j++){
                fichE << clientes[i].fechas[j]<< endl;
                } 
                for(int j=0;j<numserv;j++){
                fichE << servicios[i].servicio[j];
                }
                
                fichE << carros[i].marca << endl;
                fichE << carros[i].modelo << endl;
                fichE << carros[i].tipo << endl;
            }
        }
        fichE.close();
    }

bool compararIdentidades(const string& id1, const string& id2) {
    string cleanId1 = id1;
    string cleanId2 = id2;

    // Eliminar espacios en blanco de las identificaciones
    cleanId1.erase(remove_if(cleanId1.begin(), cleanId1.end(), ::isspace), cleanId1.end());
    cleanId2.erase(remove_if(cleanId2.begin(), cleanId2.end(), ::isspace), cleanId2.end());

    return cleanId1 == cleanId2;
}

void validarrepetido(cliente clientes[], int contCl){
    for(int i = 0; i < contCl; i++) {
        for(int j = i + 1; j < contCl; j++) {
            if(compararIdentidades(clientes[i].ident, clientes[j].ident)) {
                cout << "CLIENTE N" << char(167) << i+1 << " REPETIDO!" << endl;
            }
        }
    }
}


bool identidad(const string& identidad) {
    //tamaño
    if (identidad.length() != 13) {
        cout << "El numero de identidad debe tener 13 caracteres." << endl;
        return false;
    }
    //verificar tipo de dato
    for (char c : identidad) {
        if (!isdigit(c)) {
            cout << "El numero de identidad debe contener solo digitos." << endl;
            return false;
        }
    }
    return true; //identidad valida
}

bool nombre(const string& nombre) {
    // Verificar si el nombre está vacío
    if (nombre.empty()) {
        cout << "El nombre no puede estar vacio." << endl;
        return false;
    }
    // Verificar si todos los caracteres son letras o espacios
    for (char c : nombre) {
        if (!isalpha(c) && !isspace(c)) {
            cout << "El nombre solo puede contener letras y espacios." << endl;
            return false;
        }
    }
    return true; // El nombre es válido
}
bool sexo(char sexo){
    if(tolower(sexo) != 'm' && tolower(sexo) != 'f'){
        cout<<"Opcion invalida"<<endl;
        return false;
    }
    return true;
}

int calcularEdad(cliente fechas) {
    // Obtener la fecha y hora actual
    time_t now = time(0);
    tm *fechaActual = localtime(&now);

    // Obtener el año actual
    int yearActual = fechaActual->tm_year + 1900;
    int mesActual = fechaActual->tm_mon + 1;
    int diaActual = fechaActual->tm_mday;

    // Calcular la edad
    int edad = yearActual - fechas.fechas[2];
    
    // Verificar si aún no ha cumplido años este año
    if (mesActual < fechas.fechas[1] || (mesActual == fechas.fechas[1] && diaActual < fechas.fechas[0])) {
        edad--;
    }

    return edad;
}


bool placa(const string& placa){
    //verificar longitud
    if(placa.length() != 7){  // Compara la longitud con 7
        cout << "Numero de caracteres invalido" << endl;
        return false;
    }
    return true; //placa es válida
}


bool anio(int year) {
    if (cin.fail()) {
        cout << "Ingrese un a"<<char(164)<<"o valido." << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }


    // Verificar si la edad está en el rango válido
    if(year<1960||year>2025){
        cout<<"A"<<char(164)<<"o invalido"<<endl;
        return false;
    }

    return true;

}
bool tipo(int tipo) {
    if (cin.fail()) {
        cout << "Ingrese una opcion valida" << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    // Verificar si la edad está en el rango válido
    if(tipo<1||tipo>6){
        cout<<"Ingrese una opcion valida"<<endl;
        return false;
    }

    return true;

}

bool servs(int &servs) {
    if (cin.fail()) {
        cout << "Ingrese una opcion valida." << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    // Verificar si la edad está en el rango válido
    if(servs<1||servs>4){
        cout<<"Opcion invalida"<<endl;
        return false;
    }

    return true;

}

bool numservs(int servicio, int cont, int numserv) { 
    if (cin.fail()) {
            cout<<"Opcion no validad"<<endl;
            return false;
        }
    if(servicio<1&&servicio>4){
        cout<<"Opcion invalidad"<<endl;
        return false;
    }
        
        for (int i = 0; i < numserv; i++) {
            if (servicio == servicios[cont].servicio[i]) {
                cout << "El servicio ya ha sido seleccionado." << endl;
                return false;
            }
        }
        
    
    return true; 
}




void agregar() {
    int ingCl, num_cl, i=0;
    do {
        cout << char(168) << "Cuantos clientes desea ingresar" << char(63) << endl;
        cin >> num_cl;
        cin.ignore();
        
        for (i; i < num_cl; i++) {
            cout << "DATOS CLIENTE N" << char(167) << i + 1 << endl;

            //validarrepetido(clientes, contCl);
            cout << "Identidad: " << endl;
            getline(cin, clientes[i].ident);
            while (!identidad(clientes[i].ident)) {
            cout << "Por favor, ingrese un numero de identidad válido: ";
            getline(cin, clientes[i].ident);}
            
            

            cout << "Nombre: "<<endl;
            getline(cin, clientes[i].nombre);
            while (!nombre(clientes[i].nombre)) {
            cout << "Por favor, ingrese un nombre válido: ";
            getline(cin, clientes[i].nombre);}

            cout << "Sexo (M/F): "<<endl;
            cin >> clientes[i].sexo;
            while(!sexo(clientes[i].sexo)){
                cout<<"Ingrese una opcion valida"<<endl;
                cin >> clientes[i].sexo;
            }
            cin.ignore();
            
        
            cout << "Ingrese el dia de nacimiento: ";
            cin >> clientes[i].fechas[0];
            cin.ignore();            
            
            cout << "Ingrese el mes de nacimiento (1-12): ";
            cin >> clientes[i].fechas[1];
            cin.ignore();  
            cout << "Ingrese el año de nacimiento: ";
            cin >> clientes[i].fechas[2];
            cin.ignore();  

            // Calcular la edad
            int edad = calcularEdad(clientes[i]);
            cout << "Edad: " <<endl;
            cout<<edad<<endl;


            cout << "Placa: "<<endl;
            getline(cin, carros[i].placa);
            while(!placa(carros[i].placa)){ // Corregido aquí
                cout<<"Ingrese una placa valida"<<endl;
                getline(cin, carros[i].placa); // y aquí
            }
            

            cout << "Marca: "<<endl;
            getline(cin, carros[i].marca);
        

            cout << "Modelo: "<<endl;
            getline(cin, carros[i].modelo);

            cout << "A" << char(164) << "o: "<<endl;
            cin >> carros[i].year;
            while(!anio(carros[i].year)){
                cout<<"Ingrese un a"<<char(164)<<"o valido"<<endl;
                 cin >> carros[i].year;
            }
            cin.ignore();

            cout << "Color: "<<endl;
            getline(cin, carros[i].color);

            cout << "Tipo\n1. Camioneta\n2. Sedan\n3. Pick up\n4. Camion\n5. Autobus\n6. Moto" << endl;
            cin >> carros[i].tipo;
            while(!tipo(carros[i].tipo)){
                cout<<"Ingrese una opcion validad"<<endl;
                cin>>carros[i].tipo;
            }
            cin.ignore();


            int numserv;
            cout << "De cuantos servicios desea disponer" << endl;
            cin >> numserv;
            while(!servs(numserv)){
                cout<<"Ingrese un numero valido"<<endl;
                cin>>carros[i].tipo;
            }
            cin.ignore();
          

            
            cout << char(168) << "Que atencion es la que necesita" << char(63) << endl;
            cout << "1. Lavado\n2. Engrase\n3. Parqueo\n4. Cambio de aceite" << endl;
            for (int j = 0; j < numserv; j++) {
            int servicio;
            cin >> servicio;
            while (!numservs(servicio, contserv, j)) {
            cout << "Ingrese una opción válida:" << endl;
            cin >> servicio;
    }
    servicios[contserv].servicio[j] = servicio; // Almacenamos el servicio válido
}
cin.ignore();

    //AQUI LO DE FACT DE AGREGAR
        //FIN

contcar++;
contCl++;
contserv++;
agregardatosfichero(num_cl, numserv);
	}
  
    cout << "Desea ingresar otro cliente? \n1. SI\n2. NO" << endl;
        cin >> ingCl;
        cin.ignore();
        switch (ingCl) {
            case 1:{
                num_cl+=contCl;
				break;
				}
            default:{
                ingCl = 2;
                break;
				}
                }
   }while(ingCl==1);
}


int main(){
    int menu;
        cout<<"\nDesea agregar"<<endl;
        cout<<"1. SI\n2. Salir"<<endl;
        cin>>menu;
        //cin.ignore();
        switch(menu){
            case 1: {
                agregar();
                break;
            }
            case2: {
                break;
            }
            default :{
                cout<<"OPCION NO VALIDA!!";
            }
        }
	
    
	
    return 0;
}