#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#ifndef GLOBALS_H
#include"globals.h"
#endif


static int      WINWIDTH   = 700;
static int      WINHEIGHT  = 500;

static int      LOOPCOUNT = 1000000;

//Arbitrary value
static quint32  INITIALSTATE = 0x0A1B2C3D;

class MaxTaps;


// This program creates a list of 4 taps which produce a maximal length
// output for a 32-bit linear feedback shift register.  The results are
// saved in a text file.


// Fromhttps://en.wikipedia.org/wiki/Linear_feedback_shift_register:

// The LFSR is maximal-length if and only if the corresponding feedback polynomial is primitive.
// This means that the following conditions are necessary (but not sufficient):

// 1. The number of taps should be even.

// 2. The set of taps – taken all together, not pairwise (i.e. as pairs of elements) – must be
// relatively prime. In other words, there must be no divisor other than 1 common to all taps.


// The taps are labeled for 1 to 32
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32


// Since tap 32 is present in all 4-tap constructs, and it is pow(2,5), the only condition
// which is exempt from the "relatively prime" condition is if all 4 taps are even.  If there
// is one or more of the taps which are odd, then the configuration POSSIBLY produces a
// maximal output.


//========== class MainWindow ==========

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void    sizeAndCenterWidget (QWidget* widget, int width, int height);

    void    paintEvent(QPaintEvent*);

    void    shiftTheRegister();

    void    moveToNextTagConfig(QPainter* p);

    void    drawTheBoxes(QPainter* p);

    void    appendAMaximal(quint32 theTaps[4]);



    bool    started;

    bool    masterSw;

    bool    finished;

    quint32 theNumber;

    quint32 tapsArray[4];

    QPushButton* startButt;

    QPushButton* stopButt;

    QPushButton* resumeButt;

    QPushButton* saveButt;

    quint64 counter;

    quint32 two_pow32_minus1;

    QColor boxColor, maxColor, useColor;

    quint32 lastTaps[4];
    quint32 lastCount;
    bool    lastIsMaximal;

    quint32 lastLastTaps[4];
    quint32 lastLastCount;
    bool    lastLastIsMaximal;

    bool    isMaximal;
    bool    savingBool;
    bool    drawBool;
    bool    noMaximals;

    MaxTaps* maximalsList = NULL;

    QString  maximalsStr = "\n";

private slots:
    void startButtClicked();

    void stopButtClicked();

    void resumeButtClicked();

    void saveButtClicked();
};


//========== class MaxTaps ==========

class MaxTaps : public QObject
{
    Q_OBJECT

public:
    MaxTaps(QObject *parent = 0);
    ~MaxTaps();

    MaxTaps* nextTaps;

    quint32 maxray[4];

    static int  num;
};






#endif // MAINWINDOW_H
