//
//  interfejs_przygotowanie.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 15/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_przygotowanie.h"

void rysowanie_interfejsu(GtkWidget *wszystkie_guziki[][9], GtkWidget *bariery_pionowe[], GtkWidget *bariery_poziome[], GtkWidget *bariery_martwe[], GtkWidget *siatka_okna, PipesPtr potoki)
{
    unsigned int numer_bariery = 0;
    char numerek_na_guziku[10] = "";
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

                gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x_guzika][y_guzika]), numerek_na_guziku);
                gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_guziki[x_guzika][y_guzika], j_kolumna_x, i_wiersz_y, 1, 1);
            }
            else
            {
                
                if(czy_bariera_pionowa(numer_bariery))
                {
                    //bariera pionowa
                    licznik_pionowych_barier++;
                    bariery_pionowe[licznik_pionowych_barier] = gtk_event_box_new();
                    gtk_grid_attach(GTK_GRID(siatka_okna), bariery_pionowe[licznik_pionowych_barier], j_kolumna_x, i_wiersz_y, 1, 1);
                    g_signal_connect(G_OBJECT(bariery_pionowe[licznik_pionowych_barier]), "button_press_event", G_CALLBACK(bariera_pionowa), NULL);
                }
                
                if(czy_bariera_pozioma(numer_bariery))
                {
                    licznik_poziomych_barier++;
                    //bariera pozioma
                    bariery_poziome[licznik_poziomych_barier] = gtk_event_box_new();
                    gtk_grid_attach(GTK_GRID(siatka_okna), bariery_poziome[licznik_poziomych_barier], j_kolumna_x, i_wiersz_y, 1, 1);
                    g_signal_connect(G_OBJECT(bariery_poziome[licznik_poziomych_barier]), "button_press_event", G_CALLBACK(bariera_pozioma), NULL);
                }
                
                if(czy_bariera_martwa(numer_bariery))
                {
                    //bariera martwa
                    licznik_martwych_barier++;
                    //bariera pozioma
                    bariery_martwe[licznik_martwych_barier] = gtk_event_box_new();
                    gtk_grid_attach(GTK_GRID(siatka_okna), bariery_martwe[licznik_martwych_barier], j_kolumna_x, i_wiersz_y, 1, 1);
                    g_signal_connect(G_OBJECT(bariery_martwe[licznik_martwych_barier]), "button_press_event", G_CALLBACK(bariera_martwa), NULL);
                }
//                bariery[numer_bariery] = gtk_event_box_new();
//                struct dane_bariery bariera_i_jej_przyjaciele[1000];
//
//                if (czy_niepuste_pole(j_kolumna_x, i_wiersz_y))
//                {
//                    podlacz_bariere(wszystkie_bariery[numer_bariery], j_kolumna_x, i_wiersz_y, potoki, &bariera_i_jej_przyjaciele[numer_bariery]);
//                }

//                gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_bariery[numer_bariery], j_kolumna_x, i_wiersz_y, 1, 1);
                
                numer_bariery++;
            }
        }
    }
}

bool czy_bariera_pionowa(int numer)
{
    return (numer%25 >=0 && numer%25 <= 7);
}

bool czy_bariera_pozioma(int numer)
{
//    if(numer%25 < 8)
//    {
//        return false;
//    }
    return (numer%25>=8 && ((numer%25)%2 == 0));
//    else
//    {
//        if(numer %2 == 0 && )
//        {
//            return true;
//        }
//        if(numer % 2 == 1 && )
//        {
//            return true;
//        }
//
//    }
//    return false;
}

bool czy_bariera_martwa(int numer)
{
    return (numer%25>=8 && ((numer%25)%2 == 1));
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
