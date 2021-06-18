#include <iostream>
#include <vector>

using namespace std;

vector<int> esort( vector<int> data )
{   
    const int N = data.size();
    int i0 = 0;
    int i2 = N-1;
    int i = 0;

    try
    {
        while(i < i2)
        {
            switch( data.at(i) )
            {
                case 0:
                {
                    swap(data.at(i), data.at(i0));
                    i0++;
                    i++;
                }
                break;

                case 1:
                {
                    i++;
                }
                break;
                
                case 2:
                {
                    swap(data.at(i), data.at(i2));
                    i2--;
                }
                break;

                default:
                {
                    throw out_of_range ("Elements provided are not just 0s, 1s and 2s");
                }
            }
        }
    }
    catch(...)
    {
        cout << "Bad inputs" << endl;
        exit;
    }

    return data;
}


int main ( void )
{
    vector<int> test_vector;

    // we  will build a test vector to pass to our sorting mechanism
    // build
    int N = 30;
    
    for( int i=0; i<30; i++ )
    {
        int a = i%3;
        test_vector.push_back(a);
    }


    test_vector = esort( test_vector );

    // print out the vector to check 
    for( int i = 0; i < N; i++ )
    {
        cout << test_vector.at(i) << ", ";
    }

    cout << endl;

    return 0;
} 