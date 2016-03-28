#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<set>

using namespace std;

class Itemsets {
public:
	set<int> item;
	int supportNum;

	Itemsets(set<int>& _item) {
		item = _item;
		supportNum = 0;
	}

	Itemsets(int i) {
		item.insert(i);
		supportNum = 0;
	}

};

int split(const string& text, string& separators, set<int>& transaction);
void showTrans(vector<set<int>> transaction);
bool scanTransaction(set<int> transaction, Itemsets& C);
void prunningC(vector<Itemsets> C, vector<Itemsets>& L, double minSupport, int transactionSize);
void showCorL(vector<Itemsets> CorL, int transactionSize);
void selfJoinL(vector<Itemsets> L, vector<Itemsets>& C,int k);
void scanC(vector<set<int>> transaction, vector<Itemsets> &C);
void makeRule(set<int> initial, set<set<int>> subsets, vector<vector<Itemsets>> C,int transactionSize,ofstream& fileOut);
void findSubsets(set<set<int>> &sets, set<int> initial);



int main(int argc, char* argv[])
{
	double minSupport;
	int transactionSize=0;

	char* fileInName;
	char* fileOutName;

	
	ifstream fileIn;
	ofstream fileOut;

	vector<set<int>> transaction;
	vector<vector<Itemsets>> C;
	vector<vector<Itemsets>> L;


	if (argc == 4) {
		minSupport = atof(argv[1]);
		fileInName = argv[2];
		fileOutName = argv[3];
	}
	else {
		cout << "argument error" << endl;
		return -1;
	}

	fileIn.open(fileInName, ios::in);
	fileOut.open(fileOutName, ios::out);

	string fileLine;
	string del = "\t";
	

	int max=0;
	int num=0;

	while (fileIn.good()) {
		set<int> tmpset;
		getline(fileIn, fileLine);
		transactionSize++;
		if(max < (num = split(fileLine, del, tmpset)))max = num;
		transaction.push_back(tmpset);
	}


	//initialize C0
	vector<Itemsets> C0;
	C.push_back(C0);
	

	for (int i = 1; i <= max; i++) {
		
		Itemsets tmp(i);
														// C0 ��ĳ��
		for (unsigned int j = 0; j < transaction.size(); j++) {
			scanTransaction(transaction[j],tmp);
		}

		C[0].push_back(tmp);							// STL�� elem�� ���� ���� �� ������ �Ѿ  
	}

	int k=0;  // generation of C or L

	do {
		//cout << "------------------[ " << k + 1 << " ]------------------" << endl;
		vector<Itemsets> tmpL;
		L.push_back(tmpL);
		prunningC(C[k],L[k],minSupport,transactionSize); //make L
		
		if (L[k].size() < 2)break;
		
		vector<Itemsets> tmpC;
		C.push_back(tmpC);
		selfJoinL(L[k],C[k+1],k);
		scanC(transaction, C[k + 1]);                    //make C
		k = k + 1;

	} while (true);


	for (unsigned int j = 1;j< L.size();j++) {
		for (unsigned int i = 0; i < L[j].size(); i++) {
			set<set<int>> subsets;
			findSubsets(subsets, L[j][i].item);
			makeRule(L[j][i].item, subsets, C, transactionSize, fileOut);
		}
	}


	/*
	cout << "max = " << max << endl;
	cout << minSupport << endl;
	cout << fileInName << endl;
	cout << fileOutName << endl;
	*/

	return 0;
}
void makeRule(set<int> initial, set<set<int>> subsets,vector<vector<Itemsets>> C,int transactionSize,ofstream& fileOut)
{
	
	
	set<set<int>>::iterator i = subsets.begin();
	
	int AUB;

	for (unsigned int x = 0; x < C[initial.size() - 1].size(); x++) {
		if (C[initial.size() - 1][x].item == initial)AUB = C[initial.size() - 1][x].supportNum;
	}

	for (; i != subsets.end(); i++) 
	{
		int A;  // A -> B,  P(B|A)  
		
		set<int> copySet(initial); //copy set

		if ((*i).size() != initial.size()) {
			
			for (unsigned int x = 0; x < C[(*i).size() - 1].size(); x++) {
				if (C[(*i).size() - 1][x].item == *i)A = C[(*i).size() - 1][x].supportNum;
			}
			
			set<int>::iterator j = (*i).begin();
			cout << "{";
			fileOut<< "{";
			for (; j != (*i).end(); j++) {
				copySet.erase((*j));
				
				if (j != (*i).begin()) {
					fileOut<< ",";
					cout << ",";
				}
				cout << *j;
				fileOut << *j;
			}
			cout << "}\t";
			fileOut<< "}\t";

			set<int>::iterator k = copySet.begin();
			
			cout << "{";
			fileOut<< "{";
			for (; k != copySet.end(); k++) {
				if (k != copySet.begin()) {
					fileOut<< ",";
					cout << ",";
				}
				cout << *k;
				fileOut << *k;
			}
			cout << "}";
			cout << "\t" << setprecision(4) << AUB*100 / (double)transactionSize;
			cout << "\t" << setprecision(4) << AUB*100 / (double)A << endl;
			fileOut<< "}";
			fileOut << "\t" << setprecision(4) << AUB * 100 / (double)transactionSize;
			fileOut << "\t" << setprecision(4) << AUB * 100 / (double)A << endl;
		}
	}
}

