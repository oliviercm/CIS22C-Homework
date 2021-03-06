﻿/*
CIS 22C
Lab 01: Create a currency and wallet class to emulate the behavior of a real life wallet and 5 different currencies.
Group Members:
Olivier Chan Sion Moy
Luis Guerrero
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Yen.h"
#include "Rupee.h"
#include "Yuan.h"
#include "Wallet.h"

using namespace std;

string generateBars(int number);
int getUserInputInt(const int& min = INT_MIN, const int& max = INT_MAX);
double getUserInputDouble(const double& min = DBL_MAX, const double& max = DBL_MAX);

void printWallet(Wallet& wallet);
void displayMainMenu();
void displayAddMenu();
void displayRemoveMenu();
void displayCurrencyMenu();
void displayTotalMenu();
void displayEmptyMenu();

namespace UI
{
	const int TERMINAL_WIDTH = 65;
	const int TERMINAL_HEIGHT = 30;

	const string BARS = "=";

	const string PROMPT_OPTION = "Pick an option: ";

	const string ERR_EXCEPTION_GENERIC = "ERROR: An exception occured.";
	const string ERR_EXCEPTION_INVALID_ARGUMENT = "ERROR: Invalid option, option is not a valid argument. Are you correctly typing a number or a string?";
	const string ERR_EXCEPTION_OUT_OF_RANGE = "ERROR: Invalid option, option is out of range.";
	const string ERR_INVALID_OPTION_RANGE = "ERROR: Invalid option, option must be between ";

	enum MAIN_MENU_OPTIONS { MAIN_NONE, MAIN_ADD, MAIN_SUBTRACT, MAIN_TOTAL, MAIN_EMPTY, MAIN_EXIT };
	enum PICK_CURRENCY_OPTIONS { CURRENCY_NONE, CURRENCY_DOLLARS, CURRENCY_EUROS, CURRENCY_YEN, CURRENCY_RUPEE, CURRENCY_YUAN, CURRENCY_BACK};
	enum TOTAL_CURRENCY_OPTIONS { TOTAL_NONE, TOTAL_NON_ZERO, TOTAL_OF_ZERO, TOTAL_INDIVIDUAL, TOTAL_BACK};
	enum EMPTY_OPTIONS { EMPTY_NONE, EMPTY_CHECK_CURRENCY, EMPTY_CHECK_WALLET, EMPTY_BY_NAME, EMPTY_ALL, EMPTY_BACK};
}


int main() 
{
	//GET USER INPUT
	int inputMain;

	//Objects.
	Wallet wallet(0, 0, 0, 0, 0);
	
	do
	{
		
		displayMainMenu();
		cout << "  [ YOUR WALLET ]" << endl << endl;
		printWallet(wallet);
		cout << endl;
		cout << UI::PROMPT_OPTION;
		inputMain = getUserInputInt(UI::MAIN_MENU_OPTIONS::MAIN_ADD, UI::MAIN_MENU_OPTIONS::MAIN_EXIT);

		switch (inputMain)
		{
			int subMenuInput;
			double addRemoveInput;
		case UI::MAIN_MENU_OPTIONS::MAIN_ADD:
			do
			{
				displayAddMenu();
				cout << "  [ YOUR WALLET ]" << endl << endl;
				printWallet(wallet);
				cout << endl;
				cout << UI::PROMPT_OPTION;
				subMenuInput = getUserInputInt(UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS, UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);

				switch (subMenuInput)
				{
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Dollars you want to add to your wallet?" << endl;
						addRemoveInput = getUserInputDouble(0);
					
						wallet.addCurrency("USD", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e)
					{
						cout << endl << e.what() << endl;
					}

					cout << endl;
					cout << wallet[0] << endl << endl;
					cin.get();

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Euros you want to add to your wallet?" << endl;
						addRemoveInput = getUserInputDouble(0);

						wallet.addCurrency("EUR", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e) 
					{
						cout << endl << e.what() << endl;
					}
					cout << endl;
					cout << wallet[1] << endl << endl;
					cin.get();

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Yen you want to add to your wallet?" << endl;
						addRemoveInput = getUserInputDouble(0);

						wallet.addCurrency("JPY", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e)
					{
						cout << endl << e.what() << endl;
					}
					cout << endl;
					cout << wallet[2] << endl << endl;
					cin.get();

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Rupees you want to add to your wallet?" << endl;
						addRemoveInput = getUserInputDouble(0);

						wallet.addCurrency("INR", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e)
					{
						cout << endl << e.what() << endl;
					}
					cout << endl;
					cout << wallet[3] << endl << endl;
					cin.get();

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Yuan you want to add to your wallet?" << endl;
						addRemoveInput = getUserInputDouble(0);

						wallet.addCurrency("CNY", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e)
					{
						cout << endl << e.what() << endl;
					}
					cout << endl;
					cout << wallet[4] << endl << endl;
					cin.get();

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK:
					break;
				default:
					break;
				}
			} while (subMenuInput != UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
			break;

		case UI::MAIN_MENU_OPTIONS::MAIN_SUBTRACT:
			do
			{
				displayRemoveMenu();
				cout << "  [ YOUR WALLET ]" << endl << endl;
				printWallet(wallet);
				cout << endl;
				cout << UI::PROMPT_OPTION;
				subMenuInput = getUserInputInt(UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS, UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);

				switch (subMenuInput)
				{
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Dollars do you want to remove from your wallet?" << endl;
						addRemoveInput = getUserInputDouble(0);

						wallet.removeCurrency("USD", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl;
					cout << wallet[0] << endl << endl;

					cin.get();
					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Euros do you want to remove from your wallet?" << endl;
						addRemoveInput = getUserInputDouble(0);


						wallet.removeCurrency("EUR", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl;
					cout << wallet[1] << endl << endl;
					cin.get();
					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Yen do you want to remove from your wallet" << endl;
						addRemoveInput = getUserInputDouble(0);


						wallet.removeCurrency("JPY", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl;
					cout << wallet[2] << endl << endl;
					cin.get();
					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Rupees do you want to remove from your wallet" << endl;
						addRemoveInput = getUserInputDouble(0);


						wallet.removeCurrency("INR", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl;
					cout << wallet[3] << endl << endl;
					cin.get();
					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:
					system("CLS");
					cout << "  [ YOUR WALLET ]" << endl << endl;
					printWallet(wallet);
					cout << endl;
					try
					{
						cout << endl << "How many Yuan do you want to remove from your wallet" << endl;
						addRemoveInput = getUserInputDouble(0);


						wallet.addCurrency("CNY", addRemoveInput);
					}
					catch (ExceptionCurrencyNegative& e) {
						cout << endl << e.what() << endl;
					}

					cout << endl;
					cout << wallet[4] << endl << endl;
					cin.get();
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
				subMenuInput = getUserInputInt(UI::TOTAL_CURRENCY_OPTIONS::TOTAL_NON_ZERO, UI::TOTAL_CURRENCY_OPTIONS::TOTAL_BACK);

				switch (subMenuInput)
				{
				case UI::TOTAL_CURRENCY_OPTIONS::TOTAL_NON_ZERO:
					cout << endl << "This many currencies ARE NOT zero: " << wallet.getNumNonZeroCurrency() << endl << endl;
					cin.get();
					break;
				case UI::TOTAL_CURRENCY_OPTIONS::TOTAL_OF_ZERO:
					cout << endl << "This many currencies ARE zero: " << wallet.getNumZeroCurrency() << endl << endl;
					cin.get();
					break;
				case UI::TOTAL_CURRENCY_OPTIONS::TOTAL_INDIVIDUAL:
					do
					{
						displayCurrencyMenu();
						cout << UI::PROMPT_OPTION;
						subsubMenu = getUserInputInt(UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS, UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
						switch (subsubMenu)
						{
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:
							cout << endl << "The total number of Dollars is: " << wallet[0].getTotalWholeParts() << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:
							cout << endl << "The total number of Euros is: " << wallet[1].getTotalWholeParts() << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:
							cout << endl << "The total number of Yen are: " << wallet[2].getTotalWholeParts() << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:
							cout << endl << "The total number of Rupees are: " << wallet[3].getTotalWholeParts() << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:
							cout << endl << "The total number of Yuan are: " << wallet[4].getTotalWholeParts() << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK:

						default:
							break;
						}
					} while (subsubMenu != UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
				case UI::TOTAL_CURRENCY_OPTIONS::TOTAL_BACK:
					break;
				default:
					break;
				}

			} while (subMenuInput != UI::TOTAL_CURRENCY_OPTIONS::TOTAL_BACK);
			break;
		case UI::MAIN_MENU_OPTIONS::MAIN_EMPTY:
			do
			{
				system("CLS");
				int userInt;

				displayEmptyMenu();
				cout << UI::PROMPT_OPTION;
				subMenuInput = getUserInputInt(UI::EMPTY_OPTIONS::EMPTY_CHECK_CURRENCY, UI::EMPTY_OPTIONS::EMPTY_BACK);
				switch (subMenuInput)
				{
				case UI::EMPTY_OPTIONS::EMPTY_CHECK_CURRENCY:
					do
					{
						displayCurrencyMenu();
						cout << UI::PROMPT_OPTION;
						subsubMenu = getUserInputInt(UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS, UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
						switch (subsubMenu)
						{
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:
							if (wallet.isCurrencyEmpty(0) == 1)
							{
								cout << endl << endl << "Dollars are not empty" << endl;
								cin.get();
							}
							else
								cout << endl << endl << "Dollars are empty" << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:
							if (wallet.isCurrencyEmpty(1) == 1)
							{
								cout << endl << endl << "Euros are not empty" << endl;
								cin.get();
							}
							else
								cout << endl << endl << "Euros are empty" << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:
							if (wallet.isCurrencyEmpty(2) == 1)
							{
								cout << endl << endl << "Yen are not empty" << endl;
								cin.get();
							}
							else
								cout << endl << endl << "Yen are empty" << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:
							if (wallet.isCurrencyEmpty(3) == 1)
							{
								cout << endl << endl << "Rupee are not empty" << endl;
								cin.get();
							}
							else
								cout << endl << endl << "Rupee are empty" << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:
							if (wallet.isCurrencyEmpty(4) == 1)
							{
								cout << endl << endl << "Yuan are not empty" << endl;
								cin.get();
							}
							else
								cout << endl << endl << "Yuan are empty" << endl;
							cin.get();
							break;
						default:
							break;
						}
					} while (subsubMenu != UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
					break;

				case UI::EMPTY_OPTIONS::EMPTY_CHECK_WALLET:
					if (wallet.isWalletEmpty() == 1)
					{
						cout << endl << endl << "Wallet is empty..." << endl;
						cin.get();
					}
					else
						cout << endl << endl << "Wallet is not empty..." << endl;
					cin.get();
					break;
				case UI::EMPTY_OPTIONS::EMPTY_BY_NAME:
					do
					{
						displayCurrencyMenu();
						cout << UI::PROMPT_OPTION;
						subsubMenu = getUserInputInt(UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS, UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
						switch (subsubMenu)
						{
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:
							wallet.emptyCurrency(0);
							cout << endl << "Emptying Dollars... " << endl;
							cout << wallet[0].getTotalWholeParts() << " Dollars" << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:
							wallet.emptyCurrency(1);
							cout << endl << "Emptying Euros... " << endl;
							cout << wallet[1].getTotalWholeParts() << " Euros" << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:
							wallet.emptyCurrency(2);
							cout << endl << "Emptying Yen... " << endl;
							cout << wallet[2].getTotalWholeParts() << " Yen" << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:
							wallet.emptyCurrency(3);
							cout << endl << "Emptying Rupees.. " << endl;
							cout << wallet[3].getTotalWholeParts() << "Rupee" << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:
							wallet.emptyCurrency(4);
							cout << endl << "Emptying Yuan... " << endl;
							cout << wallet[4].getTotalWholeParts() << "Yuan" << endl << endl;
							cin.get();
							break;
						case UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK:
							break;
						default:
							break;
						}
					} while (subsubMenu != UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
					break;
				case UI::EMPTY_OPTIONS::EMPTY_ALL:
			
					cout << endl << "Are you sure you want to empty all currencies? [1]YES [2]NO : ";
					cout << UI::PROMPT_OPTION;
					userInt = getUserInputInt(1, 2);
					if (userInt == 1)
					{
						wallet.emptyAllCurrency();
						cout << endl << "All currencies set equal to zero." << endl << endl;
						cin.get();
					}
					else
					cin.get();
					break;

				default:
					break;
				}
			} while (subMenuInput != UI::EMPTY_OPTIONS::EMPTY_BACK);
			break;
		default:
			break;
		}

	} while (inputMain != UI::MAIN_MENU_OPTIONS::MAIN_EXIT);

	return 0;
}


void displayMainMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string walletText = "[ OPERATIONS ]";
	const string addText = "[ 1 ] ADD CURRENCY";
	const string substractText = "[ 2 ] SUBTRACT CURRENCY";
	const string totalText = "[ 3 ] TOTAL CURRENCY";
	const string emptyText = "[ 4 ] EMPTY WALLET";
	const string exitText = "[ 5 ] EXIT";

	const size_t titleMargin = (UI::TERMINAL_WIDTH + walletText.length()) / 2;
	const size_t optionMargin = (titleMargin - walletText.length());


	cout << right << bars << endl  << setw(titleMargin) << endl  << walletText << endl << endl;

	cout << setw(optionMargin + addText.length()) << addText << endl << endl
		<< setw(optionMargin + substractText.length()) << substractText << endl << endl
		<< setw(optionMargin + totalText.length()) << totalText << endl << endl
		<< setw(optionMargin + emptyText.length()) << emptyText << endl << endl
		<< setw(optionMargin + exitText.length()) << exitText << endl << endl
		<< bars << endl << endl;


	return;
}

void displayAddMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string currencyText = "[ ADD ]";
	const string dollarText = "[ 1 ] DOLLAR";
	const string eurosText = "[ 2 ] EURO";
	const string yenText = "[ 3 ] YEN";
	const string rupeeText = "[ 4 ] RUPEE";
	const string yuanText = "[ 5 ] YUAN";
	const string backText = "[ 6 ] BACK";

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

	return;
}

void displayRemoveMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string currencyText = "[ REMOVE ]";
	const string dollarText = "[ 1 ] DOLLAR";
	const string eurosText = "[ 2 ] EURO";
	const string yenText = "[ 3 ] YEN";
	const string rupeeText = "[ 4 ] RUPEE";
	const string yuanText = "[ 5 ] YUAN";
	const string backText = "[ 6 ] BACK";

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

	return;
}


void displayCurrencyMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string currencyText = "[ CURRENCY ]";
	const string dollarText = "[ 1 ] DOLLAR";
	const string eurosText = "[ 2 ] EURO";
	const string yenText = "[ 3 ] YEN";
	const string rupeeText = "[ 4 ] RUPEE";
	const string yuanText = "[ 5 ] YUAN";
	const string backText = "[ 6 ] BACK";

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

	return;
}

void displayTotalMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string totalText = "[ TOTAL ]";
	const string totalNonText = "[ 1 ] TOTAL NON-ZERO CURRENCY";
	const string totalZeroText = "[ 2 ] TOTAL ZERO CURRENCY";
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
	const string emptyCurrencyText = "[ 3 ] EMPTY SPECIFIC CURRENCY";
	const string emptyWalletText = "[ 4 ] EMPTY ALL CURRENCIES";
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

double getUserInputDouble(const double& min, const double& max)
{
	string input;
	double inputDouble;
	bool err;

	do
	{
		err = false;

		getline(cin, input);

		//Exception handling
		try
		{
			inputDouble = stod(input);

			//Input must be between min and max
			if (inputDouble < min || inputDouble > max)
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

	return inputDouble;
}

string getUserInputString()
{
	string input;

	getline(cin, input);

	return input;
}

void printWallet(Wallet& wallet)
{
	cout << wallet[0] << endl;
	cout << wallet[1] << endl;
	cout << wallet[2] << endl;
	cout << wallet[3] << endl;
	cout << wallet[4] << endl;
}