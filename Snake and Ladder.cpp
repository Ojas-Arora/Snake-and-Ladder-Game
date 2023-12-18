#include <iostream>
#include <cstdlib>
#include <ctime>

void draw_line(int n, char ch);
void board();
void gamescore(const char name1[], const char name2[], int p1, int p2);
void play_dice(int &score);

int main() {
    int player1 = 0, player2 = 0, lastposition;
    char player1name[80], player2name[80];

    srand(static_cast<unsigned>(time(nullptr)));

    draw_line(50, '=');
    std::cout << "\n\n\n\n\t\tSNAKE LADDER GAME\n\n\n\n";
    draw_line(50, '=');
    std::cout << "\n\n\nEnter Name of player 1 :";
    std::cin.getline(player1name, 80);
    std::cout << "\n\n\Enter Name of player 2 :";
    std::cin.getline(player2name, 80);

    while (player1 < 100 && player2 < 100) {
        board();
        gamescore(player1name, player2name, player1, player2);

        std::cout << "\n\n--->" << player1name << " Now your Turn >> Press Enter to play ";
        std::cin.ignore();
        lastposition = player1;
        play_dice(player1);
        if (player1 < lastposition)
            std::cout << "\n\aOops!! Snake found !! You are at position " << player1 << "\n";
        else if (player1 > lastposition + 6)
            std::cout << "\nGreat!! you got a ladder !! You are at position " << player1;
        
        std::cout << "\n\n--->" << player2name << " Now your Turn >> Press Enter to play ";
        std::cin.ignore();
        lastposition = player2;
        play_dice(player2);
        if (player2 < lastposition)
            std::cout << "\n\n\aOops!! Snake found !! You are at position " << player2 << "\n";
        else if (player2 > lastposition + 6)
            std::cout << "\n\nGreat!! you got a ladder !! You are at position " << player2 << "\n";
    }

    std::cout << "\n\n\n";
    draw_line(50, '+');
    std::cout << "\n\n\t\tRESULT\n\n";
    draw_line(50, '+');
    std::cout << std::endl;
    gamescore(player1name, player2name, player1, player2);
    std::cout << "\n\n\n";
    if (player1 >= player2)
        std::cout << player1name << " !! You are the winner of the game\n\n";
    else
        std::cout << player2name << " !! You are the winner of the game\n\n";
    draw_line(50, '+');

    return 0;
}

void draw_line(int n, char ch) {
    for (int i = 0; i < n; i++)
        std::cout << ch;
}

void board() {
    std::system("clear");  // Use "cls" for Windows
    std::cout << "\n\n";
    draw_line(50, '-');
    std::cout << "\n\t\tSNAKE AT POSITION\n";
    draw_line(50, '-');
    std::cout << "\n\tFrom 98 to 28 \n\tFrom 95 to 24\n\tFrom 92 to 51\n\tFrom 83 to 19\n\tFrom 73 to 1\n\tFrom 69 to 33\n\tFrom 64 to 36\n\tFrom 59 to 17\n\tFrom 55 to 7\n\tFrom 52 to 11\n\tFrom 48 to 9\n\tFrom 46 to 5\n\tFrom 44 to 22\n\n";
    draw_line(50, '-');
    std::cout << "\n\t\t LADDER AT POSITION\n";
    draw_line(50, '-');
    std::cout << "\n\tFrom 8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
    draw_line(50, '-');
    std::cout << std::endl;
}

void gamescore(const char name1[], const char name2[], int p1, int p2) {
    std::cout << "\n";
    draw_line(50, '~');
    std::cout << "\n\t\tGAME STATUS\n";
    draw_line(50, '~');
    std::cout << "\n\t--->" << name1 << " is at position " << p1 << std::endl;
    std::cout << "\t--->" << name2 << " is at position " << p2 << std::endl;
    draw_line(50, '_');
    std::cout << std::endl;
}

void play_dice(int &score) {
    int dice;
    dice = rand() % 6 + 1;
    std::cout << "\nYou got " << dice << " Point !! ";
    score = score + dice;
    std::cout << "Now you are at position " << score;
    switch (score) {
        // Cases for snakes and ladders
        // ...
    }
}
