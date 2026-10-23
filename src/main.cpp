#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

int main(int argc, char** argv) {
    std::string videoPath = "/mnt/c/Users/f1906/test_2/data/test_videos/装甲板视频.avi";
    
    cv::VideoCapture cap(videoPath);
    std::string outDir = "/mnt/c/Users/f1906/test_2/output";
    std::filesystem::create_directories(outDir);

    cv::Mat frame, gray, binary, binaryBGR;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    int frameCount = 0;

    while (cap.read(frame)) {
        frameCount++;

        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY);

        std::string binaryPath = outDir + "/binary_" + std::to_string(frameCount) + ".jpg";
        bool ok = cv::imwrite(binaryPath, binary);

        cv::cvtColor(binary, binaryBGR, cv::COLOR_GRAY2BGR);

        cv::Mat display;
        cv::hconcat(frame, binaryBGR, display);

        std::string framePath = outDir + "/frame_" + std::to_string(frameCount) + ".jpg";
        bool ok2 = cv::imwrite(framePath, display);
        std::cout << "frame " << frameCount << ": " << (ok2 ? "OK" : "FAIL") << std::endl;

        cv::imshow("Step 1: Binary", display);
        if (cv::waitKey(1) == 27) break;
    }
    cap.release();
    cv::destroyAllWindows();
    return 0;
}
