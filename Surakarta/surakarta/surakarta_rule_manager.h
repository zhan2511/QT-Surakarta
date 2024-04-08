#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "surakarta_common.h"

class SurakartaRuleManager {
   public:
    SurakartaRuleManager() = default;

    SurakartaRuleManager(std::shared_ptr<SurakartaBoard> board,
                         std::shared_ptr<SurakartaGameInfo> game_info)
        : board_size_(board->board_size_),
          board_(std::const_pointer_cast<const SurakartaBoard>(board)),
          game_info_(std::const_pointer_cast<const SurakartaGameInfo>(game_info)) {}

    unsigned int GetBoardSize() {
        return board_size_;
    }

    virtual void OnUpdateBoard();

    /**
     * @brief Judge whether a move is legal.
     * @param move The move to be judged.
     */
    virtual SurakartaIllegalMoveReason JudgeMove(const SurakartaMove& move);

    /**
     * @brief Judge whether the game is end.
     * @param reason SurakartaIllegalMoveReason of the last move.
     */
    virtual std::pair<SurakartaEndReason, SurakartaPlayer> JudgeEnd(const SurakartaIllegalMoveReason reason);

    /**
     * @brief Get all legal target positions of a piece.
     * @param postion The position of the piece.
     */
    virtual std::unique_ptr<std::vector<SurakartaPosition>> GetAllLegalTarget(const SurakartaPosition postion);

    //    protected:
    unsigned int board_size_;
    std::shared_ptr<const SurakartaBoard> board_;
    std::shared_ptr<const SurakartaGameInfo> game_info_;

   public:
    // TODO:
    //  define your own functions/variables here
    enum class Circle_state {
        Empty,
        Piece,
        Corner,
        End
    };

    Circle_state Judge_state(std::shared_ptr<const SurakartaBoard> board, unsigned int x, unsigned int y) {
        if((*board)[x][y]->GetColor() == PieceColor::NONE)
            return Circle_state::Empty;
        else
            return Circle_state::Piece;
    }

