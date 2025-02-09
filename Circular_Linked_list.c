//Circular linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * next;
    int data;
};

void traversal(struct node * head){
    struct node * p = head;
    do{
        printf("%d ", p -> data);
        p = p -> next;
    }
    while (p != head);
}

struct node * insertstart(struct node * head, int value){
    struct node * p = head -> next;
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = value;
    while(p -> next != head){
        p = p -> next;
    }
    ptr -> next = head;
    p -> next = ptr;
    head = ptr;
    return head;
}

struct node * insertindex(struct node * head, int value, int index){
    struct node * p = head;
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data= value;
    int i = 0;
    while(i != index){
        p = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;

}

struct node * insertend(struct node * head, int value){
    struct node * p = head;
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = value;
    while(p -> next != head){
        p = p -> next;
    }
    ptr -> next = head;
    p -> next = ptr;
    return head;
}

struct node *deletestart(struct node * head){
    struct node * p = head;
    struct node * ptr = head -> next;
    while( ptr -> next != head){
        ptr = ptr -> next;
    }
    head = head -> next;
    ptr -> next = head;
    int extract = p -> data;
    free(p);
    return head;
}

struct node * deleteindex(struct node * head, int index){
    struct node * p = head;
    struct node * ptr = head -> next;
    int i =0;
    while( i != index-1){
        ptr = ptr -> next;
        p = p -> next;
        i++;
    }
    p -> next = ptr -> next;
    int extract = ptr -> data;
    free(ptr);
    
}

struct node* deleteend(struct node * head){
    struct node * p = head;
    struct node * ptr = head -> next;
    while(ptr -> next != head){
        ptr = ptr -> next;
        p = p -> next;
    }
    p -> next = ptr -> next;
    int extract = ptr -> data;
    free(ptr);
    
}
int main() {
    int choice, value, index;
    struct node * head = (struct node*)malloc(sizeof(struct node));
    while(1) {
        printf("_MENU_ \n");
        printf("1. Insert at start. \n");
        printf("2. Insert at index \n");
        printf("3. Insert at end \n");
        printf("4. Delete at start \n");
        printf("5. Delete at index \n");
        printf("6. Delete at end \n");
        printf("7. Display \n");
        printf("8. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("Enter the value to insert:");
            scanf("%d", &value);
            head = insertstart(head, value);
            break;

            case 2:
            printf("Enter the value to insert:");
            scanf("%d", &value);
            printf("Enter Index: ");
            scanf("%d", &index);
            head = insertindex(head, value, index);
            break;

            case 3:
            printf("Enter the value to insert:");
            scanf("%d", &value);
            head = insertend(head, value);
            break;

            case 4:
            head = deletestart(head);
            break;

            case 5:
            printf("Enter Index: ");
            scanf("%d", &index);
            head = deleteindex(head, value);
            break;
            
            case 6:
            head = deleteend(head);
            break;

            case 7:
            traversal(head);
            break;

            case 8:
            printf("Exiting...");
            break;

            default:
            printf("Invalid choice.. \n");
        }

    }
}    