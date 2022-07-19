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

void iniciar_aluno(struct alunos **cab_alunos, int *id_alunos, int *qnt_alunos);

void iniciar_livro(struct livros **cab_livros, int *id_livros, int *qnt_livros);

void iniciar_infraestrutura(struct infraestrutura *cab_infraestrutura, int *num_infraestrutura, int *qnt_infraestrutura);

void encerrar_aluno(struct alunos **cab_alunos, int id_alunos, int qnt_alunos);

void encerrar_livro(struct livros **cab_livros, int id_livros, int qnt_livros);

void encerrar_infraestrutura(struct infraestrutura *cab_infraestrutura, int num_infraestrutura, int qnt_infraestrutura);

#endif // ARQUIVO_H_INCLUDED
