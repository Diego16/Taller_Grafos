#ifndef __PERSONA__H__
#define __PERSONA__H__
#include <string.h>

using namespace std;

class Persona {

protected:
	string nombre;
	int codigo;
  friend bool operator == (const Persona &p1, const Persona &p2);
	friend bool operator != (const Persona &p1, const Persona &p2);
	friend bool operator <  (const Persona &p1, const Persona &p2);
	friend bool operator >  (const Persona &p1, const Persona &p2);
	friend bool operator <= (const Persona &p1, const Persona &p2);
	friend bool operator >= (const Persona &p1, const Persona &p2);
  friend ostream& operator << (ostream &o, const Persona* p1);
public:
	void setNombre(string nombreIn);
	void setCodigo(int codigoIn);
	string getNombre();
	int getCodigo();

};

#include "Persona.hxx"
#endif
