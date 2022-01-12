#pragma once
#include"Product.h"
class QLSP {
private:
	Product* p;
	int n;
public:
	int IndexOf(int);
	void Add();
	QLSP(int = 0);
	~QLSP();
};
QLSP::QLSP(int n)
 :n(n)
{
	this->p = nullptr;
}
QLSP::~QLSP() {
	delete[] this->p;
}
int QLSP::IndexOf(int ID) {
	for (int i = 0; i < this->n; i++) {
		if ((this->p + i)->getID() == ID) {
			return i;
		}
	}
	return -1;
}
void QLSP::Add() {
	int ID;
	cin >> ID;
	IndexOf(ID);
	if (IndexOf(ID) >= 0) {
		int k;
		cout << "nhap sl muon them: ";
		cin >> k;
		(this->p + IndexOf(ID))->setSl(k + (this->p + IndexOf(ID))->getSl());
	}

	else {
		cout << "nhap lua chon: " << endl << "1: them vao dau: " << endl << "2: them vao cuoi: " << "them vao vi tri x" << endl << "moi nhap: ";
		int lc;
		cin >> lc;
		if (lc == 1) {
			Product* temp = new Product[this->n];

			for (int i = 0; i < this->n; i++) {
				*(temp + i) = *(this->p + i);
			}
			delete[] this->p;
			this->p = new Product[this->n + 1];
			Product ptm;
			cin >> ptm;
			*(this->p + 0) = ptm;
			for (int i = 1; i <= this->n; i++) {
				*(this->p + i) = *(temp + i-1);
			}
			this->n++;
		}
		if (lc == 2) {
			Product* temp = new Product[this->n];

			for (int i = 0; i < this->n; i++) {
				*(temp + i) = *(this->p + i);
			}
			delete[] this->p;
			this->p = new Product[this->n + 1];
			Product ptm;
			cin >> ptm;
			
			for (int i = 0; i < this->n; i++) {
				*(this->p + i) = *(temp + i);
			}
			*(this->p + this->n) = ptm;
			this->n++;
			
		}
		if (lc == 3) {
			int vt;
			cout << "nhap vi tri: " << endl;
			cin >> vt;
			Product* temp;
			temp = new Product[this->n];
			for (int i = 0; i < this->n; i++)
				*(temp + i) = *(this->p + i);
			delete[] this->p;
			this->n++;
			this->p = new Product[this->n];
			for (int i = 0; i < vt - 1; i++)
			{
				*(this->p + i) = *(temp + i);
			}
			Product ptm;
			cin >> ptm;
			*(this->p + vt - 1) = ptm;
			for (int i = vt; i < this->n; i++)
				*(this->p + i) = *(temp + i - 1);
			delete[] temp;

			
			
			
			
		}
	}
}
