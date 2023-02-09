#!/bin/sh

catkin_make

rosmake mathpractice

roscore &

cd devel/lib/mathpractice/ 
./mathlines &

rviz riviz 