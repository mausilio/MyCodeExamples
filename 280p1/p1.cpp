#include "io.h"
using namespace std;

int main(){
	double monthlyPayment; //the user selected monthly payment
	double interestRate;   //the user selected interest rate
	int loanDuration;      // the user selected duration in years
	double temp;           //temp variable used for checking if loanDuration entered is an int
	double balance = 0;    // the balance on the loan initally 0 (payed off)
	double principal;      //the payment that goes towards the principle
	double interest;       //the interest accrued in a month

	monthlyPayment = GetParam("Please enter the monthly payment: ", 1.0, 100000);
	interestRate = GetParam("Please enter the interest rate: ", 0, 1);
	temp = GetParam("Please enter the duration of the loan, in years: ", 1, 100);
	
	//reloops until an int is inputted
	while (temp != (int)temp){
		temp = GetParam("Please enter the duration of the loan, in years: ", 1, 100);
	}




	loanDuration = temp*12; //going from years 2 monthes
	PrintHeader();
	while (loanDuration >= 1){ // loops through until month 1
		//resets balance 2 begining of month
		balance = (monthlyPayment + balance) / (1.0 + interestRate / 12.0);
		interest = balance * interestRate / 12.0;
		principal = monthlyPayment - interest;
		PrintMonthlyData(loanDuration, principal, interest, balance);
		loanDuration--; //goes back a month
	}





	return 0;
}