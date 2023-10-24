#include "bankHandler.h"

static void checkAdminUsername(void);
static void checkAdminPassword(void);
static void addCustomer(linkedList* list);
static void deleteCustomer(linkedList* list);
static void showCustomerInfo(linkedList* list, u32 coustomerIndex);


static s32 checkCustomerUsername(linkedList* list);
static void checkCustomerPassword(linkedList* list, u32 customerIndex);

void bank_adminMode(linkedList* list){

    u32 userInputChoice;
    u32 customerIndx;

    checkAdminUsername();
    checkAdminPassword();





    printf("\nyou're logging in sucessfully\n");

    printf("\nhere it's the list of customers:  \n");
    list_displayAll(*list);



    while(1){

    printf("\nenter your operation\n1-Add Customer\n2-Delete Customer\n3-show info of the customer\n4-exit from admin mode\n");
    scanf(" %lu",&userInputChoice);


    switch(userInputChoice){

            case 1 :
                addCustomer(list);

                break;
            case 2 :
                deleteCustomer(list);
                break;
            case 3 :

                printf("enter which customer you want to see his info\n");
                scanf("%lu",&customerIndx);
                showCustomerInfo(list,customerIndx);
                break;
            case 4:
                return;
            default :
                printf("\nTry Again\n");


        }
    }




}


void bank_customerMode(linkedList* list){

    u32 userInputChoice;
    s32 positionFound;
    positionFound = checkCustomerUsername(list);
    checkCustomerPassword(list,positionFound);
    showCustomerInfo(list,positionFound);

    while(1){
    printf("\nPress 1 to exit from Customer mode\n");
    scanf(" %lu",&userInputChoice);

    if(userInputChoice == 1)
        break;


}
}





////////////////////////////////////////////////////////////////////////////////////////

/* private function */

static void checkAdminUsername(void){

    u8 scanAdminUsername[100];
    printf("\n     You're in admin Mode \n");

    while(1){

        printf("enter your username\n");
        scanf("%s",&scanAdminUsername);
        if (strcmp(scanAdminUsername,"admin") == 0)
            break;
        else {
            printf("Try Again\n");
        }

    }
}
static void checkAdminPassword(void){

    u32 scanAdminPassword;

    while(1){

        printf("enter your password\n");
        scanf("%lu",&scanAdminPassword);
        if (scanAdminPassword == (u32)2020)
            break;
        else {
            printf("Your Admin Password is wrong.. Try Again\n");
        }

    }

}

static void addCustomer(linkedList* list){

    CustomerType temp;

    printf("enter custom credit\n");
    scanf("%lu",& (temp.credit));

    printf("enter custom salary\n");
    scanf("%lu",& (temp.salary));


    printf("enter custom password\n");
    scanf("%lu",& (temp.password));


    printf("enter custom username\n");
    scanf("%s",temp.username);


    printf("enter custom texes\n");
    scanf("%lu",& (temp.texes));

    list_addBack(list,temp);

    printf("\nyou added a new customer sucessfully\n");
    printf("\nhere it's the new list:  \n");
    list_displayAll( *list);

}

static void deleteCustomer(linkedList* list){

    u32 userInputChoice;
    printf("enter which customer you want to delete\n");


    scanf("%lu",&userInputChoice);

    list_deleteAt(list,userInputChoice);

    printf("\nhere it's list after your operation:  \n");
    list_displayAll( *list);


}

static void showCustomerInfo(linkedList* list,u32 customerIndex){


    list_displayAt(*list,customerIndex);

}


static s32 checkCustomerUsername(linkedList* list){


    s32 answer;
    s8 ch;
    u8 len;
    printf("\n     You're in Customer Mode \n");

    while(1){

        printf("enter your username\n");

        u8 scanCustomerUsername[100];

        while ((ch = getchar()) != '\n' && ch != EOF); // remove newline of previous input
        fgets(scanCustomerUsername,100,stdin);
        len = strlen(scanCustomerUsername);
         if (scanCustomerUsername[len - 1] == '\n')
             scanCustomerUsername[len - 1] = '\0';


        answer =list_search(*list,scanCustomerUsername);
        if ( answer!= -1){
            break;
            }
        else {
            printf("\nTry Again\n ");
        }

    }

    return answer;
}


static void checkCustomerPassword(linkedList* list, u32 customerIndex){

    u32 passwordCheck;
while(1){

        printf("enter your password\n");
        scanf("%d",&passwordCheck);



        if (list_getPasswordAt(*list,customerIndex) == passwordCheck){
            break;
            }
        else {
            printf("\nTry Again\n ");
        }

    }


}
