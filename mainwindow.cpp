
#include "mainwindow.h"
#include <qmath.h>
#include <cmath>
#include <cstdlib>

const int WIDTH = 1000;
const int HEIGHT = 620;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_pTitleWin(new CTitleWin(this)),
      m_pBrokenWin(new CBrokenImage(this)),
      m_pQueueWin(new CQueueImitation(this)),
      m_pControlWin(new CControlWin(this))
{
    // 回调函数，显示数字时间
    this -> resize(WIDTH,HEIGHT);
    this -> setMinimumSize(1000,620);
    //m_pClockWin -> callBack(this ,WIDTH , HEIGHT );

    initWidget();
    initConnect();  


//    if (parent)
//        m_startColor = parent->palette().window().color();
//    else
//        m_startColor = Qt::white;

//    m_currentAlpha = 255;
//    m_fadeTimes = 1000;

    m_opacity = 1.0;
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()),this, SLOT(changeOpacity()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::initWidget()
{
//    this -> setStyleSheet("background-color:rgb(150,40,39);");
//    QPalette pale;
//    pale.setColor(QPalette::Background, QColor(150,50,68));
//    this -> setPalette(pale);
    m_pTitleWin -> setWindowFlags(Qt::SubWindow);
    m_pBrokenWin -> setWindowFlags(Qt::SubWindow);
    m_pQueueWin -> setWindowFlags(Qt::SubWindow);
    m_pControlWin -> setWindowFlags(Qt::SubWindow);


    m_pCloseBtn = new QPushButton("close",this);
    m_pMinBtn = new QPushButton("Min",this);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //if(event->button() == Qt::LeftButton)
    {
        this -> m_winPos = this -> pos();
        this -> m_mousePos = event -> globalPos();
        this -> m_dPos = m_mousePos - m_winPos;
    }
//    if (event->button() == Qt::LeftButton) {
//       m_Drag = true;
//       m_winPos = event->globalPos() - this->pos();
//       event->accept();
//   }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this -> move( event-> globalPos() - this -> m_dPos);
//    if (m_Drag && (event->buttons() && Qt::LeftButton)) {
//       move(event->globalPos() - m_winPos);
//       event->accept();
//   }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    m_Drag = false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // ... imitate qq close

    //this -> paintEvent(NULL);
    //m_pTimer -> start(1000);

    //this -> close();
}

void MainWindow::paintEvent(QPaintEvent *)
{

    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(10, 10, this->width()-20, this->height()-20);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(QColor(255,255,255)));

    QColor color(0, 0, 0, 50);
    for(int i=0; i<10; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(10-i, 10-i, this->width()-(10-i)*2, this->height()-(10-i)*2);
        color.setAlpha(150 - sqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }

    m_pQueueWin -> setGeometry(this->width()/67,this->height()*38/50,this->width()*127/200,this->height()*136/620);

    m_pTitleWin -> setGeometry(this->width()/67,this->height()*12/500,this->width()*777/800,this->height()*68/500);
    m_pBrokenWin -> setGeometry(this->width()/67,this->height()*8/50
                                ,this->width()*127/200,this->height()*37/62);
    m_pControlWin -> setGeometry(this->width()*521/800,this->height()*80/500,this->width()*268/800,
                                 this->height()*38/50 - this->height()*8/50 + m_pQueueWin -> height());//this->height()*410/500);
    //m_pTitleLabel -> setGeometry(QRect(this->width()*180/800,this->height()*10/500,this->width()*440/800,this->height()*70/500));
    m_pCloseBtn -> setGeometry(QRect(this -> width() - this->width()*30/800 , 0 , this->width()*30/800,this->height()*30/500));
    m_pMinBtn -> setGeometry(QRect(this -> width() - this->width()*60/800 , 0 , this->width()*30/800,this->height()*30/500));


    // some where is opacity
//    QPainter p(this);
//    p.setCompositionMode( QPainter::CompositionMode_Clear );
//    p.fillRect( 10  , 10 , this -> width() - 20, this -> height() - 20, Qt::SolidPattern );
//    QPainter painter1(this);
//    QColor currentColor = m_startColor;
//    currentColor.setAlpha(m_currentAlpha);
//    painter1.fillRect(QRect(10,10,this->width() - 20 , this -> height() - 20), currentColor);

//    m_currentAlpha -= 255 * m_pTimer->interval() / m_fadeTimes;
//    if (m_currentAlpha <= 0)
//    {
//        m_pTimer->stop();
//        this -> close();
//    }

}

void MainWindow::readyClose()
{
    m_pTimer -> start(200);
}

void MainWindow::changeOpacity()
{
    m_opacity -= 0.1;
    this -> setWindowOpacity(m_opacity);
    if( m_opacity == 0)
    {
        m_pTimer -> stop();
        this -> close();
    }
}

void MainWindow::initConnect()
{

    QObject::connect(m_pMinBtn , SIGNAL(clicked()) , this ,SLOT(showMinimized()));
    QObject::connect(m_pCloseBtn , SIGNAL(clicked()) , this , SLOT(close()));

}









