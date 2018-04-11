#include "tstdata.h"
#include "functions.h"
#include <stdlib.h>

/*----------------------------------------------Functon---------------------------------------------------*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the top of the queue
int Push(itemType X){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  if(isFull() == 1){
    return -1;
  }
  else if(isFull() == -1){ // if empty
    Temp->next = NULL;
    Temp->previous = NULL;
    Temp->item = X;
    anchor = Temp;
    rear = anchor;
    tracker = anchor;
    return 1;
  }
  else{
    Temp->next = NULL;
    Temp->previous = rear;
    Temp->item = X;
    rear->next = Temp; // link it as new last node of the linked list of queue nodes
    rear = Temp; // has rear pointer point to this new last node
    }
    return 0;
  }
/*------------------------------------------Pull---------------------------------------------*/
char Pull(){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  itemType X;
  if(isFull() == -1){
      printf("you are attempting to pull an empty queue\n"); // return something
      return '\0'; // queue empty return null character
  }
  else{
    Temp = anchor;
    X = anchor->item;
    anchor = Temp->next;
    anchor->previous = NULL; // sets the previous anchor to null so tracker does not pick it up
    free(Temp);
    if(anchor == NULL) rear = NULL;
    return X;
  }
}
/*------------------------------------------PullBack---------------------------------------------*/
char PullBack(){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  itemType X;
  if(isFull() == -1){
      printf("you are attempting to pull an empty queue\n"); // return something
      return '\0'; // queue empty return null character
  }
  else{
    Temp = rear;
    X = rear->item;
    rear = Temp->previous;
    rear->next = NULL; // sets the previous rear to null so tracker does not pick it up
    free(Temp);
    if(rear == NULL) anchor = NULL;
    return Front();
  }
}
/*------------------------------------------Front---------------------------------------------*/
//returns topmost element
char Front(){
  if(isFull() == -1){
    printf("Nothing in the queue\n");
    return '\0'; // queue empty return null character
  }
  else{
    return anchor->item;
  }
}
/*------------------------------------------Back---------------------------------------------*/
char Back(){
  if(isFull() == -1){
    printf("Nothing in the queue\n");
    return '\0'; // queue empty return null character
  }
  else{
    return rear->item;
  }
}
/*----------------------------------------isFull-------------------------------------------*/
int isFull(){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  if(anchor == NULL && rear == NULL){
    return -1; // queue empty
  }
  else if(Temp == NULL){
    return 1; // queue full
  }
  else{
    return 0; // neither full or empty
  }
}
/*----------------------------------------GetNext-------------------------------------------*/
char GetNext(int direction){ // initialize tracker to anchor Tracker = anchor;
  if(direction == 0){ // move toward rear
    if(tracker->next != NULL){
      tracker = tracker->next;
      return tracker->item;
    }
    else
      return '\0';
  }else if(direction == 1){ // move toward anchor
    if(tracker->previous != NULL){
      tracker = tracker->previous;
      return tracker->item;
    }else{
      return '\0';
    }
  }
  else
    return '\0';
}
/*----------------------------------------GetCurrent-------------------------------------------*/
Node *GetCurrent(){
  if(tracker != NULL){
    return tracker;
  }
  else
    return '\0';
  }
/*----------------------------------------Reset-------------------------------------------*/
int Reset(int r){
  if(r == 1){
    tracker = rear;
  } else if(r == 0){
    tracker = anchor;
  }else
    tracker = tracker;
  return 0;
}
/*----------------------------------------Delete-------------------------------------------*/
int Delete(Node *pointer){
  /* base case */
   if(anchor == NULL || pointer == NULL)
     return 0;

   /* If node to be deleted is head node */
   if(anchor == pointer)
     anchor = pointer->next;

   /* Change next only if node to be deleted is NOT the last node */
   if(pointer->next != NULL)
     pointer->next->previous = pointer->previous;

   /* Change prev only if node to be deleted is NOT the first node */
   if(pointer->previous != NULL)
     pointer->previous->next = pointer->next;

   /* Finally, free the memory occupied by del*/
   free(pointer);
   tracker = anchor; // reset static pointer
   return 1;
/*-------------------------------------InsertAfter----------------------------------------*/
void InsertAfter(Node *pointer, char value){
   Node *Temp;
   Temp = (Node*)malloc(sizeof(Node));

   if(pointer->next == NULL){ // if we are at the end
     Push(value);
   }
   else{
     Temp->next = pointer->next;
     Temp->previous = pointer;
     Temp->item = value;

     pointer->next->previous = Temp;
     pointer->next = Temp;
     if(anchor == NULL) rear = NULL;
   }
}
/*-------------------------------------DeleteNode-----------------------------------------*/
// void DeleteNode(Node * pointer){
//  ALREADY IMPLEMENTED
// }
/*-------------------------------------FindValue------------------------------------------*/
Node *FindValue(int value){
  struct Node* current = anchor;  // Initialize current
    while (current != NULL) // iterates through the linked list to find the value
    {
        if (current->item == value)
            return current;
        current = current->next;
        NodeNumber++;
    }
    return NULL; // not found
}


}