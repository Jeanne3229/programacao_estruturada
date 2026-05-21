#include <stdio.h>
#include <stdlib.h>
#define CARACTERES 50
#define TAM 100



struct Contas{
    int n_conta;
    char nome[CARACTERES];
    int cpf;
    int telefone;
    double saldo;
};

int qtdStr(char texto[]){
    int i = 0;
    while(texto[i] != '\0'){
        i += 1;
    }
    return i;
}

void lerStr(char str[], int max){
    fgets(str, max, stdin);
    int tam = qtdStr(str);
    if(tam > 0 && str[tam - 1] == '\n'){
        str[tam - 1] = '\0';
    }
}



//funcao A
int busca(struct Contas *C, int contanumero, int tamanho){
    if(tamanho == 0){ //se estiver vazio
        return -1;
    }
    for(int i = 0; i < tamanho; i++){
        if(C[i].n_conta == contanumero){ //se o numero da conta ja existir
            return i;
        }
    }
    return -2; //se nao encontrar a conta
        }

//funcao f
void exibir(struct Contas *C, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("\nNUMERO DA CONTA: %d", C[i].n_conta);
        printf("\nNOME DO TITULAR: %s", C[i].nome);
        printf("\nTELEFONE: %d", C[i].telefone);
        printf("\n====\n"); }
}

int Cadastro(struct Contas *v, int i,int contan){ //testar se o numero da conta ja existe
    int pos = busca(v, contan, i);
    if(pos >= 0){
       printf("\nNao e possivel cadastrar pois numero da conta ja existe!");
       return -1;
    }
    else{
        printf("\n======\n");
        printf("\nDigite seu nome: ");
        lerStr(v[i].nome, CARACTERES);
        lerStr(v[i].nome, CARACTERES);
        printf("\nDigite o cpf: ");
        scanf("%d", &v[i].cpf);
        printf("\nDigite o telefone: ");
        scanf("%d", &v[i].telefone);
        printf("\nDigite o saldo: ");
        scanf("%lf", &v[i].saldo);
        v[i].n_conta = contan;
        printf("\n=========\n");
        return i;
    }

}

void ConsultaSaldo(struct Contas *C, int contan, int tamanho){
    printf("\n====CONSULTA SALDO====\n");
    int pos = busca(C, contan, tamanho);
    if(pos >= 0){
        printf("\nNUMERO CONTA: %d", contan);
        printf("\nSALDO: %lf", C[pos].saldo);
        printf("\n------\n");
    }
    else{
        printf("\nNao existe esse numero de conta no sistema!");
    }
}

void Deposito(struct Contas *C, int numero, int tamanho){
    int pos = busca(C, numero, tamanho);
    double valor;
    if(pos >= 0){
        printf("\nDigite o valor que voce deseja que seja depositado na conta: ");
        scanf("%lf", &valor);
        C[pos].saldo += valor;
    }
    else{
        printf("\nNao existe essse numero de conta no sistema");
    }
}

void Saque(struct Contas *C, int numero, int tamanho){
    int pos = busca(C, numero, tamanho);
    if(pos >= 0){
        printf("\nDigite o valor que voce deseja que seja sacado da conta: ");
        double valor;
        scanf("%lf", &valor);
        if(valor <= C[pos].saldo){
            C[pos].saldo -= valor;
        }
        else if(valor > C[pos].saldo){
            printf("\nsaldo insuficiente!");
        }
        }
    else{
            printf("\nNumero da conta nao existe!");
} }