void findSubsets(set<set<int>> &sets, set<int> initial)
{
	if (initial.empty())
		return;

	sets.insert(initial);//save the current set in the set of sets

	set<int>::iterator i = initial.begin();
	for (; i != initial.end(); i++)//for each item in the set
	{
		set<int> new_set(initial);//copy the set
		new_set.erase(new_set.find(*i));//remove the current item
		findSubsets(sets, new_set);//recursion ...
	}
}
void scanC(vector<set<int>> transaction,vector<Itemsets> &C) 
{
	for (unsigned int i = 0; i < C.size() ; i++) {

		// C0 ��ĳ��
		for (unsigned int j = 0; j < transaction.size(); j++) {
			scanTransaction(transaction[j], C[i]);
		}

							// STL�� elem�� ���� ���� �� ������ �Ѿ  
	}
}

void selfJoinL(vector<Itemsets> L,vector<Itemsets>& C,int k) 
{
	bool check= true;
	
	for (unsigned int i = 0; i < L.size(); i++) {
		for (unsigned int j = i + 1; j < L.size(); j++) {
			//set��ġ��
			Itemsets tmp(L[i].item); //���� L�� �׸� 
			tmp.item.insert(L[j].item.begin(), L[j].item.end()); // �ٸ� L+a �׸��� ��ģ��, 
			
			if (tmp.item.size() == k + 2) { // k�� �˸´� ���� �� item ���϶��� ����

				for (unsigned int n = 0; n < C.size(); n++) {
					if (C[n].item == tmp.item) {
						check = false;
						break;
					}
				}

				if (check)C.push_back(tmp);
				check = true;
			}

			// ���� ���Ϳ� ���� ���Ұ� �ִ� 
			
		}
	}
	/*
	for (int i = 0; i < C.size(); i++) {

		set<int>::iterator iter;

		for (iter = C[i].item.begin(); iter != C[i].item.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;

	}
	*/
	

}

void prunningC(vector<Itemsets> C, vector<Itemsets>& L,double minSupport,int transactionSize) 
{
	
	for (unsigned int i = 0; i < C.size(); i++) {
		if (C[i].supportNum/(double)transactionSize >= minSupport/100) {
			L.push_back(C[i]);
		}
	}

	//showCorL(L, transactionSize);
}

bool scanTransaction(set<int> transaction, Itemsets& C) 
{
	
	set<int>::iterator iter;
	set<int>::iterator pos;
	bool flag = true;

	for (iter = C.item.begin(); iter != C.item.end(); ++iter) {
		pos = transaction.find(*iter); // transaction�� item elem�� �����ϴ��� Ȯ��
		if (pos == transaction.end()) {
			flag = false;
			break;
		}
	}

	if(flag)C.supportNum++;

	return flag;
}

int split(const string& text, string& separators, set<int>& transaction) {
	
	int n = text.length();
	int start, stop;
	int max = 0;
	int num = 0;
	
	start = text.find_first_not_of(separators);
	
	while ((start >= 0) && (start < n)) {
		stop = text.find_first_of(separators, start);
		
		if ((stop < 0) || (stop > n))stop = n;
		
		num = atoi(text.substr(start, stop - start).c_str());
		if (max < num) {
			max = num;
		}

		transaction.insert(num);
		start = text.find_first_not_of(separators, stop + 1);
	}
	return max;
}

void showTrans(vector<set<int>> transaction)
{
	for (unsigned int i = 0; i < transaction.size(); i++) {

		set<int>::iterator iter;

		for (iter = transaction[i].begin(); iter != transaction[i].end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;

	}
}

void showCorL(vector<Itemsets> CorL,int transactionSize) {

	for (unsigned int i = 0; i < CorL.size(); i++) {

		set<int>::iterator iter;
		cout << " { ";
		for (iter = CorL[i].item.begin(); iter != CorL[i].item.end(); ++iter) {
			cout << *iter<<" ";
		}
		cout << " } ";
		cout << "sup : " << CorL[i].supportNum / (double)transactionSize * 100 << endl;

	}
}