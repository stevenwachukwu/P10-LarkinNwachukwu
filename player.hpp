/*Written by Steve Nwachukwu and Nick Larkin*/
#ifndef player_hpp
#define player_hpp
#include "Enum.hpp"
#include "tools.hpp"

class Player {
private:
    string playerName;
    ECcolor colorVal;
    int score = 0;
    int scoreboard [3];


public:
    Player() = default;
    //constructors and destructor for player
    Player(string playerName, ECcolor color);
    ~Player() = default;
    ECcolor color();
    ostream& print(ostream& playerOutput);
    int getScore();
    bool wonColumn(int colNum);
};

class BadPlayer {
    string incorrectPlayer;
public:
    BadPlayer (string bp):incorrectPlayer(bp) {};
    virtual string basePrint (){
        return string ("Your invalid input was "  + incorrectPlayer);
    }
};

class BadName:public BadPlayer {
    string incorrectName;
public:
    BadName (string bn):incorrectName(bn), BadPlayer(bn) {
    };
   string basePrint () override {
        return string ("Your invalid input was " + incorrectName);
    }
};

class BadColor:public BadPlayer {
string incorrectColor;
public:
    BadColor (string bc):incorrectColor(bc), BadPlayer(bc) {
    };
    string basePrint() override {
       return string ("Your invalid input was " + incorrectColor);
    }
};

class BadChoice {
string incorrectChoice;
public:
    BadChoice(string bdChoice):incorrectChoice(bdChoice) {};
    virtual string basePrint () {
        return string("Your invalid input " + incorrectChoice);
    }
};

class DuplicateSlot:public BadChoice {
string incorrectDuplicateSlot;
public:
    DuplicateSlot (string ds):incorrectDuplicateSlot(ds), BadChoice(ds) {
    };
    string basePrint() override {
        return string ("Your invalid input was " + incorrectDuplicateSlot);
    }
};

class BadSlot:public BadChoice {
string incorrectBadSlot;
public:
    BadSlot (string bs):incorrectBadSlot(bs), BadSlot(bs) {
    };
    string basePrint() override {
        return string ("Your invalid input was " + incorrectBadSlot);
    }
};

inline ostream& operator << (ostream&  output, Player& p) {return p.print(output);}
#endif
