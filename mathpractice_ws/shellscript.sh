#!/bin/sh

#shell script to run that code when we click on any button in flask created object
mkdir -p ~/mathpractcice_new_ws/src
source /opt/ros/noetic/setup.bash
cd ..
# sudo cp -r ~/mathpractice_ws 
cd ~/mathpractcice_new_ws/
catkin_make
catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3
# source devel/setup.bash
ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:~/mathpractcice_new_ws/
echo $ROS_PACKAGE_PATH

cd src
roscreate-pkg mathpractice roscpp visualization_msgs

cd mathpractice
rm -rf include 
rm -rf CMakeLists.txt

CMAKE_PATH=$PWD
cd src/
C_CODE_PATH=$PWD
echo ${C_CODE_PATH}

cd ../../..
pwd
cd ..

cd mathpractice_ws/src/mathpractice
cp CMakeLists.txt ${CMAKE_PATH}
cd src

cp bjb_sangjani_full.xodr ${C_CODE_PATH}
cp mathline.cpp ${C_CODE_PATH}
cp rosline.cpp ${C_CODE_PATH}
cp rosline.h ${C_CODE_PATH}
cd ../../../..
pwd





cd mathpractcice_new_ws
source devel/setup.bash

catkin_make 

rosmake mathpractice 

roscore &


cd devel/lib/mathpractice/
./mathlines &


sleep 1m 50s
rviz riviz -f my_frame





