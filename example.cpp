#include <iostream>
using namespace std;

// Define the structure for the linked list node
struct node {
    int data;           // The data stored in the node
    node* next;         // A pointer to the next node in the list
};

node* head = nullptr;    // Initialize the head of the list as a nullptr

// Function to insert a new node at the beginning of the list
void at_beginning(int data) {
    node* newnode = new node; // Create a new node
    newnode->data = data;     // Set the new node's data
    newnode->next = nullptr;  // Set the new node's next pointer to nullptr

    // Insert the new node at the beginning of the list
    if (head == nullptr) {
        head = newnode;       // If the list is empty, set the head to the new node
    }
    else {
        newnode->next = head; // Set the new node's next pointer to the current head
        head = newnode;       // Update the head of the list to the new node
    }
}

// Function to insert a new node at the end of the list
void at_end(int data) {
    node* newnode = new node; // Create a new node
    newnode->data = data;     // Set the new node's data
    newnode->next = nullptr;  // Set the new node's next pointer to nullptr

    // Insert the new node at the end of the list
    if (head == nullptr) {
        head = newnode;       // If the list is empty, set the head to the new node
    }
    else {
        node* current = head; // Initialize a pointer to traverse the list

        // Traverse the list to find the last node
        while (current->next != nullptr) {
            current = current->next;
        }

        // Set the last node's next pointer to the new node
        current->next = newnode;
    }
}

// Function to insert a new node at a specified position in the list
void insert(int data, int pos) {
    node* newnode = new node; // Create a new node
    newnode->data = data;     // Set the new node's data

    // Insert the new node at the specified position
    if (pos == 0) {
        newnode->next = head; // Set the new node's next pointer to the current head
        head = newnode;       // Update the head of the list to the new node
    }
    else {
        node* current = head; // Initialize a pointer to traverse the list

        // Traverse the list until the desired position is reached or the end of the list
        for (int i = 1; i < pos && current != nullptr; i++) {
            current = current->next;
        }

        // Check if the position is valid
        if (current == nullptr) {
            cout << "invalid pos" << endl;
            delete newnode;    // If not, delete the new node and return
            return;
        }

        // Insert the new node after the current node
        newnode->next = current->next;
        current->next = newnode;
    }
}

int main() {
    // Perform various insert operations on the list
    at_beginning(3);
    at_end(4);
    insert(2, 0);
    insert(1, 0);
    insert(5, 4);

    // Display the final state of the linked list
    node* current = head;
    while (current->next != nullptr) {
      cout << current->data;
      current = current->next;
    }
}
