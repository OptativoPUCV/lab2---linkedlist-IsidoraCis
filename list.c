#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}


List * createList() {
  List* lista = NULL;
  lista = (List *) malloc(sizeof(List *));
  return lista;

}

void * firstList(List * list) {
    if (list->current==NULL) return NULL;
    if (list->head==NULL) return NULL;
    list->current = list->head;
    return list->current->data;
}

void * nextList(List * list) {
  if (list->current==NULL) return NULL;
  if (list->current->next==NULL) return NULL;
  list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    if (list->current==NULL) return NULL;
    if (list->tail==NULL) return NULL;
    list->current = list->tail;
    return list->current->data;
}

void * prevList(List * list) {
    if (list->current==NULL) return NULL;
    if (list->current->prev==NULL) return NULL;
    list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
  Node *nuevo = createNode(data);
  if(list->head == NULL)
  {
    list->head = nuevo;
    list->tail = nuevo;
  }
  else
  {
    nuevo->next = list->head;
    list->head = nuevo;
  }
  
  
}
  
void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node *nodo = createNode(data);
  if(list->current == NULL)
  {
    list->head = nodo;
    list->tail = nodo;
  }
  else
  {
    nodo->prev = list->current;
    list->current->next = nodo;
    list->tail = nodo;
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    if(list->current == NULL) return NULL;
    void * dato = NULL;
    dato = list->current->data;
    if(list->current == list->tail)
    {
      list->tail = list->tail->prev;
      list->tail->next = NULL;
      list->current = NULL;
    }
    else if(list->current == list->head)
    {
      list->head = list->head->next;
      list->head->prev= NULL;
      list->current = NULL;
    }
    else
    {
      list->current->prev->next=list->current->next;
      list->current->next->prev = list->current->prev;
      list->current =NULL;
    }
    return dato;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}