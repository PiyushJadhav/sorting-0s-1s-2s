/**
 * @brief This file sorts an vector of elements of 0, 1 and 2.
 * The main() build a dummy vector, which is given to the esort() sorting functions.
 *
 */

// include
#include <iostream>
#include <vector>

#include <algorithm> // only used for testing

// namespace
using namespace std;

// prototypes
static vector<int> esort( vector<int> data );

/**
 * This function sorts the input vector conatining only 0s, 1s and 2s.
 * Our logic would be to start filling 0s from the start of the vector and 2s from the end vector.
 * We will use standard swap() to swap values within the vector.
 * Note it throws exceptions when the elements are not either 0, 1 or 2s and exit app.
 * param[in] data data vector which is to be sorted.
 * return data sorted data vector
 */
static vector<int> esort( vector<int> data )
{
    const int N = data.size();

    // iterators
    int i0 = 0;
    int i2 = N-1;

    // itr for iterating over the vector
    int i = 0;
    try
    {
        // once i reach i2, all the elements are covered
        while(i < i2)
        {
            switch( data.at(i) )
            {
                case 0:
                {
                    swap(data.at(i), data.at(i0));
                    // inc itr
                    i0++;
                    i++;
                }
                break;

                case 1:
                {
                    // since 1 is in middle, you don't want to move. i0 will swap if needed.
                    i++;
                }
                break;

                case 2:
                {
                    swap(data.at(i), data.at(i2));
                    // decrement i2, since you want next element at loc - 1
                    i2--;

                    // should not incr i, since the swapped element should also be checked again
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

    for( int i=0; i<N; i++ )
    {
        int a = i%3;
        test_vector.push_back(a);
    }

    // store vec to test with
    vector<int> test_with(test_vector);

    test_vector = esort( test_vector );

    // test
    // sort the test_with
    sort(test_with.begin(), test_with.end() );
    bool result = equal(test_vector.begin(), test_vector.end(), test_with.begin() );

    if( result )
    {
        cout << "Test successful" << endl;
    }
    else
    {
        cout << "Test fail." << endl;
    }

    return 0;
}