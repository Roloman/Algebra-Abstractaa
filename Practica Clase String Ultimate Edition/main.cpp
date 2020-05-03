#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::boolalpha;

#include <string>
using std::string;


// Ejercicio 1, convertir string a char* y viceversa

void CopiaStringAChar( string cadena ){
    const char *ptr1 = 0;
    ptr1 = cadena.data();
    cout << cadena << endl;
}

void CopiaCharAString( char *ptr1 ){
    string cadena;
    cadena = ptr1;
    cout << cadena << endl;
}



void imprimirEstadisticas( const string &refString )
{
    cout << "capacidad: " << refString.capacity() << "\ntamanio max: "
    << refString.max_size() << "\ntamanio: " << refString.size()
    << "\nlongitud: " << refString.length()
    << "\nvacia: " << refString.empty();
}

int main()
{
    string cadena1 = ("1234567890");
    cout << cadena1 << endl;
    cout << "Capacidad: " << cadena1.capacity() << endl;
    cout << "tamanio: "<< cadena1.size() << endl;
    cout << "longitud: "<< cadena1.length() << endl;
    cout << "max tamnio: "<< cadena1.max_size() << endl;


    cadena1 += "1234567890";
    cout << cadena1 << endl;
    cout << "Capacidad: " << cadena1.capacity() << endl;
    cout << "tamanio: "<< cadena1.size() << endl;
    cout << "longitud: "<< cadena1.length() << endl;
    cout << "max tamnio: "<< cadena1.max_size() << endl;

    cadena1 += "12345678901234567890";
    cout << cadena1 << endl;
    cout << "Capacidad: " << cadena1.capacity() << endl;
    cout << "tamanio: "<< cadena1.size() << endl;
    cout << "longitud: "<< cadena1.length() << endl;
    cout << "max tamnio: "<< cadena1.max_size() << endl;

        cadena1 += "12345678901234567890123";
    cout << cadena1 << endl;
    cout << "Capacidad: " << cadena1.capacity() << endl;
    cout << "tamanio: "<< cadena1.size() << endl;
    cout << "longitud: "<< cadena1.length() << endl;
    cout << "max tamnio: "<< cadena1.max_size() << endl;

    /*cout << "Estadisticas antes de la entrada:\n" << boolalpha;
    imprimirEstadisticas( cadena1 );

    cout << "\n\nEscriba una cadena: ";
    cin >> cadena1;
    cout << "La cadena introducida fue: " << cadena1;

    cout << "\nEstadisticas despues de la entrada:\n";
    imprimirEstadisticas( cadena1 );

    /*cin >> cadena1;
    cout << "\n\nEl resto de la cadena es: " << cadena1 << endl;
    imprimirEstadisticas( cadena1 );

    cadena1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
    cout << "\n\ncadena1 es ahora: " << cadena1 << endl;
    imprimirEstadisticas( cadena1 );

    cadena1.resize( cadena1.length() + 10 );
    cout << "\n\nEstadisticas despues de cambiar el tamanio en base a (length + 10):\n";
    imprimirEstadisticas( cadena1 );

    cout << endl;*/
    return 0;
}
