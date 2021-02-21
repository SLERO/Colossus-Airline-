#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "head_crab.h"
#include "display_menu.h"
#include "menu_processing.h"
#include "work_file.h"
#include "secondary_funk.h"

#define LIM_STR 5             // main menu bars
#define LIM_STO 7             // flight operations menu bar
#define LIM_RAC 4             // number of flights

void show_race_menu (struct disco big_air[][PLC] , int seat , int skyfly)
{
                int fly_num;

                do {
                     fly_num = qwestion_race_num();
                       if (fly_num == -1)
                           {
                              file_writer_exit(big_air, seat, skyfly);
                              exit(0);
                           }
                        else
                            show_menu_operation (big_air, fly_num,  seat, skyfly);
                   }while (1);
}

void show_menu_operation(struct disco big_air[][PLC], int fly_num , int seat, int skyfly)
{
        char strike;
        char sign_1 = '-';
        char sign_3 = '~';

        char * link[LIM_STO] = {
        link[0] = "a) Show the NUMBER of free seats",
        link[1] = "b) Show the LIST of free places",
        link[2] = "c) Show a list of reserved seats in alphabetical order",
        link[3] = "d) Book a seat for a passenger",
        link[4] = "e) Remove armor from place",
        link[5] = "f) Return flight selection",
        link[6] = "g) WARNING! Erase save file"
        };

        do {
            for (int i = 0; i < LIM_STO; i++)         // show menu
                printf("%s \n",link[i]);
            line_painter(sign_3);
            line_painter(sign_3);
            printf("Flight #%d is being processed.\n",race_num_check(fly_num));
            line_painter(sign_1);
            printf("Select the desire action: ");
            strike = getchar();          // or SCANF ?     unknown perevod stroki !!!
            strike = tolower(strike);    // font alignment
            line_painter(sign_1);
            cleaner_input();
             switch(strike)
             {
                case 'a' : show_num_free_seats            (big_air[fly_num],seat); break;
                case 'b' : show_list_free_seats           (big_air[fly_num],seat); break;
                case 'c' : show_list_reseved_seats_alfabet(big_air[fly_num],seat); break;
                case 'd' : book_seat                      (big_air[fly_num]); break;
                case 'e' : remove_armor                   (big_air[fly_num]); break;
                case 'f' : show_race_menu                 (big_air, seat, skyfly) ;   break;  // !!!!!
                case 'g' : data_devastator_selective      (big_air, fly_num); break;
                default : puts("INPUT NOT RECOGNIZED! REPEAT."); break;
             }
        }while (strike != 'f');
}

int qwestion_race_num (void)
{
         int voyage , zet , noo,  watch, subfly;
         int check[LIM_STR] = {102,311,444,519,999};
         bool scat = true;                   // control correct number flight
         char sign_1 = '-';
         char sign_2 = '*';

         char * link[LIM_STR] = {
             link[0] = "Flight     102    to Paris",
             link[1] = "Flight     311    to Berlin",
             link[2] = "Flight     444    to Los Angeles",
             link[3] = "Flight     519    to Moskow",
             link[4] = "Enter COD  999    for exit programm"
         };

                 do {
                     for (zet = 0; zet < LIM_STR; zet++)
                        printf("%s \n",link[zet]);
                          line_painter(sign_1);
                       printf("Enter your flight number : ");


                    watch = scanf("%d", &voyage);
                    if (watch != 1)
                     {
                        printf("ERROR! Enter not number. Repeat.\n");
                        line_painter(sign_2);
                        cleaner_input();
                        continue;
                     }
                    else
                     {
                        for (noo = 0; noo < LIM_STR; noo++)
                        {
                            if(check[noo] == voyage)
                                {
                                    if (check[noo] == 999)
                                        {
                                            return -1;          // call exit save function
                                        }
                                    else
                                       {
                                           scat = false;       // break need scat ??
                                           subfly = noo;       //  structure number with flight save
                                           cleaner_input();
                                           //break;
                                           return subfly;
                                       }
                                }
                        }

                        if (scat)
                        {
                             printf("ERROR! INCORRECT number fly. Repeat.\n");
                             line_painter(sign_2);
                             cleaner_input();
                             continue;      // control correct number flight
                        }
                     }

                } while (1);      // scat or simple 1 ??


            //return subfly;
}






