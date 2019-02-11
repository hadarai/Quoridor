//
//  interfejs_bariery.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 19/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_bariery.h"

bool czy_bariera_juz_tu_stoi_pion[72];
bool czy_bariera_juz_tu_stoi_poziom[72];
bool czy_bariera_juz_tu_stoi_martwe[64];

void stawianie_bariery_poziomej(GtkWidget *widget, GdkEvent *pomocniczy, struct dane_bariery *dane_tej_bariery)
{
    extern unsigned int ilosc_barier;
    if(!moj_ruch || ilosc_barier <= 0) return;
    int numer = dane_tej_bariery->numer_w_tablicy;
    if(numer%9 == 8)
    {
        numer = numer - 1;
    }
    
    if(czy_bariera_juz_tu_stoi_poziom[numer] || czy_bariera_juz_tu_stoi_poziom[numer+1] || czy_bariera_juz_tu_stoi_martwe[numer - (numer/9)])
    {
        printf("nie mozna, bo bool");
        return;
    }
    
    if(!czy_moge_postawic_bariere_poziomo(numer)) return;
    
    //ustawienie odpowiednich grafik
    ustaw_grafike_bariery_poziomej(dane_tej_bariery->tablica_barier[numer]);
    ustaw_grafike_bariery_poziomej(dane_tej_bariery->tablica_barier[numer+1]);
    ustaw_grafike_bariery_martwej(dane_tej_bariery->tablica_barier_martwych[numer - (numer/9)]);
    
    przerwij_polaczenie_poziome(numer);
    przerwij_polaczenie_poziome(numer+1);
    
    //ustawienie na tablicy booli
    czy_bariera_juz_tu_stoi_poziom[numer] = 1;
    czy_bariera_juz_tu_stoi_martwe[numer - (numer/9)] = 1;
    czy_bariera_juz_tu_stoi_poziom[numer+1] = 1;
    moj_ruch = false;
    wyslij_bariere(numer, 0, dane_tej_bariery->potoki);
    ilosc_barier--;
    return;
}

void stawianie_bariery_pionowej(GtkWidget *widget, GdkEvent *pomocniczy, struct dane_bariery *dane_tej_bariery)
{
    extern unsigned int ilosc_barier;
    if(!moj_ruch || ilosc_barier <= 0) return;
    int numer = dane_tej_bariery->numer_w_tablicy;
    if(numer/8 == 8)
    {
        numer = numer - 8;
    }
    
    if(czy_bariera_juz_tu_stoi_pion[numer] || czy_bariera_juz_tu_stoi_pion[numer+8] || czy_bariera_juz_tu_stoi_martwe[numer])
    {
        printf("nie mozna, bo bool");
        return;
    }
    
    //zmiana grafik
    ustaw_grafike_bariery_pionowej(dane_tej_bariery->tablica_barier[numer]);
    ustaw_grafike_bariery_pionowej(dane_tej_bariery->tablica_barier[numer+8]);
    ustaw_grafike_bariery_martwej(dane_tej_bariery->tablica_barier_martwych[numer]);
    
    przerwij_polaczenie_pionowe(numer);
    przerwij_polaczenie_pionowe(numer+8);
    
    //ustawienie na tablicy booli
    czy_bariera_juz_tu_stoi_pion[numer] = 1;
    czy_bariera_juz_tu_stoi_martwe[numer] = 1;
    czy_bariera_juz_tu_stoi_pion[numer+8] = 1;
    moj_ruch = false;
    wyslij_bariere(numer, 1, dane_tej_bariery->potoki);
    ilosc_barier--;
    return;
}

void ustaw_grafike_bariery_poziomej(GtkWidget *bariera)
{
    GtkWidget *grafika;
    grafika = gtk_image_new_from_file ("bariera_pozioma.png");
    gtk_container_add (GTK_CONTAINER(bariera),grafika);
    gtk_widget_show(grafika);

}

void ustaw_grafike_bariery_pionowej(GtkWidget *bariera)
{
    GtkWidget *grafika;
    grafika = gtk_image_new_from_file ("bariera_pionowa.png");
    gtk_container_add (GTK_CONTAINER(bariera),grafika);
    gtk_widget_show(grafika);
}

void ustaw_grafike_bariery_martwej(GtkWidget *bariera)
{
    GtkWidget *grafika;
    grafika = gtk_image_new_from_file ("bariera_martwa.png");
    gtk_container_add (GTK_CONTAINER(bariera),grafika);
    gtk_widget_show(grafika);
}

void przeciwnik_polozyl_bariere(int numer_bariery, int czy_pionowa)
{
    extern GtkWidget *bariery_pionowe[72];
    extern GtkWidget *bariery_poziome[72];
    extern GtkWidget *bariery_martwe[64];
    
    if(czy_pionowa == 1)
    {
        numer_bariery = (71 - numer_bariery);
        ustaw_grafike_bariery_pionowej(bariery_pionowe[numer_bariery]);
        ustaw_grafike_bariery_pionowej(bariery_pionowe[numer_bariery-8]);
        ustaw_grafike_bariery_martwej(bariery_martwe[numer_bariery-8]);
        
        przerwij_polaczenie_pionowe(numer_bariery);
        przerwij_polaczenie_pionowe(numer_bariery-8);
        
        //ustawienie na tablicy booli
        czy_bariera_juz_tu_stoi_pion[numer_bariery] = 1;
        czy_bariera_juz_tu_stoi_martwe[numer_bariery-8] = 1;
        czy_bariera_juz_tu_stoi_pion[numer_bariery-8] = 1;
    }
    else
    {
        numer_bariery = (71 - numer_bariery);
        ustaw_grafike_bariery_poziomej(bariery_poziome[numer_bariery]);
        ustaw_grafike_bariery_poziomej(bariery_poziome[numer_bariery-1]);
        ustaw_grafike_bariery_martwej(bariery_martwe[numer_bariery - (numer_bariery/9)-1]);
        
        przerwij_polaczenie_poziome(numer_bariery);
        przerwij_polaczenie_poziome(numer_bariery-1);
        
        //ustawienie na tablicy booli
        czy_bariera_juz_tu_stoi_poziom[numer_bariery] = 1;
        czy_bariera_juz_tu_stoi_martwe[numer_bariery - (numer_bariery/9)-1] = 1;
        czy_bariera_juz_tu_stoi_poziom[numer_bariery-1] = 1;
    }
}

