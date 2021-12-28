#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    char time[20];
    int available;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   printf("[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%s,%d) ",ptr->time,ptr->available);
      ptr = ptr->next;
   }
	
   printf(" ]\n");
}


void allAvailableSlots() {
   struct node *ptr = head;
   printf("All Available Slots are: \n");
	
   //start from the beginning
   while(ptr != NULL) {
       if(ptr->available == 0){
            printf("(%s,%d) ",ptr->time,ptr->available);
       }
      ptr = ptr->next;
   }
	
   printf("\n");
}

void allBookedSlots() {
   struct node *ptr = head;
   printf("All Booked Slots are: \n");
	
   //start from the beginning
   while(ptr != NULL) {
       if(ptr->available == 1){
            printf("(%s,%d) ",ptr->time,ptr->available);
       }
      ptr = ptr->next;
   }
	
   printf("\n");
}

//insert link at the first location
void insertFirst(char time[20]) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   strcpy(link->time, time);
   link->available = 0;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}


//find a link with given key
struct node* find(char time[20]) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(strcmp(time , current->time) != 0) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }
   //if data found, return the current Link
   return current;
}

void book(char selSlot[20]){
   
    struct node *foundLink = find(selSlot);
    if(foundLink != NULL) {
        //printf("Element found: ");
        printf("(%d,%s) ",foundLink->available,foundLink->time);
        if(foundLink->available == 1){
            printf("Can not place booking, time slot not available");
        }else{
            printf("Booking placed YAY! \n");
            foundLink->available = 1;
            printList();
        }
        printf("\n");  
    } else {
        printf("Try again.");
    } 
}

void cancel(char selSlot2[20]){
    struct node *foundLink = find(selSlot2);
    printf("%s", selSlot2);
    if(foundLink != NULL) {
        //printf("Element found: ");
        printf("(%d,%s) ",foundLink->available,foundLink->time);
        if(foundLink->available == 0){
            printf("Can not cancel booking, time slot not occupied");
        }else{
            printf("Booking cancelled \n");
            foundLink->available = 0;
            printList();
        }
        printf("\n");  
    } else {
        printf("Try again.");
    } 
}




void main() {
    insertFirst("4pm");
    insertFirst("3pm");
    insertFirst("2pm");
    insertFirst("1pm");
    insertFirst("1pm");
    insertFirst("1pm");
    insertFirst("1pm");
    insertFirst("1pm");
    
    while (true)
    {
        printf("WELCOME TO ROOM ALLOC\n");
        printf("These are the available slots\n");
        printList();
        printf("\nMenu:\n");
        printf("1.book\n");
        printf("2.cancel\n");
        printf("3.show all bookings\n");
        printf("4.show all vacant slots\n");
        int selection;

        scanf("%d", &selection);
        
        switch (selection)
        {
        case 1 : {
            char selSlot[20];
            scanf("%s", selSlot);
            book(selSlot);
            break;
        }
            
        case 2:{
            char selSlot2[20];
            scanf("%s", selSlot2);
            cancel(selSlot2);
            break;}
        case 3:
            allBookedSlots();
            break;
        case 4:
            allAvailableSlots();
            break;
        
        default:
            break;
        }
    }   
   printList();

}
