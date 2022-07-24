#include "cabecalho.h"

void iniciar_aluno(struct alunos *cab_alunos, int *id_alunos, int *qnt_alunos){

    string copiar;
    int id;
    ifstream arquivo("aluno.txt");

    getline(arquivo, copiar);
    (*id_alunos) = stoi(copiar);
    getline(arquivo, copiar);
    (*qnt_alunos) = stoi(copiar);
    struct alunos* p;
    struct alunos* ant = cab_alunos;
    for(int i=0; i<(*qnt_alunos); i++){
        p = ant->prox;
        p = new alunos();
        ant->prox = p;
        getline(arquivo, copiar);
        id = stoi(copiar);
        p->id = id;
        getline(arquivo, p->nome);
        getline(arquivo, p->matricula);
        getline(arquivo, copiar);
        p->pendencia = stoi(copiar);
        p->prox = NULL;
        ant = p;
    }

    arquivo.close();
    return;
}

void iniciar_livro(struct livros *cab_livros, int *id_livros, int *qnt_livros){

    string copiar;
    int id;
    ifstream arquivo("livro.txt");

    getline(arquivo, copiar);
    (*id_livros) = stoi(copiar);
    getline(arquivo, copiar);
    (*qnt_livros) = stoi(copiar);
    struct livros* p;
    struct livros* ant = cab_livros;
    for(int i=0; i<(*qnt_livros); i++){
        p = ant->prox;
        p = new livros();
        ant->prox = p;
        getline(arquivo, copiar);
        id = stoi(copiar);
        p->id = id;
        getline(arquivo, p->nome);
        getline(arquivo, copiar);
        p->id = stoi(copiar);
        getline(arquivo, p->categoria);
        getline(arquivo, copiar);
        p->estado = stoi(copiar);
        getline(arquivo, copiar);
        p->id_aluno = stoi(copiar);
        p->prox = NULL;
        ant = p;
    }

    arquivo.close();
    return;
}

void iniciar_infraestrutura(struct infraestrutura *cab_infraestrutura, int *num_infraestrutura, int *qnt_infraestrutura){

    string copiar;
    ifstream arquivo("infraestrutura.txt");

    getline(arquivo, copiar);
    (*num_infraestrutura) = stoi(copiar);
    getline(arquivo, copiar);
    (*qnt_infraestrutura) = stoi(copiar);
    struct infraestrutura *antr = cab_infraestrutura;
    struct infraestrutura *r;
    for(int i=0; i< (*qnt_infraestrutura); i++){
        r = antr->prox;
        r = new infraestrutura();
        antr->prox = r;
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

void encerrar_aluno(struct alunos *cab_alunos, int id_alunos, int qnt_alunos){

    ofstream arquivo("aluno.txt");

    arquivo << id_alunos << endl;
    arquivo << qnt_alunos << endl;
    struct alunos *p = cab_alunos->prox;
    struct alunos *ant = cab_alunos->prox;
    while(p != NULL){
        arquivo << p->id << endl;
        arquivo << p->nome << endl;
        arquivo << p->matricula << endl;
        arquivo << p->pendencia << endl;
        p = p->prox;
        free(ant);
        ant = p;
    }

    free(cab_alunos);
    arquivo.close();
    return;
}

void encerrar_livro(struct livros *cab_livros, int id_livros, int qnt_livros){

    ofstream arquivo("livro.txt");

    arquivo << id_livros << endl;
    arquivo << qnt_livros << endl;
    struct livros *p = cab_livros->prox;
    struct livros *ant = cab_livros->prox;
    while(p != NULL){
        arquivo << p->id << endl;
        arquivo << p->nome << endl;
        arquivo << p->ano<< endl;
        arquivo << p->categoria << endl;
        arquivo << p->estado << endl;
        arquivo << p->id_aluno << endl;
        p = p->prox;
        free(ant);
        ant = p;
    }

    free(cab_livros);
    arquivo.close();
    return;
}

void encerrar_infraestrutura(struct infraestrutura *cab_infraestrutura, int num_infraestrutura, int qnt_infraestrutura){

    ofstream arquivo("infraestrutura.txt");

    arquivo << num_infraestrutura << endl;
    arquivo << qnt_infraestrutura << endl;
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

    free(cab_infraestrutura);
    arquivo.close();
    return;
}
