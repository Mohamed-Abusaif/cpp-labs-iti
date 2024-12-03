#include "Employee.h"

#ifndef MENU_H
#define MENU_H

void gotoxy(int x, int y);
int getch(void);
void DisplayMenu(int currentPostion, int row, int col);
void applicationRunning(int flagExitScreen, int ch, int flagExitCurrentScreen, int employeeCount, Employee empArray[], int row, int col,int currentPostion);
#endif // MENU_H
