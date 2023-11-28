#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void converterParaFormaCorreta(char *str){

int i = 0;

    while(str[i] != '\0'){
        
        // CONVERTENDO PARA MINUSCULA SE FOR DIGITADO MAIUSCULO
        
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
        // SE FOR DIGITADO MINUSCULO, MENSAGEM DE ERRO E EXIT
        
        else if(str[i] >= 'a' && str[i] <= 'z'){
            printf("Dia da semana invalido\n");
            exit(1);
        }
        i++;
    }
}

int valPlaca(char *placa){
    int tamanho = strlen(placa);

    // VERIFICA SE A PLACA TEM 7 OU 8 DIGITOS
    
    if(tamanho != 7 && tamanho != 8){
        printf("Placa invalida\n");
        return 0;
    }

    // VERIFICA SE O HIFEN ESTA NO LUGAR CORRETO SE HOUVER
    
    if(tamanho == 8 && placa[3] != '-'){
        printf("Placa invalida\n");
        return 0;
    }

    // VERIFICA SE HA 7 DIGITOS E SEM HIFEN
    
    if(tamanho == 7 && placa[2] == '-'){
        printf("Placa invalida\n");
        return 0;
    }

    return 1;
}

int main(){
    char placa[10];
    char diaDaSemana[20];
    int valida = 1;

    // LER PLACA E DIA DA SEMANA
    
    scanf("%s", placa);
    scanf("%s", diaDaSemana);

    // VALIDA A PLACA
    
    if(!valPlaca(placa)){
        valida = 0;
    }

    // CORRIGE A FORMA DO DIA DA SEMANA DO VOID
    
    converterParaFormaCorreta(diaDaSemana);

    // VERIFICA SE O FORMATO DO DIA DA SEMANA ESTA OK
    
    if(strcmp(diaDaSemana, "segunda-feira") != 0 && strcmp(diaDaSemana, "terca-feira") != 0 &&
       strcmp(diaDaSemana, "quarta-feira") != 0 && strcmp(diaDaSemana, "quinta-feira") != 0 &&
       strcmp(diaDaSemana, "sexta-feira") != 0 && strcmp(diaDaSemana, "sabado") != 0 &&
       strcmp(diaDaSemana, "domingo") != 0){
        printf("Dia da semana invalido\n");
        valida = 0;
    }

    // VERIFICA A RESTRICAO DE CIRCULAR
    
    if(valida){
        int terminacao = placa[strlen(placa) - 1] - '0';
        if((strcmp(diaDaSemana, "segunda-feira") == 0 && (terminacao == 0 || terminacao == 1)) ||
           (strcmp(diaDaSemana, "terca-feira") == 0 && (terminacao == 2 || terminacao == 3)) ||
           (strcmp(diaDaSemana, "quarta-feira") == 0 && (terminacao == 4 || terminacao == 5)) ||
           (strcmp(diaDaSemana, "quinta-feira") == 0 && (terminacao == 6 || terminacao == 7)) ||
           (strcmp(diaDaSemana, "sexta-feira") == 0 && (terminacao == 8 || terminacao == 9))){
            
            printf("%s nao pode circular %s\n", placa, diaDaSemana);
        
        }else if(strcmp(diaDaSemana, "sabado") == 0 || strcmp(diaDaSemana, "domingo") == 0){
            printf("Nao ha proibicao no fim de semana\n");
        }else{
            printf("%s pode circular %s\n", placa, diaDaSemana);
        }
    }

    return 0;
}
