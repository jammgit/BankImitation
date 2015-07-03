#ifndef CTITLEWIN_H
#define CTITLEWIN_H

#include "qtheader.h"

class CTitleWin :public QMainWindow
{
    Q_OBJECT
public:
    CTitleWin(QWidget *parent = NULL);
    ~CTitleWin();
    void paintEvent(QPaintEvent *);
    //void callBack(QMainWindow *win , int width , int height);
private:
    void initWidget();

private:
    QLabel *m_pTimeLabel;
    QLabel *m_pTitleLabel;
    QTimer *m_pClock;

    int m_width;
    int m_height;

private:
    QWidget *m_pParent;
};

#endif // CTitleWin_H
