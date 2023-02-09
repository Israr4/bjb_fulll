#include <ros/ros.h>
#include <fstream>
#include <visualization_msgs/Marker.h>
#include "rosline.h"
#include <cmath>
#include <vector>
#include <memory>


int main( int argc, char** argv )
 {
  
  ros::init(argc, argv, "mathlines");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1000);
  ros::Rate r(30);
  float f = 0.0;

  std::unique_ptr<lane>          l(new lane);

  // std::vector <double> vec_i = l -> get_i_vector();

  // std::vector <double> vec_xx = l -> get_x_vector();
  // std::vector <double> vec_ss = l. get_s_vector();

  // std::ofstream file_out("myfile.txt");
//   for(const auto& s : vec_center_x)           //to write a vector values in file
//   file_out << s << "    x" <<std::endl;
  
//  for(const auto& s : vec_center_y)
//   file_out << s << "    y"<<std::endl;

//  for(const auto& s : vec_i)
//   file_out << s << "    i"<<std::endl;

//  for(const auto& s : vec_xx)
//   file_out << s << "    xx"<<std::endl;
  
  //for center lane
  std::vector <double> vec_center_x = l -> get_center_lane_vecx();
  std::vector <double> vec_center_y = l -> get_center_lane_vecy();

  // for left lanes
  std::vector <double> vec_left_x_4 = l -> get_left_lane_4_vecx();
  std::vector <double> vec_left_y_4 = l -> get_left_lane_4_vecy();

  std::vector <double> vec_left_x_3 = l -> get_left_lane_3_vecx();
  std::vector <double> vec_left_y_3 = l -> get_left_lane_3_vecy();

  std::vector <double> vec_left_x_2 = l -> get_left_lane_2_vecx();
  std::vector <double> vec_left_y_2 = l -> get_left_lane_2_vecy();

  std::vector <double> vec_left_x_1 = l -> get_left_lane_1_vecx();
  std::vector <double> vec_left_y_1 = l -> get_left_lane_1_vecy();

  std::vector <double> vec_left_x_11 = l -> get_left_lane_11_vecx();
  std::vector <double> vec_left_y_11 = l -> get_left_lane_11_vecy();

  std::vector <double> vec_car_left_x_1 = l -> get_car_left_1_vecx();
  std::vector <double> vec_car_left_y_1 = l -> get_car_left_1_vecy();

  std::vector <double> vec_car_left_x_2 = l -> get_car_left_2_vecx();
  std::vector <double> vec_car_left_y_2 = l -> get_car_left_2_vecy();

  std::vector <double> vec_car_left_x_3 = l -> get_car_left_3_vecx();
  std::vector <double> vec_car_left_y_3 = l -> get_car_left_3_vecy();

  // for (int i=0; i < vec_center_x.size(); i++)
  // {
  //   std::cout<<"X = "<<i<<"    "<<vec_center_x.at(i)<<std::endl;
  // }
  // std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  // for (int i=0; i < vec_center_y.size(); i++)
  // { 
  //   std::cout<<"Y = "<<i<<"    "<<vec_center_y.at(i)<<std::endl;
  // }
  // std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;



  // std::vector <double> vec_width_x = l. get_width_vecx();
  // std::vector <double> vec_width_y = l. get_width_vecy();

  // for (int i=0; i < vec_left_x_4.size(); i++)
  // {
  //   std::cout<<"X = "<<i<<"    "<<vec_left_x_4.at(i)<<std::endl;
  // }
  // std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  // for (int i=0; i < vec_left_y_4.size(); i++)
  // { 
  //   std::cout<<"Y = "<<i<<"    "<<vec_left_y_4.at(i)<<std::endl;
  // }
  // std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;




//   for (int i=0; i < vec_left_x_3.size(); i++)
//   {
//     std::cout<<"X = "<<i<<"    "<<vec_left_x_3.at(i)<<std::endl;
//   }
//   std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
//   for (int i=0; i < vec_left_y_3.size(); i++)
//   { 
//     std::cout<<"Y = "<<i<<"    "<<vec_left_y_3.at(i)<<std::endl;
//   }
//   std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;



