#include "surakarta_rule_manager.h"
#include <iostream>

void SurakartaRuleManager::OnUpdateBoard() {
    // TODO:
    // Every time the board and game_info is updated to the next round version, this function will be called.
    // You don't need to implement this function if you don't need it.
    // A more delicate way is to use Qt's signal and slot mechanism, but that's the advanced part.
}

SurakartaIllegalMoveReason SurakartaRuleManager::JudgeMove(const SurakartaMove& move) {
    // TODO: Implement this function.

    // An example of how to get the color of a piece and the current player.
    // for (unsigned int i = 0; i < board_size_; i++) {
    //     for (unsigned int j = 0; j < board_size_; j++) {
    //         PieceColor color = (*board_)[i][j]->GetColor();
    //         if (color == PieceColor::BLACK) {
    //             // i,j is the position of a black piece
    //         } else if (color == PieceColor::WHITE) {
    //             // i,j is the position of a white piece
    //         } else {
    //             // i,j is an empty position
    //         }
    //     }
    // }
    SurakartaPlayer current_player = game_info_->current_player_;
    if (move.player != game_info_->current_player_)
        return SurakartaIllegalMoveReason::NOT_PLAYER_TURN;
    else if (current_player == SurakartaPlayer::BLACK) {
        // black player's turn
        if(move.to.x >= board_size_ || move.to.y >= board_size_ || move.from.x >= board_size_ || move.from.y >= board_size_)
            return SurakartaIllegalMoveReason::OUT_OF_BOARD;
        else if(SurakartaPlayer::WHITE == (*board_)[move.from.x][move.from.y]->GetColor())
            return SurakartaIllegalMoveReason::NOT_PLAYER_PIECE;
        else if(PieceColor::NONE == (*board_)[move.from.x][move.from.y]->GetColor())
            return SurakartaIllegalMoveReason::NOT_PIECE;
        else if(move.to == move.from)
            return SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE;
        else if( (*board_)[move.to.x][move.to.y]->GetColor() == PieceColor::BLACK)
            return SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE;
        else if( (*board_)[move.to.x][move.to.y]->GetColor() == PieceColor::WHITE) {
            Circle_state Capture_circle_line[(int)board_size_*4+5]; // 构造两条棋子链
            Circle_state Capture_circle_list[(int)board_size_*4+5];
            Get_Capture_Circle_line(Capture_circle_line, board_, board_size_, move.from, move.to); // 获取两条链
            Get_Capture_Circle_list(Capture_circle_list, board_, board_size_, move.from, move.to);
            if(Is_Capture_False(Capture_circle_line, Capture_circle_list, board_size_) == false)
                return SurakartaIllegalMoveReason::ILLIGAL_CAPTURE_MOVE;
            else
                return SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE;
        }
        else if( (*board_)[move.to.x][move.to.y]->GetColor() == PieceColor::NONE) {
            if(Is_Move_False(move.from , move.to) == false)
                return SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE;
            else
                return SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE;
        }
        
    } else if (current_player == SurakartaPlayer::WHITE) {
        // white player's turn
        if(move.to.x >= board_size_ || move.to.y >= board_size_ || move.from.x >= board_size_ || move.from.y >= board_size_)
            return SurakartaIllegalMoveReason::OUT_OF_BOARD;
        else if(SurakartaPlayer::BLACK == (*board_)[move.from.x][move.from.y]->GetColor())
            return SurakartaIllegalMoveReason::NOT_PLAYER_PIECE;
        else if(PieceColor::NONE == (*board_)[move.from.x][move.from.y]->GetColor())
            return SurakartaIllegalMoveReason::NOT_PIECE;
        else if(move.to == move.from)
            return SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE;
        else if( (*board_)[move.to.x][move.to.y]->GetColor() == PieceColor::WHITE)
            return SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE;
        else if( (*board_)[move.to.x][move.to.y]->GetColor() == PieceColor::BLACK) {
            Circle_state Capture_circle_line[(int)board_size_*4+5];
            Circle_state Capture_circle_list[(int)board_size_*4+5];
            Get_Capture_Circle_line(Capture_circle_line, board_, board_size_, move.from, move.to);
            Get_Capture_Circle_list(Capture_circle_list, board_, board_size_, move.from, move.to);
            if(Is_Capture_False(Capture_circle_line, Capture_circle_list, board_size_) == false)
                return SurakartaIllegalMoveReason::ILLIGAL_CAPTURE_MOVE;
            else
                return SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE;
        }
        else if( (*board_)[move.to.x][move.to.y]->GetColor() == PieceColor::NONE) {
            if(Is_Move_False(move.from , move.to) == false)
                return SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE;
            else
                return SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE;
        }
    }
    return SurakartaIllegalMoveReason::LEGAL;
}

