#include <iostream>
#include <string>
#include "alunos.h"
#include "livros.h"
//#include "salas.h"

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

struct salas{
    int id;
    int tipo;
    int estado;
    int id_aluno;
    struct sala* prox;
};


int main()
{
    struct alunos* cab_alunos = (struct alunos*) malloc (sizeof(struct alunos)); //criação do cabeça de cada uma das listas encadeadas
    cab_alunos->prox = NULL;

    struct livros* cab_livros = (struct livros*) malloc (sizeof(struct livros));
    cab_livros->prox = NULL;

    struct salas* cab_salas = (struct salas*) malloc (sizeof(struct salas));
    cab_salas->prox = NULL;

    int id_aluno = 1; //IDs gerados automaticamente pela bilioteca
    int id_livro = 1;

    string nome;
    string matricula;

    int opcao;

    int enq = 1;
    while(enq){
        //Abre o menu até que a opção de encerrar o programa seja escolhida
        cout << "Bem vindo ao menu inicial!" << endl;
        cout << "Digite sua opcao abaixo para prosseguir:\n" << endl;
        cout << "1 - Listar todos os alunos cadastrados" << endl;
        cout << "2 - Adicionar novo aluno" << endl;
        cout << "3 - Remover aluno" << endl;
        cout << "4 - Buscar aluno\n" << endl;
        cout << "5 - Adicionar livro" << endl;
        cout << "6 - Remover livro" << endl;
        cout << "7 - Listar todos os livros" << endl;
        cout << "8 - Buscar livro" << endl;
        cout << "9 - Emprestar livro" << endl;
        cout << "10 - Devolver livro\n" << endl;
        cout << "11 - Encerrar o programa" << endl;
        cout << "Digite: " << endl;
        cin >> opcao;

        system("cls");

        switch (opcao){
            case 1:
                imprimir_todos_alunos(cab_alunos);
                break;
            case 2:
                inserir_aluno(cab_alunos, id_aluno);
                id_aluno++;
                break;
            case 3:
                remover_aluno(cab_alunos);
                break;
            case 4:
                imprimir_aluno(cab_alunos);
                break;
            case 5:
                inserir_livro(cab_livros, id_livro);
                id_livro++;
                break;
            case 6:
                remover_livro(cab_livros);
                break;
            case 7:
                imprimir_todos_livros(cab_livros, cab_alunos);
                break;
            case 8:
                imprimir_livro(cab_livros, cab_alunos);
                break;
            case 9:
                emprestar_livro(cab_livros, cab_alunos);
                break;
            case 10:
                devolver_livro(cab_livros, cab_alunos);
                break;
            case 11:
                enq = 0;
        }
    }



    cout << "Fim do programa!" << endl;
    return 0;
}