//   for (int i=0; i < vec_left_x_2.size(); i++)
//   {
//     std::cout<<"X = "<<i<<"    "<<vec_left_x_2.at(i)<<std::endl;
//   }
//   std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
//   for (int i=0; i < vec_left_y_2.size(); i++)
//   { 
//     std::cout<<"Y = "<<i<<"    "<<vec_left_y_2.at(i)<<std::endl;
//   }
//   std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;


// std::cout<<"-----------------------------------------------------------------------"<<std::endl;

//   for (int i=0; i < vec_left_x_1.size(); i++)
//   {
//     std::cout<<"X = "<<i<<"    "<<vec_left_x_1.at(i)<<std::endl;
//   }
//   std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  // for (int i=0; i < vec_left_y_1.size(); i++)
  // { 
  //   std::cout<<"Y = "<<i<<"    "<<vec_left_y_1.at(i)<<std::endl;
  // }
  // std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;

  
std::cout<<vec_center_x.size()<<std::endl;
std::cout<<vec_center_y.size()<<std::endl;
std::cout<<vec_left_x_1.size()<<std::endl;
std::cout<<vec_left_y_1.size()<<std::endl;
std::cout<<vec_left_x_2.size()<<std::endl;
std::cout<<vec_left_y_2.size()<<std::endl;
std::cout<<vec_left_x_3.size()<<std::endl;
std::cout<<vec_left_y_3.size()<<std::endl;
std::cout<<vec_left_x_4.size()<<std::endl;
std::cout<<vec_left_y_4.size()<<std::endl;
std::cout<<vec_left_x_11.size()<<std::endl;
std::cout<<vec_left_y_11.size()<<std::endl;
std::cout<<vec_car_left_x_1.size()<<std::endl;
std::cout<<vec_car_left_y_1.size()<<std::endl;
std::cout<<vec_car_left_x_2.size()<<std::endl;
std::cout<<vec_car_left_y_2.size()<<std::endl;
std::cout<<vec_car_left_x_3.size()<<std::endl;
std::cout<<vec_car_left_y_3.size()<<std::endl;


