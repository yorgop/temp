#include <stdio.h>
#include <stdlib.h>
//#include "stack.h"

struct node;
typedef struct node Node;

struct node{
  char data;
  char top;
  Node* next;
};

//function prototypes
void push(Node**, char);
void pop(Node**);
char top(Node**);
void print(Node*);
void destroy(Node**);
void reverse(Node**);

void delimiter_check(int);

int main(int argc, char* argv[]){

  Node* head = NULL;
  //commented out testing is below

  // printf("******************************\n");
  // printf("Testing of the functions\n");
  //
  //
  //
  // push(&head, 'a');
  // push(&head, 'b');
  // push(&head, 'c');
  // push(&head, 'd');
  // push(&head, 'e');
  // push(&head, 'f');
  // push(&head, 'g');
  // push(&head, 'h');
  // printf("Top of the stack is now: %c\n", top(&head));
  //
  // pop(&head);
  // pop(&head);
  // printf("Top of the stack is now: %c\n", top(&head));
  //
  //
  // //to print out that stack in order from top to bottom
  // //I am reversing the linked list before the print function
  // //and then reversing it back to it's original order
  // reverse(&head);
  // printf("The contents of the stack in order are now:\n");
  // print(head);
  // reverse(&head);
  //
  //
  // destroy(&head);
  //
  //
  //
  //
  //
  //
  //
  // printf("\n******************************\n");


char c;
scanf("%c", &c);

if(c == EOF){
  //correct if it is an empty string
  printf("Yes\n");
}

while(c != '\n'){

  //if character is a left delimiter
  if( c == '{' || c == '[' || c == '<' || c == '(' ){

    //push onto the stack
    printf("Pushed onto the stack\n");
    push(&head, c);
    printf("Current Top: %c\n", top(&head));

    reverse(&head);
    print(head);
    reverse(&head);
  }

  //if character is a right delimiter and the top of stack is a left
  //delimiter of the same type call pop
  if(c == '}' || c == ']' || c == '>' || c == ')'){

    if(c == '}' && top(&head) == '{'){
      printf("Popping stack\n");
      pop(&head);
      printf("Current Top: %c\n", top(&head));
    }
    else if(c == ']' && top(&head) == '['){
      printf("Popping stack\n");
      pop(&head);
      printf("Current Top: %c\n", top(&head));
    }
    else if(c == '>' && top(&head) == '<'){
      printf("Popping stack\n");
      pop(&head);
      printf("Current Top: %c\n", top(&head));
    }
    else if(c == ')' && top(&head) == '('){
      print(head);
      printf("Popping stack\n");
      pop(&head);
      printf("Current Top: %c\n", top(&head));
    }
    else{
      printf("No\n");
    }

  }
  scanf("%c", &c);

}


  destroy(&head);

  return 0;

}

//the equivalent of an insert_at_tail function in our linked list
void push(Node** pHead, char item){
  Node* temp;

  //when the linked list is empty
  if(*pHead == NULL){
    *pHead = (Node*) malloc(sizeof(Node));
    (*pHead)->data = item;
    (*pHead)->next = NULL;
  }

  //when not empty
  else{
    temp = *pHead;

    //traverse the linked list until we get to the last node that points to NULL
    while(temp->next != NULL){
      temp = temp->next;
    }

    //now that we are at the final Node
    temp->next = (Node*) malloc(sizeof(Node));
    temp->next->data = item;
    temp->next->next = NULL;

  }

}
//will remove the last node in the linked list that points to NULL or return nothing if the list is empty
void pop(Node** pHead){
  Node* temp;

  //if the linked list is empty cannot pop
  if(*pHead == NULL){
    return;
  }

  //if the linked list has one Node
  if((*pHead)->next == NULL){
    free((*pHead)->next);
    (*pHead)->next = NULL;
  }

  //when the linked list is not empty
  else{
    temp = *pHead;

    //travel to the second to last node
    while(temp->next->next != NULL){
      temp = temp->next;
    }

    //remove final node and set the previous node->next to NULL
    free(temp->next);
    temp->next = NULL;
  }

}

//returns the end of the linked list (The most recently pushed item)
char top(Node** pHead){

  Node* temp;

  //if the linked list is empty them retrn NULL CHARACTER \0
  if(*pHead == NULL){
    return '~';
  }

  else{
    temp = *pHead;

    while(temp->next != NULL){
      temp = temp->next;
    }

    return (temp->data);

  }

}
//prints out the linked list starting from the first node that Head points to
void print(Node* head){

  if(head == NULL){
    printf("Stack is Empty!\n");
    return;
  }

  while(head != NULL){
    printf("[  %c  ]\n", head->data);
    head = head->next;
  }

}

//destroys and frees every node in the linked list
void destroy(Node** pHead){
  Node* temp;

  while(*pHead != NULL){
    temp = *pHead;
    *pHead = (*pHead)->next;
    free(temp);
  }
}

//will reverse the direction of the linked list
void reverse(Node** pHead){
  Node* previous = NULL;
  Node* next = NULL;
  Node* current = *pHead;

  //while the list is not empty
  while(current != NULL){
    next = current->next;
    current->next = previous;

    //move pointer to the next node
    previous = current;
    current = next;


  }

  *pHead = previous;

}
