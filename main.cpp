#include "lib.h"
int main() {

    //Declare the apocalypse   
    Year* yearHead = nullptr;

    //Read \- O v O -/
    readFileYear(yearHead);

    //Dizzplay
    //displayScreen(yearHead); // U can use if u want to see in the terminal
    displayFile(yearHead); //Otherwise display in file is much better

    //Delete, avoid mém mo ri lít kinh
    Delete_Data(yearHead);
    
    return 0;
}