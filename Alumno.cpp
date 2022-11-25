#include "Alumno.hpp"
#include <iostream>
#include <conio.h> //getch()
#include <fstream> //ficheros
#include <string.h> //strspn-isDNI() stoi()??????
#include <iomanip>//formato de espaciado
#include <vector>
#include<stdlib.h> //funcion time()
#include<time.h> //random



void Alumno::login()
{
   int opcion;

    do
    {
		system("cls");
        cout<<"\n\t\t\t\t ___PORTAL ACADEMICO___\t\t\t\t\n\n";
        cout<<"\t1. Iniciar Sesi\242n\n\n";
        cout<<"\t2. Salir\n\n";
        cout<<"\tOpci\242n: ";
        cin>>opcion;

        switch(opcion)
        {

        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;
        case 1:
            iniciarSesion();
            break;
        case 2:
            break;
        }

    }while(opcion !=2);

}

void Alumno::iniciarSesion()
{

    string user,pass;
	int contador=0;
	bool ingresa=false;

	ifstream datosPaciente;
	ifstream cursos;
	cursos.open("DatosAlumnos//DNI-PASS.txt",ios::in);
    datosPaciente.open("DatosAlumnos//informacionAlumno.txt",ios::in);

	if(cursos.is_open() && datosPaciente.is_open())
	{
	    cin.ignore();// limpia buffer
		do{
			system("cls");
			cout<<"\n\n\t\t\tINICIAR SESION";
			cout<<"\n\t\t\t------------------";
			cout<<"\n\tDNI: ";
			getline(cin,user);
			cout<<"\tPassword: ";

			char caracter;
			pass = "";
			caracter= getch();
			while(caracter !=13){

				if(caracter != 8){
					pass.push_back(caracter);
					cout<<"*";
				}
				else{
					if(pass.length() >0){
						cout<<"\b \b";
						pass.pop_back();
					}
				}

				caracter=getch();
			}

			
			//busqueda de dni y password en txt
			cursos.clear();
			cursos.seekg(0);
			while(!cursos.eof()){
				getline(cursos,dni);
				getline(cursos,password);
				if(dni == user && password == pass){
					ingresa=true;
					break;
				}
			}
			//intentos
			contador++;

		} while(ingresa!=true && contador <3);


		if(ingresa == false){
			cout<<"\n\n\tEl DNI o password son incorrectos";
			cout<<"\n\tUsted no puedo ingresar al sistema .ADIOS";
			pausa();
		}

		
		else
		{
		    //obtenemos los datos del Alumno
            datosPaciente.seekg(0);
            string aux_dni;
            while(!datosPaciente.eof())
            {
                getline(datosPaciente,aux_dni);
                getline(datosPaciente,nombre);
                getline(datosPaciente,apellido);
                getline(datosPaciente,celular);
                getline(datosPaciente,direccion);
                getline(datosPaciente,correo);
                if(dni==aux_dni){
                    dni=aux_dni;
					break;
                }
            }

            cursos.close();
            datosPaciente.close();

			//pausa();
			cuenta();
		}
	}
	else{
		error();
	}

    cursos.close();
    datosPaciente.close();
    //pausa();
}

void Alumno::cuenta()
{

        int opcion;
        do{
            system("cls");
            cout<<"\n\t\t\t\t***PORTAL ACADEMICO***\t\t\t\t\n\n";
            cout<<"\n\tBienvenid@ "<<nombre<<" "<<apellido;
            cout<<"\n\n\n\t1.Ver Avance curricular";
			cout<<"\n\n\t2.Matriculas";
            cout<<"\n\n\t3.Salir";
            cout<<"\n\n\n\tOpci\242n: ";
            cin>>opcion;
			
			cin.ignore();

            switch(opcion)
            {
                default:
                    cout<<"Ha ingresado una opci\242n no valida!\n\n";
                    break;
                case 1:
                    verAvance_Curricular();
                    break;
				case 2:
                    matricularse();
                    break;
            }
        }while(opcion!=3);


}


bool is_DNI(const std::string& s)
{	
	return( strspn( s.c_str(), "0123456789" ) == s.size() ) && (s.length()==8);
}



void Alumno::verAvance_Curricular()
{
	system("cls");
	ifstream cursos;
	cursos.open("DatosAlumnos//avanceCurricular.txt",ios::in);

	if(cursos.is_open())
	{
		cout<<"\n\t\t\t\t*** AVANCE CURRICULAR ***\n\n";
		cout<<"\n\t\tSemestre                     Curso                     Tipo    Creditos   Veces    Nota Final  Aprobo\n\n";

		cursos.seekg(0);
		string aux_dni,aux_sem,aux_curso,aux_tipo,aux_cred,aux_veces,aprobo,aux;
		float aux_notaf;
		while(!cursos.eof())
		{

			getline(cursos,aux);

			if(is_DNI(aux) && dni==aux)
			{
				getline(cursos,aux_sem);
				
				do
				{
					getline(cursos,aux_curso);
					getline(cursos,aux_tipo);
					getline(cursos,aux_cred);
					getline(cursos,aux_veces);
					cursos>>aux_notaf; cursos.ignore();

					if(aux_notaf>=11.5) aprobo="Si";
					else aprobo="No";

					char separator  = ' ';
					cout<< "\t";
					cout << right << setw(10) << setfill(separator) <<aux_sem;
					cout << right << setw(46) << setfill(separator) <<codeName(stoi(aux_curso));
					cout << right << setw(10) << setfill(separator) <<aux_tipo;
					cout << right << setw(10) << setfill(separator) <<aux_cred;
					cout << right << setw(10) << setfill(separator) << aux_veces;
					cout << right << setw(13) << setfill(separator) << aux_notaf;
					cout << right << setw(7) << setfill(separator) << aprobo;
					cout << endl;

					//verificador
					getline(cursos,aux_sem);

				}while (aux_sem !="end");

			}

		}
	}
	
	cursos.close();
	pausa();

}