std::pair<SurakartaEndReason, SurakartaPlayer> SurakartaRuleManager::JudgeEnd(const SurakartaIllegalMoveReason reason) {
    // TODO: Implement this function.
    // Note that at this point, the board and game_info have not been updated yet.
    SurakartaPlayer current_player = game_info_->current_player_;

    if(reason == SurakartaIllegalMoveReason::ILLIGAL_CAPTURE_MOVE || reason == SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE || reason == SurakartaIllegalMoveReason::OUT_OF_BOARD || reason == SurakartaIllegalMoveReason::NOT_PIECE || reason == SurakartaIllegalMoveReason::NOT_PLAYER_PIECE) {
        if(current_player == SurakartaPlayer::WHITE)
            return std::make_pair(SurakartaEndReason::ILLIGAL_MOVE, SurakartaPlayer::BLACK);
        else
            return std::make_pair(SurakartaEndReason::ILLIGAL_MOVE, SurakartaPlayer::WHITE);
    }

    else if(reason == SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE) {
        if((int)game_info_->num_round_ - (int)game_info_->last_captured_round_ == (int)game_info_->max_no_capture_round_) {
            int black_piece_num = 0;
            int white_piece_num = 0;
            for (int i = 0; i < (int)board_size_; i++)
                for (int j = 0; j < (int)board_size_; j++) {
                    if ((*board_)[i][j]->GetColor() == PieceColor::BLACK)
                        black_piece_num++;
                    else if ((*board_)[i][j]->GetColor() == PieceColor::WHITE)
                        white_piece_num++;
                }
            if (black_piece_num>white_piece_num)
                return std::make_pair(SurakartaEndReason::STALEMATE, SurakartaPlayer::BLACK);
            else if (black_piece_num<white_piece_num)
                return std::make_pair(SurakartaEndReason::STALEMATE, SurakartaPlayer::WHITE);
            else 
                return std::make_pair(SurakartaEndReason::STALEMATE, SurakartaPlayer::NONE);
        }
    }

    else if(reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
        if(current_player == SurakartaPlayer::WHITE) {
            int not_be_captured = 0;
            for(int i = 0; i < (int)board_size_; i++)
                for(int j = 0; j < (int)board_size_; j++)
                    if((*board_)[i][j]->GetColor() == PieceColor::BLACK)
                        not_be_captured++;
            if(not_be_captured == 1)
                return std::make_pair(SurakartaEndReason::CHECKMATE, SurakartaPlayer::WHITE);
        }
        else if(current_player == SurakartaPlayer::BLACK) {
            int not_be_captured = 0;
            for(int i = 0; i < (int)board_size_; i++)
                for(int j = 0; j < (int)board_size_; j++)
                    if((*board_)[i][j]->GetColor() == PieceColor::WHITE)
                        not_be_captured++;
            if(not_be_captured == 1)
                return std::make_pair(SurakartaEndReason::CHECKMATE, SurakartaPlayer::BLACK);
        }
    }

    return std::make_pair(SurakartaEndReason::NONE, SurakartaPlayer::NONE);
}

std::unique_ptr<std::vector<SurakartaPosition>> SurakartaRuleManager::GetAllLegalTarget([[maybe_unused]]const SurakartaPosition postion) {
    // TODO:
    // We don't test this function, you don't need to implement this function if you don't need it.
    return std::make_unique<std::vector<SurakartaPosition>>();
}

void SurakartaRuleManager::HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}
