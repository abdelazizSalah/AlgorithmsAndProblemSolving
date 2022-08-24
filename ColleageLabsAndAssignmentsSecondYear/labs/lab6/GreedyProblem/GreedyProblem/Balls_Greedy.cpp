#include <bits/stdc++.h>
using namespace std; 
#define fast ios_base :: sync_with_stdio(0), cin.tie(0) , cout.tie(0)

//three test cases wrong
void solve()
{
	int s, a, b; cin >> s >> a >> b; 
	int dumS = s;
	bool ZF = false; // determine wether we reached zero before of not
	pair<int, pair<int, int>> mx = { -1 ,{-1, INT_MAX} }; // bmax , amax
	int R = INT_MAX;
	int Bballs = 0, Aballs = 0; 
	while (s >= 0)
	{
		R = s % b;
		Bballs = s / b;
		if (R == 0)
		{
			if (!ZF) // lw mknsh fe haga abl keda btwsl l 0 7ot el zero da aham
			{
				mx = { Bballs , {Aballs , 0} };
				ZF = true;
			}
			else if (Bballs > mx.first) // lw el Bballs > maxB
			{
				mx = { Bballs , {Aballs , 0} };
				//if (Aballs > mx.second.first) // w kman el Aballs > maxA yeb2a da a7sn
				//	mx = { Bballs , {Aballs , 0} };
				//else if (Bballs + Aballs > mx.second.first + mx.first) // 3dd el kowar aktur
				//	mx = { Bballs , {Aballs ,0} };
			}
			else if ((Bballs == mx.first && Aballs > mx.second.first)) // 3dd el kowar aktur yeb2a de a7sn
				mx = { Bballs , {Aballs ,0} };


		}
		else if (R < mx.second.second)
		{
			mx = { Bballs , {Aballs , R} };
		}
		else if ((R <= mx.second.second) && (!ZF && Bballs > mx.first)) // 3dd el kowar l B aktur yeb2a de a7sn
			mx = { Bballs , {Aballs , R} };
		else if ((R <= mx.second.second) && ((!ZF) && (Bballs == mx.first) && (Aballs > mx.second.first)))// lw nfs 3dd el Bballs yeb2a ndwr 3l 3ndhom a aktur
			mx = { Bballs , {Aballs , R} };
		s -= a; // each time we take 1 a and if we reached the 0 we store the max value
		Aballs++;
	}

	cout << mx.second.first<< ' ' << mx.first << ' ' << mx.second.second;
}

int main()
{
	fast;
	solve();
	return 0;
}