#include "singleLinkedList.h"


static void list_addFirst (linkedList *list,CustomerType customerArgument);


//////////////////////////////////////////////////////
void list_addFirst (linkedList *list,CustomerType customerArgument)
{
    node* newNode = (node*) malloc(sizeof(node));

    newNode->customerData = customerArgument;
    newNode->next = list->first;

    list->first = newNode;
}

void list_addBack (linkedList* list , CustomerType customerArgument)
{
    if(list_empty(*list)) return list_addFirst(list,customerArgument);

    node* temp = list->first;

    while(temp->next) temp= temp->next;

    node* newNode = (node*) malloc(sizeof(node));

    newNode->customerData= customerArgument;
    newNode->next = NULL;

    temp->next = newNode;

}
u8 list_empty (linkedList list)
{
    return (list.first==0);
}

void list_displayAll(linkedList list)
{
    u32 locIterator = 1;
    node* temp = list.first;

    while(temp != NULL)
    {
        printf("%u- ",locIterator++);
        printf("%s\n",temp->customerData.username);
        temp=temp->next;
    }
}

void list_removeFirst (linkedList* list)
{
    if(list_empty(*list)) return;

    node* temp = list->first;

    list->first = temp->next;

    free(temp);
}


void list_displayAt (linkedList list , u32 pos)
{
    if(list_empty(list)) return;

    node* temp = list.first;

    while(--pos && temp->next) temp = temp->next;

    if(pos==0) {

        printf("\n         The  Name is : %s\n",temp->customerData.username);
        printf("\n The  credit is : %d\n",temp->customerData.credit);
        printf("\n The  salary is : %d\n",temp->customerData.salary);
        printf("\n The  password is : %d\n",temp->customerData.password);
        printf("\n The  texes is : %d\n",temp->customerData.texes);
    }
}



void list_deleteAt(linkedList* list , u32 pos)
{
    if(list_empty(*list) || pos <1) return;

    if(pos==1) return list_removeFirst(list);

    node* temp = list->first;
    --pos;
    while(--pos && temp->next) temp= temp->next;

    if (pos ==0 && temp->next != NULL)
    {
        node* temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);

    }
}



s32 list_search (linkedList list, u8 customerUsernameArgument[]){

    s32 idx =-1;
    node* temp= list.first;

    while(temp)
    {
        ++idx;

        if ((strcmp(customerUsernameArgument,temp->customerData.username))==0) return idx+1;
        temp= temp->next;
    }

    return -1;


}




u32 list_getPasswordAt (linkedList list , u32 pos)
{
    if(list_empty(list)) return -1;

    node* temp = list.first;

    while(--pos && temp->next) temp = temp->next;

    if(pos==0) {

        return temp->customerData.password;
    }

    return -1;
}
