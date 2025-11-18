#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void createList(int n){
    int i, data;
    struct node *temp;

    for (i=1; i<=n ; i++){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for %d node: ",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;

        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
}

void deleteBeginning(){
    if(head==NULL){
        printf("\nThe list is empty!");
        return;
    }
    struct node *temp=head;
    head=head->next;
    printf("\nElement %d is deleted ", temp->data);
    free(temp);
}

void deleteEnd(){
    struct node *temp=head, *prev;
    if(head== NULL){
        printf("\nThe list is empty!");
        return;
    }
    if(head->next==NULL){
        printf("\nElement %d is deleted ", head->data);
        free(head);
        //head=NULL;
        return;
    }

    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    printf("\nElement %d is deleted ", temp->data);
    free(temp);

}

void delete_Element(int value){
    if(head==NULL){
        printf("\nThe list is empty!");
        return;
    }
    if(head->data==value){
        deleteBeginning();
        return;
    }
    struct node *temp=head, *prev;
    while(temp!=NULL &&  temp->data!=value ){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found! \n");
        return;
    }
    prev->next=temp->next;
    printf("\nElement %d is deleted ", temp->data);
    free(temp);

}

void display(){
    if(head==NULL){
        printf("\nThe list is empty!");
        return;
    }
    struct node *temp=head;
    printf("\n--The linked list --\n");
    while(temp!=NULL){
        printf("%d ->", temp->data);
        temp=temp->next;
    }
    printf("NUll\n");
}

void main(){
    int choice, value, n;
    printf("--Linked list operations--\n");
    printf("1.Create a Linked list by insertint nodes\n");
    printf("2.Delete from beginning\n");
    printf("3.Delete from end\n");
    printf("4.Delete a specific element\n");
    printf("5.Display \n");
    printf("6.Exit\n");

    while(1){
        printf("\nSelect your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1 :
                    printf("\nEnter the number of nodes: ");
                    scanf("%d",&n);
                    createList(n);
                    break;

            case 2:
                    deleteBeginning();
                    break;
            case 3:
                    deleteEnd();
                    break;
            case 4:
                    printf("\nEnter the element to be deleted : ");
                    scanf("%d", &value);
                    delete_Element(value);
                    break;
            case 5 :
                    display();
                    break;
            case 6  :
                    printf("\n\n--Program ending successfully--");
                    exit(0);
        }
    }
}
