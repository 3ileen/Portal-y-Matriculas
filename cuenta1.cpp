#include <iostream>
#include<stdlib.h>
#include<fstream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int main() {
	
	
	ifstream semestre;
	ifstream nombre;
	ifstream tipo;
	ifstream creditos;
	ifstream veces;
	ifstream nota_final;
	
	semestre.open("Alumno/11115/Semestre.txt",ios::in);
	nombre.open("Alumno/11115/Nombre.txt",ios::in);
	tipo.open("Alumno/11115/Tipo.txt",ios::in);
	creditos.open("Alumno/11115/Creditos.txt",ios::in);
	veces.open("Alumno/11115/Veces.txt",ios::in);
	nota_final.open("Alumno/11115/Nota final.txt",ios::in);
	
	
	
	
	if(semestre.is_open())
	{
		int aprobados[10],desaprobados[10];
		
		cout<<"\n\nSemestre\t"<<"Curso\t\t\t\t"<<"Tipo\t\t"<<"Creditos\t"<<"Veces\t\t"<<"Nota Final\t"<<"Aprobo"<<endl;
		
		semestre.seekg(0);
		string aux_sem,aux_curso,aux_tip,aux_cred,aux_ve,aux_notaf,aprobo;
		while(!semestre.eof())//IMPRIMIR
		{
			getline(semestre,aux_sem);
			getline(nombre,aux_curso);
			if(aux_curso=="1")
			{
				aux_curso="Comunicacion\t";
			}
			else if(aux_curso=="2"){
				aux_curso="Estructuras Discretas I";}
			else if(aux_curso=="3"){
				aux_curso="I. Vida Universitaria";}
			else if(aux_curso=="4"){
				aux_curso="Matematica I\t";}
			else if(aux_curso=="5"){
				aux_curso="Metodologia\t";}
			else if(aux_curso=="6"){
				aux_curso="Programacion de V.";
			}
			getline(tipo,aux_tip);
			getline(creditos,aux_cred);
			getline(veces,aux_ve);
			getline(nota_final,aux_notaf);
			if(stoi(aux_notaf)>=11.5)
			{
				aprobo="Si";
			}
			else 
			   aprobo="No";
			
			cout<<"\n\n"<<aux_sem<<"\t\t"<<aux_curso<<"\t\t"<<aux_tip<<"\t\t"<<aux_cred<<"\t\t"<<aux_ve<<"\t\t"<<aux_notaf<<"\t\t"<<aprobo;	
		
				
			
			
			
			
			
			
		}
	}
	
	semestre.close();
	nombre.close();
	tipo.close();
	creditos.close();
	veces.close();
	nota_final.close();
	
return 0;	
}


