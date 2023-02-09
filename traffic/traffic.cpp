#include<iostream>

int main()
{
        for(int i=0;i<=100;i++)
        {
           for(int j=0;j<=2;j++) //to print 1st traffic
            {
                std::cout<<"*"<<" ";
                if(j==2)  //to print 2nd traffic
                {
                    std::cout<<"                        "; 
                    for(int j=0;j<=2;j++)
                           {
                            std::cout<<"*"<<" ";
                            if(j==2) //to print 3rd traffic
                            {
                                std::cout<<"                        "; 
                                for(int j=0;j<=2;j++)
                                {
                                   std::cout<<"*"<<" ";
                                }
                            }
                           }
                }
            }
            std::cout<<std::endl;
            if(i==20)
                {
                    std::cout<<std::endl;
                    for(int i=0;i<=10;i++) // print a new object of 10 rows and 3 colomns
                    {
                    for(int j=0;j<=2;j++)
                    {
                        std::cout<<"&"<<" ";
                        if(j==2)           // if j==2 print object on its right side
                        {
                        std::cout<<" ";
                           for(int k=0;k<=2;k++)
                           {
                            std::cout<<"*"<<" ";
                            if(k==2)       //if k==2 print the 2nd traffic
                            {
                                std::cout<<"                 "; 
                            for(int j=0;j<=2;j++)
                            {
                            std::cout<<"&"<<" ";
                            if(j==2)      //if j==2 print on its right side
                            {
                                std::cout<<" ";
                                for(int k=0;k<=2;k++)
                                {
                                    std::cout<<"*"<<" ";
                                    if(k==2) ////if k==2 print the 3rd traffic
                                    {
                                        std::cout<<"                 ";
                                        for(int j=0;j<=2;j++)
                                        {
                                           std::cout<<"&"<<" ";
                                           if(j==2) 
                                           {
                                                std::cout<<" ";
                                                for(int k=0;k<=2;k++)
                                                { 
                                                    std::cout<<"*"<<" ";
                                                }
                                           }
                                        }
                                    }
                                }
                            }
                            }
                            }
                           }
                        }
                    }
                        std::cout<<std::endl;  
                    }
                    std::cout<<std::endl;
                }
         }

         
         

         return 0;
 } 
 
