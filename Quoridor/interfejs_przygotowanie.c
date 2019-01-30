//
//  interfejs_przygotowanie.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 15/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_przygotowanie.h"

void rysowanie_interfejsu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna, PipesPtr potoki)
{
    unsigned int numer_bariery = 0;
    char numerek_na_guziku[10] = "";

    for (int i_wiersz_y = 0; i_wiersz_y < 17; i_wiersz_y++)
    {
        for (int j_kolumna_x = 0; j_kolumna_x < 17; j_kolumna_x++)
        {
            if (czy_klasc_guzik(i_wiersz_y, j_kolumna_x))
            {
                int x_guzika = j_kolumna_x / 2;
                int y_guzika = i_wiersz_y / 2;
                wszystkie_guziki[x_guzika][y_guzika] = gtk_button_new();

                gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x_guzika][y_guzika]), numerek_na_guziku);
                gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_guziki[x_guzika][y_guzika], j_kolumna_x, i_wiersz_y, 1, 1);
            }
            else
            {
                numer_bariery++;
                wszystkie_bariery[numer_bariery] = gtk_event_box_new();
                
                podlacz_bariere(wszystkie_bariery[numer_bariery], j_kolumna_x, i_wiersz_y, potoki);
                
                gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_bariery[numer_bariery], j_kolumna_x, i_wiersz_y, 1, 1);
            }
        }
    }
}

void podlacz_bariere(GtkWidget *bariera, unsigned int x, unsigned int y, PipesPtr potoki)
{
    
    if (czy_niepuste_pole(x, y))
    {
        struct dane_bariery bariera_i_jej_przyjaciele;
        bariera_i_jej_przyjaciele.x = x;
        bariera_i_jej_przyjaciele.y = y;
        bariera_i_jej_przyjaciele.potoki = potoki;
        g_signal_connect(G_OBJECT(bariera), "button_press_event", G_CALLBACK(stawianie_bariery), (gpointer)&bariera_i_jej_przyjaciele);
    }
}

void podlaczanie_guzikow(GtkWidget *wszystkie_guziki[][9], struct pozycja_do_ruchu pozycje_guzikow[][9], PipesPtr potoki)
{
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
