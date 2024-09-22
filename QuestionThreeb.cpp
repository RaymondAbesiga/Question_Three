#include <iostream>
using namespace std;

int main() {
    double loadedAmount;
    int waterUnits;
    double cost = 0.0;

    // Prompt user for input
    cout << "Enter the amount of money loaded onto your account (UGX): ";
    cin >> loadedAmount;

    cout << "Enter the number of water units consumed: ";
    cin >> waterUnits;

    // Calculate the total cost based on water units consumed
    if (waterUnits <= 10) {
        cost = waterUnits * 150;  // 150 UGX for the first 10 units
    } else if (waterUnits <= 20) {
        cost = (10 * 150) + ((waterUnits - 10) * 175);  // 150 UGX for the first 10, 175 UGX for next 10
    } else {
        cost = (10 * 150) + (10 * 175) + ((waterUnits - 20) * 200);  // 150 UGX for the first 10, 175 UGX for next 10, 200 UGX for beyond 20
    }

    // Adding a surcharge of 15%
    cost += cost * 0.15;

    // Adding 18% VAT
    double totalWithVAT = cost * 1.18;

    // Check if user has enough balance
    if (loadedAmount < totalWithVAT) {
        cout << "Error: Insufficient balance." << endl;
        cout << "Remaining balance: " << loadedAmount << " UGX" << endl;
    } else {
        loadedAmount -= totalWithVAT;  // Deduct total cost from the user's balance
        cout << "Total cost after VAT: " << totalWithVAT << " UGX" << endl;
        cout << "Remaining balance: " << loadedAmount << " UGX" << endl;
    }

    return 0;
}
