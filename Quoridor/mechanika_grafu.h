//
//  mechanika.h
//  Quoridor
//
//  Created by Maksymilian Czudziak on 14/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#ifndef mechanika_grafu_h
#define mechanika_grafu_h

#include <stdio.h>
#include <stdbool.h>
#include "gtk/gtk.h"

void uzupelnij_graf(bool graf[][81]);

bool czy_sasiaduja(int x, int y);
//uzupelnij_graf(graf_polaczen_pol);

bool czy_moge_przejsc_na_grafie(int x_gracza, int y_gracza, int x_dokad, int y_dokad);

void przerwij_polaczenie_pionowe(int numer_bariery_pionowej);
void przerwij_polaczenie_poziome(int numer_bariery_poziomej);

void przywroc_polaczenie_pionowe(int numer_bariery_pionowej);
void przywroc_polaczenie_poziome(int numer_bariery_poziomej);

bool czy_mogę_postawic_bariere_poziomo(int numer_bariery_poziomej);
bool czy_mogę_postawic_bariere_pionowo(int numer_bariery_pionowej);

bool DFS(void);

void miedzy_kim_jestes_pion(int numer_bariery);
void miedzy_kim_jestes_poziom(int numer_bariery);


void wypisz_graf(bool graf[][81]);

#endif /* mechanika_h */
