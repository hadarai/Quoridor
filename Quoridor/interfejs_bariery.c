//
//  interfejs_bariery.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 19/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "interfejs_bariery.h"


//void uaktywnij_bariery(GtkWidget *bariery[], const unsigned short int ilosc)
//{
//    for(int i=0;i<ilosc;i++)
//    {
//
//    }
//}

void stawianie_bariery(GtkWidget *widget, struct dane_bariery *bariera)
{
    printf("x%d y%d", bariera->x, bariera->y);
//    printf("eloooo");
    char magia[10];
    
    sprintf(magia, "siemaiu");
    //    wiadomosc[2] = x_gracza + '0';
    //    wiadomosc[4] = y_gracza + '0';
    //    printf("%s", wiadomosc);
//    sendStringToPipe(bariera->potoki, magia);
    
}

void bariera_pozioma(GtkWidget *widget)
{
    printf("jestem pozioma\n");
}
void bariera_pionowa(GtkWidget *widget)
{
    printf("jestem pionowa\n");
}
void bariera_martwa(GtkWidget *widget)
{
    printf("jestem martwa\n");
}
