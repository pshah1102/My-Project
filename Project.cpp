//Please make following changes to your codeblocks ide.
//Go to settings->compiler->linker settings->in link libraries section press add button and type winmm and click ok
//Without above settings cash outlet function will not work and CD drive will not be ejected if present in P.C

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;


    class Atm
    {
        float main_balance = 100000;            //private data member which stores balance
        int pin;                                //private data member which stores pin number
        public:
            void getpin()                       //member function to get the pin when program starts
            {
                cout<<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to ATM SIMULATOR \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                cout<<"\n \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Account number:1007533192\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;

                cout<<"\n \t       \xB2\xB2\xB2\xB2\xB2 Enter pin(Personal Identification Number) 4 digits only \xB2\xB2\xB2\xB2\xB2";
                cin>>pin;
                while(pin<999 || pin>9999)      //this loop checks whether the pin number is of 4 digits or not
                {
                    cout<<"\n \t\t\t Invalid pin. Please try again";
                    cout<<"\n \t\t\t Enter your pin";
                    cin>>pin;
                }
                system("cls");                 //clears the output screen
            }
        void showMenu();          //declaration of all member function and all are defined outside the class
        void choice();
        void withdrawal();
        void deposit();
        void checkbalance();
        void fund_transfer();
        void statement();
        bool checkpin();
    };



    //as class is defined under the namespace stimulator so there is no need of using the scope resolution operator
    //while calling the member functions
    //but scope resolution operator is required while defining the member functions

        void cashoutlet()                         //this function opens the cd drive
        {
            mciSendString("set cdaudio door open",0,NULL,NULL);
        }

        void waiting(unsigned int mseconds)       //this function sets the desired buffer time in between the processes
        {
            clock_t goal = mseconds + clock();
            while (goal > clock());
        }

    int totalcount=4;                              //this variable is used to check that if wrong pin is entered
                                                   //more than 5 five times than program will terminate

        bool Atm::checkpin()                       //this function checks whether entered pin is correct or not
        {
            int pin1;
            x:cout<<"\n\n\t\t\t Enter your pin";
            cin>>pin1;

            if(totalcount==0)
                exit(0);

            else
            {
                if(pin1 == pin)
                    return true;

                else
                {
                    cout<<"\n\n\t\t\t Incorrect Pin !";
                    totalcount--;
                    checkpin();
                }
            }
        }

        void Atm::showMenu()       //this function prints the menu when called and calls the choice function to select one of the given function
		{
			cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			cout << "\n\n\t\t\t [ 1 ] Withdrawal" << endl;
			cout << "\t\t\t [ 2 ] Deposit" << endl;
			cout << "\t\t\t [ 3 ] Check Balance" << endl;
			cout << "\t\t\t [ 4 ] Funds Transfer" << endl;
			cout << "\t\t\t [ 5 ] Statement" << endl;
			cout << "\t\t\t [ 6 ] Exit ATM" << endl;
			cout << "\t\t\t _____________________________________________"<<endl;
			cout << "\t\t\t Enter your choice: ";
			choice();
		}

		void Atm::choice()
		{
		    int c;              //c is used to select the desired option by inputting the number of desired option
		    x: cin>>c;
            if(c>6 || c<1)      //this if statement checks whether the input is within the range of 1-6
            {
                cout<<endl<<"Please enter a valid option";
                goto x;
            }
		    switch(c)           //switch statement is used to go to the desired option's function
		    {
            case 1:
                withdrawal();   //function having the logic/code of withdrawal option

            case 2:
                deposit();      //function having the logic/code of deposit option

            case 3:
                checkbalance();  //function having the logic/code of check balance option

            case 4:
                fund_transfer();   //function having the logic/code of fund transfer option

           case 5:
                statement();     //function having the logic/code of statement option
            case 6:
                exit(0);

		    }
		}

		void Atm::statement()    //prints all the previous transaction of the account holder
		{
		    char ch[500];int i=totalcount;
		    system("cls");
		    cout << "\n\n\t\t\t\t\t PRINTING RECEIPT . . .\n";
		    waiting(5000);
		    system("cls");
		    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
		    cout<<setw(15)<<"Time"<<setw(15)<<"Date"<<setw(20)<<"Type"<<setw(15)<<"Amount"<<setw(15)<<"Balance"<<endl;
		    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
		    ifstream f;
		    f.open("ministatement.txt",ios::in);      //file opened in read mode
            while(!f.eof())
            {
                f.getline(ch,500);                    //reads the function till newline character is found
                cout<<ch<<endl;
            }
            f.close();                                //file closed
		    showMenu();
		}

		void fputdata(char date[],char time[],float main_balance,float amount,string type)  //function is used to store the data in the file
		{
		    fstream f;
		    f.open("ministatement.txt", ios::app);        //file opened in append mode
		    f<<setw(15)<<time<<setw(15)<<date<<setw(20)<<type<<setw(15)<<amount<<setw(15)<<main_balance<<"\n";  //stores the data in a formatted
                                                                                                                //manner using manipulators
		    f.close();
		    totalcount++;
		}


		void Atm::withdrawal()       //function used to withdraw money from the account
		{
            system("cls");
            cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WITHDRAWAL TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			if(checkpin())           //to enter the pin and also verify it
                {
					float amount2;      //for storing the amount to be withdrawn
					system("cls");
					cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WITHDRAWAL TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
					cout << "\n\n\t\t\t AVAILABLE BALANCE :"<<main_balance << endl;
					x:cout << "\t\t\t Enter the amount : ";
					cin >> amount2;
					if(amount2>main_balance)  //if entered amount is more than available balance then this conditions becomes true
                    {
                        cout<<endl<<"Cannot deduct more than availabe balance";
                        cout<<"\nPlease enter the amount again.\n";
                        goto x;
                    }
                    else        //if entered amount is legit than flow goes ahead
                    {
                        main_balance=main_balance-amount2;   //deducts the entered amount from the main balance
						cout << "\t\t\t Your remaining savings balance: "<<main_balance<<endl;
                        system("cls");

                        system("cls");
                        printf("\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please collect your cash \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                        cashoutlet();
                        waiting(5000);                //sets the buffer time to 5000 milli second
                        system("cls");

                        char date[9];
                        char time[9];
                        _strdate(date);                 //stores current date of the system
                        _strtime(time);                 //stores current time of the system
                        cout << "\n\n\t\t\t\t\t PRINTING RECEIPT . . .\n";
                        waiting(3000);                  //sets the buffer time to 3000 milli second
                        system("cls");

                        //code below prints the receipt of transaction done

                        cout << endl <<"\n\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RECEIPT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
                        cout << "\n\t\t\t|\t\t\t\t\t      |"
                             << "\n\t\t\t|\t   ATM TRANSACTION RECORD\t      |"
                             << "\n\t\t\t|\t\t\t\t\t      |"
                             << "\n\t\t\t|DATE:\t\t\t   "<<date<<"\t      |"
                             << "\n\t\t\t|TIME:\t\t\t   "<<time<<"\t      |";

                        cout << "\n\t\t\t|TRANSACTION:\t\t    SAVINGS WITHDRAWAL|"
                             << "\n\t\t\t|AMOUNT:\t\t    "<<amount2<<".00\t      |"
                             << "\n\t\t\t|CURRENT BAL:\t\t    "<<main_balance<<"             |\n";

                        fputdata(date,time,main_balance,amount2,"withdrawal");  //sends the current data of transaction to save it into the file

                        waiting(3000);       //sets the buffer time to 5000 milli second
                        system("cls");
                        showMenu();          //shows the main menu for further transaction
                    }
				}
		}

		void Atm::deposit()   //function is used for depositing the money in the account
		{
            system("cls");
            cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DEPOSIT TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
            if(checkpin())
            {
                float depamount1;    //stores the amount to be deposited
                system("cls");
                cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DEPOSIT TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
				cout<<endl<<"\t\t\t Your main balance is:"<<main_balance;

				cout << "\n\n\t\t\t Enter the deposit amount :";
				cin >> depamount1;

				main_balance=main_balance+depamount1;      //adds the deposited amount to the main balance
				cout <<endl<< "\t\t\t Your New Balance:"<<main_balance<<endl;

                system("cls");
                printf("\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please deposit your cash \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                cashoutlet();             //function to take cash from the user and deposits in the account
                waiting(5000);

				system("cls");
                char date[9];
                char time[9];
                _strdate(date);
                _strtime(time);
                cout << "\n\n\t\t\t\t\t PRINTING RECEIPT . . .\n";
                waiting(3000);
                system("cls");

                //code below prints the receipt of transaction done

                cout << endl <<"\n\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RECEIPT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
                cout << "\n\t\t\t|\t\t\t\t\t      |"
                     << "\n\t\t\t|\t   ATM TRANSACTION RECORD\t      |"
                     << "\n\t\t\t|\t\t\t\t\t      |"
                     << "\n\t\t\t|DATE:\t\t\t   "<<date<<"\t      |"
                     << "\n\t\t\t|TIME:\t\t\t   "<<time<<"\t      |";

				cout << "\n\t\t\t|TRANSACTION:\t           DEPOSIT TRANSACTION|"
				 	 << "\n\t\t\t|AMOUNT:\t\t   "<<depamount1<<".00\t      |"
				 	 << "\n\t\t\t|CURRENT BAL:\t\t   "<<main_balance<<"\t      |\n";

                fputdata(date,time,main_balance,depamount1,"deposit");   //sends the current data of transaction to save it into the file
				waiting(3000);
				system("cls");
				showMenu();
            }
        }

        void Atm::checkbalance()       //function is used to check the balance of the account
			{
                system("cls");
                char date[9];
                char time[9];
                _strdate(date);
                _strtime(time);
                cout << "\n\n\t\t\t\t\t PRINTING RECEIPT . . .\n";
                waiting(3000);
                system("cls");

                //code below prints the available balance

                cout << endl <<"\n\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RECEIPT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
                cout << "\n\t\t\t|\t\t\t\t\t      |"
                     << "\n\t\t\t|\t   ATM TRANSACTION RECORD\t      |"
                     << "\n\t\t\t|\t\t\t\t\t      |"
                     << "\n\t\t\t|DATE:\t\t\t   "<<date<<"\t      |"
                     << "\n\t\t\t|TIME:\t\t\t   "<<time<<"\t      |";

                cout << "\n\t\t\t|YOUR AVAILABLE BALANCE :  "<<main_balance<<" \t      |\n";
                waiting(3000);
                system("cls");
                showMenu();
       }

       void Atm:: fund_transfer()   //function is used to transfer the money from your account to other account
       {
            system("cls");
            cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FUND TRANSFER TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
            if(checkpin())
            {
                long long int accntNo, amt;  //to store the account number and amount to be transferred
                system("cls");
                cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FUND TRANSFER TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                cout << "\n\n\t\t\t YOUR BALANCE : "<<main_balance;

                cout << "\n\t\t\t Enter Account Number (for Transfer) : ";
                cin >> accntNo;

                while(accntNo<999999999 || accntNo>9999999999)   //checks that entered account number is of 10 digits or not
                {
                    cout<<"\t\t\tInvalid account number. Please try again";
                    cout<<"\n\t\t\tEnter your account number";
                    cin>>accntNo;
                }

                cout << "\n\t\t\t Enter Amount To Transfer (Limit Upto 20,000) : ";
                cin >> amt;
                while (amt > 20000)       //checks whether the entered amount is within the preset limit
                {
                    cout << "\n\n\t\t\t  Invalid Amount!\n\t\t\t Please try again!";
                    cout << "\n\t\t\t  Please enter Amount To Transfer : ";
                    cin >> amt;
                }

                waiting(1000);
				cout << "\n\n\t\t\t The amount of "<<amt<<" has been transfered to : "<<accntNo<<endl;
				waiting(3000);
				system("cls");
                char date[9];
                char time[9];
                _strdate(date);
                _strtime(time);
                cout << "\n\n\t\t\t\t\t PRINTING RECEIPT . . .\n";
                waiting(3000);
                system("cls");

                //code below prints the receipt of transaction

                cout << endl <<"\n\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RECEIPT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
                cout << "\n\t\t\t|\t\t\t\t\t      |"
                     << "\n\t\t\t|\t   ATM TRANSACTION RECORD\t      |"
                     << "\n\t\t\t|\t\t\t\t\t      |"
                     << "\n\t\t\t|DATE:\t\t\t   "<<date<<"\t      |"
                     << "\n\t\t\t|TIME:\t\t\t   "<<time<<"\t      |";

                cout << "\n\t\t\t|TRANSACTION:\t           FUND TRANSFER      |"
					 << "\n\t\t\t|AMOUNT:\t\t   "<<amt<<".00\t      |";

				main_balance=main_balance-amt;   // deducts the entered amount from main balance of user
				cout<< "\n\t\t\t|CURRENT BAL:\t\t   "<<main_balance<<"\t      |\n\n";

                fputdata(date,time,main_balance,amt,"fund transfer");     //sends the current data of transaction to save it into the file
				waiting(3000);
				system("cls");
				showMenu();
			}
       }

		int main()         //driver function of the program
		{
		    Atm a;           //object of Atm class is created
		    a.getpin();
		    a.showMenu();
                    cout<<endl<<"Thanks For visiting our Atm Services";
                    return 0;
		}
