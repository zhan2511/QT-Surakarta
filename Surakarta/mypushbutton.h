#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushbutton(QWidget *parent = nullptr);

    //自定义图标
    void SetCustomisedIcon(QString NormalImage);
    int width;
    int height;
    int pixwidth=width;
    int pixheight=height;

    //弹跳特效
    void BounceDown();
    void BounceUp();


    // void PressEfect(QString PressImage);

signals:
private:
    QString NormalImage;
    QString PressImage;
};

#endif // MYPUSHBUTTON_H
