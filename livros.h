#include <iostream>
#include <string>
#include <stdlib.h>
#include "alunos.h"

#include <cstdlib>
#ifdef __linux__
	#define CLEAR "clear"
#elif _WIN32
	#define CLEAR "cls"
#endif

using namespace std;

#ifndef LIVROS_H_INCLUDED
#define LIVROS_H_INCLUDED

void imprimir_todos_livros(struct livros *cab_livros, struct alunos *cab_alunos);

struct livros *busca_livro(struct livros *cab, int id);

struct livros *busca_livro_ant(struct livros *cab, int id, struct livros **ant);

void imprimir_livro(struct livros *cab, struct alunos *cab_alunos);

void inserir_livro(struct livros *cab, int id);

void remover_livro(struct livros *cab);

void emprestar_livro(struct livros *cab, struct alunos *cab_alunos);

void devolver_livro(struct livros *cab, struct alunos *cab_alunos);

#endif // LIVROS_H_INCLUDED
