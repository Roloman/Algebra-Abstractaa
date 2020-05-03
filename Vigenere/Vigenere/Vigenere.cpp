// Vigenere.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Vigenere.h"

using std::setw;
using namespace std;


Vigenere::Vigenere()
{
    string alfabeto = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
    string ascii = "............................... !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    string clave_completa;
    string Clave_completa2;
}

Vigenere::~Vigenere()
{
    //dtor
}

string Vigenere::CompletarClave(string mensaje, string clave)
{
    string sub_clave = clave;
    string clave_completa;
    int tam_mensaje = mensaje.size();
    while (sub_clave.size() < tam_mensaje)
    {
        sub_clave += clave;
    }
    clave_completa = sub_clave.substr(0, tam_mensaje);
    return clave_completa;
}

string Vigenere::cifrar_ascii (string mensaje, string clave)
{   
    int tam_mensaje = mensaje.size();
    int tam_clave = mensaje.size();
    int tam_alfabeto = alfabeto.size();
    int pos_letra_mensaje, pos_letra_clave;
    int n;
    string msn, clv;
    string cifrado;

    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra_mensaje = mensaje[i];
        pos_letra_clave = Clave_completa[i];
        n = pos_letra_mensaje + pos_letra_clave;
        if (n > 128)
        {
            n = n % 128;
            //cout << n << '\t';
        }
        cifrado += char(n);
    }
    //cout << endl;
    return cifrado;
}

string Vigenere::descifrar_ascii(string mensaje, string clave)
{
    int tam_alfabeto = alfabeto.size();
    int pos_letra_mensaje, pos_letra_clave;
    int n;
    string msn;
    string cifrado;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra_mensaje = mensaje[i];
        pos_letra_clave = Clave_completa[i];
        n = pos_letra_mensaje - pos_letra_clave;
        if (n < 0)
        {
            n += 128;
            //cout << n << '\t';
        }
        msn = char(n);
        
        cifrado += msn;
    }
    //cout << endl;
    return cifrado;
}

//32 al 168 de ascii

void Vigenere::iteradores(string& a)
{
    string::const_iterator iterador1 = a.begin();
    while (iterador1 != a.end()) {
        cout << *iterador1;
        iterador1++;
    }
    cout << endl;
}

string Vigenere::cifrar_decimal(string mensaje, string clave)
{
    string cifrado;
    int tam = alfabeto.size();
    int pos_letra, pos_clave, tmp, n;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra = alfabeto.find(mensaje[i]);
        pos_clave = alfabeto.find(clave[i]);
        tmp = pos_clave + pos_letra;
        n = tmp;
        while (n >= tam)
        {
            n -= tam;
        }
        cifrado += alfabeto[n];
    }
    return cifrado;
}

string Vigenere::descifrar_decimal(string mensaje, string clave)
{
    string descifrado;
    int tam = alfabeto.size();
    int pos_letra, pos_clave, tmp, n;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra = alfabeto.find(mensaje[i]);
        pos_clave = alfabeto.find(clave[i]);
        tmp = pos_letra - pos_clave;
        n = tmp;
        while (n < 0)
        {
            n += tam;
        }
        descifrado += alfabeto[n];
    }
    return descifrado;
}

void Funcion_Encriptar()
{
    Vigenere emisor;
    Vigenere receptor;

    int algoritmo;
    string mensaje;
    string clave;
    string encriptado;
    string desencriptado;
    cout << "Ingrese el mensaje que desea encriptar: ";
    getline(cin, mensaje);
    cout << "Ingrese la clave de encriptacion: ";
    getline(cin, clave);
    emisor.Clave_completa = emisor.CompletarClave(mensaje, clave);
    cout << "Escriba un numero para elegir la opcion de encriptado:" << endl;
    cout << '\t' << "1 Encriptacion Numerico" << endl;
    cout << '\t' << "2 Encriptacion Ascii" << endl;
    cout << '\t' << "3 Encriptacion Hex" << endl;
    cin >> algoritmo;
    while (algoritmo < 1 || algoritmo > 3)
    {
        cout << "Intentemos esto una vez mas:" << endl;
        cout << '\t' << "1 Encriptacion Numerico" << endl;
        cout << '\t' << "2 Encriptacion Ascii" << endl;
        cout << '\t' << "3 Encriptacion Hex" << endl;
        cin >> algoritmo;
    }
    if (algoritmo == 1)
    {
        encriptado = emisor.cifrar_decimal(mensaje, emisor.Clave_completa);
        desencriptado = emisor.descifrar_decimal(encriptado, emisor.Clave_completa);
    }
    if (algoritmo == 2)
    {
        encriptado = emisor.cifrar_ascii(mensaje, emisor.Clave_completa);
        desencriptado = emisor.descifrar_ascii(encriptado, emisor.Clave_completa);
    }
    cout << "El mensaje Encriptado es: ";
    cout << encriptado << endl << endl << endl;
    cout << "El mensaje Desencriptado es: ";
    cout << desencriptado << endl << endl << endl;
}

