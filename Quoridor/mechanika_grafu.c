//
//  mechanika.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 14/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "mechanika_grafu.h"

void uzupelnij_graf(bool graf[][81])
{
    
    for(int i=0;i<81;i++)
    {
        for (int j = 0; j<81; j++)
        {
            if(czy_sasiaduja(i,j))
            {
                graf[i][j] = 1;
            }
        }
    }
    
}

bool czy_sasiaduja(int x, int y)
{
    if(x == y) return true;
    // czy z x da sie dojsc w 1 ruchu do y
    //sasiad z lewej
    if (y-1 == x) {
        return true;
    }
    //sasiad z prawej
    if (y+1 == x) {
        return true;
    }
    //sasiad z gory
    if (y-9 == x) {
        return true;
    }
    //sasiad z dolu
    if (y+9 == x) {
        return true;
    }
    return false;
}

bool czy_moge_przejsc_na_grafie(int x_gracza, int y_gracza, int x_dokad, int y_dokad)
{
    extern bool graf_polaczen_pol[81][81];
    int numer_pola_gracza = ((y_gracza * 9) + x_gracza);
    int numer_pola_dokad = ((y_dokad * 9) + x_dokad);
    
//    printf("%d %d", numer_pola_gracza, numer_pola_dokad );
    if(graf_polaczen_pol[numer_pola_gracza][numer_pola_dokad])
    {
        return true;
    }
    return false;
}

void przerwij_polaczenie_pionowe(int numer_bariery_pionowej)
{
    extern bool graf_polaczen_pol[81][81];
    
    int kolumna = numer_bariery_pionowej%8;
    int rzad = numer_bariery_pionowej/8;
    
    int pole1 = kolumna + (rzad * 9);
    int pole2 = kolumna + 1 + (rzad * 9);
    
    graf_polaczen_pol[pole1][pole2] = false;
    graf_polaczen_pol[pole1][pole2] = false;
}

void przerwij_polaczenie_poziome(int numer_bariery_poziomej)
{
    extern bool graf_polaczen_pol[81][81];
    int kolumna = numer_bariery_poziomej % 9;
    int wiersz = numer_bariery_poziomej / 9;
    
    int pole1 = kolumna + (9 * wiersz);
    int pole2 = kolumna + (9 * (wiersz + 1));
    
    graf_polaczen_pol[pole1][pole2] = false;
    graf_polaczen_pol[pole1][pole2] = false;
}

void przywroc_polaczenie_pionowe(int numer_bariery_pionowej)
{
    extern bool graf_polaczen_pol[81][81];
    
    int kolumna = numer_bariery_pionowej%8;
    int rzad = numer_bariery_pionowej/8;
    
    int pole1 = kolumna + (rzad * 9);
    int pole2 = kolumna + 1 + (rzad * 9);
    
    graf_polaczen_pol[pole1][pole2] = true;
    graf_polaczen_pol[pole1][pole2] = true;
}

void przywroc_polaczenie_poziome(int numer_bariery_poziomej)
{
    extern bool graf_polaczen_pol[81][81];
    int kolumna = numer_bariery_poziomej % 9;
    int wiersz = numer_bariery_poziomej / 9;
    
    int pole1 = kolumna + (9 * wiersz);
    int pole2 = kolumna + (9 * (wiersz + 1));
    
    graf_polaczen_pol[pole1][pole2] = true;
    graf_polaczen_pol[pole1][pole2] = true;
}

bool czy_mogę_postawic_bariere_poziomo(int numer_bariery_poziomej)
{
    przerwij_polaczenie_poziome(numer_bariery_poziomej);
    przerwij_polaczenie_poziome(numer_bariery_poziomej + 1);
    
    bool czy_ok = DFS();
    
    przywroc_polaczenie_poziome(numer_bariery_poziomej);
    przywroc_polaczenie_poziome(numer_bariery_poziomej + 1);
    
    return czy_ok;
}

bool czy_mogę_postawic_bariere_pionowo(int numer_bariery_pionowej)
{
    przerwij_polaczenie_pionowe(numer_bariery_pionowej);
    przerwij_polaczenie_pionowe(numer_bariery_pionowej + 8);
    
    bool czy_ok = DFS();
    
    przywroc_polaczenie_pionowe(numer_bariery_pionowej);
    przywroc_polaczenie_pionowe(numer_bariery_pionowej + 8);

    return czy_ok;
}
bool DFS()
{
    extern struct pozycja pozycja_gracza;
    
    return true;
}
void wypisz_graf(bool graf[][81])
{
    
    for(int i=0;i<81;i++)
    {
        for (int j = 0; j<81; j++)
        {
            printf("%d ", graf[i][j]);
        }
        printf("\n");
    }
    
}
