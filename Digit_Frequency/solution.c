# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    int frequency[10] = {0,0,0,0,0,0,0,0,0,0};
    int i, j;
    for (i=0; i <= 9; i++) {
        for (j=0; j < strlen(s); j++) {
            if (i == *(s + j) - 48)
                frequency[i]++;
        }
    }

    for (i=0; i <= 9; i++)
        printf("%d ", frequency[i]);
    return 0;
}