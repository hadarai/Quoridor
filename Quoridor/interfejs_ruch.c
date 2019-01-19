//
//  interfejs_ruch.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 16/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_ruch.h"

void wyswietl_pola_dostepne_do_ruchu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna, unsigned int x, unsigned int y)
{
    char etykieta_pola_do_ruchu[10] = "M";
    
    unsigned int x_na_siatce = x * 2, y_na_siatce = y * 2;
    unsigned int x_na_guzikach = x, y_na_guzikach = y;
    
    struct dane_o_ruchu dane_ruchu;
    
    dane_ruchu.z_x = x;
    dane_ruchu.z_y = y;
    //dane_ruchu.wszystkie_guziki[][] = wszystkie_guziki[][];
    //printf("jestem %d, %d", dane_ruchu.z_x, dane_ruchu.z_y);
    
    if (x + 1 < 8) // po prawej
    {
        gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x + 1][y]), etykieta_pola_do_ruchu);
        dane_ruchu.na_x = x + 1;
        dane_ruchu.na_y = y;
        g_signal_connect(G_OBJECT(wszystkie_guziki[x + 1][y]), "clicked", G_CALLBACK(ruch), (gpointer)&dane_ruchu);
        gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_guziki[x_na_guzikach][y_na_guzikach], x_na_siatce, y_na_siatce, 1, 1);
        printf("jestem %u, %u. Z %u, %u\n", dane_ruchu.na_x, dane_ruchu.na_y, dane_ruchu.z_x, dane_ruchu.z_y);
    }
    
    if (x - 1 >= 0) //po lewej
    {
        gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x - 1][y]), etykieta_pola_do_ruchu);
        dane_ruchu.na_x = x - 1;
        dane_ruchu.na_y = y;
        g_signal_connect(G_OBJECT(wszystkie_guziki[x - 1][y]), "clicked", G_CALLBACK(ruch), (gpointer)&dane_ruchu);
        gtk_grid_attach(GTK_GRID(siatka_okna), wszystkie_guziki[x_na_guzikach - 1][y_na_guzikach], x_na_siatce - 1, y_na_siatce, 1, 1);
        printf("jestem %u, %u. Z %u, %u\n", dane_ruchu.na_x, dane_ruchu.na_y, dane_ruchu.z_x, dane_ruchu.z_y);
    }
    if (y + 1 <= 8) // na dole
    {
        gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x][y + 1]), etykieta_pola_do_ruchu);
        dane_ruchu.na_x = x;
        dane_ruchu.na_y = y + 1;
        g_signal_connect(G_OBJECT(wszystkie_guziki[x][y + 1]), "clicked", G_CALLBACK(ruch), (gpointer)&dane_ruchu);
        printf("jestem %u, %u. Z %u, %u\n", dane_ruchu.na_x, dane_ruchu.na_y, dane_ruchu.z_x, dane_ruchu.z_y);
    }
    if (y - 1 >= 0) // na gorze
    {
        gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x][y - 1]), etykieta_pola_do_ruchu);
        dane_ruchu.na_x = x;
        dane_ruchu.na_y = y -1;
        g_signal_connect(G_OBJECT(wszystkie_guziki[x][y - 1]), "clicked", G_CALLBACK(ruch), (gpointer)&dane_ruchu);
        printf("jestem %u, %u. Z %u, %u\n", dane_ruchu.na_x, dane_ruchu.na_y, dane_ruchu.z_x, dane_ruchu.z_y);
    }
}

void ruch(struct dane_o_ruchu *dane)
{
//    int na_x;
//    int na_y;
//    int z_x;
//    int z_y;
    printf("jestem %ux, %uy. Z %ux, %uy", dane->na_x, dane->na_y, dane->z_x, dane->z_y);
    
    //char etykieta_pusta[10] = ".";
    //gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[dane.z_x][dane.z_y]), etykieta_pusta);
    
}
