#include "Grafo.h"
#include <iostream>
#include <fstream>
using namespace std;
struct Persona
{
  int codigo;
  string nombre;
};
bool loadFile(string nombreArchivo, Graph<Persona> &tRed);
vector<string> tokenizer(string toTokenize, char token);
int main(int argc, char const *argv[]) {
        Graph<Persona> *tRed= new Graph<Persona>(true);
        return 0;
}
bool loadFile(string nombreArchivo, Graph<Persona> &tRed)
{
	bool success = false;
	string line;
  int lines=0, usuarios=0;
	ifstream myfile(nombreArchivo.c_str());
	vector<string> tokenizedLine;
	if (myfile.is_open())
	{
		while((myfile.peek()!=EOF))
		{
      lines++;
			Persona newPerson;
			getline (myfile,line);
			tokenizedLine = tokenizer(line, ' ');
      if(lines==1)
      {
        
      }
			newPerson.codigo = stoi(tokenizedLine[1]);
			newPerson.nombre = tokenizedLine[0];
			tRed.addVertex(newPerson);
		}
	}
	else
		return false;
	myfile.close();
	return true;
}
vector<string> tokenizer(string toTokenize, char token)
{
	vector<string> tokenizedLine;
	string aux;
	int i = 0;
	while( i <= toTokenize.size())
	{
		if(toTokenize[i] == token)
		{
			i++;
			tokenizedLine.insert(tokenizedLine.begin(), aux );
			aux.clear();
		}
		aux += toTokenize[i];
		i++;
	}
	aux.resize(aux.size() - 2);
	tokenizedLine.insert(tokenizedLine.begin(), aux );
	return tokenizedLine;
}
