#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct MonkeyNode {
	int FinalRemainingBananas;
	int MinimumNumber;
};

int SuperMonkey(vector<MonkeyNode*>& DynamicOne, int OurValue, vector<int>& NumOfBitesOfEachMonkey, int min)
{
	if (DynamicOne[OurValue]->MinimumNumber != 0)
	{
		return DynamicOne[OurValue]->MinimumNumber;
	}
	if (OurValue < min)
	{
		DynamicOne[OurValue]->FinalRemainingBananas = OurValue;
		DynamicOne[OurValue]->MinimumNumber = 0;
		return 0;
	}
	int sum;
	for (int i = 0; i < NumOfBitesOfEachMonkey.size(); i++)
	{
		if (OurValue >= NumOfBitesOfEachMonkey[i])
		{
			sum = 1 + SuperMonkey(DynamicOne, OurValue - NumOfBitesOfEachMonkey[i], NumOfBitesOfEachMonkey, min);
			DynamicOne[OurValue]->MinimumNumber = sum;
		}
	}

	for (int i = 0; i < NumOfBitesOfEachMonkey.size(); i++)
	{
		if (OurValue == NumOfBitesOfEachMonkey[i])
		{
			DynamicOne[OurValue]->MinimumNumber = 1;
			DynamicOne[OurValue]->FinalRemainingBananas = 0;
			return DynamicOne[OurValue]->MinimumNumber;
		}
	}
	int minn;
	for (int i = 0; i < NumOfBitesOfEachMonkey.size(); i++)
	{
		if (OurValue >= NumOfBitesOfEachMonkey[i])
		{
			minn = OurValue - NumOfBitesOfEachMonkey[i];
			break;
		}
	}
	for (int i = 1; i < NumOfBitesOfEachMonkey.size(); i++)
	{
		if (OurValue >= NumOfBitesOfEachMonkey[i])
		{
			if (DynamicOne[OurValue - NumOfBitesOfEachMonkey[i]]->FinalRemainingBananas < DynamicOne[minn]->FinalRemainingBananas)
				minn = OurValue - NumOfBitesOfEachMonkey[i];

		}
	}

	int counter = 0;
	int OurValues = DynamicOne[minn]->FinalRemainingBananas;

	DynamicOne[OurValue]->MinimumNumber = DynamicOne[minn]->MinimumNumber + 1;
	DynamicOne[OurValue]->FinalRemainingBananas = DynamicOne[minn]->FinalRemainingBananas;

	for (int i = 0; i < NumOfBitesOfEachMonkey.size(); i++)
	{
		if (OurValue >= NumOfBitesOfEachMonkey[i])
		{
			if (DynamicOne[OurValue - NumOfBitesOfEachMonkey[i]]->FinalRemainingBananas == OurValues)
				counter++;
		}
	}
	if (counter > 1)
	{
		for (int i = 0; i < NumOfBitesOfEachMonkey.size(); i++)
		{
			if (OurValue >= NumOfBitesOfEachMonkey[i])
			{
				if (DynamicOne[OurValue - NumOfBitesOfEachMonkey[i]]->MinimumNumber < DynamicOne[minn]->MinimumNumber && DynamicOne[OurValue - NumOfBitesOfEachMonkey[i]]->FinalRemainingBananas == OurValues)
					minn = OurValue - NumOfBitesOfEachMonkey[i];

			}
		}
	}

	DynamicOne[OurValue]->MinimumNumber = DynamicOne[minn]->MinimumNumber + 1;
	DynamicOne[OurValue]->FinalRemainingBananas = DynamicOne[minn]->FinalRemainingBananas;
	return DynamicOne[OurValue]->MinimumNumber;
}

int GetMinimum(vector<int>Arr)
{
	int min = Arr[0];
	for (int i = 1; i < Arr.size(); i++)
	{
		if (Arr[i] < min)
			min = Arr[i];
	}
	return min;
}



int main()
{
	int NumberOfBuckets, NumberOfMonkey;
	vector<int>NumOfBananasInBucket;
	vector<int>NumOfBitesOfEachMonkey;
	cin >> NumberOfBuckets;
	for (int i = 0; i < NumberOfBuckets; i++)
	{
		int value;
		cin >> value;
		NumOfBananasInBucket.push_back(value);
	}
	cin >> NumberOfMonkey;
	for (int i = 0; i < NumberOfMonkey; i++)
	{
		int value;
		cin >> value;
		if (value == 0)
			continue;
		NumOfBitesOfEachMonkey.push_back(value);
	}
	vector<MonkeyNode*>DynamicVector;
	for (int i = 0; i < 100000; i++)
	{
		MonkeyNode* NewOne = new MonkeyNode{ 0,0 };
		DynamicVector.push_back(NewOne);
	}
	if (NumOfBitesOfEachMonkey.size() == 0)
	{
		for (int i = 0; i < NumberOfBuckets; i++)
		{
			cout << NumOfBananasInBucket[i] << " " << 0 << endl;
		}
		return 0;
	}
	int minimum = GetMinimum(NumOfBitesOfEachMonkey);
	for (int i = 0; i < NumberOfBuckets; i++)
	{
		int k = SuperMonkey(DynamicVector, NumOfBananasInBucket[i], NumOfBitesOfEachMonkey, minimum);

		cout << DynamicVector[NumOfBananasInBucket[i]]->FinalRemainingBananas << " " << DynamicVector[NumOfBananasInBucket[i]]->MinimumNumber << endl;
	}

	return 0;
}