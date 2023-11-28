#include <stdio.h>
#include <math.h>

int main(){
    
    int meses;
    double aporteMensal, taxaMensal; 
    double valorTotal;

    scanf("%d %lf %lf", &meses, &aporteMensal, &taxaMensal);

    for(int i = 1; i <= meses; i++){
        valorTotal = aporteMensal * (1 + taxaMensal) * ((pow(1 + taxaMensal, i)) - 1) / taxaMensal;
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, valorTotal);
    }

    return 0;
}
