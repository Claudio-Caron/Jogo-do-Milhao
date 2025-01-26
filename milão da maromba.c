#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
//#include <time.h> (era para utilizar caso fosse preciso usar a função rand range - random-)
#include <windows.h>

#define alternativa 150

char perg[10][4][alternativa];
void mensrodada(int esprodada);
void preencher();
void pergunta();
void escolha();
void certo();
void mensagem();
void galinha();
void seringa();
void instrucoes();
void dica(int *);
//int remov = 2, numdica = 2, pula = 1;
// int remov, int numdica, int pula,
int p1(int *, int *, int *, char gaba, int x, char esppremios[][40], int z);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    instrucoes();
    mensagem();
    preencher();
    system("cls");
    escolha();
    system("pause");
    return 0;
}
void mensagem()
{
    int j;
    puts("\t\t\t=======||  ||       || //=======\\  \\\\          //");
    puts("\t\t\t||         ||       || ||       ||  \\\\        //");
    puts("\t\t\t||======|| ||=======|| ||       ||   \\\\  /\\  //");
    puts("\t\t\t        || ||       || ||       ||    \\\\//\\\\//");
    puts("\t\t\t||======== ||       ||  \\=======//     \\/  \\/");
    puts("\n\t\t\t\t\t||==\\   /====\\");
    puts("\t\t\t\t\t||  |   |   |");
    puts("\t\t\t\t\t||==/   \\====/          /_-/\n");
    puts("\t\t\t|\\    /|   ()  ||       ||      ||      /\\     //====\\\\  ");
    puts("\t\t\t||\\  /||   ||  ||       ||      ||     //\\\\   ||      || ");
    puts("\t\t\t|| \\/ ||   ||  ||       ||======||    //--\\\\  ||      ||");
    puts("\t\t\t||    ||   ||  ||       ||      ||   //    \\\\ ||      ||   ");
    puts("\t\t\t||    ||   ||  |======= ||      ||  //      \\\\ \\\\----//");
    puts("\t\t\t");
    puts("\t\t\t\t\t\t\t\tDA MAROMBA");
    Sleep(3000);
    printf("\n\n\t\t\t\tPrepare seu shake\n");
    Sleep(1500);
    printf("\t\t\t\tO jogo irá iniciar");
    Sleep(1000);
    for (j = 0; j < 3; j++)
    {
        printf(".");
        Sleep(1000);
    }
    printf(" \n");
}
void escolha()
{
    int oremov = 2, onumdica = 2, opula = 1;
    int cont = 0, rodada = 0;
    char gabarito[11] = "BBCDCDDDDC";
    char premios[10][40] = {
        "1:# Hiper Calórico",
        "2:# Omega 3",
        "3:# Caixa de barrinhas proteicas",
        "4:# Pasta de amendoim",
        "5:# Beta Alanina",
        "6:# Pré-treino",
        "7:# Whey Protein",
        "8:# Creatina",
        "9:# Um Mês de academia grátis",
        "10:# Um ano de farmácia grátis"}; // fazer um for do 0 ao premio da rodada menos um no else, com fito de imprimir todos os premios conseguidos no jogo;
    do
    {
        switch (rodada)
        {
        case 0:                                                                     // inicia rodada 1, porém, utilizei o 0 para reciclar a variavel em outra função
            cont = p1(&oremov, &onumdica, &opula, gabarito[0], rodada, premios, 0); // se não der certo, tentar jogar [] da matriz para cima e deixar como parametro em baixo so o nome da matriz; ou ainda fazer uma função somente para os premios;
            break;
        case 1:
            cont = p1(&oremov, &onumdica, &opula, gabarito[1], rodada, premios, 1);
            break;
        case 2:
            cont = p1(&oremov, &onumdica, &opula, gabarito[2], rodada, premios, 2);
            break;
        case 3:
            cont = p1(&oremov, &onumdica, &opula, gabarito[3], rodada, premios, 3);
            break;
        case 4:
            cont = p1(&oremov, &onumdica, &opula, gabarito[4], rodada, premios, 4);
            break;
        case 5:
            cont = p1(&oremov, &onumdica, &opula, gabarito[5], rodada, premios, 5);
            break;
        case 6:
            cont = p1(&oremov, &onumdica, &opula, gabarito[6], rodada, premios, 6);
            break;
        case 7:
            cont = p1(&oremov, &onumdica, &opula, gabarito[7], rodada, premios, 7);
            break;
        case 8:
            cont = p1(&oremov, &onumdica, &opula, gabarito[8], rodada, premios, 8);
            break;
        case 9:
            cont = p1(&oremov, &onumdica, &opula, gabarito[9], rodada, premios, 9);
            break;
        }
        rodada++;
    } while (cont == 0 && rodada <= 9);
}
void mensrodada(int esprodada)
{
    printf("\t\t\t\t\t\t----------\n");
    printf("\t\t\t\t\t\t|RODADA %d|\n\t\t\t\t\t\t----------\n Responda a pergunta corretamente e acumule prêmios!\n\n", esprodada + 1);
    printf("/--------------------------------------------\\\n");
    printf("|Para remover duas alternativas, digite 1    |\n");
    printf("|--------------------------------------------|\n");
    printf("|Para solicitar uma dica da questão, digite 2|\n");
    printf("|--------------------------------------------|\n");
    printf("|Para saltar a pergunta, digite 3            |\n");
    printf("\\--------------------------------------------/\n");
}
void certo()
{
    printf("\t\t\t\tResposta correta!\n\t\t\t\tAguarde para prosseguir\n\n");
}
int p1(int *remov, int *numdica, int *pula, char gaba, int x, char esppremios[][40], int z)
{
    const char perguntas[11][200] = {
        "1- Qual é a finalidade do exercício \"rosca martelo\"?",
        "2- Qual alimento e responsável por promover a vaso-dilatação nos treinos, elevando a taxa de circulação sanguínea,          irrigando os músculos com mais eficiência durante os treinos?",
        "3- Qual alimento é reconhecido por retirar as câimbras, pela sua rica fonte de potássio, auxiliando na contração e recuperação muscular?",
        "4- O que significa \"PR\" em musculação?",
        "5- Qual termo é usado para descrever o processo de redução de gordura corporal para destacar a definição muscular?",
        "6- Qual é a técnica em que você realiza esforço na fase excêntrica do exercício, na falha muscular?",
        "7- Qual é o papel das gorduras na dieta de um praticante de musculação?",
        "8- Qual é a importância da periodização no treinamento de musculação?",
        "9- Professor é Fake-Natty?",
        "10- O que é o \"overtraining\" e por que é importante evitá-lo?"};
    char r;
    int i, y = 0, contaj = 0, contdica = 0; // usar ponteiro para declarar essas variáveis no bloco do escolha;Se não der certo, declarar como globais, mas vai dar certo sim, confia
    // int x=0;//posisao do vetor da pergunta;(usar como parâmetro em chamarpergunta)
    do
    { // //
        do
        {
            mensrodada(x);
            printf("REMOÇÕES RESTANTES: %d\nDICAS RESTANTES: %d\nSALTO RESTANTE: %d\n\n", *remov, *numdica, *pula);
            printf("%s\n", perguntas[x]);
            for (i = 0; i < 4; i++)
            {
                printf("%s \n", perg[x][i]);
            }
            printf("\t\t\t------------------------------------------------------\n");
            printf("\t\t\t|Insira a alternativa ou solicite um recurso de ajuda|\n");
            printf("\t\t\t------------------------------------------------------\n\t\t\t\t\t      ");
            // funcao das alternativas
            scanf(" %c", &r);
            fflush(stdin);
            r = toupper(r);
            if (r != 'A' && r != 'B' && r != 'C' && r != 'D' && r != '1' && r != '2' && r != '3')
            {
                printf("Você digitou uma opção inválida, insira novamente a alternativa em :");
                for (i = 3; i > 0; i--)
                {
                    if (i == 3)
                    {
                        Sleep(1000);
                    }
                    printf("%i   ", i);
                    Sleep(1000);
                }
                system("cls");
            }
        } while (r != 'A' && r != 'B' && r != 'C' && r != 'D' && r != '1' && r != '2' && r != '3'); // alterar a condição no momento que for implementado ajudas.
        if (r == '3' && *pula > 0)
        {

            (*pula)--;
            printf("\t\t\t\tVocê saltou essa pergunta!!!\n\n");
            Sleep(1500);
            printf("Premio obtido na rodada %s\n", esppremios[z]);
            Sleep(4000);
            system("cls");
            return 0;
        }
        else if (r == '3' && *pula == 0)
        {
            printf("\t\t\t\tVocê já usou o recurso de salto!!!\n\t\t\t\tRESPONDA A PERGUNTA OU SOLICITE OUTRA AJUDA\n\n");
            if (contdica != 0)
            {
                Sleep(3000); // adicionar esse bloco nas remoções
                system("cls");
                dica(&x); // fazer uma função para dica, com fito de reduzir as linhas
                continue;
            }
            Sleep(3000);
            system("cls");
            continue;
        }
        if (x == 8)
        {
            if (r == 'A' || r == 'B' || r == 'C')
            {
                r = 'D';
            }
        }
        if (r == '2')
        {
            if (*numdica > 0)
            {
                if (*numdica == 1 && contdica != 0)
                {
                    printf("Você já solicitou dicas nessa rodada!!!\nRESPONDA A PERGUNTA OU SOLICITE OUTRA AJUDA\n\n");
                    Sleep(3000);
                    system("cls");
                    dica(&x);
                    continue;
                }
                if (*numdica == 2 && contdica == 0)
                {
                    (*numdica)--;
                    contdica++;
                    system("cls");
                    dica(&x);
                    continue;
                }
                else if (*numdica == 1 && contdica == 0)
                {
                    (*numdica)--;
                    system("cls");
                    dica(&x);
                    continue;
                }
            }
            else if (*numdica == 0)
            {
                printf("Você não possui mais dicas disponíveis!!!\nRESPONDA A PERGUNTA OU SOLICITE OUTRA AJUDA\n\n");
                Sleep(3000);
                system("cls");
                if (contdica != 0)
                {
                    dica(&x);
                }
                continue;
            }
        }
        if (r == gaba)
        {
            certo();
            printf("Prêmio obtido na rodada %s\n", esppremios[z]);
            Sleep(4000);
            system("cls");
            if (x == 9)
            {
                printf("\t\t\t\t\t-------------------------------------\n");
                printf("\t\t\t\t\t|PARABÉNS!!! VOCÊ CONCLUIU O DESAFIO|\n");
                printf("\t\t\t\t\t-------------------------------------\n\n");
                printf("\t\t\t\t\tPrêmios Recebidos:\n");
                for (z = 0; z < x; z++)
                {
                    printf("\t\t\t\t%s\n", esppremios[z]);
                }
                seringa();
            }
            return 0;
        }
        else if (r == '1' && *remov > 0)
        {

            if (contaj != 0)
            {
                printf("Você já removeu uma alternativa nessa rodada!!\nRESPONDA A PERGUNTA OU SOLICITE OUTRA AJUDA\n\n");
                if (contdica != 0)
                {
                    Sleep(3000);
                    system("cls");
                    (*remov)--;
                    dica(&x);
                    continue;
                }
                (*remov)--;
                Sleep(3000);
                system("cls");
                continue;
            }
            (*remov)--;
            contaj++;
            // da para transformar numa função com ponteiro x;
            switch (x)
            {
            case 0:
                strcpy(perg[0][0], "A)");
                strcpy(perg[0][2], "C)");
                break;
            case 1:
                strcpy(perg[1][0], "A)");
                strcpy(perg[1][3], "D)");
                break;
            case 2:
                strcpy(perg[2][1], "B)");
                strcpy(perg[2][0], "A)");
                break;
            case 3:
                strcpy(perg[3][1], "B)");
                strcpy(perg[3][2], "C)");
                break;
            case 4:
                strcpy(perg[4][3], "D)");
                strcpy(perg[4][0], "A)");
                break;
            case 5:
                strcpy(perg[5][1], "B)");
                strcpy(perg[5][0], "A)");
                break;
            case 6:
                strcpy(perg[6][1], "B)");
                strcpy(perg[6][2], "C)");
                break;
            case 7:
                strcpy(perg[7][0], "A)");
                strcpy(perg[7][1], "B)");
                break;
            case 8:
                strcpy(perg[8][0], "A)");
                strcpy(perg[8][1], "B)");
                break;
            case 9:
                strcpy(perg[9][0], "A)");
                strcpy(perg[9][3], "D)");
                break;
            }
            if (contdica != 0)
            {
                system("cls");
                dica(&x);
                continue;
            }
            system("cls");
            continue;
        }
        else if (r == '1' && *remov == 0)
        {

            printf("Você esgotou todas as remoções\nRESPONDA A PERGUNTA OU SOLICITE OUTRA AJUDA\n\n");
            if (contdica != 0)
            {
                Sleep(3000);
                system("cls");
                dica(&x);
                continue;
            }
            Sleep(3000);
            system("cls");
            continue;
        }
        else
        {
            // printf("Alternativa correta: %c\n", gaba);
            system("cls");
            for (i = 0; i < 4; i++)
            {
                if (gaba == perg[x][i][0])
                {
                    printf("\t\t\tALTERNATIVA CORRETA: %s\n", perg[x][i]);
                    break;
                }
            }
            galinha(); // transformar essa galinha em uma função
            //  fazer um for para mostrar os premios conseguidos
            if (x == 0)
            {
                printf("\t\t\t-------------------------------------------\n");
                printf("\t\t\t|Jogo encerrado, você não conseguiu prêmios|\n");
                printf("\t\t\t--------------------------------------------\n");
                return 1;
            }
            printf("\t\t\t-------------------------------------\n");
            printf("\t\t\t|Jogo encerrado, prêmios acumulados:|\n");
            printf("\t\t\t-------------------------------------\n");
            for (z = 0; z < x; z++)
            {
                printf("\t\t\t%s\n", esppremios[z]);
            }
            return 1;
        }
    } while (y == 0);
}

