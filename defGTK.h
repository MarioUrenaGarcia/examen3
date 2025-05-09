/**
 * @file defGTK.h
 * @brief Header file de appGTK.c
 * @date 09/05/2025
 * @author Mario Ureña García, Alfredo Emiliano Cisneros Cervantes, Ricardo Ponce de León Vargas
 */

// Bibliotecas --------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk-2.0/gtk/gtk.h>

// Definiciones -------------------------------------------------------------------------
#define RESET "\x1b[0m"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"

// Declaración de estructuras -------------------------------------------------------------

// Estructura para almacenar la información de un paciente de una cola FIFO
struct paciente
{
    char nombre[30];
    char vacuna[30];
    struct paciente *next;
};
typedef struct paciente nodoPaciente;
struct interfazPrincipal
{
    // Ventana principal---------------
    GtkWidget *windowHome;
    GtkWidget *mainboxHome;

    // 2 cajas horizontales
    GtkWidget *pacienteBox;
    GtkWidget *vacunaBox;

    // Paciente
    GtkWidget *pacienteLabel;
    GtkWidget *pacienteEntry;

    // Vacuna
    GtkWidget *vacunaLabel;
    GtkWidget *vacunaEntry;

    // Botones
    GtkWidget *ingresarPacienteButton;
    GtkWidget *vacunarPacienteButton;
    GtkWidget *reportarFilaButton;

    // Separadores
    GtkWidget *separator1;
    GtkWidget *separator2;

    // Notificaciones
    GtkWidget *notificacionLabel;

    // Variables para procesos de C
    nodoPaciente *inicio;
    nodoPaciente *fin;
};
typedef struct interfazPrincipal inter;
