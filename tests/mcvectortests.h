#include "testscommon.h"
#include "../src/mcvector.h"

void mcVectorTests()
{
    printf("running mcVector Tests..\n");
    int i;

    McVector v;
    mcVectorInit(&v);

    mcVectorAdd(&v, "Bonjour");
    mcVectorAdd(&v, "tout");
    mcVectorAdd(&v, "le");
    mcVectorAdd(&v, "monde");

    
    assert((char *) mcVectorGet(&v, 0) == "Bonjour");
    assert((char *) mcVectorGet(&v, 1) == "tout");
    assert((char *) mcVectorGet(&v, 2) == "le");
    assert((char *) mcVectorGet(&v, 3) == "monde");

    mcVectorDelete(&v, 3);
    assert(mcVectorTotal(&v) == 3);
    mcVectorDelete(&v, 2);
    assert(mcVectorTotal(&v) == 2);
    mcVectorDelete(&v, 1);
    assert(mcVectorTotal(&v) == 1);
    assert((char *) mcVectorGet(&v, 0) == "Bonjour");    
    
    mcVectorSet(&v, 0, "Hello");
    assert((char *) mcVectorGet(&v, 0) == "Hello");
    assert(mcVectorTotal(&v) == 1);
    mcVectorAdd(&v, "World");
    assert((char *) mcVectorGet(&v, 1) == "World");
    assert(mcVectorTotal(&v) == 2);

    mcVectorFree(&v);
    printf("mcVector Tests done!\n");
}