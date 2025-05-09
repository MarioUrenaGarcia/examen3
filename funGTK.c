/**
 * @file funGTK.c
 * @brief Funciones de GTK para la aplicación de vacunación
 * @date 09/05/2025
 * @author Mario Ureña García, Alfredo Emiliano Cisneros Cervantes, Ricardo Ponce de León Vargas
 */

#include "defGTK.h"

void deQueue(nodoPaciente **inicio, nodoPaciente **fin);
void enQueue(nodoPaciente **inicio, nodoPaciente **fin, char nombre[], char vacuna[]);
void reporteDeFila(nodoPaciente *aux, char *reporte);
// Funciones ----------------------------------------------------------------------------

/**
 * @brief Función para cerrar la aplicación.
 * @param widget Widget que se está utilizando.
 * @param llavero Puntero a la estructura de la interfaz.
 * @return void
 * @details Esta función se llama cuando se cierra la ventana principal de la aplicación.
 */
extern void closeTheApp(GtkWidget *widget, gpointer llavero)
{
    gtk_main_quit();
    return;
}

/**
 * @brief Función para ingresar un paciente a la cola.
 * @param button Botón que se ha presionado.
 * @param llavero Puntero a la estructura de la interfaz.
 * @return void
 * @details Esta función se llama cuando se presiona el botón de ingresar paciente.
 */
extern void ingresarPaciente(GtkWidget *button, gpointer llavero)
{
    inter *pt = (inter *)llavero;
    char nombre[30];
    char vacuna[30];

    strcpy(nombre, gtk_entry_get_text(GTK_ENTRY(pt->pacienteEntry)));
    strcpy(vacuna, gtk_entry_get_text(GTK_ENTRY(pt->vacunaEntry)));

    // Si la longitud de alguna de las cadenas es 0, no se permite el ingreso
    if (strlen(nombre) == 0 || strlen(vacuna) == 0)
    {
        gtk_label_set_text(GTK_LABEL(pt->notificacionLabel), "Error: Nombre o vacuna vacíos");
    }
    // Si el nombre de la vacuna no es influenza, sarampion o covid
    else if (strcmp(vacuna, "influenza") != 0 && strcmp(vacuna, "sarampion") != 0 && strcmp(vacuna, "covid") != 0)
    {
        gtk_label_set_text(GTK_LABEL(pt->notificacionLabel), "Error: Vacuna no válida");
    }
    else
    {
        enQueue(&pt->inicio, &pt->fin, nombre, vacuna);
        gtk_label_set_text(GTK_LABEL(pt->notificacionLabel), "Paciente ingresado a la cola");
    }

    // Limpiar los campos de entrada
    gtk_entry_set_text(GTK_ENTRY(pt->pacienteEntry), "");
    gtk_entry_set_text(GTK_ENTRY(pt->vacunaEntry), "");

    return;
}

/**
 * @brief Función para reportar la fila de pacientes.
 * @param button Botón que se ha presionado.
 * @param llavero Puntero a la estructura de la interfaz.
 * @return void
 * @details Esta función se llama cuando se presiona el botón de reportar fila.
 */
extern void reportarFila(GtkWidget *button, gpointer llavero)
{
    inter *pt = (inter *)llavero;
    char reportePacientes[120];

    reporteDeFila(pt->inicio, reportePacientes);
    gtk_label_set_text(GTK_LABEL(pt->notificacionLabel), reportePacientes);

    return;
}

/**
 * @brief Función para vacunar a un paciente.
 * @param button Botón que se ha presionado.
 * @param llavero Puntero a la estructura de la interfaz.
 * @return void
 * @details Esta función se llama cuando se presiona el botón de vacunar paciente.
 */
extern void vacunarPaciente(GtkWidget *button, gpointer llavero)
{
    inter *pt = (inter *)llavero;

    // Si la cola está vacía
    if (pt->inicio == NULL && pt->fin == NULL)
    {
        gtk_label_set_text(GTK_LABEL(pt->notificacionLabel), "Error: No hay pacientes en la cola");
    }
    // Si la cola no está vacía
    else
    {
        deQueue(&pt->inicio, &pt->fin);
        gtk_label_set_text(GTK_LABEL(pt->notificacionLabel), "Paciente vacunado");
    }

    return;
}