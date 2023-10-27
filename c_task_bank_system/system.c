/*
 * @file 		system.c
 * @author 		Ahmed Radwan Ibrahim
 * @brief       this file contain fn definations needed for the bank system
 *
 */
#include"systtem.h"
static int admin_check(void);
extern customer* customer_head;
void first_window(void) {

    printf("\n\n\n");
	printf("+===========================================================================================+\n")   ;
    printf("|                               Welcome to\" The Bank system\"                               |\n")   ;
    printf("+===========================================================================================+\n")   ;
    printf("| 1 | Admin window                                                                          |\n")   ;
    printf("|---|---------------------------------------------------------------------------------------|\n")   ;
    printf("| 2 | Client window                                                                         |\n")   ;
    printf("|---|---------------------------------------------------------------------------------------|\n")   ;
    printf("| 0 | Exit                                                                                  |\n")   ;
    printf("+===========================================================================================+\n")   ;


}
void admin_window(void) {
    u32 option=1;

    if(admin_check())
    {
      system("cls");
      while(option)
      {  
        printf("\n\n\n");
        printf("+===========================================================================================+\n")   ;
        printf("|                               You are now in admin mode                                   |\n")   ;
        printf("+===========================================================================================+\n")   ;
        printf("| 1 | Add Client                                                                            |\n")   ;
        printf("|---|---------------------------------------------------------------------------------------|\n")   ;
        printf("| 2 | Show Client                                                                           |\n")   ;
        printf("|---|---------------------------------------------------------------------------------------|\n")   ;
        printf("| 3 | Delet Client                                                                          |\n")   ;
        printf("|---|---------------------------------------------------------------------------------------|\n")   ;
        printf("| 4 | Show All Clients                                                                      |\n");
        printf("|---|---------------------------------------------------------------------------------------|\n")   ;
        printf("| 0 | Exit                                                                                  |\n")   ;
        printf("+===========================================================================================+\n")   ;
        scanf(" %d",&option);
        fflush(stdin);
        switch (option)
        {
        case 1:
            Add_New_Customer();
            break;
        case 2:
            Admin_Show_Customer();
            break;
        case 3:
            Delet_Customer();
            break; 
        case 4:
            Show_All_Customers();
            break;
        case 0:
            printf("exit from admin mode done\n");
            break;   
        default:
        printf("undefuned choise retray\n");
            break;
        }
    }
  }
    
}
void customer_window(void) {
    system("cls");
    u32 option=99;
    while(option)
    {
    printf("\n\n\n");
    printf("+===========================================================================================+\n")   ;
    printf("|                               You are now in your acount page                             |\n")   ;
    printf("+===========================================================================================+\n")   ;
    printf("| 1 | Show Client                                                                           |\n")   ;
    printf("|---|---------------------------------------------------------------------------------------|\n")   ;
    printf("| 0 | Exit                                                                                  |\n")   ;
    printf("+===========================================================================================+\n")   ;
    scanf(" %d",&option);
    fflush(stdin);
    switch (option)
    {
    case 0:
        printf("exit done from client page\n");
        return;
        break;
    case 1:
        Show_Customer();
        break;
    default:
    printf("undefined choise");
        break;  
    }
    }
}
void Add_New_Customer(void)
{
    customer *temp_node=(customer*)malloc(sizeof(customer));
    customer *last_node=customer_head;
    printf("enter Id:");
    scanf(" %d",&temp_node->id);
    fflush(stdin);
    printf("enter pass:");
    scanf(" %d",&temp_node->psw);
    fflush(stdin);
    printf("enter salary:");
    scanf(" %d",&temp_node->salary);
    fflush(stdin);
    printf("enter credit:");
    scanf(" %d",&temp_node->credit);
    fflush(stdin);
    printf("enter taxes:");
    scanf(" %d",&temp_node->taxes);
    fflush(stdin);
    temp_node->next_customer=NULL;
    if(customer_head->id==temp_node->id)
    {
        printf("error repeted id not allowed\n");// check the repeted id
        free(temp_node);
        return;
        }
    while((last_node->next_customer)!=NULL)
    {
        if(last_node->id==temp_node->id)
        {
            printf("error repeted id not allowed\n");// check the repeted id
            free(temp_node);
            return;
        }
        last_node=last_node->next_customer;
    }
   if(last_node->id==temp_node->id)
   {
        printf("error repeted id not allowed\n");// check the repeted id
        free(temp_node);
        return;
    }
    last_node->next_customer=temp_node;
    printf("/********added succesfuly*********/\n");

}
void Show_All_Customers(void) {
    customer *desired_customer=customer_head;
    while(1)
    {
        if (desired_customer== NULL)
        {
            printf("all clients displayed succcessfuly\n");
            break;
        }
        
        printf("\n***********************************\n");
        printf("| Id     is:  %d\n",desired_customer->id);
        printf("| credit is:  %d\n",desired_customer->credit);
        printf("| salary is:  %d\n",desired_customer->salary);
        printf("| taxes  is:  %d\n",desired_customer->taxes);
        printf("***********************************\n");
        desired_customer=desired_customer->next_customer;
        

    }
}
void Show_Customer(void) {
    u32 LOCAL_customer_ID=0;
    u32 LOCAL_customer_pass=0;
    printf("\n enter Your ID: ");
    scanf(" %d",&LOCAL_customer_ID);
    fflush(stdin);
    printf("\n enter your pass: ");
    scanf(" %d",&LOCAL_customer_pass);
    fflush(stdin);
    customer *desired_customer=customer_head;
    while (desired_customer->id != LOCAL_customer_ID)
    {
        if(desired_customer->next_customer == NULL)
        {
            printf("id out of range\n");
            return ;
        }
        desired_customer=desired_customer->next_customer;
    }
    if ((LOCAL_customer_pass==desired_customer->psw))
    {   
        printf("\n***********************************\n");
        printf("| Id     is:  %d\n",desired_customer->id);
        printf("| credit is:  %d\n",desired_customer->credit);
        printf("| salary is:  %d\n",desired_customer->salary);
        printf("| taxes  is:  %d\n",desired_customer->taxes);
        printf("***********************************\n");
        return ;
    }
    else
    {
        printf("\n wrong customer info");
        return ;
    }
}
void Delet_Customer(void) {
    u32 LOCAL_customer_ID=0;
    printf("\n enter customer Id You want to delet: ");
    scanf(" %d",&LOCAL_customer_ID);
    fflush(stdin);
    customer *desired_customer=customer_head;
    customer *temp_node=desired_customer;
    while (desired_customer->id != LOCAL_customer_ID)
    {
        if(desired_customer->next_customer == NULL)
        {
            printf("id out of range\n");
            return ;
        }
        temp_node=desired_customer;
        desired_customer=desired_customer->next_customer;
    }
    temp_node->next_customer=desired_customer->next_customer;
    free(desired_customer);
    printf("deleted sucssesfuly");
}

