#include <iostream>
#include <string>

#include <boost/gil/gil_all.hpp>
#include <boost/gil/extension/io/png_dynamic_io.hpp>
#include <boost/gil/extension/io/jpeg_dynamic_io.hpp>
#include <boost/algorithm/string/predicate.hpp>

#include "boost/filesystem.hpp"

#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

const char ESCAPE = '\033';
const std::string INPUT_LOCATION = "~/toConvert";
const std::string OUTPUT_LOCATION = "~/converted";
const int NUMBER_OF_THREADS = 4;

struct Resolution {
    int x;
    int y;
};

Resolution getResolution();
void printError(std::string text);
void printInfo(std::string text);
void printTitle(std::string text);
void convertion(Resolution resolution);
void convert(std::string filename, Resolution resolution);

int main() {
    printTitle("Da Converter \n");
    printInfo("Converts files in ~/toConvert -> ~/converted \n");

    if (!boost::filesystem::exists(INPUT_LOCATION)) {
        printError("No " + INPUT_LOCATION);
        return 1;
    }

    Resolution resolution = getResolution();
    convertion(resolution);
}


Resolution getResolution() {
    Resolution resolution;
    std::cout << "Enter x res \n";
    std::cin >> resolution.x;
    std::cout << "Enter y res \n";
    std::cin >> resolution.y;
    return resolution;
}


void printTitle(std::string text) {
    std::cout << ESCAPE + "[7;30m" + text + ESCAPE + "[0;30m";
}

void printError(std::string text) {
    std::cout << ESCAPE + "[1;31m" + text + ESCAPE + "[0;31m";
}

void printInfo(std::string text) {
    std::cout << ESCAPE + "[1;33m" + text + ESCAPE + "[0;33m";
}


// FIXME, might be nice to move convert code to own file convert.h
void convertion(Resolution resolution) {
    boost::asio::io_service ioService;
    boost::thread_group threadpool;

    boost::asio::io_service::work work(ioService);
    for(int i = 0; i != NUMBER_OF_THREADS; i++) {
        threadpool.create_thread(
            boost::bind(&boost::asio::io_service::run, &ioService)
        );
    }


    boost::filesystem::directory_iterator end_itr;
    for (boost::filesystem::directory_iterator itr(INPUT_LOCATION); itr != end_itr; ++itr ) {
        std::string name = itr->path().filename;
        ioService.post(boost::bind(convert, name, resolution));
    }

    ioService.stop();

    threadpool.join_all();
}

void convert(std::string filename, Resolution resolution) {
    boost::gil::rgba32_image_t toConvert;
    boost::gil::rgba32_image_t converted(resolution.x, resolution.y);
    
    if (boost::algorithm::ends_with(filename, ".png")) {
        boost::gil::png_read_and_convert_image(filename, toConvert);
    } else if (boost::algorithm::ends_with(filename, ".jpeg")) {
        boost::gil::jpeg_read_and_convert_image(filename, toConvert);
    } else {
        printError("unsupported, call Laurie: " + filename);
    }

    for(int i = 0; i != resolution.y; i++) {
       for(int i = 0; i != resolution.x; i++) { 
           boost::gil::rgba32_pixel_t pixel;
       }
    } 
    
    png_write_view(OUTPUT_LOCATION + "/" + filename, const_view(converted));
}