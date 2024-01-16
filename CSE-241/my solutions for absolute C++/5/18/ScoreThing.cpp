#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getHighScores(string namesArr[], int scoresArr[]);
void sort(string namesArr[], int scoresArr[], int maxData);
int returnHigher(int ix0, int ix1, int arr[]);

int main(){
    string namesArr[10];
    int scoresArr[10];

    int maxData = getHighScores(namesArr, scoresArr);

    for(int i = 0; i < maxData; ++i){
        cout << namesArr[i] << " " << scoresArr[i] << endl;
    }

    return (0);
}

int getHighScores(string namesArr[], int scoresArr[]){
    fstream inputStream;
    inputStream.open("Scores.txt");

    string name;
    int score,
        i = 0;

    while(inputStream.peek() != EOF){
        inputStream >> name >> score;
        namesArr[i] = name;
        scoresArr[i] = score;
        ++i;
    }

    sort(namesArr, scoresArr, i);

    inputStream.close();

    return i;
}

int returnHigher(int ix0, int ix1, int arr[]){
    if(arr[ix0] > arr[ix1])
        return ix0;
    else
        return ix1;
}

void sort(string namesArr[], int scoresArr[], int maxData){
    int tempScore;
    string tempName;
    bool wrongPlace = true;

    while(wrongPlace){
        wrongPlace = false;
        for(int ix = 0; ix < maxData - 1; ix++){
            if(returnHigher(ix, ix+1, scoresArr) != ix){
                tempName = namesArr[ix];
                tempScore = scoresArr[ix];

                namesArr[ix] = namesArr[ix+1];
                scoresArr[ix] = scoresArr[ix+1];

                namesArr[ix+1] = tempName;
                scoresArr[ix+1] = tempScore;
                wrongPlace = true;
            }
        }
    }
}