#include <iostream>
using namespace std;

const int MAX_MONTHS = 12; // maximum number of months to track

void get_income(float income[], int num_months)
{
    for (int i = 0; i < num_months; i++)
    {
        cout << "Enter your income for month " << i + 1 << ": $";
        cin >> income[i];
    }
}

void get_expenses(float expenses[], int num_months)
{
    for (int i = 0; i < num_months; i++)
    {
        cout << "Enter your expenses for month " << i + 1 << ": $";
        cin >> expenses[i];
    }
}

float calculate_balance(float income[], float expenses[], int num_months)
{
    float balance = 0;
    for (int i = 0; i < num_months; i++)
    {
        balance += income[i] - expenses[i];
    }
    return balance;
}

void display_balance(float balance)
{
    cout << "Your balance is: $" << balance << endl;
    if (balance > 0)
    {
        cout << "You have a surplus of $" << balance << endl;
    }
    else if (balance < 0)
    {
        cout << "You have a deficit of $" << -balance << endl;
    }
    else
    {
        cout << "You have a zero balance." << endl;
    }
}

void display_report(float income[], float expenses[], int num_months)
{
    float total_income = 0, total_expenses = 0;
    for (int i = 0; i < num_months; i++)
    {
        total_income += income[i];
        total_expenses += expenses[i];
    }
    float avg_income = total_income / num_months;
    float avg_expenses = total_expenses / num_months;
    cout << "Total income: $" << total_income << endl;
    cout << "Total expenses: $" << total_expenses << endl;
    cout << "Average income per month: $" << avg_income << endl;
    cout << "Average expenses per month: $" << avg_expenses << endl;
}

int main()
{
    int num_months;
    float income[MAX_MONTHS], expenses[MAX_MONTHS], balance;

    // Get the number of months to track from the user
    cout << "Enter the number of months to track (1-" << MAX_MONTHS << "): ";
    cin >> num_months;
    if (num_months < 1 || num_months > MAX_MONTHS)
    {
        cout << "Invalid number of months." << endl;
        return 1;
    }

    // Get income and expenses from the user
    get_income(income, num_months);
    get_expenses(expenses, num_months);

    // Calculate the balance
    balance = calculate_balance(income, expenses, num_months);

    // Display the balance to the user
    display_balance(balance);

    // Display a report of the user's data
    display_report(income, expenses, num_months);

    return 0;
}
