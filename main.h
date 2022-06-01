#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#define GRID_SIZE 5

// Déclaration
typedef struct {
    int content;
    int chain_number;
    int passed_by;
    char previous_direction;
} cell;


typedef struct {
    int x;
    int y;
    int chain_number;
} cursor;


typedef struct {
    int width;
    int height;
    cell grid[GRID_SIZE][GRID_SIZE];
} plateau;


void set_zero(plateau level, cursor *chain);
void move(plateau *level, cursor *chain, char *direction);
void reset(plateau *level, plateau all_level[], int j);
void previous_move(plateau *level, cursor *chain);

void color(int textColor, int bgColor);
void draw_level(plateau level, int i);
void action(char *action);
int end_level(plateau level);

plateau level_1;
plateau level_2;
plateau level_3;
plateau level_4;
plateau level_5;
plateau level_6;
plateau level_7;
plateau level_8;
plateau level_9;
plateau level_10;
plateau level_11;
plateau level_12;

#endif
