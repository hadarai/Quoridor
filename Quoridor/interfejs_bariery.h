//
//  interfejs_bariery.h
//  Quoridor
//
//  Created by Maksymilian Czudziak on 19/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#ifndef interfejs_bariery_h
#define interfejs_bariery_h

#include <stdio.h>
#include "gtk/gtk.h"
#include "interfejs_przygotowanie.h"
#include "fifo.h"
#include "komunikacja.h"

//struct dane_bariery
//{
//    int numer_w_tablicy;
//    GtkWidget *tablica_barier[81];
//    GtkWidget *tablica_barier_martwych[64];
//    PipesPtr potoki;
//};

extern bool moj_ruch;



void stawianie_bariery_poziomej(GtkWidget *widget, GdkEvent *pomocniczy, struct dane_bariery *dane_tej_bariery);
void stawianie_bariery_pionowej(GtkWidget *widget, GdkEvent *pomocniczy, struct dane_bariery *dane_tej_bariery);

void ustaw_grafike_bariery_poziomej(GtkWidget *bariera);
void ustaw_grafike_bariery_pionowej(GtkWidget *bariera);
void ustaw_grafike_bariery_martwej(GtkWidget *bariera);

void przeciwnik_polozyl_bariere(int numer_bariery, int czy_pionowa);

#endif /* interfejs_bariery_h */
