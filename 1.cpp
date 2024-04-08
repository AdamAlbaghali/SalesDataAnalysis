#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_SALESPERSON = 6;
const int NUM_QUARTERS = 4;

struct Salesperson {
    int ID;
    double Quarter[NUM_QUARTERS];
    double totalSale;

    Salesperson() {
        ID = 0;
        totalSale = 0;
        for (int i = 0; i < NUM_QUARTERS; ++i) {
            Quarter[i] = 0;
        }
    }
};

void initialize(ifstream& indata, Salesperson salespersons[]);
void getData(ifstream& infile, Salesperson salespersons[]);
void saleByQuarter(Salesperson salespersons[], double totalSalesByQuarter[]);
void totalSaleByPerson(Salesperson salespersons[]);
void printReport(ofstream& outfile, Salesperson salespersons[], double totalSalesByQuarter[]);
void maxSaleByPerson(ofstream& outData, Salesperson salespersons[]);
void maxSaleByQuarter(ofstream& outData, double totalSalesByQuarter[]);

int main() {
    Salesperson salespersons[NUM_SALESPERSON];
    double totalSalesByQuarter[NUM_QUARTERS] = {0};

    
    ifstream idFile("SalesManID.txt");
    if (!idFile) {
        cerr << "Error: Unable to open salesperson ID file." << endl;
        return 1;
    }
    initialize(idFile, salespersons);
    idFile.close();

    
    ifstream salesDataFile("SalesData.txt");
    if (!salesDataFile) {
        cerr << "Error: Unable to open sales data file." << endl;
        return 1;
    }
    getData(salesDataFile, salespersons);
    salesDataFile.close();

    
    ofstream outputFile("SalesdataAnalysis.txt");
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    
    saleByQuarter(salespersons, totalSalesByQuarter);
    totalSaleByPerson(salespersons);
    printReport(outputFile, salespersons, totalSalesByQuarter);
    maxSaleByPerson(outputFile, salespersons);
    maxSaleByQuarter(outputFile, totalSalesByQuarter);

    outputFile.close();

    return 0;
}

void initialize(ifstream& indata, Salesperson salespersons[]) {
    int i = 0;
    while (i < NUM_SALESPERSON && indata >> salespersons[i].ID) {
        i++;
    }
}

void getData(ifstream& infile, Salesperson salespersons[]) {
    int ID, month;
    double saleAmount;
    while (infile >> ID >> month >> saleAmount) {
        int i = 0;
        while (i < NUM_SALESPERSON) {
            if (salespersons[i].ID == ID) {
                salespersons[i].Quarter[(month - 1) / 3] += saleAmount;
                break;
            }
            i++;
        }
    }
}

void saleByQuarter(Salesperson salespersons[], double totalSalesByQuarter[]) {
    int i = 0;
    while (i < NUM_SALESPERSON) {
        int j = 0;
        while (j < NUM_QUARTERS) {
            totalSalesByQuarter[j] += salespersons[i].Quarter[j];
            j++;
        }
        i++;
    }
}

void totalSaleByPerson(Salesperson salespersons[]) {
    int i = 0;
    while (i < NUM_SALESPERSON) {
        int j = 0;
        while (j < NUM_QUARTERS) {
            salespersons[i].totalSale += salespersons[i].Quarter[j];
            j++;
        }
        i++;
    }
}

void printReport(ofstream& outfile, Salesperson salespersons[], double totalSalesByQuarter[]) {
    outfile << "-----------  Annual Sales Report -------------" << endl;
    outfile << "  ID         QT1        QT2      QT3       QT4     Total" << endl;
    outfile << "_____________________________________________________________" << endl;
    int i = 0;
    while (i < NUM_SALESPERSON) {
        outfile << setw(5) << salespersons[i].ID << setw(11) << fixed << setprecision(2);
        int j = 0;
        while (j < NUM_QUARTERS) {
            outfile << salespersons[i].Quarter[j] << setw(9);
            j++;
        }
        outfile << salespersons[i].totalSale << endl;
        i++;
    }
    outfile << "Total" << setw(9) << fixed << setprecision(2);
    int j = 0;
    while (j < NUM_QUARTERS) {
        outfile << totalSalesByQuarter[j] << setw(9);
        j++;
    }
    outfile << endl;
}

void maxSaleByPerson(ofstream& outData, Salesperson salespersons[]) {
    double maxSale = 0;
    int maxIndex = -1;
    int i = 0;
    while (i < NUM_SALESPERSON) {
        if (salespersons[i].totalSale > maxSale) {
            maxSale = salespersons[i].totalSale;
            maxIndex = i;
        }
        i++;
    }
    if (maxIndex != -1) {
        outData << "Max Sale by SalesPerson: ID = " << salespersons[maxIndex].ID << ", Amount = $" << maxSale << endl;
    }
}

void maxSaleByQuarter(ofstream& outData, double totalSalesByQuarter[]) {
    double maxSale = 0;
    int maxIndex = -1;
    int i = 0;
    while (i < NUM_QUARTERS) {
        if (totalSalesByQuarter[i] > maxSale) {
            maxSale = totalSalesByQuarter[i];
            maxIndex = i + 1; 
        }
        i++;
    }
    if (maxIndex != -1) {
        outData << "Max Sale by Quarter: Quarter = " << maxIndex << ", Amount = $" << maxSale << endl;
    }
}
