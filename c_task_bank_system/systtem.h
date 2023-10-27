/*
 * @file 		system.h
 * @author 		Ahmed Radwan Ibrahim
 * @brief       this file contain fn prototypes needed for the bank system
 *
 */
#ifndef __SYSTEM_H__
#define __SYSTEM_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Standard_Data_Types.h"

#define ADMIN_ID (12368)
#define ADMIN_PASS (12368)
typedef struct Customer {
  u32 credit;
  u32 salary;
  u32 psw;
  u32 id;
  u32 taxes;
  struct Customer* next_customer;
} customer;

void Add_New_Customer(void);
void Delet_Customer(void);
void Show_Customer(void);
void Show_All_Customers(void);
void first_window(void);
void admin_window(void);
void customer_window(void);
void Admin_Show_Customer(void);

#endif
