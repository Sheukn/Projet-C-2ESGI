struct position {
    int x; // x coordinate
    int y; // y coordinate
};

typedef struct{
    int type; // 0 = knight | 1 = archer | 2 = horseman | 3 = catapult | 4 = spearman 
    int hp; // health points
    int atk; // attack points
    int def; // defense points 
    int weak; // weak againsts 0 = knight | 1 = archer | 2 = horseman | 3 = catapult | 4 = spearman   
    int speed; // speed of the unit
    int range; // range of the unit
    char symbol; // symbol of the unit
    int alive; // 1 = alive | 0 = dead 
    int team; // 1 = player1 | 2 = player2 
    bool hasMoved; // 1 = Deja agit | 0 = Disponible
    bool hasAttacked; // 1 = true | 0 = false
    struct position pos; // position of the unit
}unit;

typedef struct {
    int id; // 0 = player1 | 1 = player2
    int remaining_units; 
    unit* army; // 2 knights | 2 archers | 2 horseman | 2 catapults | 2 spearman
}player;


typedef struct {
    unit* unit;
    char type; // - = grass | # = water | F = forest | M = mountain
}cell;

typedef struct {
    struct position pos;
}cursor;