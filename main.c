#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct s_node {
    int data;
    struct s_node *next;
} t_node;

// Function to find the position of a node with specific data
int find_position(t_node *head, int target_data) {
    int position = 0; // Initialize position (0-based indexing)
    t_node *current = head;

    while (current != NULL) {
        if (current->data == target_data) {
            return position; // Return position if the node is found
        }
        current = current->next;
        position++;
    }

    return -1; // Return -1 if the node is not found
}

// Helper function to create a new node
t_node *create_node(int data) {
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Helper function to print the linked list
void print_list(t_node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate
int main() {
    // Create a linked list: 10 -> 20 -> 30 -> 40 -> NULL
    t_node *head = create_node(10);
    head->next = create_node(20);
    head->next->next = create_node(30);
    head->next->next->next = create_node(40);

    printf("Linked list: ");
    print_list(head);

    // Find the position of node with data 30
    int target_data = 30;
    int position = find_position(head, target_data);

    if (position != -1)
        printf("The position of node with data %d is: %d\n", target_data, position);
    else
        printf("Node with data %d not found.\n", target_data);

    return 0;
}
