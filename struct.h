struct position {
    int x; // x coordinate
    int y; // y coordinate
};

typedef struct{
    int type; // 0 = knight | 1 = archer | 2 = horseman | 3 = catapult | 4 = spearman 
    struct position pos; // position of the unit
    int hp; // health points
    int atk; // attack points
    int def; // defense points 
    int weak; // weak againsts 0 = knight | 1 = archer | 2 = horseman | 3 = catapult | 4 = spearman   
    int speed; // speed of the unit
    int range; // range of the unit
}unit;

typedef struct {
    int id; // 1 = player1 | 2 = player2
    int remaining_units; 
    unit army[10]; // 2 knights | 2 archers | 2 horseman | 2 catapults | 2 spearman
}player;