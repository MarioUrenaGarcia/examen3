/**
 * @file
 * @brief
 * @date
 * @author
 */

#include "defGTK.h"

// Funciones ----------------------------------------------------------------------------

/**
 * @brief Añade un nuevo paciente a la cola.
 * @param inicio Doble puntero al inicio de la cola.
 * @param fin Doble puntero al final de la cola.
 * @param nombre Nombre del paciente.
 * @param vacuna Nombre de la vacuna.
 * @return void
 */
extern void enQueue(nodoPaciente **inicio, nodoPaciente **fin, char nombre[], char vacuna[])
{
    nodoPaciente *nuevo;
    nuevo = (nodoPaciente *)malloc(sizeof(nodoPaciente));
    if (nuevo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el nuevo paciente.\n");
        exit(1);
    }
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->vacuna, vacuna);
    nuevo->next = NULL;

    if ((*inicio == NULL) && (*fin == NULL))
    {
        *inicio = nuevo;
        *fin = nuevo;
    }
    else
    {
        (*fin)->next = nuevo;
        *fin = nuevo;
    }

    return;
}

/**
 * @brief Elimina el primer paciente de la cola.
 * @param inicio Doble puntero
 * @param fin Doble puntero al final de la cola.
 * @return void
 */
extern void deQueue(nodoPaciente **inicio, nodoPaciente **fin)
{
    nodoPaciente *borra;

    if ((*inicio == NULL) && (*fin == NULL))
    {
        printf("Error: No hay pacientes en la cola.\n");
    }
    else // Hay más de un nodo
    {
        borra = *inicio;

        // Si solo hay un nodo
        if (*inicio == *fin)
        {
            *inicio = (*inicio)->next;
            *fin = *inicio;
            free(borra);
        }
        else
        {
            *inicio = (*inicio)->next;
            free(borra);
        }
    }

    return;
}

/**
 * @brief Devuelve una cadena en forma de Vacunas en cola: # influenza, # sarampion, # covid
 * @param aux Doble puntero al inicio de la cola.
 * @param reporte Cadena donde se guardará el reporte.
 * @return void
 */
extern void reporteDeFila(nodoPaciente *aux, char *reporte)
{
    int influenza = 0;
    int sarampion = 0;
    int covid = 0;

    while (aux != NULL)
    {
        if (strcmp(aux->vacuna, "influenza") == 0)
        {
            influenza++;
        }
        else if (strcmp(aux->vacuna, "sarampion") == 0)
        {
            sarampion++;
        }
        else if (strcmp(aux->vacuna, "covid") == 0)
        {
            covid++;
        }
        aux = aux->next;
    }

    sprintf(reporte, "Vacunas en cola: %d influenza, %d sarampion, %d covid", influenza, sarampion, covid);

    return;
}