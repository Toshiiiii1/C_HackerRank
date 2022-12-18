#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
	// xac dinh xem gender la nam hay nu, roi tinh tong
	int index = (gender == 'b') ? 0 : 1, sum = 0;
	for (index; index < number_of_students; index+=2) {
		sum += marks[index];
	}
	return sum;
}

int main() {
    int number_of_students;
    char gender;
    int sum, student;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}