void Alumno::matricularse()
{
	
	ifstream cursos;
	cursos.open("DatosAlumnos//avanceCurricular.txt",ios::in);


	vector<int> aprobados;
	vector<int> desaprobados;
	vector<int> cursos_llevar;

	if(cursos.is_open())
	{
		cursos.clear();
		cursos.seekg(0);
		
		string aux_dni,aux_sem,aux_curso,aux_tipo,aux_cred,aux_veces,aprobo,aux;
		float aux_notaf;
		while(!cursos.eof())
		{
			getline(cursos,aux);
			//verica si es DNI
			if(is_DNI(aux) && dni==aux)
			{
				getline(cursos,aux_sem);
				
				do
				{
					getline(cursos,aux_curso);
					getline(cursos,aux_tipo);
					getline(cursos,aux_cred);
					getline(cursos,aux_veces);
					cursos>>aux_notaf; cursos.ignore();

					//cursos aprobados totales en avance curricular
					if(aux_notaf >=11.5)
						aprobados.push_back(stoi(aux_curso));
					else
						desaprobados.push_back(stoi(aux_curso));
					
			
					//verificador 
					getline(cursos,aux_sem);

				}while (aux_sem !="end");

			}

		}

		
		//MALLA CURRICULAR	
		int	mallaC[34][34]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},		
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
		
		
		for(int j=0;j<34;j++) //cursos
		{
			int cont=0;
			for(int k=0;k<34;k++) //prerequisitos
				if(mallaC[j][k]==1)
					cont++;
			
			int repetido=0;
			//que j no este en aprobados
			for(int v=0;v<aprobados.size();v++){
				if(j==aprobados[v]){ 
					repetido++;
				}
			}

			if(repetido != 1)
			{	
				int coinc=0;
				for (int i=0;i<aprobados.size();i++)  //aprobados 
				{
					if(mallaC[j][aprobados[i]]==1 && j!=aprobados[i])
						coinc++;
				}
				
				if(cont==coinc ) 
					cursos_llevar.push_back(j);
			}
			
		}
	
	}	
	cursos.close();


	//MATRICULAS

	vector<int> candidatosCursos;
	float code;
	int cont;

	do
	{
		system("cls");
		cout<<"\n\n\t\t***CURSOS A LLEVAR***\n\n";

		//imprimir los cursos a llevar
		cout<<"\n\n\t\t***CURSOS A LLEVAR***\n\n";
		for(int i=0;i<cursos_llevar.size();i++)
			cout<<"\t("<<cursos_llevar[i]<<") - "<<codeName(cursos_llevar[i])<<endl;
		cont=0;
		candidatosCursos.clear();

		cout<<"\n\tIngrese codigo (-1/salir)";
		cin>>code;

		do
		{
			candidatosCursos.push_back(code);
			cout<<"\n\tIngrese codigo (-1/salir)";
			cin>>code;
		}while(code!=-1);
		
		for(int i=0;i<candidatosCursos.size();i++)
			for(int j=0;j<cursos_llevar.size();j++)
				if(candidatosCursos[i]==cursos_llevar[j])
					cont++;
			
		if(cont!=candidatosCursos.size()){
			cout<<"\n\nIngreso un codigo de curso no valido.\n";
			cout<<"\tIngrese de nuevo...\n";
			getch();
		}

	}while(cont!=candidatosCursos.size());
	

	//codigo incorecto
	for(int i=0;i<candidatosCursos.size();i++)
				cout<<candidatosCursos[i];


	verHorario(candidatosCursos);

}



