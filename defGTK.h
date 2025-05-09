/**
 * @file
 * @brief
 * @date
 * @author
 */

// Bibliotecas --------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk-2.0/gtk/gtk.h>

// Definiciones -------------------------------------------------------------------------
#define RESET "\x1b[0m"

#define RED "\x1b[31m"
#define WHITE "\x1B[37m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define CYAN "\x1b[36m"
#define MAGENTA "\x1b[35m"
#define ORANGE "\x1B[38;2;255;128;0m"
#define ROSE "\x1B[38;2;255;151;203m"
#define GRAY "\x1B[38;2;176;174;174m"
#define BLACK "\x1B[30m"

#define BG_RED "\x1B[41m"
#define BG_WHITE "\x1B[47m"
#define BG_BLUE "\x1B[44m"
#define BG_GREEN "\x1B[42m"
#define BG_YELLOW "\x1B[43m"
#define BG_CYAN "\x1B[46m"
#define BG_MAGENTA "\x1B[45m"
#define BG_ORANGE "\x1B[48;2;255;128;0m"
#define BG_ROSE "\x1B[48;2;255;151;203m"
#define BG_GRAY "\x1B[48;2;176;174;174m"
#define BG_BLACK "\x1B[40m"
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
    GTtkWidget *windowHome;
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

    // Notificaciones
    GtkWidget *notificacionLabel;
};
typedef struct interfaz inter;
