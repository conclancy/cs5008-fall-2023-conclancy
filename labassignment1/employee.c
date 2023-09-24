/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/
typedef struct employee
{
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

} employee_t;

/* Read the employee details using scanf*/
void readData(int n, employee_t* s) {

    int i;

    for (i=0; i<n; i++) {
        printf("Enter the employee id of employee %d: ", i+1);
        scanf("%d", &s[i].empId);

        printf("Enter the name of employee %d: ", i+1);
        scanf("%100s", &s[i].Name);

        printf("Enter the designation of employee %d: ", i+1);
        scanf("%100s", &s[i].Designation);

        printf("Enter the department of employee %d: ", i+1);
        scanf("%10s", &s[i].Dept);

        printf("\n");
    }

    //printf("Enter the number of employees:");
    //scanf("%d", &n);
    //printf("%d\n", n);
}

/* Function to print the employee details*/
void display(int n, employee_t * s)
{
    int i; 

    for (i=0; i<n; i++) {
        printf("Employee %d employee id: %d\n", i+1, s[i].empId);
        printf("Employee %d name: %s\n", i+1, s[i].Name);
        printf("Employee %d designation: %s\n", i+1, s[i].Designation);
        printf("Employee %d department: %s\n", i+1, s[i].Dept);

        printf("\n");
    }
    
}

/*----------Main Program--------*/
int main() {

    int n = 0; // The number of employees

    printf("Enter the number of employees:");
    scanf("%d", &n);
    printf("%d\n", n); //TODO
    printf("\n");

    //Dynamic memory allocation
    employee_t* s = (employee_t*)malloc(n * sizeof(employee_t));
    
    //Only proceed if the pointer is not null
    if(s != NULL) {
        readData(n, s);
        display(n, s);
        free(s);
    }

    return 0;
}

