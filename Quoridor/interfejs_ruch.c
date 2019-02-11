//
//  interfejs_ruch.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 16/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_ruch.h"

extern bool moj_ruch;
extern struct pozycja pozycja_gracza;
extern struct pozycja pozycja_przeciwnika;

char etykieta_pusta[10] = "";
char etykieta_gracza[10] = "G";

void ruch(GtkWidget *widget, struct pozycja_do_ruchu *pozycja)
{
    //    sendStringToPipe(pozycja->potoki, "trzy");
    printf("Gracz jest na: %ux %uy. Ruch na %ux, %uy\n", pozycja_gracza.x, pozycja_gracza.y, pozycja->x, pozycja->y);
    //    printf("Gracz jest na: %ux %uy. Ruch na %ux, %uy\n", pozycja_gracza.x, pozycja_gracza.y, pozycja->x, pozycja->y);
    if (!moj_ruch)
    {
        return;
    }
    
    if (!czy_moge_przejsc_na_grafie(pozycja_gracza.x, pozycja_gracza.y, pozycja->x, pozycja->y))
    {
        return;
    }

    //rozwazam czy to bedzie ruch w lewo
    if (czy_to_bedzie_w_prawo(pozycja->x, pozycja->y, pozycja_gracza.x, pozycja_gracza.y, pozycja_przeciwnika.x, pozycja_przeciwnika.y)) //1
    {

        gtk_button_set_label(GTK_BUTTON(pozycja->tablica[pozycja_gracza.x][pozycja_gracza.y]), etykieta_pusta);
        gtk_button_set_label(GTK_BUTTON(pozycja->tablica[pozycja->x][pozycja->y]), etykieta_gracza);
//        wyswietl_gracza(pozycja->tablica, pozycja->x, pozycja->y);
        pozycja_gracza.x = pozycja->x;
        pozycja_gracza.y = pozycja->y;
        moj_ruch = false;
        wyslij_ruch(pozycja_gracza.x, pozycja_gracza.y, pozycja->potoki);
    }

    if (czy_to_bedzie_w_lewo(pozycja->x, pozycja->y, pozycja_gracza.x, pozycja_gracza.y, pozycja_przeciwnika.x, pozycja_przeciwnika.y)) //1
    {
        gtk_button_set_label(GTK_BUTTON(pozycja->tablica[pozycja_gracza.x][pozycja_gracza.y]), etykieta_pusta);
        gtk_button_set_label(GTK_BUTTON(pozycja->tablica[pozycja->x][pozycja->y]), etykieta_gracza);
//        wyswietl_gracza(pozycja->tablica, pozycja->x, pozycja->y);
        pozycja_gracza.x = pozycja->x;
        pozycja_gracza.y = pozycja->y;
        moj_ruch = false;
        wyslij_ruch(pozycja_gracza.x, pozycja_gracza.y, pozycja->potoki);
    }

    if (czy_to_bedzie_w_gore(pozycja->x, pozycja->y, pozycja_gracza.x, pozycja_gracza.y, pozycja_przeciwnika.x, pozycja_przeciwnika.y)) //1
    {
        gtk_button_set_label(GTK_BUTTON(pozycja->tablica[pozycja_gracza.x][pozycja_gracza.y]), etykieta_pusta);
        gtk_button_set_label(GTK_BUTTON(pozycja->tablica[pozycja->x][pozycja->y]), etykieta_gracza);
//        wyswietl_gracza(pozycja->tablica, pozycja->x, pozycja->y);
        pozycja_gracza.x = pozycja->x;
        pozycja_gracza.y = pozycja->y;
        moj_ruch = false;
        wyslij_ruch(pozycja_gracza.x, pozycja_gracza.y, pozycja->potoki);
    }

    if (czy_to_bedzie_w_dol(pozycja->x, pozycja->y, pozycja_gracza.x, pozycja_gracza.y, pozycja_przeciwnika.x, pozycja_przeciwnika.y)) //1
    {
        gtk_button_set_label(GTK_BUTTON(pozycja->tablica[pozycja_gracza.x][pozycja_gracza.y]), etykieta_pusta);
        gtk_button_set_label(GTK_BUTTON(pozycja->tablica[pozycja->x][pozycja->y]), etykieta_gracza);
//        wyswietl_gracza(pozycja->tablica, pozycja->x, pozycja->y);
        pozycja_gracza.x = pozycja->x;
        pozycja_gracza.y = pozycja->y;
        moj_ruch = false;
        wyslij_ruch(pozycja_gracza.x, pozycja_gracza.y, pozycja->potoki);
    }
//    moj_ruch = true;
    return;
}

