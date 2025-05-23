/**
 *
 * @file appGTK.c
 * @brief Programa que permite la atención de una fila de personas que se van a vacunar.
 * @details App gráfica que permite dar de alta pacientes a una cola FIFO, por su nombre corto, vacuna
 *          (influenza, sarampion o covid) y permite atenderlos de la lista (vacunarlos/borrar).
 *          También debe permitir generar un reporte de cuantos pacientes por vacuna hay en la cola.
 *          A) Interfaz gráfica: Interfaz en GTK:
 *             - Una ventana con dos campos de entrada: Nombre y tipo de vacuna.
 *             - Un botón para agregar pacientes a la cola.
 *             - Un botón para atender un paciente de la cola (vacunarlo).
 *             - Un botón para generar un reporte de la fila de pacientes.
 *             - Label para mostrar el reporte.
 *          B) Agregar Paciente y Aplicar vacuna: Los respectivos callbacks para cada botón para que,
 *             con los datos ingresados en los campos de entrada (paciente y vacuna), la app de de alta o baja
 *             al paciente en la cola FIFO si se oprimen los botones respectivos.
 *          C) Reportar la cola: Respectivo callback para que, con los datos ingresados en la cola FIFO, calcule
 *             cuantos pacientes hay en ese momento en la cola para cada vacuna si se oprime el botón. Muestre
 *             en un label de la app.
 * @date 09/05/2025
 * @author Mario Ureña García, Alfredo Emiliano Cisneros Cervantes, Ricardo Ponce de León Vargas
 *
 */

#include "defGTK.h"

// Prototipos de C -----------------------------------------------------------------------
// Prototipos de GTK ---------------------------------------------------------------------
void closeTheApp(GtkWidget *widget, gpointer llavero);
void ingresarPaciente(GtkWidget *button, gpointer llavero);
void reportarFila(GtkWidget *button, gpointer llavero);
void vacunarPaciente(GtkWidget *button, gpointer llavero);
// Main ----------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  // Variables C -------------------------------------------------------------------------
  // Variables Gtk -----------------------------------------------------------------------
  // Super struct-------------------------------------------------------------------------
  inter principal;
  // Procesos C --------------------------------------------------------------------------
  printf(YELLOW "\n\nBienvenido a la aplicación de vacunación\n\n" RESET);
  // Inicializar variables
  principal.inicio = NULL;
  principal.fin = NULL;
  // Procesos GTK ------------------------------------------------------------------------
  /* 1. Inicializar el ambiente */
  gtk_init(&argc, &argv);

  /*2. Creación de los objetos */
  /*2b. Ventana principal y atributos*/
  principal.windowHome = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(principal.windowHome), 200, 400);
  gtk_window_set_title(GTK_WINDOW(principal.windowHome), "Vacunacion");
  gtk_container_set_border_width(GTK_CONTAINER(principal.windowHome), 10);
  /*2b. Contenedores*/
  principal.mainboxHome = gtk_vbox_new(FALSE, 5);
  principal.pacienteBox = gtk_hbox_new(FALSE, 5);
  principal.vacunaBox = gtk_hbox_new(FALSE, 5);
  /*2b. Etiquetas*/
  principal.pacienteLabel = gtk_label_new("Paciente:");
  principal.vacunaLabel = gtk_label_new("Vacuna:");
  principal.notificacionLabel = gtk_label_new("Notificaciones");
  /*2b. Botones*/
  principal.ingresarPacienteButton = gtk_button_new_with_label("Ingresar Paciente a cola");
  principal.vacunarPacienteButton = gtk_button_new_with_label("Vacunar Paciente");
  principal.reportarFilaButton = gtk_button_new_with_label("Reportar fila de pacientes");
  /*2b. Separadores*/
  principal.separator1 = gtk_hseparator_new();
  principal.separator2 = gtk_hseparator_new();
  /*2b. Crear campo de entrada*/
  principal.pacienteEntry = gtk_entry_new();
  principal.vacunaEntry = gtk_entry_new();

  /*3. Registro de los Callbacks */
  g_signal_connect(GTK_OBJECT(principal.windowHome), "delete-event", GTK_SIGNAL_FUNC(closeTheApp), &principal);
  g_signal_connect(GTK_OBJECT(principal.ingresarPacienteButton), "clicked", GTK_SIGNAL_FUNC(ingresarPaciente), &principal);
  g_signal_connect(GTK_OBJECT(principal.reportarFilaButton), "clicked", GTK_SIGNAL_FUNC(reportarFila), &principal);
  g_signal_connect(GTK_OBJECT(principal.vacunarPacienteButton), "clicked", GTK_SIGNAL_FUNC(vacunarPaciente), &principal);
  /* 4. Define jerarquía de instancias (pack the widgets)*/
  // Caja de pacientes
  gtk_box_pack_start_defaults(GTK_BOX(principal.pacienteBox), principal.pacienteLabel);
  gtk_box_pack_start_defaults(GTK_BOX(principal.pacienteBox), principal.pacienteEntry);
  // Caja de vacunas
  gtk_box_pack_start_defaults(GTK_BOX(principal.vacunaBox), principal.vacunaLabel);
  gtk_box_pack_start_defaults(GTK_BOX(principal.vacunaBox), principal.vacunaEntry);
  // Caja principal
  gtk_box_pack_start_defaults(GTK_BOX(principal.mainboxHome), principal.pacienteBox);
  gtk_box_pack_start_defaults(GTK_BOX(principal.mainboxHome), principal.vacunaBox);
  gtk_box_pack_start_defaults(GTK_BOX(principal.mainboxHome), principal.separator1);
  gtk_box_pack_start_defaults(GTK_BOX(principal.mainboxHome), principal.ingresarPacienteButton);
  gtk_box_pack_start_defaults(GTK_BOX(principal.mainboxHome), principal.vacunarPacienteButton);
  gtk_box_pack_start_defaults(GTK_BOX(principal.mainboxHome), principal.reportarFilaButton);
  gtk_box_pack_start_defaults(GTK_BOX(principal.mainboxHome), principal.separator2);
  gtk_box_pack_start_defaults(GTK_BOX(principal.mainboxHome), principal.notificacionLabel);
  // Ventana principal
  gtk_container_add(GTK_CONTAINER(principal.windowHome), principal.mainboxHome);

  /* 5. Mostrar los widgets */
  gtk_widget_show_all(principal.windowHome);
  /* 6. El programa se queda en loop */
  gtk_main();

  return 0;
}
