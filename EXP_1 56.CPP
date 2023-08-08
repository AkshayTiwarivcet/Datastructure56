#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int x) {
  if (top == MAX - 1) {
    printf("Stack overflow\n");
    return;
  }
  top++;
  stack[top] = x;
  printf("Pushed %d into the stack\n", x);
}

int pop() {
  if (top == -1) {
    printf("Stack underflow\n");
    return -1;
  }
  int x = stack[top];
  top--;
  printf("Popped %d from the stack\n", x);
  return x;
}

int peek() {
  if (top == -1) {
    printf("Stack is empty\n");
    return -1;
  }
  int x = stack[top];
  printf("The top element is %d\n", x);
  return x;
}

void display() {
  if (top == -1) {
    printf("Stack is empty\n");
    return;
  }
  printf("The elements of the stack are:\n");
  for (int i = top; i >= 0; i--) {
    printf("%d\n", stack[i]);
  }
}

int menu() {
  int choice;
  printf("\nChoose an option:\n");
  printf("1. Push an element into the stack\n");
  printf("2. Pop an element from the stack\n");
  printf("3. Peek at the top element of the stack\n");
  printf("4. Display the elements of the stack\n");
  printf("5. Exit\n");
  scanf("%d", &choice);
  return choice;
}

int main() {
  int x;
  while (1) {
    int choice = menu();
    switch (choice) {
      case 1:
        printf("Enter an element to push: ");
        scanf("%d", &x);
        push(x);
        break;
      case 2:
        x = pop();
        break;
      case 3:
        x = peek();
        break;
      case 4:
        display();
        break;
      case 5:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}