void Alumno::verHorario(vector<int> candidatosCursos)
{
	vector<int> horasCursos,creditaje;
	//vector<int> candidatosCursos={3,4,5,6,7,0,8};
	//agregar los horarios y creditajes respectivos de los cursos elegidos
	for(int i=0;i<candidatosCursos.size();i++)
	{
		horasCursos.push_back(horario_creditaje(candidatosCursos[i],'h'));
		creditaje.push_back(horario_creditaje(candidatosCursos[i],'c'));
	}


	//HORARIO LUNES-SABADO
	int horario[14][6]={{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1},
						{-1,-1,-1,-1,-1,-1}};


	srand(time(NULL)); //MEJORAR EL RANDOM
	int c,f;	

	for(int i=0;i<candidatosCursos.size();i++)
	{
		int h=horasCursos[i];
		while(h>0)
		{
			c= rand() % (6) ;
			f= rand() % (14) ;	

			if(horario[f-1][c]==-1 && horario[f][c]==-1 && horario[f+1][c]==-1 && f>=1 && f<13 && h>=3)
			{
				horario[f+1][c]=candidatosCursos[i];
				horario[f][c]=candidatosCursos[i];
				horario[f-1][c]=candidatosCursos[i];
				h-=3;
			}
			if(horario[f-1][c]==-1 && horario[f][c]==-1 && f>=1 && h>=2)
			{
				horario[f][c]=candidatosCursos[i];
				horario[f-1][c]=candidatosCursos[i];
				h-=2;
			}

			if(horario[f+1][c]==-1 && horario[f][c]==-1 && f<13 && h>=2)
			{
				horario[f+1][c]=candidatosCursos[i];
				horario[f][c]=candidatosCursos[i];
				h-=2;
			}

			if(horario[f][c]==-1 && h>=1 && f>=0 && h>=1)
			{
				horario[f][c]=candidatosCursos[i];
				h--;
			}

		}
	}




	cout<<endl<<"\t lunes  martes  miercoles  jueves  viernes   sabado\n";
	char separator  = ' ';
	for(int i=0;i<14;++i){
		cout<<"\n\t-------------------------------------------------------\n";
		cout<<"\t|";
		for(int j=0;j<6;++j){
			if(horario[i][j]==-1)
			{
				
				cout <<right << setw(7) << setfill(separator) <<" "<<" |";
			}
			else
			{
				cout << right << setw(7) << setfill(separator) <<horario[i][j]<<" |";
			}
		}

	}
	cout<<"\n\t-------------------------------------------------------\n\n\n";

	pausa();
}




























//►►►►-----------------------FUNCIONES-----------------------------

int horario_creditaje(int codigo,char clave)
{

	ifstream hc;
	hc.open("DatosAlumnos//horarios-creditaje.txt",ios::in);

	int _creditaje,_codigo,_hora;
	hc.clear();
	hc.seekg(0);
	while(!hc.eof())
	{
		hc>>_codigo; 
		hc>>_creditaje;
		hc>>_hora; 
        if(_codigo == codigo){
            break;
        }

	}
	hc.close();
	
	if(clave=='h'){
		return _hora;
	}
	if(clave=='c'){
		return _creditaje;
	}

}

string codeName(int codigo)
{
	string nombreCurso;
	
	switch(codigo)
	{
	case 0: nombreCurso = "Comunicacion";break;
	case 1: nombreCurso = "Estructuras Discretas I";break;
	case 2: nombreCurso = "Introduccion a la Vida Universitaria";break;
	case 3: nombreCurso = "Matematica I";break;
	case 4: nombreCurso = "Metodologia del Estudio";break;
	case 5: nombreCurso = "Programacion de Video Juegos";break;
	case 6: nombreCurso = "Apresiacion Musical";break;
	case 7: nombreCurso = "Ciencia de la Computacion I";break;
	case 8: nombreCurso = "Estructuras Discretas II";break;
	case 9: nombreCurso = "Introduccion a la Filosofia";break;
	case 10: nombreCurso = "Introduccion a la Ciencia de la Computacion";break;
	case 11: nombreCurso = "Matematica II";break;
	case 12: nombreCurso = "Persona Matrimonio y Familia";break;
	case 13: nombreCurso = "Algebra Abstracta";break;
	case 14: nombreCurso = "Antropologia Filosofica y Teologia";break;
	case 15: nombreCurso = "Apreciacion Artistica";break;
	case 16: nombreCurso = "Apreciacion Literaria";break;
	case 17: nombreCurso = "Arquitectura de Computadores";break;
	case 18: nombreCurso = "Calculo I";break;
	case 19: nombreCurso = "Ciencia de la Computacion II";break;
	case 20: nombreCurso = "Desarrollo Basado en Plataformas";break;
	case 21: nombreCurso = "Algoritmo y Estructuras de Datos";break;
	case 22: nombreCurso = "Base de Datos I";break;
	case 23: nombreCurso = "Calculo II";break;
	case 24: nombreCurso = "Estadistica y Probabilidades";break;
	case 25: nombreCurso = "Teologia";break;
	case 26: nombreCurso = "Teoria de la Computacion";break;
	case 27: nombreCurso = "Analisis Numerico";break;
	case 28: nombreCurso = "Analisis y Diseño de Algoritmos";break;
	case 29: nombreCurso = "Base de Datos II";break;
	case 30: nombreCurso = "Fisica Computacional";break;
	case 31: nombreCurso = "Ingenieria de Software I";break;
	case 32: nombreCurso = "Moral";break;
	case 33: nombreCurso = "Teatro";break;
	}
	
	return nombreCurso;
	
}

void pausa()
{
    cout<<"\n\n\tPresiona Enter para Salir...";
    getch();
    system("cls");
}


void error()
{
	cout<<"\nNo se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
	cout<<"la misma ubicaci\242n que el programa o que el archivo de texto  \n";
}