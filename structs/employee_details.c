#include <stdio.h>
#include <stdlib.h>

/**
 * prompt for employee details
 * store employee details
 * modify each employee
 * delete employee
 * display all employees
*/

struct employee {
    char name[50];
    int id;
    int age;
    float salary;
    char department[50];
};

void display(struct employee emp);
void addEmployee(struct employee emp[], int *n);
void modifyEmployee(struct employee emp[], int n);
void deleteEmployee(struct employee emp[], int *n);

int main(void)
{
    struct employee employees[100];
    int n = 0, choice;

    while (1)
    {
        printf("\nEmployee management system\n");
        printf("1. Add employee\n");
        printf("2. Modify Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Display All Employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            addEmployee(employees, &n);
            break;

            case 2:
            modifyEmployee(employees, n);

            case 3:
            deleteEmployee(employees, &n);

            case 4:
            printf("\nEmployee Record:\n");

            for (int i = 0; i < n; i++)
            {
                display(employees[i]);
            }
            break;

            case 5:
            exit(0);
            
            default:
            printf("Invalid choide:\n");
        }
    }

    return (0);
}


void display(struct employee emp)
{
    printf("\nName: %s\n", emp.name);
    printf("ID: %d\n", emp.id);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);
    printf("Department; %s\n", emp.department);

}

void addEmployee(struct employee emp[], int *n)
{
    printf("\nEnter name, id, age, salary, and department: ");
    scanf("%s %d %d %f %s", emp[*n].name, &emp[*n].id, &emp[*n].age, &emp[*n].salary, &emp[*n].department);
    (*n)++;
}

void modifyEmployee(struct employee emp[], int n)
{
    int id, flag = 0;

    printf("\nEnter employee id to modify: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (emp[i].id == id)
        {
            printf("\nEnter name, age, salary, and department: ");
            scanf("%s %d %f %s", &emp[i].name,&emp[i].age, &emp[i].salary,&emp[i].department);
            flag = 1;
            break;
        }
    }
if (flag == 0)
{
    printf("\nEmployee id %d not found\n", id);
}

}

void deleteEmployee(struct employee emp[], int *n)
{
    int id, flag = 0;

    printf("\nEnter employee id to delete: ");
    scanf("%d", &id);


for (int i = 0; i < *n; i++)
{
    if (emp[i].id == id)
    {
        for (int j = i; j < (*n) - 1; j++)
        {
            emp[j] = emp[j + 1];
        }
        (*n)--;
        flag = 1;
        break;
    }
}

if (flag == 0)
{
    printf("\nEmployee with id %d not found\n", id);
}

}