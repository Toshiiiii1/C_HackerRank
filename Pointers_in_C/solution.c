# include <stdio.h>

void update(int *a, int *b) {
    int temp1 = *a, temp2 = *b;
    *a = temp1 + temp2;
    *b = (temp1 - temp2 > 0)? temp1 - temp2 : temp2 - temp1;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
    return 0;
}