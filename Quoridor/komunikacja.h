//
//  komunikacja.h
//  Quoridor
//
//  Created by Maksymilian Czudziak on 15/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#ifndef komunikacja_h
#define komunikacja_h

#include <stdio.h>

#include "gtk/gtk.h"
#include "fifo.h"
#include "interfejs_ruch.h"


void wyslij_ruch(int x_gracza, int y_gracza, PipesPtr potoki);
gboolean odczytaj_wiadmosc(gpointer data);

void stalo_sie(void);
void stalo_sie_bariera(void);
void pole_do_ruchu(void);
//void ruch(struct dane_o_ruchu dane);
#endif /* komunikacja_h */
