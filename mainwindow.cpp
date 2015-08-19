#include "mainwindow.h"


//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32

//========== class MainWindow ==========

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //Initialize the taps
    tapsArray[0] = 32;
    tapsArray[1] = 31;
    tapsArray[2] = 30;
    tapsArray[3] = 29;

    //----------

    for (int i=0; i<4; i++){
        lastTaps[i] = 0;
        lastLastTaps[i] = 0;
    }//for

    //----------

    //Not running yet
    started = false;

    //Turn on the master
    masterSw = true;

    //Not finished yet
    finished = false;

    counter = 0;

    theNumber = INITIALSTATE;

    //Max sequence length
    two_pow32_minus1 = (quint32) qPow(2, 32)-1;

    qDebug()<< "Maximal:  " << two_pow32_minus1;

    //Size and center the main window
    sizeAndCenterWidget (this, WINWIDTH, WINHEIGHT);

    //Create a start button
    startButt = new QPushButton("Start", this);
    startButt->setGeometry ((WINWIDTH - 90)/2, (WINHEIGHT - 80), 90, 25);
    startButt->setVisible(true);
    connect (startButt, SIGNAL(clicked()), this, SLOT (startButtClicked()));

    //Create a stop button
    stopButt = new QPushButton("Stop", this);
    stopButt->setGeometry ((WINWIDTH - 150), (WINHEIGHT - 80), 90, 25);
    stopButt->setVisible(false);
    connect (stopButt, SIGNAL(clicked()), this, SLOT (stopButtClicked()));

    //Create a resume button
    resumeButt = new QPushButton("Resume", this);
    resumeButt->setGeometry ((WINWIDTH - 150), (WINHEIGHT - 80), 90, 25);
    resumeButt->setVisible(false);
    connect (resumeButt, SIGNAL(clicked()), this, SLOT (resumeButtClicked()));

    //Create a save button
    saveButt = new QPushButton("Save", this);
    saveButt->setGeometry ((WINWIDTH - 150), (WINHEIGHT - 160), 90, 25);
    saveButt->setVisible(false);
    connect (saveButt, SIGNAL(clicked()), this, SLOT (saveButtClicked()));

    //Colors for the tap boxes display
    useColor = QColor(155, 220, 155, 255);

    isMaximal  = false;
    savingBool = false;
    drawBool   = false;
    noMaximals = false;

    //List holds maximals
    maximalsList = NULL;


}//Constructor

//---------- Destructor ----------

MainWindow::~MainWindow()
{

}



//---------- MainWindow paintEvent loop ----------

void MainWindow :: paintEvent(QPaintEvent*) {

    //Do stuff only if started
    if (started){

        QPainter* painter = new QPainter(this);

        drawTheBoxes(painter);

        //----------

        quint32 loopCounter = 0;

        bool stay;
        if (masterSw)
            stay = true;
        else
            stay = false;

        while (stay) {

            shiftTheRegister();

            // End of the sequence
            if (theNumber == INITIALSTATE) {

                // If maximal length sequence
                if (counter >= two_pow32_minus1) {

                    qDebug() << "";
                    qDebug() << "Maximal";
                    qDebug()  << tapsArray[3]<<" "<<tapsArray[2]<<" "<<tapsArray[1]
                                                <<" "<<tapsArray[0] << "    " << counter;
                    stay = false;

                    //Save the maximal taps
                    appendAMaximal(tapsArray);

                    isMaximal = true;

                    drawTheBoxes(painter);

                    painter->drawText(60,205,"         ");
                    painter->drawText(60,205,"Maximal");

                    moveToNextTagConfig(painter);  //Go to next configuratioin

                } else {
                    isMaximal = false;

                    qDebug() << "";
                    qDebug()  << tapsArray[3]<<" "<<tapsArray[2]<<" "<<tapsArray[1]
                                                <<" "<<tapsArray[0] << "    " << counter;

                    moveToNextTagConfig(painter);   //Go to next configuration

                }//else

                stay = false;                       //Kick out of the loop
            }//if

            loopCounter++;
            if (loopCounter > LOOPCOUNT){           // LOOPCOUNT passes..
                stay = false;                       // On to other stuff
            }//if
        }//while

        //Set the font
        QFont f = this->font();
        f.setPointSize(12);
        painter->setFont(f);

        quint64 dc = (quint64) counter / 1000;
        dc = 1000 * dc;
        QString s = QString::number(dc);
        painter->drawText(60, 160, s);

        //----------

        if ((started) && (!masterSw) && (!finished)){
            painter->drawText(60,(WINHEIGHT - 60), "Stopped");
        } else {
            painter->drawText(60,(WINHEIGHT - 60), "          ");
        }//else

        //----------

        //Finished
        if (finished){
            painter->drawText(60,(WINHEIGHT - 60), "          ");
            painter->drawText(60,(WINHEIGHT - 60), "Finished    ");
            stopButt->setVisible(false);
            saveButt->setVisible(true);
        }//if

        //----------

        if ((drawBool) && (lastTaps[3] > 0)){

            QFont f = this->font();
            f.setPointSize(12);
            painter->setFont(f);

            //Draw last taps
            QString s0 = QString::number(lastTaps[0]);
            QString s1 = QString::number(lastTaps[1]);
            QString s2 = QString::number(lastTaps[2]);
            QString s3 = QString::number(lastTaps[3]);

            QString s = s3+"   "+s2+"   "+s1+"   "+s0+"      " + QString::number(lastCount);

            if (lastIsMaximal)
                s.append("   Maximal");

            painter->drawText(60, (WINHEIGHT - 260), s);
        }//if

        //----------

        if ((drawBool) && (lastLastTaps[3] > 0)){

            //Draw last last taps
            QString ss0 = QString::number(lastLastTaps[0]);
            QString ss1 = QString::number(lastLastTaps[1]);
            QString ss2 = QString::number(lastLastTaps[2]);
            QString ss3 = QString::number(lastLastTaps[3]);

            QString ss = ss3+"   "+ss2+"   "+ss1+"   "+ss0+"      " + QString::number(lastLastCount);

            if (lastLastIsMaximal)
                ss.append("   Maximal");

            painter->drawText(60, (WINHEIGHT - 220), ss);

        }//if

        //----------

        if (noMaximals){
            painter->drawText(60, (WINHEIGHT - 180), "There are no Maximals to save.");
        }//if

    }//if started

    if (!savingBool)
        this->update();   //Generates loop
}//paintEvent


