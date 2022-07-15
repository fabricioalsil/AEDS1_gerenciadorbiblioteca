#include "cabecalho.h"

void iniciar(struct alunos **cab_alunos, struct livros **cab_livros, struct infraestrutura *cab_infraestrutura, int *id_alunos, int *id_livros, int *num_infraestrutura){
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
    cab_alunos = (struct alunos **)realloc(cab_alunos, (*id_alunos)*sizeof(struct alunos*));
    for(int i=0; i<*id_alunos; i++){
        cab_alunos[i] = new alunos();
        getline(arquivo, cab_alunos[i]->nome);
        getline(arquivo, cab_alunos[i]->matricula);
        getline(arquivo, copiar);
        cab_alunos[i]->id = stoi(copiar);
        getline(arquivo, copiar);
        cab_alunos[i]->pendencia = stoi(copiar);
    }

    getline(arquivo, copiar);
    *id_livros = stoi(copiar);
    cab_livros = (struct livros **)realloc(cab_livros, (*id_livros)*sizeof(struct livros*));
    for(int i=0; i<*id_livros; i++){
        cab_livros[i] = new livros();
        getline(arquivo, cab_livros[i]->nome);
        getline(arquivo, copiar);
        cab_livros[i]->ano = stoi(copiar);
        getline(arquivo, cab_livros[i]->categoria);
        getline(arquivo, copiar);
        cab_livros[i]->id = stoi(copiar);
        getline(arquivo, copiar);
        cab_livros[i]->estado = stoi(copiar);
        getline(arquivo, copiar);
        cab_livros[i]->id_aluno = stoi(copiar);
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

void encerrar(struct alunos **cab_alunos, struct livros **cab_livros, struct infraestrutura *cab_infraestrutura, int id_alunos, int id_livros, int num_infraestrutura){
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
    for(int i=0; i < id_alunos; i++){
        if(cab_alunos[i]==NULL)
            continue;
        arquivo << cab_alunos[i]->nome << endl;
        arquivo << cab_alunos[i]->matricula << endl;
        arquivo << cab_alunos[i]->id << endl;
        arquivo << cab_alunos[i]->pendencia << endl;
        free(cab_alunos[i]);
        cab_alunos[i] = NULL;
    }

    arquivo << id_livros << endl;;
    for(int i=0; i < id_livros; i++){
        if(cab_livros[i]==NULL)
            continue;
        arquivo << cab_livros[i]->nome << endl;
        arquivo << cab_livros[i]->ano<< endl;
        arquivo << cab_livros[i]->categoria << endl;
        arquivo << cab_livros[i]->id << endl;
        arquivo << cab_livros[i]->estado << endl;
        arquivo << cab_livros[i]->id_aluno << endl;
        free(cab_livros[i]);
        cab_livros[i] = NULL;
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