    void Get_Capture_Circle_line(Circle_state Capture_Circle_line[], std::shared_ptr<const SurakartaBoard> board, unsigned int board_size, SurakartaPosition move_from, SurakartaPosition move_to) {
        //转换unsigned int为int以避免warning报错
        int board_s = (int)board_size;
        int move_x = (int)move_from.x;
        int move_y = (int)move_from.y;
        int move_from_x = (int)move_from.x;
        int move_from_y = (int)move_from.y;
        int move_to_x = (int)move_to.x;
        int move_to_y = (int)move_to.y;
        int corner_times = 0;
        bool have_get;

        //我在此处对棋子链的顺序进行了规定，第一步先往左走
        //  ->如果棋子的起始位置是第一行或者最后一行，那么它将无法走入旋吃轨道
        //  ->将棋子链的初末状态用“Piece”堵住使得这个链不能成为“可以吃子”的链
        if(move_from_y == 0 || move_from_y == board_s - 1) {
            Capture_Circle_line[0] = Circle_state::Piece;
            Capture_Circle_line[board_s*4+3] = Circle_state::Piece;
        }
        
        //在棋盘上半部分
        else if(move_from_y <= board_s / 2 - 1) {
            //通过循环对棋子链进行遍历
            for (int i = 0; i < board_s*4+4; i++) {
                //对特殊棋子进行处理，使得下一个位置能被正确的找到
                have_get = false;
                //起始位置显然不会挡住路径，特殊处理
                if(move_x == move_from_x && move_y == move_from_y) {
                    Capture_Circle_line[i] = Circle_state::Empty;
                    have_get = true;
                }
                //对吃子终点进行特殊处理
                if(move_x == move_to_x && move_y == move_to_y) {
                    Capture_Circle_line[i] = Circle_state::End;
                    have_get = true;
                }
                //corner_times用于记录已经经过的角点，以精确确定下一个位置
                if(corner_times == 0) {
                    if(move_x == -1) {
                        Capture_Circle_line[i] = Circle_state::Corner;
                        move_x = move_y;
                        move_y = 0;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                        move_x--;
                    }
                }

                else if(corner_times == 1) {
                    if(move_y == board_s) {
                        Capture_Circle_line[i] = Circle_state::Corner;
                        move_y = board_s - move_x - 1;
                        move_x = 0;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                        move_y++;
                    }
                }

                else if(corner_times == 2) {
                    if(move_x == board_s) {
                        Capture_Circle_line[i] = Circle_state::Corner;
                        move_x = move_y;
                        move_y = board_s - 1;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                        move_x++;
                    }
                }

                else if(corner_times == 3) {
                    if(move_y == -1) {
                        Capture_Circle_line[i] = Circle_state::Corner;
                        move_y = board_s - move_x - 1;
                        move_x = board_s - 1;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                        move_y--;
                    }
                }

                else {
                    if(have_get == false)
                    Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                    move_x--;
                }
            }
        }
        //在棋盘下半部分
        else {
            for (int i = 0; i < board_s*4+4; i++) {

                have_get = false;

                if(move_x == move_from_x && move_y == move_from_y) {
                    Capture_Circle_line[i] = Circle_state::Empty;
                    have_get = true;
                }

                if(move_x == move_to_x && move_y == move_to_y) {
                    Capture_Circle_line[i] = Circle_state::End;
                    have_get = true;
                }

                if(corner_times == 0) {
                    if(move_x == -1) {
                        Capture_Circle_line[i] = Circle_state::Corner;
                        move_x = board_s - move_y - 1;
                        move_y = board_s - 1;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                        move_x--;
                    }
                }

                else if(corner_times == 1) {
                    if(move_y == -1) {
                        Capture_Circle_line[i] = Circle_state::Corner;
                        move_y = move_x;
                        move_x = 0;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                        move_y--;
                    }
                }

                else if(corner_times == 2) {
                    if(move_x == board_s) {
                        Capture_Circle_line[i] = Circle_state::Corner;
                        move_x = board_s - move_y - 1;
                        move_y = 0;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                        move_x++;
                    }
                }

                else if(corner_times == 3) {
                    if(move_y == board_s) {
                        Capture_Circle_line[i] = Circle_state::Corner;
                        move_y = move_x;
                        move_x = board_s - 1;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                        move_y++;
                    }
                }

                else {
                    if(have_get == false)
                    Capture_Circle_line[i] = Judge_state(board, move_x, move_y);
                    move_x--;
                }
            }
        }
    }
    //同理（第一步是竖着走的）
    void Get_Capture_Circle_list(Circle_state Capture_Circle_list[], std::shared_ptr<const SurakartaBoard> board, unsigned int board_size, SurakartaPosition move_from, SurakartaPosition move_to) {
        
        int board_s = (int)board_size;
        int move_x = (int)move_from.x;
        int move_y = (int)move_from.y;
        int move_from_x = (int)move_from.x;
        int move_from_y = (int)move_from.y;
        int move_to_x = (int)move_to.x;
        int move_to_y = (int)move_to.y;
        int corner_times = 0;
        bool have_get;

        if(move_from_x == 0 || move_from_x == board_s - 1) {
            Capture_Circle_list[0] = Circle_state::Piece;
            Capture_Circle_list[board_s*4+3] = Circle_state::Piece;
        }
        else if(move_from_x <= board_s / 2 - 1) {
            for (int i = 0; i < board_s*4+4; i++) {

                have_get = false;
                
                if(move_x == move_from_x && move_y == move_from_y) {
                    Capture_Circle_list[i] = Circle_state::Empty;
                    have_get = true;
                }

                if(move_x == move_to_x && move_y == move_to_y) {
                    Capture_Circle_list[i] = Circle_state::End;
                    have_get = true;
                }

                if(corner_times == 0) {
                    if(move_y == -1) {
                        Capture_Circle_list[i] = Circle_state::Corner;
                        move_y = move_x;
                        move_x = 0;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                        move_y--;
                    }
                }

                else if(corner_times == 1) {
                    if(move_x == board_s) {
                        Capture_Circle_list[i] = Circle_state::Corner;
                        move_x = board_s - move_y - 1;
                        move_y = 0;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                        move_x++;
                    }
                }

                else if(corner_times == 2) {
                    if(move_y == board_s) {
                        Capture_Circle_list[i] = Circle_state::Corner;
                        move_y = move_x;
                        move_x = board_s - 1;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                        move_y++;
                    }
                }

                else if(corner_times == 3) {
                    if(move_x == -1) {
                        Capture_Circle_list[i] = Circle_state::Corner;
                        move_x = board_s - move_y - 1;
                        move_y = board_s - 1;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                        move_x--;
                    }
                }

                else {
                    if(have_get == false)
                    Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                    move_y--;
                }
            }
        }
        else {
            for (int i = 0; i < board_s*4+4; i++) {

                have_get = false;

                if(move_x == move_from_x && move_y == move_from_y) {
                    Capture_Circle_list[i] = Circle_state::Empty;
                    have_get = true;
                }

                if(move_x == move_to_x && move_y == move_to_y) {
                    Capture_Circle_list[i] = Circle_state::End;
                    have_get = true;
                }

                if(corner_times == 0) {
                    if(move_y == -1) {
                        Capture_Circle_list[i] = Circle_state::Corner;
                        move_y = board_s - move_x - 1;
                        move_x = board_s - 1;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                        move_y--;
                    }
                }

                else if(corner_times == 1) {
                    if(move_x == -1) {
                        Capture_Circle_list[i] = Circle_state::Corner;
                        move_x = move_y;
                        move_y = 0;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                        move_x--;
                    }
                }

                else if(corner_times == 2) {
                    if(move_y == board_s) {
                        Capture_Circle_list[i] = Circle_state::Corner;
                        move_y = board_s - move_x - 1;
                        move_x = 0;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                        move_y++;
                    }
                }

                else if(corner_times == 3) {
                    if(move_x == board_s) {
                        Capture_Circle_list[i] = Circle_state::Corner;
                        move_x = move_y;
                        move_y = board_s - 1;
                        corner_times++;
                    }
                    else {
                        if(have_get == false)
                        Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                        move_x++;
                    }
                }

                else {
                    if(have_get == false)
                    Capture_Circle_list[i] = Judge_state(board, move_x, move_y);
                    move_y--;
                }
            }
        }
    }

