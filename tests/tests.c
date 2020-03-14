// test for linked lists
#include "mclinkedlisttests.h"
#include "mcdoublylinkedlisttests.h"
#include "mcstacktests.h"
#include "mcqueuetests.h"
#include "mcvectortests.h"
#include "testscommon.h"

void runTests()
{
    mcSinglyLinkedListTests();
    mcDoublyLinkedListTests();
    mcStackTests();
    mcQueueTests();
    mcVectorTests();
}

int main()
{
    printf("starting tests...\n");
    runTests();
    printf("...done running tests!\n");
    return 0;
}