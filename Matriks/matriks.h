#ifndef matriks_H
#define matriks_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>   
#include<math.h>
#include <windows.h>


void menu();
void gotoxy(int x, int y);

int multiplication_operation();
int multiplication_scalar_operation();
int addsub_operation();

void cofactor(float [][25], float);
float determinant(float [][25], float);
void transpose(float [][25], float [][25], float);
float inverse();

int triangular_matriks();

float OBE_SPL();
#endif
