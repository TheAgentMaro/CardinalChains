#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "main.h"



//Vérifier si les cases ayant valeur 0
void set_zero(plateau level, cursor *chain){
    for(int i=0; i<level.width; i++)
    {
        for (int j=0; j<level.height; j++)
        {
           if (level.grid[i][j].content == 0)
           {
               if (level.grid[i][j].chain_number == chain->chain_number)
               {
                    chain->x = i;
                    chain->y = j;
               }
           }
        }
    }
}


// Mouvement entre les cases
void move(plateau *level, cursor *chain, char *direction)
{
    char bas = 's';
    char haut = 'z';
    char droite = 'd';
    char gauche = 'q';


    if ((*direction == bas) && (level->grid[chain->x+1][chain->y].content > 0)
        && (chain->x+1<level->width) && (level->grid[chain->x+1][chain->y].passed_by ==0))

    {
        chain->x = chain->x+1;
        level->grid[chain->x][chain->y].passed_by = 1;
        level->grid[chain->x][chain->y].previous_direction = bas;
    }

    else if ((*direction == haut) && (level->grid[chain->x-1][chain->y].content > 0)
             && (chain->x-1>=0) && (level->grid[chain->x-1][chain->y].passed_by ==0))

    {
        chain->x = chain->x-1;
        level->grid[chain->x][chain->y].passed_by = 1;
        level->grid[chain->x][chain->y].previous_direction = haut;
    }

    else if ((*direction == droite) && (level->grid[chain->x][chain->y+1].content > 0)
             && (chain->y+1<=level->height) && (level->grid[chain->x][chain->y+1].passed_by ==0))
    {
        chain->y = chain->y+1;
        level->grid[chain->x][chain->y].passed_by = 1;
        level->grid[chain->x][chain->y].previous_direction = droite;
    }

    else if ((*direction == gauche) && (level->grid[chain->x][chain->y-1].content > 0) && (chain->y-1>=0)
             && (level->grid[chain->x][chain->y-1].passed_by ==0))

    {

        chain->y = chain->y-1;
        level->grid[chain->x][chain->y].passed_by = 1;
        level->grid[chain->x][chain->y].previous_direction = gauche;
    }
}


//Corr (retourner à la mouvement precedente)
void precedente(plateau *level, cursor *chain)
{
    char bas = 's';
    char haut = 'z';
    char droite = 'd';
    char gauche = 'q';

    if (level->grid[chain->x][chain->y].previous_direction == bas)
    {
        level->grid[chain->x][chain->y].passed_by = 0;
        chain->x = chain->x-1;
    }

    else if (level->grid[chain->x][chain->y].previous_direction == haut)

    {
        level->grid[chain->x][chain->y].passed_by = 0;
        chain->x = chain->x+1;
    }

    else if (level->grid[chain->x][chain->y].previous_direction == droite)
    {

        level->grid[chain->x][chain->y].passed_by = 0;
        chain->y = chain->y-1;
    }


    else if (level->grid[chain->x][chain->y].previous_direction == gauche)

    {
        level->grid[chain->x][chain->y].passed_by = 0;
        chain->y = chain->y+1;
    }
}

//réinitialisation du plateau
void reset(plateau *level, plateau all_level[], int j)
{
    *level = all_level[j];
}


//Création du plateau (dépend de level)
plateau level_1 = { 3, 1,
                {
                {0,1,1},
                {1,1,0},
                {1,1,0}
                }
                };


plateau level_2 = { 3, 2,

                {
                {{0,1,1},{1,1,0}},
                {{-1,1,0},{1,1,0}},
                {{-1,1,0},{1,1,0}},
                }
                };


plateau level_3 = { 3, 3,
                {
                    {{1,1,0},{1,1,0},{1,1,0}},
                    {{-1,1,0},{-1,1,0},{1,1,0}},
                    {{0,1,1},{1,1,0},{1,1,0}},
                }
                };

plateau level_4 = {5, 5,
                {
                    {{1,1,0},{1,1,0},{1,1,0},{1,1,0},{1,1,0}},
                    {{1,1,0},{-1,1,0},{-1,1,0},{-1,1,0},{1,1,0}},
                    {{1,1,0},{-1,1,0},{0,1,1},{-1,1,0},{1,1,0}},
                    {{1,1,0},{-1,1,0},{1,1,0},{-1,1,0},{1,1,0}},
                    {{1,1,0},{1,1,0},{1,1,0},{-1,1,0},{1,1,0}},
                }
                };

plateau level_5 = {3, 4,
                {
                    {{1,1,0},{1,1,0},{1,1,0},{1,1,0}},
                    {{1,1,0},{-1,1,0},{0,1,1},{1,1,0}},
                    {{1,1,0},{-1,1,0},{1,1,0},{1,1,0}},
                }
                };

