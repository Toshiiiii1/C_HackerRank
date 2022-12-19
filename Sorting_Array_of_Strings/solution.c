#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ham tinh so luong cac ki tu khac nhau trong chuoi */
int count_unique_char(const char *str)
{

	int hash[128] = {0};
	int i, c = 0;

	// reading each character of str[]
	for (i = 0; i < strlen(str); ++i)
	{
		// set the position corresponding
		// to the ASCII value of str[i] in hash[] to 1
		hash[str[i]] = 1;
	}

	// counting number of unique characters
	// repeated elements are only counted once
	for (i = 0; i < 128; ++i)
	{
		c += hash[i];
	}

	return c;
}

/* ham so sanh hai chuoi theo thu tu tang dan bang chu cai */
int lexicographic_sort(const char *a, const char *b)
{
	int i, n1 = strlen(a), n2 = strlen(b), minLength = (n1 < n2) ? n1 : n2;
	// so sanh tung ki tu trong hai chuoi
	for (i = 0; i < minLength; i++)
	{
		if (a[i] == b[i])
		{
			continue;
		}
		else
			return a[i] > b[i];
	}
	/* neu hai chuoi giong nhau cac ki tu dau tien thi
	kiem tra do dai cua chuoi thu hai */
	return (n2 < n1) ? 1 : 0;
}

/* ham so sanh hai chuoi theo thu tu giam dan bang chu cai */
int lexicographic_sort_reverse(const char *a, const char *b)
{
	int i, n1 = strlen(a), n2 = strlen(b), minLength = (n1 < n2) ? n1 : n2;
	// so sanh tung ki tu trong hai chuoi
	for (i = 0; i < minLength; i++)
	{
		if (a[i] == b[i])
		{
			continue;
		}
		else
			return a[i] < b[i];
	}
	/* neu hai chuoi giong nhau cac ki tu dau tien thi
	kiem tra do dai cua chuoi thu nhat */
	return (n1 < n2) ? 1 : 0;
}

/* ham so sanh hai chuoi theo so luong cac ki tu khac nhau */
int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
	int n1 = count_unique_char(a), n2 = count_unique_char(b);
	// neu hai chuoi co cung so luong thi so sanh chung theo thu tu bang chu cai
	if (n1 == n2)
		return lexicographic_sort(a, b);
	else
		return n1 > n2;
}

/* ham so sanh hai chuoi theo do dai chuoi */
int sort_by_length(const char *a, const char *b)
{
	int n1 = strlen(a), n2 = strlen(b);
	// neu hai chuoi co cung so luong thi so sanh chung theo thu tu bang chu cai
	if (n1 == n2)
		return lexicographic_sort(a, b);
	else
		return n1 > n2;
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if ((*cmp_func)(arr[i], arr[j]))
			{
				char *temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	// so luong phan tu
	int n, i;
	scanf("%d", &n);

	// con tro doi = mang hai chieu
	char **arr;
	arr = (char **)malloc(n * sizeof(char *));

	for (i = 0; i < n; i++)
	{
		*(arr + i) = malloc(1024 * sizeof(char));
		scanf("%s", *(arr + i));
		*(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
	}

	string_sort(arr, n, lexicographic_sort);
	for (i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, lexicographic_sort_reverse);
	for (i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, sort_by_length);
	for (i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, sort_by_number_of_distinct_characters);
	for (i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");
	return 0;
}