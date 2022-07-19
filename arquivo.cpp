#include "cabecalho.h"

void iniciar_aluno(struct alunos **cab_alunos, int *id_alunos, int *qnt_alunos){

    string copiar;
    int id;
    ifstream arquivo("aluno.txt");

    getline(arquivo, copiar);
    (*id_alunos) = stoi(copiar);
    getline(arquivo, copiar);
    (*qnt_alunos) = stoi(copiar);
    cab_alunos = (struct alunos **)realloc(cab_alunos, (*id_alunos)*sizeof(struct alunos*));
    for(int i=0; i<(*qnt_alunos); i++){
        cab_alunos[i] = new alunos();
        getline(arquivo, copiar);
        id = stoi(copiar);
        while((i+1)<id){
            cab_alunos[i] = NULL;
            i++;
        }
        cab_alunos[i]->id = id;
        getline(arquivo, cab_alunos[i]->nome);
        getline(arquivo, cab_alunos[i]->matricula);
        getline(arquivo, copiar);
        cab_alunos[i]->pendencia = stoi(copiar);
    }

    arquivo.close();
    return;
}

void iniciar_livro(struct livros **cab_livros, int *id_livros, int *qnt_livros){

    string copiar;
    int id;
    ifstream arquivo("livro.txt");

    getline(arquivo, copiar);
    (*id_livros) = stoi(copiar);
    getline(arquivo, copiar);
    (*qnt_livros) = stoi(copiar);
    cab_livros = (struct livros **)realloc(cab_livros, (*id_livros)*sizeof(struct livros*));
    for(int i=0; i<(*qnt_livros); i++){
        cab_livros[i] = new livros();
        getline(arquivo, copiar);
        id = stoi(copiar);
        while((i+1)<id){
            cab_livros[i] = NULL;
            i++;
        }
        cab_livros[i]->id = id;
        getline(arquivo, cab_livros[i]->nome);
        getline(arquivo, cab_livros[i]->categoria);
        getline(arquivo, copiar);
        cab_livros[i]->id = stoi(copiar);
        getline(arquivo, copiar);
        cab_livros[i]->estado = stoi(copiar);
        getline(arquivo, copiar);
        cab_livros[i]->id_aluno = stoi(copiar);
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

void encerrar_aluno(struct alunos **cab_alunos, int id_alunos, int qnt_alunos){

    ofstream arquivo("aluno.txt");

    arquivo << id_alunos << endl;
    arquivo << qnt_alunos << endl;
    for(int i=0; i < id_alunos; i++){
        if(cab_alunos[i]==NULL)
            continue;
        arquivo << cab_alunos[i]->id << endl;
        arquivo << cab_alunos[i]->nome << endl;
        arquivo << cab_alunos[i]->matricula << endl;
        arquivo << cab_alunos[i]->pendencia << endl;
        free(cab_alunos[i]);
        cab_alunos[i] = NULL;
    }

    free(cab_alunos);
    arquivo.close();
    return;
}

void encerrar_livro(struct livros **cab_livros, int id_livros, int qnt_livros){

    ofstream arquivo("livro.txt");

    arquivo << id_livros << endl;
    arquivo << qnt_livros << endl;
    for(int i=0; i < id_livros; i++){
        if(cab_livros[i]==NULL)
            continue;
        arquivo << cab_livros[i]->id << endl;
        arquivo << cab_livros[i]->nome << endl;
        arquivo << cab_livros[i]->ano<< endl;
        arquivo << cab_livros[i]->categoria << endl;
        arquivo << cab_livros[i]->estado << endl;
        arquivo << cab_livros[i]->id_aluno << endl;
        free(cab_livros[i]);
        cab_livros[i] = NULL;
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
