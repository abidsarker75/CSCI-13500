# LinkedList DesignDoc

## Program Name

Linked List

## Purpose

This program makes a linked list that stores integer values. It can add nodes, remove nodes, search for values, print the list, reverse the list, and merge two lists together.

---

## Inputs

- Integer values for new nodes
- A position to insert a node
- A position to remove a node
- A value to search for
- A second linked list to merge

---

## Outputs

- The values inside the linked list
- The addresses of the nodes
- Whether a value is found
- The value at a certain position
- The size of the linked list
- A reversed linked list
- A merged linked list
- An error for an invalid position

---

## Variables

| Variable         | Type         | Purpose                                  |
| ---------------- | ------------ | ---------------------------------------- |
| value            | int          | Stores the number inside a node          |
| next             | Node\*       | Stores the address of the next node      |
| size\_           | int          | Stores how many nodes are in the list    |
| head\_           | Node\*       | Stores the address of the first node     |
| new_Node         | Node\*       | Stores the address of a new node         |
| current          | Node\*       | Moves through the linked list            |
| removed_Node     | Node\*       | Stores the node that will be removed     |
| next_Node        | Node\*       | Stores the next node for a short time    |
| previous         | Node\*       | Stores the previous node while reversing |
| position         | int          | Stores the node position                 |
| current_Position | int          | Keeps track of the current position      |
| reversed_List    | LinkedList\* | Stores the reversed linked list          |
| merged_List      | LinkedList\* | Stores the merged linked list            |
| first_Current    | Node\*       | Moves through the first linked list      |
| second_Current   | Node\*       | Moves through the second linked list     |

## Key Design Choices

- I used a Node struct because every node needs a number and the address of the next node.
- I used a LinkedList class because it keeps all the list variables and functions together.
- I used pointers because each node needs to point to the next node in the list.
- I used new because the program needs to make new nodes while the program is running.
- I used delete because the program needs to clean up nodes that are no longer needed.
- I used loops because the program must move through the nodes one at a time.
- I used std::out_of_range so the program stops safely when a position is not valid.

---

## Program Steps (Algorithm)

1. Make a new empty linked list.
2. Set the first node pointer to nullptr.
3. Set the list size to zero.
4. Make a new node when adding a value.
5. Connect the new node to the correct place.
6. Move through the nodes using a pointer.
7. Search for values when needed.
8. Print the values or addresses when needed.
9. Remove and delete nodes when needed.
10. Check that positions are valid before using them.
11. Reverse the pointers when reversing the list.
12. Switch between both lists when merging them.
13. Delete all remaining nodes when the list is finished.

---

## Functions

### Function: LinkedList()

Purpose: Makes a new linked list that starts empty.

### Function: InsertNode()

Purpose: Adds a new node to the end of the list.

### Function: InsertNodeFront()

Purpose: Adds a new node to the beginning of the list.

### Function: Contains()

Purpose: Checks if a certain value is inside the list.

### Function: Remove()

Purpose: Removes a node from a certain position in the list.

### Function: PrintValues()

Purpose: Prints every value stored inside the linked list.

### Function: PrintAddresses()

Purpose: Prints the position and address of every node.

### Function: GetValueAtPosition()

Purpose: Returns the value stored at a certain position.

### Function: ReverseList()

Purpose: Reverses the order of all nodes in the list.

### Function: InsertNodeAt()

Purpose: Adds a new node at a certain list position.

### Function: GetSize()

Purpose: Returns the number of nodes currently in the list.

### Function: MergeIntertwine()

Purpose: Combines two lists by switching between their stored values.

### Function: `~LinkedList()

Purpose: Deletes every remaining node when the list is finished.

---

## Sample Input/Output

### Input:

InsertNode(10)
InsertNode(20)
InsertNodeFront(5)
InsertNodeAt(15, 3)

### Output:

First list: 5 -> 10 -> 15 -> 20 -> nullptr
Size: 4
Contains 20: 1
Value at position 3: 15

## Ai reflection:

I did use ai and I used chatgbt for this program. This program was very difficult as this was my
first real linked list assignment. I was struggling with how we were traversing through the nodes
and how we would reverse it. Chatgbt helped guide me through the steps and explained how this would work.
It desribed it as a snake with a head and a tail and how we are starting from the head and then going to
the tail until it is a null pointer. We are just pointing to the next node until there is nothing.
