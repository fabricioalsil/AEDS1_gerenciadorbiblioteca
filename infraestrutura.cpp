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

struct alunos{  //definição dos structs necessários
    string nome;
    string matricula;
    int id;
    int pendencia;
    struct alunos* prox;
};

struct infraestrutura{
    int id;
    int tipo;
    int estado;
    int id_aluno;
    struct infraestrutura* prox;
};

void imprimir_toda_infraestrutura(struct infraestrutura *cab_infraestrutura, struct alunos *cab_alunos) {
    struct alunos *aluno;

    if (cab_infraestrutura->prox == NULL) {
        cout << "Nenhuma infraestrutura cadastrada!" << endl;
        return;
    }

    struct infraestrutura *p = cab_infraestrutura->prox;
    cout << "Infraestruturas cadastradas:" << endl;
    while (p != NULL) {
        if(p->tipo == 1)
            cout << "Sala";
        else if(p->tipo == 2)
            cout << "Computador";
        else if(p->tipo == 3)
            cout << "Armario";
        cout << "; ID: " << p->id << endl;
        if(p->estado == 0)
            cout << "Disponivel!\n" << endl;
        else{
            aluno = busca_aluno(cab_alunos, p->id_aluno);
            cout << "Sendo usado pelo aluno de matricula: " << aluno->matricula << endl;
        }
        p = p->prox;
    }
}

struct infraestrutura *busca_infraestrutura(struct infraestrutura *cab, int id) {
    struct infraestrutura *p = cab->prox;
    while (p != NULL && p->id != id)
        p = p->prox;
    return p;
}

struct infraestrutura *busca_infraestrutura_ant(struct infraestrutura *cab, int id, struct infraestrutura **ant) {
    (*ant) = cab;
    struct infraestrutura *p = cab->prox;
    while (p != NULL && p->id != id) {
        (*ant) = p;
        p = p->prox;
    }
    return p;
}

void imprimir_infraestrutura(struct infraestrutura *cab, struct alunos *cab_alunos){
    struct alunos *aluno;

    int id;
    cout << "Digite o ID deseja buscar: ";
    cin >> id;

    struct infraestrutura *p = busca_infraestrutura(cab, id);

    if(p != NULL && p->id == id){
        if(p->tipo == 1)
            cout << "Sala";
        else if(p->tipo == 2)
            cout << "Computador";
        else if(p->tipo == 3)
            cout << "Armario";
        cout << "; ID: " << p->id << endl;
        if(p->estado == 0)
            cout << "Disponivel!\n" << endl;
        else{
            aluno = busca_aluno(cab_alunos, p->id_aluno);
            cout << "Sendo usado pelo aluno de matricula: " << aluno->matricula << endl;
        }
    }else{
        cout << "ID nao encontrado." << endl;
    }
}

void inserir_infraestrutura(struct infraestrutura *cab) {
    struct infraestrutura *ant = NULL;
    int id;

    cout << "Digite a ID da infraestrutura a ser cadastrada: ";
    cin >> id;

    struct infraestrutura *p = busca_infraestrutura_ant(cab, id, &ant);

    if(p!=NULL && p->id == id){
        cout << "ID ja cadastrado" << endl;
        return;
    }
    p = new infraestrutura();
    p->prox = ant->prox;
    ant->prox = p;

    p->id = id;
    cout << "Informe o tipo da infraestrutura sendo:" << endl;
    cout << "1 - Salas" << endl;
    cout << "2 - Computadores" << endl;
    cout << "3 - Armarios" << endl;
    cout << "Digite: ";
    cin >> p->tipo;
    p->estado = 0;
    p->id_aluno = 0;
    system(CLEAR);
    if(p->tipo == 1)
        cout << "Sala";
    else if(p->tipo == 2)
        cout << "Computador";
    else if(p->tipo == 3)
        cout << "Armario";
    cout << " cadastrado com sucesso!" << endl;
}

void remover_infraestrutura(struct infraestrutura *cab) {
    struct infraestrutura *ant = NULL;
    struct infraestrutura *p;
    int id;
    cout << "Digite o ID da infraestrutura que deseja remover: ";
    cin >> id;
    p = busca_infraestrutura_ant(cab, id, &ant);

    system(CLEAR);
    if (p != NULL) {
        if (p->estado == 0){
            ant->prox = p->prox;
            if(p->tipo == 1)
                cout << "Sala";
            else if(p->tipo == 2)
                cout << "Computador";
            else if(p->tipo == 3)
                cout << "Armario";
            cout << " removido com sucesso!" << endl;
            free(p);
        }else{
            if(p->tipo == 1)
                cout << "Sala";
            else if(p->tipo == 2)
                cout << "Computador";
            else if(p->tipo == 3)
                cout << "Armario";
            cout << " esta sendo usado no momento!" << endl;
        }
    }else {
        cout << "ID: " << id << " nao encontrado!" << endl;
    }
}

void emprestar_infraestrutura(struct infraestrutura *cab, struct alunos *cab_alunos){
    int id_infraestrutura;
    int id_aluno;
    struct infraestrutura *infraestrutura;
    struct alunos *aluno;

    cout << "Digite o ID da infraestrutura que deseja ocupar: ";
    cin >> id_infraestrutura;

    infraestrutura = busca_infraestrutura(cab, id_infraestrutura);
    if(infraestrutura!=NULL && infraestrutura->id!=id_infraestrutura){
        cout << "Nao encontrado" << endl;
        return;
    }if(infraestrutura->estado!=0){
        cout << "A infraestrutura ja esta emprestada" << endl;
        return;
    }

    system(CLEAR);

    cout << "Digite o ID do aluno que deseja ocupar a infraestrutura: ";
    cin >> id_aluno;

    aluno = busca_aluno(cab_alunos, id_aluno);
    if(aluno!=NULL && aluno->id!=id_aluno){
        cout << "Aluno não encontrado" << endl;
        return;
    }

    system(CLEAR);

    cout << "Infraestrutura ocupada com sucesso!" << endl;
    aluno->pendencia++;
    infraestrutura->id_aluno = aluno->id;
    infraestrutura->estado = 1;
}

void devolver_infraestrutura(struct infraestrutura *cab, struct alunos *cab_alunos){
    int id_infraestrutura;
    int id_aluno;
    struct infraestrutura *infraestrutura;
    struct alunos *aluno;

    cout << "Digite o ID do aluno que deseja desocupar a infraestrutura: ";
    cin >> id_aluno;

    aluno = busca_aluno(cab_alunos, id_aluno);
    if(aluno!=NULL && aluno->id!=id_aluno){
        cout << "Aluno nao encontrado" << endl;
        return;
    }if(aluno->pendencia == 0){
        cout << "Aluno nao possui pendencias" << endl;
        return;
    }

    system(CLEAR);

    cout << "Digite o ID da infraestrutura a ser desocupada: ";
    cin >> id_infraestrutura;

    infraestrutura = busca_infraestrutura(cab, id_infraestrutura);
    if(infraestrutura!=NULL && infraestrutura->id!=id_infraestrutura){
        cout << "Infraestrutura encontrada" << endl;
        return;
    }if(infraestrutura->estado == 0){
        cout << "A infraestrutura ja se encontra disponivel" << endl;
        return;
    }if(infraestrutura->id_aluno != aluno->id){
        cout << "A infraestrutura se encontra ocupada com outro aluno" << endl;
        return;
    }

    system(CLEAR);

    cout << "Infraestrutura desocupada com sucesso" << endl;
    infraestrutura->estado = 0;
    aluno->pendencia--;
}
