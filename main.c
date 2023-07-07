#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "employee.h"
char flag = 1;
char choise;
int id;
int main()
{
    Welcome_massage();
    sll_t *list = create_Employeee_list(); // creat a list
    while (flag == 1)
    {
        printf("\t[1] To Add New Employee Data.          \n");
        printf("\t[2] To Delete The Data Of an Employee. \n");
        printf("\t[3] To Modify The Data Of an Employee.\n");
        printf("\t[4] To View The Data Of an Employee.   \n");
        printf("\t[5] To View All Employees Data.        \n");
        printf("\t[6] To Exit.   \n");
        printf("\n\t   => your choise >>>> ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            do
            {
                system("cls");
                Welcome_massage();
                printf("\t Adding New Employee Data :)\n");
                Get_Employee_Data_From_User();
                // Add the new employee data to the list
                int i = Add_New_Employee_Data(list, id, name, age, salary, title);
                system("cls");
                Welcome_massage();
                if (i == SLL_OK)
                {
                    printf("\t\tEmployee Data Added Sucssessfully\n");
                }

                printf("\n\n=> press 'space' to add new Employee Data\n => Press any key to return to main list");
            } while (getch() == 32);
            system("cls");
            Welcome_massage();
            break;
        case 2:
            do
            {
                system("cls");
                Welcome_massage();
                int x = IsList_NotCreated_Or_Empty(list);
                if (x == SLL_EMPTY)
                {
                    printf("\t\tSorry The List Is Empty \n");
                    printf("\n\n => Press any key to return to main list");
                }
                else
                {
                    printf("\t\tenter The Employee ID To Delete \n");
                    printf("\t\t\tID >>>>> ");
                    scanf("%d", &id);
                    int i = delete_Employee_Data(list, id);
                    if (i == SLL_OK)
                    {
                        printf("\t\tData Deleted Sucssessfully\n");
                        printf("\t\t=> Press 'space' to delete anthor Employee Data\n");
                    }

                    else if (i == NODE_NOT_CREATED)
                    {
                        printf("\t\tThere is no data avilable for this employee ......\n");
                        printf("\n\n\t\t=> Press 'space' to delete anthor Employee Data\n");
                    }
                    printf("\n\n => Press any key to return to main list");
                }
            } while (getch() == 32);
            system("cls");
            Welcome_massage();
            break;
        case 3:
            do
            {
                system("cls");
                Welcome_massage();
                int x = IsList_NotCreated_Or_Empty(list);
                if (x == SLL_EMPTY)
                {
                    printf("\t\tSorry The List Is Empty \n");
                    printf("\n\n => Press any key to return to main list");
                }
                else
                {
                    printf("\t\tenter The Employee ID To Modify Data \n");
                    printf("\t\tID >>>>> ");
                    scanf("%d", &id);
                    int i = Modify_Employee_Data(list, id);
                    if (i == SLL_OK)
                    {
                        printf("\t\tData Modified Sucssessfully\n");
                        printf("\n\n\t\t => Press 'space' to modify anthor Employee Data\n");
                    }
                    else if (i == SLL_EMPTY)
                    {
                        printf("\t\tthe list is empty \n");
                    }
                    else if (i == NODE_NOT_CREATED)
                    {
                        printf("\t\tThere is no data avilable for this employee ......\n");
                        printf("\t\t=> press 'space' to modify anthor Employee Data\n");
                    }
                    printf("\n\n=> Press any key to return to main list");
                }

            } while (getch() == 32);
            system("cls");
            Welcome_massage();
            break;
        case 4:
            do
            {
                system("cls");
                Welcome_massage();
                int x = IsList_NotCreated_Or_Empty(list);
                if (x == SLL_EMPTY)
                {
                    printf("\t\tSorry The List Is Empty \n");
                    printf("\n\n => Press any key to return to main list");
                }
                else
                {
                    printf("enter The Employee ID To View \n");
                    printf("ID >>>>> ");
                    scanf("%d", &id);
                    search_for_Employee_data(list, id);
                    printf("=> press 'space' to view anthor Employee Data\nTo return to main list press any key\n");
                }
            } while (getch() == 32);
            system("cls");
            Welcome_massage();
            break;
        case 5:
            system("cls");
            Welcome_massage();
            View_All_Employees_Data(list);
            printf("\n\n => press any key to return to the main list");
            while (getch() == 31)
                ;
            system("cls");
            Welcome_massage();
            break;
        case 6:
            for (int j = 0; j < 20; j++)
            {
                // while(getch()!=27)
                for (long long g = 0; g < 70000000; g++)
                {
                }
                printf(".");
            }
            for (long long g = 0; g < 70000000; g++)
            {
            }
            printf(">");
            for (long long g = 0; g < 70000000; g++)
            {
            }
            printf("\tDone Existing ");
            for (long long g = 0; g < 70000000; g++)
            {
            }
            flag = 0;
            break;

        default:

            system("cls");
            Welcome_massage();
            printf("Ooops !!! Wrong Choise \n");
            printf("\n\n => press any key to Enter Anthor choise\n");
            while (getch() == 31)
                ;
            system("cls");
            Welcome_massage();
            break;
        }
    }
    return 0;
}