#include <iostream>
 #include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    // The two kernels — do not change these
    cv::Mat K1 = (cv::Mat_<double>(3, 3) <<
         1,  2,  1,
         0,  0,  0,
        -1, -2, -1
    );

    cv::Mat K2 = (cv::Mat_<double>(3, 3) <<
         1,  0, -1,
         2,  0, -2,
         1,  0, -1
    );
    
    
    
    cv::Mat img = cv::imread("./assets/hogwarts.png", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "Could not load image at ./assets/hogwarts.png\n";
        return -1;
    }

    cv::Mat output;
    cv::namedWindow("filter 2D output", cv::WINDOW_NORMAL);


    // using the built-in function
    cv::filter2D(img, output, -1, K1*K2, cv::Point(-1, -1), 5.0, cv::BorderTypes::BORDER_REPLICATE);
    
    cv::imshow("filter 2D output", output);
    cv::waitKey(0);
    
    cout <<"9 multiplications per pixel is required by our approach"<<endl;
    

    cv::Mat img_f;
    img.convertTo(img_f, CV_64FC1);

    // TODO: apply K1 and K2 to img_f with as few multiplications per pixel as possible.
    // Print the number of multiplications your approach uses per pixel.

    return 0;
}