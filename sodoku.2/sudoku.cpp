#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include<cstdlib>
#include<ctime>
#include <string>
using namespace std;
//#include "colormod.h"
#include "sudoku.h"

//grid class game class 
//runs most of the game

sudoku::sudoku(){
        srand(time(0));  // needed once per program run

        score = 100;
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                values [i] [j] = 0;
                selected[i][j]=false;
            }
        }
        selected[0][0]=true;
        error = false;
        count=5;
        x=0;
        y=0;
        start();

    }
sudoku::~sudoku(){
        //stops the webserver
        system("sh stop.sh");

    }
void sudoku::move(char key){
        //allows wsad keys for input
        switch(key){
            case 'w': 
            if(y<9){
                if(y>0){
                selected[y][x] = false;
                selected[y-1][x] = true;
                }
            }
                break;
            case 's':
            if(y<8){
                if(y>=0){
                selected[y][x] = false;
                selected[y+1][x] = true;
                }
            }
                break;
            case 'd':
                if(x<8){
                if(x>=0){
                selected[y][x] = false;
                selected[y][x+1] = true;
                }
            }

                break;
            case 'a':
                if(x<9){
                    if(x>0){
                    selected[y][x] = false;
                    selected[y][x-1] = true;
                }
            }
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            if(og[y][x]!=0){
                break;
            }
            values[y][x]=key-48;
                if(values[y][x]!=solved[y][x]){
                    error = true;
                    score-=5;
                    values[y][x]=key-48;

                }
                else{
                    values[y][x]=key-48;
                    error= false;
                }
                cout << error << endl;
                break;
            default:
                break;
            
        }
    }
void sudoku::solver(){
        	for (int i = 0; i<9; i++){
    	    for (int j = 0; j<9; j++){
    	       cout << solved[i][j] << ",";
    	    }
    	    cout << endl;
	}
    }
void sudoku::game(){
	    switch(mode){
	        case 1:
	            difficulty = "veryeasy";
	            break;
	        case 2:
	        	difficulty = "easy";
	            break;
	        case 3: 
	            difficulty = "medium";
	            break;
	        case 4:
	            difficulty = "hard";
	        
	            break;
	       default:
	            break;
	    }
	
    	ifstream sodoku;
    	board = difficulty+"/"+difficulty;
    	random = rand() % 10 + 1;
        board+= to_string(random);
        board+= ".csv";
        filename = difficulty;
        filename+= to_string(random);
        filename+=".csv";
        ifstream solution;
        solutions = difficulty+"/solution_"+difficulty;
        solutions+= to_string(random);
        solutions+= ".csv";
        cout << "Playing " << board << "\n"<< endl;
        
    	//sodoku.open(board);
    	sodoku.open(board);
    	if(!sodoku.is_open()){
    		exit(EXIT_FAILURE);
    	}
    	
    for (int i = 0; i<9; i++){
    	for (int j = 0; j<9; j++){
    		sodoku >> check;
    		c = to_string(check);
    		if (c=="33"){
    		    //cout << "Fail" << endl;
                j--;
    		}
    		else if(c=="45"){
    		    j--;
    		}    		
    		else if(c=="44"){
    		    j--;
    		}
    		else if (c=="46"){
    		  values[i][j]= 0;
    		  og[i][j]= values [i][j];
    		}
    		else {
    		       values[i][j]= check-48;
    		       og[i][j]= values [i][j];
    		}
    	}
    }
        solution.open(solutions);
    	if(!sodoku.is_open()){
    		exit(EXIT_FAILURE);
    	}
    
    for (int i = 0; i<9; i++){
    	for (int j = 0; j<9; j++){
    		solution >> check;
    		c = to_string(check);
    		if (c=="33"){
    		    //cout << "Fail" << endl;
                j--;
    		}
    		else if(c=="45"){
    		    j--;
    		}    		
    		else if(c=="44"){
    		    j--;
    		}
    		else if (c=="46"){
    		  solved[i][j]= 0;
    		}
    		else {
    		       solved[i][j]= check-48;
    		}
    	}
    }      
    
    
    
  
	
	}
void sudoku::clear(){
        for (int i=0; i<10; i++){
            //cout << "\n\n" << endl;
            system("clear");
        }
    }
bool sudoku::checked() {
        
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if(values [i] [j] != solved[i][j]){
                    verify = false;
                    break;
                    }
                else{
                    verify = true;
                }
                
            }
        }
        return verify;
    }
