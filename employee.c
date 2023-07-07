#include <string.h>
#include "employee.h"

// Welcome massege 
void Welcome_massage ()
{
    printf("******************************************************************************\n");
    printf("********************* Welcome To Employee Record System. *********************\n");
    printf("*****************************************************************************\n\n");
   
}

// get Employee data from the user
void Get_Employee_Data_From_User()
{
    printf("\n\t\tEnter employee ID => ");
    scanf("%d", &id);

    printf("\t\tEnter employee name => ");
    fflush(stdin);
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline if present

    // printf("\t\tEnter employee age => ");
    // scanf("%d", &age);
    do {
    printf("\t\tEnter employee age (Age must be between 20 and 60)\n\t\t Age =>  ");
    scanf("%d", &age);

    if (age < 20 || age > 60) {
        printf("\n\t\tInvalid age. Please enter an age between 20 and 60.\n");
    }
} while (age < 20 || age > 60);

    printf("\t\tEnter employee salary => ");
    scanf("%lf", &salary);

    printf("\t\tEnter employee title => ");
    fflush(stdin);
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // remove newline if present
}
// function to creat  the Employee list
sll_t *create_Employeee_list()
{
    sll_t *Employeelist = malloc(1 * sizeof(sll_t));
    if (Employeelist == NULL)
    {
        return NULL;
    }
    // Now the Employee list is Empty
    Employeelist->head = NULL;
    Employeelist->size = 0;
    return Employeelist;
}
// function to creat  new Employee data
node_t *create_New_Employee_Data(int ID, char Name[50], int Age, double Salary, char Title[50])
{
    // creat Employee data
    node_t *NewEmployeeData = malloc(1 * sizeof(node_t));
    if (NewEmployeeData == NULL)
    {
        return NULL;
    }
    NewEmployeeData->id = ID;
    strcpy(NewEmployeeData->name, Name);
    NewEmployeeData->age = Age;
    NewEmployeeData->salary = Salary;
    strcpy(NewEmployeeData->title, Title);
    NewEmployeeData->next = NULL;
    return NewEmployeeData;
}

/*function to check if the list is not created or empty 
i used this check alone in a seperate function to call it in the code
befor calling the (delete ,Searchand modify ) Employee data to 
give the user a massege that the list is empty befor he enterd 
the Employee ID to (delete ,Searchand modify ) Employee data */
EN_SLLStatus_t IsList_NotCreated_Or_Empty (sll_t *list )
{
    if (list == NULL) // check if there is a list created or not
    {
        return SLL_NOT_OK;
    }
    if (list->head == NULL) // check if the list is Empty or note
    {
        return SLL_EMPTY;
    }
}
// function to add new employee data
EN_SLLStatus_t Add_New_Employee_Data(sll_t *list, int ID, char Name[50], int Age, double Salary, char Title[50])
{
    if (list == NULL)
    {
        return SLL_NOT_OK;
    }
    node_t *NewEmployeeData = create_New_Employee_Data(ID, Name, Age, Salary, Title);
    //  Specil case (there is no employee data recorded).
    if (list->head == NULL)
    {
        list->head = NewEmployeeData;
        list->size++;
        return SLL_OK;
    }
    // In case of the there is recorded employee data befor .
    /*first creat temporary pointer called current
    then make it points to the last node in the linked list */
    node_t *current = list->head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = NewEmployeeData;
    list->size++;
    return SLL_OK;
}
// function to display All Employee Data
EN_SLLStatus_t View_All_Employees_Data(sll_t *list)
{
    if (list == NULL) // check if there is a list created or not
    {
        return SLL_NOT_OK;
    }
    if (list->head == NULL) // check if the list is Empty or note
    {
        printf("the list is empty\n");
        return SLL_EMPTY;
    }
    printf("Employees Data :- \n");
    node_t *current = list->head; // creat temporary pointr to points to every employee data
    while (current != NULL)
    {
        printf("NAME => %s\t ID => %d\t Age => %d\tSalary => %0.2f\tTitle => %s\n", current->name, current->id, current->age, current->salary, current->title);
        current = current->next;
    }
    printf("\n");
    return SLL_OK;
}
// function to search for an Employee data
EN_SLLStatus_t search_for_Employee_data(sll_t *list, int ID)
{
    
    node_t *current = list->head; // creat temporary pointr to points to every employee data
    while (current != NULL)
    {
        if (current->id == ID)
        {
            printf("\t\tdata found \n");
            printf("\t\tNAME => %s\tAge => %d\tSalary => %0.2f\tTitle => %s\n"
            , current->name, current->age, current->salary, current->title);
            return SLL_OK;
        }
        current = current->next;
    }
    printf("data Not found \n");
    return SLL_NOT_FOUND;
}
// function to delete Data of an Employee
EN_SLLStatus_t delete_Employee_Data(sll_t *list, int ID)
{
   
    node_t *current = list->head; // creat temporary pointr and make it points to which the head pointer points to
    if (current->id == ID)
    {
        list->head = list->head->next;
        free(current);
        list->size--;
        return SLL_OK;
    }
    node_t *perv = current;
    while (current != NULL)
    {
        if (current->id == ID)
        {
            break;
        }
        perv = current;
        current = current->next;
    } 
    if (current == NULL)
    {
        return NODE_NOT_CREATED;
    }
    perv->next = current->next;
    free(current);
    list->size--;
    return SLL_OK;
}
// function to modify Data of an Employee
EN_SLLStatus_t Modify_Employee_Data(sll_t *list, int ID)
{
    node_t *current = list->head; // creat temporary pointr to points to every employee data
    while (current != NULL)
    {
        if (current->id == ID)
        {
            delete_Employee_Data(list, ID);
            printf("\t\tEnter new Employee data\n");
            Get_Employee_Data_From_User();
            Add_New_Employee_Data(list, id, name, age, salary, title);
            return SLL_OK;
        }
        current = current->next;
    }
    printf("ID Not found \n");
    printf("\t\t=> press 'space' to modify anthor Employee Data\n");
    return SLL_NOT_FOUND;
}