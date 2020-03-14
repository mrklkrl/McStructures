#include "testscommon.h"
#include "../src/mcstack.h"

void mcStackTests()
{
    printf("running mcStack Tests..\n");
    McStack stack;
    mcStackInit (&stack);
    int* elements[4];
    int element1, element2, element3, element4;
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
        int* topOfStack = (int*)stack.pop(&stack);
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