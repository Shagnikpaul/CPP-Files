#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial linked list
struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
};
    
// Function to create a new node
struct Node *createNode(int coefficient, int exponent)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the polynomial linked list
void appendTerm(struct Node **poly, int coefficient, int exponent)
{
    struct Node *newNode = createNode(coefficient, exponent);
    if (*poly == NULL)
    { // If the polynomial is empty
        *poly = newNode;
    }
    else
    {
        struct Node *temp = *poly;
        while (temp->next != NULL)
        { // Traverse to the end
            temp = temp->next;
        }
        temp->next = newNode; // Add the new term at the end
    }
}

// Function to display the polynomial
void displayPolynomial(struct Node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent > poly2->exponent)
        {
            appendTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            appendTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else
        {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            appendTerm(&result, sumCoeff, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1
    while (poly1 != NULL)
    {
        appendTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2
    while (poly2 != NULL)
    {
        appendTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;

    // First polynomial: 3x^3 + 5x^2 + 6
    appendTerm(&poly1, 3, 3);
    appendTerm(&poly1, 5, 2);
    appendTerm(&poly1, 6, 0);

    // Second polynomial: 4x^2 + 2x + 1
    appendTerm(&poly2, 4, 2);
    appendTerm(&poly2, 2, 1);
    appendTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node *sum = addPolynomials(poly1, poly2);
    printf("Sum of polynomials: ");
    displayPolynomial(sum);

    return 0;
}