//
//  mechanika.c
//  Quoridor
//
//  Created by Maksymilian Czudziak on 14/01/2019.
//  Copyright © 2019 Maksymilian Czudziak. All rights reserved.
//

#include "mechanika_grafu.h"

//bool* nowa_macierz_sasiedztwa()
//{
//    const unsigned int rozmiar_planszy = 81;
//    const unsigned int rozmiar_macierzy = rozmiar_planszy * rozmiar_planszy;
//    bool macierz_sasiedztwa[rozmiar_macierzy][rozmiar_macierzy];
//    for(unsigned int i=1;i < rozmiar_macierzy;i++)
//    {
//        for (unsigned int j=1 ;j < rozmiar_macierzy; j++)
//        {
//            //z tym po lewej
//            macierz_sasiedztwa[i][i-1] = true;
//            macierz_sasiedztwa[i-1][i] = true;
//
//            macierz_sasiedztwa[j][j-1] = true;
//            macierz_sasiedztwa[j-1][j] = true;
//            //z tym po prawej
//            macierz_sasiedztwa[i][i+1] = true;
//            macierz_sasiedztwa[i+1][i] = true;
//
//            macierz_sasiedztwa[j][j+1] = true;
//            macierz_sasiedztwa[j+1][j] = true;
//            //z tym wyzej
//
//
//            //z tym nizej
//
//
//        }
//    }
//    return &macierz_sasiedztwa;
//}
