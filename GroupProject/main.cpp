/*  Benjamin Majeski, Andrew Dowd, and Brad.
 * 2/8/23
 * last updated 2/26/2023
 * bpmajeski@dmacc.edu
 * this is our group project
 */
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono_literals;
using namespace this_thread;
using chrono::system_clock;

//class and function prototypes
class Player;
void callOptions(Player);

//player class
class Player {
protected:
    //declorations

    bool hasSilverKey;
    bool hasGoldKey;
    bool hasPadCode;
    bool hasTouchedGrass;
    int playerRoom;
    int sunStares;
    int buttonPresses;

public:

    //constructors

    Player() {
        this->hasSilverKey = false;
        this->hasGoldKey = false;
        this->hasPadCode = false;
        this->hasTouchedGrass = false;
        this->playerRoom = 1;
        this->sunStares = 0;
        this->buttonPresses = 0;
    }

    //class methods
    //setters
    void setSilverKey(bool input) {
        hasSilverKey = input;
    }
    void setGoldKey(bool input) {
        hasGoldKey = input;
    }
    void sethasPadCode(bool input) {
        hasPadCode = input;
    }

    void sethasTouchedGrass(bool input) {
        hasTouchedGrass = input;
    }
    void setPlayerRoom(int room) {
        playerRoom = room;
    }

    void addSunStares(){ // only needs to be incremented
        sunStares += 1;
    }
    void addButtonPresses(){ // only needs to be incremented
        buttonPresses += 1;
    }

    //getters
    bool getSilverKey() {
        return hasSilverKey;
    }
    bool getGoldKey() {
        return hasGoldKey;
    }
    bool gethasPadCode() {
        return hasPadCode;
    }
    bool gethasTouchedGrass() {
        return hasTouchedGrass;
    }
    int getPlayerRoom() {
        return playerRoom;
    }
    int getsunStares() {
        return sunStares;
    }
    int getbuttonPresses() {
        return buttonPresses;
    }

};

