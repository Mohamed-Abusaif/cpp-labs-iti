
#include <iostream>
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

#define UP 65
#define DOWN 66

using namespace std;

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[34m"

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

// Stack class implementation
class Stack
{
private:
    int top;
    int size;
    Employee *items;

public:
    Stack(int size)
    {
        this->size = size;
        items = new Employee[size];
        top = -1;
    }

    bool push(Employee data)
    {
        if (top == size - 1)
        {
            return false; // Stack is full
        }
        items[++top] = data;
        return true; // Push successful
    }

    void pop()
    {
        if (top == -1)
        {
            return; // Stack is empty
        }
        top--;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack: " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << "Employee Name: " << items[i].name << endl;
            cout << "Employee ID: " << items[i].emp_id << endl;
            cout << "Employee Age: " << items[i].age << endl;
            cout << "Employee Salary: " << items[i].salary << endl;
            cout << "Employee Birth Date: " << items[i].bd.day << "/" << items[i].bd.month << "/" << items[i].bd.year << endl;
            cout << "------------------------------" << endl;
        }
    }
};

// Function to move the cursor to a specific position
void gotoxy(int x, int y)
{
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\033[%d;%dH", y, x);
#endif
}

// Function to get a single character without echoing it to the console
int getch(void)
{
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

// Function to display the menu
void DisplayMenu(int currentPosition, int row, int col)
{
    printf("\033[H\033[J"); // Clear screen

    // "New" option
    gotoxy(col / 2 - 4, 1);
    if (currentPosition == 0)
    {
        printf("%sNew%s", GREEN_COLOR, RESET_COLOR);
    }
    else
    {
        printf("%sNew%s", BLUE_COLOR, RESET_COLOR);
    }

    // "Display" option
    gotoxy(col / 2 - 4, 3);
    if (currentPosition == 1)
    {
        printf("%sDisplay Employees%s", GREEN_COLOR, RESET_COLOR);
    }
    else
    {
        printf("%sDisplay Employees%s", BLUE_COLOR, RESET_COLOR);
    }

    // "Delete" option
    gotoxy(col / 2 - 4, 5);
    if (currentPosition == 2)
    {
        printf("%sDelete Employee%s", GREEN_COLOR, RESET_COLOR);
    }
    else
    {
        printf("%sDelete Employee%s", BLUE_COLOR, RESET_COLOR);
    }

    // "Exit" option
    gotoxy(col / 2 - 4, 7);
    if (currentPosition == 3)
    {
        printf("%sExit%s", GREEN_COLOR, RESET_COLOR);
    }
    else
    {
        printf("%sExit%s", BLUE_COLOR, RESET_COLOR);
    }
}

int main(void)
{
    int row = 20, col = 20, currentPosition = 0, ch, flagExitScreen = 1;
    Stack empStack(100);

    DisplayMenu(currentPosition, row, col);

    while (flagExitScreen)
    {
        ch = getch();
        if (ch == 27)
        {
            ch = getch();
            if (ch == 91)
            {
                ch = getch();
                if (ch == UP)
                {
                    currentPosition = (currentPosition - 1 + 4) % 4; // Cycle 4 options
                }
                else if (ch == DOWN)
                {
                    currentPosition = (currentPosition + 1) % 4;
                }
            }
        }

        if (ch == 10)
        { // Check if Enter key is pressed
            if (currentPosition == 0)
            {
                printf("\033[H\033[J"); // Clear screen
                gotoxy(col / 2 - 4, 3);
                printf(" %sAdd New Employee%s \n", BLUE_COLOR, RESET_COLOR);
                Employee emp;
                // Ensure proper input handling
                printf("Enter Employee Name: ");
                scanf("%s", emp.name);
                printf("Enter Employee ID: ");
                scanf("%d", &emp.emp_id);
                printf("Enter Employee Age: ");
                scanf("%d", &emp.age);
                printf("Enter Employee Salary: ");
                scanf("%d", &emp.salary);
                printf("Enter Employee Birth Date (day month year): ");
                scanf("%d %d %d", &emp.bd.day, &emp.bd.month, &emp.bd.year);
                if (empStack.push(emp))
                {
                    printf("Employee added successfully!\n");
                }
                else
                {
                    printf("Failed to add employee. Stack is full!\n");
                }
                // Pause to allow user to see the message
                printf("Press any key to return to the menu...");
                getch();
            }
            else if (currentPosition == 1)
            {
                printf("\033[H\033[J");
                gotoxy(col / 2 - 4, 3);
                printf(" %sEmployees Database%s \n", RED_COLOR, RESET_COLOR);
                empStack.display();
                gotoxy(col / 2 - 4, 4);
                printf("----------------------");
                printf("Press any key to return to the menu...");
                getch();
            }
            else if (currentPosition == 2)
            {
                empStack.pop();
                printf("\033[H\033[J");
                gotoxy(col / 2 - 4, 3);
                printf(" %sEmployee Deleted!%s \n", YELLOW_COLOR, RESET_COLOR);
                printf("Press any key to return to the menu...");
                getch();
            }
            else if (currentPosition == 3)
            {
                printf("\033[H\033[J");
                gotoxy(col / 2 - 10, 3);
                printf(" %sPress Enter to Exit!%s \n", RED_COLOR, RESET_COLOR);
                gotoxy(col / 2 - 15, 4);
                flagExitScreen = 0;
            }
        }

        if (flagExitScreen)
        {
            DisplayMenu(currentPosition, row, col);
        }
    }

    return 0;
}
