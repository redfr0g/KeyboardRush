#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "minigame.h"
#include "gui.h"

void zerowanie_tablicy(char tab[])
{
int dlugosc;
dlugosc = sizeof(tab)/sizeof(char);
    int i;
        for(i=0;i<dlugosc;i++)
        {
            tab[i]=0;
        }
}

void rysowanie_mety(void)
{
    const char meta[128] = {"*---------------------------------------*"};

    pozycja(0,11);
    printf("%s",meta);
}

int skanowanie_bazy()
{
    FILE *bsize;
    bsize = fopen("baza.txt","r");
    int rozmiar_bazy = 0;
    char schowek[10];
        while(feof(bsize) == 0)
        {
            fscanf(bsize,"%s",schowek);
            rozmiar_bazy++;
        }
    return rozmiar_bazy;
}

void mini_game(int word_speed)
{
    int rozmiar_bazy = skanowanie_bazy();
    int end=0;
    int runda = 0;
    int punkty = 0;
while(end!=1)
{

    srand( time( NULL ));
    char word[10];
    int size;
    FILE *base;
    base = fopen("baza.txt", "r");
    int base_stop = 0;
    int num = rand()%rozmiar_bazy;
        for(base_stop;base_stop<num+1;base_stop++)
            {
                fgets(word,10,base);
            }
    int lenght = 0;
    int word_stop;
    while(word[lenght]!='\0' && word[lenght]!='\n')
    {
        lenght++;
    }

    char wzor[lenght];
        for(word_stop=0;word_stop<lenght;word_stop++)
        {
            wzor[word_stop] = word[word_stop];
            }
        clear_screen();

    char bufor[lenght];
    zerowanie_tablicy(bufor);
    char znak;
    int height_buff;
    int fall_buff = 1;
    int fall_limit = 0;
    int tab_num = 0;
    int koniec=1;
    int sprawdz;
    while(koniec!=0 && fall_limit!=10){
    for(fall_limit=0;fall_limit<10;fall_limit++){

        height_buff=0;

        while(height_buff<fall_buff)
        {
            while(height_buff<fall_buff)
            {
                printf("\n");
                height_buff++;
            }

            printf("            ");
            printf("%s", word);
            rysowanie_mety();
            pozycja(30,10);
            printf("Punkty:%d",punkty);

                while(kbhit())
                {
                znak=getch();
                bufor[tab_num]=znak;
                    if(znak == 27)
                    {
                    end = 1;
                    word_speed = 0;
                    break;
                    }
                tab_num++;
                }
            Sleep(word_speed);
            quick_clear();
        }
        fall_buff++;
        }
    sprawdz = strncmp(bufor,wzor,lenght);
        if(sprawdz = 0)
        {
            word_speed = 0;
        }
    }

    if(strncmp(bufor,wzor,lenght) == 0)
        {
            pozycja(8,4);
            printf("*** WYGRALES! ***");
            Sleep(400);
            punkty++;
        }
        else
        {
            pozycja(8,4);
            printf("*** PRZEGRALES! ***");
            Sleep(400);
        }
    runda++;
        if(runda == 10)
        {
            clear_screen();
            pozycja(3,3);
            printf("KONIEC GRY! ZDOBYLES %d PUNKTOW!",punkty);
        if(getch())
        {
            end = 1;
        }
        }
        else continue;
    fclose(base);
    }

}
