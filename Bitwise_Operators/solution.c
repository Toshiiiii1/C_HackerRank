# include <stdio.h>

void calculate_the_maximum(int n, int k) {
    int i, j, maxAND = 0, maxOR = 0, maxXOR = 0;
    for (i=1; i <= n; i++) {
        for (j = i+1; j <= n; j++) {
            if ((i&j) > maxAND && (i&j) < k)
                maxAND = i&j;
            if ((i|j) > maxOR && (i|j) < k)
                maxOR = i|j;
            if ((i^j) > maxXOR && (i^j) < k)
                maxXOR = i^j;
        }
    }

    printf("%d\n%d\n%d\n", maxAND, maxOR, maxXOR);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
    return 0;
}