#include "list.hpp"

int main()
{
    /* Test case and answer generation */

    /* Invoke the solution */

    List s;
    s.print();
    s.insert(5);
    s.print();
    s.insert(4);
    s.print();
    s.insert(7);
    s.print();
    s.insert(6);
    s.print();
    s.insert(9);
    s.print();
    s.insert(10);
    s.print();
    s.rotateCCW(2);
    s.print();
    s.rotateCCW(1);
    s.print();

    s.remove(6);
    s.print();
    s.remove(5);
    s.print();
    s.remove(9);
    s.print();
    s.remove(10);
    s.print();
    s.remove(7);
    s.print();
    s.remove(4);
    s.print();

    /* Check solution */

    return 0;
}
