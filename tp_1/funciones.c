/*
 * funciones.c

 *  Created on: 13 abr. 2020
 *      Author: Mariano Seif
 *      Legajo: 110070
 *      Curso: 1 F
 *      19mfs81@gmail.com
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

int getInt(char mensaje[]){
	int i, fail;
	char numero[6];

	fail=0;

	do{
		if(fail==1){
			printf("\nIncorrecto!");
			fail=0;
		}
		printf("\n%s", mensaje);

		do{
			__fpurge(stdin);
			fgets(numero, 7, stdin);
		}while(numero[0]=='\n' || numero[0]=='\0');

		if(numero[0]=='-' || numero[0]=='+'){
			numero[strlen(numero)] = '\0';
			for(i=1;i<(strlen(numero)-1);i++)
			{
				if(numero[i]<'0' || numero[i]>'9'){
					fail = 1;
				}
			}
		}else{
			numero[strlen(numero)-1] = '\0';
			for(i=0;i<(strlen(numero));i++)
			{
				if(numero[i]<'0' || numero[i]>'9'){
					fail = 1;
				}
			}
		}

	}while(fail==1);

	return atoi(numero);
}

int menu(int a, int b, int isSetPrimerNumero, int isSetSegundoNumero){
	int opcion;

	do{
		printf("\n\nMenu:");
		printf("\n==================================");
		if(isSetPrimerNumero==0){
			printf("\n1- Ingresar 1er operando (A=No ingresado aun)");
		}else{
			printf("\n1- Ingresar 1er operando (A=%d)", a);
		}
		if(isSetSegundoNumero==0){
				printf("\n2- Ingresar 2do operando (B=No ingresado aun)");
		}else{
				printf("\n2- Ingresar 2do operando (B=%d)", b);
		}
		printf("\n3- Calcular todas las operaciones");
		printf("\n4- Informar resultados");
		printf("\n5- Salir\n");

		opcion = getInt("Ingrese opcion: ");

		if (opcion<1 || opcion>5)
		{
			printf("\nOpcion incorrecta. Ingrese nuevamente: ");
			opcion = getInt("Ingrese opcion: ");
		}
	}while(opcion<1 || opcion>5);

	return opcion;
}

int sumar(int a, int b)
{
	return a+b;
}

int restar(int a, int b)
{
	return a-b;
}

float dividir(int a, int b)
{
	float division;
	return division = b==0 ? -1 : (float)a/(float)b;
}

long long int multiplicar(int a, int b)
{
	return a*b;
}

unsigned long long int factorial(int numero)
{
	if(numero<0){
	        return -1;
	}else if(numero>65){
		return 0;
	}
	unsigned long long int factorial = 1;
	int i;
	for (i=1; i<=numero; i++){
		factorial=factorial * i;
	}

	return factorial;
}

int mostrarResultados(int primerNumero, int segundoNumero, int suma, int resta, float division, long long int multiplicacion, unsigned long long int factorialA, unsigned long long int factorialB)
{
	printf("\nEl resultado de las operaciones entre A=%d y B=%d es: ", primerNumero, segundoNumero);
	printf("\n\t- A+B es: %d", suma);
	printf("\n\t- A-B es: %d", resta);
	if(division == -1){
		printf("\n\t- A/B - No se puede dividir por cero");
	}else if(primerNumero==0){
		printf("\n\t- A/B es: 0");
	}else{
		printf("\n\t- A/B es: %f", division);
	}

	printf("\n\t- A*B es: %lld", multiplicacion);

	if(factorialA == -1)
	{
		printf("\n\t- A!- No puedo calcular el factorial de A porque es un numero negativo");
	}else if(factorialA == 0){
		printf("\n\t- A!- Debido a una limitacion de diseño no puedo calcular el factorial de un numero mayor a 65");
	}else{
		printf("\n\t- A!- El factorial de A es: %llu", factorialA);
	}

	if(factorialB == -1){
		printf("\n\t- B!- No puedo calcular el factorial de B porque es un numero negativo");
	}else if(factorialB == 0){
		printf("\n\t- B!- Debido a una limitacion de diseño no puedo calcular el factorial de un numero mayor a 65");
	}else{
		printf("\n\t- B!- El factorial de B es: %llu", factorialB);
	}
	return 0;
}

