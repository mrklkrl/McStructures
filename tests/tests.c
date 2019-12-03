// test for linked lists
#include "../src/mclinkedlist.h"
#include <assert.h>
#include <stdio.h>

void mcSinglyLinkedListTests()
{
    printf("running mcSinglyLinkedList Tests..\n");
    McSinglyLinkedListElement elements[4];
    McSinglyLinkedList sLL;
    mcSinglyLinkedListInit(&sLL);

    // append / find
    sLL.append(&sLL, &elements[0]);
    assert(sLL.find(&sLL, 0) == &elements[0]);    
    sLL.append(&sLL, &elements[1]);
    assert(sLL.find(&sLL, 1) == &elements[1]);

    // first / last / size
    assert(sLL.first == &elements[0]);
    assert(sLL.last == &elements[1]);
    assert(sLL.size == 2);

    // insertAfter / size
    sLL.insertAfter(&sLL, &elements[2], &elements[1]);
    assert(sLL.last == &elements[2]);
    assert(sLL.size == 3);

    // insertBefore / next
    sLL.insertBefore(&sLL, &elements[3], sLL.first);
    assert(sLL.first == &elements[3]);
    assert(sLL.first->next == &elements[0]);
    assert(sLL.size == 4);

    // erase
    for(int i = 0; i < 4; i++)
    {
        sLL.erase(&sLL, &elements[i]);
    }
    assert(sLL.size == 0);

    printf("mcSinglyLinkedList Tests done!\n");
}

void runTests()
{
    mcSinglyLinkedListTests();
}

int main()
{
    printf("starting tests...\n");
    runTests();
    printf("...done running tests!\n");
    return 0;
}