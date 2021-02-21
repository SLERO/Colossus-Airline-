#include <stdio.h>
#include <string.h>

#include "menu_processing.h"
#include "secondary_funk.h"


void show_num_free_seats (const struct disco small_air[], int seat )
{
      int i;
      int sum = 0;
      char sign_1 = '#';

      for (i = 0; i < seat; i++)
      {
          if (small_air[i].ready)
            sum++;
      }
      line_painter(sign_1);
      if (sum == 0)
        {
            printf("Completely FILLED\n");
            printf("Free seats %d \n",sum);
        }
      else
           printf("Free seats %d \n",sum);
      line_painter(sign_1);                  // ??? why do you need
}


void show_list_free_seats (const struct disco small_air[], int seat)
{
     char * free = "FREE";
     char sign_1 = '#';
     int i;

     line_painter(sign_1);
     for (i = 0; i < seat; i++)
     {
         if (small_air[i].ready)
         {

             printf("Mesto #%d  %s \n", small_air[i].place, free);
         }
         else
            printf("Mesto #%d  ARMOR\n", small_air[i].place);
     }
     line_painter(sign_1);
}

void show_list_reseved_seats_alfabet (const struct disco small_air[], int seat)
{
    int  z, y,  primo, secund;
    int fire = 0;
    char sign_1 = '#';

   struct simple
    {
       int number;
       const char * stroka1;   // !!! const
       const char * stroka2;
    };

    struct simple rat[seat];
    struct simple rat_temp;

    // подсчет числа бронир мест

    for (y = 0; y < seat; y++)
        if ( !(small_air[y].ready))
         {
            rat[fire].number  = small_air[y].place;
            rat[fire].stroka1 = small_air[y].revashol.fname;
            rat[fire].stroka2 = small_air[y].revashol.lname;
            fire++;
         }

    for (primo = 0; primo < fire - 1; primo++)
        for(secund = primo + 1; secund < fire; secund++)
          if (strcmp(rat[primo].stroka1, rat[secund].stroka1) > 0)
            {
                rat_temp    = rat[primo];
                rat[primo]  = rat[secund];
                rat[secund] = rat_temp;
            }
    line_painter(sign_1);
    for (z = 0; z < fire; z++)
        printf("%d. %-20s %-20s armor place %d \n",z+1,rat[z].stroka1,
        rat[z].stroka2,rat[z].number);
    line_painter(sign_1);

}
void book_seat (struct disco small_air[])
{
       int select;
       char krass[20];
       char sign_1 = '-';

       printf("Enter place nunmber: ");
       while (1)                              //  checking the correctness of the seat number
       {
           if (scanf("%d",&select) == 1 && select > 0 && select < 13)
             {
                 cleaner_input();
                 if (small_air[select - 1].ready == false)    // overwrite protection
                 {
                     printf("ERROR: place already booked!\n");
                     printf("Enter place nunmber: ");
                     continue;
                 }
                 break;
             }
           else
             {
                 printf("NUMBER FROM 1 to 12 ONLY \n");
                 cleaner_input();
                 continue;
             }
       }
       small_air[select - 1].ready = false;       // select - 1 !!!!
       printf("Enter your FIRST name : ");
       scanf("%20s",krass);
       cleaner_input();
       strcpy(small_air[select - 1].revashol.fname, krass);
       printf("Enter your LAST name : ");
       scanf("%20s",krass);
       cleaner_input();
       strcpy(small_air[select - 1].revashol.lname, krass);
       line_painter(sign_1);
       //cleaner_input();

}
void remove_armor (struct disco small_air[])
{
       int select;

       printf("Specify a place to withdraw your reservation");
       printf("or not number to cancel: ");

       while (1)                              //  checking the correctness of the seat number
       {
           if (scanf("%d",&select) == 1 && select > 1 && select < 13)
             {
                 cleaner_input();
                 small_air[select - 1].ready = true;
                 break;
             }
           else
             {
                 cleaner_input();
                 break;
             }
       }

}

/* void file_eraser   (void)
{
    FILE * exodus;
  //  char yes = 'y';
  //  char no  = 'n';       // screw up the intent check to erase the file
    char hellfire;
    char sign_1 = '#';

    while (1)
    {
        printf("WARNING! DANGER! To confirm file cleanup ");
        printf("press enter \"Y\" to abort \"N\" \n");
        if (scanf("%c",&hellfire)== 1 && hellfire == 'Y')
        {
              line_painter(sign_1);
              if ((exodus = fopen(DATAFILE,"wb")) == NULL)
                {
                    printf("Collapse open file for save");
                }
              else
                   printf("Erase file complete\n");
              fclose(exodus);
              for (int i = 0; i < 3; i++)
                       line_painter(sign_1);
             cleaner_input();
        }
        else if (hellfire == 'N')
        {
            printf("Operation canceled\n");   //  no confirm - exit from function
            line_painter(sign_1);
            cleaner_input();
            break;
        }
        else
            printf("Incorrect input\n");
        cleaner_input();
        continue;
    }

}

    */
