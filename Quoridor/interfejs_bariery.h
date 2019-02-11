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

struct bomba
{
    int liczba;
};

//struct dane_bariery
//{
//    int numer_w_tablicy;
//    GtkWidget *tablica_barier[81];
//    GtkWidget *tablica_barier_martwych[64];
//    PipesPtr potoki;
//};

//void stawianie_bariery(GtkWidget *widget, struct dane_bariery *bariera);
//void stawianie_bariery(GtkWidget *widget, struct dane_bariery *bariera);

void stawianie_bariery_poziomej(GtkWidget *widget, struct bomba *dane_smieszne);
void stawianie_bariery_pionowej(GtkWidget *widget, struct bomba *dane_smieszne);

void bariera_pionowa(GtkWidget *widget);
void bariera_martwa(GtkWidget *widget);
#endif /* interfejs_bariery_h */
