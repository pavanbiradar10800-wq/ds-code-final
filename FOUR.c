/*
The Department of Computer Engineering has a student’s club named ’Pinnacle Club’.
Students of the second, third and final year of the department can be granted
membership on request. Similarly one may cancel the membership of the club. First node
is reserved for the president of the club and the last node is reserved for the secretary of
the club. Write a program to maintain club member‘s information using singly linked
lists. Store student PRN and Name. Write functions to:
a) Add and delete the members as well as president or even secretary. b) Compute total
number of members of club c) Display members d) Two linked lists exist for two
divisions. Concatenate two lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Club Member
struct Node {
    char name[50];
    int prn;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(char name[], int prn) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->prn = prn;
    newNode->next = NULL;
    return newNode;
}

// Function to display members
void display(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("\nNo members in the club.\n");
        return;
    }
    printf("\n--- Pinnacle Club Members ---\n");
    while (temp != NULL) {
        printf("PRN: %d\tName: %s\n", temp->prn, temp->name);
        temp = temp->next;
    }
}

// Function to count total members
int countMembers(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Add President (at beginning)
void addPresident(struct Node** head, char name[], int prn) {
    struct Node* newNode = createNode(name, prn);
    newNode->next = *head;
    *head = newNode;
    printf("President added successfully!\n");
}

// Add Secretary (at end)
void addSecretary(struct Node** head, char name[], int prn) {
    struct Node* newNode = createNode(name, prn);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Secretary added successfully!\n");
}

// Add Member (between President and Secretary)
void addMember(struct Node** head, char name[], int prn) {
    struct Node* newNode = createNode(name, prn);
    if (*head == NULL) {
        printf("Add President and Secretary first!\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Member added successfully!\n");
}

// Delete President (first node)
void deletePresident(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("President deleted!\n");
}

// Delete Secretary (last node)
void deleteSecretary(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    else
        *head = NULL;
    free(temp);
    printf("Secretary deleted!\n");
}

// Delete a Member (by PRN)
void deleteMember(struct Node** head, int prn) {
    struct Node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->prn != prn) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Member with PRN %d not found!\n", prn);
        return;
    }
    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Member deleted!\n");
}

// Concatenate two linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

// Main Function
int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int choice, prn;
    char name[50];

    while (1) {
        printf("\n--- Pinnacle Club Menu ---\n");
        printf("1. Add President\n2. Add Secretary\n3. Add Member\n4. Delete President\n5. Delete Secretary\n6. Delete Member\n7. Display Members\n8. Count Members\n9. Create Second Division List\n10. Concatenate Lists\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter President Name: ");
                scanf("%s", name);
                printf("Enter PRN: ");
                scanf("%d", &prn);
                addPresident(&head1, name, prn);
                break;

            case 2:
                printf("Enter Secretary Name: ");
                scanf("%s", name);
                printf("Enter PRN: ");
                scanf("%d", &prn);
                addSecretary(&head1, name, prn);
                break;

            case 3:
                printf("Enter Member Name: ");
                scanf("%s", name);
                printf("Enter PRN: ");
                scanf("%d", &prn);
                addMember(&head1, name, prn);
                break;

            case 4:
                deletePresident(&head1);
                break;

            case 5:
                deleteSecretary(&head1);
                break;

            case 6:
                printf("Enter PRN of member to delete: ");
                scanf("%d", &prn);
                deleteMember(&head1, prn);
                break;

            case 7:
                display(head1);
                break;

            case 8:
                printf("\nTotal Members: %d\n", countMembers(head1));
                break;

            case 9:
                printf("\nCreating Second Division List:\n");
                printf("Enter President Name: ");
                scanf("%s", name);
                printf("Enter PRN: ");
                scanf("%d", &prn);
                addPresident(&head2, name, prn);
                printf("Enter Secretary Name: ");
                scanf("%s", name);
                printf("Enter PRN: ");
                scanf("%d", &prn);
                addSecretary(&head2, name, prn);
                break;

            case 10:
                head1 = concatenate(head1, head2);
                printf("\nLists concatenated successfully!\n");
                break;

            case 11:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
