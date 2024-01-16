#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Player{

public:
    void setName(string newName);
    void setScore(int newScore);
    string getName();
    int getScore();
    void print();

private:
    string name;
    int score;

};

void sort(Player playerArr[], int maxData);
int returnHigher(int ix0, int ix1, Player arr[]);
int getHighScores(Player playerArr[]);

void Player::setName(string newName){
    name = newName;
}

void Player::setScore(int newScore){
    score = newScore;
}

string Player::getName(){
    return name;
}

int Player::getScore(){
    return score;
}

void Player::print(){
    cout << getName() << " " << getScore() << endl;
}

int main(){

    Player playerArr[10];

    int maxData = getHighScores(playerArr);

    for(int i = 0; i < maxData; ++i){
        playerArr[i].print();
    }

    return(0);
}

int getHighScores(Player playerArr[]){
    fstream inputStream;
    inputStream.open("Scores.txt");

    string name;
    int score,
        i = 0;

    while(inputStream.peek() != EOF){
        inputStream >> name >> score;
        playerArr[i].setName(name);
        playerArr[i].setScore(score);
        ++i;
    }

    sort(playerArr, i);

    inputStream.close();

    return i;
}

int returnHigher(int ix0, int ix1, Player arr[]){
    if(arr[ix0].getScore() > arr[ix1].getScore())
        return ix0;
    else
        return ix1;
}

void sort(Player playerArr[], int maxData){
    int tempScore;
    string tempName;
    bool wrongPlace = true;

    while(wrongPlace){
        wrongPlace = false;
        for(int ix = 0; ix < maxData - 1; ix++){
            if(returnHigher(ix, ix+1, playerArr) != ix){
                tempName = playerArr[ix].getName();
                tempScore = playerArr[ix].getScore();

                playerArr[ix].setName(playerArr[ix+1].getName());
                playerArr[ix].setScore(playerArr[ix+1].getScore());

                playerArr[ix+1].setName(tempName);
                playerArr[ix+1].setScore(tempScore);
                wrongPlace = true;
            }
        }
    }
}