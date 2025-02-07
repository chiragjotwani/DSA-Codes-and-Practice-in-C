//Singly Linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

void traversal(struct node* ptr){
    while(ptr!= NULL){
        printf("%d\n", ptr -> data);
        ptr= ptr-> next;
        
    }
}

struct node * insertstart( struct node *head, int data){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr ->next= head;
    ptr -> data= data;
    return ptr;
}

struct node * insertindex( struct node * head, int data, int index){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node * p = head;
    int i=0;
    while (i!=index-1){
        p= p-> next;
        i++;    
    }
    ptr -> data = data;
    ptr  -> next = p -> next;
    p -> next = ptr;
    return head;
}

struct node * insertend(struct node* head, int data){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    ptr -> data = data;
    
    
    while(p -> next!= NULL){
        p = p -> next;
    }
    ptr -> next = NULL;
    p -> next = ptr;
    return head;
}

struct node *deletefirst(struct node * head){
    struct node *ptr = head;
    head = head ->next;
    free(ptr);
    return head;
}

struct node * deleteindex(struct node * head, int index){
    int i=0;
    struct node *p= head;
    while(i!=index-1){
        p= p -> next;
        i++; 
    }
    struct node * ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}


int main(){
    struct node *head= (struct node *) malloc (sizeof(struct node));
    struct node *second= (struct node *) malloc (sizeof(struct node));
    struct node *third= (struct node *) malloc (sizeof(struct node));


    head -> data= 9;
    head -> next = second;

    second -> data = 32;
    second-> next = third;

    third -> data = 24;
    third -> next = NULL;

    traversal(head);
    // head= insertstart(head, 56);
    // head= insertindex(head, 56, 1);

    traversal(head);
    return 0;
}

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

// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     struct node * next;
//     int data;
// };

// void traversal(struct node * head){
//     struct node * ptr = head;
//     while(ptr!=NULL){
//         printf("%d ", ptr -> data);
//         ptr = ptr -> next;
//     }
// }

// struct node * insertatstart(struct node * head, int value){
//     struct node * ptr = (struct node*)malloc(sizeof(struct node));
//     ptr -> data = value;
//     ptr -> next = head;
//     head = ptr;
//     return head;
// }

// struct node * insertatend(struct node * head, int value){
//     struct node * p = head;
//     struct node * ptr = (struct node *)malloc(sizeof(struct node));
//     ptr -> data = value;
//     while(p -> next != NULL){
//         p = p -> next;
//     }
//     ptr -> next = NULL;
//     p -> next = ptr;
//     return head;
// }

// struct node * insertatindex(struct node* head, int value, int index){
//     struct node * p = head;
//     struct node * ptr = (struct node *)malloc(sizeof (struct node));
//     ptr -> data = value;
//     int i = 0;
//     while(i != index-1){
//         p = p -> next;
//         i++;
//     }
//     ptr -> next = p -> next;
//     p -> next = ptr;
//     return head;
// }

// struct node * deleteatstart (struct node * head){
//     struct node * ptr = head;
//     head = ptr -> next;
    
//     free(ptr);
//     return head;
// }

// struct node * deleteatend(struct node * head){
//     struct node * p = head;
//     struct node * ptr = head -> next;
//     while(ptr -> next != NULL){
//         p = p -> next;
//         ptr = ptr -> next;
//     }
//     p -> next = ptr -> next;
    
//     free(ptr);
//     return head;

// }

// struct node * deleteatindex( struct node * head, int index){
//     struct node * p = head;
//     struct node * ptr = head -> next;
//     int i = 0;
//     while( i != index -1){
//         p = p -> next;
//         ptr = ptr -> next;
//         i++;
//     }
//     p -> next = ptr -> next;
    
//     free(ptr);
//     return head;
// }

// int main (){
//     struct node * head = (struct node*)malloc(sizeof(struct node));
//     struct node * second = (struct node*)malloc(sizeof(struct node));
//     struct node * third = (struct node*)malloc(sizeof(struct node));
//     struct node * fourth = (struct node*)malloc(sizeof(struct node));

//     head -> data = 3;
//     head -> next = second;
//     second -> data = 4;
//     second -> next = third;
//     third -> data = 5;
//     third -> next = fourth;
//     fourth -> data = 6;
//     fourth -> next = NULL;

//     struct node * ptr = (struct node*)malloc(sizeof(struct node));

//     traversal(head);
//     head = insertatstart(head,10);
//     traversal(head);

// }


// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     struct node * next;
//     int data;
// };

// void traversal(struct node * ptr){
//     while(ptr != NULL){
//         printf("%d ", ptr -> data);
//         ptr = ptr -> next;
//     }
// }


// struct node * insert_start(struct node * head, int value){
//     struct node * ptr = (struct node *)malloc(sizeof(struct node));
//     ptr -> next = head;
//     ptr -> data = value;
//     return head;
// }

// struct node * insert_index(struct node * head, int value, int index){
//     struct node* p = head;
//     struct node * ptr = (struct node*)malloc(sizeof(struct node));
//     ptr -> data = value;
//     int i =0;
//     while (i!=index-1){
//         p = p-> next;
//         i++;
//     }
//     ptr -> next = p -> next;
//     p -> next = ptr;
//     return head;
// }

// struct node * delete_start(struct node *head){
//     struct node * ptr = head;
//     head = head -> next;
//     free(ptr);
//     return head;
// }

// struct node * delete_index(struct node * head, int index){
//     struct node * p = head;
//     struct node * ptr = head -> next;
//     int i = 0;
//     while(i!=index-1){
//         p = p-> next;
//         ptr = ptr -> next;
//         i++;
//     }
//     p -> next = ptr -> next;
//     free( ptr );
//     return head;
// }

// struct node * delete_end ( struct node * head){
//     struct node * p = head;
//     struct node * ptr = head -> next;
//     while(ptr -> next != NULL){
//         ptr = ptr -> next;
//         p = p -> next;
//     }
//     p -> next = NULL;
//     free( ptr);
//     return head;

// }

// int main(){
//     struct node * head = (struct node *)malloc(sizeof(struct node));
//     struct node * second= (struct node *)malloc(sizeof(struct node));
//     struct node * third = (struct node *)malloc(sizeof(struct node));
//     struct node * fourth = (struct node *)malloc(sizeof(struct node));

//     head -> data = 1;
//     head -> next = second;

//     second -> data = 2;
//     second -> next = third;

//     third -> data = 3;
//     third -> next = fourth;

//     fourth -> data = 4;
//     fourth -> next = NULL;

//     head = delete_end(head);
//     traversal(head);

// }

