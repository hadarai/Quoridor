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
#include <stdbool.h>

#include "komunikacja.h"
#include "mechanika_grafu.h"
#include "interfejs_bariery.h"
#include "koniec.h"

struct pozycja
{
    int x;
    int y;
};

struct pozycja_do_ruchu
{
    int x;
    int y;
    GtkWidget *tablica[9][9];
    PipesPtr potoki;
};

void ruch(GtkWidget *widget, struct pozycja_do_ruchu *pozycja);

bool czy_to_bedzie_w_prawo(int pozycja_guzika_x, int pozycja_guzika_y, int pozycja_gracza_x, int pozycja_gracza_y, int pozycja_przeciwnika_x, int pozycja_przeciwnika_y);
bool czy_to_bedzie_w_lewo(int pozycja_guzika_x, int pozycja_guzika_y, int pozycja_gracza_x, int pozycja_gracza_y, int pozycja_przeciwnika_x, int pozycja_przeciwnika_y);
bool czy_to_bedzie_w_gore(int pozycja_guzika_x, int pozycja_guzika_y, int pozycja_gracza_x, int pozycja_gracza_y, int pozycja_przeciwnika_x, int pozycja_przeciwnika_y);
bool czy_to_bedzie_w_dol(int pozycja_guzika_x, int pozycja_guzika_y, int pozycja_gracza_x, int pozycja_gracza_y, int pozycja_przeciwnika_x, int pozycja_przeciwnika_y);

void wyswietl_przeciwnika(GtkWidget *wszystkie_guziki[][9], unsigned int x, unsigned int y);
void wyswietl_gracza(GtkWidget *wszystkie_guziki[][9], unsigned int x, unsigned int y);

void ruch_przeciwnika(int x, int y);

#endif /* interfejs_ruch_h */
