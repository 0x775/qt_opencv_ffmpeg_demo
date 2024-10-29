#include "ffmpegwarper.h"

FFMpegWarper::FFMpegWarper(){

}

int FFMpegWarper::LoadFile(const char *filePath){
    AVFormatContext *formatContext = nullptr;
    if (avformat_open_input(&formatContext, filePath, nullptr, nullptr) != 0) {
            std::cerr << "无法打开视频文件" << std::endl;
            return -1;
    }

}
