/*– Faça um programa com uma função
que receba um inteiro positivo como
parâmetro e retorne seu somatório.*/
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
