/** 
 * ===========================================================
 * Name: C3C Colby Ting
 * Section: T1A
 * Project: Implementation of Linked List Library
 * Purpose: List ADT as linked list
 * ===========================================================
 */
#include "listAsLinkedList.h"
#include <stdio.h>
#include<stdlib.h>


 LinkedList* createLinkedList(){
        LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
        if(list == NULL){
            list->head = NULL;
            list->tail = NULL;
            list->numberOfElements = 0;
        }
        return list;
 }
 void printLinkedList(LinkedList* list){
        if(list->head == NULL) {
            printf("List is empty.\n");
        }
        Node* current = list->head;
        while(current != NULL) {
            printf("%f -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
 }
 double getElementLinkedList(LinkedList* list, int position)
 {
        if(list->head == NULL) {
            return -1; // List is empty
        }
        if(position < 0 || position >= list->numberOfElements) {
            return -1; // Invalid position
        }
        Node* current = list->head;
        for(int i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
        // Check implementation
 }
 void deleteElementLinkedList(LinkedList* list, int position)
 {
        if (list->head == NULL) {
            return; // List is empty
        }
        if(position < 0 || position >= list->numberOfElements) {
            return; // Invalid position
        }
        if(list->head == list->tail) {
            // Only one element in the list
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
        } else if(position == 0) {
            // Deleting the head
            Node* temp = list->head;
            list->head = list->head->next;
            free(temp);
        } else {
            // Deleting from middle or end
            Node* current = list->head;
            for(int i = 0; i < position - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            if(temp == list->tail) {
                list->tail = current; // Update tail if last element is deleted
            }
            free(temp);
        }
        list->numberOfElements--;
 }
 void insertElementLinkedList(LinkedList* list, int position, double element)
 {
       if(list->head == NULL || position <= 0) {
            // Insert at head
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = element;
            newNode->next = list->head;
            list->head = newNode;
            if(list->tail == NULL) {
                list->tail = newNode; // Update tail if list was empty
            }
        } else {
            // Insert at middle or end
            Node* current = list->head;
            for(int i = 0; i < position - 1 && current->next != NULL; i++) {
                current = current->next;
            }
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = element;
            newNode->next = current->next;
            current->next = newNode;
            if(newNode->next == NULL) {
                list->tail = newNode; // Update tail if inserted at end
            }
        }
        list->numberOfElements++;
 }
 void changeElementLinkedList(LinkedList* list, int position, double newElement)
 {
        if(list->head == NULL) {
            return; // List is empty
        }
        if(position < 0 || position >= list->numberOfElements) {
            return; // Invalid position
        }
        Node* current = list->head;
        for(int i = 0; i < position; i++) {
            current = current->next;
        }
        current->data = newElement;
 }
 int findElementLinkedList(LinkedList* list, double element)
 {
        Node* current = list->head;
        int position = 0;
        while(current != NULL) {
            if(current->data == element) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
        
 }
 void selSortLinkedList(LinkedList* list)
 {
        if(list->head == NULL) {
            return; // List is empty
        }
        Node* i = list->head;
        while(i != NULL) {
            Node* minNode = i;
            Node* j = i->next;
            while(j != NULL) {
                if(j->data < minNode->data) {
                    minNode = j;
                    
                }
                j = j->next;
            }
            double temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
            i = i->next;
        }
        

 }
 void insertSortLinkedList(LinkedList* list)
 {
        if(list->head == NULL) {
            return; // List is empty
        }
        Node* sorted = NULL;
        Node* i = list->head;
        while(i != NULL) {
            Node* next = i->next;
            if(sorted == NULL || i->data < sorted->data){
                i->next = sorted;
                sorted = i;
            } else{
                Node* search = sorted;
                while (search->next != NULL && search->next->data < i->data)
                {
                    search = search->next;
                }
                i->next = search->next;
                search->next = i;
                
            }
            i = next;
        }
        list->head = sorted;

 } void appendElementLinkedList(LinkedList* list, double element)
 {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = element;
        newNode->next = NULL;
        if (list->head == NULL) {
            list->head = newNode;
            list->tail = newNode;
        } else {
            list->tail->next = newNode;
            list->tail = newNode;
        }
        list->numberOfElements++;
 } 
 int lengthOfLinkedList(LinkedList* list)
 {      if(list == NULL) {
            return 0;
        }
        return list->numberOfElements;
    
 } void deleteLinkedList(LinkedList* list)
 {
        if(list == NULL) {
            return;
        }
        Node* current = list->head;
        Node* nextNode;
        while(current != NULL) {
            nextNode = current->next;
            free(current);
            current = nextNode;
        }
        free(list);
 }
