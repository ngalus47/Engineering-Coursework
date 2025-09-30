#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    int *items;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;

void initQueue(Queue *q, int capacity);
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int front(Queue *q);
int rear(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void freeQueue(Queue *q);

#endif // QUEUE_H