void Admin_Show_Customer(void) {
    u32 LOCAL_customer_ID=0;
    printf("\n enter client ID: ");
    scanf(" %d",&LOCAL_customer_ID);
    fflush(stdin);
    customer *desired_customer=customer_head;
    while (desired_customer->id != LOCAL_customer_ID)
    {
        if(desired_customer->next_customer == NULL)
        {
            printf("id out of range\n");
            return ;
        }
        desired_customer=desired_customer->next_customer;
    }
   
        printf("\n***********************************\n");
        printf("| Id     is:  %d\n",desired_customer->id);
        printf("| credit is:  %d\n",desired_customer->credit);
        printf("| salary is:  %d\n",desired_customer->salary);
        printf("| taxes  is:  %d\n",desired_customer->taxes);
        printf("***********************************\n");
        return ;
}

static int admin_check(void) {
    u32 LOCAL_Admin_ID=0;
    u32 LOCAL_Admin_pass=0;
    printf("\n enter admin ID: ");
    scanf(" %d",&LOCAL_Admin_ID);
    fflush(stdin);
    printf("\n enter admin pass: ");
    scanf(" %d",&LOCAL_Admin_pass);
    fflush(stdin);
    if ((LOCAL_Admin_ID==ADMIN_ID)&&(LOCAL_Admin_pass==ADMIN_PASS))
    {
        return 1;
    }
    else
    {
        printf("\n wrong admin info");
        return 0;
    }
}
 