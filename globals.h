








#ifndef GLOBALS_H
#define GLOBALS_H


#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <vector>


//#include <QAbstractEventDispatcher>
//#include <QAbstractItemView>
//#include <QAbstractScrollArea>
//#include <QAction>
//#include <QActionEvent>
//#include <QActionGroup>
#include <QApplication>
//#include <QAudio>
//#include <QAudioBuffer>
//#include <QAudioDecoder>
//#include <QAudioDecoderControl>
//#include <QAudioDeviceInfo>
//#include <QAudioEncoderSettings>
//#include <QAudioEncoderSettingsControl>
//#include <QAudioFormat>
//#include <QAudioInput>
//#include <QAudioInputSelectorControl>
//#include <QAudioOutput>
//#include <QAudioOutputSelectorControl>
//#include <QAudioProbe>
//#include <QAudioRecorder>
//#include <QAudioSystemFactoryInterface>
//#include <QAudioSystemPlugin>
//#include <qaudiosystem.h>
#include <QBitArray>
//#include <QBitmap>
#include <QBuffer>
#include <QByteArray>
//#include <QCamera>
//#include <QCameraCaptureBufferFormatControl>
//#include <QCameraCaptureDestinationControl>
//#include <QCameraControl>
//#include <QCameraExposure>
//#include <QCameraExposureControl>
//#include <QCameraFeedbackControl>
//#include <QCameraFlashControl>
//#include <QCameraFocus>
//#include <QCameraFocusControl>
//#include <QCameraFocusZone>
//#include <QCameraFocusZoneList>
//#include <QCameraImageCapture>
//#include <QCameraImageCaptureControl>
//#include <QCameraImageProcessing>
//#include <QCameraImageProcessingControl>
//#include <QCameraLocksControl>
//#include <QCameraViewfinder>
//#include <QCameraViewfinderSettingsControl>
//#include <QCameraZoomControl>
#include <QCheckBox>
#include <QColor>
#include <QCoreApplication>
//#include <QCursor>
#include <QDataStream>
#include <QDebug>
#include <QDesktopWidget>
//#include <QElapsedTimer>
//#include <QEvent>
//#include <QEventLoop>
//#include <QEventLoopLocker>
#include <QDir>
#include <QFile>
#include <QFileDevice>
#include <QFileDialog>
#include <QFileInfo>
//#include <QFlag>
//#include <QFlags>
#include <QFont>
#include <QFontInfo>
#include <QFontMetrics>
#include <QFrame>
//#include <QGraphicsItem>
//#include <QGraphicsPixmapItem>
//#include <QGraphicsBlurEffect>
//#include <QGraphicsColorizeEffect>
//#include <QGraphicsDropShadowEffect>
//#include <QGraphicsEffect>
//#include <QGraphicsGridLayout>
//#include <QGraphicsObject>
//#include <QGraphicsItem>
//#include <QGraphicsItemAnimation>
//#include <QGraphicsLayout>
//#include <QGraphicsLayoutItem>
//#include <QGraphicsLinearLayout>
//#include <QGraphicsProxyWidget>
//#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
//#include <QGraphicsScale>
//#include <QGraphicsScene>
//#include <QGraphicsSceneEvent>
//#include <QGraphicsSceneHoverEvent>
//#include <QGraphicsSceneMouseEvent>
//#include <QGraphicsSceneMoveEvent>
//#include <QGraphicsSimpleTextItem>
//#include <QGraphicsTextItem>
//#include <QGraphicsTransform>
//#include <QGraphicsView>
//#include <QGraphicsWidget>
//#include <QHash>
//#include <QHashIterator>
//#include <QHBoxLayout>
//#include <QIcon>
//#include <QImage>
//#include <QImageIOHandler>
#include <QIODevice>
#include <QLabel>
//#include <QLayout>
//#include <QLayoutItem>
#include <QLine>
#include <QList>
#include <QListWidget>
#include <QListView>
#include <QMainWindow>
//#include <QMediaObject>
//#include <QMediaResource>
//#include <QMediaService>
#include <QMessageBox>
//#include <QMessageLogger>
#include <QMouseEvent>
//#include <QtMultimedia/QMediaPlayer>
//#include <QtMultimedia/QMediaPlaylist>
//#include <QtMultimedia/QMediaObject>
//#include <QtMultimedia/QMediaBindableInterface>
//#include <QtMultimedia/qmediaenumdebug.h>
//#include <QtMultimedia/QMediaContent>
//#include <QtMultimedia/QMediaControl>
//#include <QtMultimedia/QMediaGaplessPlaybackControl>
//#include <QtMultimedia/QMediaMetaData>
//#include <QtMultimedia/QMediaService>
//#include <QtMultimedia/QSoundEffect>
//#include <QtMultimedia/QMediaStreamsControl>
//#include <QtMultimedia/QMediaTimeRange>
//#include <QtMultimedia/QMetaDataReaderControl>
#include <QObject>

