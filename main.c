#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int convert(long long n) {
    int dec = 0, i = 0, rem;

    while (n!=0) {
        rem = n % 10;
        n /= 10;
        if (rem == 1){
            dec += pow(2, i);
        }
        ++i;
    }
    return dec;
}


char isDig(char dig[]){
    char scr[10] = "1234567890";
    int n = strlen(dig);
    for (int i = 0;  i < n; i++){
        if (strchr(scr, dig[i]) == NULL) {
            printf("Error. Please try again.\n");
            return 1;
        }
    }
    return 0;
}

int isbin(char dig[]){
    char scr[10] = "10";
    int n = strlen(dig);
    for (int i = 0;  i < n; i++){
        if (strchr(scr, dig[i]) == NULL) {
            printf("Error. Please try again.\n");
            return 1;
        }
    }
    return 0;
}

int main() {
    int d;
    char nStr[7], asStr[7];

    printf("Enter the size of the set: \n");
    scanf("%s", nStr);
    while(isDigital(nStr)!=0){
        scanf("%s", nStr);
    }


    int n = atoi(nStr);
    int bins[n];
    int decs[n];

    printf("Enter the elements of the set: \n");
    for (d = 0; d < n; d++) {
        scanf("%s", asStr);
        while ( isbinary(asStr) != 0){
            scanf("%s", asStr);
        }
        int s = atoi(asStr);
        bins[d] = s;


    }

    for (int i = 0; i < n; i++) {
        decs[i] = bins[i];

        decs[i] = convert(bins[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d | %d\n", bins[i], decs[i]);
    }
    return 0;
}
