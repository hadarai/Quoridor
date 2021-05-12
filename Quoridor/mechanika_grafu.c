//
//  mechanika.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 14/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "mechanika_grafu.h"

void uzupelnij_graf(bool graf[][81])
{

    for (int i = 0; i < 81; i++)
    {
        for (int j = 0; j < 81; j++)
        {
            if (czy_sasiaduja(i, j))
            {
                graf[i][j] = 1;
            }
        }
    }
}

bool czy_sasiaduja(int x, int y)
{
    if (x == y)
        return true;
    // czy z x da sie dojsc w 1 ruchu do y
    //sasiad z lewej
    if (y - 1 == x)
    {
        return true;
    }
    //sasiad z prawej
    if (y + 1 == x)
    {
        return true;
    }
    //sasiad z gory
    if (y - 9 == x)
    {
        return true;
    }
    //sasiad z dolu
    if (y + 9 == x)
    {
        return true;
    }
    return false;
}

bool czy_moge_przejsc_na_grafie(int x_gracza, int y_gracza, int x_dokad, int y_dokad)
{
    extern bool graf_polaczen_pol[81][81];
    int numer_pola_gracza = ((y_gracza * 9) + x_gracza);
    int numer_pola_dokad = ((y_dokad * 9) + x_dokad);

    return graf_polaczen_pol[numer_pola_gracza][numer_pola_dokad];
}

void przerwij_polaczenie_pionowe(int numer_bariery_pionowej)
{
    extern bool graf_polaczen_pol[81][81];

    int kolumna = numer_bariery_pionowej % 8;
    int rzad = numer_bariery_pionowej / 8;

    int pole1 = kolumna + (rzad * 9);
    int pole2 = kolumna + 1 + (rzad * 9);

    //    printf("Przerywam: %d i %d\n", pole1, pole2);

    graf_polaczen_pol[pole1][pole2] = 0;
    graf_polaczen_pol[pole2][pole1] = 0;
}

void przerwij_polaczenie_poziome(int numer_bariery_poziomej)
{
    extern bool graf_polaczen_pol[81][81];
    int kolumna = numer_bariery_poziomej % 9;
    int wiersz = numer_bariery_poziomej / 9;

    int pole1 = kolumna + (9 * wiersz);
    int pole2 = kolumna + (9 * (wiersz + 1));

    //    printf("Przerywam: %d i %d\n", pole1, pole2);

    graf_polaczen_pol[pole1][pole2] = 0;
    graf_polaczen_pol[pole2][pole1] = 0;
}

void przywroc_polaczenie_pionowe(int numer_bariery_pionowej)
{
    extern bool graf_polaczen_pol[81][81];

    int kolumna = numer_bariery_pionowej % 8;
    int rzad = numer_bariery_pionowej / 8;

    int pole1 = kolumna + (rzad * 9);
    int pole2 = kolumna + 1 + (rzad * 9);

    //    printf("Przywracam: %d i %d\n", pole1, pole2);

    graf_polaczen_pol[pole1][pole2] = 1;
    graf_polaczen_pol[pole2][pole1] = 1;
}

void przywroc_polaczenie_poziome(int numer_bariery_poziomej)
{
    extern bool graf_polaczen_pol[81][81];
    int kolumna = numer_bariery_poziomej % 9;
    int wiersz = numer_bariery_poziomej / 9;

    int pole1 = kolumna + (9 * wiersz);
    int pole2 = kolumna + (9 * (wiersz + 1));

    //    printf("Przywracam: %d i %d\n", pole1, pole2);

    graf_polaczen_pol[pole1][pole2] = 1;
    graf_polaczen_pol[pole2][pole1] = 1;
}

