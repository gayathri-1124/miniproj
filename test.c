#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   char* time;
   int booked;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;




//display the list
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%s,%d) ",ptr->time,ptr->booked);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

// //insert link at the first location
void insertFirst(char* time, int available) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->time = time;
   link->booked = available;
   //point it to old first node
   link->next = head;
   //point first to new first node
   head = link;
}


//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
int find(char* key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return 0;
   }

   //navigate through list
   while(strcmp(current->time , key)==0) {
	
      //if it is last node
      if(current->next == NULL) {
         return 0;
      } else {
         //go to next link
         current = current->next;
      }
   }      
   //if data found, return the current Link
   return current->booked;
}

void book(char* key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return ;
   }

   //navigate through list
   while(strcmp(current->time , key)==0) {
	
      //if it is last node
      if(current->next == NULL) {
         printf("s");
      } else {
         //go to next link
         current = current->next;
      }
   }      
   //if data found, return the current Link
   current->booked = 1;
   printf("Booked");
}

void main() {
   insertFirst("10am",0);
   insertFirst("11am",0);
   insertFirst("12am",0);
   insertFirst("1pm",0);
   insertFirst("2pm",0);
   printList();
   char* selTime;
   while (true)
   {
       printf("\nWELCOME TO ROOM ALLOC\n");
       scanf("%s", selTime);
       struct node *ptr = head;
       if(find(selTime) == 1){
           printf("booked");
           
       }else{
           printf("not booked");
           book(selTime);
       }
       printList();
   }
   
	
}