#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

    //输入 paintevent 中 paint 的参数
    void GetPaintInfo_pix(QPixmap pix);
    void GetPaintInfo_scale(int scaleX,int scaleY);//缩放
    void GetPaintInfo_size(int width,int height);//填充大小
    void GetPaintInfo_pos(int posX,int posY);//填充位置


private:
    //paintevent 中 paint 的参数
    QPixmap pix;
    int scaleX=pix.width();
    int scaleY=pix.height();
    int width=pix.width();
    int height=pix.height();
    int posX;
    int posY;
signals:
protected:
    // void paintEvent(QPaintEvent *event)override;


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MYWIDGET_H
