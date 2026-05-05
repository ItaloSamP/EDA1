#include <stdio.h>

void IntercalaVetores(char *V1, char *V2, char *V3) {
    if(*V1 == '\0'){
        while(*V2 != '\0'){
            *V3=*V2;
            V3++;
            V2++;
        }

        *V3 = '\0';
        return;
    }

    if(*V2 == '\0'){
        while(*V1 != '\0'){
            *V3=*V1;
            V3++;
            V1++;
        }

        *V3 = '\0';
        return;
    }

    *V3=*V1;
    V3++;
    *V3=*V2;
    V3++;

    return IntercalaVetores(V1+1, V2+1, V3);
}

int main() {
    char V1[] = "ABCDE" , V2[] = "123" ;  
    char V3[sizeof(V1) + sizeof(V2) - 1]; 

    IntercalaVetores(V1, V2, V3);  
    printf("Intercalacao: %s\n", V3); 
    return 0;
}