#include <iostream>
#include<fstream>
#include<string>

using namespace std;
int hora(int codigo)
{
	ifstream h;

	h.open("Alumno//Creditos.txt",ios::in);

	int time,_codigo,cred;
	if(h.is_open())
	{
		h.clear();
		h.seekg(0);

		while(!h.eof())
		{
			h>>_codigo; h.ignore();
			h>>cred; h.ignore();
			h>>time; h.ignore();

			if(_codigo==codigo)
				break;
		}
	}
	h.close();
	return time;
	
}
int main(int argc, char *argv[]) {

	cout<<hora(27);

	return 0;
}
