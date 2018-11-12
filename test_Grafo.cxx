#include "Grafo.h"
#include "Persona.h"
#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <map>
#include <cstring>
using namespace std;

bool loadFile(string nombreArchivo, Graph<Persona*> &tRed, list<Persona*> &listAux);
Persona* findPersona(int code, list<Persona*> &listAux);
Persona* findPersonaN(string nombre, list<Persona*> &listAux);
vector<string> tokenizer(string toTokenize, char token);
int main(int argc, char const *argv[]) {
	Graph<Persona*> tRed= new Graph<Persona*>(true);
	list<Persona*> listAux;
	bool opt=true;
	string cmdInput = " ", input = " ", input1 = " ";
	char command[300]={' '};
	if(argc<2||argc>2)
	{
		cerr << "Uso: " << argv[0] << " Red0X.txt " << endl;
		return 1;
	}
	loadFile(argv[1],tRed,listAux);
	while(opt)
	{
		cout << "$ ";
		cin.clear();
		cin.sync();
		cin.getline(command,300);
		int cantCmd = 0;
		char* cmdList[10];
		char* piece;
		piece = strtok(command, " ");
		while (piece != NULL)
		{
			cmdList[cantCmd] = piece;
			cantCmd++;
			piece = strtok(NULL, " ");
		}
		if (strcmp(cmdList[0],"consultar")==0)
		{
			if (cantCmd==3)
			{
				Persona* auxPersona= new Persona();
				cmdInput = cmdList[1];
				cmdInput.append(" ");
				cmdInput.append(cmdList[2]);
				auxPersona=findPersonaN(cmdInput, listAux);
				if(auxPersona->getCodigo()==0)
				{
					cout<<"Esta persona no esta en la red"<<endl;
				}
				else
				{
					cout << "Siguiendo :"<<tRed.findVertex(auxPersona)->GetAdjacents().size()<<" personas"<<endl;
					multimap<Vertex<Personas*>*, Edge* >::iterator it;
					for()
					{

					}
				}
			}
			else
				cout << "** Parametros invalidos **" << endl;
		}
		else if(strcmp(cmdList[0],"report")==0)
		{
			if (cantCmd>=2)
			{
				cmdInput = cmdList[1];
				if(cmdInput=="flights")
				{
					if(cantCmd==3)
					{
						input = cmdList[2];
						input1 = "N";
					}
					else if(cantCmd==4)
					{
						input = cmdList[2];
						input1 = cmdList[3];
					}
					else
					{
						input = "N";
						input1 = "N";
					}
				}
				else if(cmdInput=="inventory")
				{
				}
				else if(cmdInput=="money")
				{
				}
				else
					cout << "** Parametros invalidos **" << endl;
			}
			else
				cout << "** Parametros invalidos **" << endl;
		}
		else if(strcmp(cmdList[0],"exit")==0)
		{
			opt=false;
		}
	}
	return 0;
}
bool loadFile(string nombreArchivo, Graph<Persona*> &tRed, list<Persona*> &listAux)
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
			Persona* newPerson= new Persona();
			string nombre=" ";
			getline (myfile,line);
			tokenizedLine = tokenizer(line, ' ');
			if(lines==0)
			{
				usuarios=stoi(tokenizedLine[0]);
			}
			else if(lines<=usuarios)
			{
				nombre=tokenizedLine[1]+" "+tokenizedLine[0];
				newPerson->setCodigo(stoi(tokenizedLine[2]));
				newPerson->setNombre(nombre);
				listAux.push_back(newPerson);
				tRed.addVertex(newPerson);
			}
			else
			{
				tRed.addEdge(findPersona(stoi(tokenizedLine[2]),listAux),findPersona(stoi(tokenizedLine[1]),listAux),stoi(tokenizedLine[0]));
			}
			lines++;
		}
	}
	else
		return false;
	myfile.close();
	return true;
}
Persona* findPersona(int code, list<Persona*> &listAux)
{
	Persona* aux = new Persona();
	for(list<Persona*>::iterator it = listAux.begin(); it!=listAux.end(); it++)
	{
		if((*it)->getCodigo()==code)
		{
			return *it;
		}
	}
	aux->setCodigo(0);
	return aux;
}
Persona* findPersonaN(string nombre, list<Persona*> &listAux)
{
	Persona* aux = new Persona();
	for(list<Persona*>::iterator it = listAux.begin(); it!=listAux.end(); it++)
	{
		if((*it)->getNombre()==nombre)
		{
			return *it;
		}
	}
	aux->setCodigo(0);
	return aux;
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
