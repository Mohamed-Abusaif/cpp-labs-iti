#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// Structs
typedef struct BD
{
    int day;
    int month;
    int year;
} BD;

typedef struct Employee
{
    char name[10];
    int emp_id;
    int age;
    int salary;
    BD bd;
} Employee;

#endif // EMPLOYEE_H
