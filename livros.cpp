#include "cabecalho.h"

void imprimir_todos_livros(struct livros **cab_livros, struct alunos **cab_alunos, int *id_livro) {

    if ((*id_livro)==0) {
        cout << "Nenhum livro cadastrado!" << endl;
        return;
    }

    cout << "Livros cadastrados:" << endl;

    for(int i=0; i < (*id_livro); i++) {
        cout << "Nome: " << cab_livros[i]->nome << "; ID: " << cab_livros[i]->id << endl;
        if(cab_livros[i]->estado == 0)
            cout << "Livro disponivel!\n" << endl;
        else{
            cout << "Livro emprestado para o aluno de matricula: " << cab_alunos[cab_livros[i]->id_aluno-1]->matricula << endl;
        }
    }
}

void imprimir_livro(struct livros **cab_livros, struct alunos **cab_alunos, int *id_livro){
    int contador=0;

    int opcao;
    cout << "Se deseja buscar por ID digite 1, por categoria digite 2: ";
    cin >> opcao;

    if(opcao == 2){
        string categoria;
        cout << "Digite a categoria: ";
        cin.ignore();
        getline(cin, categoria);

        for(int i=0; i < (*id_livro); i++) {
            if( cab_livros[i]==NULL ){
                continue;
            }if(cab_livros[i]->categoria != categoria){
                continue;
            }
            contador++;
            cout << "Nome: " << cab_livros[i]->nome << "; ID: " << cab_livros[i]->id << endl;
            if(cab_livros[i]->estado == 0)
                cout << "Livro disponivel!\n" << endl;
            else{
                cout << "Livro emprestado para o aluno de matricula: " << cab_alunos[cab_livros[i]->id_aluno-1]->matricula << endl;
                }
            }
        if(contador == 0){
            cout << "Nehnum livro da categoria " << categoria <<" foi encontrado!\n" << endl;
        }
        return;
    }

    int idl;
    cout << "Digite o ID do livro que deseja buscar: ";
    cin >> idl;

    if(idl < 1 || idl > (*id_livro)){
        cout << "ID nao encontrado!" << endl;
        return;
    }

    if(cab_livros[idl-1] != NULL){
        cout << "Nome: " << cab_livros[idl-1]->nome << "; ID: " << cab_livros[idl-1]->id << "; Categoria: " << cab_livros[idl-1]->categoria << endl;
        if(cab_livros[idl-1]->estado == 0)
            cout << "Livro disponivel!\n" << endl;
        else{
            cout << "Livro emprestado para o aluno de matricula: " << cab_alunos[cab_livros[idl-1]->id_aluno-1]->matricula << endl;
        }
    }else{
        cout << "ID nao encontrado." << endl;
    }
}

void inserir_livro(struct livros **cab, int *id_livro, int *qnt_livro) {
    (*id_livro)++;
    cab = (struct livros **)realloc(cab, (*id_livro)*sizeof(struct livros *));
    cab[(*id_livro)-1] = new livros();

    cout << "Digite o nome do livro: ";
    cin.ignore();
    getline(cin, cab[(*id_livro)-1]->nome);
    cout << "Digite a categoria: ";
    getline(cin, cab[(*id_livro)-1]->categoria);
    cout << "Digite o ano de publicacao: ";
    cin >> cab[(*id_livro)-1]->ano;
    cab[(*id_livro)-1]->id = (*id_livro);
    cab[(*id_livro)-1]->estado = 0;
    system(CLEAR);
    cout << "Livro " << cab[(*id_livro)-1]->nome << " de " << cab[(*id_livro)-1]->ano << " cadastrado com sucesso!" << endl;
    (*qnt_livro)++;
}

void remover_livro(struct livros **cab, int *id_livro, int *qnt_livro) {
    int id;
    cout << "Digite o ID do livro que deseja remover: ";
    cin >> id;

    if(id < 1 || id > (*id_livro)){
        cout << "ID nao encontrado!" << endl;
        return;
    }

    system(CLEAR);
    if (cab[id-1] != NULL) {
        if (cab[id-1]->estado == 0){
            cout << "Livro " << cab[id-1]->nome << " de " << cab[id-1]->ano << " removido com sucesso!" << endl;
            (*qnt_livro)--;
            free(cab[id-1]);
            cab[id-1] = NULL;
        }else{
            cout << "Livro " << cab[id-1]->nome << " de " << cab[id-1]->ano << " esta sendo usado no momento!" << endl;
        }
    }else {
        cout << "Livro de ID: " << id << " nao encontrado!" << endl;
    }
}

void emprestar_livro(struct alunos **cab_alunos, struct livros **cab_livros, int *id_aluno, int *id_livro){
    int idl;
    cout << "Digite o ID do livro que deseja emprestar: ";
    cin >> idl;

    if(idl < 1 || idl > (*id_livro)){
        cout << "ID nao encontrado!" << endl;
        return;
    }

    if(cab_livros[idl-1]==NULL){
        cout << "Livro nao encontrado" << endl;
        return;
    }if(cab_livros[idl-1]->estado!=0){
        cout << "Livro ja esta emprestado" << endl;
        return;
    }

    system(CLEAR);

    int ida;
    cout << "Digite o ID do aluno que deseja o livro: ";
    cin >> ida;

    if(ida < 1 || ida > (*id_aluno)){
        cout << "ID nao encontrado!" << endl;
        return;
    }

    if(cab_alunos[ida-1]==NULL){
        cout << "Aluno não encontrado" << endl;
        return;
    }

    system(CLEAR);

    cout << "Livro emprestado com sucesso!" << endl;
    cab_alunos[ida-1]->pendencia++;
    cab_livros[idl-1]->id_aluno = cab_alunos[ida-1]->id;
    cab_livros[idl-1]->estado = 1;
}

void devolver_livro(struct alunos **cab_alunos, struct livros **cab_livros, int *id_aluno, int *id_livro){
    int ida;
    cout << "Digite o ID do aluno que deseja devolver o livro: ";
    cin >> ida;

    if(ida < 1 || ida > (*id_aluno)){
        cout << "ID nao encontrado!" << endl;
        return;
    }

    if(cab_alunos[ida-1]==NULL){
        cout << "Aluno nao encontrado" << endl;
        return;
    }if(cab_alunos[ida-1]->pendencia == 0){
        cout << "Aluno nao possui pendencias" << endl;
        return;
    }

    system(CLEAR);

    int idl;
    cout << "Digite o ID do livro a ser devolvido: ";
    cin >> idl;

    if(idl < 1 || idl > (*id_livro)){
        cout << "ID nao encontrado!" << endl;
        return;
    }

    if(cab_livros[idl-1]==NULL){
        cout << "Livro nao encontrado" << endl;
        return;
    }if(cab_livros[idl-1]->estado == 0){
        cout << "O livro ja se encontra disponivel" << endl;
        return;
    }if(cab_livros[idl-1]->id_aluno != cab_alunos[ida-1]->id){
        cout << "O livro nao esta com esse aluno" << endl;
        return;
    }

    system(CLEAR);

    cout << "Livro devolvido com sucesso" << endl;
    cab_livros[idl-1]->estado = 0;
    cab_alunos[ida-1]->pendencia--;
}

