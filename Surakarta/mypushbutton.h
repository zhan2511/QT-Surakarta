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
    QString PressImage="";

    //弹跳特效
    void BounceDown();
    void BounceUp();


signals:
private:
    QString NormalImage;
    // QString ReleaseImage;

    // QWidget interface
protected:

    //按压效果
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // MYPUSHBUTTON_H
