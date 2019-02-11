//
//  interfejs_bariery.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 19/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_bariery.h"
extern bool moj_ruch;

void stawianie_bariery_poziomej(GtkWidget *widget, GdkEvent *pomocniczy, struct dane_bariery *super_dane)
{
//    if(!moj_ruch) return;
    
    miedzy_kim_jestes_poziom(super_dane->numer_w_tablicy);
    
    
    
    
//    super_dane->numer_w_tablicy = 10;
    printf("Poziom: %d \n", super_dane->numer_w_tablicy);
    
//    GtkWidget *grafika_bariery;
//    grafika_bariery = gtk_image_new_from_file ("bariera.png");
//    gtk_container_add (GTK_CONTAINER (super_dane->tablica_barier[super_dane->numer_w_tablicy]), grafika_bariery);
    
    moj_ruch = false;
    return;
}
void stawianie_bariery_pionowej(GtkWidget *widget, GdkEvent *pomocniczy, struct dane_bariery *super_dane)
{
//    if(!moj_ruch) return;
    
//    printf("Bariera pionowa\n");
    
//        GtkWidget *grafika_bariery;
//        grafika_bariery = gtk_image_new_from_file ("bariera.png");
//        gtk_container_add (GTK_CONTAINER (super_dane->tablica_barier[super_dane->numer_w_tablicy]), grafika_bariery);
    
//    dane_smieszne->numer_w_tablicy = 10;
    miedzy_kim_jestes_pion(super_dane->numer_w_tablicy);
    printf("Pion: %d \n", super_dane->numer_w_tablicy);
    
    moj_ruch = false;
    return;
}

void bariera_pozioma_przedstaw(GtkWidget *widget)
{
    printf("jestem pozioma");
}
void bariera_pionowa_przedstaw(GtkWidget *widget)
{
    printf("jestem pionowa\n");
}
void bariera_martwa_przedstaw(GtkWidget *widget)
{
    printf("jestem martwa\n");
}
