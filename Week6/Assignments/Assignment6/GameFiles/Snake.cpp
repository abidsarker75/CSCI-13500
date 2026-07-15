#include "Snake.h"
#include <iostream>

// TODO: Constructor
// - Build a snake with STARTING_LENGTH segments using `new`.
// - head should point to segment id 0 (or 1, your choice - just be consistent),
//   tail should point to the last segment created.
// - Set length and nextId appropriately.
Snake::Snake() {
    head_ = nullptr;
    tail_ = nullptr;
    length_ = 0;
    id_ = 0;

    // TODO: allocate STARTING_LENGTH nodes and link them together

    // Creates STARTING_LENGTH body parts for the snake.
    for (int i = 0; i < STARTING_LENGTH; i++) {
        Node* newNode = new Node;
        newNode->body_part_ = id_;
        newNode->next_ = nullptr;
        id_++;

        // If the snake is empty then the new node is both the head and tail
        if (head_ == nullptr) {
            head_ = newNode;
            tail_ = newNode;
        } else {
            // Link the new node to the end of the snake.
            tail_->next_ = newNode;
            tail_ = newNode;
        }

        length_++;
    }
}

// TODO: Destructor
// - Walk the list and delete every remaining node.
// - If you don't do this, running under valgrind/ASan will report a leak.
Snake::~Snake() {
    // Will delete nodes from the front until snake is empty.
    while (head_ != nullptr) {
        Node* oldHead = head_;
        head_ = head_->next_;
        delete oldHead;
    }

    // THis will reset the snake after deleting everything
    tail_ = nullptr;
    length_ = 0;
}

// TODO: kill()
// - Remove up to `count` nodes from the FRONT of the list, deleting each one.
// - Handle the edge case where the snake has fewer than `count` nodes left:
//   kill all remaining nodes and stop. Do not crash.
// - Update `length` (and `tail`/`head` if the snake becomes empty!).
// - Return the number of segments ACTUALLY killed.
int Snake::Kill(int count) {
    int killedCount = 0;

    // Will remove nodes from the front while count is not 0.
    while (count > 0 && head_ != nullptr) {
        Node* oldHead = head_;
        head_ = head_->next_;
        delete oldHead;

        length_--;
        killedCount++;
        count--;
    }

    // If all nodes are deleted the tail should also be a nullptr.
    if (head_ == nullptr) {
        tail_ = nullptr;
    }
    return killedCount;
}

// TODO: regenerate()
// - Append `count` new nodes to the BACK of the list using `new`.
// - Use `nextId` to assign each new node a unique, increasing id, and
//   increment `nextId` each time.
// - Update `tail` (and `head` if the snake was empty!) and `length`.
void Snake::Regenerate(int count) {
    // Add new body parts to the back of the snake.
    for (int i = 0; i < count; i++) {
        Node* newNode = new Node;
        newNode->body_part_ = id_;
        newNode->next_ = nullptr;
        id_++;

        // If the snake is empty, the new node becomes both head and tail.
        if (head_ == nullptr) {
            head_ = newNode;
            tail_ = newNode;
        } else {
            // Attach the new node after the current tail.
            tail_->next_ = newNode;
            tail_ = newNode;
        }

        length_++;
    }
}

// TODO: print()
// - Walk the list from head to tail and print in the format:
//   Snake: [12] -> [13] -> [14] -> [15]
// - If the snake is empty, print something sensible like "Snake: (dead)".
// - This function must not modify the snake - use a `const Node*` to walk it.
void Snake::PrintSnake() const {
    // If the snake has no head, then there are no body parts left.
    if (head_ == nullptr) {
        std::cout << "Snake: (dead)" << std::endl;
        return;
    }

    std::cout << "Snake: ";

    // Use const Node* because this function should not change the snake.
    const Node* current = head_;

    // Walks through the linked list from head to tail.
    while (current != nullptr) {
        std::cout << "[" << current->body_part_ << "]";

        if (current->next_ != nullptr) {
            std::cout << " -> ";
        }
        current = current->next_;
    }
    std::cout << std::endl;
}

int Snake::GetLength() const {
    // Returns the number of snake body parts.
    return length_;
}