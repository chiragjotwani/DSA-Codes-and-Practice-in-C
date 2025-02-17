// #include<stdio.h>
// #include<stdlib.h>

// struct Queue{
//     int size;
//     int f;
//     int r;
//     int *arr;
// };

// int isFull(struct Queue *q){
//     if((q->r + 1) % q->size == q->f){
//         return 1;
//     }
//     return 0;
// }

// int isEmpty(struct Queue *q){
//     if(q -> r == q -> f){
//         return 1;
//     }
//     return 0;
// }

// void enqueue(struct Queue *q, int val){
//     if(isFull(q)){
//         printf("Queue Overflow\n");
//     }
//     else{
//         q -> r = (q -> r + 1) % q -> size;
//         q -> arr[q -> r] = val;
//     }
// }
 
// int dequeue(struct Queue *q){
//     int a = -1;
//     if(isEmpty(q)){       
//         printf("No element to dequeue\n");
//     }
//     else{
//         q -> f = (q -> f + 1) % q -> size;
//         a = q -> arr[q -> f];
//     } 
//     return a;
// }

// int main(){
//     struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));;
//     q -> size = 10;
//     q -> f = q -> r = 0;
//     q -> arr = (int *)malloc(q -> size * sizeof(int));

//     if(isEmpty(q)){
//         printf("Queue is empty\n");
//     }

//     if(isFull(q)){
//         printf("Queue is full\n");
//     }

//     enqueue(q, 12);
//     enqueue(q, 15);
//     enqueue(q, 23);
//     enqueue(q, 25);

//     if(isEmpty(q)){
//         printf("Queue is empty\n");
//     }

//     if(isFull(q)){
//         printf("Queue is full\n");
//     }


//     printf("%d\n", dequeue(q));

//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    int data;
};

struct queue{
    struct node *f;
    struct node *r;
};

struct node *createNode(int data){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n -> data = data;
    n -> next = NULL;
    return n;
}

struct queue *createqueue(){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q -> f = q -> r = NULL;
    return q;
}

int isEmpty(struct queue *q){
    return(q -> f == NULL);
}

int isFull(struct queue *q){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int data){
    struct node *n = createNode(data);
    if(q -> r == NULL){
        q -> f = q -> r = n;
        printf("Enqueued:%d\n", data);
        return;
    }
    q -> r -> next = n;
    q -> r = n;
    printf("Enqueued: %d\n", data);

}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue empty");
        return -1;
    }
    struct node *temp = q -> f;
    int data = temp -> data;
    q -> f = q -> f -> next;
    if(q -> f == NULL)
        q -> r =NULL;
    free(temp);
    printf("Dequeued: %d\n", data);
    return data;
}

void display(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return;
    }
    struct node *temp = q -> f;
    printf("Queue contents: ");
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    int choice, val;
    struct queue *q = createqueue();
    while (1)
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(q, val);
            break;

            case 2:
            dequeue(q);
            break;

            case 3:
            display(q);
            break;

            case 4:
            printf("Exit..");
            return 0;

            default:
            printf("Invalid choice");
        }

    }
    
}