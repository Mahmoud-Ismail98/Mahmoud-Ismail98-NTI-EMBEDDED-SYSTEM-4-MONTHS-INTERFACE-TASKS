#include "bankHandler.h"



int main()
{

    /* set up of the Program */
    linkedList list ={NULL};
    CustomerType customer1 ={2321,2000,1,10,"Ahmed Ali"};
    CustomerType customer2 ={1238,2000,2,0,"Muhammad Ali"};
    CustomerType customer3 ={6597,2000,3,5,"Mahmoud Ahmed"};
    CustomerType customer4 ={1248,2000,4,200,"Sayed Muhsen"};
    CustomerType customer5 ={8979,2000,5,30,"Bruno Sha3ban"};
    CustomerType customer6 ={4589,2000,6,55,"Michael Mufeed"};
    CustomerType customer7 ={2468,2000,7,6,"Mahmoud Koryem"};
    CustomerType customer8 ={5555,2000,8,8,"Ahmed Radwaan"};
    CustomerType customer9 ={3256,2000,9,41,"Mahmoud Abu-Gabl"};
    CustomerType customer10 ={4233,2000,10,11,"Muhammad Ammar"};


    list_addBack(&list,customer1);
    list_addBack(&list,customer2);
    list_addBack(&list,customer3);
    list_addBack(&list,customer4);
    list_addBack(&list,customer5);
    list_addBack(&list,customer6);
    list_addBack(&list,customer7);
    list_addBack(&list,customer8);
    list_addBack(&list,customer9);
    list_addBack(&list,customer10);

    u32 adminPassword = 2020;
    u8 adminUsername[100]= "admin";
    u32 userInputChoice;





    while(1){

        printf("\nPlease enter your identity\n1-Admin\n2-Customer\n3-Exit\n");
        scanf(" %lu",&userInputChoice);


        switch(userInputChoice){

            case 1 :
                bank_adminMode(&list);

                break;
            case 2 :
                bank_customerMode(&list);
                break;
            case 3 :
                return 0;
            default :
                printf("\nTry Again\n");


        }

    }




    return 0;

}
