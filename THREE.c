/*
Consider the telephone book database of N clients. Make use of a hash table
implementation to quickly look up a client’s telephone number. Make use of linear
probing, double hashing and quadratic collision handling techniques.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 10   // Hash table size

// Structure to store client information
struct Client {
    int key;             // Phone number (as key)
    char name[30];       // Client name
};

// Initialize hash table with empty values
void initialize(struct Client hashTable[]) {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i].key = -1;      // -1 indicates empty
        strcpy(hashTable[i].name, "");
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using Linear Probing
void insertLinear(struct Client hashTable[], int key, char name[]) {
    int index = hash(key);
    int i = 0;

    while(hashTable[(index + i) % SIZE].key != -1 && i < SIZE)
        i++;

    if(i < SIZE) {
        hashTable[(index + i) % SIZE].key = key;
        strcpy(hashTable[(index + i) % SIZE].name, name);
    } else {
        printf("Hash Table is full!\n");
    }
}

// Insert using Quadratic Probing
void insertQuadratic(struct Client hashTable[], int key, char name[]) {
    int index = hash(key);
    int i = 0;

    while(hashTable[(index + i * i) % SIZE].key != -1 && i < SIZE)
        i++;

    if(i < SIZE) {
        hashTable[(index + i * i) % SIZE].key = key;
        strcpy(hashTable[(index + i * i) % SIZE].name, name);
    } else {
        printf("Hash Table is full!\n");
    }
}

// Secondary hash function for double hashing
int hash2(int key) {
    return (7 - (key % 7));   // must be non-zero
}

// Insert using Double Hashing
void insertDouble(struct Client hashTable[], int key, char name[]) {
    int index = hash(key);
    int step = hash2(key);
    int i = 0;

    while(hashTable[(index + i * step) % SIZE].key != -1 && i < SIZE)
        i++;

    if(i < SIZE) {
        hashTable[(index + i * step) % SIZE].key = key;
        strcpy(hashTable[(index + i * step) % SIZE].name, name);
    } else {
        printf("Hash Table is full!\n");
    }
}

// Search for a client
void search(struct Client hashTable[], int key) {
    int index = hash(key);
    int i = 0;

    while(i < SIZE) {
        int pos = (index + i) % SIZE;
        if(hashTable[pos].key == key) {
            printf("Client found: %s (Phone: %d)\n", hashTable[pos].name, hashTable[pos].key);
            return;
        }
        i++;
    }
    printf("Client not found!\n");
}

// Display hash table
void display(struct Client hashTable[]) {
    printf("\nHash Table:\n");
    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i].key != -1)
            printf("[%d] => %d : %s\n", i, hashTable[i].key, hashTable[i].name);
        else
            printf("[%d] => Empty\n", i);
    }
}

int main() {
    struct Client hashTable[SIZE];
    int choice, key;
    char name[30];

    initialize(hashTable);

    while(1) {
        printf("\n--- Telephone Directory using Hash Table ---\n");
        printf("1. Insert using Linear Probing\n");
        printf("2. Insert using Quadratic Probing\n");
        printf("3. Insert using Double Hashing\n");
        printf("4. Search Client\n");
        printf("5. Display Table\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter phone number: ");
                scanf("%d", &key);
                printf("Enter client name: ");
                scanf("%s", name);
                insertLinear(hashTable, key, name);
                break;

            case 2:
                printf("Enter phone number: ");
                scanf("%d", &key);
                printf("Enter client name: ");
                scanf("%s", name);
                insertQuadratic(hashTable, key, name);
                break;

            case 3:
                printf("Enter phone number: ");
                scanf("%d", &key);
                printf("Enter client name: ");
                scanf("%s", name);
                insertDouble(hashTable, key, name);
                break;

            case 4:
                printf("Enter phone number to search: ");
                scanf("%d", &key);
                search(hashTable, key);
                break;

            case 5:
                display(hashTable);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
