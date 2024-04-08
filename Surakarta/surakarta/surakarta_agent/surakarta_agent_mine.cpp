#include "surakarta/surakarta_agent/surakarta_agent_mine.h"

SurakartaMove SurakartaAgentMine::CalculateMove() {
    // TODO: Implement your own ai here.
    SurakartaPosition Piece_from, Piece_to;
    
    

    //Step 1:对吃子进行评分处理
    struct Surakarta_move_score
    {
        SurakartaPosition Position_[2];
        int score_;
    };
    int board_size = BOARD_SIZE;
    Surakarta_move_score move_score[board_size][board_size];

    int max_score = 0;
    for(int i=0;i<board_size;i++) {
        for(int j=0;j<board_size;j++) {
            move_score[i][j].Position_[0] = SurakartaPosition(i,j);
            move_score[i][j].score_ = 0;
            if((*board_)[i][j]->GetColor() == game_info_->current_player_) {
                int capture_num = 0;
                for(int m=0;m<board_size;m++) {
                    for (int n=0;n<board_size;n++) {
                        SurakartaMove move = SurakartaMove(SurakartaPosition(i,j),SurakartaPosition(m,n),game_info_->current_player_); 
                        SurakartaIllegalMoveReason reason = rule_manager_->JudgeMove(move);   
                        if(reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE)
                        capture_num ++;
                    }
                }
                if(capture_num > 0)
                move_score[i][j].score_ = capture_num;
                if(move_score[i][j].score_ > max_score)
                max_score = move_score[i][j].score_;
            }
        }
    }

    //Step 2:找出评分最高的吃子
    if(max_score > 0) {
        for(int i=0;i<board_size;i++) {
            for(int j=0;j<board_size;j++) {
                if(move_score[i][j].score_ == max_score) {
                    Piece_from = move_score[i][j].Position_[0];
                    for(int m=0;m<board_size;m++) {
                        for(int n=0;n<board_size;n++) {
                            SurakartaMove move = SurakartaMove(Piece_from,SurakartaPosition(m,n),game_info_->current_player_);    
                            SurakartaIllegalMoveReason reason = rule_manager_->JudgeMove(move);   
                            if(reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
                                Piece_to = SurakartaPosition(m,n);
                                return SurakartaMove(Piece_from, Piece_to, game_info_->current_player_);
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        for(int i=0;i<board_size;i++) {
            for(int j=0;j<board_size;j++) {
                if((*board_)[i][j]->GetColor() == game_info_->current_player_) {
                    Piece_from = move_score[i][j].Position_[0];
                    for(int m=0;m<board_size && m<=i+1;m++) {
                        for(int n=0;n<board_size && n<=j+1;n++) {
                            SurakartaMove move = SurakartaMove(Piece_from,SurakartaPosition(m,n),game_info_->current_player_);    
                            SurakartaIllegalMoveReason reason = rule_manager_->JudgeMove(move);   
                            if(reason == SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE) {
                                Piece_to = SurakartaPosition(m,n);
                                return SurakartaMove(Piece_from, Piece_to, game_info_->current_player_);
                            }
                        }
                    }
                }
            }
        }
    }
    return SurakartaMove(Piece_from, Piece_to, game_info_->current_player_);
}