#include "titlewin.h"

QPoint sec[4] = {QPoint(0, 10), QPoint(3, 0), QPoint(0, -90), QPoint(-3, 0)};
QPoint min[4] = {QPoint(0, 8), QPoint(5, 0), QPoint(0, -70), QPoint(-5, 0)};
QPoint hour[4] = {QPoint(0, 6), QPoint(7, 0), QPoint(0, -50), QPoint(-7, 0)};


CTitleWin::CTitleWin(QWidget *parent)
    : QMainWindow(parent),
      m_pParent(parent)
{
    initWidget();

    m_pClock = new QTimer(this);
    QObject::connect(m_pClock , SIGNAL(timeout()), this , SLOT(update()));
    m_pClock -> start(1000);
}

CTitleWin::~CTitleWin()
{

}

void CTitleWin::initWidget()
{
    this -> setStyleSheet("background-color:rgb(255,255,255);");

    m_pTimeLabel = new QLabel(this);
    QFont font( "Times", this->width()*13/1100, QFont::Fantasy);
    m_pTimeLabel -> setFont(font);
    m_pTimeLabel -> setAlignment(Qt::AlignCenter);
    m_pTimeLabel -> show();

    m_pTitleLabel = new QLabel(this);
    m_pTitleLabel -> setFont(font);
    m_pTitleLabel -> setAlignment(Qt::AlignCenter);
    m_pTitleLabel -> show();


}

void CTitleWin::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    //painter.translate(100, 100);



    painter.setWindow(-(this->height()*100.0/74.4),
                      -(this->height()*100.0/74.4),
                      this -> width()*2000/750,
                      this -> height()*200.0/74.4);

    // 绘制大刻度
    // 每次坐标旋转画完就入栈，不影响下一次坐标旋转
    painter.save(); //save() 与 restore() 必须是一一对应的
    for (int i = 0; i < 60 ; ++i)
    {
       painter.rotate(6);  //rotate()是顺时针旋转坐标轴
       if (i % 5 == 4)
       {
           painter.setPen(QPen(Qt::black, 5));
           painter.drawLine(QLineF(0, -90, 0, -100));
       }
       else
       {
           painter.setPen(QPen(Qt::black, 1));
           painter.drawLine(QLineF(0, -95, 0, -100));
       }
    }
    painter.restore();

    int s = QTime::currentTime().second();
    int m = QTime::currentTime().minute();
    int h = QTime::currentTime().hour();


    m_pTimeLabel -> setText(QTime::currentTime().toString());
    m_pTimeLabel -> setGeometry(QRect(this->width()*80/800,
                                      this->height()*60/500,
                                      this->width()*60/800,
                                      this->height()*20/500));

    m_pTitleLabel -> setGeometry(QRect(this->width()/2 - m_pTitleLabel -> width()/2,
                                      this->height()*60/500,
                                      this->width()*60/800,
                                      this->height()*20/500));
    //painter.drawText(-20, 50, QTime::currentTime().toString());

    painter.save();
    painter.rotate(((h % 12) +  static_cast<double>(m / 60.0)) * 30);
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::blue);
    painter.drawConvexPolygon(hour, 4);
    painter.restore();

    painter.save();
    painter.rotate(m * 6);
    painter.setBrush(Qt::green);
    painter.setPen(Qt::green);
    painter.drawConvexPolygon(min, 4);
    painter.restore();

    painter.save();
    painter.rotate(s * 6);
    painter.setBrush(Qt::red);
    painter.setPen(Qt::red);
    painter.drawConvexPolygon(sec, 4);
    painter.restore();
}
//void CTitleWin::callBack(QMainWindow *win , int width , int height)
//{
//    m_pParent = win;
//    m_width = width;
//    m_height = height;
//}