void sudoku::Print(){
        count = 5;
        if(error == true){
            while (count >=0){

            //sleep_until(system_clock::now() + seconds(1));   
            clear();
            count--;
            instructions();
            cout << "Score: " << score << "\n"<< endl;
            cout << "    1  2  3   4  5  6   7  8  9" << endl;
        
            for (int row = 0; row<9; row++){
                    if (row%3==0){
                        cout << endl;
                    }
                    cout << row+1 <<"   ";
        
        
                for (int col=0; col<9; col++){
                    if(col!=0){
                        if (col%3==0){
                            cout << " ";
                        }
                    }
                    Color::Modifier red(Color::FG_RED);
                    Color::Modifier green(Color::FG_GREEN);
                    Color::Modifier blue(Color::FG_BLUE);
                    Color::Modifier def(Color::FG_DEFAULT);
                    Color::Modifier BG(Color::BG_GREEN);
                    Color::Modifier BD(Color::BG_DEFAULT);
                    Color::Modifier BR(Color::BG_RED);
        
                    
                    if(selected[row][col]==true){
                        if(values[row][col]!=og[row][col]){
                            if (error == true){
                                if (count %2==0){
                                    cout << BR<< values[row][col] << BD << def<<"  " ;
                                }
                            else{
                                cout << BG<< blue<< og[row][col] << BD << def<<"  " ;
                            }

                            }
                        }
                        //cout << BG<< values[row][col] << BD << def<<"  " ;
                    
                    x= col;
                    y= row;
                    }
                    if(selected[row][col]!=true){
                        //cout << "test";
                    if(values[row][col]!=0){
                        if(values[row][col]!=og[row][col]){
                            if (error == true){
 
                            cout << BR<< values[row][col] << BD << def<<"  " ;

                            }
                        }
                    else{
                        cout << red<< values[row][col] << BD << def<<"  " ;
                    }
                    }
                    else{
                        cout << blue <<values[row][col] << BD <<def << "  " ;
                    }
        
                    if(col%3==0){
                        //cout << "  ";
                    }
                }
                    
                }
                
                cout << endl;
                //m1
                
            }
            cout << endl;
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono; // nanoseconds, system_clock, seconds
        sleep_until(system_clock::now() + seconds(1));   
            }
            
        values[y][x]= og[y][x];

        error = false;

        }
        else{
            instructions();
            cout << "Score: " << score << "\n"<< endl;
            cout << "    1  2  3   4  5  6   7  8  9" << endl;
        
            for (int row = 0; row<9; row++){
                    if (row%3==0){
                        cout << endl;
                    }
                    cout << row+1 <<"   ";
        
        
                for (int col=0; col<9; col++){
                    if(col!=0){
                        if (col%3==0){
                            cout << " ";
                        }
                    }
                    Color::Modifier red(Color::FG_RED);
                    Color::Modifier green(Color::FG_GREEN);
                    Color::Modifier blue(Color::FG_BLUE);
                    Color::Modifier def(Color::FG_DEFAULT);
                    Color::Modifier BG(Color::BG_GREEN);
                    Color::Modifier BD(Color::BG_DEFAULT);
                    Color::Modifier BR(Color::BG_RED);
        
                    
                    if(selected[row][col]==true){
                    cout << BG<< values[row][col] << BD << def<<"  " ;
                    x= col;
                    y= row;
                    }
                    if(selected[row][col]!=true){
                        //cout << "test";
                    if(values[row][col]!=0){
                        if(values[row][col]!=og[row][col]){
                            cout << def<< values[row][col] << BD << def<<"  " ;

                        }
                    else{
                        cout << red<< values[row][col] << BD << def<<"  " ;
                    }
                    }
                    else{
                        cout << blue <<values[row][col] << BD <<def << "  " ;
                    }
        
                    if(col%3==0){
                        //cout << "  ";
                    }
                }
                    
                }
                
                cout << endl;
                //m1
                
            }
            cout << endl;
            
        }
    }
void sudoku::instructions(){
    cout << endl<< "playing " << filename << endl;
    cout << endl<< "               Easy Mode\n\n";
    cout <<"Use   W   keys followed by the 'return' key to navigate "  << endl;
    cout << "    A S D" <<endl;
    cout << "Type 'quit' to quit\n" << endl;
}
void sudoku::welcome(){
    while(true){
        cout << "Welcome to Sodoku\n" << endl;
        cout << "What level would you like to play?" << endl;
        cout << "Type number for selection\n" << endl;
        cout << "1. Very Easy" << endl;
        cout << "2. Easy" << endl;
        cout << "3. Medium" << endl;
        cout << "4. Hard" << endl;
        cout << ": " ;
        cin >> mode;
        if (mode>0){
            if(mode<5){
                break;
            }
            else{
                clear();
                cout << "Enter a number 1..4" << endl;
            }
        }
        else{
            clear();
            cout << "Enter a number 1..4" << endl;
        }
    }
    //instructions();
}
void sudoku::video(){
system("sh start.sh");
}
void sudoku::start(){
        video();
        welcome();
        game();
        Print();
        while(true){
        if (checked()==true){
            break;
        }
        cout << ": ";
        cin >> key;
        if(key=='q'){
            cin >> input;
            if(input=="uit"){
                cout << "are you sure you want to quit (y/n)" << endl;
                cout << ": ";
                cin >> input;
                if(input == "y"){
                    break;

                }
                else{
                    
                }
            }
            else{
                
            }
        }
        else if(key=='n'){
            cin >> input;
            if(input=="ew"){
                clear();
                welcome();
                game();
            }
            else{
                
            }
        }        
        else if(key=='?'){
            solver();
        }
        move(key);
        clear();
        Print();
        //g2.instructions();
    }
    
}