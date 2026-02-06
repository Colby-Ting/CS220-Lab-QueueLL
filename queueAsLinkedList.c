/** 
 * ===========================================================
 * Name: C3C Colby Ting
 * Section: T1A
 * Project: Queue ADT implemented using linked list
 * Purpose: Queue ADT library - FIFO
 * ===========================================================
 */
#include "listAsLinkedList.h"
#include "queueAsLinkedList.h"
#include <stdio.h>
#include<stdlib.h>

void queueEnqueue(QueueAsLinkedList* queue, double element){
    appendElementLinkedList(queue, element);
}
double queueDequeue(QueueAsLinkedList* queue){
    if(queueIsEmpty(queue)) {
        return -1; // Queue is empty
    }
    double frontElement = getElementLinkedList(queue, 0);
    deleteElementLinkedList(queue, 0);
    return frontElement;
}
bool queueIsEmpty(QueueAsLinkedList* queue){
    if(queue->head == NULL) {
        return true; // Queue is empty
    }
    return false; // Queue is not empty
    
}
bool queueIsFull(QueueAsLinkedList* queue){
    return false; // A linked list implementation of a queue is never full
}
QueueAsLinkedList* queueInit(){
    QueueAsLinkedList* queue = (QueueAsLinkedList*)malloc(sizeof(QueueAsLinkedList));
    if(queue == NULL) {
        return NULL; // Memory allocation failed
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->numberOfElements = 0;
    return queue;
}
void deleteQueue(QueueAsLinkedList* queue){

    Node* current = queue->head;
    while(current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}
double queuePeek(QueueAsLinkedList* queue){
    if(queueIsEmpty(queue)) {
        return -1.0; // Queue is empty
    }
    return getElementLinkedList(queue, 0); // Return the front element without removing it
}
void queuePrint(QueueAsLinkedList* queue){
    if(queueIsEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = queue->head;
    while(current != NULL) {
        printf("%f -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int queueSize(QueueAsLinkedList* queue){
    if(queue == NULL) {
        return 0; // Queue is NULL
    }
    return queue->numberOfElements; // Return the number of elements in the queue
}