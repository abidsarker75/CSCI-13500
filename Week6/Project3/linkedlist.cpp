#include "linkedlist.hpp"
#include <iostream>
#include <stdexcept> // This will let us throw an error for an invalid position

// This will start an empty linked list
LinkedList::LinkedList() {
    size_ = 0;
    head_ = nullptr;
}

// This will add a new node at the end
void LinkedList::InsertNode(const int value) {
    Node* new_Node = new Node(value);

    // Will checks if the list is empty
    if (head_ == nullptr) {
        head_ = new_Node;
        size_++;
        return;
    }

    Node* current = head_;

    // Moves through to the last node.
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new_Node;
    size_++;
}

// Adds a new node at the front
void LinkedList::InsertNodeFront(const int value) {
    Node* new_Node = new Node(value);

    new_Node->next = head_;
    head_ = new_Node;

    size_++;
}

// Checks if the value is in the list
bool LinkedList::Contains(const int value) const {
    Node* current = head_;

    // Moves through every node in the list
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }

        current = current->next;
    }

    return false;
}

// Will remove a node at the given position
bool LinkedList::Remove(const int position) {
    // Checks if the position is not valid
    if (position < 1 || position > size_) {
        return false;
    }

    // Removes the first node in the list
    if (position == 1) {
        Node* removed_Node = head_;

        head_ = head_->next;

        delete removed_Node;
        removed_Node = nullptr;

        size_--;

        return true;
    }

    Node* current = head_;

    // Moves to the node right before removal
    for (int current_Position = 1; current_Position < position - 1; current_Position++) {
        current = current->next;
    }

    Node* removed_Node = current->next;
    current->next = removed_Node->next;
    delete removed_Node;
    removed_Node = nullptr;
    size_--;

    return true;
}

// Prints every value inside the linked list
void LinkedList::PrintValues() const {
    Node* current = head_;

    // Moves through and prints every node
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Prints each node position and its address
void LinkedList::PrintAddresses() const {
    Node* current = head_;
    int position = 1;

    // Moves through and prints every address
    while (current != nullptr) {
        std::cout << position << ": " << current << std::endl;
        current = current->next;
        position++;
    }
}

// Gets the value at the given position
int LinkedList::GetValueAtPosition(
    const int position) const {
    // Checks if the position is not valid
    if (position < 1 || position > size_) {
        throw std::out_of_range("Invalid position");
    }

    Node* current = head_;

    // Moves to the position the user entered
    for (int current_Position = 1;
         current_Position < position;
         current_Position++) {
        current = current->next;
    }

    return current->value;
}

// Reverses the order of the linked list
LinkedList* LinkedList::ReverseList() {
    Node* previous = nullptr;
    Node* current = head_;

    // Changes where each node points next
    while (current != nullptr) {
        Node* next_Node = current->next;
        current->next = previous;
        previous = current;
        current = next_Node;
    }

    LinkedList* reversed_List = new LinkedList;
    reversed_List->head_ = previous;
    reversed_List->size_ = size_;

    // Makes the old list completely empty
    head_ = nullptr;
    size_ = 0;

    return reversed_List;
}

// Adds a new node at a position
void LinkedList::InsertNodeAt(
    const int value,
    const int position) {
    // Checks if the position is not valid
    if (position < 1 || position > size_ + 1) {
        throw std::out_of_range("Invalid position");
    }

    // Adds the node at the beginning
    if (position == 1) {
        InsertNodeFront(value);
        return;
    }

    Node* current = head_;

    // Moves to the node before insertion
    for (int current_Position = 1;
         current_Position < position - 1;
         current_Position++) {
        current = current->next;
    }

    Node* new_Node = new Node(value);

    new_Node->next = current->next;
    current->next = new_Node;

    size_++;
}

// Gives back the current list size
int LinkedList::GetSize() const {
    return size_;
}

// Combines both lists by switching between them
LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const {
    LinkedList* merged_List = new LinkedList;

    Node* first_Current = head_;
    Node* second_Current = second_list.head_;

    // Keeps going until both lists are finished
    while (first_Current != nullptr ||
           second_Current != nullptr) {
        if (first_Current != nullptr) {
            merged_List->InsertNode(first_Current->value);

            first_Current = first_Current->next;
        }

        if (second_Current != nullptr) {
            merged_List->InsertNode(second_Current->value);

            second_Current = second_Current->next;
        }
    }
    return merged_List;
}

// Deletes every node still in the list
LinkedList::~LinkedList() {
    Node* current = head_;

    // Moves through and deletes every node
    while (current != nullptr) {
        Node* next_Node = current->next;

        delete current;
        current = nullptr;

        current = next_Node;
    }

    head_ = nullptr;
    size_ = 0;
}