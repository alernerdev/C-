#pragma once
class CSort
{
public:
	CSort();
	~CSort();
	virtual void Sort(int arr[], int length) = 0;
	virtual void GetStats(int * visitingCount, int * swapCount)
	{
		*visitingCount = m_visitingCount;
		*swapCount = m_swapCount;
	}

protected:
	int m_visitingCount;
	int m_swapCount;
};

