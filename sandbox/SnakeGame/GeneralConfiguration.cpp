  #include "snakegame.h"

  char campo[VERTICAL_MAX][HORIZONTAL_MAX];
  int cursor = 0;

  void empty_area(){
    for(int row = 0; row<= VERTICAL_MAX; row++){
      for(int column = 0; column<= HORIZONTAL_MAX; column++){
        campo[row][column] = ' ';
        if(column == 0 || column == HORIZONTAL_MAX) campo[row][column] = WALL;
        else if(row == 0 || row == VERTICAL_MAX ) campo[row][column] = WALL;
      }
    }
  }

  void insert_str_in_area(int x_coordenate, int y_coordenate, string add_char){
    int str_pos = 0;
    for (int row = x_coordenate; row < x_coordenate + add_char.length() - 1; row++){
      campo[y_coordenate][row] = add_char[str_pos];
      str_pos++;
    }
  }

  void print_game_area(){
    system("cls");
    for(int row = 0; row<= VERTICAL_MAX; row++){
      for(int column = 0; column<= HORIZONTAL_MAX; column++){
        cout << campo[row][column];
        if (column == HORIZONTAL_MAX) cout << "\n";
      }
    }
  }

  void insert_char_in_area(int x_coordenate, int y_coordenate, char add_char){
    campo[y_coordenate][x_coordenate] = add_char;
    print_game_area();
  }

  void write_str_char_by_char(int x_coordinate, int y_coordinate, string add_str, int sleep_time){
    int count_str_char = 0;
    for(int column = x_coordinate;  column < x_coordinate + add_str.length(); column++){
      if (add_str[count_str_char] == '|'){
        y_coordinate++;
        count_str_char++;
      }
      insert_char_in_area(column, y_coordinate, add_str[count_str_char]);
      Sleep(sleep_time);
      count_str_char++;
    }
  }

  void create_credits(){
    string credit_str = "SNAKE GAME|BY|MARCOS ANDRE ";
    write_str_char_by_char(15, 8, credit_str, TEMPO_INITIAL_MENU);
  }
  
  void create_menu(){
    empty_area();

    vector<int> menu_coordinate = {22, 5};
    vector<int> start_coordinate = {23, 10};
    vector<int> options_coordinate = {22, 12};
    vector<int> credits_coordinate = {22, 14};
    vector<int> quit_coordinate = {23, 16};

    string menu = "- MENU - ";
    string start = "START ";
    string options = "OPTIONS ";
    string credits = "CREDITS ";
    string quit = "QUIT ";

    write_str_char_by_char(menu_coordinate[0], menu_coordinate[1], menu, TEMPO_INITIAL_MENU);
    write_str_char_by_char(start_coordinate[0], start_coordinate[1], start, TEMPO_INITIAL_MENU);
    write_str_char_by_char(options_coordinate[0], options_coordinate[1], options, TEMPO_INITIAL_MENU);
    write_str_char_by_char(credits_coordinate[0], credits_coordinate[1], credits, TEMPO_INITIAL_MENU);
    write_str_char_by_char(quit_coordinate[0], quit_coordinate[1], quit, TEMPO_INITIAL_MENU);
  }  

  void menu(){
    string menu = "- MENU - ";
    string start = "START ";
    string options = "OPTIONS ";
    string credits = "CREDITS ";
    string quit = "QUIT ";
    
    vector<int> menu_coordinate = {22, 5};
    vector<int> start_coordinate = {23, 10};
    vector<int> options_coordinate = {22, 12};
    vector<int> credits_coordinate = {22, 14};
    vector<int> quit_coordinate = {23, 16};

    insert_str_in_area(menu_coordinate[0], menu_coordinate[1], menu);
    insert_str_in_area(start_coordinate[0], start_coordinate[1], start);
    insert_str_in_area(options_coordinate[0], options_coordinate[1], options);
    insert_str_in_area(credits_coordinate[0], credits_coordinate[1], credits);
    insert_str_in_area(quit_coordinate[0], quit_coordinate[1], quit);
    print_game_area();
  }

  void credits(){
    empty_area();
    create_credits();
    Sleep(1500);
    empty_area();
  }


