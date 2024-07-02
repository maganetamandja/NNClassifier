/*take platonic ideals and compare to the test example*/
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;


class separator {
    //private : vector<vector<float>> platonic_ideals;

   // private : vector<float> test_point;

    
    private : vector<float> compare(vector<float> test_point, vector<vector<float>> platonic_ideals){
        vector<vector<float>> resulting_vector;
        vector<float> resulting_distance;
        vector<float> t_vec;

        int rows = platonic_ideals.size(); 
        int columns = platonic_ideals[0].size();

        float modulus;
        //vector<float> resulting_distance_vector;

        for (size_t i = 0; i<rows; ++i){ //createt  a result vector
            //one platonic ideal
            //substract vectors
            //resulting_vector.push_back({0});

           for (size_t j=0; j<columns; ++j) {
            float n = platonic_ideals[i][j]-test_point[j];

            //cout<<"push this in " << to_string(n) << endl;
            
            t_vec.push_back(n);
            //resulting_vector[i][j] = platonic_ideals[i][j]-test_point[j];
            }

            resulting_vector.push_back(t_vec);
            //cout<<"update vector : size of resulting_vector = "<< resulting_vector.size()<<endl;
            t_vec.clear();



        }

        for ( size_t k = 0; k<rows; ++k ){ //find modulus

            //cout << "show me here"<<endl;


            for (size_t l = 0; l<columns;++l){

            modulus = modulus + pow(resulting_vector[k][l],2);

                

            }
            modulus = sqrt(modulus);

            resulting_distance.push_back(modulus);

            //cout<<"show modulus = "<<to_string(modulus)<<endl;



        };





       return resulting_distance;


    };

    public : vector<float> return_modulus(vector<float> test_point_p, vector<vector<float>> platonic_ideals_p){

        return compare(test_point_p, platonic_ideals_p);
    
    }




};

vector<float> func_seperator(vector<float> test_point_f, vector<vector<float>> platonic_ideals_f){
    separator separator_obj ;
    return separator_obj.return_modulus(test_point_f, platonic_ideals_f);
}