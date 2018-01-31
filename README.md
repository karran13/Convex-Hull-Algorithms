# Convex-Hull-Algorithms
Three algorithms to find the convex hull of a set of points: Graham Scan, Jarvis March, Andrew's Algorithm

**Introduction**

A Convex Hull of a set of points, say X, is defined as the smallest convex set that contains X. 
Finding the convex hull of a set of points is one of the most fundamental problems of computational geometry that finds its applications in numerous places.The algorithms we are going to analyze, deal with the planar case, where in we have a finite set of points in the same plane. 
In this case, the convex hull is found to be a convex polygon made up of a set of points from among the finite point set given to us. Our three convex hull algorithms return these set of points that make up the required convex polygon. The algorithms we have implemented are:

1. Graham's Scan

2. Jarvis March 

3. Andrew's Algorithm

**Graham's Scan**

This algorithm is based on traversing the set of points starting from the lowermost leftmost point in an order sorted by the angle it makes with the rest of the points, and classifying the angles of the turns we make going to the next point as left turns or right turns, to ensure the convexity of the polygon we're forming.

**Method:**

Step 1: We find the lowermost leftmost point, let it be P.

Step 2: We sort the rest of the points in increasing order of the angle they and the point P make with the x-axis. If P' represents the current point to be sorted, This was done taking the cross product between the two vectors PP' and PX, where X is a point on the X axis ahead of P.

Step 3: We consider each of the points in the sorted array in sequence. We use a stack data structure here, to add and remove the points from the set that we consider to be our Convex Hull.

For each point, it is first determined whether traveling from the two points immediately preceding this point constitutes making a left turn or a right turn. 

If a right turn, the second-to-last point is not part of the convex hull, and lies 'inside' it and is therefore removed from the stack. 

The same determination is then made for the set of the latest point and the two points that immediately precede the point found to have been inside the hull, and is repeated until a "left turn" set is encountered, at which point the algorithm moves on to add the next point in the set of points in the sorted array minus any points that were found to be inside the hull. There is no need to consider these points again. 

Deciding whether it is a left turn or a right turn between three points, say P1, P2 and P3 is also easily accomplished using the cross product between the vectors P1P2 and P1P3.

Step 4: The process eventually returns to the point at which it started, at which point the algorithm is completed and the stack now contains the points of the convex hull in counter clockwise order.

**Theoretical time analysis**

Sorting the points has a time complexity of O(nlogn), and our left turn/right turn stack traversal has a complexity of O(n), as each point can be encountered a maximum of twice. One for it's first go and second if it needs to be removed from the stack. So the overall time complexity, theoretically is O(nlogn)

**Jarvis March**

This algorithm starts with the leftmost lowermost point, say P, and in it's next iterative step searches for a point P' such that the line PP' is to the left of all the other points in the set, this process is repeated till we reach the initial point again.

**Method:** 

1. After finding our initial point(Leftmost, lowermost) the algorithm uses the angles all the remaining points make with the current point to find the next suitable point.

2. This is again easily accomplished using cross products

3. The same step is repeated for the remaining points, till the convex hull is formed. 

**Theoretical time analysis** 

The angle check step is for all the points in the set, meaning n points and this angle check gets repeated for as many as the number of points on the hull, say h. So theoretically, our time complexity is O(nh). Meaning that this would perform better than O(nlogn) algorithms only if the number of points h, on the hull is less than logn.

**Andrew's Algorithm**

This algorithm is based on sorting the given set of points by their x co-ordinates (in case of tie, by y co-ordinate) and then constructing the upper and lower hulls of the required convex hull. 

**Method:** 

1. After sorting the points as mentioned, to construct the upper and lower hull we use a simple condition. Let U and L be the sets denoting Upper Hull and Lower Hull respectively, then 

2. When we traverse forward, we keep adding points to L while using the condition that if L contains more than three points, and the last two points of L and the current new point do not make a counter clockwise turn, me remove the last point from L. 

3. Similarly, for U we do the same when we traverse back from the last point to the first. Since the meaning of a counter clockwise turn is now flipped, the same condition works for putting points in U. 

4. As usual left turns and right turns are determined using cross products as described in graham's scan.

5. Finally we just remove the common point from U and L and we have our required convex hull. 

**Theoretical time analysis** 

Sorting the points take O(nlogn) time, while the traversal is just O(n), since again a point can be encountered a maximum of two times, first in adding it into U or L and second in removing it from U or L. So theoretically, the overall time complexity is O(nlogn), for the algorithm.

**Practical Analysis**

The three algorithms are run on a number of inputs and outputs are generated. A visualization platform is used to visualize the convex hull given a set of points. The following figures show the outputs of the algorithms when the input given is 50, 500 and 5000 randomly generated points on all the three algorithms.

![Alt text](relative/path/to/50.png?raw=true "Title")
![Alt text](relative/path/to/500.png?raw=true "Title")
![Alt text](relative/path/to/5000.png?raw=true "Title")

The algorithm is run on inputs of sizes from 10 to 100000 and the time analysis graphs have been plotted.

Andrew's Algorithm is represented by the red curve. 
Graham's Algorithm is represented by the green curve. 
Jarvis' algorithm is represented by the blue curve. 

![Alt text](relative/path/to/time.png?raw=true "Title")

As expected from the theoretical time analysis, Andrews algorithm takes the highest time and Jarvis takes the lowest time as Jarvis is Output Sensitive.


