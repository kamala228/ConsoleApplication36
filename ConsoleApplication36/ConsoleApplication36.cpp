//#include <iostream>
//#include <string>
//#include <vector>
//#include <windows.h>
//
//using namespace std;
//
//struct Word {
//    string ua;
//    string en;
//    string de;
//    string fr;
//};
//
//int main() {
//    system("chcp 1251 >nul");
//
//    vector<Word> words = {
//        {"кіт", "cat", "Katze", "chat"},
//        {"собака", "dog", "Hund", "chien"},
//        {"сонце", "sun", "Sonne", "soleil"},
//        {"книга", "book", "Buch", "livre"},
//        {"яблуко", "apple", "Apfel", "pomme"}
//    };
//
//    cout << "Вивчення іноземних мов!\n";
//    cout << "Оберіть мову для перекладу з української:\n";
//    cout << "1 - Англійська\n";
//    cout << "2 - Німецька\n";
//    cout << "3 - Французька\n";
//    int choice;
//    cin >> choice;
//
//    int score = 0;
//
//    for (auto& word : words) {
//        cout << "\nПерекладіть слово: " << word.ua << "\n";
//        string answer;
//        cout << "Ваша відповідь: ";
//        cin >> answer;
//
//        string correct;
//        if (choice == 1) correct = word.en;
//        else if (choice == 2) correct = word.de;
//        else if (choice == 3) correct = word.fr;
//        else {
//            cout << "Невірний вибір мови.\n";
//            return 1;
//        }
//
//        if (answer == correct) {
//            cout << "Правильно!\n";
//            score++;
//        }
//        else {
//            cout << "Неправильно. Правильна відповідь: " << correct << "\n";
//        }
//    }
//
//    cout << "\nРезультат: " << score << " з " << words.size() << "\n";
//
//    return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

struct Card {
    int value;
    bool revealed = false;
};

void printBoard(const vector<Card>& board) {
    cout << "\nПоле:\n";
    for (size_t i = 0; i < board.size(); ++i) {
        if (board[i].revealed)
            cout << "[" << board[i].value << "] ";
        else
            cout << "[" << i + 1 << "] ";
    }
    cout << "\n";
}

int main() {
    system("chcp 1251 >nul");
    srand(time(0));

    vector<Card> board = {
        {1}, {2}, {1}, {2}
    };

    random_shuffle(board.begin(), board.end());

    int moves = 0;
    int foundPairs = 0;

    while (foundPairs < board.size() / 2) {
        printBoard(board);
        int a, b;
        cout << "Оберіть першу картку (1-" << board.size() << "): ";
        cin >> a;
        cout << "Оберіть другу картку (1-" << board.size() << "): ";
        cin >> b;

        if (a == b || a < 1 || b < 1 || a > board.size() || b > board.size()) {
            cout << "Невірний вибір.\n";
            continue;
        }

        --a; --b;

        board[a].revealed = true;
        board[b].revealed = true;
        printBoard(board);
        moves++;

        if (board[a].value == board[b].value) {
            cout << "Пара знайдена!\n";
            foundPairs++;
        }
        else {
            cout << "Не співпадає. Спробуйте ще.\n";
            board[a].revealed = false;
            board[b].revealed = false;
        }
    }

    cout << "\nВітаю! Ви знайшли всі пари за " << moves << " ходів!\n";
    return 0;
}
