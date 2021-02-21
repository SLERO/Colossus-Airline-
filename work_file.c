#include <stdio.h>
#include <stdlib.h>

#include "work_file.h"
#include "secondary_funk.h"
#include "head_crab.h"


int file_reader_start (struct disco big_air[][PLC], int seat, int skyfly)
{
      FILE * exodus;
      long int sentinel;
      int bum;

      if ((exodus = fopen(DATAFILE,"ab+")) == NULL)
      {
          printf("Collapse open file for load");
          exit(1);
      }
      fseek(exodus,0,SEEK_END);             //  file empty check - last byte number 0
      sentinel = ftell(exodus);
      if (sentinel == 0)                    // file empty - initialization of structures array
            bool_and_place_controler (big_air, seat, skyfly);   // !!!!
      else
      {
           fseek(exodus,0,SEEK_SET);         // return cursor to the beginning file
           for (bum = 0; bum < skyfly; bum++)
           {
               fread(big_air[bum], seat, sizeof(big_air[0][0]), exodus);
           }                                 // READ by SEAT (!!12) blocks SKYFLY  times
           fclose(exodus);                   // file is not empty - copy from it
           printf("Loading data from file completed\n");
           line_painter('-');
      }

      return 0;
}

void file_writer_exit (struct disco big_air[][PLC], int seat, int skyfly)
{
      FILE * exodus;
      int bum;
      char sign_1 = '-';

      if ((exodus = fopen(DATAFILE,"wb")) == NULL)
      {
          printf("Collapse open file for save");
      }
      for (bum = 0; bum < skyfly; bum++)
      {
          fwrite(big_air[bum],seat,sizeof(big_air[0][0]),exodus);
      }        // write by SKYFLY blocks BUM  times
      fclose(exodus);
      printf("Save and exit are done correctly");
      line_painter(sign_1);

}

void bool_and_place_controler (struct disco big_air[][PLC], int seat, int skyfly)
{
    int i , z;
    char sign_1 = '-';
    printf("File empty, auto-initialization\n");
    line_painter(sign_1);

    for (i = 0; i < skyfly; i++)
      for (z = 0; z <seat; z++)
        {
            big_air[i][z].ready = true;
            big_air[i][z].place = i + 1;
        }
}

void data_devastator_selective (struct disco big_air[][PLC] , int num_fly)
{
    int i, z , m;
  //  int race;
    char sign_1 = '-';
    char hellfire;
    FILE * exodus;
    long int black_hawk;

    struct disco devastator[PLC];

    for (i = 0; i < PLC; i++)
    {
        devastator[i].ready = true;
        devastator[i].place = i + 1;
          for (z = 0; z < LIM; z++)
          {
              devastator[i].revashol.fname[z] = '\0';
              devastator[i].revashol.lname[z] = '\0';
          }
    }

    while (1)
    {
        printf("WARNING! DANGER! To confirm DATA FLY cleanup ");
        printf("press enter \"Y\" to abort \"N\" \n");
        if (scanf("%c",&hellfire)== 1 && hellfire == 'Y')
        {
              line_painter(sign_1);
              if ((exodus = fopen(DATAFILE,"rb+")) == NULL)
                {
                    printf("Collapse open file for save");
                }
              else
                   {   // redundant - cleaning the RAM is enough
                       black_hawk = sizeof(struct disco) * PLC * num_fly;
                       fseek(exodus,black_hawk,SEEK_SET);
                       fwrite(devastator, PLC, sizeof(devastator[0]),exodus);
                       printf("Erase DATA FLY #%d complete\n", race_num_check(num_fly));
                       // and on exit it will be copied to a file
                       // but for demonstration let it be
                       for (m = 0; m < PLC; m++)
                         big_air[num_fly][m] = devastator[m];
                   }
              fclose(exodus);
              for (int i = 0; i < 3; i++)
                       line_painter(sign_1);
             cleaner_input();
             break;
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
