#include <stdio.h>
#include <stdlib.h>
#include "gui.h"
#include "minigame.h"

int main()
{
int word_speed = 250;
hidecursor();
{
    while( 1 ){
    int wykonuj = 1;
    int wybor = 0;
    int poziom = 1;
    int poprzedniwybor;
    poprzedniwybor = wybor;
    draw_title();
    while( wykonuj!=0)
    {
        pozycja(1, wybor * 2 + 1);
        printf(">");

        poprzedniwybor = wybor;
        switch( getch())
        {
        case 224:
            switch ( getch())
            {
                case 72: //gora
                    if(0<wybor) wybor--;
                    else wybor = 3;
                    break;

                case 80:    //dol
                    if(wybor <3) wybor++;
                    else wybor = 0;
                    break;

                case 77: //prawo
                    switch(wybor)
                    {
                    case 0:
                        clear_screen();
                        mini_game(word_speed);
                        wykonuj = 0;
                        break; //start
                    case 1:
                        clear_screen();
                        word_speed = rysowanie_opcji();
                        wykonuj = 0;
                        break; //opcje
                    case 2:
                        clear_screen();
                        rysowanie_instrukcji();
                        getch();
                        wykonuj = 0;
                        break;

                    case 3:
                        return 0; //wyjscie z petli programu

                    }
            }
            break;

        }
        pozycja(1, poprzedniwybor * 2 + 1);
        printf(" ");


    }

}
}
return 0;
}
