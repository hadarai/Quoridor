#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>

#include "fifo.h"
#include "mechanika_grafu.h"
#include "wydarzenia.h"

#include "interfejs_przygotowanie.h"
#include "interfejs_ruch.h"
#include "interfejs_bariery.h"

#define MAKS_DL_TEKSTU 100

static GtkWidget *okno_gry, *bufor;
static PipesPtr potoki;
static char *moj_id, *twoj_id;

static void przekaz_tekst(GtkWidget *widget, GtkWidget *text);
static gboolean pobierz_tekst(gpointer data);

static void zakoncz_dzialanie(GtkWidget *widget, gpointer data);

void pokazBlad(char *komunikat)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(okno_gry), GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "%s", komunikat);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[])
{
    if ((potoki = initPipes(argc, argv)) == NULL)
        return 1;
    if (argc == 2 && strcmp(argv[1], "A") == 0)
    {
        twoj_id = "B > ";
        moj_id = "A > ";
    }
    else
    {
        moj_id = "B > ";
        twoj_id = "A > ";
    }

    gtk_init(&argc, &argv);

    gchar naglowek[31];
    if (moj_id[0] == 'A')
        sprintf(naglowek, "Gracz Pierwszy");
    else
        sprintf(naglowek, "Gracz Drugi");

    okno_gry = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(okno_gry), naglowek);
    g_signal_connect(G_OBJECT(okno_gry), "destroy", G_CALLBACK(zakoncz_dzialanie), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(okno_gry), 5);

    GtkWidget *siatka_okna = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(siatka_okna), 1);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_okna), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_okna), TRUE);
    gtk_container_add(GTK_CONTAINER(okno_gry), siatka_okna);

    //GtkWidget *button=gtk_button_new_with_label("koniec");

    GtkWidget *wszystkie_guziki[9][9]; //[x][y]
    GtkWidget *wszystkie_bariery[208];

    rysowanie_interfejsu(wszystkie_guziki, wszystkie_bariery, siatka_okna);

    unsigned int pozycja_gracza_x = 4, pozycja_gracza_y = 8;
    char etykieta_gracza[10] = "P";
    gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[pozycja_gracza_x][pozycja_gracza_y]), etykieta_gracza);

    wyswietl_pola_dostepne_do_ruchu(wszystkie_guziki, wszystkie_bariery, siatka_okna, pozycja_gracza_x, pozycja_gracza_y);
    uaktywnij_bariery();

    //GtkWidget *super_boks = gtk_event_box_new ();
    //gtk_widget_set_name(super_boks, "boksik");

    //char literka[10] = "sie";
    //    gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[4][0]), literka);

    //    gtk_grid_attach(GTK_GRID(siatka_okna), super_boks, 10, 1, 1, 1);

    //    gtk_grid_attach(<#GtkGrid *grid#>, <#GtkWidget *child#>, <#gint left#>, <#gint top#>, <#gint width#>, <#gint height#>)

    //gtk_button_set_label(pole4, "P");

    //g_timeout_add(100,pobierz_tekst,NULL);

    gtk_widget_show_all(okno_gry);
    //gtk_widget_grab_focus(okno_gry);
    gtk_main();
    return 0;
}

static void przekaz_tekst(GtkWidget *widget, GtkWidget *text)
{
    gchar wejscie[MAKS_DL_TEKSTU + 5];

    sendStringToPipe(potoki, gtk_entry_get_text(GTK_ENTRY(text)));

    strcpy(wejscie, moj_id);
    strcpy(wejscie + strlen(wejscie), gtk_entry_get_text(GTK_ENTRY(text)));
    strcat(wejscie, "\n");

    gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(bufor), wejscie, -1);
    gtk_entry_set_text(GTK_ENTRY(text), "");
}

static gboolean pobierz_tekst(gpointer data)
{
    gchar wejscie[MAKS_DL_TEKSTU + 5];

    strcpy(wejscie, twoj_id);
    if (getStringFromPipe(potoki, wejscie + strlen(wejscie), MAKS_DL_TEKSTU))
    {
        strcat(wejscie, "\n");
        gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(bufor), wejscie, -1);
    }
    return TRUE;
}

static void zakoncz_dzialanie(GtkWidget *widget, gpointer data)
{
    closePipes(potoki);
    gtk_main_quit();
}

//    bufor = (GtkWidget *)gtk_text_buffer_new (NULL);
//    GtkWidget *text_view = gtk_text_view_new_with_buffer (GTK_TEXT_BUFFER(bufor));
//    gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);
//    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
//    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(text_view), FALSE);

//    GtkWidget *scrolled_window = gtk_scrolled_window_new (NULL, NULL);
//    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC,
//                                  GTK_POLICY_AUTOMATIC);
//    gtk_container_add (GTK_CONTAINER (scrolled_window), text_view);
//    gtk_container_set_border_width (GTK_CONTAINER(scrolled_window), 1);
//    gtk_grid_attach(GTK_GRID(grid), scrolled_window, 0, 0, 60, 20);

//    GtkWidget *text = gtk_entry_new();
//    gtk_entry_set_max_length(GTK_ENTRY(text), MAKS_DL_TEKSTU);
//    gtk_entry_set_text(GTK_ENTRY(text), "");
//    g_signal_connect(G_OBJECT(text), "activate",G_CALLBACK(przekaz_tekst),(gpointer) text);
//    gtk_grid_attach(GTK_GRID(grid), text, 0, 20, 60, 1);
