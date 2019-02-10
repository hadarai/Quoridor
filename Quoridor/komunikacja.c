//
//  komunikacja.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 15/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "komunikacja.h"

//extern PipesPtr potoki;
//extern struct pozycja pozycja_gracza;
//extern struct pozycja pozycja_przeciwnika;
extern char wiadomosc[6];
//extern GtkWidget *wszystkie_guziki[9][9];

void wyslij_ruch(int x_gracza, int y_gracza, PipesPtr potoki)
{
    //    char wiadomosc[] = "r x y";

    sprintf(wiadomosc, "r %d %d", x_gracza, y_gracza);
    //    wiadomosc[2] = x_gracza + '0';
    //    wiadomosc[4] = y_gracza + '0';
    //    printf("%s", wiadomosc);
    sendStringToPipe(potoki, wiadomosc);
    //    int result = fprintf(potoki->fifo_out,"%s",wiadomosc);
    //    fflush(potoki->fifo_out);
    //    if (result == 0)
    //        pokazBlad("Failed to send data");
}

gboolean odczytaj_wiadmosc(gpointer data)
{
//    extern PipesPtr potoki;
    PipesPtr potoki = (PipesPtr)data;
    extern bool moj_ruch;
    extern struct pozycja pozycja_przeciwnika;
    gchar wejscie[10];
    if(getStringFromPipe(potoki, wejscie, 10))
    {
        if(wejscie[0] == 'r')
        {
            int wsp_x = 8 - (wejscie[2] - '0');
            int wsp_y = 8 - (wejscie[4] - '0');
            
            ruch_przeciwnika(wsp_x, wsp_y);
            printf("%d %d", wsp_x, wsp_y);
//            wyswietl_przeciwnika(wsp_x, wsp_y);
        }
        printf("odczytalem wiadoamosc");
//        printf("%s", wejscie);
        
        moj_ruch = true;
    }
    return TRUE;
}

//static gboolean pobierz_tekst(gpointer data)
//{
//    gchar wejscie[MAKS_DL_TEKSTU + 5];
//
//    strcpy(wejscie, twoj_id);
//    if (getStringFromPipe(potoki, wejscie + strlen(wejscie), MAKS_DL_TEKSTU))
//    {
//        strcat(wejscie, "\n");
//        gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(bufor), wejscie, -1);
//    }
//    return TRUE;
//}

void stalo_sie()
{
    printf("cos sie stalo\n");
}
void stalo_sie_bariera()
{
    printf("Bariera zostala umieszczona.\n");
}
void pole_do_ruchu()
{
    printf("Mam sie ruszyc\n");
}
//void ruch(struct dane_o_ruchu dane)
//{
//}
