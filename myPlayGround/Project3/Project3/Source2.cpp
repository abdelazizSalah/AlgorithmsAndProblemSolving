#include <stdio.h>
#include <stdbool.h>


#define MAX_SIZE 10

struct Queue
{
    int data[MAX_SIZE];
    int front;
    int back;
    int itemCount;
};

struct Queue createQueue() {
    struct Queue queue = {
        queue.front = 0,
       queue.back = -1,
        queue.itemCount = 0
    };

    return queue;
}

int peekQueue(struct Queue queue) {
    return queue.data[queue.front];
}

bool isEmpty(struct Queue queue) {
    return queue.itemCount == 0;
}

bool isFull(struct Queue queue) {
    return queue.itemCount == MAX_SIZE;
}

int size(struct Queue queue) {
    return queue.itemCount;
}

void enqueue(struct Queue* queue, int data) {

    if (!isFull(*queue)) {

        if (queue->back == MAX_SIZE - 1) {
            queue->back = -1;
        }

        queue->data[++queue->back] = data;
        queue->itemCount++;
    }
    else {
        printf("----- Full Queue -----\n");
    }
}

int dequeue(struct Queue* queue) {

    if (!isEmpty(*queue)) {
        int data = queue->data[queue->front++];

        if (queue->front == MAX_SIZE) {
            queue->front = 0;
        }

        queue->itemCount--;
        return data;

    }
    else {
        printf("----- Empty Queue -----\n");
        return 0;
    }

}

void displayQueue(struct Queue queue) {

    if (queue.itemCount == 0) {
        printf("---- Empty Queue ----\n");
    }
    else {
        int count = 0;
        int i;
        for (i = 0; i < queue.itemCount; i++)
        {
            if (queue.front + i < MAX_SIZE) {
                printf("%d ", queue.data[queue.front + i]);
            }
            else {
                printf("%d ", queue.data[count++]);
            }

        }
        printf("\n");
    }
    printf("----------------------\n");
}

int main() {

    int l, y; 
    int arr[10] = {l= 3 ,y =4 }; 


    struct Queue q = createQueue();

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);



    displayQueue(q);
    dequeue(&q);
    int x = peekQueue(q);
    printf("%d\n", x);
    displayQueue(q);


}