# include <stdio.h>
# include <math.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    /* đưa ma trận về đồ thị Oxy với tâm (ứng với giá trị nằm chính giữa ma trận) là điểm 0,0*/
    for (i = n-1; i >= 1-n; i--){
        for (j = 1-n; j <= n-1; j++)
            printf("%d ", (abs(i) < abs(j)) ? abs(j)+1 : abs(i)+1);
        printf("\n");
    }    
    return 0;
}