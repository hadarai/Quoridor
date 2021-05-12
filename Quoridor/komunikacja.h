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
#include "interfejs_bariery.h"
#include "koniec.h"

void wyslij_ruch(int x_gracza, int y_gracza, PipesPtr potoki);
void wyslij_bariere(int numer_bariery, int czy_pion, PipesPtr potoki);
void wyslij_zwyciestwo(void);

gboolean odczytaj_wiadmosc(gpointer data);

#endif /* komunikacja_h */
