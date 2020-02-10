// test for linked lists
#include "../src/mclinkedlist.h"
#include "../src/mcdoublylinkedlist.h"
#include "../src/mcstack.h"
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

void mcStackTests()
{
    printf("running mcStack Tests..\n");
    McStack stack;
    mcStackInit (&stack);
    McSinglyLinkedListElement* elements[4];
    McSinglyLinkedListElement element1, element2, element3, element4;
    elements[0] = &element1;
    elements[1] = &element2;
    elements[2] = &element3;
    elements[3] = &element4;

    // top / push / size / isEmpty
    for(int i = 0; i < 4; ++i)
    {
        stack.push(&stack, elements[i]);
        assert(stack.top(&stack) == elements[i]);
        assert(stack.size == i+1);
        assert(!stack.isEmpty);
    }
    // pop / isEmpty
    for(int i = 3; i >= 0; --i)
    {
        McSinglyLinkedListElement* topOfStack = (McSinglyLinkedListElement*)stack.pop(&stack);
        assert(topOfStack == elements[i]);
        assert(stack.size == i);
        if(i > 0)
        {
            assert(!stack.isEmpty);
        }           
        else
        {
            assert(stack.isEmpty);
        }
    }

    printf("mcStack Tests done!\n");
}

void runTests()
{
    mcSinglyLinkedListTests();
    mcDoublyLinkedListTests();
    mcStackTests();
}

int main()
{
    printf("starting tests...\n");
    runTests();
    printf("...done running tests!\n");
    return 0;
}