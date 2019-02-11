//
//  komunikacja.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 15/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "komunikacja.h"

extern char wiadomosc[10];

void wyslij_ruch(int x_gracza, int y_gracza, PipesPtr potoki)
{
    sprintf(wiadomosc, "r %d %d", x_gracza, y_gracza);
    sendStringToPipe(potoki, wiadomosc);
}

void wyslij_bariere(int numer_bariery, int czy_pion, PipesPtr potoki)
{
    if(numer_bariery < 10)
    {
        sprintf(wiadomosc, "b 0%d %d", numer_bariery, czy_pion);
    }
    else
    {
        sprintf(wiadomosc, "b %d %d", numer_bariery, czy_pion);
    }
    sendStringToPipe(potoki, wiadomosc);
}

void wyslij_zwyciestwo()
{
    extern PipesPtr potoki;
    sprintf(wiadomosc, "z");
    sendStringToPipe(potoki, wiadomosc);
}

gboolean odczytaj_wiadmosc(gpointer data)
{
    PipesPtr potoki = (PipesPtr)data;
    extern bool moj_ruch;
    extern struct pozycja pozycja_przeciwnika;
    gchar wejscie[10];
    if(getStringFromPipe(potoki, wejscie, 10))
    {
        printf("%s", wejscie);
        
        if(wejscie[0] == 'z')
        {
            przegrana();
        }
        
        if(wejscie[0] == 'r')
        {
            int wsp_x = 8 - (wejscie[2] - '0');
            int wsp_y = 8 - (wejscie[4] - '0');

            ruch_przeciwnika(wsp_x, wsp_y);
            printf("%d %d", wsp_x, wsp_y);
        }
        
        if(wejscie[0] == 'b')
        {
            int numer_bariery;
            numer_bariery = ((wejscie[2] - '0') * 10);
            numer_bariery = numer_bariery + wejscie[3] - '0';
            
            
            przeciwnik_polozyl_bariere(numer_bariery, (wejscie[5] - '0'));
        }
        moj_ruch = true;
    }
    return TRUE;
}
