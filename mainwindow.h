#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// ****** QT header ******
#include "qtheader.h"

// ****** window class ******
#include "titlewin.h"
#include "brokenimage.h"
#include "queueimitation.h"
#include "controlwin.h"

class CTitleWin;
class CBrokenImage;
class CQueueImitation;
class CControlWin;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);


public slots:
    void changeOpacity();
    void readyClose();

protected:
    void closeEvent(QCloseEvent *);

private:
    void initWidget();
    void initConnect();


    // ****** 以下是子窗口类及绘图变量 ******
private:
    CTitleWin *m_pTitleWin;
    CBrokenImage *m_pBrokenWin;
    CQueueImitation *m_pQueueWin;
    CControlWin *m_pControlWin;
    // ****** 以上是子窗口类及绘图变量 ******

private:
//    QPalette *m_pPale;
//    QTimer *m_pTimer;
    QPushButton *m_pCloseBtn;
    QPushButton *m_pMinBtn;

    // ****** 以下是窗口移动变量 ******
private:
    QPoint m_winPos;
    QPoint m_mousePos;
    QPoint m_dPos;
    bool m_Drag;
   // ****** 以上是窗口移动变量 ******

    QColor m_startColor;
    int m_currentAlpha;
    int m_fadeTimes;
    QTimer *m_pTimer;
    double m_opacity;
};

#endif // MAINWINDOW_H
