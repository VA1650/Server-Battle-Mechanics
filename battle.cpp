#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <ctime>
#include <algorithm> // Для std::max

using namespace std;

// Константы для цветов
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string RESET = "\033[0m";

struct GameState {
    vector<int> servers = { 100, 100, 100 };

    int totalPower() const {
        return accumulate(servers.begin(), servers.end(), 0);
    }

    bool isDead() const {
        for (int s : servers) if (s <= 0) return true;
        return false;
    }
};

void displayStatus(const GameState& player, const GameState& oponent) {
    cout << "\n" << YELLOW << "--- Battle Grid Status ---" << RESET << "\n";
    cout << RED << "OPONENT: " << RESET << oponent.totalPower() << " | ";
    for (int s : oponent.servers) cout << "[" << (s > 0 ? to_string(s) : "OFF") << "] ";

    cout << "\n" << GREEN << "YOU:     " << RESET << player.totalPower() << " | ";
    for (int s : player.servers) cout << "[" << (s > 0 ? to_string(s) : "OFF") << "] ";
    cout << "\n" << YELLOW << "--------------------------" << RESET << "\n";
}

pair<int, int> getSmartMove(const GameState& ai, const GameState& human, int lastHumanDef) {
    int target = -1;
    int protect = 0;

    // 1. Lethal Check (Добивание)
    for (int i = 0; i < 3; ++i) {
        if (human.servers[i] > 0 && human.servers[i] <= 20 && (i + 1) != lastHumanDef) {
            target = i;
            break;
        }
    }

    // 2. Adaptive Attack (Обход защиты)
    if (target == -1) {
        vector<int> possible;
        for (int i = 0; i < 3; ++i) {
            if (human.servers[i] > 0) {
                if ((i + 1) == lastHumanDef && (rand() % 100 < 80)) continue;
                possible.push_back(i);
            }
        }
        if (possible.empty()) {
            for (int i = 0; i < 3; ++i) if (human.servers[i] > 0) possible.push_back(i);
        }
        target = possible[rand() % possible.size()]; // Рандом среди эффективных
    }

    // 3. Smart Defense
    for (int i = 1; i < 3; ++i) {
        if (ai.servers[i] < ai.servers[protect]) protect = i;
    }

    return { target + 1, protect + 1 };
}

void playGame() {
    GameState player, oponent;
    int pAtack, pDef, lastPDef = -1;
    srand(time(0));

    cout << "System initiated. Identify target and defense nodes (1-3).\n";

    while (!player.isDead() && !oponent.isDead()) {
        displayStatus(player, oponent);

        cout << "Select node to ATTACK (1-3): ";
        while (!(cin >> pAtack) || pAtack < 1 || pAtack > 3) {
            cout << RED << "Invalid node. Choose 1, 2 or 3: " << RESET;
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Select node to DEFEND (1-3): ";
        while (!(cin >> pDef) || pDef < 1 || pDef > 3) {
            cout << RED << "Invalid node. Choose 1, 2 or 3: " << RESET;
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // Дальше идет вызов бота и логика боя...
        auto [oAtack, oDef] = getSmartMove(oponent, player, lastPDef);
        lastPDef = pDef; // Запоминаем деф для следующего хода бота

        // Player's Turn
        if (pAtack != oDef) {
            oponent.servers[pAtack - 1] = max(0, oponent.servers[pAtack - 1] - 20);
            cout << GREEN << ">> Hit confirmed on node " << pAtack << RESET << "\n";
        }
        else cout << YELLOW << ">> Opponent firewall blocked attack on " << pAtack << RESET << "\n";

        // AI's Turn
        if (oAtack != pDef) {
            player.servers[oAtack - 1] = max(0, player.servers[oAtack - 1] - 20);
            cout << RED << ">> Security breach on node " << oAtack << RESET << "\n";
        }
        else cout << BLUE << ">> You blocked attack on node " << oAtack << RESET << "\n";
    }

    displayStatus(player, oponent);
    if (oponent.isDead()) cout << GREEN << "VICTORY: Enemy system bypassed." << RESET << "\n";
    else cout << RED << "CRITICAL FAILURE: System offline." << RESET << "\n";
}

int main() {
    string choice;
    do {
        playGame();
        cout << "Restart sequence? (Y/N): ";
        cin >> choice;
    } while (choice == "Y" || choice == "y");
    return 0;
}
