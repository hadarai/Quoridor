//
//  interfejs_przygotowanie.h
//  Quoridor
//
//  Created by Maksymilian Czudziak on 15/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#ifndef interfejs_przygotowanie_h
#define interfejs_przygotowanie_h

#include <stdio.h>
#include <gtk/gtk.h>
#include <stdbool.h>

#include "interfejs_ruch.h"
#include "interfejs_bariery.h"
#include "komunikacja.h"
#include "fifo.h"


bool czy_niepuste_pole(unsigned int i_wiersz, unsigned int j_kolumna);
bool czy_klasc_guzik(unsigned int i_wiersz, unsigned int j_kolumna);

struct dane_bariery
{
    int numer_w_tablicy;
    GtkWidget *tablica_barier[81];
    GtkWidget *tablica_barier_martwych[64];
    PipesPtr potoki;
};

void rysowanie_interfejsu(
                          GtkWidget *wszystkie_guziki[][9],
                          GtkWidget *bariery_pionowe[],
                          GtkWidget *bariery_poziome[],
                          GtkWidget *bariery_martwe[],
                          GtkWidget *siatka_okna,
                          PipesPtr potoki);

void podlaczanie_guzikow(
                         GtkWidget *wszystkie_guziki[][9],
                         //struct pozycja_do_ruchu pozycje_guzikow[9][9],
                         PipesPtr potoki);

void podlaczanie_barier(GtkWidget *bariery_poziome[], GtkWidget *bariery_pionowe[],  GtkWidget *bariery_martwe[], struct dane_bariery dane_barier_poziomych[], struct dane_bariery dane_barier_pionowych[],  PipesPtr potoki);

bool czy_bariera_pionowa(int numer);
bool czy_bariera_pozioma(int numer);
bool czy_bariera_martwa(int numer);
#endif /* interfejs_przygotowanie_h */
