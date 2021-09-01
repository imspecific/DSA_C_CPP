#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};


void *addAtBeg(struct Node *head,int data){

    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;

}

void addAtLast(struct Node *head, int data){

    struct Node *temp,*p;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    p=head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = temp;
    temp->next = NULL;

}

void *addAtPos(struct Node *head, int data, int pos){

    int i;
    struct Node *temp, *p;
    temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if(pos == 1){
        temp->next = head;
        head = temp;
    }
    p=head;
    for(i=0; i<pos-1; i++){
        p = p->next;
    }
    if(p == NULL)
        printf("Wrong position");
    else{
        temp->next = p->next;
        p->next = temp;
    }
}


void Display(struct Node *head){

    struct Node *p;
    if(head == NULL){
        printf("List is empty");
        return;
    }
    p = head;
    printf("Linked List is: \n");
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
        printf("-> ");
    }
}


void main(){

    struct Node *head = NULL;
    head = addAtBeg(head,4);
    head = addAtBeg(head,5);
    addAtLast(head,7);
    addAtPos(head,12,2);
    //addAtPos(head,13,1);
    Display(head);

}