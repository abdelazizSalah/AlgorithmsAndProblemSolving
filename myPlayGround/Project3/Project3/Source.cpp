//#include <stdio.h>
//#include <stdlib.h>
//#include <bits/stdc++.h>
//using namespace std;
//void To_Lower(char* name, int* size)
//{
//	int i = 0;
//	while (name[i] != '\0')
//	{
//		(*size)++;
//		if (name[i] >= 'A' && name[i] <= 'Z')
//			name[i] += 32;
//		i++;
//	}
//}
//
//int Check(int Smallersize, int Greatersize,string name1, string name2)
//{
//	bool yes = false;
//	int idx = 0;
//	for (int i = 0; i < Greatersize; i++)
//	{
//		if (name1[idx] == name2[i])
//		{
//			idx++;
//			int j = i + 1;
//			while (j < Greatersize)
//			{
//				if (name1[idx] == name2[j])
//					idx++;
//				j++;
//				if (idx == Smallersize)
//				{
//					return 1;
//				}
//			}
//		}
//
//	}
//	return 0;
//}
//int main(int argc, char** argv)
//{
//	char* name1 = argv[1];
//	char* name2 = argv[2];
//
//	//string name1, name2;
//	//cin >> name1 >> name2;
//
//	// making all of them lowercase
//	int size1 = 0, size2 = 0; // to store their size
//	To_Lower(name1, &size1);
//	To_Lower(name2, &size2);
//
//	//depending on the kangaroo we will work
//	if (size2 > size1)
//		cout << Check(size1, size2, name1, name2);
//	else if (size2 < size1)
//		cout << Check(size2, size1, name2, name1);
//	else cout << 0; // if same size
//
//	return 0;
//}