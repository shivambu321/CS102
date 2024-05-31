//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 4
//PROGRAM 1
//1.Write a C program to demonstrate the various operations of the circular queue using the count
//and % operator as discussed in the class. The program should be menu driven.


/*
Description: 
This program creates a circular queue. It provides four options: insertion (enqueue), deletion (dequeue), display, and exit.
The user can choose any of these operations until they decide to exit. The queue operations are performed using the count and modulus operator.
The count variable keeps track of the number of elements in the queue, and the modulus operator is used to achieve the circular nature of the queue. 
If the queue is full or empty, the program will display a message accordingly. The display operation shows the elements in the queue from front to rear. 
*/


#include<stdio.h>
#include<stdlib.h>

#define SIZE 3


int cq[SIZE];
int front = -1, rear =-1, count = 0;

int isFull() {
    if(count == SIZE)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if(count == 0)
        return 1;
    else
        return 0;
}

void enQueue(int element) {
    if(isFull())
        printf("\n Queue is full!! \n");
    else {
        if(front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        cq[rear] = element;
        count++;
        printf("\n Inserted -> %d", element);
    }
}

void deQueue() {
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
    } else {
        element = cq[front];
        if(front == rear){
            front = -1;
            rear = -1;
        } 
        else {
            front = (front + 1) % SIZE;
        }
        count--;
        printf("\n Deleted element -> %d \n", element);
    }
}

void display() {
    int i;
    if(isEmpty())
        printf(" \n Empty Queue\n");
    else {
        printf("\n Front -> %d ", front);
        printf("\n items -> ");
        for(i=0; i<count; i++)
            printf("%d ",cq[(front+i)%SIZE]);
        printf("\n Rear -> %d \n", rear);
    }
}

int main() {
    int choice, value;
    while(1){
        printf("\n\n##### MENU #####\n");
        printf("1. Insertion 2. Deletion 3. Display 4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&value);
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
