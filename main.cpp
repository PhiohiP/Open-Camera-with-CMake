#include <iostream>
#include <opencv2/opencv.hpp>

int main() {

    // Buka kamera
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Error: Unable to open camera!" << std::endl;
        return -1;
    }

    // Loop untuk menangkap dan menampilkan frame
    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cv::imshow("Video Stream", frame);

        // Hentikan loop jika tombol 'q' ditekan
        if (cv::waitKey(30) == 'q') break;
    }

    // Tutup kamera dan jendela tampilan
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
