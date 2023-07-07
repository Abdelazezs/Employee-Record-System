#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>

int id;
char name[50];
int age;
double salary;
char title[50];


typedef struct  Node_Type
 {
    char name[50];
    int age;
    int id;
    double salary;
    char title[50];
    struct Node_Type * next;
}node_t;
typedef struct tag_sll
{
    node_t *head;
    int size;
} sll_t;

typedef enum
{
    SLL_OK,
    SLL_NOT_OK,
    SLL_EMPTY,
    SLL_NOT_CREATED,
    SLL_NOT_FOUND,
    NODE_NOT_CREATED,
    LIST_NOT_CREATED,
} EN_SLLStatus_t;
// Welcome massege 
void Welcome_massage ();
// get Employee data from the user 
void Get_Employee_Data_From_User();
// function to creat  the Employee list
sll_t *create_Employeee_list();
/*function to check if the list is not created or empty 
i used this check alone in a seperate function to call it in the code
befor calling the (delete ,Searchand modify ) Employee data to 
give the user a massege that the list is empty befor he enterd 
the Employee ID to (delete ,Searchand modify ) Employee data */
EN_SLLStatus_t IsList_NotCreated_Or_Empty (sll_t *list );
// function to creat  new Employee data 
node_t *create_New_Employee_Data(int ID , char Name[50],int Age ,double Salary ,char Title[50]);
// function to add new employee data 
EN_SLLStatus_t Add_New_Employee_Data(sll_t *list, int ID , char Name[50],int Age ,double Salary ,char Title[50]);
// function to display All Employee Data
EN_SLLStatus_t View_All_Employees_Data(sll_t *list);
// function to search for an Employee data 
EN_SLLStatus_t search_for_Employee_data(sll_t *list, int  ID);
// function to delete Data of an Employee
EN_SLLStatus_t delete_Employee_Data(sll_t *list, int ID);
// function to modify Data of an Employee
EN_SLLStatus_t Modify_Employee_Data(sll_t *list, int ID);
#endif