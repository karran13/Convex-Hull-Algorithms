#include <bits/stdc++.h>
#include "convexhull.h"
#define iOS ios::sync_with_stdio(false)

using namespace std;
int n;					/**< The number of points in the input set */
vector<point> arr;		/**< The vector containing all the points in the input set */

int main(void)
{
	iOS;
	srand(time(NULL));
	double input[15]={10,25,75,100,125,500,750,1000,3000,7000,10000,25000,50000,75000,100000};
	//double time[15];
	clock_t t1;		/**< The clock times are recorded to calculate the running time of the algorithm */
	clock_t t2;
	
	printf("Determination of a Convex Hull for a set of points\n");
	point p;
	printf("Enter the number of points in the set\n");
	cin >> n;
	//for(int l=0;l<15;l++)
	//{
		//n=input[l];
		int choice;
		printf("Choose an option\n1)Enter the points manually\n2)Randomly generate points\n");
		cin >> choice;
		
		while(choice!=1 && choice!=2)
		{
			printf("We have only two options. Choose 1 or 2\n");
			cin >> choice;
		}
		if(choice==1)
		{
			printf("Enter the x and the y coordinates of the points");
			for(int i=0;i<n;i++)
			{
				cin >> p.x >> p.y;
				arr.pb(p);
			}
		}
		else if(choice==2)
		{
			for(int i=0;i<n;i++)
			{
				p.x=rand()%10000;
				p.y=rand()%10000;
				arr.pb(p);
			}

		}
		int algo;
		printf("Choose the algorithm you want to run the input set on\n1)Graham Scan\n2)Jarvis March\n3)Andrew's Algorithm\n");
		cin >> algo;
		
		vector<point> ret;
		t1=clock();
		if(algo==1)
		{
			ret= GrahamScan::GrahamScanHull(arr);
		}
		else if(algo==2)
		{
			ret=JarvisMarch::JarvisHull(arr);
		}
		else if(algo==3)
		{
			ret=AndrewAlgo::AndrewHull(arr);
		}
		t2=clock();
		
		double time=((double)(t2-t1))/(CLOCKS_PER_SEC);
		
	//}
	
	
    ofstream output;				/**< The output file containing the set of points in .ch format */
    output.open("convexhull_output.ch");
    output << "CH\n";
    output << n << " " << ret.size() << "\n";
    for(int i=0;i<arr.size();i++)
        output << arr[i].x << " "<<arr[i].y<< " 0" << endl;


    for(int i=0;i<ret.size();i++)
    {

        for(int j=0;j<arr.size();j++)
        {
            if(arr[j].x==ret[i].x && arr[j].y==ret[i].y)
            {
                output << j << " ";
                break;
            }
        }
    }

    output.close();	
    
    /*cout << endl << endl << "OUTPUT" << endl;
    for(int i=0;i<ret.size();i++)
    	cout << ret[i].x << " " << ret[i].y << endl;
   */
   // for(int l=0;l<15;l++)
   // 	cout << input[l] << " " << time[l] << endl;
   cout << "Time taken by the algorithm is " << time << " seconds" <<  endl; 
    printf("\nOpen the file \"convexhull_output.ch\" in the visualization tool to view the output\n");
    return 0;
	
}
