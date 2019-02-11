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

//struct dane_bariery
//{
//    int numer_w_tablicy;
//    GtkWidget *tablica_barier[81];
//    GtkWidget *tablica_barier_martwych[64];
//    PipesPtr potoki;
//};

extern bool moj_ruch;

//bool czy_bariera_juz_tu_stoi_pion[72];
//bool czy_bariera_juz_tu_stoi_poziom[72];

void stawianie_bariery_poziomej(GtkWidget *widget, GdkEvent *pomocniczy, struct dane_bariery *super_dane);
void stawianie_bariery_pionowej(GtkWidget *widget, GdkEvent *pomocniczy, struct dane_bariery *super_dane);

void bariera_pozioma_przedstaw(GtkWidget *widget);
void bariera_pionowa_przedstaw(GtkWidget *widget);
void bariera_martwa_przedstaw(GtkWidget *widget);

#endif /* interfejs_bariery_h */
