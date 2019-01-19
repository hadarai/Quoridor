//
//  interfejs_przygotowanie.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 15/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_przygotowanie.h"
#include "wydarzenia.h"
#include <stdbool.h>

//void rysowanie_interfejsu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna)
//{
//    unsigned int numer_bariery = 0;
//    char numerek_na_guziku[10] = "";
//
//    for (int i_wiersz = 0; i_wiersz < 17; i_wiersz++)
//    {
//        for (int j_kolumna = 0; j_kolumna < 17; j_kolumna++)
//        {
//            if (czy_klasc_guzik(j_kolumna, i_wiersz))
//            {
//                //numer_guzika = ((i_wiersz/2) * 9) + (j_kolumna/2);
//
//                wszystkie_guziki[i_wiersz][j_kolumna] = gtk_button_new();
//
//                sprintf(numerek_na_guziku, "x%d y%d", i_wiersz, j_kolumna);
//                gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[i_wiersz][j_kolumna]), numerek_na_guziku);
//
//                g_signal_connect(G_OBJECT(wszystkie_guziki[i_wiersz][j_kolumna]), "clicked", G_CALLBACK(stalo_sie), NULL);
//                gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_guziki[i_wiersz][j_kolumna], i_wiersz, j_kolumna, 1, 1);
//            }
//            else
//            {
//                numer_bariery++;
//                wszystkie_bariery[numer_bariery] = gtk_event_box_new();
//
//                if (czy_podlaczac_beriere(i_wiersz, j_kolumna))
//                {
//                    g_signal_connect(G_OBJECT(wszystkie_bariery[numer_bariery]), "button_press_event", G_CALLBACK(stalo_sie_bariera), NULL);
//                }
//
//                gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_bariery[numer_bariery], i_wiersz, j_kolumna, 1, 1);
//            }
//        }
//    }
//}

void rysowanie_interfejsu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna)
{
    unsigned int numer_bariery = 0;
    char numerek_na_guziku[10] = "";
    
    for (int i_wiersz_y = 0; i_wiersz_y < 17; i_wiersz_y++)
    {
        for (int j_kolumna_x = 0; j_kolumna_x < 17; j_kolumna_x++)
        {
            if (czy_klasc_guzik(i_wiersz_y, j_kolumna_x))
            {
                //numer_guzika = ((i_wiersz/2) * 9) + (j_kolumna/2);
                int x_guzika = j_kolumna_x / 2;
                int y_guzika = i_wiersz_y / 2;
                wszystkie_guziki[x_guzika][y_guzika] = gtk_button_new();
                
                sprintf(numerek_na_guziku, "x%d y%d", x_guzika, y_guzika);
                gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x_guzika][y_guzika]),numerek_na_guziku);
                
                //g_signal_connect(G_OBJECT(wszystkie_guziki[x_guzika][y_guzika]), "clicked", G_CALLBACK(stalo_sie), NULL);
                gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_guziki[x_guzika][y_guzika], j_kolumna_x, i_wiersz_y, 1, 1);
            }
            else
            {
                numer_bariery++;
                wszystkie_bariery[numer_bariery] = gtk_event_box_new();
                
                if (czy_podlaczac_beriere(j_kolumna_x, i_wiersz_y))
                {
                    g_signal_connect(G_OBJECT(wszystkie_bariery[numer_bariery]), "button_press_event", G_CALLBACK(stalo_sie_bariera), NULL);
                }
                
                gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_bariery[numer_bariery], j_kolumna_x, i_wiersz_y, 1, 1);
            }
        }
    }
}

bool czy_podlaczac_beriere(unsigned int i_wiersz, unsigned int j_kolumna)
{
    if (i_wiersz % 2 == 0 && ((i_wiersz % 2 == 0 && j_kolumna % 2 == 1) || (j_kolumna % 2 == 0 && i_wiersz % 2 == 0)))
        return true;
    else if ((i_wiersz % 2 == 1) && j_kolumna % 2 == 0)
    {
        return true;
    }
    else
        return false;
}

bool czy_klasc_guzik(unsigned int i_wiersz, unsigned int j_kolumna)
{
    return (j_kolumna % 2 == 0 && i_wiersz % 2 == 0);
}
