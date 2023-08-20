#include<iostream>  // To obtain & provide the input and output.
#include<conio.h>  //to use getch. It is used in C programming
#include<string>   //Since we are using strings in the code.
using namespace std;

/* ATM System
features to be included:-
1, check the balance.
2, cash withdraw.
3, user details.
4, update mobile number.
5, exit.
*/

//through OOP's concept

class atm {
private:                                    //Member variables
	long int account_no;
	string account_holder;
	int account_PIN;
	double account_balance;
	string acc_mobileNumber;
	
public:                                    //Member functions

//first Member function which can access the private member variables

	void accountCreation(long int account_no_a, string account_holder_a, //Initialising the variables
	int account_PIN_a, double account_balance_a, string acc_mobileNumber_a) { 
	            
    	//the variables are initialised to access the private member variables
    	
    	account_no = account_no_a;  //Assigning the formal arguments to the private variables 
    	account_holder=account_holder_a;
    	account_PIN=account_PIN_a;
    	account_balance=account_balance_a;
	    acc_mobileNumber=acc_mobileNumber_a; 			 
	}
	
//getFunction is used to 

	long int getAccountNo() {
	    return account_no;
    }
    
    string getAccountHolder() {
	    return account_holder; 
    }
    
    int getAccountPIN() {
	    return account_PIN;
    }
    
    double getAccountBalance() {
	    return account_balance;
    }
    
    string getMobileNo() {
	    return acc_mobileNumber;
    }
    
//Here on we create the functions for the mechanism of the usage of the obtained information

    void cashWithdrawal(int amount) {
    	if((amount>0) && (amount<account_balance)) {
    		account_balance -= amount;
    		cout<<"Available cash : "<<account_balance<<endl;
			_getch();
		}
		else {
			cout<<"Invalid / Insufficient balance"<<endl;
			_getch();
		}
	}
	
	void mobileNoUpdation(string number1, string number2) {
		if(number1==acc_mobileNumber) {
			acc_mobileNumber == number2;
			cout<<"Successfully Updated"<<endl;
			cout<<acc_mobileNumber<<endl;
			_getch();
		}
		
	}
};

//********************************The ClassCreation end here********************************
//*************************The ATM user interface creation starts here*************************

int main() {
	
	//it is used for authentication of the user
	
	int holderChoice=0;
	int Account_PIN; 
	long int Account_No;
	
	system("cls");       //it is used to the contents on the screen like the PIN No. or such details
	
	atm holder1;         //creating the object of the class ATM
	holder1.accountCreation(3227885, "Subbarao", 8085, 80000.00, "7901107177");  //Setting User details
	
	do{
		system("cls");
		cout<<"Enter the authentication details"<<endl;
		cout<<"Enter the Account Number: "<<endl;
		cin>>Account_No;
		cout<<"Enter the Account PIN: "<<endl;
		cin>>Account_PIN;
		
/*Here the if-else statement is used for returning the value of the account number and the pin for the authentication
of the user. These values are obtained through the function call, they are stored in the private member variables to
retrieve them we use the get function in the if-else statement*/

		if((Account_No == holder1.getAccountNo()) && (Account_PIN == holder1.getAccountPIN())) {
			do{
				
				//User Interface
				
				int cash=0;
				string oldMobileNumber;
				string newMobileNumber;
				
				cout<<"******************Welcome to my ATM******************"<<endl;
				cout<<"Select the options:- "<<endl;
				cout<<"1, Check Balance."<<endl;
				cout<<"2, Cash Withdrawal."<<endl;
				cout<<"3, Show user details."<<endl;
				cout<<"4, Update mobile number."<<endl;
				cout<<"5, Exit."<<endl;
				cin>>holderChoice;
				
				switch(holderChoice) {
					case 1:
						cout<<"The account balance of the user is: "<<holder1.getAccountBalance()<<endl;
						cout<<"Press any key to continue";
						_getch();    //In order to get any character from the user to continue
						break;
						
					case 2:
						cout<<"Amount to be withdrawn: ";
						cin>>cash;
						holder1.cashWithdrawal(cash);
						break;
						
					case 3:
						cout<<"show user details: "<<endl;
						cout<<"Account Number"<<holder1.getAccountNo()<<endl;
						cout<<"Account Holder"<<holder1.getAccountHolder()<<endl;
						cout<<"Cash Available"<<holder1.getAccountBalance()<<endl;
						cout<<"Holder Mobile Number"<<holder1.getMobileNo()<<endl;
						_getch();
						break;
						
					case 4:
						cout<<"Enter the old mobile number: ";
						cin>>oldMobileNumber;
						cout<<"Enter the new mobile number: ";
						cin>>newMobileNumber;
						holder1.mobileNoUpdation(oldMobileNumber, newMobileNumber);
						break;
						
					case 5:
						exit(0);
						
					default:
						cout<<"Inappropriate Option selected"<<endl;
						break;
				}
			}while (1);
		}
		else {
			cout<<"Holder details are invalid"<<endl;
			_getch();
        }		
	}while (1);
		
	return 0;
}
