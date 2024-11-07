#include <pthread.h>
//#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // for sleep function

pthread_mutex_t x, wsem; // x is for reader count, wsem is for mutual exclusion
pthread_t tid;
int readcount;

void initialize() {
    pthread_mutex_init(&x, NULL);
    pthread_mutex_init(&wsem, NULL);
    readcount = 0;
}

void *reader(void *param) {
    int waittime = rand() % 5;

    printf("\nReader is trying to enter");
    pthread_mutex_lock(&x);
    readcount++;

    if (readcount == 1) {
        pthread_mutex_lock(&wsem);
    }

    printf("\n%d reader(s) inside", readcount);
    pthread_mutex_unlock(&x);

    sleep(waittime);

    pthread_mutex_lock(&x);
    readcount--;

    if (readcount == 0) {
        pthread_mutex_unlock(&wsem);
    }

    pthread_mutex_unlock(&x);
    printf("\nReader is leaving");

    return NULL;
}

void *writer(void *param) {
    int waittime = rand() % 3;

    printf("\nWriter is trying to enter");
    pthread_mutex_lock(&wsem);
    printf("\nWriter has entered");

    sleep(waittime);

    pthread_mutex_unlock(&wsem);
    printf("\nWriter is leaving");

    return NULL;
}

int main() {
    int n1, n2, i;

    printf("\nEnter the number of readers: ");
    scanf("%d", &n1);
    printf("\nEnter the number of writers: ");
    scanf("%d", &n2);

    initialize();

    for (i = 0; i < n1; i++) {
        pthread_create(&tid, NULL, reader, NULL);
    }

    for (i = 0; i < n2; i++) {
        pthread_create(&tid, NULL, writer, NULL);
    }

    sleep(30);
    return 0;
}
