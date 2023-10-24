#ifndef SINGLELINKEDLIST_H_INCLUDED
#define SINGLELINKEDLIST_H_INCLUDED

#include "STY_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    u32 credit;
    u32 salary;
    u32 password;
    u32 texes;
    u8 username[100];


}CustomerType;


typedef struct node
{
    CustomerType customerData;
    struct node* next;

}node;

typedef struct linkedList
{
     node* first; // point not node

}linkedList;

void list_addBack (linkedList* list , CustomerType customerArgument );
void list_displayAll(linkedList list);
u8 list_empty (linkedList list);
void list_insertAt (linkedList* list , u32 pos, CustomerType customerArgument);
void list_deleteAt(linkedList* list , u32 pos);
s32 list_search (linkedList list, u8 customerUsernameArgument[]);
u32 list_getPasswordAt (linkedList list , u32 pos);



#endif // SINGLELINKEDLIST_H_INCLUDED
