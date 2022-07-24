#include "cabecalho.h"


void imprimir_todos_livros(struct livros *cab_livros, struct alunos *cab_alunos) {
    struct alunos *aluno;

    if (cab_livros->prox == NULL) {
        cout << "Nenhum livro cadastrado!" << endl;
        return;
    }

    struct livros *p = cab_livros->prox;
    cout << "Livros cadastrados:" << endl;
    while (p != NULL) {
        cout << "Nome: " << p->nome << "; ID: " << p->id << endl;
        if(p->estado == 0)
            cout << "Livro disponivel!\n" << endl;
        else{
            aluno = busca_aluno(cab_alunos, p->id_aluno);
            cout << "Livro emprestado para o aluno de matricula: " << aluno->matricula << endl;
        }
        p = p->prox;
    }
}

struct livros *busca_livro(struct livros *cab, int id) {
    struct livros *p = cab->prox;
    while (p != NULL && p->id < id)
        p = p->prox;
    return p;
}

struct livros *busca_livro_ant(struct livros *cab, int id, struct livros **ant) {
    (*ant) = cab;
    struct livros *p = cab->prox;
    while (p != NULL && p->id < id) {
        (*ant) = p;
        p = p->prox;
    }
    return p;
}

void imprimir_livro(struct livros *cab, struct alunos *cab_alunos){
    struct alunos *aluno;
    int contador=0;

    int opcao;
    cout << "Se deseja buscar por ID digite 1, por categoria digite 2: ";
    cin >> opcao;

    if(opcao == 2){
        struct livros *p = cab->prox;
        string categoria;
        cout << "Digite a categoria: ";
        cin.ignore();
        getline(cin, categoria);

        while (p != NULL) {
            if( p->categoria != categoria ){
                p = p->prox;
                continue;
            }
            contador++;
            cout << "Nome: " << p->nome << "; ID: " << p->id << endl;
            if(p->estado == 0)
                cout << "Livro disponivel!\n" << endl;
            else{
                aluno = busca_aluno(cab_alunos, p->id_aluno);
                cout << "Livro emprestado para o aluno de matricula: " << aluno->matricula << endl;
            }
        p = p->prox;
        }
        if(contador == 0){
            cout << "Nehnum livro da categoria " << categoria <<" foi encontrado!\n" << endl;
        }
        return;
    }
    int id;
    cout << "Digite o ID do livro que deseja buscar: ";
    cin >> id;

    struct livros *p = busca_livro(cab, id);

    if(p != NULL && p->id == id){
        cout << "Nome: " << p->nome << "; ID: " << p->id << "; Categoria: " << p->categoria << endl;
        if(p->estado == 0)
            cout << "Livro disponivel!\n" << endl;
        else{
            aluno = busca_aluno(cab_alunos, p->id_aluno);
            cout << "Livro emprestado para o aluno de matricula: " << aluno->matricula << endl;
        }
    }else{
        cout << "ID nao encontrado." << endl;
    }
}

void inserir_livro(struct livros *cab, int *id_livro, int *qnt_livro) {
    struct livros *ant = NULL;
    struct livros *p = busca_livro_ant(cab, *id_livro, &ant);

    p = new livros();
    p->prox = ant->prox;
    ant->prox = p;

    cout << "Digite o nome do livro: ";
    cin.ignore();
    getline(cin, p->nome);
    cout << "Digite a categoria: ";
    getline(cin, p->categoria);
    cout << "Digite o ano de publicacao: ";
    cin >> p->ano;
    p->id = *id_livro;
    p->estado = 0;
    system(CLEAR);
    cout << "Livro " << p->nome << " de " << p->ano << " cadastrado com sucesso!" << endl;
    (*id_livro)++;
    (*qnt_livro)++;
}

void remover_livro(struct livros *cab, int *qnt_livro) {
    struct livros *ant = NULL;
    struct livros *p;
    int id;
    cout << "Digite o ID do livro que deseja remover: ";
    cin >> id;
    p = busca_livro_ant(cab, id, &ant);

    system(CLEAR);
    if (p != NULL) {
        if (p->estado == 0){
            ant->prox = p->prox;
            cout << "Livro " << p->nome << " de " << p->ano << " removido com sucesso!" << endl;
            (*qnt_livro)--;
            free(p);
        }else{
            cout << "Livro " << p->nome << " de " << p->ano << " esta sendo usado no momento!" << endl;
        }
    }else {
        cout << "Livro de ID: " << id << " nao encontrado!" << endl;
    }
}

void emprestar_livro(struct alunos *cab_alunos, struct livros *cab_livros){
    int id_livro;
    int id_aluno;
    struct livros *livro;
    struct alunos *aluno;

    cout << "Digite o ID do livro que deseja emprestar: ";
    cin >> id_livro;


    livro = busca_livro(cab_livros, id_livro);
    if(livro==NULL || livro->id!=id_livro){
        cout << "Livro nao encontrado" << endl;
        return;
    }
    if(livro->estado!=0){
        cout << "Livro ja esta emprestado" << endl;
        return;
    }

    system(CLEAR);

    cout << "Digite o ID do aluno que deseja o livro: ";
    cin >> id_aluno;

    aluno = busca_aluno(cab_alunos, id_aluno);
    if(aluno==NULL || aluno->id!=id_aluno){
        cout << "Aluno nao encontrado" << endl;
        return;
    }

    system(CLEAR);

    cout << "Livro emprestado com sucesso!" << endl;
    aluno->pendencia++;
    livro->id_aluno = aluno->id;
    livro->estado = 1;
}

void devolver_livro(struct alunos *cab_alunos, struct livros *cab_livros){
    int id_livro;
    int id_aluno;
    struct livros *livro;
    struct alunos *aluno;

    cout << "Digite o ID do aluno que deseja devolver o livro: ";
    cin >> id_aluno;

    aluno = busca_aluno(cab_alunos, id_aluno);
    if(aluno==NULL || aluno->id!=id_aluno){
        cout << "Aluno nao encontrado" << endl;
        return;
    }if(aluno->pendencia == 0){
        cout << "Aluno nao possui pendencias" << endl;
        return;
    }

    system(CLEAR);

    cout << "Digite o ID do livro a ser devolvido: ";
    cin >> id_livro;

    livro = busca_livro(cab_livros, id_livro);
    if(livro==NULL || livro->id!=id_livro){
        cout << "Livro nao encontrado" << endl;
        return;
    }if(livro->estado == 0){
        cout << "O livro ja se encontra disponivel" << endl;
        return;
    }if(livro->id_aluno != aluno->id){
        cout << "O livro nao esta com esse aluno" << endl;
        return;
    }

    system(CLEAR);

    cout << "Livro devolvido com sucesso" << endl;
    livro->estado = 0;
    aluno->pendencia--;
}
