#ifndef ALUNOS_H_INCLUDED
#define ALUNOS_H_INCLUDED

#include "cabecalho.h"

void imprimir_todos_alunos(struct alunos **cab, int *id_aluno);

void imprimir_aluno(struct alunos **cab, int *id_aluno);

void inserir_aluno(struct alunos **cab, int *id_aluno, int *qnt_aluno);

void remover_aluno(struct alunos **cab, int *id_aluno, int *qnt_aluno);

#endif // ALUNOS_H_INCLUDED
