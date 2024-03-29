//
//  main.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 14/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "fifo.h"
#include "mechanika_grafu.h"
#include "komunikacja.h"

#include "interfejs_przygotowanie.h"
#include "interfejs_ruch.h"
#include "interfejs_bariery.h"

#include "koniec.h"

#define MAKS_DL_TEKSTU 100

GtkWidget *okno_gry;
pipes_pointer potoki;
static char *moj_id, *twoj_id;
char wiadomosc[10];
bool przegralem = false;
unsigned int ilosc_barier = 10;

void zakoncz_dzialanie(GtkWidget *widget, gpointer data);

const unsigned short int ilosc_barier_pionowych = 72;
const unsigned short int ilosc_barier_poziomych = 72;
const unsigned short int ilosc_barier_martwych = 64;

bool moj_ruch = false;
struct pozycja pozycja_gracza;
struct pozycja pozycja_przeciwnika;
bool graf_polaczen_pol[81][81];

GtkWidget *guziki[9][9]; //[x][y]

GtkWidget *bariery_pionowe[ilosc_barier_pionowych];
GtkWidget *bariery_poziome[ilosc_barier_poziomych];
GtkWidget *bariery_martwe[ilosc_barier_martwych];

struct pozycja_do_ruchu pozycje_guzikow[9][9];
struct dane_bariery dane_barier_poziomych[72];
struct dane_bariery dane_barier_pionowych[72];

int main(int argc, char *argv[])
{

    if ((potoki = initPipes(argc, argv)) == NULL)
        return 1;
    if (argc == 2 && strcmp(argv[1], "A") == 0)
    {
        moj_id = "A";
        twoj_id = "B";
        moj_ruch = true;
    }
    else
    {
        moj_id = "B";
        twoj_id = "A";
        moj_ruch = false;
    }

    gtk_init(&argc, &argv);

    gchar naglowek[31];
    if (moj_id[0] == 'A')
    {
        sprintf(naglowek, "Gracz Pierwszy");
    }
    else
    {
        sprintf(naglowek, "Gracz Drugi");
    }

    okno_gry = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(okno_gry), naglowek);
    g_signal_connect(G_OBJECT(okno_gry), "destroy", G_CALLBACK(zakoncz_dzialanie), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(okno_gry), 5);

    GtkWidget *siatka_okna = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(siatka_okna), 1);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_okna), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_okna), TRUE);
    gtk_container_add(GTK_CONTAINER(okno_gry), siatka_okna);

    pozycja_gracza.x = 4;
    pozycja_gracza.y = 8;
    pozycja_przeciwnika.x = 4;
    pozycja_przeciwnika.y = 0;

    uzupelnij_graf(graf_polaczen_pol);

    rysowanie_interfejsu(guziki, bariery_pionowe, bariery_poziome, bariery_martwe, siatka_okna, potoki);

    podlaczanie_guzikow(guziki, potoki);
    podlaczanie_barier(bariery_poziome, bariery_pionowe, bariery_martwe, dane_barier_poziomych, dane_barier_pionowych, potoki);

    wyswietl_przeciwnika(guziki, pozycja_przeciwnika.x, pozycja_przeciwnika.y);
    wyswietl_gracza(guziki, pozycja_gracza.x, pozycja_gracza.y);

    g_timeout_add(100, odczytaj_wiadmosc, potoki);

    gtk_widget_show_all(okno_gry);
    gtk_main();
    return 0;
}

void zakoncz_dzialanie(GtkWidget *widget, gpointer data)
{
    close_pipes(potoki);
    gtk_main_quit();
}

void show_error(char *komunikat)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(okno_gry), GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "%s", komunikat);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
