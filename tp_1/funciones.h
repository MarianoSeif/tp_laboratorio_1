/*
 * funciones.h
 *
 *  Created on: 13 abr. 2020
 *      Author: Mariano Seif
 *      Legajo: 110070
 *      Curso: 1 F
 *      19mfs81@gmail.com
 */



/*
 * @brief Muestra un menu en pantalla
 * @param a Primer numero ingresado por el usuario
 * @param b Segundo numero ingresado por el usuario
 * @param isSetPrimerNumero flag de ingreso
 * @param isSetSegundoNumero flag de ingreso
 * @return Opcion elegida por el usuario
 */
int menu(int a, int b, int isSetPrimerNumero, int isSetSegundoNumero);


/*
 * @brief Pide un entero y lo valida
 * @param mensaje Mensaje a mostrar al usuario
 * @return numero entero ingresado
 */
int getInt(char* mensaje);


/*
 * @brief Suma dos numero
 * @param a Primer sumando
 * @param b Segundo sumando
 * @return La suma de los numeros
 */
int sumar(int a, int b);


/*
 * @brief Resta dos numeros
 * @param a Minuendo
 * @param b Sustraendo
 * @return La resta de ambos numeros
 */
int restar(int a, int b);


/*
 * @brief Divide dos numeros
 * @param a Dividendo
 * @param b Divisor
 * @return El resultado de la division o -1 en caso de que el dividendo sea 0
 */
float dividir(int a, int b);


/*
 * @brief Multiplica dos numeros
 * @param a Multiplicando
 * @param b Multiplicador
 * @return El producto de ambos numeros
 */
long long int multiplicar(int a, int b);


/*
 * @brief Calcula el factorial de un numero
 * @param numero
 * @return Retorna el resultado del calculo, -1 si el numero es negativo o 0 si el numero es mayor a 65 lo que provocaria un desbordamiento de memoria
 */
unsigned long long int factorial(int numero);


/*
 * @brief Muestra los resultados de los todos los calculos hechos por el programa
 * @param primerNumero
 * @param segundoNumero
 * @param suma
 * @param resta
 * @param division
 * @param multiplicacion
 * @param factorialA
 * @param factorialB
 * @return 0
 */
int mostrarResultados(int primerNumero, int segundoNumero, int suma, int resta, float division, long long int multiplicacion, unsigned long long int factorialA, unsigned long long int factorialB);
