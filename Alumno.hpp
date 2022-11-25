#pragma once

#include<string>
#include<vector>


using namespace std;


class Alumno
{
    private:
        string dni,password,nombre,apellido,edad,correo,celular,direccion;
        
    public:
        void login();
        void iniciarSesion();
        void cuenta();
        void verAvance_Curricular();
        void matricularse();
        void verHorario(vector<int>);

    

};

void pausa();
void error();

//my lib
string codeName(int);
int horario_creditaje(int , char);

