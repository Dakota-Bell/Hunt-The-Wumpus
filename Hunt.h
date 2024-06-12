#ifndef Incl_Chamber // extra safety measure incase this file is ran first
#define Incl_Chamber
#include "Chamber.h"
#endif // Incl_Chamber

class Hunt{
    private:
        Chamber* player;
        Chamber* bats;
        Chamber* wumpus;
        Chamber* pit;
        bool gameOver;
        int numArrows;

    public:
        Hunt();
        void play();
        void reportPosition();
        void movePlayer(int);
        void randomFlight();
        void killPlayer(int);
        int fire();
        void moveWumpus();
};