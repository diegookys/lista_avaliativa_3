#include <stdio.h>
#include <string.h>

int romanToDecimal(char romanNum[]) {
    int decimalNum = 0;
    int length = strlen(romanNum);

    for (int i = 0; i < length; i++) {
        if (romanNum[i] == 'M') {
            decimalNum += 1000;
        }
        else if (romanNum[i] == 'D') {
            decimalNum += 500;
        }
        else if (romanNum[i] == 'C') {
            if (romanNum[i + 1] == 'M') {
                decimalNum += 900;
                i++;
            }
            else if (romanNum[i + 1] == 'D') {
                decimalNum += 400;
                i++;
            }
            else {
                decimalNum += 100;
            }
        }
        else if (romanNum[i] == 'L') {
            decimalNum += 50;
        }
        else if (romanNum[i] == 'X') {
            if (romanNum[i + 1] == 'C') {
                decimalNum += 90;
                i++;
            }
            else if (romanNum[i + 1] == 'L') {
                decimalNum += 40;
                i++;
            }
            else {
                decimalNum += 10;
            }
        }
        else if (romanNum[i] == 'V') {
            decimalNum += 5;
        }
        else if (romanNum[i] == 'I') {
            if (romanNum[i + 1] == 'X') {
                decimalNum += 9;
                i++;
            }
            else if (romanNum[i + 1] == 'V') {
                decimalNum += 4;
                i++;
            }
            else {
                decimalNum += 1;
            }
        }
    }

    return decimalNum;
}

void decimalToBinary(int decimalNum) {
    int binaryNum[32];
    int i = 0;

    while (decimalNum > 0) {
        binaryNum[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

void decimalToHexadecimal(int decimalNum) {
    char hexadecimalNum[32];
    int i = 0;

    while (decimalNum > 0) {
        int rem = decimalNum % 16;

        if (rem < 10) {
            hexadecimalNum[i] = rem + '0';
        }
        else {
            hexadecimalNum[i] = rem - 10 + 'a';
        }

        decimalNum = decimalNum / 16;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimalNum[j]);
    }
}

int main() {
    char romanNum[13];
    scanf("%s", romanNum);

    int decimalNum = romanToDecimal(romanNum);

    printf("%s na base 2: ", romanNum);
    decimalToBinary(decimalNum);
    printf("\n");

    printf("%s na base 10: %d\n", romanNum, decimalNum);

    printf("%s na base 16: ", romanNum);
    decimalToHexadecimal(decimalNum);
    printf("\n");

    return 0;
}
