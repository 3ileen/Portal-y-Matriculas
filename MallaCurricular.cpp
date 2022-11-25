#include <iostream>
#include<stdlib.h>
#include<fstream>
#include <string>
#include<vector>
using namespace std;

string nameReduce(int codigo)
{
	string nombreCurso;
	switch(codigo)
	{
		case 0: nombreCurso = "Comu";break;
		case 1: nombreCurso = "E.D. I";break;
		case 2: nombreCurso = "I.V.U.";break;
		case 3: nombreCurso = "Mat I";break;
		case 4: nombreCurso = "M. del Estudio";break;
		case 5: nombreCurso = "P.V.J";break;
		case 6: nombreCurso = "A. Musical";break;
		case 7: nombreCurso = "CCOMP I";break;
		case 8: nombreCurso = "ED II";break;
		case 9: nombreCurso = "I. Filosofia";break;
		case 10: nombreCurso = "I. CCOMP";break;
		case 11: nombreCurso = "Mate II";break;
		case 12: nombreCurso = "P.M.F.";break;
		case 13: nombreCurso = "Algebra Abstr";break;
		case 14: nombreCurso = "A.F.T.";break;
		case 15: nombreCurso = "A. Art";break;
		case 16: nombreCurso = "A. Lit";break;
		case 17: nombreCurso = "Arqui de Comp";break;
		case 18: nombreCurso = "Cal I";break;
		case 19: nombreCurso = "CCOMP II";break;
		case 20: nombreCurso = "D.B.P.";break;
		case 21: nombreCurso = "Algor y Estruc de D.";break;
		case 22: nombreCurso = "B.D I";break;
		case 23: nombreCurso = "Cal II";break;
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

int main(){
	
	ifstream cursos;
	
	cursos.open("Alumno/Cursos.txt",ios::in);
	if(cursos.is_open())
	{
		cursos.seekg(0);
		
		string n_cursos;
			
		getline(cursos,n_cursos);
		
		

	
		int aprobados[]={0,1,2,4};
		int len_aprobados=sizeof(aprobados)/sizeof(*aprobados);
		vector <int> desaprobados={3};
		vector<int> cursos_llevar;
		
		
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
			
			int verify=0;
			//que j no este en aprobados
			for(int v=0;v<len_aprobados;v++){
				if(j==aprobados[v]){
					verify++;
				}
			}

			if(verify != 1)
			{	
				int coinc=0;
				for (int i=0;i<len_aprobados;i++)  //aprobados 
				{
					if(mallaC[j][aprobados[i]]==1 && j!=aprobados[i])
						coinc++;
				}
				
				if(cont==coinc && cont!=0  )
					cursos_llevar.push_back(j);
			
			}
			
			
		}
		// concatenacion de desaprobados y cursos a llevar
		for(int i=0;i<desaprobados.size();i++)
			cursos_llevar.push_back(desaprobados[i]);
		

		//imprimir los cursos a llevar
		
		for(int i=0;i<cursos_llevar.size();i++)
			cout<<cursos_llevar[i]<<" ";
		
		
		
		
		
	}	
	
	
	cursos.close();
	

	
	return 0;
}



