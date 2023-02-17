//thư viện cần dùng
#include<iostream>

using namespace std;

class Bank {
public:
	int domination;
	int quantity;
};

//khai báo các CTDL để tổ chức danh sách liên kết
class Node {
public:
	Bank data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
public:
	//operations of List ADT
	LinkedList();
	~LinkedList();
	Node* Insert(int, Bank);
	Node* AddQuantity(Bank);
	int Delete(Bank);
	Node* Find(int);
	void Print();
	void WithDraw(int);
	void WithDraw2(int);
};

//chương trình chính (bắt buộc phải có)
int main() {
	LinkedList lst1;
	int n = 5 ;
	int x[] = {20000,50000,100000,200000,500000 };
	for (int i = 0; i < n; i++) {
		Bank Value = { x[i],i + 5 };
		lst1.Insert(i, Value);
	}
	lst1.Print();
	Bank FiveHG = { 100000,10 };
	lst1.AddQuantity(FiveHG);
	lst1.Print();
	lst1.WithDraw2(10000000);
	lst1.Print();
	return 0;
}

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::~LinkedList() {}

Node* LinkedList::Insert(int index, Bank value) {
	int currIndex = 1;
	Node* currNode = head;
	if (index < 0) return NULL;
	while (currNode && index > currIndex) {
		currNode = currNode->next;
		currIndex++;
	}

	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;

	if (index == 0) {
		//insert new node at front
		newNode->next = head;
		head = newNode;
	}
	if (currNode == NULL) {
		//index is invalid
		return NULL;
	}

	if (index > 0) {
		//insert new node at mid or back
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	cout << "Insert " << value.domination << " at position " << index << " of list" << endl;
	return newNode;
}
void LinkedList::Print() {
	if (head == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		Node* currNode = head;
		while (currNode) {
			cout << " --> Domination: " << currNode->data.domination << " VND -- Quantity:" << currNode->data.quantity << endl;
			currNode = currNode->next;
		}
		cout << "NULL" << endl;
	}
}
int LinkedList::Delete(Bank x) {
	//find Node to be deleted
	Node* prevNode = NULL;
	Node* currNode = NULL;
	int currIndex = 1;
	currNode = head;
	while (currNode && currNode->data.domination != x.domination) {
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	//delete Node if found
	if (currNode) {
		if (prevNode) {
			//currNode is not the first one
			prevNode->next = currNode->next;
			delete currNode;
		}
		else {
			//currNode is the first
			head = currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	else {
		return 0;
	}
}
Node* LinkedList::Find(int domination) {
	Node* currNode = head;
	while (currNode && currNode->data.domination != domination) {
		currNode = currNode->next;
	}
	return currNode;
}

Node* LinkedList::AddQuantity(Bank value) {
	Node* currNode = head;
	while (currNode && currNode->data.domination != value.domination) {
		currNode = currNode->next;
	}
	if (currNode == NULL) {
		return NULL;
	}
	else {
		currNode->data.quantity = currNode->data.quantity + value.quantity;
		return currNode;
	}
}

void LinkedList::WithDraw(int money) {
	cout << "Amount you want to withdraw: " << money<<" VND."<<endl;
	if (money % 20000 > 0) {
		cout << "There's no domination that you can withdraw." << endl;
	}
	else {
		if (money >= 500000) {
			Node* FiveHK = Find(500000);
			int WD_quantity = money / 500000;
			if (FiveHK->data.quantity == 0) {
				;
			}
			else {
				if (WD_quantity <= FiveHK->data.quantity) {
					FiveHK->data.quantity = FiveHK->data.quantity - WD_quantity;
				}
				else {
					WD_quantity = FiveHK->data.quantity;
					FiveHK->data.quantity = 0;
				}
				money = money - WD_quantity * 500000;
				cout << "Domination: 500000 VND\t Quantity:" << WD_quantity << endl;
			}

		}
		if (money >= 200000) {
			Node* TwoHK = Find(200000);
			int WD_quantity = money / 200000;
			if (TwoHK->data.quantity == 0) {
				;
			}
			else {
				if (WD_quantity <= TwoHK->data.quantity) {
					TwoHK->data.quantity = TwoHK->data.quantity - WD_quantity;
				}
				else {
					WD_quantity = TwoHK->data.quantity;
					TwoHK->data.quantity = 0;
				}
				money = money - WD_quantity * 200000;
				cout << "Domination: 200000 VND\t Quantity:" << WD_quantity << endl;
			}
		}

		if (money >= 100000) {
			Node* OneHK = Find(100000);
			int WD_quantity = money / 100000;
			if (OneHK->data.quantity == 0) {
				;
			}
			else {
				if (WD_quantity < OneHK->data.quantity) {
					OneHK->data.quantity = OneHK->data.quantity - WD_quantity;
				}
				else {
					WD_quantity = OneHK->data.quantity;
					OneHK->data.quantity = 0;
				}
				money = money - WD_quantity * 100000;
				cout << "Domination: 100000 VND\t Quantity:" << WD_quantity << endl;
			}
		}
		if (money >= 50000) {
			Node* FifTK = Find(50000);
			int WD_quantity = money / 50000;
			if (FifTK->data.quantity == 0) {
				;
			}
			else {
				if (WD_quantity < FifTK->data.quantity) {
					FifTK->data.quantity = FifTK->data.quantity - WD_quantity;
				}
				else {
					WD_quantity = FifTK->data.quantity;
					FifTK->data.quantity = 0;
				}
				money = money - WD_quantity * 50000;
				cout << "Domination: 50000 VND\t Quantity:" << WD_quantity << endl;
			}
		}
		if (money >= 20000) {
			Node* TwenTK = Find(20000);
			int WD_quantity = money / 20000;
			if (TwenTK->data.quantity == 0) {
				;
			}
			else {
				if (WD_quantity < TwenTK->data.quantity) {
					TwenTK->data.quantity = TwenTK->data.quantity - WD_quantity;
				}
				else {
					WD_quantity = TwenTK->data.quantity;
					TwenTK->data.quantity = 0;
				}
				money = money - WD_quantity * 20000;
				cout << "Domination: 20000 VND\t Quantity:" << WD_quantity << endl;
			}
		}
		if (money >= 0 ) {
			cout << "The ATM have ran out of money." << endl;
			cout << "The money that the ATM owe you: " << money <<endl;
		}
	}

}

void LinkedList::WithDraw2(int money) {
	int orimoney = money;
	Node* FiveHK = Find(500000);
	Node *TwoHK = Find(200000);
	Node* OneHK = Find(100000);
	Node* FifTK = Find(50000);
	Node* TwenTK = Find(20000);
	cout << "So tien ban muon rut la: " << orimoney << " VND"<< endl;
	int Quan_500 = 0 , Quan_200 = 0, Quan_100 = 0, Quan_50 = 0, Quan_20 = 0;
	if (money % 20000 != 0) {
		cout << "Khong co menh gia phu hop" << endl;
	}
	if (money >= 500000) {
		if (FiveHK->data.quantity == 0) {
			;
		}
		else {
			Quan_500 = money / 500000;
			if (Quan_500 < FiveHK->data.quantity) {
				FiveHK->data.quantity = FiveHK->data.quantity - Quan_500;
			}
			else {
				Quan_500 = FiveHK->data.quantity;
				FiveHK->data.quantity = 0;
			}
			money = money - Quan_500 * 500000;
			
		}

	}
	if (money >= 200000) {
		if (TwoHK->data.quantity == 0) {
			;
		}
		else {
			Quan_200 = money / 200000;
			if (Quan_200 < TwoHK->data.quantity) {
				TwoHK->data.quantity = TwoHK->data.quantity - Quan_200;
			}
			else {
				Quan_200 = TwoHK->data.quantity;
				TwoHK->data.quantity = 0;
			}
			money = money - Quan_200 * 200000;
			
		}

	}
	if (money >= 100000) {
		if (OneHK->data.quantity == 0) {
			;
		}
		else {
			Quan_100 = money / 100000;
			if (Quan_100 < OneHK->data.quantity) {
				OneHK->data.quantity = OneHK->data.quantity - Quan_100;
			}
			else {
				Quan_100 = OneHK->data.quantity;
				OneHK->data.quantity = 0;
			}
			money = money - Quan_100 * 100000;
			
		}

	}
	if (money >= 50000) {
		if (FifTK->data.quantity == 0) {
			;
		}
		else {
			Quan_50 = money / 50000;
			if (Quan_50 < FifTK->data.quantity) {
				FifTK->data.quantity = FifTK->data.quantity - Quan_50;
			}
			else {
				Quan_50 = FifTK->data.quantity;
				FifTK->data.quantity = 0;
			}
			money = money - Quan_50 * 50000;
			
		}

	}
	if (money >= 20000) {
		if (TwenTK->data.quantity == 0) {
			;
		}
		else {
			Quan_20 = money / 20000;
			if (Quan_20 < TwenTK->data.quantity) {
				TwenTK->data.quantity = TwenTK->data.quantity - Quan_20;
			}
			else {
				Quan_20 = TwenTK->data.quantity;
				TwenTK->data.quantity = 0;
			}
			money = money - Quan_20 * 20000;
			
		}

	}
	if (money >= 20000) {
		int demands;
		cout << "May ATM khong du tien, may chi co the rut duoc " << orimoney - money << " VND" << endl;
		cout << "1. De rut.\n2. De ko rut." << endl;
		cin >> demands;
		if (demands == 1) {
			if (Quan_500 != 0) {
				cout << "So to 500k: " << Quan_500 << endl;
			}
			if (Quan_200 != 0) {
				cout << "So to 200k: " << Quan_200 << endl;
			}
			if (Quan_100 != 0) {
				cout << "So to 100k: " << Quan_100 << endl;
			}
			if (Quan_50 != 0) {
				cout << "So to 50k: " << Quan_50 << endl;
			}
			if (Quan_20 != 0) {
				cout << "So to 20k: " << Quan_20 << endl;
			}
			cout << "So du cua ban la: " << money << endl;
		}
		else {
			FiveHK->data.quantity = FiveHK->data.quantity + Quan_500;
			TwoHK->data.quantity = TwoHK->data.quantity + Quan_200;
			OneHK->data.quantity = OneHK->data.quantity + Quan_100;
			FifTK->data.quantity = FifTK->data.quantity + Quan_50;
			TwenTK->data.quantity = TwenTK->data.quantity + Quan_20;
		}
	}

}