void preencher()
{
    strcpy(perg[0][0], "A) Trabalhar de maneira isolada o bíceps.");
    strcpy(perg[0][1], "B) Dar ênfase na porcao  do bíceps braquial, com sinergismo(movimento auxiliar) do ante-braço.");
    strcpy(perg[0][2], "C) Como o exercicio e realizado em uma pegada neutra, trabalha isoladamente a cabeça curta do biceps.");
    strcpy(perg[0][3], "D) trabalhar de maneira isolada o ante-braço.");
    strcpy(perg[1][0], "A)Cenoura.");
    strcpy(perg[1][1], "B)Beterraba.");
    strcpy(perg[1][2], "C)Melancia.");
    strcpy(perg[1][3], "D)Batata-Doce.");
    strcpy(perg[2][0], "A)Ovo.");
    strcpy(perg[2][1], "B)Castanha-do-Pará.");
    strcpy(perg[2][2], "C)Banana.");
    strcpy(perg[2][3], "D)Leite.");
    strcpy(perg[3][0], "A)Progresso Rápido.");
    strcpy(perg[3][1], "B)Peso Real.");
    strcpy(perg[3][2], "C)Potência Reversa.");
    strcpy(perg[3][3], "D)Personal Record (Recorde Pessoal).");
    strcpy(perg[4][0], "A)Hipertrofia.");
    strcpy(perg[4][1], "B)Bulking.");
    strcpy(perg[4][2], "C)Cutting."); //
    strcpy(perg[4][3], "D)Endurance.");
    strcpy(perg[5][0], "A)Isometria.");
    strcpy(perg[5][1], "B)Plyometria.");
    strcpy(perg[5][2], "C)Repetições parciais");
    strcpy(perg[5][3], "D)Série negativa"); //
    strcpy(perg[6][0], "A)Acelerar o metabolismo.");
    strcpy(perg[6][1], "B)Fornecer fibras para a digestão.");
    strcpy(perg[6][2], "C)Apoiar o crescimento dos ossos.");
    strcpy(perg[6][3], "D)Regular hormônios e fornecer energia."); //
    strcpy(perg[7][0], "A)Reduzir a necessidade de aquecimento.");
    strcpy(perg[7][1], "B)Evitar o ganho excessivo de massa muscular.");
    strcpy(perg[7][2], "C)Prevenir lesões articulares.");
    strcpy(perg[7][3], "D)Maximizar os ganhos de força e massa muscular."); //
    strcpy(perg[8][0], "A)Sim.");                                           //
    strcpy(perg[8][1], "B)Com certeza.");                                   //
    strcpy(perg[8][2], "C)Sem dúvidas.");                                   //
    strcpy(perg[8][3], "D)Inquestionavelmente.");                           //
    strcpy(perg[9][0], "A)Um estado de relaxamento muscular excessivo.");
    strcpy(perg[9][1], "B)Um período de tempo dedicado exclusivamente à recuperação.");
    strcpy(perg[9][2], "C)Estresse corporal de treinamento muito alto sem descanso adequado, o que pode levar a fadiga crônica, lesões e redução no desempenho."); //
    strcpy(perg[9][3], "D)Uma técnica avançada de treinamento para maximizar ganhos de força rapidamente.");
}
void galinha()
{
    printf("            ,~.\n");
    printf("           ,-'__ `-,\n");
    printf("          {,-'  `. }\n");
    printf("         ,( ° )   `-.__\n");
    printf("        <=.) (         `-.__,==' ' ' '} \t\t---------------------\n");
    printf("          (   )                      /) \t\t|RESPOSTA INCORRETA!|\n");
    printf("           `-'\\  ,                    )\t\t\t---------------------\n");
    printf("               |  \\        `~.        /\n");
    printf("               \\   `._        \\      /\n");
    printf("                \\     `._____,'    ,'\n");
    printf("                 `-.             ,-'\n");
    printf("                    `-._     _,-'\n");
    printf("                        77jj'\n");
    printf("                       //_||\n");
    printf("                    __//--'/`\n");
    printf("                  ,--'/`  '\n");
    puts("Você não garantiu prêmios Nessa rodada!!!");
    puts("\t\t\tVOCÊ É FRANGOLINO!!!\n");
    printf("\t\t\t       \\   \n");
    printf("\t\t\t       (o>  \n");
    printf("\t\t\t\\ \\  / ) \n");
    printf("\t\t\t\\ `)   )    \n");
    printf("\t\t\t /  /__/   \n");
    printf("\t\t\t/   / \n");
}
void dica(int *espx)
{
    char *dicas[] = {
        "DICA: Esse exercício é realizado com movimento em sentido ao peito.",
        "DICA: Sua origem permite que seja produzida açúcar de seus nutrientes.",
        "DICA: É um alimento associado aos macacos.",
        "DICA: É dito ao levantar um peso que nunca levantou antes.",
        "DICA: défict calórico.",
        "DICA: Fase em que segura a descida.",
        "DICA: Lubrifica os ossos, mas também auxilia na produção de algo que garante o funcionamento do organismo.",
        "DICA: Melhorar a performance.",
        "DICA: Observe o peitoral dele!",
        "DICA: (sobretreinamento)."};
    printf("Dica: %s\n", dicas[*espx]);
} // ultima alteracao;
void seringa()
{
    printf("\n\n");
    printf("\t\t\t --      |======================================|            \n");
    printf("\t\t\t ||      |***********\\                          |   \n");
    printf("\t\t\t ||======|************\\ |  |  |  |  |  |  |  |  | \n");
    printf("\t\t\t ||======|*************\\------------------------|=====----------                \n");
    printf("\t\t\t ||======|**************\\                       |              /\\\n");
    printf("\t\t\t ||      |***************\\                      |             /  \\\n");
    printf("\t\t\t --      |======================================|            /    \\\n");
    printf("\t\t\t                                                            /      \\ \n");
    printf("\t\t\t                                                           /        \\      \n");
    printf("\t\t\t                                                          (          ) \n");
    printf("\t\t\t                                                           `--.....-' \n");
}
void instrucoes()
{
    printf("\t\t° O jogo é caracterizado com perguntas do meio maromba(estratégias de dieta e treino)\n\t\t° O jogo tamém é composto por 10 questões\n\t\t° Cada qustão contém um prêmio, que pode ser obtido por meio de ajudas limitadas\n\n\n\t\t\t\t");
    system("pause");
    system("cls");
}