int main()
{
    //variables
    Player player;
    //input verification system
    string stringCatcher = "";
    bool goodInput = false;
    bool properInputConverted = false;
    //game control system
    int gameResult = 0;
    int numberOfMoves;
    int playerInput;
    vector<int> moveHistory;

    //introduction section of game

    cout << "You enter the dumbgeon, a place of horror and madness in search of treasure, will you be successful or will you be consumed by the horrors within..." << endl;
    sleep_until(system_clock::now() + 1s);
    cout << "As You enter the first room, and immedately take notice of a large cobblestone spiral staircase in the center of the room, a small harmless looking box in the lefthand corner and a large silver door" << endl;
    sleep_until(system_clock::now() + 1s);

    //repeating section of game
    while (gameResult == 0) {
        // resetting variables section
        goodInput = false;
        properInputConverted = true;
        //end of reset section

        callOptions(player);

        cin >> stringCatcher;//get player input

        try {
            playerInput = stoi(stringCatcher);
        }
        catch (invalid_argument const& e) { //catches non ints
            cout << "Error you can only numbers for decisions" << endl;
            properInputConverted = false;

        }
        catch (out_of_range const& e) { //catches massive numbers
            cout << "Error You didn't enter a input inside of the range of options" << endl;
            properInputConverted = false;
        }


        if (properInputConverted == true) { // stops double error statements
            //if statement for player errors (that are ints)
            if (playerInput == 0) { cout << "Error You didn't enter a input" << endl; }
            else if (playerInput < 1 || playerInput > 6) { cout << "Error You didn't enter a input inside of the range of options" << endl; }
            else { goodInput = true; }
        }

        if (goodInput == true) {

            //if statement to kick back to input
            moveHistory.push_back(playerInput);
            sleep_until(system_clock::now() + 0.5s);
            switch (player.getPlayerRoom()) {
            case 1: //room 1 code

                switch (playerInput) { //input case 1
                case 1:
                    //cout << "Option 1 picked" << endl;
                    cout << "You decided that this dungeon wasn't worth your time and you turned around and walked out" << endl;
                    gameResult = 1;
                    break;
                case 2:
                    //cout << "Option 2 picked" << endl;
                    cout << "You go up the staircase" << endl;
                    sleep_until(system_clock::now() + 1s);
                    cout << ".";
                    sleep_until(system_clock::now() + 1s);
                    cout << ".";
                    sleep_until(system_clock::now() + 1s);
                    cout << "." << endl;
                    cout << "and then soon emerge from the bottom of the spiral stairs, feeling more confused than when you started" << endl;

                    break;
                case 3:
                    //cout << "Option 3 picked" << endl;
                    cout << "You go down the staircase" << endl;
                    sleep_until(system_clock::now() + 1s);
                    cout << ".";
                    sleep_until(system_clock::now() + 1s);
                    cout << ".";
                    sleep_until(system_clock::now() + 1s);
                    cout << "." << endl;
                    cout << "And emerge from the top of the spiral stairs, feeling more confused than when you started" << endl;
                    break;
                case 4:
                    //cout << "Option 4 picked" << endl;
                    cout << "You go look at the small box in the corner and as you open it you notice that there is a silver key inside!!!" << endl;
                    player.setSilverKey(true);
                    break;
                case 5:
                    //cout << "Option 5 picked --- door" << endl;
                    if (player.getSilverKey() == true) {
                        cout << "You take your shiny silver key and slide it into the key hole, It worked! you feel a nice warm breeze as you enter into the next room!" << endl;
                        player.setPlayerRoom(2);

                        cout << "As you leave the room, you enter a very lush looking garden area inside you see a large patch of unkemp grass, a small guinea pig in a police officer outfit standing next to a small golden gate blocking the next room, and a big bright sun hanging from the ceiling as well." << endl;

                    }
                    else {
                        cout << "You go to open the door but you realize that you have no key, a mild disapointment forms deep in your soul" << endl;
                    }
                    break;
                case 6:
                    if(player.getSilverKey() == true){
                        cout << "You look around the room and see a large spiral stair case in the middle of the room, a  small little wooden box that is open in the righthand corner of the room, and a large silver door on the other end of the room" << endl;
                    }
                    else{
                        cout << "You look around the room" << endl;
                        sleep_until(system_clock::now() + 1s);
                        cout << ".";
                        sleep_until(system_clock::now() + 1s);
                        cout << ".";
                        sleep_until(system_clock::now() + 1s);
                        cout << "." << endl;
                        cout << "You see a large spiral stair case in the middle of the room, a small little wooden box in the righthand corner of the room, and a large silver door on the other end of the room" << endl;
                    }
                    break;
                }

                break;
            case 2: // room 2 code
                switch (playerInput) { //input case 2
                case 1:
                    //cout << "Option 1 picked" << endl;
                    cout << "You return to the first room" << endl;
                    cout << "You reenter the last room and as you do you see a large spiral stair case in the middle of the room, a small little wooden box that is open in the righthand corner of the room, and a large silver door on the other end of the room" << endl;
                    player.setPlayerRoom(1);
                    break;
                case 2:
                    //cout << "Option 2 picked" << endl;
                    cout << "As you approach the grass you feel a sense of dread wash over but after touching you feel calmer and more understand of your surroundings." << endl;
                    player.sethasTouchedGrass(true);
                    break;
                case 3:
                    //cout << "Option 3 picked" << endl;
                    if(player.getsunStares() == 0){
                        cout << "You look up and stare at the fake sun for a bit, after a couple of minutes your eyes start to hurt and you wonder if this was actually a good idea." << endl;
                    }
                    else if(player.getsunStares() == 1){
                        cout << "You decide to look up at the sun again to see if it will reveal any hints to you and after a couple more minutes your eyes start to really hurt now" << endl;
                    }
                    else if(player.getsunStares()  == 2){
                        cout << "You decide to look up at the sun for a 3rd time hoping it might finally reveal things to you but it doesn't do anything but hurt your eyes again..." << endl;
                    }
                    else if(player.getsunStares()  == 3){
                        cout << "After staring at the sun again, You feel like your eyes can't take staring at the sun anymore...." << endl;
                    }
                    else if(player.getsunStares()  == 4){
                        cout << "After staring at the sun for too long you feel this dungeon is pointless and you long for actual sunlight so you leave..." << endl;
                        gameResult = 1;
                    }

                    player.addSunStares();
                    break;
                case 4:
                    //cout << "Option 4 picked" << endl;

                    if(player.gethasTouchedGrass() == true){
                        cout << "You approch the small gate, but are stopped by a guinea pig in a tiny police uniform, he says to you: 'Hello good sir have you played any league of legends recently?' To which you reply: 'I just touched grass just recently' and so the gaurd then apologizes for assuming you were a filthy hardstuck iron player and handed you a gold key for the gate.' " << endl;
                        player.setGoldKey(true);
                    }
                    else{
                    cout << "You approch the small gate, but are stopped by a guinea pig in a tiny police uniform, you try to understand it, but all you can hear is 'Oday ouyay laypay eaguelay foay egendslay?'" << endl;
                    }
                    break;
                case 5:
                    //cout << "Option 5 picked" << endl;

                    if (player.getGoldKey() == true) {
                        cout << "You unlock the gate with the key that the guinea pig gaurd gave you earlier" << endl;
                        player.setPlayerRoom(3);
                        cout << "As you enter the last room that looks like a study, you see a large looking desk, a strange robotic giant device, a tempting shiny red button on the wall, and a wall safe with a code pad on it." << endl;
                    }
                    else {
                        cout << "As you approach the gate you notice its infact only a foot tall and you could step over it with ease, however you feel as if you can simply step over it due to the guinea pig policemans disapproving look" << endl;

                    }
                    break;

                case 6:
                    cout << "You look around the room" << endl;
                    sleep_until(system_clock::now() + 1s);
                    cout << ".";
                    sleep_until(system_clock::now() + 1s);
                    cout << ".";
                    sleep_until(system_clock::now() + 1s);
                    cout << "." << endl;
                    cout << "You see a large unkempt patch of dull looking grass, a small guinea pig in a police officer outfit standing next to a small golden gate blocking the next room, and a big bright sun hanging from the ceiling as well." << endl;
                    break;
                }

                break;
            case 3: // room 3 code

                switch (playerInput) { //input case 3
                case 1:
                    //cout << "Option 1 picked" << endl;
                    cout << "You return back to the last room" << endl;
                    cout << "You re-enter the very lush looking garden area inside you see a large dull patch of unkemp grass, a small guinea pig in a police officer outfit standing next to a small golden gate blocking the next room, and a big bright sun hanging from the ceiling as well." << endl;
                    player.setPlayerRoom(1);
                    break;
                case 2:
                    //cout << "Option 2 picked" << endl;
                    cout << "You rummage through the desk and find a note pade with a code on it " << endl;
                    player.sethasPadCode(true);
                    break;
                case 3:
                   //cout << "Option 3 picked" << endl;
                    cout << "You go to approach the strange machine, but you feel an amonious presence when you go near it, so you feel that its best to just leave it alone." << endl;
                    break;
                case 4:
                    //cout << "Option 4 picked" << endl;
                        if(player.getbuttonPresses() == 0){
                            cout << "You pressed a exccedingly large red button..." << endl;
                            sleep_until(system_clock::now() + 0.5s);
                            cout << "Nothing seems to have happened as a result of it" << endl;
                        }
                        else if(player.getbuttonPresses() == 1){
                            cout << "You press the button again.." << endl;
                            sleep_until(system_clock::now() + 0.5s);
                            cout << "And nothing seems to happen..." << endl;
                        }
                        else if(player.getbuttonPresses() == 2){
                            cout << "You press the button again for a third time.." << endl;
                            sleep_until(system_clock::now() + 0.5s);
                            cout << "And again nothing seems to happen..." << endl;
                        }
                        else if(player.getbuttonPresses() == 3){
                            cout << "You press the button again for a fouth time.." << endl;
                            sleep_until(system_clock::now() + 0.5s);
                            cout << "And again nothing seems to happen..." << endl;
                        }
                        else if(player.getbuttonPresses() == 4){
                            cout << "You press the button again for a fifth time.." << endl;
                            sleep_until(system_clock::now() + 0.5s);
                            cout << "And this time you hear a click come from the wall safe in the room" << endl;
                        }
                        else if(player.getbuttonPresses() == 5){
                            cout << "You press the button again for the sixth time" << endl;
                            sleep_until(system_clock::now() + 0.5s);
                            cout << "And it makes a crunch sound and doesn't unpress like before, you begin to feel sad..." << endl;
                        }
                        else{
                            cout << "You attempt to press the button but remember you previously broke the button making you feel sad again..." << endl;
                        }

                        player.addButtonPresses();
                        break;
                case 5:
                    //cout << "Option 5 picked" << endl;
                    if(player.gethasPadCode() == false){
                        cout << "You try to open the safe with brute force, but it just doesn't work... you feel discouraged by your lack of strength" << endl;
                    }
                    else if(player.gethasPadCode() == true && player.getbuttonPresses() == 4){
                        cout << "You type in the pass code into the safe to reveal" << endl;
                        sleep_until(system_clock::now() + 0.4s);
                        cout << "A massive pile of gold bars, large amounts of assorted jewels, and other fancey looking trinkets" << endl;
                                gameResult = 3;
                    }
                    else if(player.gethasPadCode() == true && player.getbuttonPresses() != 4){
                        cout << "You type in the pass code into the safe and then it slowly opens inside to reveal a large scroll..." << endl;
                        sleep_until(system_clock::now() + 0.4s);
                        cout << "And as you open the scroll on the inside of the scroll you can see your reflection, as the real treasure was you who ventured all the way here to get it, but you begin to wonder if theres any actual treasure in this crazy place." << endl;
                        gameResult = 2;

                    }

                    break;
                case 6:
                    cout << "You look around the room" << endl;
                    sleep_until(system_clock::now() + 1s);
                    cout << ".";
                    sleep_until(system_clock::now() + 1s);
                    cout << ".";
                    sleep_until(system_clock::now() + 1s);
                    cout << "." << endl;
                    cout << "You see a large looking desk, a strange robotic giant device, a tempting shiny red button on the wall, and a wall safe with a code pad on it." << endl;
                    break;
                }

                break;
            } // end of switch
        } //end of else
        sleep_until(system_clock::now() + 0.5s);
    }
    //end of game switch statement
    switch (gameResult) {

    case 1: // you walk out case
        cout << "Game over you gave up before you found the treasure" << endl;
        break;
    case 2: // you win? case
        numberOfMoves = moveHistory.size() + 1;
        cout << "Congratz? you found the treasure?" << endl;
        cout << "Wow! it took you " << numberOfMoves << "days to find it..." << endl;
        break;
    case 3: // you win case true ending
        numberOfMoves = moveHistory.size() + 1;
        cout << "Congratz you found the true treasure!" << endl;
        cout << "Wow! it took you " << numberOfMoves << "days to find it!" << endl;
        break;

    }

    return 0;
}

