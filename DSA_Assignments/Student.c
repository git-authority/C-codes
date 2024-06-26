#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int regNumber;
    int marks;
    char grade;
    struct Node* next;
} Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Enter student name: ");
    scanf("%s", newNode->name);
    printf("Enter registration number: ");
    scanf("%d", &(newNode->regNumber));
    printf("Enter marks: ");
    scanf("%d", &(newNode->marks));

    if (newNode->marks > 90)
        newNode->grade = 'E';
    else if (newNode->marks > 80)
        newNode->grade = 'A';
    else if (newNode->marks > 70)
        newNode->grade = 'B';
    else if (newNode->marks > 60)
        newNode->grade = 'C';
    else
        newNode->grade = 'F';

    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, Node* newNode) {
    if (*head == NULL || (*head)->marks >= newNode->marks) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->marks < newNode->marks) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    printf("Student List:\n");
    printf("Name\tRegistration Number\tMarks\tGrade\n");
    while (current != NULL) {
        printf("%s\t%d\t\t%d\t%c\n", current->name, current->regNumber, current->marks, current->grade);
        current = current->next;
    }
    printf("\n");
}

Node* searchByName(Node* head, char name[]) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteNode(Node** head, char name[]) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with name %s not found.\n", name);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student with name %s deleted successfully.\n", name);
}

void searchByGrade(Node* head, char grade) {
    Node* current = head;
    printf("Students with grade %c:\n", grade);
    printf("Name\tRegistration Number\tMarks\tGrade\n");
    while (current != NULL) {
        if (current->grade == grade) {
            printf("%s\t%d\t\t%d\t%c\n", current->name, current->regNumber, current->marks, current->grade);
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int i;

    for (i = 0; i < 4; i++) {
        Node* newNode = createNode();
        insertNode(&head, newNode);
    }

    displayList(head);

    char searchName[50];
    printf("Enter a student name to search: ");
    scanf("%s", searchName);
    Node* foundStudent = searchByName(head, searchName);
    if (foundStudent != NULL) {
        printf("Student found:\n");
        printf("Name\tRegistration Number\tMarks\tGrade\n");
        printf("%s\t%d\t\t%d\t%c\n", foundStudent->name, foundStudent->regNumber, foundStudent->marks, foundStudent->grade);
    } else {
        printf("Student not found.\n");
    }

    char deleteName[50];
    printf("Enter a student name to delete: ");
    scanf("%s", deleteName);
    deleteNode(&head, deleteName);
    displayList(head);

    char searchGrade;
    printf("Enter a grade to search students: ");
    scanf(" %c", &searchGrade);
    searchByGrade(head, searchGrade);

    return 0;
}
