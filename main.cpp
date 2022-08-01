#include <iostream>
#include <string>

using namespace std;

struct Player {
    string fullName;
    int team;
    union
    {
        struct { int championships, MVPtitles; } Lakers;
        struct { int championships, MVPtitles; } Celtics;
    };
    int careerPoints;
};

Player createPlayer(int team) {
    Player player;

    cout << "Enter full name of player: ";
    while (player.fullName == "") {
        getline(cin, player.fullName);
    }

    player.team = team;
    if (team == 1) {
        cout << "Number of championships: ";
        cin >> player.Lakers.championships;
        cout << "Number of MVP titles: ";
        cin >> player.Lakers.MVPtitles;
    } else {
        cout << "Number of championships: ";
        cin >> player.Celtics.championships;
        cout << "Number of MVP titles: ";
        cin >> player.Celtics.MVPtitles;
    }

    cout << "Number of career points: ";
    cin >> player.careerPoints;
    return player;
}

void printPlayer(Player player) {
    cout << "Name: " << player.fullName << "\n";
    if (player.team == 1) {
        cout << "Team: Los-Angeles Lakers\n";
        cout << "Amount: " << player.Lakers.championships << ", " << player.Lakers.MVPtitles << ", ";
    }
    else {
        cout << "Team: Boston Celtics\n";
        cout << "Amount: " << player.Celtics.championships << ", " << player.Celtics.MVPtitles << ", ";
    }
    cout << player.careerPoints << "\n";
}

int main() {
    Player dataBase[100], player = {"", 0, {0, 0}, 0};

    int i, j;
    for (i = 0; i < sizeof(dataBase) / sizeof(player); i++) {
        dataBase[i] = player;
    }

    while (true) {
        cout << "    Menu:\n"
             << "1. Enter information about player.\n"
             << "2. Output information about player.\n"
             << "3. Output of all information.\n"
             << "4. Delete information about player.\n"
             << "5. Delete of all information.\n"
             << "6. Finish the job.\n"
             << ">";
        cin >> i;

        switch (i) {
            case 1:
                cout << "Number of player: "; cin >> i;
                cout << "Team (1-Lakers, 2-Celtics): "; cin >> j;
                dataBase[i - 1] = createPlayer(j);
                break;
            case 2:
                cout << "Number of player: "; cin >> i;
                printPlayer(dataBase[i - 1]);
                break;
            case 3:
                for (i = 0; i < sizeof(dataBase) / sizeof(player); i++) {
                    if (dataBase[i].team != 0) {
                        cout << "Player" << i + 1 << ':' << "\n";
                        printPlayer(dataBase[i]);
                    }
                }
                break;
            case 4:
                cout << "Number of player: "; cin >> i;
                dataBase[i - 1] = player;
                break;
            case 5:
                for (i = 0; i < sizeof(dataBase) / sizeof(player); i++) {
                    dataBase[i] = player;
                }
                break;
            case 6:
                return 0;
            default: cout << "Repeat input!\n";
        }
    }
}
