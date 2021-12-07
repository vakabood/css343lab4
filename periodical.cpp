//---------------------------------------------------------------------------

#include "periodical.h"

//---------------------------------------------------------------------------
// Constructor
Periodical::Periodical() : Book() {
    bookTitle = "";
    year = 0;
    month = 0;
    bookFormat = 'H';
    totalCopies = 1;
}

//---------------------------------------------------------------------------
// Destructor
Periodical::~Periodical() { }

//---------------------------------------------------------------------------
// getMonth
int Periodical::getMonth() const{
    return month;
}

//---------------------------------------------------------------------------
// create
Item* Periodical::create() const {
    return new Periodical();
}

//---------------------------------------------------------------------------
// setData
void Periodical::setData(ifstream& infile) {
    infile.get();
    getline(infile, bookTitle, ',');

    infile.get();
    infile >> month;

    infile.get();
    infile >> year;
}

//---------------------------------------------------------------------------
// setCommandData
void Periodical::setCommandData(ifstream& infile) {
    infile.get();
    infile >> bookFormat;

    infile.get();
    infile >> year;

    infile.get();
    infile >> month;

    infile.get();
    getline(infile, bookTitle, ',');
}

//---------------------------------------------------------------------------
// display
void Periodical::display() const {
    cout << left << setw(5) << totalCopies << setw(22) << 
    bookTitle.substr(0, MAX_TITLE_LENGTH) << setw(15) << 
    month << setw(5) << year << endl;
}

//---------------------------------------------------------------------------
// operator<
bool Periodical::operator<(const NodeData& bookToCompare) const {
    const Periodical* p = dynamic_cast<const Periodical*>(&bookToCompare);
    if (year < p->year) {
        return true;
    } else if (year == p->year) {
        if (month < p->month) {
            return true;
        } else if (month == p->month) {
            if (bookTitle < p->bookTitle) {
                return true;
            }
        }
    }
    return false;
}

//---------------------------------------------------------------------------
// operator==
bool Periodical::operator==(const NodeData& bookToCompare) const {
    const Periodical* p = dynamic_cast<const Periodical*>(&bookToCompare);
    return bookTitle == p->bookTitle && year == p->year && month == p->month;
}

//------------------------------------------------------------------------------
// operator<<
// Displays book information
ostream& operator<<(ostream& os, const Periodical& item) {
    return os;
}


