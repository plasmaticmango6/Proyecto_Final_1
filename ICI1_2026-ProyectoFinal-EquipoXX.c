/*
nombre del proyecto: Proyecto final Menu de control de trabajadores
objetivo:
 crear un menu para administrar a los trabajadores de una empresa
número de equipo:
nombres completos de los integrantes:
 - Macias Silva Axel Ezequiel
 - Pacheco Juarez Alejandro
 - Perez Reyes Olga Dafne
carrera, semestre y grupo:
 Ingenieria en Computacion Inteligente, 1er semestre, 1 - A
materia:
 Lenguajes de Computacion I
nombre de la profesora:
 Rosalinda Avendaño Lopez
fecha de elaboración:
periodo escolar:
*/

/*comandos para subir sus cambios a github
git add .
git commit -m "comentario que mencione los cambios realizados"
git push*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// el locale y el windows es para los acentos, depende de en que sistema operativo esten usando usen locale o windows
// #include <locale.h>
// #include <windows.h>

void mostrarUnTrabajador(char nombres[], int claves[], float salarios[])
{
    // cada que se llame a esta funcion se muestra la informacion de un trabajador en especifico.
}

void buscarRegistro(char nombres[], int claves[], float salarios[])
{
    // esta funcion solo es para como lo dice buscar un registro por nombre o por clave del trabajador, y mostrar esa informacion.
    // esta funcion de puede usar en apartados como: eliminar un registro, modificar un registro y nuevamente buscar un registro.
}

void mostrarMenu()
{
    printf("--------------------------");
    printf("A) Mostrar Trabajadores");
    printf("B) Buscar un Registro");
    printf("C) Insertar nuevo Registro");
    printf("D) Eliminar un Registro");
    printf("E) Modificar un Registro");
    printf("F) Salir");
    printf("--------------------------");
}

int main()
{
    // setlocale(LC_ALL, ""); // para MAC o VS
    // SetConsoleOutputCP(65001); // para embarcadero

    srand((unsigned int)time(NULL));
    char opcionMenu;

    printf("--CONTROL DEL SISTEMA--");
    do
    {
        mostrarMenu();
        printf("Ingrese una opcion: ");
        scanf("%c", &opcionMenu);
        switch (opcionMenu)
        {
        case 'A':
        case 'a':
            /* code */
            break;
        case 'B':
        case 'b':
            /* code */
            break;
        case 'C':
        case 'c':
            /* code */
            break;
        case 'D':
        case 'd':
            /* code */
            break;
        case 'E':
        case 'e':
            /* code */
            break;
        case 'F':
        case 'f':
            printf("Has salido del programa");
            break;
        default:
            break;
        }
    } while (opcionMenu != 'f' || opcionMenu != 'F');

    return 0;
}
