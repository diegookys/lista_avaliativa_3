#include <stdio.h>
#include <string.h>

void converterParaFormatoCorreto(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        // Converte todas as letras para minusculas
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        i++;
    }
}

int main() {
    char placa[10];
    char dia_semana[20];
    int valido = 1;

    // Leitura da placa e do dia da semana
    scanf("%s", placa);
    scanf("%s", dia_semana);

    // Verificacao do formato da placa
    if (strlen(placa) != 7 && strlen(placa) != 8) {
        printf("Placa invalida\n");
        valido = 0;
    }

    // Corrigir o formato do dia da semana
    converterParaFormatoCorreto(dia_semana);

    // Verificacao do formato do dia da semana
    if (strcmp(dia_semana, "segunda-feira") != 0 && strcmp(dia_semana, "terca-feira") != 0 &&
        strcmp(dia_semana, "quarta-feira") != 0 && strcmp(dia_semana, "quinta-feira") != 0 &&
        strcmp(dia_semana, "sexta-feira") != 0 && strcmp(dia_semana, "sabado") != 0 &&
        strcmp(dia_semana, "domingo") != 0) {
        printf("Dia da semana invalido\n");
        valido = 0;
    }

    // Verificacao da restrição de circulacao
    if (valido) {
        int terminacao = placa[strlen(placa) - 1] - '0';
        if ((strcmp(dia_semana, "segunda-feira") == 0 && (terminacao == 0 || terminacao == 1)) ||
            (strcmp(dia_semana, "terca-feira") == 0 && (terminacao == 2 || terminacao == 3)) ||
            (strcmp(dia_semana, "quarta-feira") == 0 && (terminacao == 4 || terminacao == 5)) ||
            (strcmp(dia_semana, "quinta-feira") == 0 && (terminacao == 6 || terminacao == 7)) ||
            (strcmp(dia_semana, "sexta-feira") == 0 && (terminacao == 8 || terminacao == 9))) {
            printf("%s nao pode circular %s\n", placa, dia_semana);
        } else if (strcmp(dia_semana, "sabado") == 0 || strcmp(dia_semana, "domingo") == 0) {
            
printf("Nao ha proibicao no fim de semana\n");
        } else {
            printf("%s pode circular %s\n", placa, dia_semana);
        }
    }

    return 0;
}
