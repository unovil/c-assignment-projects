#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define CHAR_LIMIT 200

typedef struct Employee
{
    char name[CHAR_LIMIT];
    int hireDate;
    float salary;
} Employee;

int main()
{
    Employee emp =
    {
        .name = "First Last",
        .hireDate = 2016,
        .salary = 2000.75
    };

    printf("This is how you will fill up your form:\n");
    sleep(1);
    printf("Employee Name: ");
    printf("%s\n", emp.name);
    sleep(1);
    printf("Hire Date: ");
    printf("%d\n", emp.hireDate);
    sleep(1);
    printf("Salary: ");
    printf("%.2f\n\n", emp.salary);

    sleep(1);
    printf("Now start.\n\n");

    sleep(1);
    printf("Employee Name: ");
    fgets(emp.name, CHAR_LIMIT, stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;

    sleep(1);
    printf("Hire Date: ");
    scanf("%d", &emp.hireDate);

    sleep(1);
    printf("Salary: ");
    scanf("%f", &emp.salary);

    sleep(2);
    printf("\nYou have entered:\n");
    printf("Employee Name: %s\n", emp.name);
    printf("Hire Date: %d\n", emp.hireDate);
    printf("Salary: %.2f\n\n", emp.salary);

    sleep(1);
    printf("Goodbye!\n");
    return 0;
}
