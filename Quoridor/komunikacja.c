//
//  komunikacja.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 15/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "komunikacja.h"

extern char wiadomosc[10];

void wyslij_ruch(int x_gracza, int y_gracza, pipes_pointer potoki)
{
    sprintf(wiadomosc, "r %d %d", x_gracza, y_gracza);
    send_string_to_pipe(potoki, wiadomosc);
}

void wyslij_bariere(int numer_bariery, int czy_pion, pipes_pointer potoki)
{
    if (numer_bariery < 10)
    {
        sprintf(wiadomosc, "b 0%d %d", numer_bariery, czy_pion);
    }
    else
    {
        sprintf(wiadomosc, "b %d %d", numer_bariery, czy_pion);
    }
    send_string_to_pipe(potoki, wiadomosc);
}

void wyslij_zwyciestwo()
{
    extern pipes_pointer potoki;
    sprintf(wiadomosc, "z");
    send_string_to_pipe(potoki, wiadomosc);
}

gboolean odczytaj_wiadmosc(gpointer data)
{
    pipes_pointer potoki = (pipes_pointer)data;
    extern bool moj_ruch;
    extern struct pozycja pozycja_przeciwnika;
    gchar wejscie[10];
    if (get_string_from_pipe(potoki, wejscie, 10))
    {
        if (wejscie[0] == 'z')
        {
            przegrana();
            moj_ruch = false;
        }

        if (wejscie[0] == 'r')
        {
            int wsp_x = 8 - (wejscie[2] - '0');
            int wsp_y = 8 - (wejscie[4] - '0');

            ruch_przeciwnika(wsp_x, wsp_y);
            moj_ruch = true;
        }

        if (wejscie[0] == 'b')
        {
            int numer_bariery;
            numer_bariery = ((wejscie[2] - '0') * 10);
            numer_bariery = numer_bariery + wejscie[3] - '0';

            przeciwnik_polozyl_bariere(numer_bariery, (wejscie[5] - '0'));
            moj_ruch = true;
        }
    }
    return TRUE;
}
