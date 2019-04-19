﻿#include <iostream>

#include <string>
#include <iomanip>


#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Yen.h"
#include "Rupee.h"
#include "Yuan.h"
#include "Wallet.h"

using namespace std;

string generateBars(int number);
int getUserInputInt(const int& min, const int& max);

void printWallet();
void displayMainMenu();
void displayAddRemoveTotalMenu();
void displayTotalMenu();

namespace UI
{
	const int TERMINAL_WIDTH = 70;
	const int TERMINAL_HEIGHT = 25;

	const string BARS = "=";

	const string PROMPT_OPTION = "Pick an option: ";

	const string ERR_EXCEPTION_GENERIC = "ERROR: An exception occured.";
	const string ERR_EXCEPTION_INVALID_ARGUMENT = "ERROR: Invalid option, option is not a valid argument. Are you correctly typing a number or a string?";
	const string ERR_EXCEPTION_OUT_OF_RANGE = "ERROR: Invalid option, option is out of range.";
	const string ERR_INVALID_OPTION_RANGE = "ERROR: Invalid option, option must be between ";

	enum MAIN_MENU_OPTIONS { MAIN_NONE, MAIN_ADD, MAIN_SUBSTRACT, MAIN_TOTAL, MAIN_EMPTY, MAIN_EXIT };
	enum PICK_CURRENCY_OPTIONS { CURRENCY_DOLLARS, CURRENCY_EUROS, CURRENCY_YEN, CURRENCY_RUPEE, CURRENCY_YUAN, CURRENCY_BACK};
	enum TOTAL_CURRENCY_OPTIONS { TOTAL_NONE, TOTAL_NON_ZERO, TOTAL_OF_ZERO, TOTAL_INDIVIDUAL};
	enum EMPTY_OPTIONS { EMPTY_NONE, EMPTY_CHECK_CURRENCY, EMPTY_CHECK_WALLET, EMPTY_BY_NAME, EMPTY_ALL};

}