bool czy_moge_postawic_bariere_poziomo(int numer_bariery_poziomej)
{
    przerwij_polaczenie_poziome(numer_bariery_poziomej);
    przerwij_polaczenie_poziome(numer_bariery_poziomej + 1);
    extern struct pozycja pozycja_gracza;
    extern struct pozycja pozycja_przeciwnika;

    int numer_wierzcholka_startowego_gracza = pozycja_gracza.y * 9 + pozycja_gracza.x;
    int numer_wierzcholka_startowego_przeciwnika = pozycja_przeciwnika.y * 9 + pozycja_przeciwnika.x;

    bool czy_gracz_moze_przejsc = DFS(numer_wierzcholka_startowego_gracza, 0);
    bool czy_przeciwnik_moze_przejsc = DFS(numer_wierzcholka_startowego_przeciwnika, 8);

    przywroc_polaczenie_poziome(numer_bariery_poziomej);
    przywroc_polaczenie_poziome(numer_bariery_poziomej + 1);

    return czy_gracz_moze_przejsc && czy_przeciwnik_moze_przejsc;
    ;
}

bool czy_moge_postawic_bariere_pionowo(int numer_bariery_pionowej)
{
    przerwij_polaczenie_pionowe(numer_bariery_pionowej);
    przerwij_polaczenie_pionowe(numer_bariery_pionowej + 8);
    extern struct pozycja pozycja_gracza;
    extern struct pozycja pozycja_przeciwnika;

    int numer_wierzcholka_startowego_gracza = pozycja_gracza.y * 9 + pozycja_gracza.x;
    int numer_wierzcholka_startowego_przeciwnika = pozycja_przeciwnika.y * 9 + pozycja_przeciwnika.x;

    bool czy_gracz_moze_przejsc = DFS(numer_wierzcholka_startowego_gracza, 0);
    bool czy_przeciwnik_moze_przejsc = DFS(numer_wierzcholka_startowego_przeciwnika, 8);

    przywroc_polaczenie_pionowe(numer_bariery_pionowej);
    przywroc_polaczenie_pionowe(numer_bariery_pionowej + 8);

    return czy_gracz_moze_przejsc && czy_przeciwnik_moze_przejsc;
}

void miedzy_kim_jestes_pion(int numer_bariery)
{
    int kolumna = numer_bariery % 8;
    int rzad = numer_bariery / 8;

    int pole1 = kolumna + (rzad * 9);
    int pole2 = kolumna + 1 + (rzad * 9);

    printf("Jestem pionowo miedzy %d, a %d.\n", pole1, pole2);
}
void miedzy_kim_jestes_poziom(int numer_bariery)
{
    int kolumna = numer_bariery % 9;
    int wiersz = numer_bariery / 9;

    int pole1 = kolumna + (9 * wiersz);
    int pole2 = kolumna + (9 * (wiersz + 1));
    printf("Jestem poziomo miedzy %d, a %d.\n", pole1, pole2);
}
bool DFS(int wierzcholek_startowy, int rzad_koncowy)
{
    extern bool graf_polaczen_pol[81][81];
    //    printf("od %d do %d\n", wierzcholek_startowy, rzad_koncowy);
    int kolejka[90], pozycja_pierwszego = wierzcholek_startowy, koniec_kolejki = 0, poczatek_kolejki = 0;
    bool wierzcholki_odwiedzone[81] = {0};

    kolejka[koniec_kolejki] = pozycja_pierwszego;
    wierzcholki_odwiedzone[pozycja_pierwszego] = 1;
    koniec_kolejki++;

    while (poczatek_kolejki != koniec_kolejki)
    {
        int poprzedni = kolejka[poczatek_kolejki];
        poczatek_kolejki++;
        for (int i = 0; i < 81; i++)
        {
            if (graf_polaczen_pol[poprzedni][i] == 1 && wierzcholki_odwiedzone[i] == 0)
            {
                //                printf("%d ", i);
                kolejka[koniec_kolejki] = i;
                koniec_kolejki++;
                wierzcholki_odwiedzone[i] = 1;
                if (rzad_koncowy == 0)
                {
                    if (i == 4)
                    {
                        //                        printf("\n");
                        return true;
                    }
                }
                if (rzad_koncowy == 8)
                {
                    if (i == 76)
                    {
                        //                       printf("\n");
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
void wypisz_graf()
{

    extern bool graf_polaczen_pol[81][81];
    //    printf("\n\n");
    for (int i = 0; i < 81; i++)
    {
        for (int j = 0; j < 81; j++)
        {
            printf("%d ", graf_polaczen_pol[i][j]);
        }
        printf("\n%d ", i);
    }
}
