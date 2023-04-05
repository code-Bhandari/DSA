#include <stdio.h>

int hcf(int num1, int num2);
int lcm(int num1, int num2);
int factorial(int num);
int fibonacci(int num);

int main() {
    int choice, num1, num2, num, result;

    do {
        printf("Menu\n");
        printf("1. HCF of two numbers\n");
        printf("2. LCM of two numbers\n");
        printf("3. Factorial of a number\n");
        printf("4. Fibonacci series\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting program...\n");
                break;
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = hcf(num1, num2);
                printf("HCF of %d and %d is %d\n", num1, num2, result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = lcm(num1, num2);
                printf("LCM of %d and %d is %d\n", num1, num2, result);
                break;
            case 3:
                printf("Enter a number: ");
                scanf("%d", &num);
                result = factorial(num);
                printf("Factorial of %d is %d\n", num, result);
                break;
            case 4:
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Fibonacci series upto %d terms is: ", num);
                for (int i = 0; i < num; i++) {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

int hcf(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return hcf(num2, num1 % num2);
    }
}

int lcm(int num1, int num2) {
    static int multiple = 0;
    multiple += num2;
    if (multiple % num1 == 0 && multiple % num2 == 0) {
        return multiple;
    } else {
        return lcm(num1, num2);
    }
}

int factorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int fibonacci(int num) {
    if (num == 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}
