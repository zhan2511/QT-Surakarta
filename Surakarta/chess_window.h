#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H

#include <QMainWindow>
#include "mypieces.h"
#include "surakarta/surakarta_game.h"
#include "surakarta/surakarta_common.h"
#include "surakarta/surakarta_agent/surakarta_agent_mine.h"
#include "surakarta/surakarta_agent/surakarta_agent_random.h"
#include <QWaitCondition>

// extern SurakartaGame game;


class chess_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit chess_window(QWidget *parent = nullptr);
    // ~chess_window();

    void paintEvent(QPaintEvent *);

    std::shared_ptr<SurakartaAgentMine> Blackagent;
    std::shared_ptr<SurakartaAgentRandom> Whiteagent;
    SurakartaPlayer BlackGamer=SurakartaPlayer::NONE;
    SurakartaPlayer WhiteGamer=SurakartaPlayer::NONE;
    // SurakartaGame *game;
    SurakartaMove Blackmove;
    SurakartaMove Whitemove;
    SurakartaMove Gamermove_;

    std::vector<MyPieces*> pieces;

    QWaitCondition cdt;

    bool status=0;
    int frompos;
    int topos;

    QString BlackPawn=":/rsc/BlackPawn.png";
    QString WhitePawn=":/rsc/WhitePawn.png";
    QString Blank="";



signals:
    void select(int pos);
    void moveend(int pos);
    void blackmove(SurakartaMove Blackmove);
    void whitemove(SurakartaMove Whitemove);



public slots:
    void select_(int pos);
    void moveend_(int pos);
    void winner_(SurakartaGame game);
    void setboard(SurakartaGame game);
    void decideblackmove(SurakartaGame game);
    void decidewhitemove(SurakartaGame game);


};

#endif // CHESS_WINDOW_H
