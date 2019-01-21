//
//  interfejs_ruch.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 16/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_ruch.h"

struct dane_o_ruchu_w_prawo dane_ruchu_prawo;
struct dane_o_ruchu_w_lewo dane_ruchu_lewo;
struct dane_o_ruchu_w_dol dane_ruchu_dol;
struct dane_o_ruchu_w_gore dane_ruchu_gora;

char etykieta_pusta[10] = "";
char etykieta_gracza[10] = "G";

static void ruch_prawo(GtkWidget *widget, struct dane_o_ruchu_w_prawo *dane)
{
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x][dane->na_y]), etykieta_gracza);        //przesuwam gracza
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x - 2][dane->na_y]), etykieta_pusta);     //sprzątam po lewej
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x - 1][dane->na_y]), etykieta_pusta);     //sprzątam poprzedniego gracza
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x - 1][dane->na_y - 1]), etykieta_pusta); //sprzątam na gorze
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x - 1][dane->na_y + 1]), etykieta_pusta); //sprzątam na dole
    printf("Ruch w prawo na %ux, %uy\n", dane->na_x, dane->na_y);
//    koniec_tury();
}

static void ruch_lewo(GtkWidget *widget, struct dane_o_ruchu_w_lewo *dane)
{
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x][dane->na_y]), etykieta_gracza); //przesuwam gracza
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x+2][dane->na_y]),etykieta_pusta); //sprzątam po prawej
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x+1][dane->na_y]),etykieta_pusta); //sprzątam poprzedniego gracza
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x+1][dane->na_y-1]),etykieta_pusta); //sprzątam na gorze
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x+1][dane->na_y+1]),etykieta_pusta); //sprzątam na dole
    printf("Ruch w lewo na %ux, %uy\n", dane->na_x, dane->na_y);
//    koniec_tury();
}

static void ruch_dol(GtkWidget *widget, struct dane_o_ruchu_w_dol *dane)
{
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x][dane->na_y]), etykieta_gracza); //przesuwam gracza
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x+1][dane->na_y-1]),etykieta_pusta); //sprzątam po prawej
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x][dane->na_y-1]),etykieta_pusta); //sprzątam poprzedniego gracza
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x][dane->na_y-2]),etykieta_pusta); //sprzątam na gorze
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x-1][dane->na_y-1]),etykieta_pusta); //sprzątam po lewej
    printf("Ruch w dol na %ux, %uy\n", dane->na_x, dane->na_y);
    
//    koniec_tury();
}

static void ruch_gora(GtkWidget *widget, struct dane_o_ruchu_w_gore *dane)
{
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x][dane->na_y]), etykieta_gracza); //przesuwam gracza
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x+1][dane->na_y+1]),etykieta_pusta); //sprzątam po prawej
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x][dane->na_y+1]),etykieta_pusta); //sprzątam poprzedniego gracza
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x][dane->na_y+2]),etykieta_pusta); //sprzątam na dole
    gtk_button_set_label(GTK_BUTTON(dane->tablica[dane->na_x-1][dane->na_y+1]),etykieta_pusta); //sprzątam po lewej
    printf("Ruch w gore na %ux, %uy\n", dane->na_x, dane->na_y);
//    koniec_tury();
//    moj_ruch = false;
}

//struct pozycja wyswietl_pola_dostepne_do_ruchu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna, unsigned int x, unsigned int y)
void wyswietl_pola_dostepne_do_ruchu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna, unsigned int x, unsigned int y)
{
    char etykieta_pola_do_ruchu[10] = "M";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            dane_ruchu_prawo.tablica[i][j] = wszystkie_guziki[i][j];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            dane_ruchu_lewo.tablica[i][j] = wszystkie_guziki[i][j];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            dane_ruchu_gora.tablica[i][j] = wszystkie_guziki[i][j];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            dane_ruchu_dol.tablica[i][j] = wszystkie_guziki[i][j];
        }
    }

    if (x + 1 < 8) // ruch w prawo
    {
        gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x + 1][y]), etykieta_pola_do_ruchu);
        dane_ruchu_prawo.na_x = x + 1;
        dane_ruchu_prawo.na_y = y;

        g_signal_connect(wszystkie_guziki[x + 1][y], "clicked", G_CALLBACK(ruch_prawo), (gpointer)&dane_ruchu_prawo);
    }

    if (x - 1 >= 0) //ruch w lewo
    {
        gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x - 1][y]), etykieta_pola_do_ruchu);
        dane_ruchu_lewo.na_x = x - 1;
        dane_ruchu_lewo.na_y = y;
        g_signal_connect(wszystkie_guziki[x - 1][y], "clicked", G_CALLBACK(ruch_lewo), (gpointer)&dane_ruchu_lewo);
    }
    if (y + 1 <= 8) // ruch w dol
    {
        gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x][y + 1]), etykieta_pola_do_ruchu);
        dane_ruchu_dol.na_x = x;
        dane_ruchu_dol.na_y = y + 1;
        g_signal_connect(wszystkie_guziki[x][y + 1], "clicked", G_CALLBACK(ruch_dol), (gpointer)&dane_ruchu_dol);
    }
    if (y - 1 >= 0) // ruch w gore
    {
        gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x][y - 1]), etykieta_pola_do_ruchu);
        dane_ruchu_gora.na_x = x;
        dane_ruchu_gora.na_y = y - 1;
        g_signal_connect(wszystkie_guziki[x][y - 1], "clicked", G_CALLBACK(ruch_gora), (gpointer)&dane_ruchu_gora);
    }
//    struct pozycja pozycja_gracza;
    
    //return pozycja_gracza;
}

void wyswietl_przeciwnika(GtkWidget *wszystkie_guziki[][9],unsigned int x, unsigned int y)
{
    char etykieta_przeciwnika[10] = "P";
    gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x][y]), etykieta_przeciwnika);
}

void wyswietl_gracza(GtkWidget *wszystkie_guziki[][9],unsigned int x, unsigned int y)
{
    char etykieta_gracza[10] = "G";
    gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x][y]), etykieta_gracza);
}

