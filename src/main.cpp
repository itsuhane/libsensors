#include <cstdio>
#include <array>
#include <opencv2/opencv.hpp>
#include <libsensors.h>

extern "C" {
void on_image(double t, int width, int height, const void *bytes) {
    cv::Mat image = cv::Mat(cv::Size(width, height), CV_8UC1, const_cast<void *>(bytes)).clone();
    // cv::Mat thumb;
    // cv::resize(image, thumb, cv::Size(0, 0), 0.2, 0.2);
    // cv::imshow("image", thumb);
    // cv::waitKey(1);
}

void on_gyroscope(double t, double x, double y, double z) {
}

void on_accelerometer(double t, double x, double y, double z) {
}
}

int main(int argc, const char *argv[]) {
    sensors_image_handler_set(&on_image);
    sensors_gyroscope_handler_set(&on_gyroscope);
    sensors_accelerometer_handler_set(&on_accelerometer);

    sensors_init();
    std::array<unsigned char, 1024 * 1024> buffer;
    while (true) {
        size_t nread = fread(buffer.data(), 1, buffer.size(), stdin);
        if (nread > 0) {
            sensors_parse_data(buffer.data(), nread);
        } else {
            if (feof(stdin) || ferror(stdin)) {
                break;
            }
        }
    }
    sensors_deinit();
    return 0;
}
