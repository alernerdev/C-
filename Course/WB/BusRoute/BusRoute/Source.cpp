#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
int main()
{
	int nops;
	cin >> nops;

	// store a list of stops per bus route
	map<vector<string>, int> stopsToRoute;

	int runningRoutes = 1;

	for (int i = 0; i < nops; i++)
	{
		int numStops;
		cin >> numStops;

		vector<string> stops;
		string stop;
		for (int j = 0; j < numStops; j++)
		{
			cin >> stop;
			stops.push_back(stop);
		}

		int route = stopsToRoute[stops];
		if (route > 0)
		{
			cout << "Already exists for " << route << endl;
		}
		else
		{
			stopsToRoute[stops] = runningRoutes;
			cout << "New bus " << runningRoutes++ << endl;
		}
	}
}