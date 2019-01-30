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


//struct pozycja
//{
//    unsigned int x;
//    unsigned int y;
//};

bool czy_niepuste_pole(unsigned int i_wiersz, unsigned int j_kolumna);
bool czy_klasc_guzik(unsigned int i_wiersz, unsigned int j_kolumna);

void rysowanie_interfejsu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna, PipesPtr potoki);

void podlacz_bariere(GtkWidget *bariera, unsigned int x, unsigned int y, PipesPtr potoki);

void podlaczanie_guzikow(GtkWidget *wszystkie_guziki[][9], struct pozycja_do_ruchu pozycje_guzikow[][9], PipesPtr potoki);
//void podlaczanie_barier(GtkWidget *wszyskie_bariery[], PipesPtr potoki);

#endif /* interfejs_przygotowanie_h */
