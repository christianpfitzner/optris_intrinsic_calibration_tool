/*
 * RGBCamera.cpp
 *
 *  Created on: 27.10.2014
 *      Author: chris
 */

#include <sensors/RGBCamera.h>

#include "opencv2/highgui/highgui.hpp"

RGBCamera::RGBCamera(const unsigned int id)
:  _camera(new cv::VideoCapture(id)),
   _invert(false)
{

}

RGBCamera::~RGBCamera()
{
   // nothing to do
}


void RGBCamera::grab(void)
{
   if (!_camera->isOpened()){
      std::cout  << "Cannot open the video file" << std::endl;
      return;
   }

   _camera->read(_image);

   cv::Mat viewGray;
   cvtColor(     _image, _bin, cv::COLOR_BGR2GRAY);

   if(_invert) _bin =  cv::Scalar::all(255) - _bin;
}
