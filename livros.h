#ifndef LIVROS_H_INCLUDED
#define LIVROS_H_INCLUDED

#include "cabecalho.h"

void imprimir_todos_livros(struct livros **cab_livros, struct alunos **cab_alunos, int *id_livro);

void imprimir_livro(struct livros **cab_livros, struct alunos **cab_alunos, int *id_livro);

void inserir_livro(struct livros **cab, int *id_livro, int *qnt_livro);

void remover_livro(struct livros **cab, int *id_livro, int *qnt_livro);

void emprestar_livro(struct alunos **cab_alunos, struct livros **cab_livros, int *id_aluno, int *id_livro);

void devolver_livro(struct alunos **cab_alunos, struct livros **cab_livros, int *id_aluno, int *id_livro);

#endif // LIVROS_H_INCLUDED
