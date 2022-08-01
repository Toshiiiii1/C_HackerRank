# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    int i;
    for (i=0; i < strlen(s); i++){
        if (*(s+i) == ' ' || *(s+i) == '\0')
            printf("\n");
        else
            printf("%c", *(s+i));
    }
    return 0;
}