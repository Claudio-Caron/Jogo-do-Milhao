#include "anelHorario.h"
#include "util.h"

using namespace std;

#define FLAG MSG[1]
#define VALOR MSG[0]

void executarAnelHorario(MPI_Comm &new_comm, int nProcessos) {
    int ciclos = 0, op = 1;
    int rankGrupo;
    float MSG[2];

    MPI_Comm_rank(new_comm, &rankGrupo);

    int rankSeguinte = getRankProcessoPost(rankGrupo, nProcessos / 2);
    int rankAnterior = getRankProcessoAnt(rankGrupo, nProcessos / 2);

    cout << "Rank do grupo: " << rankGrupo << endl;

    FLAG=1;
    if (rankGrupo == 0) {
        cout << "Insira o valor para a comunicação horária (x): ";
        cin >> VALOR;

        // Envia o valor inicial para o próximo processo no anel e recebe o valor do processo anterior
        MPI_Send(&MSG, 2, MPI_FLOAT, rankSeguinte, 0, new_comm);
        MPI_Recv(&MSG, 2, MPI_FLOAT, rankAnterior, 0, new_comm, MSI);

        ciclos++;
        imprimirValorEnviado(ciclos, VALOR);

        while (op != 3) {
            imprimirMenu();
            cin >> op;

            switch (op) {
                case 1:
                    cout << "Insira o novo valor para a comunicação horária (x): ";
                    cin >> VALOR;
                    MPI_Send(&MSG, 2, MPI_FLOAT, rankSeguinte, 0, new_comm);
                    MPI_Recv(&MSG, 2, MPI_FLOAT, rankAnterior, 0, new_comm, MSI);
                    ciclos++;
                    imprimirValorEnviado(ciclos, VALOR);
                    break;

                case 2:
                    cout << "\n2 - CONTINUAR VOLTA\n" << endl;
                    VALOR++;
                    cout << "Valor de X incrementado | valor a ser enviado: " << VALOR << endl;

                    MPI_Send(&MSG, 2, MPI_FLOAT, rankSeguinte, 0, new_comm);
                    MPI_Recv(&MSG, 2, MPI_FLOAT, rankAnterior, 0, new_comm, MSI);
                    ciclos++;
                    imprimirValorEnviado(ciclos, VALOR);
                    break;

                case 3:
                    system("clear");
                    FLAG = 0; // Bit de validação setado para 0, os outros processos irão sair do loop
                    MPI_Send(&MSG, 2, MPI_FLOAT, rankSeguinte, 0, new_comm);
                    MPI_Recv(&MSG, 2, MPI_FLOAT, rankAnterior, 0, new_comm, MSI);
                    // Aguardar dar a volta no anel, ou seja, receber mensagem do último processo
                     MPI_Abort(MPI_COMM_WORLD, 999);
                    MPI_Finalize();
                    return;
                    break;

                default:
                    cout << "### VALOR INVÁLIDO! ###\n\n\n";
                    system("read -p 'Pressione qualquer tecla para continuar' var"); // system("Pause"); no Linux
                    system("clear");
                    break;
            }
        }
    } else {
        while (FLAG == 1) { // Validando que é para continuar a volta
            MPI_Recv(&MSG, 2, MPI_FLOAT, rankAnterior, 0, new_comm, MSI);
            cout << "-> Processo: " << rankGrupo << " recebeu " << VALOR <<" | envia " << VALOR + 1 << endl;
            VALOR++;
            MPI_Send(&MSG, 2, MPI_FLOAT, rankSeguinte, 0, new_comm);
        }
    }
}
