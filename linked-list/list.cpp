#include "list.hpp"
#include <iostream>

List::List() : pHead(NULL), pTail(NULL) {}

// Good
void List::insert(int value)
{
    // Case 1: List is empty.
    if (pHead == NULL)
    {
        pHead = new ListNode(value);
        pTail = pHead;
    }

    // Otherwise, traverse the list.
    else
    {
        // prev: node that will be before new node.
        // ptr: node to have new node inserted before.
        // newNode: the new node

        ListNode* ptr = pHead;
        ListNode* prev = NULL;
        while (ptr != NULL && ptr->val <= value)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        // Create the node to be inserted, could do this in each case.
        ListNode* newNode = new ListNode(value);

        if (ptr) // node gets prepended or put somewhere within.
        {

            // Case 2: Node needs to be prepended.
            if (ptr == pHead)
            {
                pHead = newNode;
                pHead->next = ptr;
            }

            // Case 3: Node goes somewhere inbetween
            else
            {
                newNode->next = ptr;
                prev->next = newNode;
            }
        }
        // Case 4: Node gets appended.
        else
        {
            newNode->next = NULL;
            prev->next = newNode;
            pTail = newNode;
        }
    }
}

// Good
void List::remove(int value)
{
    // Case 1: List is empty, nothing to remove.
    if (pHead == NULL) return;

    // Case 2: The node to be removed is the head
    if (pHead->val == value)
    {
        ListNode* oldHead = pHead;
        pHead = pHead->next; // If this is the last node,
        // pHead->next already points to NULL.

        // If this is the last node left, the head is also
        // the tail, and so we should also set pTail to NULL.
        if (pTail == oldHead)
            pTail = pHead; // equivalent to "pTail = NULL"

        // Finally, delete the old head.
        delete oldHead;
    }

    // Case 3: The node to be removed is not the head.
    else
    {
        // Traverse the list
        ListNode* ptr = pHead;
        ListNode* prev = NULL;
        while (ptr != NULL && ptr->val != value)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr) // assuming we aren't pointing to null
        {
            prev->next = ptr->next;
            delete ptr;

            // check tail
            if (prev->next == NULL)
            {
                pTail = prev;
            }
        }
    }
}

// Good
void List::print()
{
    ListNode* ptr = pHead;
    while (ptr != NULL)
    {
        std::cout << ptr->val;
        if (ptr == pHead) std::cout << "H";
        if (ptr == pTail) std::cout << "T";
        std::cout << " -> ";
        ptr = ptr->next;
    }
    std::cout << "NULL\n";
}

// Good
int List::size()
{
    int size = 0;
    ListNode* ptr = pHead;
    while (ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }
    return size;
}

// Good
void List::reverse()
{
    ListNode* prev = NULL;
    ListNode* curr = pHead;
    ListNode* next = NULL;

    pTail = pHead;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    pHead = prev;
}

// Good
void List::rotateCCW(int rotations)
{
    if (rotations <= 0 || rotations >= size()) return;

    ListNode* ptr = pHead;
    int count = 1;

    // ptr will end up being one node before the new head.
    while (count < rotations && ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    if (ptr)
    {
        // Connect old tail to new old head.
        pTail->next = pHead;

        // Set new head and new tail.
        pHead = ptr->next;
        ptr->next = NULL;
        pTail = ptr;
    }
}

void List::rotateCW(int rotations)
{
    // You also need to determine which node is the new tail
    // and set that to null. So stop #rotations# from old tail.

    // traverse to the end of the list since you need to
    // point the old tail to the front of the list.
}