//---------- shiftTheRegister ----------

void MainWindow :: shiftTheRegister() {

    quint32     sh1, sh2, sh3;
    quint32     bit;

    sh1 = 32 - tapsArray[1];
    sh2 = 32 - tapsArray[2];
    sh3 = 32 - tapsArray[3];

    bit = (((theNumber ^ (theNumber >> sh1)) ^ (theNumber >> sh2)) ^(theNumber >> sh3)) & 1;

    theNumber = (theNumber >> 1) | (bit << 31);

    //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32

    counter++;
}//shiftTheRegister


//---------- moveToNextTagConfig ---------

void MainWindow :: moveToNextTagConfig(QPainter* painter) {

    for (int i=0; i<4; i++){
        lastLastTaps[i] = lastTaps[i];
    }//for

    lastLastCount = lastCount;
    lastLastIsMaximal = lastIsMaximal;

    //----------

    for (int i=0; i<4; i++){
        lastTaps[i] = tapsArray[i];
    }//for

    lastCount = counter;
    lastIsMaximal = isMaximal;

    counter = 0;    //Reset the counter

    //----------

    theNumber = INITIALSTATE; //Reset the number

    //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32

    quint32 dex1, dex2, dex3;

    dex3 = tapsArray[3] - 1;                // Scoot [3] to left

    if (dex3 == 0) {                        // Tap [3] has bumped into left end..

        dex2 = tapsArray[2] - 1;            // Will need to move tap [2] to left

        if (dex2 == 1) {                    // Tap [2] has bumped into left limit ..

            dex1 = tapsArray[1] -1;         // Move tap [1] to left

            if (dex1 == 2) {                // Tap [1] has bumped into left stop

                masterSw = false;           // All done
                finished = true;

            } else {                        // ..else tap [1] ok
                tapsArray[1] = dex1;        // Move tap [1]..
                tapsArray[2] = dex1 -1;     // ..and adjust tap [2]..
                tapsArray[3] = dex1 - 2;    // ..and tap3
            }//else

        } else {                            // ..else tap [2] ok
            tapsArray[2] = dex2;            // Move tap [2]..
            tapsArray[3] = dex2 - 1;        // ..and adjust tap [3]
        }//else

    } else {                                // ..else tap [3] ok
        tapsArray[3] = dex3;                // Move it to new location
    }//else

    //----------

    drawBool = true;

}//moveToNextTagConfig


//---------- drawTheBoxes ---------

void MainWindow :: drawTheBoxes(QPainter* painter) {

    int border = 60;
    int barWidth = WINWIDTH - 2 * border;
    int theRectWidth = barWidth / 32;

    int x = border;
    int y = 60;
    QRect zRect;
    QRect dRect;

    for (int i=0; i<32; i++){
        zRect = QRect(x, y, theRectWidth, 20);
        painter->drawRect(zRect);
        x = x + theRectWidth;

        for (int j=0; j<4; j++){
            if ((i+1) == tapsArray[j]) {
                dRect = QRect(zRect.x()+1, zRect.y()+1, theRectWidth-1, 19);
                painter->fillRect(dRect, useColor);
            }//if
        }//for j
    }//for i

    //Draw current taps
    QString s0 = QString::number(tapsArray[0]);
    QString s1 = QString::number(tapsArray[1]);
    QString s2 = QString::number(tapsArray[2]);
    QString s3 = QString::number(tapsArray[3]);

    QFont f = this->font();
    f.setPointSize(12);
    painter->setFont(f);

    QString s = s3 + "   " + s2 + "   " + s1 + "   " +s0;
    painter->drawText(60, 120, s);

}//drawTheBoxes






