/*
Write a program to store the first year percentage of students in an array. Write function
for sorting array of floating point numbers in ascending order using - Selection Sort -
Bubble sort and display top five scores
*/
#include <stdio.h>

// Function for Selection Sort
void selectionSort(float arr[], int n) {
    int i, j, minIndex;
    float temp;
    for(i = 0; i < n-1; i++) {
        minIndex = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function for Bubble Sort
void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to display top 5 scores
void displayTopFive(float arr[], int n) {
    int i, count = 0;
    printf("\nTop Five Scores:\n");
    for(i = n-1; i >= 0 && count < 5; i--) {
        printf("%.2f\n", arr[i]);
        count++;
    }
}

int main() {
    float percent[50];
    int n, i, choice;

    // Step 1: Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Step 2: Input student percentages
    printf("Enter percentages of students:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &percent[i]);
    }

    // Step 3: Choose sorting method
    printf("\nChoose sorting method:\n");
    printf("1. Selection Sort\n2. Bubble Sort\nEnter your choice: ");
    scanf("%d", &choice);

    // Step 4: Sort the array
    if(choice == 1) {
        selectionSort(percent, n);
        printf("\nArray sorted using Selection Sort.\n");
    } else if(choice == 2) {
        bubbleSort(percent, n);
        printf("\nArray sorted using Bubble Sort.\n");
    } else {
        printf("Invalid choice!\n");
        return 0;
    }

    // Step 5: Display sorted percentages
    printf("\nSorted Percentages in Ascending Order:\n");
    for(i = 0; i < n; i++) {
        printf("%.2f ", percent[i]);
    }

    // Step 6: Display top five scores
    displayTopFive(percent, n);

    return 0;
}
