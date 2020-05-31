#include<stdio.h>
#include<vte/vte.h>

int main(int argc, char *argv[]){
  GtkWidget *window, *terminal;

  /*  Initializing the window and terminal */
  gtk_init(&argc, &argv);
  terminal = vte_terminal_new();
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Been's Term");

  /*  Start a new shell */
  gchar **envi = g_get_environ();
  /* gchar **command = (gchar*[]){g_strdup(g_environ_getenv(envi, "SHELL")), NULL}; */

  /* gchar **command = (gchar*[]){g_strdup("/bin/sh"), NULL}; */
  gchar **command = (gchar*[]){g_strdup("./mashell"), NULL};

  printf("%s", *command);

  g_strfreev(envi);
  /* terminal is a GtkWidget object, but the argument requires terminal object,
     hence using wrapper function VTE_TERMINAL for converion (sortof) */
  vte_terminal_spawn_async(VTE_TERMINAL(terminal),
                           VTE_PTY_DEFAULT, /*  start shell in default way */
                           NULL,            /*  keeping working directory NULL */
                           command,         /*  extracted above */
                           NULL,            /*  environment */
                           0,               /*  flags */
                           NULL, NULL,       /*  child  */
                           NULL,            /*  child pid */
                           -1,              /*  timeout */
                           NULL,            /*  cancellable */
                           NULL,            /*  callback */
                           NULL             /*  userdata */ );
  /* Connect some signals */
  g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
  g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);

  /* Put widgets together and run the main loop */
  gtk_container_add(GTK_CONTAINER(window), terminal);
  gtk_widget_show_all(window);
  gtk_main();
}