static int ii = 0;
 while (ros::ok())  //when the ros is running then it show the code in it
  {
    visualization_msgs::Marker centre_lane,left_lane_4,left_lane_3,left_lane_2,left_lane_1,left_lane_11,car_left_1,car_left_2,car_left_3 ;
    car_left_1.header.frame_id =car_left_2.header.frame_id =car_left_3.header.frame_id =left_lane_11.header.frame_id = left_lane_1.header.frame_id = left_lane_2.header.frame_id = left_lane_3.header.frame_id = left_lane_4.header.frame_id = centre_lane.header.frame_id = "my_frame";
    car_left_1.header.stamp    =car_left_2.header.stamp    =car_left_3.header.stamp    =left_lane_11.header.stamp    = left_lane_1.header.stamp    = left_lane_2.header.stamp    = left_lane_3.header.stamp    = left_lane_4.header.stamp    = centre_lane.header.stamp    = ros::Time::now();
    car_left_1.ns              =car_left_2.ns              =car_left_3.ns              =left_lane_11.ns              = left_lane_1.ns              = left_lane_2.ns              = left_lane_3.ns              = left_lane_4.ns              = centre_lane.ns              = "mathlines";


    centre_lane.id   = 0;
    left_lane_1.id   = 1;
    left_lane_2.id   = 2;
    left_lane_3.id   = 3;
    left_lane_4.id   = 4;
    left_lane_11.id  = 5;
    car_left_1.id  = 6;
    car_left_2.id  = 7;
    car_left_3.id  = 8;

    centre_lane.type   = visualization_msgs::Marker  :: LINE_STRIP;
    left_lane_1.type   = visualization_msgs::Marker  :: LINE_STRIP;
    left_lane_2.type   = visualization_msgs::Marker  :: LINE_STRIP;
    left_lane_3.type   = visualization_msgs::Marker  :: LINE_STRIP;
    left_lane_4.type   = visualization_msgs::Marker  :: LINE_STRIP;
    left_lane_11.type  = visualization_msgs::Marker  :: LINE_LIST;
    car_left_1.type    = visualization_msgs::Marker  :: LINE_STRIP;
    car_left_2.type    = visualization_msgs::Marker  :: LINE_STRIP;
    car_left_3.type    = visualization_msgs::Marker  :: LINE_STRIP;

    car_left_1.action = car_left_2.action = car_left_3.action = left_lane_11.action = left_lane_1.action = left_lane_2.action = left_lane_3.action = left_lane_4.action = centre_lane.action = visualization_msgs::Marker::ADD;

    centre_lane.pose.orientation.w  = 1.0;
    left_lane_1.pose.orientation.w  = 1.0;
    left_lane_2.pose.orientation.w  = 1.0;
    left_lane_3.pose.orientation.w  = 1.0;
    left_lane_4.pose.orientation.w  = 1.0;
    left_lane_11.pose.orientation.w  = 1.0;
    car_left_1.pose.orientation.w  = 1.0;
    car_left_2.pose.orientation.w  = 1.0;
    car_left_3.pose.orientation.w  = 1.0;


    // car_left_1.pose.position.x = vec_car_left_x_1[ii];  // to move the car on specific lane
    // car_left_1.pose.position.y = vec_car_left_y_1[ii];
    // car_left_1.pose.position.z = 0;
    // // if(ii>100) //car lane changing
    // // {
    // // car_left_1.pose.position.x = vec_car_left_x_2[ii+5] ;
    // // car_left_1.pose.position.y = vec_car_left_y_2[ii+5] ;
    // // car_left_1.pose.position.z = 0;
    // // }
    // if (ii > vec_car_left_x_1.size())
    // {
    // ii =0;
    // }


  
    // car_left_2.pose.position.x = vec_car_left_x_2[ii] ;
    // car_left_2.pose.position.y = vec_car_left_y_2[ii] ;
    // car_left_2.pose.position.z = 0;
    // if (ii > vec_car_left_x_2.size())
    // {
    // ii =0;
    // }


    // car_left_3.pose.position.x = vec_car_left_x_3[ii] ;
    // car_left_3.pose.position.y = vec_car_left_y_3[ii] ;
    // car_left_3.pose.position.z = 0;
    // if (ii > vec_car_left_x_3.size())
    // {
    // ii =0;
    // }


    centre_lane.scale.x = 0.1;   //width of a line
    centre_lane.scale.y = 0.1;
    centre_lane.scale.z = 0;

    left_lane_4.scale.x = 0.1;   //width of a line
    left_lane_4.scale.y = 0.1;
    left_lane_4.scale.z = 0;

    left_lane_3.scale.x = 0.1;   //width of a line
    left_lane_3.scale.y = 0.1;
    left_lane_3.scale.z = 0;

    left_lane_2.scale.x = 0.1;   //width of a line
    left_lane_2.scale.y = 0.1;
    left_lane_2.scale.z = 0;

    left_lane_1.scale.x = 0.1;   //width of a line
    left_lane_1.scale.y = 0.1;
    left_lane_1.scale.z = 0;

    left_lane_11.scale.x = 1;   //width of a line
    left_lane_11.scale.y = 1;
    left_lane_11.scale.z = 0;

    car_left_1.scale.x = 0.1;   //width of a line
    car_left_1.scale.y = 0.1;
    car_left_1.scale.z = 0;

    car_left_2.scale.x = 0.1;   //width of a line
    car_left_2.scale.y = 0.1;
    car_left_2.scale.z = 0;

    car_left_3.scale.x = 0.1;   //width of a line
    car_left_3.scale.y = 0.1;
    car_left_3.scale.z = 0;

    

    centre_lane.color.a   = 1.0;
    left_lane_4.color.a   = 1.0;
    left_lane_3.color.a   = 1.0;
    left_lane_2.color.a   = 1.0;
    left_lane_1.color.a   = 1.0;
    left_lane_11.color.a  = 1.0;
    car_left_1.color.a  = 1.0;
    car_left_2.color.a  = 1.0;
    car_left_3.color.a  = 1.0;

    centre_lane.color.r = 1.0;
    centre_lane.color.g = 0.0;
    centre_lane.color.b = 0.0;

    left_lane_4.color.r = 1.0;
    left_lane_4.color.g = 1.0;
    left_lane_4.color.b = 1.0;

    left_lane_3.color.r = 0.0;
    left_lane_3.color.g = 0.0;
    left_lane_3.color.b = 1.0;

    left_lane_2.color.r = 0.0;
    left_lane_2.color.g = 1.0;
    left_lane_2.color.b = 1.0;

    left_lane_1.color.r = 0.0;
    left_lane_1.color.g = 1.0;
    left_lane_1.color.b = 0.0;

    left_lane_11.color.r = 0.0;
    left_lane_11.color.g = 1.0;
    left_lane_11.color.b = 1.0;

    car_left_1.color.r = 1.0;
    car_left_1.color.g = 1.0;
    car_left_1.color.b = 1.0;

    car_left_2.color.r = 1.0;
    car_left_2.color.g = 1.0;
    car_left_2.color.b = 1.0;

    car_left_3.color.r = 1.0;
    car_left_3.color.g = 1.0;
    car_left_3.color.b = 1.0;

  
    

    for (double_t i = 0; i<vec_center_x.size() ; i++)
    {
      geometry_msgs::Point p; 
      p.x = vec_center_x.at(i);
      p.y = vec_center_y.at(i);
      p.z = 0.0;
      centre_lane.points.push_back(p);

      geometry_msgs::Point q; 
      q.x = vec_left_x_4.at(i);
      q.y = vec_left_y_4.at(i);
      q.z = 0.0;
      left_lane_4.points.push_back(q);

      geometry_msgs::Point r; 
      r.x = vec_left_x_3.at(i);
      r.y = vec_left_y_3.at(i);
      r.z = 0.0;
      left_lane_3.points.push_back(r);

      geometry_msgs::Point s; 
      s.x = vec_left_x_2.at(i);
      s.y = vec_left_y_2.at(i);
      s.z = 0.0;
      left_lane_2.points.push_back(s);

      geometry_msgs::Point t; 
      t.x = vec_left_x_1.at(i);
      t.y = vec_left_y_1.at(i);
      t.z = 0.0;
      left_lane_1.points.push_back(t);

      geometry_msgs::Point b; 
      b.x = vec_car_left_x_1[i];
      b.y = vec_car_left_y_1[i];
      b.z = 0.0;
      car_left_1.points.push_back(b);

      geometry_msgs::Point d; 
      d.x = vec_car_left_x_2[i];
      d.y = vec_car_left_y_2[i];
      d.z = 0.0;
      car_left_2.points.push_back(d);

       geometry_msgs::Point c; 
      c.x = vec_car_left_x_3[i];
      c.y = vec_car_left_y_3[i];
      c.z = 0.0;
      car_left_3.points.push_back(c);
    }


    for (double_t i = 0; i<vec_left_x_11.size() ; i++)  //only for linelist leftlane11
    {
      geometry_msgs::Point a; 
      a.x = vec_left_x_11.at(i);
      a.y = vec_left_y_11.at(i);
      a.z = 0.0;
      left_lane_11.points.push_back(a);
     }



      marker_pub.publish(centre_lane);
      marker_pub.publish(left_lane_4);
      marker_pub.publish(left_lane_3);
      marker_pub.publish(left_lane_2);
      marker_pub.publish(left_lane_1);
      marker_pub.publish(left_lane_11);    //only for line list11
      marker_pub.publish(car_left_1);
      marker_pub.publish(car_left_2);
      marker_pub.publish(car_left_3);
      r.sleep();
      ii++;
      f += 0.4;
 }
}