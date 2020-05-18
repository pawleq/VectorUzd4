#pragma once
#include "header.h"
#include "Zmogus.h"
using std::vector;
class Studentas : public Zmogus
{
protected:
	vector<int> v_;
	int e_;
	double galutinis_;
	double galutmed_;
public:

	Studentas(string pavarde = "", string vardas = "", double e = 0, double galutinis = 0, double galutinismed = 0) : Zmogus(pavarde, vardas), e_(e), galutinis_(galutinis), galutmed_(galutinis) { }
	Studentas(ifstream& input, unsigned int &Vilgis, unsigned int &Pilgis);
	inline string vardas() const {return vardas_;}
	inline string pavarde() const {return pavarde_;}
	double galutinisVid() const {return galutinis_;}
	double galutinisMed() const {return galutmed_;}
	~Studentas() {this->v_.clear();};

	Studentas& operator=(const Studentas& origin) {
        if (&origin == this) return *this;
        this->vardas_ = origin.vardas_;
        this->pavarde_ = origin.pavarde_;
        this->e_ = origin.e_;
        this->galutinis_ = origin.galutinis_;
        this->galutmed_ = origin.galutmed_;
        return *this;
    }
    Studentas(const Studentas& student)
    {
        this->vardas_ = student.vardas_;
        this->pavarde_ = student.pavarde_;
        this->e_ = student.e_;
        this->galutinis_ = student.galutinis_;
        this->galutmed_ = student.galutmed_;
    }
    void verification(){}
	void setVardas(string vardas) {vardas_ = vardas;}
	void setPavarde(string pavarde) {pavarde_ = pavarde;}
	void setE(int e) {e_ = e;}
	void pushV(int v) {v_.push_back(v);}
	void reserveV(int rsize) {v_.reserve(rsize);}
	void setEback();
	void FindLongest(vector<Studentas> &input, unsigned int &Vilgis, unsigned int &Pilgis);
	void getAverage();
	void getMedian();

	// operatoriai

bool operator == (const Studentas&);
void operator +=(int b);
int operator >>(unsigned int & b);
int operator <<(unsigned int & b);

	};
bool compare_by_word(const Studentas& lhs, const Studentas& rhs);
bool compare_by_name(const Studentas& lhs, const Studentas& rhs);
bool compare_by_grades(const Studentas& lhs);
bool compare_by_mediana(const Studentas& lhs);
