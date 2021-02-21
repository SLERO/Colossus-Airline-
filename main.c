/* Colossus Airline -- Program for booking tickets for 4 flights. */
#include <stdio.h>
//#include <stdbool.h>    // for booking
//#include <string.h>
//#include <stdlib.h>     // for exit
//#include <ctype.h>      // for tolower
#include "secondary_funk.h"
#include "menu_processing.h"
#include "display_menu.h"
#include "work_file.h"
#include "head_crab.h"



int main (void)
{
     struct disco flights[RACE][PLC];

     file_reader_start (flights,PLC, RACE);
     show_race_menu (flights, PLC, RACE);
    return 0;
}
