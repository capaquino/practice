#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>

/* Write a function to delete a node in a singly linked list (except
the tail), given access only to that node. */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(ListNode* n) : val(n->val), next(n->next) {}
};

class List
{
private:
    ListNode* pHead;
    ListNode* pTail;

public:
    List()
    {
        pHead = new ListNode(4);
        ListNode* pFirst = new ListNode(5);
        ListNode* pSecond = new ListNode(1);
        pTail = new ListNode(9);

        pHead->next = pFirst;
        pFirst->next = pSecond;
        pSecond->next = pTail; // pTail->next already points to null
    }

    void printLinkedList()
    {
        ListNode* ptr = pHead;
        std::cout << "\n";
        while (ptr != NULL)
        {
            std::cout << ptr->val << " -> ";
            ptr = ptr->next;
        }
        std::cout << "NULL, size: " << size() << std::endl;
    } // ptr goes out of scope and is destroyed here.

    int size()
    {
        int s;
        ListNode* ptr = pHead;
        while (ptr->next != NULL)
        {
            s++;
            ptr = ptr->next;
        }
        return s;
    }

    // Cannot delete head or tail with this as is.
    void deleteNodeAt(int position)
    {
        ListNode* ptr = pHead;
        int count = 0;
        while (count != position-1)
        {
            ptr = ptr->next;
            count++;
        } // after the loop, ptr points to the node before target

        // need a temporary pointer to keep track of the target
        // node, which is ptr->next.
        ListNode* temp = ptr->next;

        // point the node before the target to the one after the target.
        ptr->next = ptr->next->next;

        // delete the target node.
        delete temp;

    } // ptr and temp go out of scope and are destroyed here.

    void deleteHead()
    {
        ListNode* ptr = pHead; // difference w/? --> ListNode* ptr = new ListNode(pHead);
        pHead = pHead->next;
        delete ptr; // the data that ptr points to is deleted.

    } // ptr goes out of scope and is destroyed here.

    void deleteTail()
    {
        ListNode* ptr = pHead;
        while (ptr->next != pTail)
        {
            ptr = ptr->next;
        }
        ptr->next = NULL;
        delete pTail; // the data that pTail points to is deleted, not
        // pTail itself. So now you point the tail to the new logical tail.
        pTail = ptr;
    } // ptr goes out of scope and is destroyed here.
};



int main()
{
    /* Test case and answer generation */

    /* Invoke the solution */

    List s;
    s.printLinkedList();

    s.deleteNodeAt(2);
    s.printLinkedList();

    s.deleteNodeAt(1);
    s.printLinkedList();

    //s.deleteHead();
    //s.printLinkedList();

    s.deleteTail();
    s.printLinkedList();

    /* Check solution */



    return 0;
}