bool czy_to_bedzie_w_prawo(int pozycja_guzika_x, int pozycja_guzika_y, int pozycja_gracza_x, int pozycja_gracza_y, int pozycja_przeciwnika_x, int pozycja_przeciwnika_y)
{
    if (pozycja_guzika_x == pozycja_gracza_x + 1 && pozycja_gracza_y == pozycja_guzika_y) // czy to bedzie w lewo o jeden
    {
//        return true;
        if (pozycja_przeciwnika_x != pozycja_guzika_x || pozycja_przeciwnika_y != pozycja_guzika_y) // czy nie ma tam przeciwnika
        {
            return true;
        }
    }
    return false;
}
bool czy_to_bedzie_w_lewo(int pozycja_guzika_x, int pozycja_guzika_y, int pozycja_gracza_x, int pozycja_gracza_y, int pozycja_przeciwnika_x, int pozycja_przeciwnika_y)
{
    if (pozycja_guzika_x == (pozycja_gracza_x - 1) && pozycja_gracza_y == pozycja_guzika_y)
    {
//        return true;
        if (pozycja_przeciwnika_x != pozycja_guzika_x || pozycja_przeciwnika_y != pozycja_guzika_y) // czy nie ma tam przeciwnika
        {
            return true;
        }
    }
    return false;
}
bool czy_to_bedzie_w_gore(int pozycja_guzika_x, int pozycja_guzika_y, int pozycja_gracza_x, int pozycja_gracza_y, int pozycja_przeciwnika_x, int pozycja_przeciwnika_y)
{
    if (pozycja_guzika_x == pozycja_gracza_x && pozycja_gracza_y - 1 == pozycja_guzika_y) // czy to bedzie w gore o jeden
    {
//        return true;
//        printf("%d %d %d %d", pozycja_przeciwnika_x, pozycja_guzika_x, pozycja_przeciwnika_y,  pozycja_guzika_y);
        if ((pozycja_przeciwnika_x != pozycja_guzika_x) || (pozycja_przeciwnika_y != pozycja_guzika_y)) // czy nie ma tam przeciwnika
        {
//            printf("pupa");
            return true;
        }
    }
    return false;
}
bool czy_to_bedzie_w_dol(int pozycja_guzika_x, int pozycja_guzika_y, int pozycja_gracza_x, int pozycja_gracza_y, int pozycja_przeciwnika_x, int pozycja_przeciwnika_y)
{
    if (pozycja_guzika_x == pozycja_gracza_x && pozycja_gracza_y + 1 == pozycja_guzika_y) // czy to bedzie w lewo o jeden
    {
//        return true;
        if (pozycja_przeciwnika_x != pozycja_guzika_x || pozycja_przeciwnika_y != pozycja_guzika_y) // czy nie ma tam przeciwnika
        {
            return true;
        }
    }
    return false;
}

void wyswietl_przeciwnika(GtkWidget *wszystkie_guziki[][9], unsigned int x, unsigned int y)
{
    char etykieta_przeciwnika[10] = "P";
    gtk_button_set_label(GTK_BUTTON(wszystkie_guziki[x][y]), etykieta_przeciwnika);
}

void wyswietl_gracza(GtkWidget *wszystkie_guziki[][9], unsigned int x, unsigned int y)
{
    GtkWidget *image;
//    GtkWidget *guzik_gracza = wszystkie_guziki[x][y];
    image = gtk_image_new_from_file ("pionek_gracza.png");
//    gtk_container_add (GTK_CONTAINER (event_box), image);
    gtk_button_set_image (GTK_BUTTON(wszystkie_guziki[x][y]),image);
//    char etykieta_gracza[10] = "G";
}

void ruch_przeciwnika(int x, int y)
{
    extern GtkWidget *guziki[9][9];
    extern struct pozycja pozycja_przeciwnika;
    char etykieta_przeciwnika[10] = "P";
    char etykieta_pusta[10] = "";
    
    gtk_button_set_label(GTK_BUTTON(guziki[pozycja_przeciwnika.x][pozycja_przeciwnika.y]), etykieta_pusta);
    
    pozycja_przeciwnika.x = x;
    pozycja_przeciwnika.y = y;
    
    gtk_button_set_label(GTK_BUTTON(guziki[x][y]), etykieta_przeciwnika);
}
