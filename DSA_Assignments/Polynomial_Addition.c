#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term of a polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to create a new term
Term* createTerm(int coefficient, int exponent) {
    Term* term = (Term*)malloc(sizeof(Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

// Function to insert a term into the polynomial
void insertTerm(Term** polynomial, int coefficient, int exponent) {
    Term* term = createTerm(coefficient, exponent);

    if (*polynomial == NULL) {
        *polynomial = term;
    } else {
        Term* current = *polynomial;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = term;
    }
}

// Function to add two polynomials
Term* addPolynomials(Term* polynomial1, Term* polynomial2) {
    Term* result = NULL;
    Term* current = NULL;

    while (polynomial1 != NULL && polynomial2 != NULL) {
        if (polynomial1->exponent > polynomial2->exponent) {
            insertTerm(&result, polynomial1->coefficient, polynomial1->exponent);
            polynomial1 = polynomial1->next;
        } else if (polynomial1->exponent < polynomial2->exponent) {
            insertTerm(&result, polynomial2->coefficient, polynomial2->exponent);
            polynomial2 = polynomial2->next;
        } else {
            int sum = polynomial1->coefficient + polynomial2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, polynomial1->exponent);
            }
            polynomial1 = polynomial1->next;
            polynomial2 = polynomial2->next;
        }
    }

    while (polynomial1 != NULL) {
        insertTerm(&result, polynomial1->coefficient, polynomial1->exponent);
        polynomial1 = polynomial1->next;
    }

    while (polynomial2 != NULL) {
        insertTerm(&result, polynomial2->coefficient, polynomial2->exponent);
        polynomial2 = polynomial2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Term* polynomial) {
    if (polynomial == NULL) {
        printf("0");
    } else {
        while (polynomial != NULL) {
            printf("%dX^%d", polynomial->coefficient, polynomial->exponent);
            polynomial = polynomial->next;
            if (polynomial != NULL) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

// Function to free memory occupied by a polynomial
void freePolynomial(Term* polynomial) {
    Term* current = polynomial;
    while (current != NULL) {
        Term* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Term* polynomial1 = NULL;
    Term* polynomial2 = NULL;

    int numTerms1, numTerms2;
    int coefficient, exponent;

    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &numTerms1);

    printf("Enter the terms of Polynomial 1:\n");
    for (int i = 0; i < numTerms1; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &coefficient);
        printf("Exponent: ");
        scanf("%d", &exponent);
        insertTerm(&polynomial1, coefficient, exponent);
    }

    printf("\nEnter the number of terms in Polynomial 2: ");
    scanf("%d", &numTerms2);

    printf("Enter the terms of Polynomial 2:\n");
    for (int i = 0; i < numTerms2; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &coefficient);
        printf("Exponent: ");
        scanf("%d", &exponent);
        insertTerm(&polynomial2, coefficient, exponent);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(polynomial1);

    printf("Polynomial 2: ");
    displayPolynomial(polynomial2);

    Term* result = addPolynomials(polynomial1, polynomial2);

    printf("Addition Result: ");
    displayPolynomial(result);

    // Free memory occupied by polynomials
    freePolynomial(polynomial1);
    freePolynomial(polynomial2);
    freePolynomial(result);

    return 0;
}
