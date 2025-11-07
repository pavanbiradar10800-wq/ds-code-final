/*
a) Write a program to store roll numbers of student in array who attended a training
program in random order. Write a function for searching whether a particular student
attended a training program or not, using Linear search.
*/
#include <stdio.h>

int main() {
    int n, roll[50], i, search, found = 0;

    // Step 1: Input number of students
    printf("Enter number of students who attended the training: ");
    scanf("%d", &n);

    // Step 2: Input roll numbers
    printf("Enter roll numbers of students:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &roll[i]);
    }

    // Step 3: Input roll number to search
    printf("Enter roll number to search: ");
    scanf("%d", &search);

    // Step 4: Linear Search
    for(i = 0; i < n; i++) {
        if(roll[i] == search) {
            found = 1;
            break;
        }
    }

    // Step 5: Display result
    if(found == 1)
        printf("Student with roll number %d attended the training program.\n", search);
    else
        printf("Student with roll number %d did NOT attend the training program.\n", search);

    return 0;
}
