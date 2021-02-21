#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    char* string;
} Node;

void push(Node* tail, char* str);
void initList(Node* head, char* str);
void add2list(Node* head, char* str);
void printAll(Node* head);
Node* delNode(Node* head, Node* toDelete);
void freeList(Node* head);
Node* getLast(Node* head);
