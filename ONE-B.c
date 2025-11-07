/*
b) Write a program to store roll numbers of student array who attended training
programs in sorted order. Write a function for searching whether a particular student
attended a training program or not, using Binary search.
*/
#include <stdio.h>

int main() {
    int n, roll[50], i, search, first, last, middle, found = 0;

    // Step 1: Input number of students
    printf("Enter number of students who attended the training: ");
    scanf("%d", &n);

    // Step 2: Input roll numbers (sorted order)
    printf("Enter roll numbers in sorted order:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &roll[i]);
    }

    // Step 3: Input roll number to search
    printf("Enter roll number to search: ");
    scanf("%d", &search);

    // Step 4: Binary Search logic
    first = 0;
    last = n - 1;
    while(first <= last) {
        middle = (first + last) / 2;

        if(roll[middle] == search) {
            found = 1;
            break;
        }
        else if(roll[middle] < search)
            first = middle + 1;
        else
            last = middle - 1;
    }

    // Step 5: Display result
    if(found == 1)
        printf("Student with roll number %d attended the training program.\n", search);
    else
        printf("Student with roll number %d did NOT attend the training program.\n", search);

    return 0;
}
