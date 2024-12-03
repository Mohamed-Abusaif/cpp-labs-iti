#include <iostream>
#include "Employee.h"
#include "Menu.h"

#define EMP_SIZE 100

using namespace std;

int main(void)
{
    int row = 20, col = 20, currentPostion = 0, ch, flagExitScreen = 1;
    int flagExitCurrentScreen = 1;
    Employee empArray[EMP_SIZE];
    int employeeCount = 0;

    DisplayMenu(currentPostion, row, col);
    applicationRunning(flagExitScreen, ch, flagExitCurrentScreen, employeeCount, empArray, row, col,currentPostion);

    return 0;
}
