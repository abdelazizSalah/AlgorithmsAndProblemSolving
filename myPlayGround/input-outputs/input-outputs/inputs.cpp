#include <fstream>
#include <iostream>

using namespace std;
int main()
{
	ifstream file;
	file.open("InputSample.txt"); // opening the file 

	if (!file.is_open()) // if it can't open it
	{
		cout << "can't open\n";
		return -1;
	}

	int NoOfMount; // no of mount rovers
	file >> NoOfMount;
	int* Mspeed = new int[NoOfMount]; // array to store the speed
	for (int i = 0; i < NoOfMount; i++)
	{
		file >> Mspeed[i];
	}

	// no of emerg rovers
	int NoOfEmerg;
	file >> NoOfEmerg;
	int* Espeed = new int[NoOfEmerg];
	for (int i = 0; i < NoOfEmerg; i++)
	{
		file >> Espeed[i];
	}

	// no of pol rovers
	int NoOfPol;
	file >> NoOfPol;
	int* Pspeed = new int[NoOfPol];
	for (int i = 0; i < NoOfPol; i++)
	{
		file >> Pspeed[i];
	}

	//no of missions before checkup
	int NOMBC;
	file >> NOMBC;

	// static member function
	//Rover::set_N(NOMBC);

	//checkup durations 
	int CM, CP, CE;
	file >> CM >> CP >> CE;

	//Autop -> number of days after which the mountanious mission is automatically promoted 
	int AutoP = 0;
	file >> AutoP;

	// no of events in the file 
	int Eventsnum = 0;
	file >> Eventsnum;

	////creation of Mrovers
	//for (size_t i = 0; i < NoOfMount; i++)
	//{
	//	MRover* Mptr = new MRover(Mspeed[i], CM);
	//	AddRover(Mptr);
	//	Mptr->set_M_checkup(CM);
	//}

	////creation of Provers
	//for (size_t i = 0; i < NoOfPol; i++)
	//{
	//	PRover* Pptr = new PRover(Pspeed[i], CM);
	//	AddRover(Pptr);
	//	Pptr->set_P_checkup(CP);
	//}

	////creation of Erovers
	//for (size_t i = 0; i < NoOfEmerg; i++)
	//{
	//	ERover* Eptr = new ERover(Espeed[i], CM);
	//	AddRover(Eptr);
	//	Eptr->set_E_checkup(CE);
	//}

	//iterating on all events
	for (size_t i = 0; i < Eventsnum; i++)
	{
		char typeEv;   // type of the event
		file >> typeEv;

		if (typeEv == 'F' || typeEv == 'f')  // formulation event
		{

			//READING DATA
			char typeM; // type of the missions 
			file >> typeM;

			int eventday;
			file >> eventday;

			int ID;  //no more than one mission can have the same ID
			file >> ID;

			int TLOC; //targetLoc
			file >> TLOC;

			int MDUR; // no of days needed to fulfill the missions 
			file >> MDUR;

			int SIG; // mission significance 
			file >> SIG;

			////DETERMINE WHICH TYPE SHOULD WORK ON
			//if (typeM == 'M' || typeM == 'm') // mount
			//{
			//	//Formulation(TYPE rtype, int rTLOG, int rSIG, int rMDUR, int id, int ED, MarsStation * rMrsPtr);
			//	Event* Fptr = new Formulation(MOUNTAINOUS, TLOC, SIG, MDUR, ID, eventday, this);
			//	Events.enqueue(Fptr);
			//}
			//else if (typeM == 'P' || typeM == 'p') // polar
			//{
			//	Event* Fptr = new Formulation(POLAR, TLOC, SIG, MDUR, ID, eventday, this);
			//	Events.enqueue(Fptr);
			//}
			//else if (typeM == 'E' || typeM == 'e') // emerg
			//{
			//	/*Event* Fptr = new Formulation(EMERGENCY, TLOC, SIG, MDUR, ID, eventday, this);
			//	Events.enqueue(Fptr);*/
			//}
			continue;
		}

		else if (typeEv == 'X' || typeEv == 'x') //cancelation event
		{
			int eventday;
			file >> eventday;
			int ID;  //no more than one mission can have the same ID
			file >> ID;
			/*		Event* Cptr = new Cancelation(ID, eventday, this);
					Events.enqueue(Cptr);*/
			continue;
		}

		else if (typeEv == 'P' || typeEv == 'p') // promotion event
		{
			int eventday;
			file >> eventday;
			int ID;  //no more than one mission can have the same ID
			file >> ID;
			//Event* Pptr = new Promotion(ID, eventday, this); // creat event and enqueue in the lis
			//Events.enqueue(Pptr);
			//continue;
		}


		

	}
	file.close(); // closing the file 
	return 0;
	// >> cin 
	// << cout  
	//ofstream zuzFile; // da ana keda 3mlt object mn outfile akny 3mlt file gded b shift new
	//zuzFile.open("zuz.txt"); // open de function bft7 beha el malaf w hya bta5od parameter fl constructor ba3aha string w elly byb2a esm el file
	//zuzFile << "we write it inside the file"; // lama t3ml run htla2y el el file et3ml w gowah mktob el enta katbo da
	///////////////////////////////////////////////////////////// mmkn bdl el .doc tkhleh .txt aw .ay 7aga baa
	//zuzFile << "\nnow say good bye bro";

	////functions to be known
	////1-isopen --> de btt2kd el file bt3k mfti7 wla laa
	//if (!zuzFile.is_open())
	//{
	//	cout << "is closed"; // hy2olk eno closed 34an ana katb da b3d el zuzfile.close elly b2fl beha el file bta3y aslun
	//}

	////2-lama tktb ctrl + z by2fl el file 
	//cout << "\nenter the student status";
	//cout << "\npress  ctrl+z to exit";
	//char name[10];
	//int id; 
	//while (cin >> name >> id)
	//{
	//	zuzFile << "\n" << name << " " << id << endl;
	//}
	//zuzFile.close(); // keda bn2fl el file // dayman lazm ne2flo fl akher 

	//	//3-write function -> de bktb beha fl file bta3y 
	////function which accepts 2 parameters
	////1-t7wl el array l array of chars 
	////2-el size bta3 el array 3n tre2 enk tdrb el size bta3 el array * el size of the type 
	//int arr[10];
	//int j = 0;
	//for (int i = 0; i < 10; i++)
	//{
	//	j = i * 10;
	//	arr[i] = j;
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << endl << arr[i] << " ";
	//}
	//ofstream fout("writefunc.txt");

	////reinterpret de bt8yr el type bta3 el arr l char* 
	///*fout.write(reinterpret_cast<char*> (arr), 10 * sizeof(int));*/ //or we can make it in this form 
	//fout.write((char*)arr, sizeof(arr));
	//fout.close();

	////4- reading from the file
	////we need to creat an object from ifstream 
	//int arr2[20]; 
	//int i = 0; 
	//ifstream fin("writefunc.txt", ios::binary); // enta hena bt3ml open automatically
	//fin.read((char*)&arr2, sizeof(arr2));
	//for (int  i = 10; i < 20 ; i++)
	//{
	//	arr2[i] = i * 10;
	//}
	//for (int i = 0; i < 20; i++)
	//{
	//	cout << arr2[i] << endl;
	//}
	//fin.close();

	//return 0; 





	//ofstream file1("zizo.txt");
	//if (!file1.is_open())
	//	cout << "Can't open the file";

	//int x = 10 , y = 14;
	//file1 << x <<' '<< y << endl ;

	//file1.close();


	//cout << x << y; 
	//ifstream file2;
	//file2.open("zizo.txt"); 

	//if (!file2.is_open())
	//	cout << "can't open";

	//file2 >> y >> x; // this is how we read from the files and stores the data inside parameters

	//file2.close(); 

	//cout << endl << x << y;

	//file1.open("zizo.txt" , ios :: app); // this to append not to overwrite
	//if (!file1.is_open())
	//	cout << "can't open the file"; 
	//file1 << " " << x << " " << y;

	//file1.close(); 

	////to start and overwrite 
	//file1.open("zizo.txt");
	//if (!file1.is_open())
	//	cout << "can't open the file";
	//file1 << x << " " << y;

	//file1.close();

	////so this is the method how we deal with files how we insert and how we write and read , howa we can append
	//

	////------------------------------------------------------//
	//// if  we want to creat a file and read and write and append in the same time 
	////1- creat an object from the fstream 
	////2- use the ios and the globle scobe resloution ios :: 

	//fstream generalFile; 
	//generalFile.open("generalFile.txt", ios::in | ios::out | ios::app);

	//generalFile << 11 << "      " << 10;
	//generalFile >> ws >> x; // ws da byms7 kol el white spaces ;

	//generalFile.close(); 

	// // if you want to overwrite over any thing was written :)))))
	//file1.open("generalFile.txt"); 
	//file1 << "clear";

	//file1.close();


	//freopen function is a redirecting function , bt5leny aft7 el file w aktb feh bst5dam el cout  wl cin
	//freopen(textname , mode , stream) ;


	//freopen("zizo.txt", "r", stdin); // keda ha read 
	//cin >> x;

	//freopen("zizo.txt", "w", stdout); // kda  ha write  
	//cout << "my name is zizo salah\n"; 
	//cout << "hello zuz :D \n";
	//
	//


////////////////////////////////////////
//project logic 
	//ifstream file;
	//file.open("InputSample.txt");

	//if (!file.is_open())
	//{
	//	cout << "can't open\n";
	//	return -1;
	//}

	////no of rovers 
	//int NoOfMount, NoOfPol, NoOfEmerg;
	//NoOfEmerg = NoOfMount = NoOfPol = 0; // intialization 

	//file >> NoOfMount >> NoOfPol >> NoOfEmerg;

	////speed of rovers
	//int SM, SP, SE;
	//SM = SP = SE = 0;

	//file >> SM >> SP >> SE;

	////no of missions 
	//int NoOfMissions = 0;
	//file >> NoOfMissions;

	////checkup durations 
	//int CM, CP, CE;
	//CM = CP = CE = 0;

	//file >> CM >> CP >> CE;

	////Autop -> number of days after which the mountanious mission is automatically promoted 
	//int AutoP = 0;

	//file >> AutoP;

	//// no of events in the file 
	//int Eventsnum = 0;

	//file >> Eventsnum;

	//for (int i = 0; i < Eventsnum; i++)
	//{
	//	char typeEv;   // type of the event
	//	file >> typeEv;

	//	if (typeEv == 'F' || typeEv == 'f')  // formulation event
	//	{

	//		//
	//		char typeM; // type of the missions 
	//		file >> typeM;

	//		if (typeM == 'M' || typeM == 'm') // mount
	//		{



	//		}
	//		else if (typeM == 'P' || typeM == 'p') // polar
	//		{


	//		}
	//		else if (typeM == 'E' || typeM == 'e') // emerg
	//		{



	//		}

	//		int eventday;
	//		file >> eventday;


	//		int ID;  //no more than one mission can have the same ID
	//		file >> ID;

	//		int TLOC; //targetLoc
	//		file >> TLOC;

	//		int MDUR; // no of days needed to fulfill the missions 
	//		file >> MDUR;

	//		int SIG; // mission significance 
	//		file >> SIG;

	//		continue;
	//	}

	//	else if (typeEv == 'X' || typeEv == 'x') //cancelation event
	//	{
	//		int eventday;
	//		file >> eventday;
	//		int ID;  //no more than one mission can have the same ID
	//		file >> ID;
	//		continue; // because it will read only two parameters
	//	}

	//	else if (typeEv == 'P' || typeEv == 'p') // promotion event
	//	{
	//		int eventday;
	//		file >> eventday;
	//		int ID;  //no more than one mission can have the same ID
	//		file >> ID;
	//		continue; // because it will read only two parameters
	//	}
	//}

	
}