int main() 
{
	//GET USER INPUT
	int inputMain;

	//Objects.
	Wallet wallet(0, 0, 0, 0, 0);
	Currency currency;

	/*
	//HOW TO PRINT OUT EVERYTHING IN THE WALLET
	//You can also do:
	//cout << "this many dollars: " << wallet[0].getWholeParts << " and this many cents: " << wallet[0].getFractionalParts
	//Prints out "this many dollars: 5 and this many cents: 41"
	//Or you can also do:
	//cout << "$" << wallet[0].getTotalWholeParts
	//Prints out "$5.41"
	cout << "Wallet contains:" << endl;
	cout << wallet[0] << endl;
	cout << wallet[1] << endl;
	cout << wallet[2] << endl;
	cout << wallet[3] << endl;
	cout << wallet[4] << endl << endl;

	//How to add and remove currency
	//You can either give the index (0-4) or the abbreviation (USD, EUR, JPY, INR, CNY)
	cout << "Remove 2 rupees" << endl;
	wallet.removeCurrency(3, 2); //Using currency indexes
	cout << wallet[3] << endl << endl;

	cout << "Add 5 dollars" << endl;
	wallet.addCurrency("USD", 5); //Using currency abbreviations
	cout << wallet[0] << endl << endl;

	//How to get number of non-zero currency
	cout << "This many currencies ARE NOT zero" << endl;
	cout << wallet.getNumNonZeroCurrency() << endl << endl;

	//How to set a currency to 0, without having to do math or anything
	cout << "Empty out dollars" << endl;
	wallet.emptyCurrency(0);
	cout << wallet[0] << endl << endl;

	cout << "This many currencies ARE NOT zero" << endl;
	cout << wallet.getNumNonZeroCurrency() << endl << endl;

	//How to empty out every currency
	cout << "Empty out everything" << endl << endl;
	wallet.emptyAllCurrency();
	
	//How to get number of zero currency
	cout << "This many currencies ARE zero" << endl;
	cout << wallet.getNumZeroCurrency() << endl << endl;

	//How to check if a specific currency is 0
	cout << "Are yen empty?" << endl;
	cout << wallet.isCurrencyEmpty("JPY") << endl << endl;

	//How to check if wallet is empty
	cout << "Is wallet empty?" << endl;
	cout << wallet.isWalletEmpty() << endl << endl;
	*/
	
	do
	{
		
		displayMainMenu();
		cout << UI::PROMPT_OPTION;
		inputMain = getUserInputInt(UI::MAIN_MENU_OPTIONS::MAIN_ADD, UI::MAIN_MENU_OPTIONS::MAIN_EXIT);

		switch (inputMain)
		{
			int subMenuInput, userWhole, userFractional;
		case UI::MAIN_MENU_OPTIONS::MAIN_ADD:
			do
			{
				displayAddRemoveTotalMenu();
				cout << UI::PROMPT_OPTION;
				subMenuInput = getUserInputInt(UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS, UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);

				switch (subMenuInput)
				{
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:
					system("CLS");
					try
					{
						cout << endl << "How many Dollars you want to add to your wallet?" << endl;
						cin >> userWhole;
					
						cout << endl << "How many Cents you want to add to your wallet?" << endl;
						cin >> userFractional;
					
					
						wallet.addCurrency("USD", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl << endl;
					cout << wallet[0] << endl << endl;
					system("pause");

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:
					system("CLS");
					try
					{
						cout << endl << "How many Euros you want to add to your wallet?" << endl;
						userWhole = getUserInputInt(1, 1000000);

						cout << endl << "How many Cents you want to add to your wallet?" << endl;
						userFractional = getUserInputInt(1, 100000);

						wallet.addCurrency("EUR", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e) 
					{
						cout << endl << e.what() << endl;
					}
					cout << endl << endl;
					cout << wallet[1] << endl << endl;
					system("pause");

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:
					system("CLS");
					try
					{
						cout << endl << "How many Yen you want to add to your wallet?" << endl;
						userWhole = getUserInputInt(1, 1000000);

						cout << endl << "How many Sen you want to add to your wallet?" << endl;
						userFractional = getUserInputInt(1, 100000);

						wallet.addCurrency("JPY", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e)
					{
						cout << endl << e.what() << endl;
					}
					cout << endl << endl;
					cout << wallet[2] << endl << endl;
					system("pause");

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:
					system("CLS");
					try
					{
						cout << endl << "How many Rupees you want to add to your wallet?" << endl;
						userWhole = getUserInputInt(1, 1000000);

						cout << endl << "How many Paise you want to add to your wallet?" << endl;
						userFractional = getUserInputInt(1, 100000);

						wallet.addCurrency("INR", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e)
					{
						cout << endl << e.what() << endl;
					}
					cout << endl << endl;
					cout << wallet[3] << endl << endl;
					system("pause");

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:
					system("CLS");
					try
					{
						cout << endl << "How many Yuan you want to add to your wallet?" << endl;
						userWhole = getUserInputInt(1, 1000000);

						cout << endl << "How many Fens you want to add to your wallet?" << endl;
						userFractional = getUserInputInt(1, 100000);

						wallet.addCurrency("JPY", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e)
					{
						cout << endl << e.what() << endl;
					}
					cout << endl << endl;
					cout << wallet[4] << endl << endl;
					system("pause");

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK:
					break;
				default:
					break;
				}
			} while (subMenuInput != UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
			break;

		case UI::MAIN_MENU_OPTIONS::MAIN_SUBSTRACT:
			do
			{
				displayAddRemoveTotalMenu();
				cout << UI::PROMPT_OPTION;
				subMenuInput = getUserInputInt(UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS, UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);

				switch (subMenuInput)
				{
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:
					system("CLS");
					try
					{
						cout << endl << "How many Dollars you want to delete of your wallet?" << endl;
						cin >> userWhole;

						cout << endl << "How many Cents you want to delete of your wallet?" << endl;
						cin >> userFractional;


						wallet.removeCurrency("USD", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl << endl;
					cout << wallet[0] << endl << endl;
					system("pause");
					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:
					system("CLS");
					try
					{
						cout << endl << "How many Euros you want to delete of your wallet?" << endl;
						cin >> userWhole;

						cout << endl << "How many Cents you want to delete of your wallet?" << endl;
						cin >> userFractional;


						wallet.addCurrency("EUR", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl << endl;
					cout << wallet[1] << endl << endl;
					system("pause");
					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:
					system("CLS");
					try
					{
						cout << endl << "How many Yen you want to delete of your wallet?" << endl;
						cin >> userWhole;

						cout << endl << "How many Sen you want to delete of your wallet?" << endl;
						cin >> userFractional;


						wallet.addCurrency("JPY", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl << endl;
					cout << wallet[2] << endl << endl;
					system("pause");
					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:
					system("CLS");
					try
					{
						cout << endl << "How many Rupees you want to delete of your wallet?" << endl;
						cin >> userWhole;

						cout << endl << "How many Paise you want delete of your wallet?" << endl;
						cin >> userFractional;


						wallet.addCurrency("INR", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl << endl;
					cout << wallet[3] << endl << endl;
					system("pause");
					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:
					system("CLS");
					try
					{
						cout << endl << "How many Yuan you want to delete of your wallet?" << endl;
						cin >> userWhole;

						cout << endl << "How many Fens you want to delete of your wallet?" << endl;
						cin >> userFractional;


						wallet.addCurrency("CNY", userWhole, userFractional);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl << endl;
					cout << wallet[4] << endl << endl;
					system("pause");
					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK:
					break;
				default:
					break;
				}
			} while (subMenuInput != UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
			break;
		case UI::MAIN_MENU_OPTIONS::MAIN_TOTAL:
			int subsubMenu;
			do
			{
				displayTotalMenu();
				cout << UI::PROMPT_OPTION;
				subMenuInput = getUserInputInt(UI::TOTAL_CURRENCY_OPTIONS::TOTAL_NON_ZERO, UI::TOTAL_CURRENCY_OPTIONS::TOTAL_INDIVIDUAL);

				switch (subMenuInput)
				{
				case UI::TOTAL_CURRENCY_OPTIONS::TOTAL_NON_ZERO:
					cout << endl << "This many currencies ARE NOT zero: " << wallet.getNumNonZeroCurrency() << endl << endl;
					break;
				case UI::TOTAL_CURRENCY_OPTIONS::TOTAL_OF_ZERO:
					cout << endl << "This many currencies ARE zero: " << wallet.getNumNonZeroCurrency() << endl << endl;
					break;
				case UI::TOTAL_CURRENCY_OPTIONS::TOTAL_INDIVIDUAL:
					displayAddRemoveTotalMenu();
					cout << UI::PROMPT_OPTION;
					subsubMenu = getUserInputInt(UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS, UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
					switch (subsubMenu)
					{
					case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:
						cout << endl << "The total number of Dollars is: " << "$" << wallet[0].getTotalWholeParts() << endl << endl;
						break;
					case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:
						cout << endl << "The total number of Euros is: " << "" << wallet[1].getTotalWholeParts() << endl << endl;
						break;
					case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:
						cout << endl << "The total number of Yen are: " << "" << wallet[2].getTotalWholeParts() << endl << endl;
						break;
					case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:
						cout << endl << "The total number of Rupee are: " << "" << wallet[3].getTotalWholeParts() << endl << endl;
						break;
					case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:
						cout << endl << "The total number of Yuan are: " << "" << wallet[4].getTotalWholeParts() << endl << endl;
						break;
					case UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK:

					default:
						break;
					}
				default:
					break;
				}

			} while (subMenuInput != UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
			break;
		case UI::MAIN_MENU_OPTIONS::MAIN_EMPTY:
			
			system("CLS");
			int userInt;

			cout << endl << "Are you sure you want to empty all currency? [1]YES [2]NO : ";
			cin >> userInt;
			if (userInt == 1)
			{
				wallet.emptyAllCurrency();
				cout << endl << "All currency was set equal to zero" << endl;
				system("pause");
			}else
				system("pause");
			break;
			
		default:
			break;
		}

	} while (inputMain != UI::MAIN_MENU_OPTIONS::MAIN_EXIT);



	system("pause");
	return 0;
}

void printWallet()
{
	system("CLS");

	Wallet wallet(0, 0, 0, 0, 0);

	cout << endl << endl << "\t\t\t  [ YOUR WALLET ]" << endl << endl;
	cout << "\t\t\t" << "Dollars " << wallet[0].getWholeParts() << " and " << wallet[0].getFractionalParts() << " Cents" << endl;
	cout << "\t\t\t" << "Euros " << wallet[1].getWholeParts() << " and " << wallet[1].getFractionalParts() << " Cents" << endl;
	cout << "\t\t\t" << "Yen " << wallet[2].getWholeParts() << " and " << wallet[2].getFractionalParts() << " Sen" << endl;
	cout << "\t\t\t" << "Rupee " << wallet[3].getWholeParts() << " and " << wallet[3].getFractionalParts() << " Paise" << endl;
	cout << "\t\t\t" << "Yuan " << wallet[4].getWholeParts() << " and " << wallet[4].getFractionalParts() << " Fens" << endl << endl;


	return;
}

void displayMainMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string walletText = "[ OPERATIONS ]";
	const string addText = "[ 1 ] ADD CURRENCY";
	const string substractText = "[ 2 ] SUBSTRACT CURRENCY";
	const string totalText = "[ 3 ] TOTAL CURRENCY";
	const string emptyText = "[ 4 ] EMPTY WALLET";
	const string exitText = "[ 5 ] EXIT";

	const size_t titleMargin = (UI::TERMINAL_WIDTH + walletText.length()) / 2;
	const size_t optionMargin = (titleMargin - walletText.length());

	printWallet();
	cout << right << bars << endl  << setw(titleMargin) << endl  << walletText << endl << endl;

	cout << setw(optionMargin + addText.length()) << addText << endl << endl
		<< setw(optionMargin + substractText.length()) << substractText << endl << endl
		<< setw(optionMargin + totalText.length()) << totalText << endl << endl
		<< setw(optionMargin + emptyText.length()) << emptyText << endl << endl
		<< setw(optionMargin + exitText.length()) << exitText << endl << endl
		<< bars << endl << endl;


	return;
}

void displayAddRemoveTotalMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string currencyText = "[ CURRENCY ]";
	const string dollarText = "[ 0 ] DOLLAR";
	const string eurosText = "[ 1 ] EURO";
	const string yenText = "[ 2 ] YEN";
	const string rupeeText = "[ 3 ] RUPEE";
	const string yuanText = "[ 4 ] YUAN";
	const string backText = "[ 5 ] BACK";

	const size_t titleMargin = (UI::TERMINAL_WIDTH + currencyText.length()) / 2;
	const size_t optionMargin = titleMargin - currencyText.length();

	cout << right << setw(titleMargin) << endl << currencyText << endl << endl << bars << endl << endl;

	cout << setw(optionMargin + dollarText.length()) << dollarText << endl << endl
		<< setw(optionMargin + eurosText.length()) << eurosText << endl << endl
		<< setw(optionMargin + yenText.length()) << yenText << endl << endl
		<< setw(optionMargin + rupeeText.length()) << rupeeText << endl << endl
		<< setw(optionMargin + yuanText.length()) << yuanText << endl << endl
		<< setw(optionMargin + backText.length()) << backText << endl << endl
		<< bars << endl << endl;
}


void displayTotalMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string totalText = "[ TOTAL ]";
	const string totalNonText = "[ 1 ] TOTAL NUMBER OF NON-ZERO CURRENCIES";
	const string totalZeroText = "[ 2 ] TOTAL NUMBER OF CURRENCIES AS ZERO";
	const string totalByNameText = "[ 3 ] TOTAL CURRENCY BY NAME";
	const string backText = "[ 4 ] BACK";

	const size_t titleMargin = (UI::TERMINAL_WIDTH + totalText.length()) / 2;
	const size_t optionMargin = titleMargin - totalText.length();

	cout << right << setw(titleMargin) << endl << totalText << endl << endl << bars << endl << endl;

	cout << setw(optionMargin + totalNonText.length()) << totalNonText << endl << endl
		<< setw(optionMargin + totalZeroText.length()) << totalZeroText << endl << endl
		<< setw(optionMargin + totalByNameText.length()) << totalByNameText << endl << endl
		<< setw(optionMargin + backText.length()) << backText << endl << endl
		<< bars << endl << endl;

	return;
}


void displayEmptyMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string emptyText = "[ EMPTY ]";
	const string checkCurrencyText = "[ 1 ] CHECK IF A CURRENCY IS EMPTY";
	const string checkWalletText = "[ 2 ] CHECK IF WALLET IS EMPTY";
	const string emptyCurrencyText = "[ 3 ] EMPTY A SPECIFIC CURRENCY";
	const string emptyWalletText = "[ 4 ] EMPTY Wallet";
	const string backText = "[ 5 ] BACK";

	const size_t titleMargin = (UI::TERMINAL_WIDTH + emptyText.length()) / 2;
	const size_t optionMargin = titleMargin - emptyText.length();

	cout << right << setw(titleMargin) << endl << emptyText << endl << endl << bars << endl << endl;

	cout << setw(optionMargin + checkCurrencyText.length()) << checkCurrencyText << endl << endl
		<< setw(optionMargin + checkWalletText.length()) << checkWalletText << endl << endl
		<< setw(optionMargin + emptyCurrencyText.length()) << emptyCurrencyText << endl << endl
		<< setw(optionMargin + emptyWalletText.length()) << emptyWalletText << endl << endl
		<< setw(optionMargin + backText.length()) << backText << endl << endl
		<< bars << endl << endl;

	return;


	return;
}
/*************************
** HELPER FUNCTIONS
**************************/

string generateBars(int number)
{
	string bars = string();
	string bar = UI::BARS;

	for (int i = 0; i < number; i++)
	{
		bars.append(bar);
	}

	return bars;
}

int getUserInputInt(const int& min, const int& max)
{
	string input;
	int inputInt;
	bool err;

	do
	{
		err = false;

		getline(cin, input);

		//Exception handling
		try
		{
			inputInt = stoi(input);

			//Input must be between min and max
			if (inputInt < min || inputInt > max)
			{
				cerr << UI::ERR_INVALID_OPTION_RANGE << min << " and " << max << " inclusive." << endl;
				err = true;
			}
		}

		catch (invalid_argument&)
		{
			cerr << UI::ERR_EXCEPTION_INVALID_ARGUMENT << endl;
			err = true;
		}
		catch (out_of_range&)
		{
			cerr << UI::ERR_EXCEPTION_OUT_OF_RANGE << endl;
			err = true;
		}
		catch (...)
		{
			cerr << UI::ERR_EXCEPTION_GENERIC << endl;
			err = true;
		}
	

	} while (err || !cin);

	return inputInt;
}
