#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <vector>

using std::setw;
using namespace std;


class Vigenere
{
public:
	Vigenere();
	string alfabeto;
	string Clave_completa;
	string Clave_completa2;
	string CompletarClave(string mensaje, string clave);
	string cifrar_ascii(string mensaje, string clave);
	string descifrar_ascii(string mensaje, string clave);
	void iteradores(string& a);
	string cifrar_decimal(string mensaje, string clave);
	string descifrar_decimal(string mensaje, string clave);
	//void Funcion_Encriptar();
	string Aqui(string mensaje);
	string Completa_W(string mensaje);
	string Elimina_Aqui(string mensaje);
	string Elimina_Ws(string mensaje);
	string CompletarClave2(string mensaje, string clave);
	void Aqui_Ws();

	virtual ~Vigenere();

protected:
private:

};
