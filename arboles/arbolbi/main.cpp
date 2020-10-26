#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

Nodo *crearNodo(int,Nodo *);
Nodo *arbol = NULL;

void insertarNodo(Nodo *&,int,Nodo *);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void InOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);

void menu();

int main() {
    menu();
    getch();
    return 0;
}

void menu(){

    ifstream archivo;
                archivo.open("winni.txt");
                if (!archivo.is_open()){
                    cout<<"No se pudo abrir el archivo."<<endl;
                    system("pause");
                }else{
                    string linea;
                    while(archivo.good()){
                        getline(archivo,linea); //lee linea por linea del archivo.
                        cout<< linea <<endl;
                    }
                }

    int dato,opcion,contador=0;

    do{
        cout << "MENU" <<endl;
        cout << "1.Insertar un nuevo nodo" << endl;
        cout << "2.Mostrar todo el arbol" << endl;
        cout << "3.Buscar valor en el arbol" << endl;
        cout << "4.PreOrden del arbol" << endl;
        cout << "5.InOrden del arbol" << endl;
        cout << "6.PostOrden del arbol" << endl;
        cout << "0.Salir" << endl;
        cout << "Opcion: ";
        cin>>opcion;

        switch (opcion){
            case 1: cout << "Digite un numero:";
                cin>>dato;
                insertarNodo(arbol,dato);
                system("pause");
                break;
            case 2: cout << "Mostrando Arbol" << endl;
                mostrarArbol(arbol,contador);
                system("pause");
                break;
            case 3: cout << "Digite el valor a buscar: ";
                    cin >> dato;
                    if(busqueda(arbol,dato)==true){
                        cout << "Se encontro el valor en el arbol"<< endl;
                    } else {
                        cout << "No se encontro el valor en el arbol"<< endl;
                    }
                    system("pause");
                    break;
            case 4: cout << "Mostrando el arbol en PreOrden" << endl;
                    preOrden(arbol);
                    system("pause");
                    break;
            case 5: cout << "Mostrando el arbol en InOrden" << endl;
                    InOrden(arbol);
                    system("pause");
                    break;
            case 6: cout << "Mostrando el arbol en PostOrden" << endl;
                    postOrden(arbol);
                    system("pause");
                    break;
        }
        system("cls");
    }while(opcion!=0);
}

Nodo *crearNodo(int n,Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = NULL;

    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol,int n,Nodo *padre){
    if(arbol == NULL) {
        Nodo *nuevo_nodo = crearNodo(n,padre);
        arbol = nuevo_nodo;
    } else {
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertarNodo(arbol->izq,n,arbol);
        } else {
            insertarNodo(arbol->der,n,arbol);
        }
    }
}

void mostrarArbol(Nodo *arbol,int cont){
    if(arbol == NULL){
        return;
    } else {
        mostrarArbol(arbol->der,cont+1);
        for(int i=0;i<cont;i++){
            cout << "   ";
        }
        cout << arbol->dato <<endl;
        mostrarArbol(arbol->izq,cont+1);
    }
}

bool busqueda(Nodo *arbol,int n){
    if(arbol == NULL){
        return false;
    } else if(arbol->dato == n){
        return true;
    } else if(n<arbol->dato) {
        return busqueda(arbol->izq,n);
    } else {
        return busqueda(arbol->der,n);
    }
}

void preOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    } else {
        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void InOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }else {
        InOrden(arbol->izq);
        cout << arbol->dato << " - ";
        InOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->dato << " - ";
    }
}

void eliminar(Nodo *arbol,int){
    if(arbol == NULL){
        return;
    } else if(n<arbol->dato) { // Si el valor a eliminar es menor
        eliminar(arbol->izq,n); // busca a la izquierda.
    } else if(n>arbol->dato) { // Si el valor a eliminar es mayor
        eliminar(arbol->der,n); // busca a la derecha.
    } else {
        eliminarNodo(arbol);
    }
}

Nodo *minimo(Nodo *arbol){
    if(arbol == NULL){
        return NULL;
    }
    if(arbol->izq){  // tiene hijo izq
        return minimo(arbol->izq);
    } else {   // no tiene hijo izq
        return arbol;
    }
}
