#include <stdio.h>

int main() {
    double num1, num2;     // store user numbers
    char opera;            // store operator (+, -, *, /)

    // Take first number
    printf("Enter first number: ");
    scanf("%lf", &num1);

    // Take operator    
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &opera);

    // Take second number
    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Switch used for selecting operation
    switch (opera) {
        case '+':
            printf("Result: %.2lf\n", num1 + num2);
            break;

        case '-':
            printf("Result: %.2lf\n", num1 - num2);
            break;

        case '*':
            printf("Result: %.2lf\n", num1 * num2);
            break;

        case '/':
            if (num2 == 0)   // Prevent division by zero
                printf("Error! Division by zero is not allowed.\n"); 
            else
                printf("Result: %.2lf\n", num1 / num2);
            break;

        default:
            printf("Invalid operator!\n");
    }

    return 0;
}
