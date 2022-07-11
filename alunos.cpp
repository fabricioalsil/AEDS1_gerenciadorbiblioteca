#include <iostream>
#include <string>
#include "alunos.h"

using namespace std;

struct alunos{  //definição dos structs necessários
    string nome;
    string matricula;
    int id;
    int pendencia;
    struct alunos* prox;
};

void imprimir_todos_alunos(struct alunos *cab_alunos) {
    if (cab_alunos->prox == NULL) {
        cout << "Nenhum aluno foi matriculado!" << endl;
        return;
    }

    struct alunos *p = cab_alunos->prox;
    cout << "Alunos cadastrados:" << endl;
    while (p != NULL) {
        cout << "Nome: " << p->nome << "; ID: " << p->id << endl;
        if(p->pendencia == 0)
            cout << "Nao possui pendencias\n" << endl;
        else
            cout << "Possui pendencias\n" << endl;
        p = p->prox;
    }
}

struct alunos *busca_aluno(struct alunos *cab, int id) {
    struct alunos *p = cab->prox;
    while (p != NULL && p->id < id)
        p = p->prox;
    return p;
}

struct alunos *busca_aluno_ant(struct alunos *cab, int id, struct alunos **ant) {
    (*ant) = cab;
    struct alunos *p = cab->prox;
    while (p != NULL && p->id < id) {
        (*ant) = p;
        p = p->prox;
    }
    // p = null  : se chave 'k' nao encontrada.
    // p != null : se p->c = k, entao chave encontrada. Senao, chave nao encontrada.
    return p;
}

void imprimir_aluno(struct alunos *cab){

    int id;
    cout << "Digite o ID do aluno que deseja buscar: ";
    cin >> id;

    struct alunos *p = busca_aluno(cab, id);

    if(p != NULL && p->id == id){
        cout << "Nome: " << p->nome << "; ID: " << p->id << endl;
        if(p->pendencia == 0)
            cout << "Nao possui pendencias.\n" << endl;
        else
            cout << "Possui pendencias.\n" << endl;
    }else{
        cout << "ID nao encontrado." << endl;
    }
}


void inserir_aluno(struct alunos *cab, int id) {
    struct alunos *ant = NULL;
    struct alunos *p = busca_aluno_ant(cab, id, &ant);

    p = new alunos();
    p->prox = ant->prox;
    ant->prox = p;

    cout << "Digite o nome do aluno: ";
    cin.ignore();
    getline(cin, p->nome);
    cout << "Digite a matricula: ";
    getline(cin, p->matricula);
    p->id = id;
    p->pendencia = 0;
    system("cls");
    cout << "Aluno " << p->nome << " cadastrado com sucesso!" << endl;
}

void remover_aluno(struct alunos *cab) {
    struct alunos *ant = NULL;
    struct alunos *p;
    int id;
    cout << "Digite o ID do aluno que deseja remover: ";
    cin >> id;
    p = busca_aluno_ant(cab, id, &ant);

    system("cls");
    if (p != NULL) {
        if(p->pendencia == 0){
            ant->prox = p->prox;
            cout << "Aluno " << p->nome << " removido com sucesso!" << endl;
            free(p);
        }else{
            cout << "O aluno " << p->nome << " nao pode ser removido por possuir pendencias!" << endl;
        }
    }else {
        cout << "Aluno de ID: " << id << " nao encontrado!" << endl;
    }
}
