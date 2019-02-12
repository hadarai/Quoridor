//
//  interfejs_przygotowanie.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 15/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_przygotowanie.h"
extern struct dane_bariery dane_barier_poziomych[];

void rysowanie_interfejsu(GtkWidget *wszystkie_guziki[][9], GtkWidget *bariery_pionowe[], GtkWidget *bariery_poziome[], GtkWidget *bariery_martwe[], GtkWidget *siatka_okna, PipesPtr potoki)
{
    unsigned int numer_bariery = 0;
    unsigned int licznik_pionowych_barier = 0, licznik_poziomych_barier = 0, licznik_martwych_barier = 0;

    for (int i_wiersz_y = 0; i_wiersz_y < 17; i_wiersz_y++)
    {
        for (int j_kolumna_x = 0; j_kolumna_x < 17; j_kolumna_x++)
        {
            if (czy_klasc_guzik(i_wiersz_y, j_kolumna_x))
            {
                int x_guzika = j_kolumna_x / 2;
                int y_guzika = i_wiersz_y / 2;
                wszystkie_guziki[x_guzika][y_guzika] = gtk_button_new();
                
                gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_guziki[x_guzika][y_guzika], j_kolumna_x, i_wiersz_y, 1, 1);
                
            }
            else
            {
                if (czy_bariera_pionowa(numer_bariery))
                {
                    //bariera pionowa
                    bariery_pionowe[licznik_pionowych_barier] = gtk_event_box_new();
                    gtk_grid_attach(GTK_GRID(siatka_okna), bariery_pionowe[licznik_pionowych_barier], j_kolumna_x, i_wiersz_y, 1, 1);
                    licznik_pionowych_barier++;
                }

                if (czy_bariera_pozioma(numer_bariery))
                {
                    //bariera pozioma
                    bariery_poziome[licznik_poziomych_barier] = gtk_event_box_new();
                    gtk_grid_attach(GTK_GRID(siatka_okna), bariery_poziome[licznik_poziomych_barier], j_kolumna_x, i_wiersz_y, 1, 1);
                    licznik_poziomych_barier++;
                }

                if (czy_bariera_martwa(numer_bariery))
                {
                    //bariera martwa
                    bariery_martwe[licznik_martwych_barier] = gtk_event_box_new();
                    gtk_grid_attach(GTK_GRID(siatka_okna), bariery_martwe[licznik_martwych_barier], j_kolumna_x, i_wiersz_y, 1, 1);
                    licznik_martwych_barier++;
                }
                numer_bariery++;
            }
        }
    }
}

bool czy_bariera_pionowa(int numer)
{
    return (numer % 25 >= 0 && numer % 25 <= 7);
}

bool czy_bariera_pozioma(int numer)
{
    return (numer % 25 >= 8 && ((numer % 25) % 2 == 0));
}

bool czy_bariera_martwa(int numer)
{
    return (numer % 25 >= 8 && ((numer % 25) % 2 == 1));
}

void podlaczanie_guzikow(GtkWidget *wszystkie_guziki[][9],PipesPtr potoki)
{
    extern struct pozycja_do_ruchu pozycje_guzikow[9][9];
    for (int i_wiersz_y = 0; i_wiersz_y < 9; i_wiersz_y++)
    {
        for (int j_kolumna_x = 0; j_kolumna_x < 9; j_kolumna_x++)
        {
            pozycje_guzikow[j_kolumna_x][i_wiersz_y].x = j_kolumna_x;
            pozycje_guzikow[j_kolumna_x][i_wiersz_y].y = i_wiersz_y;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    pozycje_guzikow[j_kolumna_x][i_wiersz_y].tablica[i][j] = wszystkie_guziki[i][j];
                }
            }
            pozycje_guzikow[j_kolumna_x][i_wiersz_y].potoki = potoki;
            g_signal_connect(wszystkie_guziki[j_kolumna_x][i_wiersz_y], "clicked", G_CALLBACK(ruch), (gpointer)&pozycje_guzikow[j_kolumna_x][i_wiersz_y]);
        }
    }
}


void podlaczanie_barier(GtkWidget *bariery_poziome[], GtkWidget *bariery_pionowe[],  GtkWidget *bariery_martwe[], struct dane_bariery dane_barier_poziomych[], struct dane_bariery dane_barier_pionowych[],  PipesPtr potoki)
{
    
    extern const unsigned short int ilosc_barier_pionowych;
    extern const unsigned short int ilosc_barier_poziomych;
    extern const unsigned short int ilosc_barier_martwych;
    
    //poziome
    for (int i = 0; i < ilosc_barier_poziomych; i++)
    {
        dane_barier_poziomych[i].numer_w_tablicy = i;
        
        for(int j=0;j<ilosc_barier_poziomych;j++)
        {
            dane_barier_poziomych[i].tablica_barier[j] = bariery_poziome[j];
        }
        for(int j=0;j<ilosc_barier_martwych;j++)
        {
            dane_barier_poziomych[i].tablica_barier_martwych[j] = bariery_martwe[j];
        }
        dane_barier_poziomych[i].potoki = potoki;
        
        g_signal_connect(G_OBJECT(bariery_poziome[i]), "button_press_event", G_CALLBACK(stawianie_bariery_poziomej), (gpointer)&dane_barier_poziomych[i]);
    }
    
    //pionowe
    for (int i = 0; i < ilosc_barier_pionowych; i++)
    {
        dane_barier_pionowych[i].numer_w_tablicy = i;
        
        for(int j=0;j<ilosc_barier_pionowych;j++)
        {
            dane_barier_pionowych[i].tablica_barier[j] = bariery_pionowe[j];
        }
        for(int j=0;j<ilosc_barier_martwych;j++)
        {
            dane_barier_pionowych[i].tablica_barier_martwych[j] = bariery_martwe[j];
        }
        dane_barier_pionowych[i].potoki = potoki;
        
        g_signal_connect(G_OBJECT(bariery_pionowe[i]), "button_press_event", G_CALLBACK(stawianie_bariery_pionowej), (gpointer)&dane_barier_pionowych[i]);
    }
    
}

bool czy_niepuste_pole(unsigned int i_wiersz, unsigned int j_kolumna)
{
    if (i_wiersz % 2 == 0 && ((i_wiersz % 2 == 0 && j_kolumna % 2 == 1) || (j_kolumna % 2 == 0 && i_wiersz % 2 == 0)))
        return true;
    if ((i_wiersz % 2 == 1) && j_kolumna % 2 == 0)
    {
        return true;
    }
    return false;
}

bool czy_klasc_guzik(unsigned int i_wiersz, unsigned int j_kolumna)
{
    return (j_kolumna % 2 == 0 && i_wiersz % 2 == 0);
}

