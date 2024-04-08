#include <chrono>
#include <iostream>
#include <thread>
#include "surakarta/surakarta_agent/surakarta_agent_mine.h"
#include "surakarta/surakarta_agent/surakarta_agent_random.h"
#include "surakarta/surakarta_common.h"
#include "surakarta/surakarta_game.h"

#define ANSI_CLEAR_SCREEN "\033[2J"
#define ANSI_MOVE_TO_START "\033[H"
#define SLEEP_TIME_MS 0
#define TEST_ROUND 1000

class SurakartaGame_play {
   public:
    struct Game_play_result {
        PieceColor Mine;
        SurakartaPlayer winner_;
    };

    SurakartaGame game;

    const Game_play_result PlayGame() {
        PieceColor Mine;
        game.StartGame();
        std::shared_ptr<SurakartaAgentMine> agent1 = std::make_shared<SurakartaAgentMine>(game.GetBoard(), game.GetGameInfo(), game.GetRuleManager());
        std::shared_ptr<SurakartaAgentRandom> agent2 = std::make_shared<SurakartaAgentRandom>(game.GetBoard(), game.GetGameInfo(), game.GetRuleManager());
        bool is_agent1_turn = rand() % 2 == 0;  // 随机模拟先后手
        if (is_agent1_turn)
            Mine = PieceColor::BLACK;
        else
            Mine = PieceColor::WHITE;
        while (!game.IsEnd()) {
            if (is_agent1_turn) {
                auto move = agent1->CalculateMove();
                game.Move(move);
                is_agent1_turn = !is_agent1_turn;
            } else {
                auto move = agent2->CalculateMove();
                game.Move(move);
                is_agent1_turn = !is_agent1_turn;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME_MS));
        }
        return Game_play_result{Mine, game.GetGameInfo()->winner_};
    }
};

int main() {
    // SurakartaGame game;
    // game.GetRuleManager()->HelloWorld();
    // game.StartGame();
    // TODO: After you pass the test, uncomment the following code, you should see a random game.
    // std::shared_ptr<SurakartaAgentRandom> agent = std::make_shared<SurakartaAgentRandom>(game.GetBoard(), game.GetGameInfo(), game.GetRuleManager());
    // std::cout << ANSI_CLEAR_SCREEN << ANSI_MOVE_TO_START;
    // while (!game.IsEnd()) {
    //     auto move = agent->CalculateMove();
    //     game.Move(move);
    //     std::cout << *game.GetBoard() << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //     std::cout << ANSI_CLEAR_SCREEN << ANSI_MOVE_TO_START;
    // }
    // std::cout << *game.GetBoard();
    // std::cout << game.GetGameInfo()->end_reason_ << std::endl;

    // TODO: Create 2 agent, one is SurakartaAgentRandom, the other is your own agent. Let them play against each other.
    std::cout << ANSI_CLEAR_SCREEN << ANSI_MOVE_TO_START;
    double Mine_win = 0;
    double Random_win = 0;
    double Stalemate = 0;
    for (int i = 0; i < TEST_ROUND; i++) {
        SurakartaGame_play game;
        SurakartaGame_play::Game_play_result result = game.PlayGame();
        if (result.winner_ == result.Mine) {
            Mine_win++;
        } else if (result.winner_ == ReverseColor(result.Mine)) {
            Random_win++;
        } else
            Stalemate++;
        printf("Win rate:");
        printf("%.2lf%% ", Mine_win / (Mine_win + Random_win + Stalemate) * 100);
        std::cout << "  Random_win: " << Random_win << "  Mine_win: " << Mine_win << "  Stalemate:" << Stalemate << std::endl;
    }
    return 0;
}
