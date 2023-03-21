#include <stdio.h>
#include <stdlib.h>


struct student{
    char name[50];
    int id;
    int age;
    float grade;
};

int main(void)
{
    struct student students[100];
    int n,i;

    printf("Enter number of students:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter name, id, age, grade: ", i + 1);
        scanf("%s %d %d %f", &students[i].name, &students[i].id, &students[i].age, &students[i].grade);

    }

    printf("\nStudent record:\n");
    
    for (i = 0; i < n; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].id);
        printf("Age: %d\n", students[i].age);
        printf("Grade: %.2f\n", students[i].grade);

    }

    return (0);

}