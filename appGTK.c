/**
 *
 * @file Nombre del archivo
 * @brief Breve Descripción
 * @details Descripción extendida
 * @date
 * @author Mario Ureña García
 *
 */

#include "defGTK.h"

// Prototipos de C -----------------------------------------------------------------------
// Prototipos de GTK ---------------------------------------------------------------------
void closeTheApp(GtkWidget *widget, gpointer llavero);
void ingresarPaciente(GtkWidget *buttons, gpointer llavero);
void reportarFila(GtkWidget *widget, gpointer llavero);
// Main ----------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  // Variables C -------------------------------------------------------------------------
  // Variables Gtk -----------------------------------------------------------------------
  // Super struct-------------------------------------------------------------------------
  inter principal;
  // Procesos C --------------------------------------------------------------------------
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
