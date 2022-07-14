#include <iostream>
#include <string>
#include <stdlib.h>
#include "alunos.h"
#include "livros.h"
#include "infraestrutura.h"

#include <cstdlib>
#ifdef __linux__
	#define CLEAR "clear"
#elif _WIN32
	#define CLEAR "cls"
#endif

using namespace std;

#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

void iniciar(struct alunos *cab_alunos, struct livros *cab_livros, struct infraestrutura *cab_infraestrutura, int *id_alunos, int *id_livros, int *num_infraestrutura);

void encerrar(struct alunos *cab_alunos, struct livros *cab_livros, struct infraestrutura *cab_infraestrutura, int id_alunos, int id_livros, int num_infraestrutura);


#endif // ARQUIVO_H_INCLUDED
