#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


struct stClient
{
	string Number;
	string pinCode;
	string name;
	string phone;
	double balance;
};

string readAccountNumber()
{
	string AccountNumber = "";
	cout << "\n Please Enter Account Number? ";
	cin >> AccountNumber;

	return AccountNumber;
}

vector <string> LineDataToVector(string line)
{//       A150#//#1234#//#Gomaa ElSherbini#//#00925365232#//#5000.000000
	vector <string> vClient;
	string delim = "#//#";
	short pos = 0;
	string clientItem = "";

	while ((pos = line.find(delim)) != -1)
	{
		clientItem = line.substr(0, pos);
		if (clientItem != "")
		{
			vClient.push_back(clientItem);
		}
		line.erase(0, pos + delim.length());
	}
	if (line != "")
	{
		vClient.push_back(line);
	}
	return vClient;
}

stClient VectorDataToStClient(vector <string> vClient)
{
	stClient client;

	client.Number = vClient[0];
	client.pinCode = vClient[1];
	client.name = vClient[2];
	client.phone = vClient[3];
	client.balance = stod(vClient[4]);

	return client;
}

vector <stClient> vectorStClienstAccounts(string fileName)
{
	fstream Clients;
	string line;
	stClient client;
	vector <stClient> vStClients;

	Clients.open(fileName, ios::in);

	if (Clients.is_open())
	{
		while (getline(Clients, line))
		{
			if (line != "")
			{
				client = VectorDataToStClient(LineDataToVector(line));
				vStClients.push_back(client);
			}
		}
		Clients.close();
	}
	return vStClients;
}

void printStClientData(stClient client)
{
	cout << "\nThe following are the eclient details:\n\n";

	cout << " Account Number:  " << client.Number << endl;
	cout << " Pin Code:  " << client.pinCode << endl;
	cout << " Name:  " << client.name << endl;
	cout << " Phone: " << client.phone << endl;
	cout << " Balance: " << client.balance << endl;

}

void printAccountWithAccontNumber(vector <stClient> vStClients, string AccountNumber)
{
	stClient client;
	for (stClient client : vStClients)
	{
		if(client.Number == AccountNumber)
		{
			printStClientData(client);
			return;
		}
		else
			continue;
	}
	cout << "\n Client with account Number (" << AccountNumber << ") Not Found!\n";
}

int main()
{
	string AccountNumber = readAccountNumber();
	vector <stClient> vStClients = vectorStClienstAccounts("clientInfo.txt");

	
	printAccountWithAccontNumber(vStClients, AccountNumber);
	

	
	system("pause>0");
	return main();
}
	
			
//stClient returnClient(vector <stClient> vStClients, string AccountNumber)
//{
//	for (stClient account : vStClients)
//	{
//		if (account.Number == AccountNumber)
//			return account;
//		//cout << account.name << endl;
//	}
//}
//
//void printAccountDetails(bool result, vector <stClient> vStClients, string AccountNumber)
//{
//	stClient client;
//	if (result)
//		printStClientData(returnClient(vStClients, AccountNumber));
//	else
//}

//vector <string> getAllClientsData(string fileName)
//{
//	fstream Clients;
//	vector <string> vClients;
//
//	Clients.open(fileName, ios::in);
//
//	string line;
//	if (Clients.is_open())
//	{
//		while (getline(Clients, line))
//		{
//			vClients.push_back(line);
//		}
//		Clients.close();
//	}
//	return vClients;
//}
// 
//stClient stAccountClientInfo(vector <string> vClients, string AccountNumber)
//{
//	stClient stClientInfo;
//
//	for (string& line : vClients)
//	{
//		stClientInfo = VectorDataToStClient(LineDataToVector(line));
//		
//		if(stClientInfo.Number == AccountNumber)
//			return stClientInfo;
//	}
//}
