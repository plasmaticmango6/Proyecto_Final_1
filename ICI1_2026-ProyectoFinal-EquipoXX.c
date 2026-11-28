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

/*comandos para actualizar el codigo, en caso de que haya un cambio
git status
git pull*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// el locale y el windows es para los acentos, depende de en que sistema operativo esten usando usen locale o windows
#include <locale.h>
// #include <windows.h>

int generarNombre(char resultado[], size_t capacidadResultado, const char nombres[][30], size_t cantidadNombres, const char apellidos[][30], size_t cantidadApellidos)
{
    if (cantidadNombres == 0 || cantidadApellidos == 0 || capacidadResultado == 0)
        return 0;

    size_t indiceNombre = (size_t)rand() % cantidadNombres;
    size_t indiceApellido = (size_t)rand() % cantidadApellidos;
    size_t indiceApellido2 = (size_t)rand() % cantidadApellidos;
    int caracteresEscritos = snprintf(resultado, capacidadResultado, "%s %s %s", nombres[indiceNombre], apellidos[indiceApellido], apellidos[indiceApellido2]);

    return caracteresEscritos >= 0 && (size_t)caracteresEscritos < capacidadResultado;
}

int generarTrabajador(const char nombres[][30], size_t cantidadNombres, const char apellidos[][30], size_t cantidadApellidos, char trabajadores[][70], int claves[], float salarios[])
{
    for (size_t i = 0; i < 10; i++)
    {
        if (!generarNombre(trabajadores[i], sizeof(trabajadores[i]), nombres, cantidadNombres, apellidos, cantidadApellidos))
        {
            fprintf(stderr, "No se pudo generar el nombre del trabajador.\n");
            return 1;
        }

        salarios[i] = (float)(rand() % 20000 + 5000);
        claves[i] = rand() % 9000 + 1000;
    }

    return 0;
}

void mostrarUnTrabajador(const char trabajadores[][70], const int claves[], const float salarios[], size_t cantidadTrabajadores, size_t posicionTrabajador)
{
    if (posicionTrabajador >= cantidadTrabajadores)
    {
        printf("La posicion del trabajador no es valida.\n");
        return;
    }

    printf("\nTrabajador: %s\n", trabajadores[posicionTrabajador]);
    printf("Salario: $%.2f\n", salarios[posicionTrabajador]);
    printf("Clave / ID: %d\n", claves[posicionTrabajador]);
}

void buscarRegistro(const char trabajadores[][70], const int claves[], const float salarios[], size_t cantidadTrabajadores)
{
    char tipoBusqueda;
    printf("Buscar por nombre (N) o por clave (C): ");
    if (scanf(" %c", &tipoBusqueda) != 1)
    {
        printf("No se pudo leer el tipo de busqueda.\n");
        return;
    }

    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }

    size_t coincidencias = 0;
    if (tipoBusqueda == 'N' || tipoBusqueda == 'n')
    {
        char nombreBuscado[70];
        printf("Ingrese el nombre completo: ");
        if (fgets(nombreBuscado, sizeof(nombreBuscado), stdin) == NULL)
        {
            printf("No se pudo leer el nombre.\n");
            return;
        }
        nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

        for (size_t i = 0; i < cantidadTrabajadores; i++)
        {
            if (strcmp(trabajadores[i], nombreBuscado) == 0)
            {
                mostrarUnTrabajador(trabajadores, claves, salarios, cantidadTrabajadores, i);
                coincidencias++;
            }
        }
    }
    else if (tipoBusqueda == 'C' || tipoBusqueda == 'c')
    {
        int claveBuscada;
        printf("Ingrese la clave: ");
        scanf("%d", &claveBuscada);
        if (claveBuscada == NULL)
        {
            printf("No se pudo leer la clave.\n");
            return;
        }

        for (size_t i = 0; i < cantidadTrabajadores; i++)
        {
            if (claves[i] == claveBuscada)
            {
                mostrarUnTrabajador(trabajadores, claves, salarios, cantidadTrabajadores, i);
                coincidencias++;
            }
        }
    }
    else
    {
        printf("Opcion de busqueda no valida.\n");
        return;
    }

    if (coincidencias == 0)
    {
        printf("No se encontro ningun trabajador con ese dato.\n");
    }
}

void mostrarMenu()
{
    printf("\n--------------------------\n");
    printf("A) Mostrar Trabajadores\n");
    printf("B) Buscar un Registro\n");
    printf("C) Insertar nuevo Registro\n");
    printf("D) Eliminar un Registro\n");
    printf("E) Modificar un Registro\n");
    printf("F) Salir\n");
    printf("--------------------------\n");
}

int main()
{
    setlocale(LC_ALL, ""); // para MAC o VS
    // SetConsoleOutputCP(65001); // para embarcadero

    srand((unsigned int)time(NULL));

    char opcionMenu;

    const char nombres[][30] = {"Axel", "Diego", "Rubas", "Dante", "Omar", "Dafne", "Beatriz", "Lucía", "Sofía",
                                "Paula", "Daniela", "Carla", "Lucas", "Pablo", "Leonardo", "Manuel", "Adrián", "Claudia", "Valeria", "Yaretzy"};

    const char apellidos[][30] = {"Gonzalez", "Martinez", "Gimenez", "Duarte", "Herrera", "Cabrera", "Macias", "Torres",
                                  "Muñoz", "Diaz", "Perez", "Fuentes", "Vega", "Silva", "Márquez", "Sanchez", "Ortiz", "Campos",
                                  "Espinoza", "Gutiérrez", "Mares", "Arechar"};

    char trabajadores[10][70];
    int claves[10];
    float salarios[10];

    if (generarTrabajador(nombres, sizeof(nombres) / sizeof(nombres[0]), apellidos, sizeof(apellidos) / sizeof(apellidos[0]), trabajadores, claves, salarios) != 0)
        return 1;

    printf("--CONTROL DEL SISTEMA--");
    do
    {
        mostrarMenu();
        printf("\nIngrese una opcion: ");
        scanf(" %c", &opcionMenu);
        switch (opcionMenu)
        {
        case 'A':
        case 'a':
            for (size_t i = 0; i < 10; i++)
            {
                printf("\nTrabajador %zu: %s\n", i + 1, trabajadores[i]);
                printf("Salario: $%.2f\n", salarios[i]);
                printf("Clave / ID: %d\n", claves[i]);
            }
            break;
        case 'B':
        case 'b':
            buscarRegistro(trabajadores, claves, salarios, 10);
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
    } while (opcionMenu != 'f' && opcionMenu != 'F');

    return 0;
}
