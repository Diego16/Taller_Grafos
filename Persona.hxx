#ifndef __PERSONA__HXX___
#define __PERSONA__HXX___
#include "Persona.h"

void Persona::setNombre(string nombreIn)
{
	nombre=nombreIn;
}
void Persona::setCodigo(int codigoIn)
{
	codigo=codigoIn;
}
string Persona::getNombre()
{
	return nombre;
}
int Persona::getCodigo()
{
	return codigo;
}
bool operator == (const Persona &p1, const Persona &p2)
{
	return p1.codigo==p2.codigo;
}
bool operator != (const Persona &p1, const Persona &p2)
{
	return p1.codigo!=p2.codigo;
}
bool operator < (const Persona &p1, const Persona &p2)
{
	return p1.codigo<p2.codigo;
}
bool operator > (const Persona &p1, const Persona &p2)
{
	return p1.codigo>p2.codigo;
}
bool operator <= (const Persona &p1, const Persona &p2)
{
	return p1.codigo<=p2.codigo;
}
bool operator >= (const Persona &p1, const Persona &p2)
{
	return p1.codigo>=p2.codigo;
}
ostream& operator << (ostream &o, const Persona* p1)
{
	return o << p1->nombre<<" "<<p1->codigo;
}
#endif
