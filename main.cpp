#include "cabecalho.h"

int main()
{
    struct alunos** cab_alunos = (struct alunos **) malloc (sizeof(struct alunos *));

    struct livros** cab_livros = (struct livros **) malloc (sizeof(struct livros *));

    struct infraestrutura* cab_infraestrutura = new infraestrutura();
    cab_infraestrutura->prox = NULL;

    int id_aluno = 0; //IDs gerados automaticamente pela bilioteca
    int id_livro = 0;
    int num_infraestrutura = 0;

    int qnt_aluno = 0;
    int qnt_livro = 0;
    int qnt_infraestrutura = 0;

    int opcao;

    cout << "Escolha uma das opcoes abaixo: " << endl;
    cout << "1 - Comecar do zero ou primeira inicializacao" << endl;
    cout << "2 - Comecar da ultima sessao salva" << endl;
    cout << "Digite a opcao: ";
    cin >> opcao;

    system(CLEAR);

    if(opcao == 2){
        iniciar_aluno(cab_alunos, &id_aluno, &qnt_aluno);
        iniciar_livro(cab_livros, &id_livro, &qnt_livro);
        iniciar_infraestrutura(cab_infraestrutura, &num_infraestrutura, &qnt_infraestrutura);
    }

    int enq = 1;
    while(enq){
        //Abre o menu até que a opção de encerrar o programa seja escolhida
        cout << "Bem vindo ao menu inicial!" << endl;
        cout << "Digite sua opcao abaixo para prosseguir:\n" << endl;

        cout << "1 - Adicionar novo aluno" << endl;
        cout << "2 - Remover aluno" << endl;
        cout << "3 - Listar todos os alunos cadastrados" << endl;
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
                inserir_aluno(cab_alunos, &id_aluno, &qnt_aluno);
                break;
            case 2:
                remover_aluno(cab_alunos, &id_aluno, &qnt_aluno);
                break;
            case 3:
                imprimir_todos_alunos(cab_alunos, &id_aluno);
                break;
            case 4:
                imprimir_aluno(cab_alunos, &id_aluno);
                break;
            case 5:
                inserir_livro(cab_livros, &id_livro, &qnt_livro);
                break;
            case 6:
                remover_livro(cab_livros, &id_livro, &qnt_livro);
                break;
            case 7:
                imprimir_todos_livros(cab_livros, cab_alunos, &id_livro);
                break;
            case 8:
                imprimir_livro(cab_livros, cab_alunos, &id_livro);
                break;
            case 9:
                emprestar_livro(cab_alunos, cab_livros, &id_aluno, &id_livro);
                break;
            case 10:
                devolver_livro(cab_alunos, cab_livros, &id_aluno, &id_livro);
                break;
            case 11:
                inserir_infraestrutura(cab_infraestrutura, &num_infraestrutura, &qnt_infraestrutura);
                break;
            case 12:
                remover_infraestrutura(cab_infraestrutura, &qnt_infraestrutura);
                break;
            case 13:
                imprimir_toda_infraestrutura(cab_infraestrutura, cab_alunos);
                break;
            case 14:
                imprimir_infraestrutura(cab_infraestrutura, cab_alunos);
                break;
            case 15:
                emprestar_infraestrutura(cab_infraestrutura, cab_alunos, &id_aluno);
                break;
            case 16:
                devolver_infraestrutura(cab_infraestrutura, cab_alunos, &id_aluno);
                break;
            case 17:
                int opcao;
                cout << "Escolha uma das opcoes abaixo:" << endl;
                cout << "1 - Encerrar sem salvar." << endl;
                cout << "2 - Salvar e encerrar." << endl;
                cout << "Digite a opcao: ";
                cin >> opcao;
                system(CLEAR);

                if(opcao == 2){
                    encerrar_aluno(cab_alunos, id_aluno, qnt_aluno);
                    encerrar_livro(cab_livros, id_livro, qnt_livro);
                    encerrar_infraestrutura(cab_infraestrutura, num_infraestrutura, qnt_livro);
                }

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
