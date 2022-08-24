#include <iostream>
#include <cmath>

using namespace std;

class Event
{
private:
	char Event_Name[200];
	char CustomerName[200];
	float GuestCount;
	float EventDuration;
	int NumberOfWaiters;
	float CostPerWaiter;
	float FoodCost;
	float TotalCost;
	float DepositAmount;


public:
	void getEventName()
	{
		cout << "Enter the name of the event : \n";
		cin.getline(Event_Name, 200);
		bool flag = true;
		do {
			if (Event_Name[0] == '\0') // if user pressed enter by mistake
			{
				cout << "Enter a valid name of the event : \n";
				cin.getline(Event_Name, 200);
			}
			else flag = false;
		} while (flag);
	}

	void  getCustomerName()
	{
		cout << "Enter the customer's first and last name : \n";
		cin.getline(CustomerName, 200);
		bool flag = true;
		do {
			if (CustomerName[0] == '\0') // if user pressed enter by mistake
			{
				cout << "Enter a valid name of the costumer : \n";
				cin.getline(CustomerName, 200);
			}
			else flag = false;
		} while (flag);
	}

	void getGuestCount()
	{
		bool flag = true;
		cout << "Enter the number of guests : \n";
		do {

			cin >> GuestCount;

			if (cin.fail())//where this code give true if user entered a character or text
			{
				cout << "enter a valid digit number" << endl;
				cin.clear();//to clear what the user enter
				cin.ignore(10, '\n');//to avoid the infinite loop
			}
			else if (GuestCount <= 0)// if user entered a zero or a negative number
			{
				cout << "Enter a positive Non-zero number \n";

			}

			else flag = false;
		} while (flag);

		int l;
		do {
			l = floor(GuestCount); // if user entered guest numbers a fraction not an integer
			if ((l - GuestCount) != 0)
			{
				cout << "Enter an integer (whole number) not a fraction : \n";
				cin >> GuestCount;  // retake the value from user until it's an integer number
			}
			else
				break; // exit condition
		} while (true);
	}

	void  getEventDuration()
	{
		bool flag = true;
		cout << "Enter the number of minutes in the event : \n";
		do {

			cin >> EventDuration;
			EventDuration = (ceil(EventDuration)); //to approximate value to next int value

			if (cin.fail())//where this code give true if user entered a character or text
			{
				cout << "enter a valid digit number " << endl;
				cin.clear();//to clear what the user enter
				cin.ignore(10, '\n');//to avoid the infinite loop
			}
			else if (EventDuration <= 0)// if user entered a zero or a negative number
			{
				cout << "Enter a positive Non-zero number \n";

			}

			else flag = false;
		} while (flag);

		int insure;
		if (EventDuration < 15) // to give the user a chance that if he entered a small number i doubt the number and tell the user to check it
		{
			cout << "Are you sure that you entered the event Time :" << EventDuration << " in Minutes ? \n";
			cout << "Enter 1 to insure that you entered correct OR enter 0 to Re-enter the duration again \n";
			cin >> insure;
			if (!insure)

			{
				cout << "Enter the Event's duration : \n";
				cin >> EventDuration;
				EventDuration = (ceil(EventDuration)); //to approximate value to next int value
			}
		}
	}

	void  CalcualteCost()
	{
		int h; // number of hours which will charged for 46.5
		int m;// number of minutes which will remains from the total time after reducing hours
		int payless; // gives a hint to the user that more than 47 min it's better to choose 1 hour instead
		FoodCost = 54.5 * GuestCount;
		NumberOfWaiters = int(ceil(float(GuestCount) / 20));
		h = EventDuration / 60;
		m = EventDuration - 60 * h;
		if (h == 0)  // if the user entered time less than 1 hour he will be charged for 46.5 ( 1 hour cost)
		{
			h = 1; m = 0;
		}
		if (m >= 47)
		{
			cout << "Note that you chose " << h << " hours and " << m << " minutes" << endl;
			cout << "This will charge you more than choosing " << h + 1 << " hours" << endl;
			cout << "If you want to make it " << h + 1 << " hours with less cost Enter 1 or if you want to remain with your time enter 0 " << endl;
			cin >> payless;
			if (payless == 1)
			{
				m = 0; h = h + 1;
			}
		}
		CostPerWaiter = 46.5 * h + m * 1;
		TotalCost = FoodCost + (NumberOfWaiters * CostPerWaiter);
		DepositAmount = 0.25 * TotalCost;

	}

    void PrintInfo()
	{
		cout << endl << "---------------------------------------------" << endl;
		cout << endl << "---------------------------------------------" << endl;
		cout << endl << "---------------------------------------------" << endl;
		cout << Event_Name << " event" << endl;
		cout << "Event estimate for " << CustomerName << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Number of waiter : " << NumberOfWaiters << endl;
		cout << "The cost per waiter : " << CostPerWaiter << endl;
		cout << "The cost for food is : " << FoodCost << endl;
		cout << "Total cost is : " << TotalCost << endl;
		cout << "please provide a 25% deposit to reserve the event" << endl;
		cout << "The deposit needed is : " << DepositAmount;
	}

};

int main()
{
	Event customer;
	customer.getEventName();
	customer.getCustomerName();
	customer.getGuestCount();
	customer.getEventDuration();
	customer.CalcualteCost();
	customer.PrintInfo();

	return 0;
}