#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "rapidxml.hpp"
#include <cmath>
#include <array>

using namespace rapidxml;

class lane
{
        public:
        double width;
        double ds;
        double x_point_generator;
        double y_point_generator;  

        std::vector <double> x_xodr_value_vector;
        std::vector <double> y_xodr_value_vector;
        std::vector <double> hdg_xodr_value_vector;
        std::vector <double> length_xodr_value_vector;




        std::vector <double> vector_center_lane_x ;
        std::vector <double> vector_center_lane_y ;
        std::vector <double> get_center_lane_vecx();  // gets the  x and y values  from vector_center_lane_x and vector_center_lane_y
        std::vector <double> get_center_lane_vecy();
        std::vector <double> geometry_node_points_func(xml_node<> * planview_node, double i);
        std::vector <double> center_xy_vector;


        std::vector <double> vector_left_lane_4_x;
        std::vector <double> vector_left_lane_4_y;
        std::vector <double> get_left_lane_4_vecx();  // gets the  x and y values  from vector_center_lane_x and vector_center_lane_y
        std::vector <double> get_left_lane_4_vecy(); 

        
        std::vector <double> vector_left_lane_3_x;
        std::vector <double> vector_left_lane_3_y;
        std::vector <double> get_left_lane_3_vecx();  // gets the  x and y values  from vector_center_lane_x and vector_center_lane_y
        std::vector <double> get_left_lane_3_vecy(); 
        double  left_lane3_points_func(xml_node<> * lane_node, double i);

        
        std::vector <double> vector_left_lane_2_x;
        std::vector <double> vector_left_lane_2_y;
        std::vector <double> get_left_lane_2_vecx();  // gets the  x and y values  from vector_center_lane_x and vector_center_lane_y
        std::vector <double> get_left_lane_2_vecy();
        double  left_lane2_points_func(xml_node<> * lane_node, double i);

        std::vector <double> vector_left_lane_1_x;
        std::vector <double> vector_left_lane_1_y;
        std::vector <double> get_left_lane_1_vecx();  // gets the  x and y values  from vector_center_lane_x and vector_center_lane_y
        std::vector <double> get_left_lane_1_vecy();
        double  left_lane1_points_func(xml_node<> * lane_node, double i);

       
        std::vector <double> vector_left_lane_11_x;     //additional leftlane vector to show linelist
        std::vector <double> vector_left_lane_11_y;
        std::vector <double> get_left_lane_11_vecx();  
        std::vector <double> get_left_lane_11_vecy();


        
        
        
        
        
        std::vector <double> vector_car_left_3_x;     // to move car on a road
	std::vector <double> vector_car_left_3_y;
        std::vector <double> get_car_left_3_vecx();  // gets the  x and y values  from vector_center_mid_left_4_x and vector_center_mid_left_4_y
        std::vector <double> get_car_left_3_vecy();
        
        std::vector <double> vector_car_left_2_x;
	std::vector <double> vector_car_left_2_y;
        std::vector <double> get_car_left_2_vecx();  // gets the  x and y values  from vector_left_4_mid_left_3_x and vector_left_4_mid_left_3_y
        std::vector <double> get_car_left_2_vecy();

        std::vector <double> vector_car_left_1_x;
	std::vector <double> vector_car_left_1_y;
        std::vector <double> get_car_left_1_vecx();  // gets the  x and y values  from vector_left_3_mid_left_2_x and vector_left_3_mid_left_2_y
        std::vector <double> get_car_left_1_vecy();
       


        
        
        std::vector <double> i_vector;                 // only for testing to store that values in file
        std::vector <double> get_i_vector();

        std::vector <double> x_vector;
        std::vector <double> get_x_vector();

        std::vector <double> vector_width_x;  
        std::vector <double> vector_width_y;
        std::vector <double> get_width_vecx();  // gets the  x and y values  from vector_center_lane_x and vector_center_lane_y
        std::vector <double> get_width_vecy(); 

        lane();
       
};

