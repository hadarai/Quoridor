//
//  interfejs_bariery.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 19/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_bariery.h"

void stawianie_bariery_poziomej(GtkWidget *widget, struct bomba *dane_smieszne)
{
//    printf("Bariera poziomabe\n");
    
//    dane_smieszne->numer_w_tablicy = 10;
//    printf("jestem %d \n", dane_smieszne->numer_w_tablicy);
    return;
}
void stawianie_bariery_pionowej(GtkWidget *widget, struct bomba *dane_smieszne)
{
//    printf("Bariera pionowa\n");
    
    //    extern GtkWidget *bariery_pionowe[];
    //    GtkWidget *image;
    //    image = gtk_image_new_from_file ("bariera.png");
    //    gtk_container_add (GTK_CONTAINER (bariery_pionowe[7]), image);
    
//    dane_smieszne->numer_w_tablicy = 10;
//    printf("jestem %d \n", dane_smieszne->numer_w_tablicy);
    return;
}

void bariera_pozioma(GtkWidget *widget)
{
    printf("jestem pozioma");
}
void bariera_pionowa(GtkWidget *widget)
{
    printf("jestem pionowa\n");
}
void bariera_martwa(GtkWidget *widget)
{
    printf("jestem martwa\n");
}
