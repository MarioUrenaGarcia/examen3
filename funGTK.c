/**
 * @file
 * @brief
 * @date
 * @author
 */

#include "defGTK.h"

void deQueue(nodoPaciente **inicio, nodoPaciente **fin);
void enQueue(nodoPaciente **inicio, nodoPaciente **fin, char nombre[], char vacuna[]);
void reporteDeFila(nodoPaciente *aux, char *reporte);
// Funciones ----------------------------------------------------------------------------

/**
 * @brief
 * @date
 * @author
 * @param
 * @return
 * @Ejemplo
 */
extern void closeTheApp(GtkWidget *widget, gpointer llavero)
{
    gtk_main_quit();
    return;
}

extern void ingresarPaciente(GtkWidget *button, gpointer llavero)
{
    inter *principal = (inter *)llavero;
    char nombre[30];
    char vacuna[30];

    strcpy(nombre, gtk_entry_get_text(GTK_ENTRY(principal->pacienteEntry)));
    strcpy(vacuna, gtk_entry_get_text(GTK_ENTRY(principal->vacunaEntry)));

    // Si la longitud de alguna de las cadenas es 0, no se permite el ingreso
    if (strlen(nombre) == 0 || strlen(vacuna) == 0)
    {
        gtk_label_set_text(GTK_LABEL(principal->notificacionLabel), "Error: Nombre o vacuna vacíos");
    }
    // Si el nombre de la vacuna no es influenza, sarampion o covid
    else if (strcmp(vacuna, "influenza") != 0 && strcmp(vacuna, "sarampion") != 0 && strcmp(vacuna, "covid") != 0)
    {
        gtk_label_set_text(GTK_LABEL(principal->notificacionLabel), "Error: Vacuna no válida");
    }
    else
    {
        enQueue(&principal->inicio, &principal->fin, nombre, vacuna);
        gtk_label_set_text(GTK_LABEL(principal->notificacionLabel), "Paciente ingresado a la cola");
    }

    // Limpiar los campos de entrada
    gtk_entry_set_text(GTK_ENTRY(principal->pacienteEntry), "");
    gtk_entry_set_text(GTK_ENTRY(principal->vacunaEntry), "");

    return;
}

extern void reportarFila(GtkWidget *widget, gpointer llavero)
{
    inter *principal = (inter *)llavero;
    char reportePacientes[120];

    reporteDeFila(principal->inicio, reportePacientes);
    gtk_label_set_text(GTK_LABEL(principal->notificacionLabel), reportePacientes);

    return;
}