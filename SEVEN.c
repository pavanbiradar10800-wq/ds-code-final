/*
Pizza parlor accepting maximum M orders. Orders are served on a first come first served
basis. Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write a program
for simulating job queue. Write functions to add jobs and delete jobs from the queue.
*/
#include <stdio.h>
#define MAX 5   // maximum number of orders (you can change this)

int queue[MAX];
int front = -1, rear = -1;

// Function to add (enqueue) an order
void addOrder(int orderID) {
    if (rear == MAX - 1) {
        printf("🍕 Sorry! No more orders can be accepted (Queue Full)\n");
        return;
    }

    if (front == -1)  // if queue is empty
        front = 0;

    rear++;
    queue[rear] = orderID;
    printf("✅ Order %d added successfully!\n", orderID);
}

// Function to delete (dequeue) an order
void serveOrder() {
    if (front == -1 || front > rear) {
        printf("😕 No orders to serve (Queue Empty)\n");
        return;
    }

    printf("🍽️  Order %d served!\n", queue[front]);
    front++;

    // Reset queue if all orders are served
    if (front > rear)
        front = rear = -1;
}

// Function to display all orders
void displayOrders() {
    if (front == -1) {
        printf("😕 No pending orders.\n");
        return;
    }

    printf("\n📋 Current Orders in Queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("Order %d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, orderID;

    printf("🍕 Welcome to Pizza Parlor Job Queue System 🍕\n");

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Add Order\n");
        printf("2. Serve Order\n");
        printf("3. Display Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Order ID: ");
            scanf("%d", &orderID);
            addOrder(orderID);
            break;
        case 2:
            serveOrder();
            break;
        case 3:
            displayOrders();
            break;
        case 4:
            printf("👋 Exiting... Thank you!\n");
            return 0;
        default:
            printf("⚠️ Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

