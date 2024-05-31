//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 
//
//

/*
Description: This program uses an array to implement the queue. The enQueue function is used to insert an element into the queue,
the deQueue function is used to remove an element from the queue, and the display function is used to display the elements of the queue. 
The main function presents a menu for the user to choose an operation.
*/

#include <stdio.h>
#define SIZE 5

int q[SIZE], front = -1, rear = -1;

void enQueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue is Full!!\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        q[rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

void deQueue() {
    if (front == -1)
        printf("Queue is Empty!!\n");
    else {
        printf("Removed -> %d\n", q[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display() {
    if (rear == -1)
        printf("Queue is Empty!!!\n");
    else {
        int i;
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", q[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    printf("\n:: Queue Implementation using Array ::\n");
    while (1) {
        printf("\n****** MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d", &value);
                    enQueue(value);
                    break;
            case 2: deQueue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nWrong selection!!! Try again!!!\n");
        }
    }
}