void MainWindow :: appendAMaximal(quint32 theTaps[4]){

    if (maximalsList == NULL){      //If first entry in list

        maximalsList = new MaxTaps(this);

        maximalsList->maxray[0] = theTaps[0];
        maximalsList->maxray[1] = theTaps[1];
        maximalsList->maxray[2] = theTaps[2];
        maximalsList->maxray[3] = theTaps[3];

        MaxTaps :: num++;

    } else {  //Else, not first entry in list

        MaxTaps* ztaps = maximalsList;          // First entry in list

        while (ztaps->nextTaps != NULL){        // Go to end of list
            ztaps = ztaps->nextTaps;
        }//while

        ztaps->nextTaps = new MaxTaps(this);    // Append entry to list..
        MaxTaps :: num++;                       // ..count it and..

        ztaps->nextTaps->maxray[0] = theTaps[0]; //..load the data
        ztaps->nextTaps->maxray[1] = theTaps[1];
        ztaps->nextTaps->maxray[2] = theTaps[2];
        ztaps->nextTaps->maxray[3] = theTaps[3];

    }//else

}//appendAMaximal


//---------- sizeAndCenterWidget ---------

void MainWindow :: sizeAndCenterWidget (QWidget* widget, int width, int height) {
    int x,y;
    int screenWidth;
    int screenHeight;

    QDesktopWidget* desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - width)/2;
    y = (screenHeight - height)/2;

    widget->setGeometry (x, y, width, height);
    widget->setFixedSize(width, height);
}//sizeAndCenterWidget


//---------------  SLOT startButtClicked  ---------------

void MainWindow :: startButtClicked(){
    started = true;
    startButt->setVisible(false);
    stopButt->setVisible(true);
    qDebug()<<"Start";
}//startButtClicked


//---------------  SLOT stopButtClicked  ---------------

void MainWindow :: stopButtClicked(){
    masterSw = false;
    stopButt->setVisible(false);
    resumeButt->setVisible(true);

    if (MaxTaps::num > 0)
        saveButt->setVisible(true);

    qDebug()<<"Stopped";
}//stopButtClicked


//---------------  SLOT resumeButtClicked  ---------------

void MainWindow :: resumeButtClicked(){
    masterSw = true;
    stopButt->setVisible(true);
    resumeButt->setVisible(false);
    saveButt->setVisible(false);
    savingBool = false;
    qDebug()<<"Resume";
}//resumeButtClicked


//---------------  SLOT saveButtClicked  ---------------

void MainWindow :: saveButtClicked(){

    quint32  tapsPad[4];
    MaxTaps* myTaps;
    int      len;

    if (MaxTaps :: num == 0) {
        qDebug()<<"No Maximals to Save.";
        noMaximals = true;
        return;
    } else {
        noMaximals = false;
    }//else

    savingBool = true;

    //Clear the string
    len = maximalsStr.length();
    maximalsStr.remove(0,len);

    maximalsStr.append("Shift Right \n\n");

    myTaps = maximalsList;

    //Go thru the list for right shift
    bool stay = true;
    while (stay) {

        //Get a copy of the taps
        tapsPad[0] = myTaps->maxray[0];
        tapsPad[1] = myTaps->maxray[1];
        tapsPad[2] = myTaps->maxray[2];
        tapsPad[3] = myTaps->maxray[3];

        //Append taps to maximalsStr
        for (int i=3; i>=0; i--) {
            QString s = QString::number(tapsPad[i]) + "   ";
            maximalsStr.append(s);
        }//for

        qDebug() << "";
        qDebug() << maximalsStr;

        //Double space
        maximalsStr.append("\n\n");

        myTaps = myTaps->nextTaps;

        if (myTaps == NULL)
            stay = false;
    }//while

    //----------

    maximalsStr.append("\n\n\nShift Left \n\n");

    myTaps = maximalsList;

    //Go thru the list for left shift
    stay = true;
    while (stay) {

        //Get a copy of the taps & convert
        tapsPad[0] = 32 - myTaps->maxray[0] + 1;
        tapsPad[1] = 32 - myTaps->maxray[1] + 1;
        tapsPad[2] = 32 - myTaps->maxray[2] + 1 ;
        tapsPad[3] = 32 - myTaps->maxray[3] + 1;

        //Append taps to maximalsStr
        for (int i=3; i>=0; i--) {
            QString s = QString::number(tapsPad[i]) + "   ";
            maximalsStr.append(s);
        }//for

        qDebug() << "";
        qDebug() << maximalsStr;

        //Double space
        maximalsStr.append("\n\n");

        myTaps = myTaps->nextTaps;

        if (myTaps == NULL)
            stay = false;
    }//while

    //----------

    //Returns full path
    QString fn = QFileDialog::getSaveFileName(this);

    if (fn.isEmpty()) return;

    fn.append(".txt");

    QFile file(fn);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << maximalsStr;
    file.close();

    qDebug()<<"Save";
}//saveButtClicked



//========== class MaxTaps ==========

MaxTaps :: MaxTaps(QObject *parent) : QObject(parent){

    nextTaps = NULL;

}//Constructor

//---------- Destructor ----------

MaxTaps :: ~MaxTaps() {

}//Destructor

