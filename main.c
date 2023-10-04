#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the beginning of the linked list
void addToBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to delete a node by its value
void deleteNodeByValue(struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *head = current->next; // Update the head if the node to delete is the first node
            } else {
                prev->next = current->next; // Link the previous node to the next node
            }
            free(current); // Free the memory of the deleted node
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Value %d not found in the list\n", value);
}

int main() {
    struct Node* head = NULL;

    // Adding nodes at the beginning
    addToBeginning(&head, 3);
    addToBeginning(&head, 5);
    addToBeginning(&head, 7);

    // Displaying the initial linked list
    displayList(head);

    // Deleting a node by its value
    deleteNodeByValue(&head, 5);

    // Displaying the updated linked list
    displayList(head);

    return 0;
}

