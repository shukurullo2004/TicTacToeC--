#include <iostream>
#include <ctime>

void drawboard(char *space);
void playermove(char *space, char player);
void computermove(char *space,char computer);
bool checkwinner(char *space, char player, char computer);
bool checktoe(char *space);

int main(){
    char space[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',};
    
    char player ='x';
    char computer = 'o';
    bool running = true;

    
    drawboard(space);
    while(running){
        playermove(space, player);
        drawboard(space);
        if(checkwinner(space, player, computer)){
            running =false;
            break;
        }
        else if(checktoe(space))
        {
            running = false;
            break;
        }
        
        
        computermove(space, computer);
        drawboard(space);
        if(checkwinner(space, player, computer)){
            running =false;
            break;
        }
        else if (checktoe(space))
        {
            running = false;
            break;
        }
        
    }
    
   std::cout << "Thanks for using Shukurullo's programm :)!" ; 
}

void drawboard(char *space){
    std::cout <<"     |     |     " <<std::endl;
    std::cout <<"  "<< space[0] <<"  |" <<"  "<< space[1] <<"  |" <<"  "<< space[2] <<"  " <<std::endl;
    std::cout <<"_____|_____|_____" << std::endl;
    std::cout <<"     |     |     " <<std::endl;
    std::cout <<"  "<< space[3] <<"  |" <<"  "<< space[4] <<"  |" <<"  "<< space[5] <<"  " <<std::endl;
    std::cout <<"_____|_____|_____" << std::endl;
    std::cout <<"     |     |     " <<std::endl;
    std::cout <<"  "<< space[6] <<"  |" <<"  "<< space[7] <<"  |" <<"  "<< space[8] <<"  " <<std::endl;
    std::cout <<"_____|_____|_____" << std::endl;
}

void playermove(char *space, char player){
    int number;
    do{
        do{
            std::cout << "Enter a spot to place marker(1-9): " << std::endl;
        std::cin >> number; 
        number--;
        if(space[number] == ' '){
            space[number] = player;
            break;
        }
        else{
            std::cout <<"This spot is taken already\nPlease choose another one: " << std::endl;
        }   
        }while(space[number] != 'x' || 'o');
        
    }while(number<0 || number >9);
    
}

void computermove(char *space,char computer){
    int number;
    srand(time(0));
    while(true){
        number = rand() % 9;
        if(space[number] == ' '){
            space[number] = computer;
            break;
        }
    }
}

bool checkwinner(char *space, char player, char computer){
     if((space[0] != ' ') && (space[0] == space[1]) && (space[1] == space[2])){
        space[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((space[3] != ' ') && (space[3] == space[4]) && (space[4] == space[5])){
        space[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((space[6] != ' ') && (space[6] == space[7]) && (space[7] == space[8])){
        space[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((space[0] != ' ') && (space[0] == space[3]) && (space[3] == space[6])){
        space[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((space[1] != ' ') && (space[1] == space[4]) && (space[4] == space[7])){
        space[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((space[2] != ' ') && (space[2] == space[5]) && (space[5] == space[8])){
        space[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((space[0] != ' ') && (space[0] == space[4]) && (space[4] == space[8])){
        space[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((space[2] != ' ') && (space[2] == space[4]) && (space[4] == space[6])){
        space[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else{
        return false;
    }

    return true;
}

bool checktoe(char *space){
    for(int i = 0; i < 9; i ++){
        if(space[i] == ' '){
            return false;
        }
    }
    std::cout << " It is toe" << std::endl;
    return true;
    
}
