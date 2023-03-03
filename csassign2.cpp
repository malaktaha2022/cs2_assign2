/*
Malak Abdelhalim
900222407
Assignment 2
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

// class of points
class point
{
private:
    float x;
    float y;

public:
//default constructor
    point()
    {
        x = 0;
        y = 0;
    }
// parametized constructor
    point(float X, float Y)
    {
        x = X;
        y = Y;
    }

    void set_x(float X)
    {
        x = X;
    }

    float get_x()
    {
        return x;
    }

    void set_y(float Y)
    {
        y = Y;
    }

    float get_y()
    {
        return y;
    }

    void display_point()
    {
        cout << "( " << x << ", " << y << " )";
    }

    float get_distance(point p)
    {
        return sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
    }
};
// finds the center of each cluster of points
point centerpoint(point * arr, int size)
{
    float sumX = 0;
    float sumY = 0;
    float averageX = 0;
    float averageY = 0;
    for (int i = 0; i < size; i++)
    {
        sumX = sumX + arr[i].get_x();
        sumY = sumY + arr[i].get_y();
    }
    averageX = sumX / size;
    averageY = sumY / size;
    point center(averageX, averageY);

    return center;
}
// finds which cluster a point is closest to
void closer(point* clusterA, point* clusterB, point p, int n)
{
    point centerA;
    point centerB;
    float distanceA, distanceB;

    centerA = centerpoint(clusterA, n);
    centerB = centerpoint(clusterB, n);

    distanceA = p.get_distance(centerA);
    distanceB = p.get_distance(centerB);

    if (distanceA < distanceB)
    {
        cout << "A" << endl;
    }
    else if (distanceA > distanceB)
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "equidistant from both" << endl;
    }

}

int main()
{
    srand(time(0));
    int n;
    point centerA, centerB;
    float tempX, tempY;
    // dynamix array of clusters of n points for A & B
    cout << "enter the number of points in the clusters:";
    cin >> n;
    point * Ca = new point[n];
    point * Cb  = new point[n];
    // array of 20 points to test
    point P[20];
    
    // assigns correct values to coordinates of points for each cluster
    for (int i = 0; i < n; i++)
    {
        Ca[i].set_x((rand() % 19) + 71);
        Ca[i].set_y((rand() % 19) + 71);
        Cb[i].set_x((rand() % 19) + 21);
        Cb[i].set_y((rand() % 19) + 21);
    }
    
    // runs through the 20 points and utilizes function closer
    for (int i = 0; i < 20; i++)
    {
        cout << "Point " << i+1 << " belongs to cluster ";
        P[i].set_x((rand() % 94) + 6);
        P[i].set_y((rand() % 94) + 6);
        closer(Ca, Cb, P[i], n);
    }


}
