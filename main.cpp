#include <iostream>
#include <string>
#include <stdlib.h>
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


int main()
{
    struct alunos* cab_alunos = new alunos(); //criação do cabeça de cada uma das listas encadeadas
    cab_alunos->prox = NULL;

    struct livros* cab_livros = new livros();
    cab_livros->prox = NULL;

    struct infraestrutura* cab_infraestrutura = new infraestrutura();
    cab_infraestrutura->prox = NULL;

    int id_aluno = 0; //IDs gerados automaticamente pela bilioteca
    int id_livro = 0;
    int num_infraestrutura = 0;

    iniciar(cab_alunos, cab_livros, cab_infraestrutura, &id_aluno, &id_livro, &num_infraestrutura);

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
        cout << "11 - Adicionar infraestrutura" << endl;
        cout << "12 - Remover infraestrutura" << endl;
        cout << "13 - Listar todas as infraestruturas" << endl;
        cout << "14 - Buscar infraestrutura" << endl;
        cout << "15 - Ocupar recurso" << endl;
        cout << "16 - Desocupar recurso\n" << endl;
        cout << "17 - Encerrar o programa" << endl;
        cout << "Digite: " << endl;
        cin >> opcao;

        system(CLEAR);

        switch (opcao){
            case 1:
                imprimir_todos_alunos(cab_alunos);
                break;
            case 2:
                id_aluno++;
                inserir_aluno(cab_alunos, id_aluno);
                break;
            case 3:
                remover_aluno(cab_alunos);
                break;
            case 4:
                imprimir_aluno(cab_alunos);
                break;
            case 5:
                id_livro++;
                inserir_livro(cab_livros, id_livro);
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
                num_infraestrutura++;
                inserir_infraestrutura(cab_infraestrutura);
                break;
            case 12:
                remover_infraestrutura(cab_infraestrutura);
                break;
            case 13:
                imprimir_toda_infraestrutura(cab_infraestrutura, cab_alunos);
                break;
            case 14:
                imprimir_infraestrutura(cab_infraestrutura, cab_alunos);
                break;
            case 15:
                emprestar_infraestrutura(cab_infraestrutura, cab_alunos);
                break;
            case 16:
                devolver_infraestrutura(cab_infraestrutura, cab_alunos);
                break;
            case 17:
                encerrar(cab_alunos,cab_livros, cab_infraestrutura, id_aluno, id_livro, num_infraestrutura);
                enq = 0;
                break;
            default:
                cout << "Opcao invalida, tente novamente." << endl;
                break;
        }
    }



    cout << "Fim do programa!" << endl;
    return 0;
}
