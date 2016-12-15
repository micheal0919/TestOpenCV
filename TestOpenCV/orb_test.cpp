#include <Windows.h>  
#include <string>
#include <vector>
#include <exception>

#include <glog/logging.h>
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

TEST(orb, opencv)
{
	try
	{
		std::string img_path = "../data/images/000000.jpg";
		cv::Mat img = cv::imread(img_path, cv::IMREAD_COLOR);
		//cv::namedWindow("TestWin", cv::WINDOW_AUTOSIZE);
		//cv::imshow("TestWin", img);
		//cv::waitKey();
		LOG(INFO);

		//cv::Ptr<cv::AKAZE> akaze = cv::AKAZE::create();
		//std::vector<cv::KeyPoint> kpts;
		//cv::Mat desc;
		//akaze->detectAndCompute(img, cv::noArray(), kpts, desc);
		//LOG(INFO);

		//	cv::Ptr<cv::ORB> orb = cv::ORB::create(10000);

		cv::Ptr<cv::ORB> orb = cv::ORB::create(1000);


		//orb->setMaxFeatures(1000);
		//orb->setScaleFactor(1.2);
		//orb->setNLevels(8);
		//orb->setEdgeThreshold(31);
		//orb->setFirstLevel(0);
		//orb->setWTA_K(2);
		//orb->setScoreType(cv::ORB::HARRIS_SCORE);
		//orb->setPatchSize(32);

		std::vector<cv::KeyPoint> kpts;
		cv::Mat desc;
		orb->detectAndCompute(img, cv::noArray(), kpts, desc);
		//orb_detector->detect(img, kpts);
		LOG(INFO) << "the num of key points is " << kpts.size();

		cv::Mat img_kpts;
		cv::drawKeypoints(img, kpts, img_kpts, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);
		cv::namedWindow("TestWin", cv::WINDOW_AUTOSIZE);
		cv::imshow("TestWin", img_kpts);
		cv::waitKey();
	}
	catch (int e)
	{
		LOG(ERROR) << "Executing SEH __except block\r\n";
	}

	LOG(INFO) << "Endding of ORB_test opencv";
}
