/*
 * main.c
 *
 *  Created on: 13 abr. 2020
 *      Author: Mariano Seif
 *      Legajo: 110070
 *      Curso: 1 F
 *      19mfs81@gmail.com
 */

#include <stdio.h>
#include "funciones.h"

int main(void)
{
	int opcion, primerNumero, segundoNumero, isSetPrimerNumero, isSetSegundoNumero, suma, resta;
	long long int multiplicacion;
	unsigned long long int factorialA, factorialB;
	float division;

	primerNumero = 0;
	segundoNumero = 0;
	isSetPrimerNumero = 0;
	isSetSegundoNumero = 0;

	opcion = menu(primerNumero, segundoNumero, isSetPrimerNumero, isSetSegundoNumero);

	while(opcion!=5){

		switch(opcion){
			case 1:
				primerNumero = getInt("Ingrese numero (max 5 cifras):");
				isSetPrimerNumero = 1;
				break;
			case 2:
				segundoNumero = getInt("Ingrese numero (max 5 cifras):");
				isSetSegundoNumero = 1;
				break;
			case 3:
				suma = sumar(primerNumero, segundoNumero);
				resta = restar(primerNumero, segundoNumero);
				division = dividir(primerNumero, segundoNumero);
				multiplicacion = multiplicar(primerNumero, segundoNumero);
				factorialA = factorial(primerNumero);
				factorialB = factorial(segundoNumero);
				printf("\nSe hicieron todos los calculos");
				printf("\nSi alguno de los numeros no fue ingresado se asigna 0");
				printf("\nIngrese la opcion 4 para ver los resultados");
				break;
			case 4:
				mostrarResultados(primerNumero, segundoNumero, suma, resta, division, multiplicacion, factorialA, factorialB);
		}

		opcion = menu(primerNumero, segundoNumero, isSetPrimerNumero, isSetSegundoNumero);
	};

	return 0;
}

