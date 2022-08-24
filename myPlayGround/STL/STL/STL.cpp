#include <iostream>
using namespace std;
bool Greaterthanthree(int i);
//in order to use any STL u must include them first 
//1- sequence containters
#include <vector>//1 vectors
#include <deque>//2 deque
#include <list>//3 list
#include <forward_list>//4 forward list
#include <utility> //5 pair library

//2- associative containters
#include <set> // 6 sets 
#include <map> // 7 map

//3- unordered associative containers
#include <unordered_map>
#include<unordered_set>

//4- container adapter
#include <stack>
#include<Queue>
#include<concurrent_priority_queue.h>

//algo lib
#include<algorithm>//it is helpful library used to use the build in algotithms
/*-----------------------------------------*/
#include <string>

//advice:
//when you deal with arrays use them global to intialize them automatically with 0 and have no garbage values
int arr2[100];
int freq[100];

struct com
{
	bool operator () (int l, int r) // l w r dol ay 2 numbers inside the queue
	{
		return l < r; // keda hytb3 mn el kber lel soghyr
		//lw 3ksna el operation hykhleh mn el soghyr lel kber
	}
};
int main()
{

	//how to change the color of the console 
	system("color 4"); // according to the number we get the color		   
		 // 1- vectors 
	//vector <int> v1; // object with no constructor
	//vector <int> v2(10); //object with intial size 
	//vector <int> v3(v2); //creating an object using the copy constructor
	//vector <int> v4 = { 1, 3, 4,5, 6, 7, 8 }; // creating an object with  no size then determine its size using the intial given values 
	//Your code here
	//int size = v4.size();
	//int size = v4.size(); 
	//for (int i = 0; i < size; i++)
	//{
	//	int index = i;
	//	for (int j = i + 1; j < size; j++)
	//	{
	//		if (v4[j] > v4[index])
	//			index = j;
	//	}
	//	int swap = v4[index];
	//	v4[index] = v4[i];
	//	v4[i] = swap;
	//}
	//for (auto it : v4)
	//	cout << it << ' ';
	//cout << endl; 
	//
	//int size2 = v4.size();
	//for (int i = 0; i < size2; i++)
	//{
	//	bool swaped = false; 
	//	for (int j = 0; j < size2 - 1; j++)
	//	{
	//		if (v4[j] > v4[j + 1])
	//		{
	//			int swap = v4[j];
	//			v4[j] = v4[j + 1];
	//			v4[j + 1] = swap;
	//			swaped = true; 
	//		}
	//	}
	//	if (!swaped)
	//		break; 
	//}
	//for (auto it : v4)
	//	cout << it << ' ';
	//	
	//cout << endl;
	////reverse loop
	//for (int i = 0; i < size2; i++)
	//{
	//	int swap = v4[size2 - 1];
	//	v4[size2 - 1] = v4[i];
	//	v4[i] = swap;

	//	size2--;
	//}
	//
	//for (auto it : v4)
	//	cout << it << ' ';

	//v1.push_back(5);//inserting new element at the end of the vector
	//v1.erase(v1.end() - 1);// erase removes the element at certain position 
	//v1.emplace_back(6);//same as pushback but it is faster  
	///// <summary>
	///// note that when u use push back the size of the vector is increased up to 1.5 times the old size if the old size was > 3 
	///// </summary>
	//v1.at(0);//it gets the element at that position
	//v1.pop_back(); // it removes the last element
	//v1.begin();//gets the address of the first element ;
	//v1.back(); //returns the last element in the vctor
	//v1.front();//returns the first element of the vector
	//v1.size(); //returns the size of the vector 
	//v1.capacity(); // returns the number of available empty unused places in the vector
	//v1.swap(v2);// it takes another vector as a parameter and it swaps all the elements in the first into the second and all elements in the second into the first
	//v1.cbegin();//return a constantptr to the first element;
	//v1.crbegin();//return a constant reversed ptr to the first element
	//v1.crend(); //returns a constant reversed ptr to the vector
	//v1.cend();//returns a constant ptr to the end of the vector 
	//v1.clear(); // clear the vector
	//v1.resize(10);//it change the size of the vector to the new size 
	//v1.shrink_to_fit(); //remove all excess elements 
	//vector <int> ::iterator it; // iterator is same as a ptr to the TL so we can use it to use the functions 
	//it = v1.begin();
	//v1.insert(it , 5);
	//it = v1.begin();
	//v1.emplace(it + 1, 12);// it takes a pos and val , it is same as the insert but it is faster

	//sort(v4.begin(), v4.end());//sort is a function which use a very fast algorithm which reaches nlogn (maybe heap or quick or shell or any other good tech)
	////to sort descendingly not ascendingle
	//sort(v1.rbegin(), v1.rend()); 

	////auto and for each
	//for (auto it : v4) // inside it, it contains counter and condition 
	//	cout << it <<' '; // auto is an automatic variable which takes the DT of the intial value it is given to it , while the for each is a smart for loop which works until the given list ends, and the intial val of the it is the first element of the given list
	//
	//cout << *min_element(v4.begin(), v4.end());
	//cout << *max_element(v4.begin(), v4.end());
	//
	//auto pair = minmax_element(v4.begin(), v4.end());//it returns both the min and the max as a pair object 
	//cout << *pair.first << ' ' << *pair.second;// the first is the minimum and the second is the max 

	//auto it = find_if(v4.begin(), v4.end(), Greaterthanthree); //the list must be sorted
	//for (; it != v4.end(); it++)
	//	cout << *it << endl;
	//vector <int> v0(7); 

	//int arr[] = { 3 , 3,4 ,2,5 ,5 ,1 };
	//copy(arr, arr + 7, v0.begin()); // it copies the elements from the arr to the v0
	//for (int i = 0; i < v0.size (); i++)
	//	cout << v0[0] << endl; 
	//copy_backward(v0.begin(), v0.end(), v1.end());

	////how to print without using loops?
	//copy(v0.begin(), v0.end(), ostream_iterator<int>(cout, " ")); 
	//copy(arr, arr + 6, ostream_iterator<int>(cout, " "));

	////how to read the input without loops ? 
	//copy(istream_iterator <int>(cin), istream_iterator<int>(), back_inserter(v0)); // the second parameter is a default constructor used to determine when to stop inserting 

	////how to read and print the given input 
	//copy(istream_iterator<int>(cin), istream_iterator <int>(), ostream_iterator<int>(cout, " "));

	////2-Deck
	//deque <char> q1 = { 'a' , 'b' , 'c' , 'd' };
	////deque is same as vector except we have an access on the begining of the list
	//q1.push_front(6); 
	//q1.pop_front(); 

	////3-List -->  doubly linked list 
	////intialization
	//list <int> l = { 1 , 3, 2 ,10 , 32 }; 
	//list <int> l2(20);
	//list<int> l3(l2);
	////functions 
	//l2.push_back(5); //it inserts from the end ;
	//l2.push_front(23);// from the front
	////the complexty for both is o(1)
	//l2.pop_back();
	//l2.pop_front();

	//list <int> ::iterator it = l2.begin(); 
	////for (auto it : l2) ////easy method to print the list
	////	cout << it << endl;
	//for (it; it != l2.end(); it++)
	//	cout << *it << endl;

	//l2.back(); 
	//l2.front();

	//l2.remove(2); //it removes all nodes which contains the val 2
	//l2.erase(l2.begin()); //it removes a certain position
	//l2.erase(l2.begin(), l2.end()); // it removes from intial position to end position, it accepts only the address or iterators
	//auto it = l2.begin(); // mynf34 t3ml it = l2.begin() + 1 msln hydek error brdu
	//it++; 
	//l2.erase(it, l2.end()); // mynf34 enk t2olo l2.end() - 1 hydek error 
	//it = l2.begin();
	//l2.insert(it , 2);//nfs el kalam de btakhod iterator feh el position w el val 

	//it = l2.begin();
	//l2.insert(it, 2, 4);// lw 3auz t5leh ydef kema mo3yna aktur mn mara

	//l2.assign(10, 2); //bt7gz 10 amakn w t7ot kol l values bta3tha = 2 ;

	//l2.empty(); // it returns boolean
	//l2.resize(20); //it changes the size
	//l2.clear(); // destructor which clears the whole list
	//l2.merge(l); // it concatenates 2 lists together // and the data are merged sorted , and the l now will be empty
	//l2.splice(l.begin(), l2);//bya5od mkan mo3yn mn list w yn2lha fl list el tanya ,  w de msh bt3ml sorting , bs l brdo hatb2a empty
	//l2.unique(); // de bt3ml remove l kol el duplicate
	//l2.remove_if(Greaterthanthree);//it accepts a boolean function and removes all the elements which satsifies that condition

	//l2.sort(greater<int>()); // it sorts the list, it is faster than the sorting in the 
	////greater<int> is template function bt5ly el sort yt3ml descending 
	//l2.sort(less<int>()); // de kda ascending aw mmkn tb3to fady khales hyb2a ascending brdu

	//l2.reverse(); // bt3ks el list

	////mfesh random access fl list bs mmkn t3ml iterator t5leh hwa el y3ml el random access da baa
	//auto it = l2.begin(); 
	//it++; 
	//*it = 1000; 
	//for (it = l2.begin(); it != l2.begin(); it++)
	//	cout << *it << endl;

	////forward list 
//	// it is a single linkedlist
//	
//forward_list <int> FL1;
//forward_list <int> FL2(20);
//forward_list <int> FL3 {12 , 13 , 31, 14};
//
////there is no push back because we have only access on the the head 
//FL2.assign(5, 7);// de keda bt7gz 5 amakn w t7ot fehom kolohom rkm 7 
//for(int&x : FL2)
//	cout << x << endl;
//
//FL2.assign({ 4, 12 , 98 });  // kda hyro7 yms7 el 5 amakn el fo2 w y7ot el 3 el t7t dol mknhom
//
//for(int& x : FL2	) // lw 3mltha by value hattb3 brdu bs el fr2 enk msh htb2a 3amel alias
//	cout << x << endl; 
//for (auto it : FL2)
//cout << it << " "; 
//// keda el 2 for loops el fo2 dol nfs el 7aga bs btor2 mokhtlfa 
//// awl wahda ana 3mlt variable w b3to by refenece 34an arbto bl container el m3aya b7es eny m3mlsh mkan gded , akny bzbt b3ml alias gded byshawr 3la nfs el mkan
//// tany wahda b2a ana est5mdt el auto w da 3bara 3n template class bta5od el datatype bta3 ay haga , haga bttshkl ml akher
//FL2.push_front(4); // de hay7otha fe el awl 5ales 
//FL2.pop_front(); // de btshel awl element
//FL2.emplace_front(5); // de zy el push bzbt bs btkon asr3 34an howa byro7 y7otha directly fel memory mn gher ma y3ml operations 3ks el push
//FL2.emplace_after(FL2.begin(), 5); 
//FL2.insert_after(FL2.before_begin(), 12); // keda ana h7ot element f awl mkan 5ales
////mezt el insertafter w el befor begin en da single linkedlist fa ana mb3rfsh arg3 lwra f34an keda bstghl dol eny awsl lel element el abl el mkan el ana 3auzo 
//FL2.insert_after(FL2.begin(), { 12 , 123 , 124 , 12 }); // de keda ana b2dr a7ot aktr mn element msh element wahed bs , y3ny a2dr azwd 3dd ma ana 3auz msh lazm element element, bs el klamm da m3 el insert bs msh el emplace
//
////next de function fl iterator
//auto f = next (FL2.begin()); // next de zy bta3t el linked list de bzbt  enha btgeb el next bta3 el node de
//auto f3 = next(FL2.begin(), 3); // de keda hyro7 yshawr 3la 3 element b3d el begin hyt7rk 3 7rkat
//
//FL2.erase_after(FL2.begin()); // byms7 el element el b3d da
//FL2.erase_after(FL2.before_begin()); // keda hams7 awl element 
//
//FL2.remove(5); // keda hyms7 kol el amakn el leha kemt 5 
//FL2.remove_if([](double n) {return n <= 2; }); // btms7 t7t shrt mo3yn
////ana kda bktb el logic kolo gowa el function nfsha
//
//FL2.splice_after(FL2.before_begin(), FL3); // keda hytb3 kol el elements el gowa FL3 gowa FL2 <--- w FL3 hatb2a fadya 34an byb3t by refrence
//FL3.resize(10,2); //de bt8yr el size
//FL3.empty(); // check wether it is empty or not
//FL3.max_size();
//FL3.merge(FL1); 
//FL3.sort(greater<>());
//FL3.reverse();
//FL3.unique(); //clw fe dublicate byshelhom
//FL3.swap(FL1); 
//FL3.clear();

//// pair	
////string is first while the int is second
//pair <string, int > p1("ahmed", 10); // intialization
//pair <string, int > p2 = make_pair("ahmed", 10); // make pair is a function that change the first and the second
////we can read this pair
//cin >> p1.first >> p2.first >> p2.second >> p2.first;
////and we can intialize them 
//p1.first = "ahmed";
//
////we can make the pair contains 3 items not 2 or 4 not only
//pair < pair<int , double>, pair <char, string>> superpair;
//superpair.first.second = 1003.123; // de keda el double 
//superpair.second.second = "zuzzz"; // de keda el string and so on
//
//
//// el est5dam el asasy baa lel pair enk tst5dmo fe other containers
//vector <pair <int, char>> vp1;
//// 34an tfhm el function pushback en el gyelha pair lazm t3ml 7aga ml tlata dol
//vp1.push_back(make_pair(123, 'c')); 
//vp1.push_back({ 133 , 'a' });
//vp1.push_back(pair <int, char>(111, 's'));
//
////to print the elements of the vector we must determine which element do you want to print or to call
//for (int i = 0; i < vp1.size(); i++)
//{
//	cout << vp1[i].first << ' ' << vp1[i].second;
//}
//
////another method
//for (auto it = vp1.begin(); it != vp1.end(); it++)
//cout << it->first << ' ' << it->second;
//
////by using for each
//for (auto it : vp1)
//cout << it.first << ' ' << it.second;


////associative container 
////set
//set <int> s1{ 3 , 5, 1 , 6  , 0 }; // keda asscendingly
//set <int , greater<>> s2{ 3 , 5, 1 , 6  , 0 }; // keda ana b5leh y3ml sort descendingly
//set <int> s3{ 3 , 5, 1 , 6  , 0 }; // keda asscendingly
//
////for each loop with auto 
//for (auto it : s1)
//cout << it << endl ;  // it here is int not ptr
//
////functions
//s1.begin(); // 1st
//s1.end(); //last
//s1.rend(); //reversed end
//s1.rbegin(); // reversed begin 
//s1.cbegin(); //constant begin
//s1.cend(); // constant end
//s1.crbegin(); 
//s1.crend(); 
//
//s1.empty(); //check
//s1.max_size(); // how many element we can insert in this set 
//s1.clear(); // clear the set
//s1.size();// return the size of the set 
//s1.insert(6); // it insert as sorted element O(log n)
//set<int>::iterator it = s1.begin(); 
//
//s1.emplace_hint(it, 12); // this function accepts 2 parameters -> iterator and the element you want to insert
//
////we can change the insert complexity from O(logn) to O(1)
//
//it = s1.emplace_hint(it, 12);
//it = s1.emplace_hint(it, 7);
//it = s1.emplace_hint(it, 3);
//it = s1.emplace_hint(it, 2);
//
//
////el tre2a el fo2 de bt5leny b3d ma adef el element akhly el iterator yshawr 3la el mkan el gdedfa bt7wl l complexity mn o(logn) to o(1)
////note that emplace function returns pair 
////first -> the element , second -> boolean
//auto it2 = s1.emplace(12);  //it.first -> 12 , it.second -> 0 because 12 is already exists
//
////to remove an element we have 4 methods
////1
//s1.erase(12); 
//
////2
//it = s1.begin(); 
//++++++it; // we can do infinte prefix operations // keda hwa hayshawr 3la 3 element 
//s1.erase(it); //keda hams7 3 element
//
////3
//it = s1.find(7);
//s1.erase(it, s1.end()); // keda howa hyms7 mn awl el it l7d akher el set
//
////4
////de lw ana 3auz ams7 range mo3yn mn ela fahem 
//auto itlow = s1.lower_bound(2); 
//auto itup = s1.upper_bound(3); 
//
//s1.erase(itlow, itup);
//
////swap 
//s1.swap(s3); 
//
//s2.clear(); 
//for (auto s : s1)
//cout << s << endl;
//
////
//////key compare function
//	set <int> s5{ 3 , 5, 1 , 6  , 0 }; // keda asscendingly
//	auto com = s5.key_comp();
//	auto ittttttttttttttt = s5.begin();
//	int c = 6;
//	for (; com(*ittttttttttttttt, c); ittttttttttttttt++) // hena hyfdl yetb3 tol ma el iterator content not equal the value of c
//		cout << *ittttttttttttttt << endl;
//
//	// count function
//	s5.count(0); // if 0 exists in the set it will return 1 if not it returns 0
//
//	auto ittt = s5.equal_range(3); // it returns pair -> the sent value if exists and the first second greater element
//	cout << "-------------" << endl << *ittt.first << ' ' << *ittt.second << endl << "-------------"; // IT PRINTS 1 & 3
//	
//	//multisets allows the redundancy 
//	 
//	multiset<int> ms1{ 10 , 10 , 10 , 3 , 23 , 3, 10 }; 
//	for (auto s : ms1)
//		cout << s << ' '; 

////map p1 
	////we can make it sorted in descending order by this way
	//map<int ,string, greater<>> m1{ {1 , "ahmed" } , {2 , "zuz"} , {3 , "Karim"} }; // intialization

	//for (auto m : m1)
	//	cout << m.first << ' ' << m.second << endl;

	////it allows the random access
	//m1[4] = "nayera";

	////reverse printing
	//map <int, string> ::reverse_iterator it = m1.rbegin();
	//for (; it!=m1.rend(); it++)
	//	cout << it->first << ' ' << it->second << endl; 

	////map is uniqe key container
	////lw edet nfs el key value gdeda hy3ml 3leha overwrite
	//m1[1] = "samy"; 

	////it prints 1 if the key sent exists , 0 otherwise 
	//cout << m1.count(2);  

	////how to insert ?
	////using random access
	//m1[4] = "nayera";

	////using insert
	//m1.insert(pair<int, string> {5, "gogo"});

	////using makepair
	//m1.insert(make_pair(6, "salwa")); 

	////by using curly braces
	//m1.insert({ 7 , "marwa" }); 

	////we use the iterator to increase the efficincy
	//auto et = m1.begin(); 
	//et = m1.insert(et, { 8 , "kareem" }); //insertion efficency -> o(1)
	//et = m1.insert(et, { 9 , "mona" });
	//et = m1.insert(et, { 10 , "hady" });

	////how to insert as range 
	//map<char, int> m2;
	//m2.insert(m1.begin(), m1.find(8)); 	//keda hy7ot elements fe m2 mn awl m1 l7d el element el elkey bt3to = 8 
 //  

	////emplace->knows that we gonna insert pair
	//m2.emplace('s', 12); 
	////emplace doesn't accept iterator  while the emplace iterator does
	//auto ot = m2.begin(); 
	//m2.emplace_hint(ot, 'f', 145); 
	//
	////erasing -> 3 methods
	//m2.erase('f'); // delete using the key

	////delete using iterator
	//ot++; 
	//m2.erase(ot); 	

	////deleting a certain range
	//m2.erase(m2.begin(), m2.find('s'));

	////equal range -> it return map
	//auto p = m2.equal_range('c');  //or 

	////el p de object mt5zn gowaha ptr y3ny lazm tst5dm el dot w b3d keda tst5dm el arrow
	//cout << p.first->first << ' ' << p.second->second << endl; 

	////keycomp
	//auto kcomp = m2.key_comp();
	//auto it = m2.begin(); 
	//char c = 's';
	//for (; kcomp(it->first, c); it++)
	//	cout << it->first << it->second;

	//auto upbound = m2.upper_bound('a');
	//auto lowbound = m2.lower_bound('s'); 
	//m2.erase(upbound, lowbound); 

	////f0r each
	//for (auto m : m2)
	//	cout << m.first << m.second; 
	//
	//m2.empty(); 
	//m2.max_size(); //3dd el 3nasr el t2dr tdefha msh el amakn el fadya
	//m2.size(); //kkam element mawgod fl map
	//map<char, int> m3;
	//m3.swap(m2);
	//m2.clear(); 
	////in maps we can't modify the keys but we can modify the values
	////if we need to allow the redundancy we use the multimap
	//multimap<string, string> mmp;  // we can't use the random access here
	//mmp.insert({ "ahmed", "SF" });

//////maps part 2
//map <string, int> GradeByName; 
//int NoOfStudents;
//cout << "Please enter the number of the students: ";
//cin >> NoOfStudents; 
//cout << "\nPlease Enter The Name Of The Student then his grade\n "; 
//
////intialization and reading data;
//for (int i = 0; i < NoOfStudents; i++)
//{
//	cout << "Name: ";
//	string nm;
//	cin >> nm; 
//	cout << "Grade: "; 
//	int grd;
//	cin >> grd;
//	GradeByName.insert({nm , grd});
//}

////how to know the frequence ?
////we can make a function that compares each element with the next to it if they were sorted then count the redundancy
//int arr[] = { 3 , 3 ,1 ,2 , 2 }; 
//int noofelements = sizeof(arr) / sizeof(arr[0]);
//sort(arr, arr + noofelements); 
//int counter = 1;
//for (int i = 0; i < noofelements; i++)
//{
//	if (arr[i] == arr[i + 1] )
//		counter++;
//	else
//	{
//		cout<<arr[i] <<"=>" << counter << endl;
//		counter = 1;
//	}
//}
////another method by using the two arrays
//int n;
//cin >> n; 
//for (int i = 0; i < n; i++)
//{
//	cin >> arr2[i]; 
//	freq[arr2[i]] ++; 
//}
//
//sort(arr2, arr2 + n); 
//
//for (int i = 0; i < n; i++)
//	if (arr2[i] != arr2[i + 1])
//		cout << arr2[i] << "=>" << freq[arr2[i]] << endl;

//another solution using map
//this is better solution
//map <int, int> m; 
//cout << "enter the number of elements: "; 
//int s; 
//cin >> s; 
//for (int i = 0; i < s; i++)
//{
//	int n; 
//	cin >> n; 
//	m[n] ++;
//}
//// now we don't need to sort because the map is already sorted
////print elements using for each loop
//for (auto m : m)
//	cout << m.first<< "=>" << m.second << endl;



	////stack
////we can determine the container we wanna use in the stack
////y3ny ana mmkn akhly el stack 3la shakl list aw vector aw deque aw ay haga ana 3auzha
//	stack<string, list<string>> s;
//	s.push("alooo");
//	s.emplace("adkhlooo");
//	s.pop();
//
//	for (int i = 0; !s.empty(); i++)
//	{
//		cout << s.top();
//	}
//
//	//we can insert some elements without repeating the code using the for each loop
//	for (auto ss : { "Aa" , "bb" , "c" , "kkk" })
//		s.push(ss);
//
//	while (!s.empty())
//	{
//		cout << s.top();
//		s.pop();
//	}
//properties -> fast insert , remove and size -> o(1)

////queue -> can be list or deque only
//	queue<int , deque<int>> q1;
//	queue<int, list<int> > q2; 
//	q1.push(12);
//	q1.emplace(10);
//	q1.pop();
//	while (!q1.empty())
//	{
//		cout << q1.front();
//		q1.pop();
//	}
//	//inserting using for each
//	for (auto ss : { 1 , 2 , 3, 4, 5 })
//		q1.push(ss);
//	//properties -> fast insert and remove -> o(1)

////priority queue
////this is same as queue except that we enqueue according to the certain priority
//priority_queue<int , vector<int> , less<>> pq1; //-> descending by defaul if wanna reverse use greater<> 
//pq1.emplace(12); 
//pq1.push(20); 
//pq1.pop();
//
////how to creat my prioty? 
////by creating a certain struct and send it instead of the less <> 
//priority_queue<int, com> pq2; 
//for (auto ss : { 11 , 14 ,15 , 102 })
//	pq2.push(ss);  // keda hy3ml insert 3la 7sb el priority el ana 3amlha
////properties of Pq
////add remove->o(log n)
////min-max ->o(1)

////unordered containers 
////they depends on the hash tables & hash functions
////1- unorderedset->they are not sorted
//	unordered_set<string> us({ "ahmed" , "salem" });
//	for (auto us : us)
//		cout << us; 
//	//iterator
//	unordered_set<string> ::iterator it; 
//	//functions
//	us.bucket("ahmed"); // -> it returns the number of the bucket which contains certain element
//	us.insert("mona"); // it inserts new element
//	//us.swap() -> swaps 2 uosets together
//	us.find("mona"); // finds certain element and return the bucket number
//	us.clear(); // clears the set
//	us.begin(); //->
//	us.bucket_count(); //the total number of buckets exists
//	us.load_factor(); // it returns the max number of buckets that can be stored in certain bucket
//	//load factor equation -> size /  bucket count
//	
//	//if all elements have been stored in the same bucket use the rehash function
//	us.rehash(100); 
//	//properties of the unordered container
//	//add - delete - search -> O(1)
//	//the element values can't be changed 
//  //keys can't be changed also


	return 0;
 }
bool Greaterthanthree(int i)
{
	return i > 3;
}