plateau level_6 = {5, 5,
                {
                    {{1,1,0},{1,1,0},{1,1,0},{1,1,0},{1,1,0}},
                    {{1,1,0},{-1,1,0},{-1,1,0},{-1,1,0},{1,1,0}},
                    {{1,1,0},{-1,1,0},{0,1,1},{-1,1,0},{1,1,0}},
                    {{1,1,0},{1,1,0},{1,1,0},{1,1,0},{1,1,0}},
                    {{-1,1,0},{-1,1,0},{-1,1,0},{1,1,0},{-1,1,0}},
                }
                };

plateau level_7 = {2, 2,
                {
                    {{0,1,0},{1,1,0}},
                    {{2,1,0},{1,1,0}},
                }
                };

plateau level_8 = {2, 3,
                {
                    {{1,1,0},{1,1,0},{1,1,0}},
                    {{2,1,0},{0,1,1},{1,1,0}},
                }
                };

plateau level_9 = {2, 4,
                {
                    {{0,1,0},{1,1,0},{1,1,0},{2,1,0}},
                    {{-1,1,0},{1,1,0},{1,1,0},{-1,1,0}},
                }
                };

plateau level_10 = {3, 3,
                {
                    {{1,1,0},{2,1,0},{2,1,0}},
                    {{1,1,0},{0,1,1},{1,1,0}},
                    {{1,1,0},{1,1,0},{1,1,0}},
                }
                };

plateau level_11 = {3, 4,
                {
                    {{1,1,0},{1,1,0},{1,1,0},{1,1,0}},
                    {{1,1,0},{-1,1,0},{0,1,1},{1,1,0}},
                    {{1,1,0},{1,1,0},{2,1,0},{3,1,0}},
                }
                };

                void color(int textColor, int bgColor)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,bgColor*16+textColor);

}

//Affichage de level 
void affichage_level(plateau level, int i)
{
    printf("###########################\n");
    printf("###");
    color(9, 0);
    printf("       LEVEL %d       ", i+1);
    color(15, 0);
    printf("###\n");
    printf("###########################\n");
    for (int i=0; i<level.width; i++)
    {
        printf("\n       ");
        for (int j=0; j<level.height; j++)
        {

            if(level.grid[i][j].content == 0)
            {
                color(9, 0);
                printf(" X ");
                color(15, 0);
            }
            else if(level.grid[i][j].content==-1)
            {
                printf("   ");
            }
            else if((level.grid[i][j].passed_by==1) && (level.grid[i][j].content != 0))
            {
                color(9, 0);
                printf(" %d ", level.grid[i][j].content);
                color(15, 0);
            }
            else if(level.grid[i][j].content>0)
            {
                printf(" %d ", level.grid[i][j].content);
            }
        }
    }
    printf("\n\n");
    color(15, 0);
}

// Demande à l'utilisateur d'entrer un valeur
void action(char *action)
{
    char do_action[10];
    printf("To select a direction (Z, S, D, Q)\n");
    printf("To select another chain (A)\n");
    printf("To cancel the previous move (B)\n");
    printf("To erase the chain (X)\n");
    printf("To reset the level (R)\n");
    printf("To go to another level (+/-)\n");
    printf(">> ");
    scanf("%s", do_action);
    *action = do_action[0];
}


// si l'utilisateur gange (arrive au derniére case)
int gange(plateau level)
{
    for (int i = 0; i<level.width; i++)
    {
        for (int j=0; j<level.height; j++)
        {
            if ((level.grid[i][j].passed_by == 0) && (level.grid[i][j].content != -1))
            {
                return 1;
            }
        }
    }
    color(0, 10);
    printf("\n------ LEVEL CLEARED ------\n");
    printf("Type '+' for the next level\n\n");
    color(15, 0);
    return 0;
}


//Fonction main
int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    char *do_smt;

    cursor grid[4];
    grid->chain_number = j+1;


    plateau all_lvl[]= {level_1, level_2, level_3, level_4, level_5, level_6, level_7};
    plateau actual_lvl = all_lvl[j];

    set_zero(actual_lvl, &(grid[0]));
    cursor temp = grid[0];

    while (i<70)
    {
        system("cls");
        gange(actual_lvl);
        affichage_level(actual_lvl, j);
        action(do_smt);

        if ((*do_smt == 's') || (*do_smt == 'z') || (*do_smt == 'd') || (*do_smt == 'q'))
        {
            move(&actual_lvl, &(grid[0]), do_smt);
        }

        else if (*do_smt == 'r')
        {
            reset(&actual_lvl, all_lvl, j);
            set_zero(actual_lvl, &(grid[0]));
        }

        else if (*do_smt == '+')
        {
            j++;
            actual_lvl = all_lvl[j];
            set_zero(actual_lvl, &(grid[0]));
        }

        else if ((*do_smt == '-') && (j>0))
        {
            j--;
            actual_lvl = all_lvl[j];
            set_zero(actual_lvl, &(grid[0]));
        }

        else if ((*do_smt == 'b') && (actual_lvl.grid[grid[0].x][grid[0].y].content != 0))
        {

            precedente(&actual_lvl, &(grid[0]));
        }

        i++;
    }

    return 0;


}
