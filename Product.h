#pragma once
#include<iostream>
using namespace std;
class Product {
private:
	int ID;
	string NameP;
	int Sl;
	double Gia;
	friend ostream& operator<<(ostream&, const Product&);
	friend istream& operator>>(istream&, Product&);
	

public:
	int getID();
	void setID(int);
	void setSl(int);
	int getSl();
	Product(int = 0, string = "", int = 0, double = 0.0);
	~Product();
};
Product::Product(int ID, string NameP, int Sl, double Gia)
	:ID(ID), NameP(NameP),Sl(Sl), Gia(Gia) {

}
Product::~Product() {
	
}
ostream& operator<<(ostream&o, const Product&h) {
	o << "ID: "<<endl;
	o << h.ID;
	o << "Name: " << endl;
	o << h.NameP;
	o << "so luong: " << endl;
	o << h.Sl;
	o << "gia: " << endl;
	o << h.Gia;
	return o;
}
istream& operator>>(istream&i, Product&h) {
	cout << "ID: " << endl;
	i >> h.ID;
	cout << "Name: " << endl;
	i >> h.NameP;
	cout << "so luong: " << endl;
	i >> h.Sl;
	cout<< "gia: " << endl;
	i >> h.Gia;
	return i;
}
int Product::getID() {
	return this->ID;
}
void Product::setID(int ID) {
	this->ID = ID;
}
int Product::getSl() {
	return this->Sl;
}
void Product::setSl(int Sl) {
	this->Sl = Sl;
}

