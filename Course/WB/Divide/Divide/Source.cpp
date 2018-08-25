#include <iostream> 

using namespace std; 

int main () 
{ 
	double a,b,price,x,y; 
	
	cin >> price >> a >> b >> x >> y; 
	
	if (a >= b)
		return 0;

	if(price > a && price <= b) 
	{ 
		if (x >= 0)
			cout << price *((100.0 - x) / 100.0);
		else
			cout << price;
	} 
	else if(price > b) 
	{ 
		if (y >= 0)
			cout << price*((100.0 - y) / 100.0);
		else
			cout << price;
	} 
	else 
		cout<<price; 

	return 0;
}