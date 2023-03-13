#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "time.h"

int menu()
{
    int op;
    printf("\n\n");
    printf("Opcao 1: Cadastro de Receitas e Gastos\n");
    printf("Opcao 2: Relatorio de Movimentacao Anual\n");
    printf("Opcao 3: Relatorio de Movimentacao Mensal\n");
    printf("Opcao 4: Poupanca\n");
    printf("Opcao 5: Saldo Total\n");
    printf("Opcao 6: Sair");
    printf("\n");
    scanf(" %d", &op);
    return op;
}

int menu2()
{
    int ops;
    printf("\nOpcao 1: Investimento Inicial");
    printf("\nOpcao 2: Adicionar fundos\n");
    printf("Opcao 3: Verificar Saldo Atual\n");
    printf("Opcao 4: Sacar\n");
    printf("Opcao 5: Sair\n");
    scanf("%d", &ops);
    return ops;
}

struct cadastro
{
    char valor[10];
    char desc[100];
    char data[20];
    char cat[20];
};


int main()
{
    int op;
    int cont = 0;
    char categorias[10][20];
    struct cadastro cad;
    struct cadastro cad2;
    struct cadastro cad3;
    struct cadastro cad4;
    double saldo = 0;

    while(1)
    {
        op = menu();
        FILE *fr1 = fopen("cadastro.txt", "rb");
        FILE *fr = fopen("cadastro.txt", "ab");
        if(op == 1)
        {
            FILE *ss = fopen("saldo.txt", "a");
            printf("Valor:\n");
            scanf("%s", cad.valor);
            getchar();

            printf("Descricao:\n");
            fgets(cad.desc, 100, stdin);
            cad.desc[strlen(cad.desc) - 1] = '\0';

            printf("Data:\n");
            scanf(" %s", cad.data);

            printf("Categoria:\n");
            fgets(cad.cat, 20, stdin);
            cad.cat[strlen(cad.cat) - 1] = '\0';

            fwrite(&cad, sizeof(cad), 1, fr);
            saldo += atof(cad.valor);
            fprintf(ss, "%lf\n", saldo);
            fclose(fr);
            fclose(ss);
        }
        else if(op == 2)
        {
            FILE *fr3 = fopen("cadastroanual.txt", "w");
            FILE *fl =  fopen("cadastrotrad.txt", "w");
            char ano[6] = "-22";
            fprintf(fr3,"Receitas:\n");

            while(!feof(fr1))
            {
                if(fread(&cad2 , 1 , sizeof(cad2), fr1))
                {
                    if(strstr(cad2.data, ano) != NULL)
                    {
                        int p = atoi(cad2.valor);
                        if(p >= 0)
                        {
                            fprintf(fl,"\n%s", cad2.cat);
                            fprintf(fr3,"\nValor: %s Descricao: %s Data: %s Categoria: %s", cad2.valor, cad2.desc, cad2.data, cad2.cat);
                        }
                    }
                }
            }
            fprintf(fr3,"\n\nGastos:\n");
            fclose(fr3);
            fclose(fr1);

            FILE *fr7 = fopen("cadastroanual.txt", "a");
            FILE *fr8 = fopen("cadastro.txt", "rb");

            while(!feof(fr8))
            {
                if(fread(&cad3 , 1 , sizeof(cad3), fr8))
                {
                    if(strstr(cad3.data, ano) != NULL)
                    {
                        int p2 = atoi(cad3.valor);
                        if(p2 < 0)
                        {
                            fprintf(fl,"\n%s", cad3.cat);
                            fprintf(fr7,"\nValor: %s Descricao: %s Data: %s Categoria: %s", cad3.valor, cad3.desc, cad3.data, cad3.cat);
                        }
                    }
                }
            }
            char jo[100];
            while(!feof(fr8))
            {
                if(fread(&cad4 , 1 , sizeof(cad4), fr8))
                {
                    if(strstr(cad4.data, ano) != NULL)
                    {
                        fscanf(fl,"\n%s", jo);
                        if(jo != cad4.cat)
                        {
                            fprintf(fl,"\n%s", cad4.cat);
                        }
                    }

                }
            }

            fclose(fr7);
            fclose(fl);
        }


        else if(op == 3)
        {
            FILE *fr7 = fopen("cadastromensal.txt", "w");
            FILE *fr8 = fopen("cadastrotrad.txt", "r");
            printf("\n");

            while(!feof(fr8))
            {
                fscanf(fr8, "%s", categorias[cont]);
                cont++;
            }
            char mes[6] = "-10-";
            for(int z = 0; z < cont; z++)
            {
                fprintf(fr7, "\n[Categoria: %s]\n", categorias[z]);
                fprintf(fr7,"\n+++Receitas+++\n");
                FILE *fr9 = fopen("cadastro.txt", "rb");
                while(!feof(fr9))
                {
                    if(fread(&cad3 , 1 , sizeof(cad3), fr9))
                    {
                        if(strstr(cad3.data, mes) != NULL)
                        {
                            if(strstr(cad3.cat, categorias[z]) != NULL)
                            {
                                int p = atoi(cad3.valor);
                                if(p >= 0)
                                {
                                    fprintf(fr7,"\nValor: %s Descricao: %s Data: %s Categoria: %s", cad3.valor, cad3.desc, cad3.data, cad3.cat);
                                }
                            }
                        }

                    }
                }
                fprintf(fr7,"\n");
                fclose(fr9);

                FILE *fr10 = fopen("cadastro.txt", "rb");
                fprintf(fr7,"\n---Gastos---\n");
                while(!feof(fr10))
                {
                    if(fread(&cad3 , 1 , sizeof(cad3), fr10))
                    {
                        if(strstr(cad3.data, mes) != NULL)
                        {
                            if(strstr(cad3.cat, categorias[z]) != NULL)
                            {
                                int p = atoi(cad3.valor);
                                if(p < 0)
                                {
                                    fprintf(fr7,"\nValor: %s Descricao: %s Data: %s Categoria: %s", cad3.valor, cad3.desc, cad3.data, cad3.cat);
                                }
                            }
                        }

                    }
                }
                fprintf(fr7,"\n");
                fclose(fr10);
            }

            fclose(fr7);
            fclose(fr8);


            FILE *fr0 = fopen("cadastromensal.txt", "r");
            char k[1000];
            while(!feof(fr0))
            {
                if(fread(&cad3 , 1 , sizeof(cad3), fr0))
                {
                    fgets(k, 1000, fr0);
                    printf("%s", k);
                }
            }
            fclose(fr0);
        }

        else if(op == 4)
        {
            while(1)
            {
                int ops;
                ops = menu2();
                if(ops == 1)
                {
                    FILE *pp0 = fopen("poupanca.txt", "r");
                    double valor = 0;

                    printf("Valor:\n");
                    scanf("%lf", &valor);
                    getchar();

                    time_t antes;
                    antes = time(NULL);
                    struct tm tempo = *localtime(&antes);

                    fclose(pp0);

                    FILE *pp = fopen("poupanca.txt", "w");
                    fprintf(pp, "%.2lf %d %d %d", valor, tempo.tm_mday, tempo.tm_mon + 1, tempo.tm_year - 100);
                    fclose(pp);
                }
                else if(ops == 2)
                {
                    time_t agora;
                    agora = time(NULL);
                    struct tm tempo2 = *localtime(&agora);

                    int valor2;
                    int dia;
                    int mes;
                    int ano;
                    double valor;
                    char v1[10];
                    char v2[10];
                    char v3[10];
                    char v4[10];
                    int cont1;
                    int cont2;
                    int cont3;
                    double rendimento;
                    double total;

                    FILE *pp2 = fopen("poupanca.txt", "r");
                    fscanf(pp2, "%s %s %s %s", v1, v2, v3, v4);
                    valor2 = atoi(v1);
                    dia = atoi(v2);
                    mes = atoi(v3);
                    ano = atoi(v4);
                    cont1 = tempo2.tm_mday - dia;
                    cont2 = (tempo2.tm_mon+1 - mes) *30;
                    cont3 = ((tempo2.tm_year-100) -ano) * 365;
                    rendimento = (cont1 + cont2 + cont3) * 0.002;
                    total = (double) (valor2 * (1 + rendimento));
                    fclose(pp2);
                    FILE *pp = fopen("poupanca.txt", "w");
                    printf("Valor:\n");
                    scanf("%lf", &valor);
                    getchar();
                    double final = total + valor;
                    fprintf(pp, "%.2lf %s %s %s", final, v2, v3, v4);
                    fclose(pp);
                }
                else if(ops == 3)
                {
                    time_t agora;
                    agora = time(NULL);
                    struct tm tempo2 = *localtime(&agora);

                    int valor2;
                    int dia;
                    int mes;
                    int ano;
                    char v1[10];
                    char v2[10];
                    char v3[10];
                    char v4[10];
                    int cont1;
                    int cont2;
                    int cont3;
                    double rendimento;
                    double total;
                    FILE *pp2 = fopen("poupanca.txt", "r");
                    fscanf(pp2, "%s %s %s %s", v1, v2, v3, v4);
                    valor2 = atoi(v1);
                    dia = atoi(v2);
                    mes = atoi(v3);
                    ano = atoi(v4);
                    cont1 = tempo2.tm_mday - dia;
                    cont2 = (tempo2.tm_mon+1 - mes) *30;
                    cont3 = ((tempo2.tm_year-100) -ano) * 365;
                    rendimento = (cont1 + cont2 + cont3) * 0.002;
                    total = (double) (valor2 * (1 + rendimento));
                    printf("Total atual: %.2lf\n", total);
                    fclose(pp2);
                }
                else if(ops == 4)
                {
                    time_t agora;
                    agora = time(NULL);
                    struct tm tempo2 = *localtime(&agora);

                    int valor2;
                    int dia;
                    int mes;
                    int ano;
                    double valor;
                    char v1[10];
                    char v2[10];
                    char v3[10];
                    char v4[10];
                    int cont1;
                    int cont2;
                    int cont3;
                    double rendimento;
                    double total;

                    FILE *pp2 = fopen("poupanca.txt", "r");
                    fscanf(pp2, "%s %s %s %s", v1, v2, v3, v4);
                    valor2 = atoi(v1);
                    dia = atoi(v2);
                    mes = atoi(v3);
                    ano = atoi(v4);
                    cont1 = tempo2.tm_mday - dia;
                    cont2 = (tempo2.tm_mon+1 - mes) *30;
                    cont3 = ((tempo2.tm_year-100) -ano) * 365;
                    rendimento = (cont1 + cont2 + cont3) * 0.002;
                    total = (double) (valor2 * (1 + rendimento));
                    fclose(pp2);
                    FILE *pp = fopen("poupanca.txt", "w");
                    printf("Valor:\n");
                    scanf("%lf", &valor);
                    getchar();
                    double final = total - valor;
                    fprintf(pp, "%.2lf %s %s %s", final, v2, v3, v4);
                    fclose(pp);
                }
                else if(ops == 5)
                {
                    break;
                }
            }
        }
        else if(op == 5)
        {
            FILE *ss2 = fopen("saldo.txt", "r");
            char st[100];
            while(fscanf(ss2, "%s", st) == 1)
            {
                saldo += atof(st);
            }
            printf("\n-----------------------");
            printf("\nSaldo Total: %.2lf\n", saldo);
            printf("-----------------------");
            fclose(ss2);
        }
        else if(op == 6)
        {
            printf("\nPrograma fechado com sucesso.");
            fclose(fr);
            fclose(fr1);
            break;
        }
}
}