#include <iostream>

#include<string.h>
#include<fstream>
using namespace std;
//void lectura();

int main() {
	ifstream semestre;
	string textos;
	semestre.open("AC/Sem.txt",ios::in);
	if(semestre.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(!semestre.eof()){
		getline(semestre,textos);
		cout<<textos<<endl;
	}
	semestre.close();
	return 0;
}
/*void lectura(){
	
	int cod;
	ifstream archivo;
	
	archivo.open("codigo1.txt");
	int cod;
	ifstream archivo;

	
	archivo.open("codigo1.txt");
	
	archivo>>cod;
	archivo.close();
	int codigo;
	
	do{
		system("cls");
		cout<<"\nIngrese su codigo: ";cin>>codigo;
		if(codigo==cod){
		break;
		}
	}while(true);
	
	cout<<"\n**Bienvenido a Matrcula UCSP**";
	

}*/
