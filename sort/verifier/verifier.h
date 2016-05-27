#ifndef __VERIFIER_H__
#define __VERIFIER_H__

/* Element max count */
#define MAX_DIMENSION 1024
/* Max value of every element */
#define MAX_ELEMENT 1024
/* Max test case */
#define MAX_TEST_CASE 10*1024

int *FillArray();

void ReleaseArray(int *Array);

void CheckArrayElement(int Array[], const unsigned int size);

#endif

