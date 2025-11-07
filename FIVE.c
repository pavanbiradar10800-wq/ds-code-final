/*
 The ticket booking system of Cinemax theater has to be implemented. There are 10 rows
and 7 seats in each row. Doubly linked list has to be maintained to keep track of free seats
in rows. Assume some random booking to start with. Use an array to store pointers
(Head pointer) to each row. On demand
a) The list of available seats is to be displayed b) The seats are to be booked c) The
booking can be cancelled.
*/
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define SEATS 7

// Structure for each seat node
struct Seat {
    int seatNo;
    int booked; // 0 = free, 1 = booked
    struct Seat *next;
    struct Seat *prev;
};

// Function to create a doubly linked list for one row
struct Seat* createRow() {
    struct Seat *head = NULL, *temp = NULL, *newSeat = NULL;
    for (int i = 1; i <= SEATS; i++) {
        newSeat = (struct Seat*)malloc(sizeof(struct Seat));
        newSeat->seatNo = i;
        newSeat->booked = 0; // initially all seats free
        newSeat->next = NULL;
        newSeat->prev = temp;

        if (head == NULL)
            head = newSeat;
        else
            temp->next = newSeat;

        temp = newSeat;
    }
    return head;
}

// Display available seats
void displayAvailable(struct Seat* rows[]) {
    printf("\n--- Available Seats ---\n");
    for (int i = 0; i < ROWS; i++) {
        struct Seat *temp = rows[i];
        printf("Row %d: ", i + 1);
        while (temp != NULL) {
            if (temp->booked == 0)
                printf("%d ", temp->seatNo);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Book a seat
void bookSeat(struct Seat* rows[], int row, int seat) {
    if (row < 1 || row > ROWS || seat < 1 || seat > SEATS) {
        printf("Invalid row or seat number!\n");
        return;
    }

    struct Seat *temp = rows[row - 1];
    while (temp != NULL && temp->seatNo != seat)
        temp = temp->next;

    if (temp == NULL) {
        printf("Seat not found!\n");
        return;
    }

    if (temp->booked == 1)
        printf("Seat already booked!\n");
    else {
        temp->booked = 1;
        printf("Seat %d in Row %d booked successfully!\n", seat, row);
    }
}

// Cancel a booking
void cancelSeat(struct Seat* rows[], int row, int seat) {
    if (row < 1 || row > ROWS || seat < 1 || seat > SEATS) {
        printf("Invalid row or seat number!\n");
        return;
    }

    struct Seat *temp = rows[row - 1];
    while (temp != NULL && temp->seatNo != seat)
        temp = temp->next;

    if (temp == NULL) {
        printf("Seat not found!\n");
        return;
    }

    if (temp->booked == 0)
        printf("Seat is not booked yet!\n");
    else {
        temp->booked = 0;
        printf("Booking for Seat %d in Row %d cancelled successfully!\n", seat, row);
    }
}

// Random initial bookings (for demo)
void randomBooking(struct Seat* rows[]) {
    rows[0]->booked = 1;            // Seat 1 in Row 1
    rows[1]->next->booked = 1;      // Seat 2 in Row 2
    rows[2]->next->next->booked = 1; // Seat 3 in Row 3
    rows[4]->booked = 1;            // Seat 1 in Row 5
}

int main() {
    struct Seat* rows[ROWS];
    int choice, row, seat;

    // Step 1: Create 10 rows (each a doubly linked list)
    for (int i = 0; i < ROWS; i++)
        rows[i] = createRow();

    // Step 2: Assume some random bookings
    randomBooking(rows);

    // Step 3: Menu-driven operations
    while (1) {
        printf("\n=== CINEMAX TICKET BOOKING SYSTEM ===\n");
        printf("1. Display Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel a Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailable(rows);
                break;

            case 2:
                printf("Enter Row (1-10): ");
                scanf("%d", &row);
                printf("Enter Seat (1-7): ");
                scanf("%d", &seat);
                bookSeat(rows, row, seat);
                break;

            case 3:
                printf("Enter Row (1-10): ");
                scanf("%d", &row);
                printf("Enter Seat (1-7): ");
                scanf("%d", &seat);
                cancelSeat(rows, row, seat);
                break;

            case 4:
                printf("Thank you for using Cinemax System!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