//#include <QOpenGLBuffer>
//#include <QOpenGLContext>
//#include <QOpenGLContextGroup>
//#include <QOpenGLDebugLogger>
//#include <QOpenGLDebugMessage>
//#include <QOpenGLFramebufferObject>
//#include <QOpenGLFramebufferObjectFormat>
//#include <QOpenGLFunctions>
//#include <QOpenGLFunctionsPrivate>
//#include <QOpenGLFunctions_ES2>
//#include <QOpenGLPaintDevice>
//#include <QOpenGLShader>
//#include <QOpenGLShaderProgram>
//#include <QOpenGLTimeMonitor>
//#include <QOpenGLTimerQuery>
//#include <QOpenGLVersionFunctions>
//#include <QOpenGLVersionProfile>
//#include <QOpenGLVertexArrayObject>

#include <QPaintDevice>
#include <QPainter>
#include <QPalette>
#include <QPixmap>
#include <QPoint>
#include <QPushButton>
#include <QRadioButton>
#include <QRect>
#include <QRectF>
#include <QRegion>
#include <QResource>
#include <QRgb>
#include <QScreen>
#include <QSlider>
//#include <QSound>
#include <QSpinBox>
//#include <QStackedWidget>
//#include <QStylePainter>
#include <QString>
#include <QStringList>
#include <QStringRef>
//#include <QStyle>
//#include <QStyleFactory>
//#include <QStyleHints>
//#include <QStyleOption>
//#include <QStyleOptionButton>
//#include <QStylePainter>
#include <QTextStream>
#include <QTime>
#include <QTimer>
#include <QTimerEvent>
//#include <QUrl>
//#include <QVariant>
//#include <QVector>
//#include <QVBoxLayout>
//#include <QVideoDeviceSelectorControl>
//#include <QVideoEncoderSettings>
//#include <QVideoEncoderSettingsControl>
//#include <QVideoFrame>
//#include <QVideoProbe>
//#include <QVideoRendererControl>
//#include <QVideoSurfaceFormat>
//#include <QVideoWidget>
//#include <QVideoWidgetControl>
//#include <QVideoWindowControl>
//#include <QWheelEvent>
#include <QWidget>

//#include <QtEndian>

#include <QtCore>
#include <QtGlobal>

#include <QtGui>
//#include <QtOpenGL/QGLBuffer>
//#include <QtOpenGL/QGLColormap>
//#include <QtOpenGL/QGLContext>
//#include <QtOpenGL/QGLFormat>
//#include <QtOpenGL/QGLFramebufferObject>
//#include <QtOpenGL/QGLFramebufferObjectFormat>
//#include <QtOpenGL/QGLFunctions>
//#include <QtOpenGL/QGLFunctionsPrivate>
//#include <QtOpenGL/QGLPixelBuffer>
//#include <QtOpenGL/QGLShader>
//#include <QtOpenGL/QGLWidget>
//#include <QtOpenGL/QtOpenGL>

using std::cout;
using std::cin;
using std::vector;


//Used in diagnostics

void DoDebug ( quint32 t1);

void DoDebug ( quint32 t1, quint32 t2);

void DoDebug ( quint32 t1, quint32 t2, quint32 t3);

void DoDebug ( quint32 t1, quint32 t2, quint32 t3, quint32 t4);



#endif // GLOBALS_H




