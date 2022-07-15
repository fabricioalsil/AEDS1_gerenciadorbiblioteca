#ifndef INFRAESTRUTURA_H_INCLUDED
#define INFRAESTRUTURA_H_INCLUDED

#include "cabecalho.h"

void imprimir_toda_infraestrutura(struct infraestrutura *cab_infraestrutura, struct alunos **cab_alunos);

struct infraestrutura *busca_infraestrutura(struct infraestrutura *cab, int id);

struct infraestrutura *busca_infraestrutura_ant(struct infraestrutura *cab, int id, struct infraestrutura **ant);

void imprimir_infraestrutura(struct infraestrutura *cab, struct alunos **cab_alunos);

void inserir_infraestrutura(struct infraestrutura *cab);

void remover_infraestrutura(struct infraestrutura *cab);

void emprestar_infraestrutura(struct infraestrutura *cab, struct alunos **cab_alunos, int *id_aluno);

void devolver_infraestrutura(struct infraestrutura *cab, struct alunos **cab_alunos, int *id_aluno);

#endif // INFRAESTRUTURA_H_INCLUDED
