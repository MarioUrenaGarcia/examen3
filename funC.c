/**
 * @file
 * @brief
 * @date
 * @author
 */

#include "defGTK.h"

// Funciones ----------------------------------------------------------------------------

/**
 * @brief
 * @date
 * @author
 * @param
 * @return
 * @Ejemplo
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