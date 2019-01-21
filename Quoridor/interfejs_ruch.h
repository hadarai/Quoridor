//
//  interfejs_ruch.h
//  Quoridor
//
//  Created by Maksymilian Czudziak on 16/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#ifndef interfejs_ruch_h
#define interfejs_ruch_h

#include <stdio.h>
#include <gtk/gtk.h>
#include "wydarzenia.h"

struct dane_o_ruchu_w_prawo
{
    int na_x;
    int na_y;
    GtkWidget *tablica[9][9];
};

struct dane_o_ruchu_w_lewo
{
    int na_x;
    int na_y;
    GtkWidget *tablica[9][9];
};

struct dane_o_ruchu_w_dol
{
    int na_x;
    int na_y;
    GtkWidget *tablica[9][9];
};

struct dane_o_ruchu_w_gore
{
    int na_x;
    int na_y;
    GtkWidget *tablica[9][9];
};

static void ruch_prawo(GtkWidget *widget, struct dane_o_ruchu_w_prawo *dane);
static void ruch_lewo(GtkWidget *widget, struct dane_o_ruchu_w_lewo *dane);
static void ruch_dol(GtkWidget *widget, struct dane_o_ruchu_w_dol *dane);
static void ruch_gora(GtkWidget *widget, struct dane_o_ruchu_w_gore *dane);

void wyswietl_pola_dostepne_do_ruchu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna, unsigned int x, unsigned int y);

#endif /* interfejs_ruch_h */
