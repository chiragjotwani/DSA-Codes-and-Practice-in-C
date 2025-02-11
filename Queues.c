#include <stdio.h>
#include <stdlib.h>

struct queue{
    int front;
    int back;
    int size;
    int *arr;
};

int isfull(struct queue * q){
    if(q -> back == q -> size -1){
        return 1;
    }
    return 0;
}

int isempty(struct queue * q){
    if(q -> front == q -> back){
        return -1;
    }
    return 0;
}

void enqueue(struct queue * q, int value){
    if(isfull(q)){
        printf("Queue is full");
    }
    else{
        q -> back++;
        q -> arr[q->back] = value;

    }
}

int dequeue(struct queue *q){
    if(isempty(q)){
        printf("Queue is empty");
        return -1;
    }
    else{
        int extract = q -> arr[ q-> front];
        q -> front++;
        return extract;
    }
}

void display(struct queue * q){
    for ( int i = q -> front + 1; i<=q -> back; i++ ){
        printf("%d ", q->arr[i]);
    }
}

int main(){
    struct queue * q = (struct queue*)malloc(sizeof(struct queue));
    q -> size = 5;
    q -> arr = (int*)malloc(sizeof(int));
    q -> front = q -> back = -1;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    display(q);
    return 0;
}