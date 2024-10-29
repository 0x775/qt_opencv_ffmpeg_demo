#ifndef FFMPEGWARPER_H
#define FFMPEGWARPER_H
#include <iostream>

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


class FFMpegWarper
{
public:
    FFMpegWarper();
    ~FFMpegWarper();

    //加载文件
    int LoadFile(const char* filePath);

    //截取视频部分
    void CutFragment();
    //提取声音
    //去除声音
    //增加图片贴纸
    //增加字幕
    //视频写字
    //合并视频

};

#endif // FFMPEGWARPER_H
