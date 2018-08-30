#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;
int main()
{
	int nops;
	cin >> nops;

	// vector of string vectors
	vector<vector<string>> tasks;
	string op;

	int currentMonth = 1; // January
	map<int, int> daysPerMonth = { {1,31}, {2,28}, {3,31},{ 4,30 },{ 5,31 },{ 6,30 },{ 7,31 },{ 8,31 },{ 9,30 },{ 10,31 },{ 11,30 },{ 12,31 } };

	for (int i = 0; i < nops; i++)
	{
		cin >> op;
		if (op == "ADD")
		{
			int day;
			string task;

			cin >> day;
			cin >> task;

			if (tasks.size() == 0)
				tasks.resize(daysPerMonth[currentMonth]);

			// make it zero based
			// list of tasks is space seprated.  Tasks cannot have spaces in the name
			tasks[day - 1].push_back(task);
		}
		else if (op == "NEXT")
		{
			vector<string> v;

			if (currentMonth == 12) 
				currentMonth = 1; // Dec and Jan have the same number of days, dont need o do anything
			else
			{
				// next month has more days than current month
				if (daysPerMonth[currentMonth + 1] > daysPerMonth[currentMonth])
				{
					int daysToAdd = daysPerMonth[currentMonth + 1] - daysPerMonth[currentMonth];
					daysToAdd = abs(daysToAdd);
					for (int j = 0; j < daysToAdd; j++)
					{
						// just add blank tasks for the longer month
						tasks.push_back(v);
					}

				}
				// next month has less days than current month
				else if (daysPerMonth[currentMonth + 1] < daysPerMonth[currentMonth])
				{
					vector<string> t;
					int lastDayNewMonthIndex, tasksToMoveIndex;
					int daysToDelete = daysPerMonth[currentMonth + 1] - daysPerMonth[currentMonth];
					daysToDelete = abs(daysToDelete);

					lastDayNewMonthIndex = daysPerMonth[currentMonth] - 1 - daysToDelete;
					for (int j = 0; j < daysToDelete; j++)
					{
						tasksToMoveIndex = daysPerMonth[currentMonth] - daysToDelete + j;
						t = tasks[tasksToMoveIndex];
						if (t.size() == 0)
						{
							// there is nothing to move
						}
						else
						{
							// there are tasks to move!!! But does the move to the last slot have tasks of its own ?		
							tasks[lastDayNewMonthIndex].insert(end(tasks[lastDayNewMonthIndex]), begin(t), end(t));
						}
					}

					// shrink the tasks list for the month with fewer days
					tasks.resize(tasks.size() - daysToDelete);
				}
				else // equal number of days
				{
					// if same number of days, dont need to do anything
				}

				// next month
				currentMonth++;
			}
		}
		else if (op == "DUMP")
		{
			int day;

			cin >> day;
			cout << tasks[day - 1].size() << " ";

			int count = 0;
			for (const string & s : tasks[day - 1])
			{
				// add space only if there was previous task output
				if (count > 0)
					cout << " " << s;
				else
					cout << s;

				count++;
			}
			cout << endl;
		}
	}
}