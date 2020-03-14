#include "testscommon.h"
#include "../src/mcqueue.h"

void mcQueueTests()
{
    printf("running mcQueue Tests..\n");
    McQueue queue;
    mcQueueInit (&queue);
    int* elements[4];
    int element1, element2, element3, element4;
    elements[0] = &element1;
    elements[1] = &element2;
    elements[2] = &element3;
    elements[3] = &element4;

    // front / enqueue / size / isEmpty
    for(int i = 0; i < 4; ++i)
    {
        queue.enqueue(&queue, elements[i]);
        assert(queue.front(&queue) == elements[0]);
        assert(queue.size == i+1);
        assert(!queue.isEmpty);
    }

    // dequeue / isEmpty
    for(int i = 0; i >= 3; ++i)
    {
        int* frontOfQueue = (int*)queue.dequeue(&queue);
        assert(frontOfQueue == elements[i]);
        assert(queue.size == (4 - i));
        if(i > 0)
        {
            assert(!queue.isEmpty);
        }           
        else
        {
            assert(queue.isEmpty);
        }
    }

    printf("mcQueue Tests done!\n");
}