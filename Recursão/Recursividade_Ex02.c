#include <stdio.h>
int tamstring(const char s[])
{
    if (s[0] == '\0')
        return 0;
    return 1 + tamstring(s + 1);
}

int main(void)
{
     char s[20];
    int t;
    printf("Tamanho de string\n\n");
    printf("\nDigite a string: ");
    scanf("%19s", s);
    t=tamstring(s);
    printf("\n\nO tamanho eh %d", t);
}