int main(){
    struct Contas corrente[TAM];
    struct Contas poupanca[TAM];
    int entrada = 1;
    int tipo;
    int qtdcorrente = 0;
    int qtdpoupanca = 0;
    int nconta;

    do{
        printf("\n====MENU====\n");
        printf("\n1- Cadastro nova conta");
        printf("\n2- Consultar saldo");
        printf("\n3- Fazer um deposito em uma conta");
        printf("\n4- Saque");
        printf("\n5- Exibir informacoes\n");
        printf("\nDigite a escolha do menu que voce deseja(0 pra sair a qualquer momento): ");
        scanf("%d", &entrada);
        //opcao 1
        if(entrada == 1){
            printf("\nDigite o tipo de conta que voce deseja operar(8 corrente - 9 poupanca): ");
            scanf("%d", &tipo);

            if(tipo != 8 && tipo != 9){
            printf("\nEste tipo de conta nao existe! FIM DA OPERAÇÃO!");
            continue;}

            if(tipo == 8){
                if(qtdcorrente >= TAM){
                    printf("\nLIMITE ATINGIDO!");
                    continue;}

            printf("\nDigite o numero da conta que voce deseja cadastrar: ");
            scanf("%d", &nconta);
            int resultado = Cadastro(corrente, qtdcorrente, nconta);
            if(resultado >= 0){
                qtdcorrente += 1;
            }
            else{
                continue;
            }
            }

            else if(tipo == 9){
                 if(qtdpoupanca >= TAM){
                    printf("\nLIMITE ATINGIDO!");
                    continue;}

            printf("\nDigite o numero da conta que voce deseja cadastrar: ");
            scanf("%d", &nconta);
            int resultado = Cadastro(poupanca, qtdpoupanca, nconta);
            if(resultado >= 0){
                qtdpoupanca += 1;
            }
            else{
                continue;
            }
            }
            }
        //opcao 2

        if(entrada == 2){
            printf("\nDigite o tipo de conta que voce deseja operar(8 corrente - 9 poupanca): ");
            scanf("%d", &tipo);

            if(tipo != 8 && tipo != 9){
                printf("\nEste tipo de conta nao existe! FIM DA OPERAÇÃO!");
                continue; }

            if(tipo == 8){
                printf("\nDigite o numero da conta que voce deseja ver o saldo: ");
                scanf("%d", &nconta);
                ConsultaSaldo(corrente, nconta, qtdcorrente);
            }
            else if(tipo == 9){
                printf("\nDigite o numero da conta que voce deseja ver o saldo: ");
                scanf("%d", &nconta);
                ConsultaSaldo(poupanca, nconta, qtdpoupanca);
            }
        }

        //opcao 3
        if(entrada == 3){
            printf("\nDigite o tipo de conta que voce deseja operar(8 corrente - 9 poupanca): ");
            scanf("%d", &tipo);
            if(tipo != 8 && tipo != 9){
                printf("\nEste tipo de conta nao existe! FIM DA OPERAÇÃO!");
                continue; }

            if(tipo == 8){
                printf("\nDigite o numero da conta que voce deseja fazer um deposito: ");
                scanf("%d", &nconta);
                Deposito(corrente, nconta, qtdcorrente);
            }
            else if(tipo == 9){
                printf("\nDigite o numero da conta que voce deseja fazer um deposito: ");
                scanf("%d", &nconta);
                Deposito(poupanca, nconta, qtdpoupanca);
            }
        }


        //opcao 4
        if(entrada == 4){
            printf("\nDigite o tipo de conta que voce deseja operar(8 corrente - 9 poupanca): ");
            scanf("%d", &tipo);
            if(tipo != 8 && tipo != 9){
                printf("\nEste tipo de conta nao existe! FIM DA OPERAÇÃO!");
                continue; }


            if(tipo == 8){
                printf("\nDigite o numero da conta que voce deseja fazer um saque: ");
                scanf("%d", &nconta);
                Saque(corrente, nconta, qtdcorrente);
            }
            else if(tipo == 9){
                printf("\nDigite o numero da conta que voce deseja fazer um saque: ");
                scanf("%d", &nconta);
                Saque(poupanca, nconta, qtdpoupanca);
            }
        }
        //opcao 5
        if(entrada == 5){
            printf("\nDigite o tipo da conta que voce deseja visualizar(8 pra corrente, 9 pra poupanca): ");
            scanf("%d", &tipo);
            if(tipo != 8 && tipo != 9){
                printf("\nO tipo nao foi encontrado!");
                continue;
            }
            else if(tipo == 8){
                exibir(corrente, qtdcorrente);
            }
            else if(tipo == 9){
                exibir(poupanca, qtdpoupanca);
            }
        }

        } while(entrada != 0);

    return 0;
}
