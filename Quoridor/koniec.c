//
//  koniec.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 11/02/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "koniec.h"

void zwyciestwo(void)
{
    extern bool przegralem;
    extern bool moj_ruch;
    moj_ruch = false;
    przegralem = true;
    extern GtkWidget *okno_gry;

    wyslij_zwyciestwo();

    GtkWidget *wKoniec = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(wKoniec), "Koniec Gry");
    g_signal_connect(G_OBJECT(wKoniec), "destroy", G_CALLBACK(zakoncz_dzialanie), NULL);
    gtk_window_set_default_size(GTK_WINDOW(wKoniec), 450, 200);
    GtkWidget *Label = gtk_label_new("Wygrales!!! :D\nGratulacje!");
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);
    gtk_container_add(GTK_CONTAINER(wKoniec), Label);
    gtk_widget_show_all(wKoniec);
}

void przegrana(void)
{
    extern bool przegralem;
    extern bool moj_ruch;
    moj_ruch = false;
    if (przegralem)
        return;
    przegralem = true;
    extern GtkWidget *okno_gry;

    wyslij_zwyciestwo();

    GtkWidget *wKoniec = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(wKoniec), "Koniec Gry");
    g_signal_connect(G_OBJECT(wKoniec), "destroy", G_CALLBACK(zakoncz_dzialanie), NULL);
    gtk_window_set_default_size(GTK_WINDOW(wKoniec), 450, 200);

    GtkWidget *Label = gtk_label_new("Niestety przegrales :(\nOpracuj lepsza strategie ;)");
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);
    gtk_container_add(GTK_CONTAINER(wKoniec), Label);
    gtk_widget_show_all(wKoniec);
}
