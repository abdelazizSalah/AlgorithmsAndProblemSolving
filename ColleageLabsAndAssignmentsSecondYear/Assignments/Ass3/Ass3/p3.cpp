#include <bits/stdc++.h>	
using namespace std;
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
using ll = long long;

//for the second tree
struct idNode {
	int id;
	idNode* left;
	idNode* right;

	//constructor
	idNode(int id)
	{
		this->id = id;
		left = nullptr;
		right = nullptr;
	}
};

//for the first tree
struct mainNode {
	mainNode* left;
	mainNode* right;
	idNode* idptr;
	int depkey;

	//constructor
	mainNode(int k)
	{
		left = nullptr;
		right = nullptr;
		idptr = nullptr;
		depkey = k;
	}

};

void insertid(idNode* &ptr, int id)
{
	idNode* dum = ptr;
	idNode* befdum = ptr;
	bool sameid = false;
	while (dum != nullptr)
	{
		if (id < dum->id)
		{
			befdum = dum;
			dum = dum->left;
		}
		else if (id > dum->id)
		{
			befdum = dum;
			dum = dum->right;
		}
		else
		{
			//we should do nothing here
			//we cant insert with same id 
			sameid = true;
		}
	}


	//if first inserted node
	if (!befdum)
		ptr = new idNode(id);

	//if dum = null we should insert in this pos
	else if (!sameid)
	{
		if (id > befdum->id) // insert right
			befdum->right = new idNode(id);
		else
			befdum->left = new idNode(id);
	}
}


void insertmain(mainNode* &head, int k, int id)
{
	mainNode* befdum = head;
	mainNode* dum = head;
	bool equ = false;
	while (dum != nullptr)
	{
		if (k > dum->depkey) // right
		{
			befdum = dum;
			dum = dum->right;
		}
		else if (k < dum->depkey)
		{
			befdum = dum;
			dum = dum->left;
		}
		else // if ==
		{
			befdum = dum;
			equ = true;
			break;
		}
	}
	// when dum = null this mean that this is the pos where i should insert
	if (!befdum) // first inserted node
	{
		head = new mainNode(k);
		insertid(head->idptr, id);
	}
	else if (!equ) // the node is not found
	{
		if (befdum->depkey > k) // insert left
		{
			befdum->left = new mainNode(k);
			insertid(befdum->left->idptr, id);
		}
		else
		{
			befdum->right = new mainNode(k);
			insertid(befdum->right->idptr, id);
		}
	}
	else // the node already exist so we need just to insert in the other tree
		insertid(befdum->idptr, id);
}

ll searchId(idNode* idptr, int id , bool &found)
{
	ll cntr = 1;
	while (idptr && idptr->id != id)
	{
		cntr++;
		if (id > idptr->id) // go right
			idptr = idptr->right;
		else
			idptr = idptr->left;
	}

	if (idptr) found = true;
	else cntr--; //34an lama bwsl l null bzwd 1
	return cntr;
}

void Searchbst(mainNode* head, int dk, int id, ll& counter , bool & found)
{
	ll cntr = 1;
	while (head && head->depkey != dk)
	{
		cntr++;
		if (dk > head->depkey) // go right
			head = head->right;
		else
			head = head->left;
	}

	if (head) // found
		counter = cntr + searchId(head->idptr, id, found); 
	else
		counter = cntr - 1; // 1 34an lma bzor el null ana bzwd 1 mn 3ndy fa ana 3auz ams7o
}


void solve()
{
	int n, q; cin >> n >> q;
	mainNode* head = nullptr;
	while (n--) // building the nested bst
	{
		int dk, id;	cin >> dk >> id;
		insertmain(head, dk, id);
	}

	while (q--)
	{
		//search for the queres
		//1 -> found 0 -> not found
		int dk, id; cin >> dk>> id;
		if (!head)
			cout << 0 <<' '<<0 <<'\n'; // is there is no bst 
		else
		{
			ll counter = 0; 
			bool found = false ;
			Searchbst(head, dk, id , counter , found);
			cout << counter << ' ' << found << '\n'; 
		}
	}

}

int main()
{
	//accepted 1st time :)))))))))))
	fast;
	solve();
	return 0;
}