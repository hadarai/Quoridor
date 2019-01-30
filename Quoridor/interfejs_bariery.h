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

struct dane_bariery
{
    unsigned int x;
    unsigned int y;
    GtkWidget *tablica[81];
    PipesPtr potoki;
};

//void uaktywnij_bariery(GtkWidget *bariery[], const unsigned short int ilosc);
//void stawianie_bariery(GtkWidget *widget, struct dane_bariery *bariera);
void stawianie_bariery(GtkWidget *widget, struct dane_bariery *bariera);

#endif /* interfejs_bariery_h */
