#ifndef MENU_PROCESSING_H_INCLUDED
#define MENU_PROCESSING_H_INCLUDED

#include "head_crab.h"

void show_num_free_seats (const struct disco small_air[], int seat );
void show_list_free_seats (const struct disco small_air[], int seat);
void show_list_reseved_seats_alfabet (const struct disco small_air[], int seat);
void book_seat (struct disco small_air[]);
void remove_armor (struct disco small_air[]);
void file_eraser   (void);

#endif // MENU_PROCESSING_H_INCLUDED
