#include <stdio.h>
#include <string.h>

void converterParaFormatoCorreto(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        // Converte todas as letras para minúsculas
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        i++;
    }
}

int validarPlaca(char *placa) {
    int tamanho = strlen(placa);

    // Verifica se a placa tem 7 ou 8 dígitos
    if (tamanho != 7 && tamanho != 8) {
        printf("Placa invalida\n");
        return 0;
    }

    // Verifica se há hífen na posição correta (se presente)
    if (tamanho == 8 && placa[3] != '-') {
        printf("Placa invalida\n");
        return 0;
    }

    // Verifica se há exatamente 7 caracteres e não há hífen
    if (tamanho == 7 && placa[2] == '-') {
        printf("Placa invalida\n");
        return 0;
    }

    return 1;
}

int main() {
    char placa[10];
    char dia_semana[20];
    int valido = 1;

    // Leitura da placa e do dia da semana
    scanf("%s", placa);
    scanf("%s", dia_semana);

    // Validar a placa
    if (!validarPlaca(placa)) {
        valido = 0;
    }

    // Corrigir o formato do dia da semana
    converterParaFormatoCorreto(dia_semana);

    // Verificação do formato do dia da semana
    if (strcmp(dia_semana, "segunda-feira") != 0 && strcmp(dia_semana, "terca-feira") != 0 &&
        strcmp(dia_semana, "quarta-feira") != 0 && strcmp(dia_semana, "quinta-feira") != 0 &&
        strcmp(dia_semana, "sexta-feira") != 0 && strcmp(dia_semana, "sabado") != 0 &&
        strcmp(dia_semana, "domingo") != 0) {
        printf("Dia da semana invalido\n");
        valido = 0;
    }

    // Verificação da restrição de circulação
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
