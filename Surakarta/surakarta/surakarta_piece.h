#pragma once

#include <iostream>

using PieceColorMemoryType = int;
enum class PieceColor : PieceColorMemoryType { BLACK,
                                               WHITE,
                                               NONE,
                                               UNKNOWN
}; // 对状态定义为类 PieceColor 

using SurakartaPlayer = PieceColor; // 玩家状态与类 PieceColor 对接

inline PieceColor ReverseColor(PieceColor color) {
    switch (color) {
        case PieceColor::BLACK:
            return PieceColor::WHITE;
        case PieceColor::WHITE:
            return PieceColor::BLACK;
        default:
            return color;
    }
} // 创建反色函数 ReverseColor，将接收到的color转换为相反状态

inline std::ostream& operator<<(std::ostream& os, const PieceColor& color) {
    switch (color) {
        case PieceColor::NONE:
            os << ".";
            break;
        case PieceColor::BLACK:
            os << "B";
            break;
        case PieceColor::WHITE:
            os << "W";
            break;
        default:
            os << "?";
            break;
    }
    return os;
} // 创建重载函数 std::ostream& operator<< 将接收到的状态color转换为字符串输出

inline std::istream& operator>>(std::istream& is, PieceColor& color) {
    char ch;
    is >> ch;
    switch (ch) {
        case '.':
            color = PieceColor::NONE;
            break;
        case 'B':
            color = PieceColor::BLACK;
            break;
        case 'W':
            color = PieceColor::WHITE;
            break;
        default:
            color = PieceColor::UNKNOWN;
            break;
    }
    return is;
} // 创建重载函数 std::istream& operator>> 将接收到的字符ch转换为相对应状态

struct SurakartaPosition {
    unsigned int x;
    unsigned int y;
    SurakartaPosition(unsigned int x = 0, unsigned int y = 0) // 构造初始化参数函数，将坐标x，y均设为0
        : x(x), y(y) {} 
    friend std::ostream& operator<<(std::ostream& os, const SurakartaPosition& pos) {
        os << "(" << pos.x << ", " << pos.y << ")";
        return os;
    } // 将SurakartaPosition中的位置数据以os的友元函数形式输出
    bool operator==(const SurakartaPosition& rhs) const {
        return x == rhs.x && y == rhs.y;
    } // 比较两个SurakartaPosition对象是否相等
    bool operator!=(const SurakartaPosition& rhs) const {
        return !(*this == rhs);
    } // 比较两个SurakartaPosition对象是否不相等
};// 创建结构体 SurakartaPosition 来表示棋盘上的位置

class SurakartaPiece {
   public:
    SurakartaPiece()
        : position_({0, 0}), color_(PieceColor::NONE) {}

    SurakartaPiece(unsigned int x, unsigned int y, PieceColor color)
        : position_({x, y}), color_(color) {}

    SurakartaPiece(SurakartaPosition position, PieceColor color)
        : position_(position), color_(color) {}
    // 构造函数 SurakartaPiece 获取三种不同输入模式下棋子的位置和颜色信息

    void SetPosition(SurakartaPosition position) { position_ = position; } // 设置棋子位置
    void SetColor(PieceColor color) { color_ = color; } // 设置棋子颜色
    void Set(SurakartaPosition position, PieceColor color) { // 整体设置棋子
        position_ = position;
        color_ = color;
    }
    SurakartaPosition GetPosition() const { return position_; } //获取Position
    PieceColor GetColor() const { return color_; } //获取Color

    friend std::ostream& operator<<(std::ostream& os, const SurakartaPiece& piece) {
        os << piece.color_;
        return os;
    } // 友元函数，只输出棋子的颜色（即B or W or NONE）

    //    private:
    SurakartaPosition position_;
    PieceColor color_;
}; //创建整体类 SurakartaPiece 来描述各项元素的数据