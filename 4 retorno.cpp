/*Fa�a um programa em C com uma
fun��o que receba a dist�ncia em Km e a
quantidade de litros de gasolina
consumidos por um carro em um
percurso como par�metro, calcule e
apresente o consumo em Km/l .*/
#include <stdlib.h>//func1.cpp
#include <stdio.h>
#include <math.h>
void consumo(float kilometro, float litro)
{
	float consumo;
	consumo=kilometro*litro;
	printf("Consumo: %.2f KM/l",consumo);
}
main()
{
	float km,l;
	printf("Diga o KM: ");
	scanf("%f",&km);
	printf("Diga os litros: ");
	scanf("%f",&l);
	consumo(km,l);
}
