//
//  main.h
//  Quoridor
//
//  Created by Maksymilian Czudziak on 21/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#ifndef main_h
#define main_h

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>

#include "fifo.h"
#include "mechanika_grafu.h"
#include "wydarzenia.h"

#include "interfejs_przygotowanie.h"
#include "interfejs_ruch.h"
#include "interfejs_bariery.h"

void koniec_tury(void);

static GtkWidget *okno_gry, *bufor;
static PipesPtr potoki;
static char *moj_id, *twoj_id;

static void przekaz_tekst(GtkWidget *widget, GtkWidget *text);
static gboolean pobierz_tekst(gpointer data);

static void zakoncz_dzialanie(GtkWidget *widget, gpointer data);

const unsigned short int ilosc_barier = 208;

void pokazBlad(char *komunikat);

int main(int argc, char *argv[]);

static void przekaz_tekst(GtkWidget *widget, GtkWidget *text);

static gboolean pobierz_tekst(gpointer data);

static void zakoncz_dzialanie(GtkWidget *widget, gpointer data);

gboolean moj_ruch = false;

struct pozycja
{
    unsigned int x;
    unsigned int y;
};
#endif /* main_h */
