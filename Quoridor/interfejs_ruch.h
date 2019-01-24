//
//  interfejs_ruch.h
//  Quoridor
//
//  Created by Maksymilian Czudziak on 16/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#ifndef interfejs_ruch_h
#define interfejs_ruch_h

#include <stdio.h>
#include <gtk/gtk.h>
#include "wydarzenia.h"
#include <stdbool.h>
//#include "main.h"


struct pozycja
{
    int x;
    int y;
};

struct pozycja_do_ruchu
{
    int x;
    int y;
    GtkWidget *tablica[9][9];
};

//void ruch(GtkWidget *widget, struct pozycja *pozycja);
void ruch(GtkWidget *widget, struct pozycja_do_ruchu *pozycja);
//struct dane_o_ruchu_w_prawo
//{
//    int na_x;
//    int na_y;
//    GtkWidget *tablica[9][9];
//};
//
//struct dane_o_ruchu_w_lewo
//{
//    int na_x;
//    int na_y;
//    GtkWidget *tablica[9][9];
//};
//
//struct dane_o_ruchu_w_dol
//{
//    int na_x;
//    int na_y;
//    GtkWidget *tablica[9][9];
//};
//
//struct dane_o_ruchu_w_gore
//{
//    int na_x;
//    int na_y;
//    GtkWidget *tablica[9][9];
//};

//static void ruch_prawo(GtkWidget *widget, struct dane_o_ruchu_w_prawo *dane);
//static void ruch_lewo(GtkWidget *widget, struct dane_o_ruchu_w_lewo *dane);
//static void ruch_dol(GtkWidget *widget, struct dane_o_ruchu_w_dol *dane);
//static void ruch_gora(GtkWidget *widget, struct dane_o_ruchu_w_gore *dane);

//void ruch_prawo(GtkWidget *widget, struct dane_o_ruchu_w_prawo *dane);
//void ruch_lewo(GtkWidget *widget, struct dane_o_ruchu_w_lewo *dane);
//void ruch_dol(GtkWidget *widget, struct dane_o_ruchu_w_dol *dane);
//void ruch_gora(GtkWidget *widget, struct dane_o_ruchu_w_gore *dane);

//void wyswietl_pola_dostepne_do_ruchu(GtkWidget *wszystkie_guziki[][9], GtkWidget *wszystkie_bariery[], GtkWidget *siatka_okna, unsigned int x, unsigned int y);

void wyswietl_przeciwnika(GtkWidget *wszystkie_guziki[][9],unsigned int x, unsigned int y);
void wyswietl_gracza(GtkWidget *wszystkie_guziki[][9],unsigned int x, unsigned int y);

#endif /* interfejs_ruch_h */
