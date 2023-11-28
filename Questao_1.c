#include <stdio.h>
#include <string.h>

int romanoParaDec(char numeroRomano[]){
    
int numeroDecimal = 0;
int length = strlen(numeroRomano);

    for(int i = 0; i < length; i++){
        if(numeroRomano[i] == 'M'){numeroDecimal += 1000;
        }else if(numeroRomano[i] == 'D'){
            numeroDecimal += 500;
        }else if(numeroRomano[i] == 'C'){
        
        if(numeroRomano[i + 1] == 'M'){numeroDecimal += 900;
            i++;
        }else if(numeroRomano[i + 1] == 'D'){numeroDecimal += 400;
            i++;
        }else{numeroDecimal += 100;
            }
        }else if(numeroRomano[i] == 'L'){numeroDecimal += 50;
        }else if(numeroRomano[i] == 'X'){
        
        if (numeroRomano[i + 1] == 'C'){numeroDecimal += 90;
            i++;
        }else if(numeroRomano[i + 1] == 'L'){numeroDecimal += 40;
            i++;
        }else{numeroDecimal += 10;
            }
        }else if(numeroRomano[i] == 'V'){numeroDecimal += 5;
        }else if(numeroRomano[i] == 'I'){
        
        if (numeroRomano[i + 1] == 'X'){numeroDecimal += 9;
            i++;
        }else if(numeroRomano[i + 1] == 'V'){numeroDecimal += 4;
            i++;
        }else{numeroDecimal += 1;
            }
        }
    }

    return numeroDecimal;
}

void decParaBinario(int numeroDecimal){

int numeroBinario[32];
int i = 0;

    while(numeroDecimal > 0){
        numeroBinario[i] = numeroDecimal % 2;
        numeroDecimal = numeroDecimal / 2;
        i++;
    }

    for(int j = i - 1; j >= 0; j--){
        printf("%d", numeroBinario[j]);
    }
}

void decimalParaHex(int numeroDecimal){
    
char numeroHex[32];
int i = 0;

    while(numeroDecimal > 0){
        int rem = numeroDecimal % 16;

        if(rem < 10){
            numeroHex[i] = rem + '0';
        }else{
            numeroHex[i] = rem - 10 + 'a';
        }

        numeroDecimal = numeroDecimal / 16;
        i++;
    }

    for(int j = i - 1; j >= 0; j--){
        printf("%c", numeroHex[j]);
    }
}

int main(){
    
    char numeroRomano[13];
    scanf("%s", numeroRomano);

    int numeroDecimal = romanoParaDec(numeroRomano);

    printf("%s na base 2: ", numeroRomano);
    decParaBinario(numeroDecimal);
    printf("\n");

    printf("%s na base 10: %d\n", numeroRomano, numeroDecimal);

    printf("%s na base 16: ", numeroRomano);
    decimalParaHex(numeroDecimal);
    printf("\n");

    return 0;
}
