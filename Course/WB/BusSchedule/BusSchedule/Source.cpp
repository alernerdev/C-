#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
int main()
{
	int nops;
	cin >> nops;


	// store a list of stops per bus
	map<string, vector<string>> busToStops;
	// and store a list of buses per stop
	map<string, vector<string>> stopToBuses;

	string op;

	for (int i = 0; i < nops; i++)
	{
		cin >> op;
		if (op == "NEW_BUS")
		{
			string busName;
			cin >> busName;

			int stopCount;
			cin >> stopCount;

			// vector whose size is equal to stops count
			vector<string> stops;

			string stopName;
			for (int i = 0; i < stopCount; i++)
			{
				cin >> stopName;
				stops.push_back(stopName); // and fill up the stops

				vector<string> & buses = stopToBuses[stopName];
				buses.push_back(busName);
			}
			busToStops[busName] = stops; // store the vector
		}
		else if (op == "ALL_BUSES")
		{
			if (busToStops.size() == 0)
			{
				cout << "No buses" << endl;
				continue;
			}

			int count = 0;
			for (const auto & route : busToStops)
			{
				cout << "Bus " << route.first << ": ";
				for (const auto & stopName : route.second)
				{
					if (count == 0)
						cout << " ";

					cout << stopName;
				}
				cout << endl;
			}

		}
		else if (op == "STOPS_FOR_BUS")
		{
			string busName;
			cin >> busName;

			// stops collection is empty or there is no such key
			if (busToStops.size() == 0 || busToStops[busName].size() == 0)
			{
				cout << "No bus" << endl;
				continue;
			}

			int count = 0;
			const vector<string> & stops = busToStops[busName];
			for (const auto & stopName : stops)
			{
				cout << "Stop " << stopName << ":" << endl;
				// and now, search through every other bus to see if any of the stops match
				for (const auto & crossBus : stopToBuses)
				{
					cout << " ";
				}
			}
		}
		else if (op == "BUSES_FOR_STOP")
		{
			string stopName;
			cin >> stopName;
			// stops collection is empty or there is no such key
			if (stopToBuses.size() == 0  || stopToBuses[stopName].size() == 0)
			{
				cout << "No stop" << endl;
				continue;
			}
				
			int count = 0;
			const vector<string> & buses = stopToBuses[stopName];
			for (const auto & busName : buses)
			{
				if (count == 0)
					cout << " ";

				cout << busName;
			}
			cout << endl;
		}
	}
}