#include "cabecalho.h"

void imprimir_todos_alunos(struct alunos **cab, int *id_aluno) {
    if ((*id_aluno) == 0) {
        cout << "Nenhum aluno foi cadastrado!" << endl;
        return;
    }

    cout << "Alunos cadastrados:" << endl;

    for(int i=0; i < (*id_aluno); i++) {
        cout << "Nome: " << cab[i]->nome << "; ID: " << cab[i]->id << endl;
        if(cab[i]->pendencia == 0)
            cout << "Nao possui pendencias\n" << endl;
        else
            cout << "Possui pendencias\n" << endl;
    }
}

void imprimir_aluno(struct alunos **cab, int *id_aluno){
    int id;
    cout << "Digite o ID do aluno que deseja buscar: ";
    cin >> id;

    if(id < 1 || id > (*id_aluno)){
        cout << "ID nao encontrado!" << endl;
        return;
    }

    if(cab[id-1] != NULL){
        cout << "Nome: " << cab[id-1]->nome << "; ID: " << cab[id-1]->id << endl;
        if(cab[id-1]->pendencia == 0)
            cout << "Nao possui pendencias.\n" << endl;
        else
            cout << "Possui pendencias.\n" << endl;
    }else{
        cout << "ID nao encontrado." << endl;
    }
}

void inserir_aluno(struct alunos **cab, int *id_aluno, int *qnt_aluno) {
    (*id_aluno)++;
    cab = (struct alunos **)realloc(cab, (*id_aluno)*sizeof(struct alunos *));
    cab[(*id_aluno)-1] = new alunos();

    cout << "Digite o nome do aluno: ";
    cin.ignore();
    getline(cin, cab[(*id_aluno)-1]->nome);
    cout << "Digite a matricula: ";
    getline(cin, cab[(*id_aluno)-1]->matricula);
    cab[(*id_aluno)-1]->id = (*id_aluno);
    cab[(*id_aluno)-1]->pendencia = 0;
    system(CLEAR);
    cout << "Aluno " << cab[(*id_aluno)-1]->nome << " cadastrado com sucesso!" << endl;
    (*qnt_aluno)++;
}

void remover_aluno(struct alunos **cab, int *id_aluno, int *qnt_aluno) {
    int id;
    cout << "Digite o ID do aluno que deseja remover: ";
    cin >> id;

    if(id < 1 || id > (*id_aluno)){
        cout << "ID nao encontrado!" << endl;
        return;
    }

    system(CLEAR);
    if (cab[id-1] != NULL) {
        if(cab[id-1]->pendencia == 0){
            cout << "Aluno " << cab[id-1]->nome << " removido com sucesso!" << endl;
            (*qnt_aluno)--;
            free(cab[id-1]);
            cab[id-1] = NULL;
        }else{
            cout << "O aluno " << cab[id-1]->nome << " nao pode ser removido por possuir pendencias!" << endl;
        }
    }else {
        cout << "ID nao encontrado!" << endl;
    }
}
