//---------------------------------------------------------------------------

#include "periodical.h"

//---------------------------------------------------------------------------
// Constructor
Periodical::Periodical() : Book() {
    bookTitle = "";
    genre = "PERIODICAL";
    year = 0;
    month = 0;
    bookFormat = 'H';
    totalCopies = 1;
    numOfCopiesIn = 1;
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
    cout << left << setw(8) << 
    year << setw(5) << month << setw(MAX_TITLE_LENGTH) << 
    bookTitle.substr(0, MAX_TITLE_LENGTH) << endl;
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

void Periodical::displayData() const {
    cout << left << setw(7) << numOfCopiesIn << setw(8) << 
    year << setw(15) << month << left << setw(MAX_TITLE_LENGTH + 5) <<
    bookTitle.substr(0, MAX_TITLE_LENGTH) << endl;
}

void Periodical::displayHeader() const {
    cout << genre << " BOOKS" << endl;
    cout << left << setw(7) << "AVAIL" << left << setw(8) <<
    "YEAR" << setw(15) << 
    "MONTH" << left << setw(MAX_TITLE_LENGTH) << "TITLE" << endl;
}