// prints out options menu
void callOptions(Player player) {
    cout << "" << endl;
    cout << "Options available to you: " << endl;
    //while loop until valid input
    switch (player.getPlayerRoom()) {
    case 1: //room 1 code

        cout << "1 - Leave the lame dungeon" << endl;
        cout << "2 - Go up the staircase" << endl;
        cout << "3 - Go down the staircase" << endl;
        cout << "4 - Try to open the box small box" << endl;
        cout << "5 - Open the silver door" << endl;
        cout << "6 - Look around the room" << endl;

        break;

    case 2: // room 2
        cout << "1 - Go back to the last room" << endl;
        cout << "2 - Investigate the stone underneath the tori" << endl;
        cout << "3 - Look at fake hanging sun" << endl;
        cout << "4 - Talk to the guinea pig guard" << endl;
        cout << "5 - Try to open the garden gate" << endl;
        cout << "6 - Look around the room" << endl;

        break;

    case 3: // room 3
        cout << "1 - Go back to the garden" << endl;
        cout << "2 - Rummage through the desk" << endl;
        cout << "3 - Place with the strange device?" << endl;
        cout << "4 - Press the button" << endl;
        cout << "5 - Open the safe" << endl;
        cout << "6 - Look around the room" << endl;
        break;



    }
}
