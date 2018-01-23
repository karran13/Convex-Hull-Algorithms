#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define mp make_pair
using namespace std;


/** \struct point structure point having the x and the y coordinates of the point */ 
typedef struct{
    double x,y;
}point;

point fp; 			/**< The left most point is stored in this */


/** class primitives
* brief a class containing all the primitive operations involved
*details This class incorporates all the primitive operations 
*		like orientation, square distance between points, getting first point in a list of points etc.
*/ 
class primitives {


	
	public:
/** brief orientation - Gives the orientation of three points 
* 	details	This function takes three points in an order as input and outputs if it takes a left turn or a right turn
*	\param p the first point
*	\param q the second or the middle point
*	\param r the third point
*	\return 0 is returned if the points are collinear, 1 if they make a left turn and 2 if they make a right turn
*/
			 static int orientation(point p,point q,point r)
			{
				double val=(q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);		
				if(val==0) return 0;            // collinear points
				else if(val>0) return 1;        // left turn
				else return 2;                  // right turn
			}
			
/** brief SqDist - Gives the distance between two points
*	details This function gives the square of the distance between two given points
*	\param	a The first point
*	\param b The  second point
*	\return	The square of the distance
*/
			static double SqDist(point a,point b)
			{
				double ret;	 	/**< Square of the distance */
				ret=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
				return ret;
			}

/** brief compare - compares the orientation of the two points 
*	details This function helps in sorting the points on the basis of polar coordinates with respect
*		to the left most point. 
*	\param	a The first point
*	\param b The  second point
*	\return	1 is returned if the polar angle of a is less than b. Else 0
*/			
			static bool compare(point a,point b)
			{
				int tr=orientation(fp,a,b);
				if(tr==0)
					return SqDist(fp,a)<SqDist(fp,b);    // if points with same angle closer one comes first
				if(tr==1) return 1;
				else return 0;
			}

/** brief getFirstPoint - returns the left most and bottom most point in a vector of points 
*	\param	arr The vector of input points
*	\return	The point and the index of the point in the vector
*/			
			static pair<point,int> getFirstPoint(vector<point> arr)
			{
				pair<point,int> ret=mp(arr[0],0);
				for(int i=1;i<arr.size();i++)
				{
					if(arr[i].y<ret.ff.y)
						ret=mp(arr[i],i);
					else if(arr[i].y==ret.ff.y && arr[i].x<ret.ff.x)
						ret=mp(arr[i],i);
				}
				return ret;
			}

/** brief nextToTop - returns the point next to the top element in a stack of points
*	\param	s A stack of points
*	\return	The point immediately below to the top of the stack
*/							
			static point nextToTop(stack<point> s)
			{
				point x=s.top();
				s.pop();
				point ret=s.top();
				s.push(x);
				return ret;
			}
};
