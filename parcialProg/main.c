#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
} eVacuna;
float aplicarAumento(float precio);
int reemplazarCaracteres(char* cadena, char caracter, char segunCaracter);
int ordenarArray(eVacuna* lista, int tam);

int main()
{
    float precio = 100;
    float aumento;
    char cadena[20] = "avispa";
    char primerCaracter = 'a';
    char segundoCaracter = 'c';
    eVacuna lista[TAM] = {
    {1000, "Ivan", 'a', 19.23},
    {1001, "Alicia", 'a', 18.15},
    {1002, "Pedro", 'd', 20.84},
    {1003, "Carlos", 'a', 25.14}
    };

    printf("Precio: %.2f\n", precio);
    aumento = aplicarAumento(precio);
    printf("Aumento: %.2f\n", aumento);
    printf("Palabra original: %s\n", cadena);
    reemplazarCaracteres(cadena, primerCaracter, segundoCaracter);
    printf("Reemplazar caracter \"%c\" por el caracter \"%c\": %s\n\n", primerCaracter, segundoCaracter, cadena);
    ordenarArray(lista, TAM);
    printf("Ordenar por tipo, ante igualdad de tipo ordenarse por efectividad creciente");
    for(int i=0; i<TAM; i++)
    {
        printf("Id: %4d   |    Nombre: %10s   |  Tipo: %c   |  Efectividad: %5.2f \n", lista[i].id, lista[i].nombre, lista[i].tipo, lista[i].efectividad);
    }
    printf("\n");
    system("pause");
    return 0;
}

float aplicarAumento(float precio)
{
    float aumento;
    float resultado = -1;

    if(precio > 0)
    {
        aumento = precio * 0.05;
        resultado = precio + aumento;
    }

    return resultado;
}

int reemplazarCaracteres(char* cadena, char caracter, char segunCaracter)
{
    char aux[100];
    int contador = 0;
    int i=0;


    if(cadena)
    {
        strcpy(aux, cadena);
        while(cadena[i] != '\0')
        {
            if(cadena[i] == caracter)
            {
                cadena[i] = segunCaracter;
                contador++;
            }
            i++;
        }

    }
    return contador;
}

int ordenarArray(eVacuna* lista, int tam)
{
    int todoOk = 0;
    eVacuna aux;
    if(lista)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((lista[i].tipo != lista[j].tipo) && (lista[i].tipo > lista[j].tipo) ||
                    (lista[i].tipo == lista[j].tipo && (lista[i].efectividad < lista[j].efectividad)))
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}
