#include <iostream>
#include <string>
#include "strutils.h"
#include <string>

using namespace std;


void displayResults(double difference, double totalPoint, double goalPoint, double assistPoint, double nutmegPoint){
    cout << "From scoring goals, you collected " << goalPoint << " points." << endl;
    cout << "From making assists, you collected " << assistPoint << " points." << endl;
    cout << "From nutmegs, you collected " << nutmegPoint << " points." << endl;
    cout << "You collected " << totalPoint << " points." << endl;

    if (difference == 0) {
        cout << "Congratulations! You have reached your goal!" << endl;
    } else if (difference > 0) {
        cout << "You have surpassed your goal! You have extra " << difference << " points :)" << endl;
    } else {
        cout << "You did not reach your goal by " << (difference*-1) << " points." << endl;
    }
}


double calculateScore(int league, const string &exercise){
    if (exercise == "goal"){
        if (league >= 4 && league < 6){
            return 4;

        }
        else{
            return 6.5;
        }

    }
    else if (exercise == "assist"){
        if (league >= 4 && league < 11){
            return 9;

        }
        else{
            return 12.5;
        }
    }
    else if (exercise == "nutmeg"){
        if (league >= 4 && league < 20){
            return 6;

        }
        else if (league >= 20 && league < 25){
            return 8;
        }
        else{
            return 10.5;
        }
    }
    return 0;

}


void computeResults(int matches, int goal, int league, int goalCount, int assistCount, int nutmegCount){

    double haftagol;

    cin >> haftagol;

    double goalScore = calculateScore(league, "goal");
    double assistScore = calculateScore(league, "assist");
    double nutmegScore = calculateScore(league, "nutmeg");

    double goalPoint = matches * goalCount * goalScore;
    double assistPoint = matches * assistCount * assistScore;
    double nutmegPoint = matches * nutmegCount * nutmegScore;

    double total = goalPoint + assistPoint + nutmegPoint;
    
    double difference = total - haftagol;

    displayResults(difference, total, goalPoint, assistPoint, nutmegPoint);
}


void getInput(const string &username){
    int matches, league, goalCount, assistCount, nutmegCount;
   
    cout << "Welcome " << username << ", please enter your number of matches played: ";
    cin >> matches;
    while (matches < 0) {
        cout << "Number of matches out of range!" << endl;
        cout << username << ", please enter your number of matches played: ";
        cin >> matches;

    }
    cout << username << ", please enter your league: ";
    cin >> league;
    while ((league < 4) || (league > 30)) {
        cout << "League out of range!" << endl;
        cout << username << ", please enter your league: ";
        cin >> league;
    }

    cout << username << ", how many times did you score a goal: ";
    cin >> goalCount;
    while (goalCount < 0) {
        cout << "Times out of range!" << endl;
        cout << username << ", how many times did you score a goal: ";
        cin >> goalCount;
    }

    cout << username << ", how many times did you make an assist: ";
    cin >> assistCount;
    while (assistCount < 0) {
        cout << "Times out of range!" << endl;
        cout << username << ", how many times did you make an assist: ";
        cin >> assistCount;
    }

    cout << username << ", how many times did you nutmeg an opponent: ";
    cin >> nutmegCount;
    while (nutmegCount < 0) {
        cout << "Times out of range!" << endl;
        cout << username << ", how many times did you nutmeg an opponent: ";
        cin >> nutmegCount;
    }

    cout << username << ", please enter your weekly point goal: " << endl;
    
    computeResults(matches, goalCount, league, goalCount, assistCount, nutmegCount);



}


void makeUsername(const string &sentence){
    const int gun = 14;
    const int ay = 4;
    const int yil = 2025;
    
    
    string username = "";
    int i = sentence.find(",");
    int j = sentence.find(",", i+1);


    
    string lastname = sentence.substr(0, i);
    string firstname = sentence.substr(i + 1, j - i - 1);
    string birthdate = sentence.substr(j + 1);

    ToLower(lastname);
    ToLower(firstname);

    int tire1 = birthdate.find("-");
    int tire2 = birthdate.find("-", tire1+1);
    string monthstr = birthdate.substr(0, tire1);
    string daystr = birthdate.substr(tire1+1, tire2-tire1-1);
    string yearstr = birthdate.substr(tire2+1);
    int day = atoi(daystr);
    int month = atoi(monthstr);
    int year = atoi(yearstr);
    int yas = yil - year;
    if ((month > ay) || (month == ay && day > gun)) {
        yas--;
    }
        
    username = firstname + lastname + itoa(yas);
    getInput(username);
}






int main(){
    const int gun = 14;
    const int ay = 4;
    const int yil = 2025;
    string sentence;
    string username;
    int matches, goal, league, goalCount, assistCount, nutmegCount;
    double difference, totalPoint, goalPoint, assistPoint, nutmegPoint, haftagol;
    cout << "Please enter your information: ";
    cin >> sentence;
    makeUsername(sentence);

    return 0;
}
