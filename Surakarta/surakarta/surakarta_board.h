#pragma once

#include <memory>
#include <vector>
#include "surakarta_piece.h"

#define BOARD_SIZE 6

//定义名为 SurakartRow 的类用来表示棋盘格线，board_size 即为棋盘大小
class SurakartRow : public std::vector<std::shared_ptr<SurakartaPiece>> { //这里的类 SurakartRow 是 std::vector<std::shared_ptr<SurakartaPiece>> 的模板派生类
   public:
    SurakartRow(unsigned int board_size)
        : std::vector<std::shared_ptr<SurakartaPiece>>(board_size) {}
};

//定义名为 SurakartBroad 的类用来表示棋盘
class SurakartaBoard : public std::vector<SurakartRow> { //这里的类 SurakartBoard 是 std::vector<SurakartRow> 的模板派生类
   public:
    unsigned int board_size_; //方形棋盘大小
    SurakartaBoard(unsigned int board_size)
        : board_size_(board_size) {
        for (unsigned int i = 0; i < board_size_; i++) {
            this->push_back(SurakartRow(board_size_));
        } // 将新的SurakartRow对象push到整个vector的末尾
    }

    bool IsInside(const SurakartaPosition& position) const {
        return position.x < board_size_ && position.y < board_size_;
    } // 定义函数 IsInside 判断棋子是否在棋盘中

    friend inline std::ostream& operator<<(std::ostream& os, const SurakartaBoard& board) {
        for (unsigned int y = 0; y < board.board_size_; y++) {
            for (unsigned int x = 0; x < board.board_size_; x++) {
                os << (*board[x][y]) << " ";
            }
            os << std::endl;
        }
        return os;
    } // 定义友元函数 operator<< 来将SurakartaBoard上的棋盘信息输出

    friend inline std::istream& operator>>(std::istream& is, SurakartaBoard& board) {
        for (unsigned int y = 0; y < board.board_size_; y++) {
            for (unsigned int x = 0; x < board.board_size_; x++) {
                char ch;
                is >> ch;
                PieceColor color;
                switch (ch) {
                    case 'B':
                        color = PieceColor::BLACK;
                        break;
                    case 'W':
                        color = PieceColor::WHITE;
                        break;
                    default:
                        color = PieceColor::NONE;
                        break;
                }
                board[x][y] = std::make_shared<SurakartaPiece>(x, y, color);
            }
        }
        return is;
    } // 定义友元函数 operator>> 来读入一个以字符串形式输入的棋盘
};
