#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the stack

int stack[MAX_SIZE]; // Array to store the stack elements
int top = -1; // Top of the stack

void push(int element) {
    if(top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    top++;
    stack[top] = element;
    printf("%d pushed to the stack\n", element);
}

void pop() {
    if(top == -1) {
        printf("Error: Stack underflow\n");
        return;
    }
    printf("%d popped from the stack\n", stack[top]);
    top--;
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for(int i=top; i>=0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, element;
    do {
        printf("\n");
        printf("Menu:\n");
        printf("1. Push an element to the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Display the stack elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);

    return 0;
}