string Vigenere::Aqui(string mensaje)
{
    string aqui = "aqui";
    int diez = 10;
    for (int i = 0; i < mensaje.size(); i++)
    {
        if ( i > 0 && i % diez == 0)
        {
            mensaje.insert(i, aqui);
            diez += 14;
        }
    }
    return mensaje;
}

string Vigenere::Completa_W(string mensaje)
{
    while (mensaje.size() % 4 != 0)
    {
        mensaje += "W";
    }
    return mensaje;
}

string Vigenere::Elimina_Aqui(string mensaje)
{
    //str.erase(10, 8);
    int diez = 10;
    for (int i = 0; i < mensaje.size(); i++)
    {
        if (i > 0 && i % diez == 0)
        {
            mensaje.erase(diez, 4);
            diez += 10;
        }
    }
    return mensaje;
}

string Vigenere::Elimina_Ws(string mensaje)
{
    string ws = "W";
    string spacio = " ";
    int posicion = mensaje.find(ws);
    while (posicion != string::npos) {
        mensaje.replace(posicion, 4, spacio);
        posicion = mensaje.find(ws, posicion + 1);
    }
    return mensaje;
}

string Vigenere::CompletarClave2(string mensaje, string clave)
{
    string sub_clave = clave;
    string clave_completa2;
    int tam_mensaje = mensaje.size();
    
    sub_clave += mensaje;
    clave_completa2 = sub_clave.substr(0, (tam_mensaje + 1));

    return clave_completa2;
}

void Vigenere::Aqui_Ws()
{
    string mensaje;
    string mensaje_aqui;
    string mensaje_Aqui_Ws;
    string clave;
    string encriptado;
    string desencriptado;
    cout << "Ingrese el mensaje que desea encriptar: ";
    getline(cin, mensaje);
    cout << "Ingrese la clave de encriptacion: ";
    getline(cin, clave);
    Clave_completa2 = CompletarClave2(mensaje, clave);
    cout << "soy clave completa 2 " << Clave_completa2 << endl;
    mensaje_aqui = Aqui(mensaje);
    cout << "Completando Aqui:" << endl;
    cout << mensaje_aqui << endl;
    mensaje_Aqui_Ws = Completa_W(mensaje_aqui);
    cout << "Completando Ws:" << endl;
    cout << mensaje_Aqui_Ws << endl;
    encriptado = cifrar_decimal(mensaje_Aqui_Ws, Clave_completa2);
    cout << "Mensaje cifrado:" << endl;
    cout << encriptado << endl;
    desencriptado = cifrar_decimal(encriptado, Clave_completa2);
    cout << "Mensaje descifrado:" << endl;
    cout << desencriptado << endl;
    mensaje_Aqui_Ws = Elimina_Ws(desencriptado);
    cout << "Mensaje sin Ws:" << endl;
    cout << mensaje_Aqui_Ws << endl;
    mensaje_aqui = Elimina_Aqui(mensaje_Aqui_Ws);
    cout << "Mensaje sin Aqui:" << endl;
    cout << mensaje_aqui << endl;
}

int main()
{   

    //Funcion_Encriptar();
    //string mensaje = "Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso.";
    //string clave = "Pablo Neruda";
    //string cifrado;
    //string descifrado;
    string mensaje1 = "Llamaremos todos a la misma hora esperando que sea tempranoooo";
    string clave1 = "gola chichon";
    string a;
    string b;
    string c;
    string d;

    string w = "hola ";
    char h = '"';

    //Funcion_Encriptar();



    /*string user;
    int ascChar;

    getline(cin, user);

    cout << user << endl;

    for (int i = 0; i < user.length(); i++)
    {
        ascChar = user[i];
        cout << ascChar << endl;
    }
    
    
    
    /*                  -v z-GCVtvoeCeYchpBxKwcCTwEoCMP59jNe8MavoerZFaCMvLWeCigCiTZ oli-zaKrCAeXDC3niC53Z8t6wk4AeBs RV nvhJmMdspBkEqcITCufXgyrtjDiiZ4nspfWD z-GCVtvoeCeBjszfqvt PFpgtFALjg9OjqHhv2w1Ja-CAqC1nr- zrIjdtdoKim
    string mensaje = "-v z-GCVtvoeCeYchpBxKwcCTwEoCMP59jNe8MavoerZFaCMvLWeCigCiTZ oli-zaKrCAeXDC3niC53Z8t6wk4AeBs RV nvhJmMdspBkEqcITCufXgyrtjDiiZ4nspfWD z-GCVtvoeCeBjszfqvt PFpgtFALjg9OjqHhv2w1Ja-CAqC1nr- zrIjdtdoKim";
    cout << "Mensaje cifrado:" << endl << endl << endl;
    cout << mensaje << endl << endl << endl;
    
    string clave = "Sharon Daniela Valdivia Begazo 191-10-45268";
    cout << "La Clave es:" << endl << endl << endl;
    cout << clave << endl << endl << endl;
    string descifrado;

    string clave_compl;
    clave_compl = CompletarClave(mensaje, clave);
    descifrado = descifrar_decimal(mensaje, clave_compl);

    cout << "El Mensaje Decifrado es:" << endl << endl << endl;
    cout << descifrado << endl;
    
    */

    
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
