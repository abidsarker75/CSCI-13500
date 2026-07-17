#include "linkedlist.hpp"
#include <iostream>

int main() {
    LinkedList first_List;

    first_List.InsertNode(10);
    first_List.InsertNode(20);
    first_List.InsertNodeFront(5);
    first_List.InsertNodeAt(15, 3);

    std::cout << "First list: ";
    first_List.PrintValues();

    std::cout << "Size: " << first_List.GetSize() << std::endl;

    std::cout << "Contains 20: " << first_List.Contains(20) << std::endl;

    std::cout << "Value at position 3: " << first_List.GetValueAtPosition(3) << std::endl;

    first_List.Remove(2);

    std::cout << "After removing position 2: ";
    first_List.PrintValues();

    LinkedList second_List;

    second_List.InsertNode(100);
    second_List.InsertNode(200);
    second_List.InsertNode(300);

    LinkedList* merged_List = first_List.MergeIntertwine(second_List);

    std::cout << "Merged list: ";
    merged_List->PrintValues();

    delete merged_List;
    merged_List = nullptr;

    LinkedList* reversed_List = first_List.ReverseList();

    std::cout << "Reversed list: ";
    reversed_List->PrintValues();

    std::cout << "Original list: ";
    first_List.PrintValues();

    delete reversed_List;
    reversed_List = nullptr;

    return 0;
}