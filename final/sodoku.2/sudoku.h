#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include<cstdlib>
#include<ctime>
#include <string>
using namespace std;
#include "colormod.h"

//grid class game class 
//runs most of the game
class sudoku{
private:
    int values [9] [9];
    int solved [9][9];
    int og [9][9];
    bool selected[9][9];
    string board;
    string solutions;
    int x;
    int random;
    int y;
    string c;
    char check;
    char checks;
    string cs;
    bool error;
    bool verify;
    int count;
    int mode;
    string difficulty;
    char key;
    string input;
    protected:
    int score;
    string filename;

public:
    //grid constructor
    sudoku();
    //sudoku destryctor
    ~sudoku();
    //welcome function ... code outside of class
    void welcome();
    //function that gives instructions on how to play
    void instructions();
    //move function for easy input
    void move(char key);
    void solver ();
	void game();
    void clear();
    bool checked();
    void Print();
    void video();
    void start();

};
