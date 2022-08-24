#include <iostream>
using namespace std;
// yeb2a eh howa el recursion yasedy ?
// el recursion howa enk t2dr test5dm el function enha tndh nfsha w de btfedk enk bdl ma tst5dm for loops 
// enta mmkn tkhly kol function tendh 3la nafsha bs kol mara bsora as8ar l7d ma twsl lel termination condition 
// tebd2 baa to5rog mn kol function tro7 lel calling point w hakaza
int factorial(int n)
{
	if (n == 1) return 1;
	else
	{
		return(n * factorial(n - 1)); // hya el fekra hena enk badal ma to3od te3ml function b for loop w tdy3 w2t kber enta bt5ly el function kol mara tendh 3la 
		//nfsha kza mara akenkk bzbt 7atet merayten odam b3d , kol mara tndh 3la nfsk el sora bts8r l7d ma tegy mr7la matl2e4 haga khals f twsl lel condition bta3 el termination
	}
}

void frwrdprintarr(int arr[], int n, int start_i = 0)
{
	//hena ana 3auz atb3 el elements bl trteb el mwgoden beh mn odam l wara 
	if (start_i == n) return;
	else {
		cout << arr[start_i] << " ";
		frwrdprintarr(arr, n, start_i + 1); // keda ana htb3 el awl b3den andah 3la el function tany
	}
}

void bckwrdprintarr(int arr[], int n, int start_i = 0)
{
	//hena baa ana 3auz atb3 el elements bltrteb brdo bs mn wra le odam
	//fana h3ml bzbt nfs el logic el fo2 el fr2 eny habdl amakn el call bta3 a5er satren
	if (start_i == n) return;
	else {
		bckwrdprintarr(arr, n, start_i + 1); // keda ana htb3 el awl b3den andah 3la el function tany
		cout << arr[start_i] << " ";
		// Tb eh el fekra ? 
		// el fekra enk keda kol mara abl l cout enta btndh 3la el function fa bltaly el str bta3 el cout da msh bytnfz fa
		// byfdl yzwd l7d ma twsl lel termination condition sa3etha bybd2 yerg3 le str el call  w ynfz wahda wahda b3do 
		// fa keda awl str hytnfz howa el cout bta3 akher element w b3d keda y5rog w ynfz  el cout bta3 el ablo w hakaza w hakaza l7d ma ywsl l awl element
	}
}

int main()
{

	cout << factorial(6) << endl;
	
	int arr[5] = { 4 , 2 , 1 ,6 ,3 };
	frwrdprintarr(arr, 5); //hena ana 7or mmkn ab3tlo start point w mmkn la
	cout << endl;
	bckwrdprintarr(arr, 5);
	return 0; 
}