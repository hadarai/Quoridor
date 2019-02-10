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