    //对棋子链进行分析判断的函数
    bool Is_Capture_False(Circle_state Circle_line[], Circle_state Circle_list[], unsigned int board_size) {  
        
        int board_s = (int)board_size;
        bool Through_corner; // 是否经过了旋吃轨道

        Through_corner = false;
        for(int i=0; i<board_s*4+4; i++) {
            if(Circle_line[i] == Circle_state::End && Through_corner) return true; 
            else if(Circle_line[i] == Circle_state::Corner) Through_corner = true;
            else if(Circle_line[i] == Circle_state::Piece || (Circle_line[i] == Circle_state::End && !Through_corner) ) break;
        }

        Through_corner = false;
        for(int i=board_s*4+3; i>=0; i--) {
            if(Circle_line[i] == Circle_state::End && Through_corner) return true;
            else if(Circle_line[i] == Circle_state::Corner) Through_corner = true;
            else if(Circle_line[i] == Circle_state::Piece || (Circle_line[i] == Circle_state::End && !Through_corner) ) break;
        }

        Through_corner = false;
        for(int i=0; i<board_s*4+4; i++) {
            if(Circle_list[i] == Circle_state::End && Through_corner) return true;
            else if(Circle_list[i] == Circle_state::Corner) Through_corner = true;
            else if(Circle_list[i] == Circle_state::Piece || (Circle_list[i] == Circle_state::End && !Through_corner) ) break;
        }

        Through_corner = false;
        for(int i=board_s*4+3; i>=0; i--) {
            if(Circle_list[i] == Circle_state::End && Through_corner) return true;
            else if(Circle_list[i] == Circle_state::Corner) Through_corner = true;
            else if(Circle_list[i] == Circle_state::Piece || (Circle_list[i] == Circle_state::End && !Through_corner) ) break;
        }
        
        return false;
    }

    bool Is_Move_False(SurakartaPosition move_from, SurakartaPosition move_to) {
        if ( (int) move_from.x - (int) move_to.x <= 1 && (int) move_from.y - (int) move_to.y <= 1 && (int) move_to.x - (int) move_from.x <= 1 && (int) move_to.y - (int) move_from.y <= 1)
            return true;
        else
            return false;
    } // 判断是否为合法的不吃子移动
    
    void HelloWorld();

    void InlineHelloWorld() {
        std::cout << "Hello World!" << std::endl;
    }

    int bye_world_ = 0;
};