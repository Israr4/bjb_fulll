#include "rosline.h"



            lane :: lane()
            {   
                xml_document <> doc;
                xml_node     <> * root_node;    
                // Read the xml file into a vector
                std::ifstream theFile ("/home/maanz-ai/mathpractice_ws/src/mathpractice/src/bjb_sangjani_full.xodr"); //we always give path of .xodr file
                static std::vector <char> buffer((std::istreambuf_iterator <char> (theFile)), std::istreambuf_iterator <char>());
                buffer.push_back('\0');
                // Parse the buffer using the xml file parsing library into doc 
                doc.parse<'0'>(&buffer[0]);
                // Find our root node
                root_node = doc.first_node("OpenDRIVE");
                // Iterate over the brewerys



                xml_node<>      * road_node             = root_node->first_node("road");
                xml_attribute<> * length_attr_road_node = road_node->first_attribute("length");
                xml_attribute<> * road_id_node          = road_node->first_attribute("id");  
                xml_node<>      * planview_node         = road_node->first_node("planView"); 

                xml_node<> * geometry_node = planview_node->first_node("geometry");
                xml_attribute<> * length_attr_geometry_node = geometry_node->first_attribute("length");
                xml_attribute<> * s_attr_geometry_node      = geometry_node->first_attribute("s") ;   
                xml_attribute<> * hdg_attr_geometry_node    = geometry_node->first_attribute("hdg");  
                xml_attribute<> * x_attr_geometry_node      = geometry_node->first_attribute("x");     
                xml_attribute<> * y_attr_geometry_node      = geometry_node->first_attribute("y"); 


                // double x = 0;      //try code for center lane using s
                //     for (xml_node<> * geometry_node = planview_node->first_node("geometry"); geometry_node; geometry_node = geometry_node->next_sibling("geometry"))
                //     {
                //             xml_attribute<> * length_attr_geometry_node = geometry_node->first_attribute("length");   
                //             xml_attribute<> * hdg_attr_geometry_node    = geometry_node->first_attribute("hdg");  
                //             xml_attribute<> * x_attr_geometry_node      = geometry_node->first_attribute("x");     
                //             xml_attribute<> * y_attr_geometry_node      = geometry_node->first_attribute("y"); 
                //             xml_attribute<> * s_attr_geometry_node      = geometry_node->first_attribute("s");
                //             static int b = 0;
                //             if(geometry_node->next_sibling("geometry") != 0)
                //             {
                //                 xml_attribute<> * soffset2_node   = geometry_node->next_sibling("geometry")->first_attribute("s");
                //                 xml_attribute<> * x2_attr_geometry_node   = geometry_node->next_sibling("geometry")->first_attribute("x");
                //                 xml_attribute<> * y2_attr_geometry_node   = geometry_node->next_sibling("geometry")->first_attribute("y");
                //                 xml_attribute<> * hdg2_attr_geometry_node   = geometry_node->next_sibling("geometry")->first_attribute("hdg");
                                
                //             //   x = atof(soffset2_node->value()) - int(atof(soffset2_node->value()));
                //                 for(double i =  (atof(s_attr_geometry_node->value())) - x ; i < int(atof(soffset2_node->value())); i++)
                //                 { 
                //                     std::cout<<i<<std::endl; 
                //                     x = atof(soffset2_node->value()) - int(atof(soffset2_node->value()));
                //                     x_point_generator = (atof(x_attr_geometry_node->value())) + (cos(atof(hdg_attr_geometry_node->value())) * i); 
                //                     y_point_generator = (atof(y_attr_geometry_node->value())) + (sin(atof(hdg_attr_geometry_node->value())) * i); 
                //                     vector_center_lane_x.push_back(x_point_generator);
                //                     vector_center_lane_y.push_back(y_point_generator);
                                    
                //                     x_xodr_value_vector.push_back(atof(x_attr_geometry_node->value()));
                //                     y_xodr_value_vector.push_back(atof(y_attr_geometry_node->value()));
                //                     hdg_xodr_value_vector.push_back((atof(hdg_attr_geometry_node->value())));
                //                     length_xodr_value_vector.push_back(atof(length_attr_geometry_node->value()));
                //                     s_attr.push_back(atof(s_attr_geometry_node->value()));
                //                     i_vector.push_back(i);
                //                     x_vector.push_back(x);
                //                     b ++;
                //                 }
                //             }
                //     }


                    for(double i = 0; i < atof(length_attr_road_node->value()); i++)  //loop to control geometry node x_value and y_value
                    {
                        std::vector <double> center_lane_x_y_vector = geometry_node_points_func(planview_node, i); // har bari new aya ga i is lia 0 and 1 a raha ha   aur planeview node is lia dia ha kyo ka geometry node is ka andar ata ha
                        vector_center_lane_x.push_back(center_lane_x_y_vector[0]);
                        vector_center_lane_y.push_back(center_lane_x_y_vector[1]);
                        std::cout<<vector_center_lane_x.size()<<std::endl;
                    }

                    




                // for right we simply add + with sin of x and add - with cos of y

                xml_node<> * lanes_node   = road_node->first_node("lanes"); 
                xml_node<> * lane_section_node = lanes_node->first_node("laneSection");

                //left node parsing
                xml_node<> * left_node         = lane_section_node->first_node("left");   //4
                xml_node<> * lane_node         = left_node->first_node("lane");
                // xml_node<> * link_node         = lane_node->first_node("link");
                xml_node<> * width_node        = lane_node->first_node("width");
                xml_attribute<> * a_width4_node   = width_node->first_attribute("a");
            

                xml_node<> * lane3_node  = lane_node = lane_node->next_sibling();          //3
                // xml_node<> * link3_node      = lane_node->first_node("link");
                xml_node<> * width3_node = lane_node->first_node("width");
           
        
                xml_node<> * lane2_node  = lane_node = lane_node->next_sibling();          //2
                // xml_node<> * link2_node      = lane_node->first_node("link");
                xml_node<> * width2_node = lane_node->first_node("width");

                
                xml_node<> * lane1_node   = lane_node =  lane_node->next_sibling();         //1
                // xml_node<> * link1_node      = lane_node->first_node("link");
                xml_node<> * width1_node = lane_node->first_node("width");



                // for(double i = 0; i < atof(length_attr_road_node->value()); i++)    //4   lane 4 ka lia func ni likhan ga kyo ka is ka lia sirf ek width node ha
                // {
                //     double  width3_saving_variable                = left_lane3_points_func(lane3_node, i);
                //     double  width2_saving_variable                = left_lane2_points_func(lane2_node, i); 
                //     double  width1_saving_variable                = left_lane1_points_func(lane1_node, i);
                //     std::vector <double>  center_lane1_x_y_vector = geometry_node_points_func(planview_node, i); //is geometry_node_points_func ko is lia call kia ha kyo ka x and y and hdg ki values chahian width tag ma
                //     x_point_generator = x_xodr_value_vector.at(i) - (sin(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + width2_saving_variable + width3_saving_variable + atof(a_width4_node->value())));
                //     y_point_generator = y_xodr_value_vector.at(i) + (cos(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + width2_saving_variable + width3_saving_variable + atof(a_width4_node->value())));
                //     // std::cout<<width3_saving_variable<<std::endl;
                //     vector_left_lane_4_x.push_back(x_point_generator);
                //     vector_left_lane_4_y.push_back(y_point_generator);
                // }

                // for(double i = 0; i < atof(length_attr_road_node->value()); i++)    //3
                // {
                //     double  width3_saving_variable                = left_lane3_points_func(lane3_node, i);
                //     double  width2_saving_variable                = left_lane2_points_func(lane2_node, i); 
                //     double  width1_saving_variable                = left_lane1_points_func(lane1_node, i);
                //     std::vector <double>  center_lane1_x_y_vector = geometry_node_points_func(planview_node, i); //is geometry_node_points_func ko is lia call kia ha kyo ka x and y and hdg ki values chahian width tag ma
                //     x_point_generator = x_xodr_value_vector.at(i) - (sin(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + width2_saving_variable + width3_saving_variable));
                //     y_point_generator = y_xodr_value_vector.at(i) + (cos(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + width2_saving_variable + width3_saving_variable));
                //     // std::cout<<width3_saving_variable<<std::endl;
                //     vector_left_lane_3_x.push_back(x_point_generator);
                //     vector_left_lane_3_y.push_back(y_point_generator);
                // }
                

                // for(double i = 0; i < atof(length_attr_road_node->value()); i++)    //2
                // {
                //     double  width2_saving_variable                = left_lane2_points_func(lane2_node, i); // har bari new aya ga i is lia 0 and 1 a raha ha   aur lane node is lia dia ha kyo ka width node is ka andar ata ha aur is na necha function ma use hona ha
                //     double  width1_saving_variable                = left_lane1_points_func(lane1_node, i);
                //     std::vector <double>  center_lane1_x_y_vector = geometry_node_points_func(planview_node, i); //is geometry_node_points_func ko is lia call kia ha kyo ka x and y and hdg ki values chahian width tag ma
                //     x_point_generator = x_xodr_value_vector.at(i) - (sin(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + width2_saving_variable));
                //     y_point_generator = y_xodr_value_vector.at(i) + (cos(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + width2_saving_variable));
                //     // std::cout<<width2_saving_variable<<std::endl;
                //     vector_left_lane_2_x.push_back(x_point_generator);
                //     vector_left_lane_2_y.push_back(y_point_generator);
                // }


                // for(double i = 0; i < atof(length_attr_road_node->value()); i++)     //1
                // {
                //     double  width1_saving_variable                = left_lane1_points_func(lane1_node, i); // har bari new aya ga i is lia 0 and 1 a raha ha   aur lane node is lia dia ha kyo ka width node is ka andar ata ha aur is na necha function ma use hona ha
                //     std::vector <double>  center_lane1_x_y_vector = geometry_node_points_func(planview_node, i); //is geometry_node_points_func ko is lia call kia ha kyo ka x and y and hdg ki values chahian width tag ma
                //     x_point_generator = x_xodr_value_vector.at(i) - (sin(hdg_xodr_value_vector.at(i)) * width1_saving_variable);
                //     y_point_generator = y_xodr_value_vector.at(i) + (cos(hdg_xodr_value_vector.at(i)) * width1_saving_variable);
                //     // std::cout<<width1_saving_variable<<std::endl;
                //     vector_left_lane_1_x.push_back(x_point_generator);
                //     vector_left_lane_1_y.push_back(y_point_generator);
                // }




                // for(int i = 0; i < atof(length_attr_road_node->value()); i++)     //1    only for line list   and fmod() is used to make modulus % between int and double    e.g    fmod(16.555 % 2)
                // {
                //     int  width1_saving_variable                   = left_lane1_points_func(lane1_node, int(i)); // har bari new aya ga i is lia 0 and 1 a raha ha   aur lane node is lia dia ha kyo ka width node is ka andar ata ha aur is na necha function ma use hona ha
                //     std::vector <double>  center_lane1_x_y_vector = geometry_node_points_func(planview_node, int(i)); //is geometry_node_points_func ko is lia call kia ha kyo ka x and y and hdg ki values chahian width tag ma
                //     x_point_generator = x_xodr_value_vector.at(i) - (sin(hdg_xodr_value_vector.at(i)) * width1_saving_variable);
                //     y_point_generator = y_xodr_value_vector.at(i) + (cos(hdg_xodr_value_vector.at(i)) * width1_saving_variable);
                //     if(int(x_point_generator) % 2 && int(y_point_generator) % 2 )      // to handle the error line list should be multiple of 2
                //     {
                //         // std::cout<<width1_saving_variable<<std::endl;
                //         vector_left_lane_11_x.push_back(x_point_generator);
                //         vector_left_lane_11_y.push_back(y_point_generator);
                //     }
                // }



                // for(double i = 0; i < atof(length_attr_road_node->value()); i++)     // car in between center lane  and left lane 1
                // {
                //     double  width1_saving_variable                = left_lane1_points_func(lane1_node, i); // har bari new aya ga i is lia 0 and 1 a raha ha   aur lane node is lia dia ha kyo ka width node is ka andar ata ha aur is na necha function ma use hona ha
                //     std::vector <double>  center_lane1_x_y_vector = geometry_node_points_func(planview_node, i); //is geometry_node_points_func ko is lia call kia ha kyo ka x and y and hdg ki values chahian width tag ma
                //     double mid_point = width1_saving_variable / 2;
                //     x_point_generator = x_xodr_value_vector.at(i) - (sin(hdg_xodr_value_vector.at(i)) * mid_point);
                //     y_point_generator = y_xodr_value_vector.at(i) + (cos(hdg_xodr_value_vector.at(i)) * mid_point);
                //     // std::cout<<width1_saving_variable<<std::endl;
                //     vector_car_left_1_x.push_back(x_point_generator);
                //     vector_car_left_1_y.push_back(y_point_generator);
                // }



                // for(double i = 0; i < atof(length_attr_road_node->value()); i++)     // car in between  left lane 1  and left lane 2
                // {
                //     double  width2_saving_variable                = left_lane2_points_func(lane2_node, i); // har bari new aya ga i is lia 0 and 1 a raha ha   aur lane node is lia dia ha kyo ka width node is ka andar ata ha aur is na necha function ma use hona ha
                //     double  width1_saving_variable                = left_lane1_points_func(lane1_node, i);
                //     std::vector <double>  center_lane1_x_y_vector = geometry_node_points_func(planview_node, i); //is geometry_node_points_func ko is lia call kia ha kyo ka x and y and hdg ki values chahian width tag ma
                //     double mid_point = width2_saving_variable / 2;
                //     x_point_generator = x_xodr_value_vector.at(i) - (sin(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + mid_point));
                //     y_point_generator = y_xodr_value_vector.at(i) + (cos(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + mid_point));
                //     std::cout<<width2_saving_variable<<std::endl;
                //     // std::cout<<mid_point<<std::endl;
                //     vector_car_left_2_x.push_back(x_point_generator);
                //     vector_car_left_2_y.push_back(y_point_generator);
                // }


                // for(double i = 0; i < atof(length_attr_road_node->value()); i++)    //   car in between  left lane 2  and left lane 3
                // {
                //     double  width3_saving_variable                = left_lane3_points_func(lane3_node, i);
                //     double  width2_saving_variable                = left_lane2_points_func(lane2_node, i); 
                //     double  width1_saving_variable                = left_lane1_points_func(lane1_node, i);
                //     double  mid_point = width3_saving_variable / 2;
                //     std::vector <double>  center_lane1_x_y_vector = geometry_node_points_func(planview_node, i); //is geometry_node_points_func ko is lia call kia ha kyo ka x and y and hdg ki values chahian width tag ma
                //     x_point_generator = x_xodr_value_vector.at(i) - (sin(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + width2_saving_variable + mid_point));
                //     y_point_generator = y_xodr_value_vector.at(i) + (cos(hdg_xodr_value_vector.at(i)) * (width1_saving_variable + width2_saving_variable + mid_point));
                //     // std::cout<<width3_saving_variable<<std::endl;
                //     vector_car_left_3_x.push_back(x_point_generator);
                //     vector_car_left_3_y.push_back(y_point_generator);
                // }






             


                
                // for(xml_node<> * width1_node = lane_node->first_node("width"); width1_node; width1_node = width1_node->next_sibling("width")) //practice code for width tag
                // {
                //         xml_attribute<> * a_width1_node   = width1_node->first_attribute("a");
                //         xml_attribute<> * b_width1_node   = width1_node->first_attribute("b");
                //         xml_attribute<> * c_width1_node   = width1_node->first_attribute("c");
                //         xml_attribute<> * d_width1_node   = width1_node->first_attribute("d");
                //         xml_attribute<> * soffset1_node   = width1_node->first_attribute("sOffset");
                //         static int z = 0;
                //         if(width1_node->next_sibling("width") != 0)
                //         {
                //             xml_attribute<> * soffset2_node   = width1_node->next_sibling("width")->first_attribute("sOffset");
                //             double x  = 0;
                //             double ds = 0;
                //             double start  = 0;
                //             double s = 0;
                //             for(double i = atof(soffset1_node->value()) - x; i < int(atof(soffset2_node->value())); i++)
                //             { 
                //                 x  = atof(soffset2_node->value()) - int(atof(soffset2_node->value()));
                //                 start  = atof(soffset1_node->value()) ;
                //                 s = i;
                //                 ds = s - start;
                //                 x_new_value_1  =  (x_xodr_value_vector.at(z) - sin(hdg_xodr_value_vector.at(z))) * ( ((atof(d_width1_node->value()) * pow(ds,3)) + (atof(c_width1_node->value()) * pow(ds,2)) + (atof(b_width1_node->value()) * ds) + (atof(a_width1_node->value()))  )) * z ;
                //                 y_new_value_1  =  (y_xodr_value_vector.at(z) + cos(hdg_xodr_value_vector.at(z))) * ( ((atof(d_width1_node->value()) * pow(ds,3)) + (atof(c_width1_node->value()) * pow(ds,2)) + (atof(b_width1_node->value()) * ds) + (atof(a_width1_node->value()))  )) * z;
                //                 // x_value = x_new_value_1 + (cos(hdg_attr_x.at(z)) * z);
                //                 // y_value = y_new_value_1 + (sin(hdg_attr_y.at(z)) * z);
                //                 vector_width_x.push_back(x_new_value_1);
                //                 vector_width_y.push_back(y_new_value_1);
                //                 z++;
                //             }
                //         }
                //         else
                //         {
                //             xml_node<> * width1_node = lane_node->last_node("width");
                //             double p = atof(length_attr_road_node->value()) - vector_width_x.size();
                //             double ds =0;
                //             double s = 0;
                //             double start  = 0;
                //             for(double a = 0; a <= p; a++)
                //             {
                //                 start  = 0 ;
                //                 s = a;
                //                 ds = s - start;
                //                 // std::cout<<p<<std::endl;
                //                 // std::cout<<atof(a_width1_node->value())<<std::endl;
                //                 x_new_value_1  =  (x_xodr_value_vector.at(z) - sin(hdg_xodr_value_vector.at(z))) * (((atof(d_width1_node->value()) * pow(ds,3)) + (atof(c_width1_node->value()) * pow(ds,2)) + (atof(b_width1_node->value()) * ds) + (atof(a_width1_node->value()))  ) ) * z ;
                //                 y_new_value_1  =  (y_xodr_value_vector.at(z) + cos(hdg_xodr_value_vector.at(z))) * (((atof(d_width1_node->value()) * pow(ds,3)) + (atof(c_width1_node->value()) * pow(ds,2)) + (atof(b_width1_node->value()) * ds) + (atof(a_width1_node->value()))  ) ) * z;
                //                 // x_value = x_new_value_1 + (cos(hdg_attr_x.at(z)) * z);
                //                 // y_value = y_new_value_1 + (sin(hdg_attr_y.at(z)) * z);
                //                 vector_width_x.push_back( x_new_value_1);
                //                 vector_width_y.push_back( y_new_value_1);
                //                 z ++;
                //             }
                //         }
                                    

                // }

                    //  std::cout<<width1_node->next_sibling("width")<<std::endl;  //to show the memory addresss of width tag aur next sibling par usa kuch mil hi ni raha is lia 0 da raha ha
                    //  if(width1_node->next_sibling("width") != 0)
                    //  {
                    
                    //  std::cout<<atof(soffset2_node->value())<<std::endl;
                    //  }
                

            }



                    std::vector <double> lane:: geometry_node_points_func(xml_node<> * planview_node, double i) // function for center lane  aur idr hum na planview node is lia likha ha kyo ka isa use karna ha aga
                    {
                        for (xml_node<> * geometry_node = planview_node->first_node("geometry"); geometry_node; geometry_node = geometry_node->next_sibling("geometry"))
                        {

                           
                            xml_attribute<> * length_attr_geometry_node = geometry_node->first_attribute("length");   
                            xml_attribute<> * hdg_attr_geometry_node    = geometry_node->first_attribute("hdg");  
                            xml_attribute<> * x_attr_geometry_node      = geometry_node->first_attribute("x");     
                            xml_attribute<> * y_attr_geometry_node      = geometry_node->first_attribute("y"); 
                            xml_attribute<> * s_attr_geometry_node      = geometry_node->first_attribute("s");
                        
                                if(i >= atof(s_attr_geometry_node->value())  && i <=(atof(s_attr_geometry_node->value()) + atof(length_attr_geometry_node->value())))
                                {
                                    center_xy_vector.clear();
                                    ds = i - atof(s_attr_geometry_node->value());
                                    x_point_generator = (atof(x_attr_geometry_node->value())) + (cos(atof(hdg_attr_geometry_node->value())) * ds); 
                                    y_point_generator = (atof(y_attr_geometry_node->value())) + (sin(atof(hdg_attr_geometry_node->value())) * ds); 
                                    center_xy_vector.push_back(x_point_generator);
                                    center_xy_vector.push_back(y_point_generator);
                                    x_xodr_value_vector.push_back(atof(x_attr_geometry_node->value())); //to store values in vector to use them later
                                    y_xodr_value_vector.push_back(atof(y_attr_geometry_node->value()));
                                    hdg_xodr_value_vector.push_back(atof(hdg_attr_geometry_node->value()));
                                    return center_xy_vector;
                                    
                                }
                            
                        }
                        return center_xy_vector;
                        
                    }





                    // double lane:: left_lane1_points_func(xml_node<> * lane_node, double i) // function for left lane 1     //idr koi bi name rakh sakta han link11 node upar simple is ki jaga original put kar dena ha
                    // {
                    //         xml_node<> * width1last_node = lane_node->last_node("width");
                    //         xml_attribute<> * a_last_width1_node   = width1last_node->first_attribute("a");
                    //         xml_attribute<> * b_last_width1_node   = width1last_node->first_attribute("b");
                    //         xml_attribute<> * c_last_width1_node   = width1last_node->first_attribute("c");
                    //         xml_attribute<> * d_last_width1_node   = width1last_node->first_attribute("d");
                    //         xml_attribute<> * soffset1_last_node   = width1last_node->first_attribute("sOffset");
                    //     for (xml_node<> * width1_node = lane_node->first_node("width"); width1_node; width1_node = width1_node->next_sibling("width"))
                    //     {
                    //         xml_attribute<> * a_width1_node   = width1_node->first_attribute("a");
                    //         xml_attribute<> * b_width1_node   = width1_node->first_attribute("b");
                    //         xml_attribute<> * c_width1_node   = width1_node->first_attribute("c");
                    //         xml_attribute<> * d_width1_node   = width1_node->first_attribute("d");
                    //         xml_attribute<> * soffset1_node   = width1_node->first_attribute("sOffset");
                    //         xml_attribute<> * soffset2_node   = width1_node->next_sibling("width")->first_attribute("sOffset");
                            
                    //             if(i >= atof(soffset1_node->value())  && i < (atof(soffset2_node->value())))
                    //             {
                    //                 ds    = i - atof(soffset1_node->value());
                    //                 width = (((atof(d_width1_node->value()) * pow(ds,3)) + (atof(c_width1_node->value()) * pow(ds,2)) + (atof(b_width1_node->value()) * ds) + (atof(a_width1_node->value()))));
                    //                 // center_xy_vector.push_back(width);
                    //                 // std::cout<<" hiii "<<std::endl;
                    //                 return width;
                                    
                    //             }
                                
                    //             else if(i > atof(soffset1_last_node->value()))
                    //             {
                    //                 ds = i - atof(soffset1_last_node->value());
                    //                 width = (((atof(d_last_width1_node->value()) * pow(ds,3)) + (atof(c_last_width1_node->value()) * pow(ds,2)) + (atof(b_last_width1_node->value()) * ds) + (atof(a_last_width1_node->value()))));
                    //                 // std::cout<<" new "<<std::endl;
                    //                 return width;
                    //             }

                    //     }
                    //     return width;
                    // }



                    //  double lane:: left_lane2_points_func(xml_node<> * lane_node, double i) // function for left lane 1     //idr koi bi name rakh sakta han link11 node upar simple is ki jaga original put kar dena ha
                    // {
                    //         xml_node<> * width2last_node = lane_node->last_node("width");
                    //         xml_attribute<> * a_last_width2_node   = width2last_node->first_attribute("a");
                    //         xml_attribute<> * b_last_width2_node   = width2last_node->first_attribute("b");
                    //         xml_attribute<> * c_last_width2_node   = width2last_node->first_attribute("c");
                    //         xml_attribute<> * d_last_width2_node   = width2last_node->first_attribute("d");
                    //         xml_attribute<> * soffset1_last_node   = width2last_node->first_attribute("sOffset");
                    //     for (xml_node<> * width2_node = lane_node->first_node("width"); width2_node; width2_node = width2_node->next_sibling("width"))
                    //     {
                    //         xml_attribute<> * a_width2_node   = width2_node->first_attribute("a");
                    //         xml_attribute<> * b_width2_node   = width2_node->first_attribute("b");
                    //         xml_attribute<> * c_width2_node   = width2_node->first_attribute("c");
                    //         xml_attribute<> * d_width2_node   = width2_node->first_attribute("d");
                    //         xml_attribute<> * soffset1_node   = width2_node->first_attribute("sOffset");
                    //         xml_attribute<> * soffset2_node   = width2_node->next_sibling("width")->first_attribute("sOffset");
                            
                    //             if(i >= atof(soffset1_node->value())  && i < (atof(soffset2_node->value())))
                    //             {
                    //                 ds = i - atof(soffset1_node->value());
                    //                 width = (((atof(d_width2_node->value()) * pow(ds,3)) + (atof(c_width2_node->value()) * pow(ds,2)) + (atof(b_width2_node->value()) * ds) + (atof(a_width2_node->value()))));
                    //                 // std::cout<<" hiii "<<std::endl;
                    //                 return width;
                                    
                    //             }
                                
                    //              else if(i > atof(soffset1_last_node->value()))
                    //             {
                    //                 ds = i - atof(soffset1_last_node->value());
                    //                 width = (((atof(d_last_width2_node->value()) * pow(ds,3)) + (atof(c_last_width2_node->value()) * pow(ds,2)) + (atof(b_last_width2_node->value()) * ds) + (atof(a_last_width2_node->value()))));
                    //                 // std::cout<<" new "<<std::endl;
                    //                 return width;
                    //             }

                    //     }
                    //     return width;
                    // }




                    // double lane:: left_lane3_points_func(xml_node<> * lane_node, double i) // function for left lane 1     //idr koi bi name rakh sakta han link11 node upar simple is ki jaga original put kar dena ha
                    // {
                    //         xml_node<> * width2last_node = lane_node->last_node("width");
                    //         xml_attribute<> * a_last_width2_node   = width2last_node->first_attribute("a");
                    //         xml_attribute<> * b_last_width2_node   = width2last_node->first_attribute("b");
                    //         xml_attribute<> * c_last_width2_node   = width2last_node->first_attribute("c");
                    //         xml_attribute<> * d_last_width2_node   = width2last_node->first_attribute("d");
                    //         xml_attribute<> * soffset1_last_node   = width2last_node->first_attribute("sOffset");
                    //     for (xml_node<> * width2_node = lane_node->first_node("width"); width2_node; width2_node = width2_node->next_sibling("width"))
                    //     {
                    //         xml_attribute<> * a_width2_node   = width2_node->first_attribute("a");
                    //         xml_attribute<> * b_width2_node   = width2_node->first_attribute("b");
                    //         xml_attribute<> * c_width2_node   = width2_node->first_attribute("c");
                    //         xml_attribute<> * d_width2_node   = width2_node->first_attribute("d");
                    //         xml_attribute<> * soffset1_node   = width2_node->first_attribute("sOffset");
                    //         xml_attribute<> * soffset2_node   = width2_node->next_sibling("width")->first_attribute("sOffset");
                            
                    //             if(i >= atof(soffset1_node->value())  && i < (atof(soffset2_node->value())))
                    //             {
                    //                 ds = i - atof(soffset1_node->value());
                    //                 width = (((atof(d_width2_node->value()) * pow(ds,3)) + (atof(c_width2_node->value()) * pow(ds,2)) + (atof(b_width2_node->value()) * ds) + (atof(a_width2_node->value()))));
                    //                 // std::cout<<" hiii "<<std::endl;
                    //                 return width;
                                    
                    //             }
                                
                    //              else if(i > atof(soffset1_last_node->value()))
                    //             {
                    //                 ds = i - atof(soffset1_last_node->value());
                    //                 width = (((atof(d_last_width2_node->value()) * pow(ds,3)) + (atof(c_last_width2_node->value()) * pow(ds,2)) + (atof(b_last_width2_node->value()) * ds) + (atof(a_last_width2_node->value()))));
                    //                 // std::cout<<" new "<<std::endl;
                    //                 return width;
                    //             }

                    //     }
                    //     return width;
                    // }



                std::vector<double> lane::get_center_lane_vecx()
                {
                    return vector_center_lane_x;
                }

                std::vector<double> lane::get_center_lane_vecy()
                {
                    return vector_center_lane_y;
                }    



                //  std::vector<double> lane::get_left_lane_4_vecx()
                //  {
                //  	return vector_left_lane_4_x;
                //  }

                //  std::vector<double> lane::get_left_lane_4_vecy()
                //  {
                // 	return vector_left_lane_4_y;
                //  }  




                //  std::vector<double> lane::get_left_lane_3_vecx()
                //  {
                //  	return vector_left_lane_3_x;
                //  }

                //  std::vector<double> lane::get_left_lane_3_vecy()
                //  {
                // 	return vector_left_lane_3_y;
                //  }   




                //  std::vector<double> lane::get_left_lane_2_vecx()
                //  {
                //  	return vector_left_lane_2_x;
                //  }

                //  std::vector<double> lane::get_left_lane_2_vecy()
                //  {
                // 	return vector_left_lane_2_y;
                //  }   



                // std::vector<double> lane::get_left_lane_1_vecx()
                // {
                //     return vector_left_lane_1_x;
                // }


                // std::vector<double> lane::get_left_lane_1_vecy()
                // {
                //     return vector_left_lane_1_y;
                // }   


                // std::vector<double> lane::get_left_lane_11_vecx()
                // {
                //     return vector_left_lane_11_x;
                // }


                // std::vector<double> lane::get_left_lane_11_vecy()
                // {
                //     return vector_left_lane_11_y;
                // } 



                // std::vector<double> lane::get_car_left_1_vecx()
                // {
                //     return vector_car_left_1_x;
                // }
                // std::vector<double> lane::get_car_left_1_vecy()
                // {
                //     return vector_car_left_1_y;
                // }  


                // std::vector<double> lane::get_car_left_2_vecx()
                // {
                //     return vector_car_left_2_x;
                // }
                // std::vector<double> lane::get_car_left_2_vecy()
                // {
                //     return vector_car_left_2_y;
                // }  

                // std::vector<double> lane::get_car_left_3_vecx()
                // {
                //     return vector_car_left_3_x;
                // }
                // std::vector<double> lane::get_car_left_3_vecy()
                // {
                //     return vector_car_left_3_y;
                // }                                                                                                                


                          





                // std::vector<double> lane::get_width_vecx()
                // {
                //     return vector_width_x;
                // }


                // std::vector<double> lane::get_width_vecy()
                // {
                //     return vector_width_y;
                // }  


                // std::vector<double> lane::get_i_vector()
                // {
                //     return i_vector;
                // }    


                // std::vector<double> lane::get_x_vector()
                // {
                //     return x_vector;
                // }  



                  


                
                                                           
    