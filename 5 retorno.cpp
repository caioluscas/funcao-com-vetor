/*� Fa�a um programa com uma fun��o
que receba um inteiro positivo como
par�metro e retorne seu somat�rio.*/
#include <stdlib.h>//func1.cpp
#include <stdio.h>
#include <math.h>
void soma(int num1)
{
	int s;
	s=num1+num1;
	printf("Somatorio do numero inteiro: %d",s);
}
main()
{
	int n1;
	printf("Diga um numero inteiro: ");
	scanf("%d",&n1);
	soma(n1);
}
