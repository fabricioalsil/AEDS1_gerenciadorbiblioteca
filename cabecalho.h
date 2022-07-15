#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "alunos.h"
#include "livros.h"
#include "infraestrutura.h"
#include "arquivo.h"

#include <cstdlib>
#ifdef __linux__
	#define CLEAR "clear"
#elif _WIN32
	#define CLEAR "cls"
#endif

using namespace std;

struct alunos{  //definição dos structs necessários
    string nome;
    string matricula;
    int id;
    int pendencia;
    struct alunos* prox;
};

struct livros{
    string nome;
    int ano;
    string categoria;
    int id;
    int estado;
    int id_aluno;
    struct livros* prox;
};

struct infraestrutura{
    int id;
    int tipo;
    int estado;
    int id_aluno;
    struct infraestrutura* prox;
};

#endif // CABECALHO_H_INCLUDED
