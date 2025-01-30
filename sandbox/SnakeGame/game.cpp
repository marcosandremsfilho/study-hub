#include "snakegame.h"
#include "GeneralConfiguration.cpp"

enum BINDING {W, A, S, D, ENTER = 99};
enum direction {UP, DOWN, LEFT, RIGHT};

int get_key(){
    char key = 32;
    key = getch();
        
    if (key == 119 || key == 87){
        return W;
    } else if(key == 115 || key == 83){
        return S;
    } else if(key == 97 || key == 65){
        return A;
    } else if(key == 100 || key == 68){
        return D;
    } else if (key == 13){
        return ENTER;
    }
    return key;
  }

void start_snake_game(){
    timeout(0);
    empty_area();
    int x_coordinate = HORIZONTAL_CENTER;
    int y_coordinate = VERTICAL_CENTER;
    int mov_direction = RIGHT;
    int key;
    int last_key; 

    do{
        insert_char_in_area(x_coordinate, y_coordinate, SNAKE_CHAR);
        key = get_key();
        if (key == 32) key = last_key;

        if(key == W) mov_direction = DOWN;
        if(key == S) mov_direction = UP;
        if(key == A) mov_direction = LEFT;
        if(key == D) mov_direction = RIGHT;
        
        insert_char_in_area(x_coordinate, y_coordinate, 32);
        if (mov_direction == RIGHT) x_coordinate++;
        if (mov_direction == LEFT) x_coordinate--;
        if (mov_direction == UP) y_coordinate++;
        if (mov_direction == DOWN) y_coordinate--;

        last_key = key;
    }while (x_coordinate != 1 || x_coordinate != HORIZONTAL_MAX-1 || y_coordinate != 1 || y_coordinate != VERTICAL_MAX-1);  
    cout << "you lost";
}


void menu_pointer(int index_number){
    if (index_number == 1){
      campo[VERTICAL_CENTER][HORIZONTAL_CENTER - 4] = '>';
      campo[VERTICAL_CENTER + 2][HORIZONTAL_CENTER - 6] = ' ';
      campo[VERTICAL_CENTER + 4][HORIZONTAL_CENTER - 5] = ' ';
      campo[VERTICAL_CENTER + 6][HORIZONTAL_CENTER - 5] = ' ';
    } else if (index_number == 2){
      campo[VERTICAL_CENTER][HORIZONTAL_CENTER - 4] = ' ';
      campo[VERTICAL_CENTER + 4][HORIZONTAL_CENTER - 5] = ' ';
      campo[VERTICAL_CENTER + 2][HORIZONTAL_CENTER - 6] = '>';
      campo[VERTICAL_CENTER + 6][HORIZONTAL_CENTER - 5] = ' ';
    } else if (index_number == 3){
      campo[VERTICAL_CENTER][HORIZONTAL_CENTER - 4] = ' ';
      campo[VERTICAL_CENTER + 2][HORIZONTAL_CENTER - 6] = ' ';
      campo[VERTICAL_CENTER + 4][HORIZONTAL_CENTER - 5] = '>';
      campo[VERTICAL_CENTER + 6][HORIZONTAL_CENTER - 5] = ' ';
    } else if (index_number == 4){
      campo[VERTICAL_CENTER][HORIZONTAL_CENTER - 4] = ' ';
      campo[VERTICAL_CENTER + 2][HORIZONTAL_CENTER - 6] = ' ';
      campo[VERTICAL_CENTER + 4][HORIZONTAL_CENTER - 5] = ' ';
      campo[VERTICAL_CENTER + 6][HORIZONTAL_CENTER - 5] = '>';
    }
    menu();
  }

int menu_key(){
    int key = 98;
    do{
        key = get_key();
    }while(key == 98);
    return key;
}

int get_menu_position(int  last_pointer, int cmd_index){
    if (last_pointer == 1 && cmd_index == S) return 2;
    if (last_pointer == 2 && cmd_index == W) return 1;
    if (last_pointer == 2 && cmd_index == S) return 3;
    if (last_pointer == 3 && cmd_index == W) return 2;
    if (last_pointer == 3 && cmd_index == S) return 4;
    if (last_pointer == 4 && cmd_index == W) return 3;

    if (cmd_index == ENTER) return last_pointer;

    return last_pointer;
  } 

void escolha(){
    int key;
    int pointer = 1;
    do{
      menu_pointer(pointer);
      key = menu_key();
      cout << key;
      pointer = get_menu_position(pointer, key);
    }while(key != ENTER); 
    cout << pointer;
    if (pointer == 1){
      start_snake_game();
    } else if (pointer == 3){
      credits();
      escolha();
    }
  }
