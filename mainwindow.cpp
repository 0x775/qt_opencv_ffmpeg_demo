#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/opencv.hpp"
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
    #include <libavfilter/buffersink.h>
    #include <libavfilter/buffersrc.h>
    #include <libavutil/avutil.h>
    #include <libavutil/imgutils.h>
    #include <libavutil/pixfmt.h>
    #include <libswresample/swresample.h>
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //test. opencv
    cv::Mat bgr = cv::imread("D:/a.png");
    cv::Mat image;
    cv::cvtColor(bgr, image, cv::COLOR_BGR2RGB);
    QImage img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    img = img.scaled(QSize(800, 600), Qt::KeepAspectRatio);
    QPixmap mp;
    mp=mp.fromImage(img);
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    label->setPixmap(mp);
    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->addWidget(label);
    ui->centralwidget->setLayout(vlayout);

    this->setWindowTitle("OpenCV4.8 + Qt5 Demo");

    //test.ffmpeg
    // 初始化libavformat并获取FFmpeg版本
    // ++++ 旧版本的ffmpeg程序, 程序开头处, 一般总是av_register_all. 4.x之后, 该函数已经废弃,不需要调用了
    //av_register_all();

    int ffmpegVersion = avformat_version();

        // 打印FFmpeg的版本
    //qDebug() << "FFmpeg version: " << QString::number(LIBAVCODEC_VERSION) << ")";
   qDebug() << "FFmpeg version: " << QString::number(ffmpegVersion) << ")";

   // 获取FFmpeg库的版本信息
       const char *version = av_version_info();
       // 打印版本信息
       std::cout << "FFmpeg version: " << version << std::endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

