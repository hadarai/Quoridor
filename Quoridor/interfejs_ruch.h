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

struct dane_o_ruchu
{
    unsigned int na_x;
    unsigned int na_y;
    unsigned int z_x;
    unsigned int z_y;
    //GtkWidget *wszystkie_guziki[9][9];
};


void wyswietl_pola_dostepne_do_ruchu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna, unsigned int x, unsigned int y);

void ruch(struct dane_o_ruchu *dane);


#endif /* interfejs_ruch_h */
