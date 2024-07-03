#include <cmath>
#include <vector>
#include <iostream>
#include "separator.h"

#include <algorithm>
#include <iterator>

using namespace std;


int main() {
   
    vector<vector<float>> platonic_ideals_test{{0.1,0.7,0.2},{0.2,0.6,0.2},{0.3,0.1,0.2},{0.4,0.5,0.2}};// platonic ideals of 4 classes and 2 dimentions space
    vector<float> test_point_test{0.39,0.48,0.21};

    vector<float> v_result;

    vector<float> v_angle_result;

    v_result = func_seperator(test_point_test,platonic_ideals_test);

    v_angle_result = func_seperator_ang(test_point_test,platonic_ideals_test); 
    
    //cout<<v_result.size()<<endl;

    for (int i = 0; i<v_result.size();++i){
        cout<<"cartesian  = "<<v_result[i]<<" || "<<"angular = "<<v_angle_result[i]<<" || weighted in "<< (v_result[i]+v_angle_result[i])/2 <<endl;
    }
    //cout <<"I got here fine"<<endl;
    return 0;

};

