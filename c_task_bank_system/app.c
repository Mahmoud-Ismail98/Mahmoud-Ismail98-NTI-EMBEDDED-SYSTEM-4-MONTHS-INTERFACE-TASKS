/*
 * @file 		app.c
 * @author 		Ahmed Radwan Ibrahim
 * @brief       this file contain the bank system algorithm
 *
 */

#include "systtem.h"
/*satic first data section*/
customer fifth_client={
    .credit=6656000,
    .id=5,
    .psw=555,
    .salary=30300,
    .taxes=300,
    .next_customer=NULL
};
customer fourth_client={
    .credit=1021500,
    .id=4,
    .psw=444,
    .salary=80000,
    .taxes=1800,
    .next_customer=&fifth_client
};
customer third_client={
    .credit=65600,
    .id=3,
    .psw=333,
    .salary=6000,
    .taxes=450,
    .next_customer=&fourth_client
};
customer second_client={
    .credit=98993,
    .id=2,
    .psw=222,
    .salary=78210,
    .taxes=2000,
    .next_customer=&third_client
};
customer first_customer={
    .credit=50000,
    .id=1,
    .psw=111,
    .salary=6000,
    .taxes=750,
    .next_customer=&second_client
};
/*satic first data section end*/
customer* customer_head=&first_customer;
int main() {
  u32 option = 1;
  
  while (option) {
    first_window();
    scanf(" %d", &option);
    fflush(stdin);
    switch (option) {
      case 1:
        admin_window();
        break;
      case 2:
        customer_window();
        break;
      case 0:
        printf("exit done\n");
        break;
      default:
        printf("\nerror choise try agin \n");
        option = 0;
        break;
    }
  }
  return 0;
}
