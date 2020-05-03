// Cesar.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "cesar.h"

using namespace std;

cesar::cesar()
{
    srand(time(NULL));
    clave = 1 + rand() % (50);
    alfabeto = "abcdefghijklmnopqrstuvwxyz ";
}

cesar::~cesar()
{
    //dtor
}

string cesar::cifrar(string mensaje)
{
    string cifrado;
    int tam = alfabeto.size();
    int pos_letra, n;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra = alfabeto.find(mensaje[i]);
        n = pos_letra + clave;
        while (n >= tam)
        {
            n =  n % tam;
        }
        cifrado += alfabeto[n];
    }
    return cifrado;
}

string cesar::decifrar(string mensaje, int key)
{
    string decifrado;
    int tam = alfabeto.size();
    int pos_letra, n;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra = alfabeto.find(mensaje[i]);
        n = pos_letra - key;
        while (n < 0)
        {
            n += tam;
        }
        decifrado += alfabeto[n];
    }
    return decifrado;
}

int cesar::ObtenerClave()
{
    return clave;
}

void cesar::RomperCifrado(string mensaje_cifrado)
{
    
    for (int i = 0; i < 50; i++)
    {
        cout << i << "  "<< decifrar(mensaje_cifrado, i) << endl << endl;
    }
}

void converssacion()
{
    cesar emisor;
    cesar receptor;
    cesar hack;
    string mensaje;
    string mensaje_cifrado;
    string mensaje_decifrado;
    
    cout << "Ingrese el mensaje que desea cifrar: ";
    getline(cin, mensaje);
    cout << "Este es el mensaje a cifrar" << endl;
    cout << mensaje << endl << endl;
    
    mensaje_cifrado = emisor.cifrar(mensaje);
    cout << "El mensaje cifrado es:" << endl;
    cout << mensaje_cifrado << endl << endl;

    mensaje_decifrado = receptor.decifrar(mensaje_cifrado, emisor.ObtenerClave());
    cout << "El mensaje decifrado es:" << endl;
    cout << mensaje_decifrado << endl << endl;

    cout << "Rompiendo el Algoritmo: " << endl;
    hack.RomperCifrado(mensaje_cifrado);
}

int main()
{
    converssacion();

    srand(time(NULL));
    int clave = 1 + rand() % (50);
    cout << clave << endl;
    /*cesar emisor;
    int key = emisor.ObtenerClave();
    cesar receptor;
    cesar hack;
    string mensaje = "estamos todos a punto de llegar al mar ";
    cout << mensaje << endl;

    string mensaje_cifrado = emisor.cifrar(mensaje);
    cout << mensaje_cifrado << endl;

    string mensaje_decifrado = receptor.decifrar(mensaje_cifrado, key);
    cout << mensaje_decifrado << endl;

    //hack.RomperCifrado(mensaje_cifrado);*/


    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
