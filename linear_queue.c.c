#include<stdio.h>
#define N 5

int front =-1, rear=-1;
int queue[N];

void enqueue(int x){
    if(rear==N-1)
        printf("Queue Overflow!\n");
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
        printf("Element %d is inserted\n", queue[rear]);

    }
    else {
        rear++;
        queue[rear]=x;
        printf("Element %d is inserted\n", queue[rear]);
    }
}

void dequeue(){
    if(front==-1 && rear==-1)
        printf("Queue Underflow!\n");

    else if(front==rear){
        printf("Element %d is deleted\n", queue[front]);
        front=rear=-1;
    }
    else{
        printf("Element %d is deleted\n", queue[front]);
        front++;
    }
}

void display(){
    int i;
    if(front==-1 && rear==-1)
        printf("Queue Underflow!\n");
    else{   
    for(i=front; i<=rear; i++){
        printf("%d ", queue[i]);
        
    }
    printf("\n");
}

}

void main(){
    printf("Linear queue operations!\n");
    int x;
    char m;
    printf("Select \na.enqueue \nb.dequeue \nc.display \nd.exit\n");
    while(1){
    scanf(" %c",&m);

    switch(m){
        case 'a': 
            scanf("%d",&x);
            
            enqueue(x);
            break;
        case 'b':
            dequeue();
            break;
        case 'c':
            display();
            break;
        case 'd':
            printf("Program ended succuessfully!");
            return;
        default:
            printf("Invalid choice , enter again!\n");
            break;
    }
}

}
