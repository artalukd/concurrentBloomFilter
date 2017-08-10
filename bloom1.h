#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#define NUM_OF_HASH 7
#define BLOOM_SIZE 19997


struct sharedData{
    struct Bloom* b;
    int threadid;
};

struct hashData{
    int tid;
    int x;
    struct Bloom* bloom;
    int* arr;
};

struct Bloom{
    int size;
    int bit[BLOOM_SIZE];
    pthread_mutex_t mutexArr[BLOOM_SIZE];
};


void *bloomThread(void *threadid );
void *hashCalculate(void *x );
void sortHashes(int a[]);
void insertHash(int a[], struct Bloom* b);
int findHash( int a[], struct Bloom* b);
void getLocks(int a[], struct Bloom* b);
