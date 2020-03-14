#include "testscommon.h"
#include "../src/mcdoublylinkedlist.h"

void mcDoublyLinkedListTests()
{
    printf("running mcDoublyLinkedList Tests..\n");
    McDoublyLinkedListElement elements[4];
    McDoublyLinkedList dLL;
    mcDoublyLinkedListInit(&dLL);

    // append / find
    dLL.append(&dLL, &elements[0]);
    assert(dLL.find(&dLL, 0) == &elements[0]);    
    dLL.append(&dLL, &elements[1]);
    assert(dLL.find(&dLL, 1) == &elements[1]);

    // first / last / size
    assert(dLL.first == &elements[0]);
    assert(dLL.last == &elements[1]);
    assert(dLL.size == 2);

    // insertAfter / size
    dLL.insertAfter(&dLL, &elements[2], &elements[1]);
    assert(dLL.last == &elements[2]);
    assert(dLL.size == 3);

    // insertBefore / next
    dLL.insertBefore(&dLL, &elements[3], dLL.first);
    assert(dLL.first == &elements[3]);
    assert(dLL.first->next == &elements[0]);
    assert(dLL.size == 4);

    // erase
    for(int i = 0; i < 4; i++)
    {
        dLL.erase(&dLL, &elements[i]);
    }
    assert(dLL.size == 0);

    printf("mcDoublyLinkedList Tests done!\n");
}
