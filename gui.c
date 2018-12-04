#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "gui.h"


void pozycja(const int x, const int y)
{
    COORD coord = { x, y};
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void clear_screen()
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &info );
    int szerokosc = info.dwSize.X;
    int wiersz = 0;
        pozycja(0,0);

        for(wiersz;wiersz<15;wiersz++)
        {
            int x = 0;
                for(x;x<szerokosc-1;x++) printf(" ");

                printf("\n");
        }
        pozycja(0,0);
}

void quick_clear(void)
{
    int wiersz = 0;
    pozycja(0,0);
        for(wiersz;wiersz<12;wiersz++)
            printf("                                           \n");
        pozycja(0,0);
}

void draw_title()
{
    char title1[100] = {"  _  __         _                      _   ___         _    "};
    char title2[100] = {" | |/ /___ _  _| |__  ___  __ _ _ _ __| | | _ \\_  _ __| |_  "};
    char title3[100] = {" | ' </ -_) || | '_ \\/ _ \\/ _` | '_/ _` | |   / || (_-< ' \\ "};
    char title4[100] = {" |_|\\_\\___|\\_, |_.__/\\___/\\__,_|_| \\__,_| |_|_\\\\_,_/__/_||_|"};
    char title5[100] = {"           |__/                                             "};
        clear_screen();
    pozycja(18,1);
        printf("%s",title1);
    pozycja(18,2);
        printf("%s", title2);
    pozycja(18,3);
        printf("%s", title3);
    pozycja(18,4);
        printf("%s", title4);
    pozycja(18,5);
        printf("%s", title5);
    pozycja(76,1);
        printf("TM");
    pozycja(55,5);
        printf("1990 Birch Studios ltd.");
    pozycja( 3,1);
        printf("START");
    pozycja( 3,3);
        printf("OPCJE");
    pozycja(3,5);
        printf("JAK GRAC?");
    pozycja( 3,7);
        printf("WYJSCIE");
}

void rysowanie_instrukcji(void)
{
    pozycja(2,1);
        printf("Jak grac w Keyboard Rush?");
    pozycja(2,3);
        printf("Gra polega na wpisaniu na kawiaturze slow wyswietlanych");
    pozycja(2,4);
        printf("na ekranie. Ale uwazaj! Slowa szybko spadaja do konca");
    pozycja(2,5);
        printf("planszy, musisz je wpisac zanim dotkna konca ekranu!");
    pozycja(2,5);
        printf("Aby poprawnie wpisywac slowa uzywaj klawiatury i");
    pozycja(2,6);
        printf("pamietaj o poprawnym ulozeniu palacow na klawiszach.");
    pozycja(2,7);
        printf("Za kazde wpisane poprawnie slowo dostaniesz jeden");
    pozycja(2,8);
        printf("punkt,a pod koniec rundy twoje punkty zostana");
    pozycja(2,9);
        printf("wyswietlone ne ekranie. W kazdej chwili mozesz");
    pozycja(2,10);
        printf("przerwac rozgrywke wciskajac ESC.");

}

int rysowanie_opcji(void)
{
    int word_speed;
    int wykonuj;
    int wybor = 2;
    int poprzedniwybor;

    pozycja( 5,3);
        printf("WYBIERZ POZIOM TRUDNOSCI:");
    pozycja( 5,5);
        printf("LATWY");
    pozycja( 5,7);
        printf("SREDNI");
    pozycja( 5,9);
        printf("TRUDNY");
    while(wykonuj!=0)
    {
        pozycja(4,wybor*2 + 1);
            printf(">");
        poprzedniwybor = wybor;
        switch(getch())
            {
            case 224:
            {
                switch(getch())
                {
                    case 72:            //gora
                        if(2<wybor) wybor--;
                            else wybor = 4;
                        break;

                    case 80:            //dol
                        if(wybor <4) wybor++;
                            else wybor = 2;
                        break;

                    case 77:            //prawo
                        switch(wybor)
                        {
                            case 2:
                                word_speed = 200; //latwy
                                wykonuj = 0;
                                break;
                            case 3:
                                word_speed = 145; //sredni
                                wykonuj = 0;
                                break;
                            case 4:
                                word_speed = 95; //trudny
                                wykonuj = 0;
                                break;
                            }
                    }
                }
                }
        pozycja(4, poprzedniwybor * 2 + 1);
            printf(" ");
    }
    return word_speed;
}
