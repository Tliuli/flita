// report1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

#define N 100

 
 void reverse(char s[]) /* разворачиваем строку */
 {
     int q, j;
     char c;
 
     for (q = 0, j = strlen(s) - 1; q < j; q++, j--) {
         c = s[q];
         s[q] = s[j];
         s[j] = c;
     }
 }

void itoa(int x, char s[]) /* переводим целое десятичное число в строку в двоичной системе счисления */
 {
     int i, sign;
 
     if ((sign = x) < 0)  /* запоминаем знак числа */
         x = -x;          /* делаем число положительным */
     i = 0;
     do {       /* записываем цифры в обратном порядке */
         s[i++] = x % 2 + '0';   /* переходим к следующей цифре */
     } while ((x /= 2) > 0); 
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

int main(void){

	setlocale(LC_CTYPE, "Russian"); /* поправляем вывод на русский */
	
	double a, tr = 5;
	char s[N];

	printf ("Введите кол-во элементов в множестве, не превышающее 100.\n");
	scanf_s ("%lf", &a);
    while ((a - (int)a) != 0){ /* накладываем условия на вводимые числа */
            tr--;
            if (tr == 0){
            printf ("Вы превысили максимальное кол-во попыток. Перезапустите программу и попробуйте заново.\n");
            getch();
	        return 0;
            }
            printf("Введите целое число. Иные символы недопустимы.\n");
			printf ("Введите кол-во элементов в множестве, не превышающее 100.\n");
	        scanf_s ("%lf", &a);
    }
	
    while (a <= 0) {
        tr--;
        if (tr == 0){
            printf ("Вы превысили максимальное кол-во попыток. Перезапустите программу и попробуйте заново.\n");
            getch();
	        return 0;
        }    
        printf("Кол-во элементов не может быть нулевым или отрицательным. Попробуйте заново ввести число.\n");
        scanf_s ("%lf", &a);
    }
    if (a > 100) {
        printf("Кол-во элементов не может быть больше 100. Лишние элементы не будут учтены.\n");
        a = 100;
    }

	const int n = 100;
    double A[n];
    int i = 0;
    tr = 5;
	int d;

    printf ("Введите указанное число %d элементов множества.\n", (int)a);
    for (i = 0; i < a; i++)
    {
        printf("%d-ое число = ", i + 1);
        scanf("%lf", &A[i]);
        while ((A[i] - (int)A[i]) != 0){
            tr--;
            if (tr == 0){
            printf ("Вы превысили максимальное кол-во попыток. Перезапустите программу и попробуйте заново.\n");
            getch();
	        return 0;
            }
            printf("Введите целое число. Иные символы недопустимы.\n");
            printf("%d-ое число = ", i + 1);
            scanf("%lf", &A[i]);
        }
    }
    printf("Вывод. Первое число - введенное, второе - его вид в двоичной кодировке.\n");
    for (i = 0; i < a; i++){ /* ввыводим числа в паре - первое число - исходное, второе - оно же в двочиной кодировке */
		d = (int)A[i];
		itoa(d, s);
        printf("%d %s\n", (int)A[i], s);
	}

    getch();

	return 0; 
}