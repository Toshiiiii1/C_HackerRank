# include <stdio.h>
# include <stdlib.h>

int main() {
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    /* tạo mảng 1 chiều bằng con trỏ lưu trữ số lượng sách
    của mỗi kệ sách */
    int *total_number_of_books = (int*)malloc(total_number_of_shelves * sizeof(int));

    /* tạo mảng 2 chiều bằng con trỏ đôi, ứng với hàng là kệ sách, ứng với
    cột là các quyển sách, mỗi phần tử trong mảng 2 chiều lưu trữ số trang
    sách */
    int **total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));

    // khởi tạo các mảng
    int i;
    for (i=0; i < total_number_of_shelves; i++){
        total_number_of_books[i] = 0;
        total_number_of_pages[i] = (int*)malloc(sizeof(int));
    }

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            total_number_of_books[x] += 1;
            /* mỗi khi thêm vào 1 quyển sách thì tăng kích thước của
            kệ sách lên */
            total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
            total_number_of_pages[x][total_number_of_books[x] - 1] = y;
        }

        else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", total_number_of_pages[x][y]);
        }

        else if (type_of_query == 3) {
            int x;
            scanf("%d", &x);
            printf("%d\n", total_number_of_books[x]);
        }
    }

    // giải phóng bộ nhớ
    if (total_number_of_books)
        free(total_number_of_books);
    
    for (i = 0; i < total_number_of_shelves; i++)
        if (*(total_number_of_pages + i))
            free(*(total_number_of_pages + i));
    
    if (total_number_of_pages)
        free(total_number_of_pages);
    return 0;
}