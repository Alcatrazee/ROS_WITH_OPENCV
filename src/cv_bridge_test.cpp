#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/Image.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

cv_bridge::CvImagePtr cv_ptr1, cv_ptr2, cv_ptr3;
void cam1_call_back(const sensor_msgs::ImageConstPtr &msg)
{
  try
  {
    cv_ptr1 = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);
    cv::imshow("cam1", cv_ptr1->image);
    cv::waitKey(10);
  }
  catch (cv_bridge::Exception &e)
  {
    ROS_ERROR("shit happened");
    return;
  }
}
void cam2_call_back(const sensor_msgs::ImageConstPtr &msg)
{
  try
  {
    cv_ptr2 = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);
    cv::imshow("cam2", cv_ptr2->image);
    cv::waitKey(10);
  }
  catch (cv_bridge::Exception &e)
  {
    ROS_ERROR("shit happened");
    return;
  }
}

void cam3_call_back(const sensor_msgs::ImageConstPtr &msg)
{
  try
  {
    cv_ptr3 = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);
    cv::imshow("cam3", cv_ptr3->image);
    cv::waitKey(10);
  }
  catch (cv_bridge::Exception &e)
  {
    ROS_ERROR("shit happened");
    return;
  }
}

void process(void)
{
  // TODO:process these three images
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_converter");
  ros::NodeHandle nh;

  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub1 = it.subscribe("/cam1/camera/image_raw", 1, cam1_call_back);
  image_transport::Subscriber sub2 = it.subscribe("/cam2/camera/image_raw", 1, cam2_call_back);
  image_transport::Subscriber sub3 = it.subscribe("/cam_middle/camera/image_raw", 1, cam3_call_back);
  while (ros::ok())
  {
    ros::spinOnce();
    process();
  }

  return 0;
}