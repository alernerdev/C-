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

			int count;
			for (const auto & route : busToStops)
			{
				count = 0;
				cout << "Bus " << route.first << ": ";
				for (const auto & stopName : route.second)
				{
					if (count != 0)
						cout << " ";

					count++;

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
			if (busToStops.size() == 0 || busToStops.count(busName) == 0)
			{
				cout << "No bus" << endl;
				continue;
			}

			const vector<string> & stops = busToStops[busName];
			int count;
			for (const auto & stopName : stops) // list of stops for that specific bus from the input
			{
				cout << "Stop " << stopName << ": ";
				// and now, given the stop, see what other buses stop here besides the one I am looking at
				if (stopToBuses[stopName].size() == 0 || stopToBuses[stopName].size() == 1)
				{
					cout << "no interchange";
				}
				else
				{
					count = 0;
					const vector<string> & buses = stopToBuses[stopName];
					for (const string & b : buses)
					{
						// check if its the same stop
						if (b == busName)
							continue;

						if (count != 0)
							cout << " ";


						cout << b;
						count++;
					}
				}

				cout << endl;
			}
		}
		else if (op == "BUSES_FOR_STOP")
		{
			string stopName;
			cin >> stopName;
			// stops collection is empty or there is no such key
			if (stopToBuses.size() == 0 || stopToBuses.count(stopName) == 0)
			{
				cout << "No stop" << endl;
				continue;
			}

			int count = 0;
			const vector<string> & buses = stopToBuses[stopName];
			for (const auto & busName : buses)
			{
				if (count != 0)
					cout << " ";

				count++;
				cout << busName;
			}
			cout << endl;
		}
	}
}