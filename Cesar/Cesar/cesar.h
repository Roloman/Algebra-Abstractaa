#pragma once
#include <string>
#include <time.h>
using namespace std;

class cesar
{
public:
    cesar();
    string alfabeto;
    string cifrar(string mensaje);
    string decifrar(string mensaje, int key);
    int ObtenerClave();
    void RomperCifrado(string mensaje_cifrado);
    virtual ~cesar();
protected:
private:
    int clave;
};

