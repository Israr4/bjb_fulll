#include <iostream>
#include <map>
#include <string>



int main()
{
    std::map <std::string,int> marksMap;
    marksMap["A"] = 10;  // first method for insertion
    marksMap["B"] = 20;
    marksMap["C"] = 30;
    marksMap["D"] = 40;

    marksMap.insert({{"E",50}, {"F",60}});   // second method for insertion 

    marksMap.insert(std::make_pair("G", 70));  // third method for insertion

    // std::map<std::string,int> :: iterator iter;  // printing with the  help of iterator
    // for(iter = marksMap.begin(); iter !=marksMap.end(); iter++)
    // {
    //     std::cout<<(*iter).first<<" "<<(*iter).second<<std::endl;
    // }

    for(auto var : marksMap)   // printing without iterator
    {
        std::cout<<var.first<<" "<<var.second<<std::endl;
    }

    return 0;
}











// // Now some time we want to insert two values(e.g X and Y values) to one key at a time so for this we used           std::pair(value1,value2)
// int main()
// {
//     std::map <std::string, std::pair<int,int>> marksMap;
    
//     marksMap["A"] = std::make_pair(100,20); // First method for insertion
//     marksMap["B"] = std::make_pair(200,30);
//     marksMap["C"] = std::make_pair(300,40);

//     marksMap.insert(std::make_pair("C",std::make_pair(400,50))); // Second method for insertion
//     marksMap.insert(std::make_pair("D",std::make_pair(500,60)));
//     marksMap.insert(std::make_pair("E",std::make_pair(600,70)));

//     marksMap.emplace("E",std::make_pair(700,80));  // Third method for insertion
//     marksMap.emplace("F",std::make_pair(800,90));
//     marksMap.emplace("G",std::make_pair(900,10));


//     std::map<std::string,std::pair<int,int>> :: iterator iter;   // printing with the help of iterator
//     for(iter = marksMap.begin(); iter !=marksMap.end(); iter++)
//     {
//         std::cout<<(*iter).first<<" "<< (*iter).second.first<<" "<< (*iter).second.second<<std::endl;
//     }

//     for(auto var : marksMap)   // printing without iterator
//     {
//         std::cout<<var.first<<" "<<var.second.first<<" "<<var.second.second<<std::endl;
//     }

//     return 0;
// }    