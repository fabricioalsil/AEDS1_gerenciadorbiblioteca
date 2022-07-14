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

void iniciar(struct alunos *cab_alunos, struct livros *cab_livros, struct infraestrutura *cab_infraestrutura, int *id_alunos, int *id_livros, int *num_infraestrutura){
    int opcao;
    string copiar;

    cout << "Escolha uma das opcoes abaixo: " << endl;
    cout << "1 - Comecar do zero ou primeira inicializacao" << endl;
    cout << "2 - Comecar da ultima sessao salva" << endl;
    cout << "Digite a opcao: ";
    cin >> opcao;

    system(CLEAR);

    if(opcao == 1)
        return;

    ifstream arquivo("save.txt");

    getline(arquivo, copiar);
    *id_alunos = stoi(copiar);
    struct alunos *antp = cab_alunos;
    struct alunos *p;
    cout << cab_alunos->prox << endl;
    for(int i=0; i<*id_alunos; i++){
        p = antp->prox;
        p = new alunos();
        if(i==0)
            cab_alunos->prox = p;
        getline(arquivo, p->nome);
        getline(arquivo, p->matricula);
        getline(arquivo, copiar);
        p->id = stoi(copiar);
        getline(arquivo, copiar);
        p->pendencia = stoi(copiar);
        p->prox = NULL;
        antp = p;
    }

    arquivo >> *id_livros;
    struct livros *antq = cab_livros;
    struct livros *q;
    for(int i=0; i<*id_livros; i++){
        q = antq->prox;
        q = new livros();
        if(i==0)
            cab_livros->prox = q;
        getline(arquivo, q->nome);
        arquivo >> q->ano;
        getline(arquivo, q->categoria);
        arquivo >> q->id;
        arquivo >> q->estado;
        arquivo >> q->id_aluno;
        q->prox = NULL;
        antq = q;
    }

    arquivo >> *num_infraestrutura;
    struct infraestrutura *antr = cab_infraestrutura;
    struct infraestrutura *r;
    for(int i=0; i<*num_infraestrutura; i++){
        r = antr->prox;
        r = new infraestrutura();
        if(i==0)
            cab_infraestrutura->prox = r;
        arquivo >> r->id;
        arquivo >> r->tipo;
        arquivo >> r->estado;
        arquivo >> r->id_aluno;
        r->prox = NULL;
        antr = r;
    }

    arquivo.close();
    return;
}

void encerrar(struct alunos *cab_alunos, struct livros *cab_livros, struct infraestrutura *cab_infraestrutura, int id_alunos, int id_livros, int num_infraestrutura){
    int opcao;
    cout << "Escolha uma das opcoes abaixo:" << endl;
    cout << "1 - Encerrar sem salvar." << endl;
    cout << "2 - Salvar e encerrar." << endl;
    cout << "Digite a opcao: ";
    cin >> opcao;

    system(CLEAR);

    if(opcao == 1)
        return;

    ofstream arquivo("save.txt");

    arquivo << id_alunos << endl;
    struct alunos *p = cab_alunos->prox;
    struct alunos *antp = cab_alunos->prox;
    while(p != NULL){
        arquivo << p->nome << endl;
        arquivo << p->matricula << endl;
        arquivo << p->id << endl;
        arquivo << p->pendencia << endl;
        p = p->prox;
        free(antp);
        antp = p;
    }

    arquivo << id_livros << endl;
    struct livros *q = cab_livros->prox;
    struct livros *antq = cab_livros->prox;
    while(q != NULL){
        arquivo << q->nome << endl;
        arquivo << q->ano<< endl;
        arquivo << q->categoria << endl;
        arquivo << q->id << endl;
        arquivo << q->estado << endl;
        arquivo << q->id_aluno << endl;
        q = q->prox;
        free(antq);
        antq = q;
    }

    arquivo << num_infraestrutura << endl;
    struct infraestrutura *r = cab_infraestrutura->prox;
    struct infraestrutura *antr = cab_infraestrutura->prox;
    while(r != NULL){
        arquivo << r->id << endl;
        arquivo << r->tipo << endl;
        arquivo << r->estado << endl;
        arquivo << r->id_aluno << endl;
        r = r->prox;
        free(antr);
        antr = r;
    }

    arquivo.close();
    return;
}
