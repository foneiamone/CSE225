/* Create a ContactBook class based on BinarySearchTree. Rename the struct Node to Contact.
The struct Contact will contain 4 things: string name, string phoneNumber, Contact *left, Contact *right.
The tree will be sorted based on the phoneNumber variable. */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Contact
{
	string name;
	string phoneNumber;
	Contact *left;
	Contact *right;
};

class ContactBook
{
private:
	Contact *strt;

	void addContact(Contact *&n, string name, string phoneNumber)
	{
		if (n == NULL)
		{
			n = new Contact;
			n->name = name;
			n->phoneNumber = phoneNumber;
			n->left = NULL;
			n->right = NULL;
		}

		else if (n->phoneNumber > phoneNumber)
		{
			addContact(n->left, name, phoneNumber);
		}

		else
		{
			addContact(n->right, name, phoneNumber);
		}
	}

	void viewContact(Contact *n)
	{
		if (n == NULL)
		{
			return;
		}

		viewContact(n->left);
		cout << n->name << ", ";
		cout << n->phoneNumber << "\n";
		viewContact(n->right);
	}

	void searchNameCount(Contact *n, string name, int *c)
	{
		if (n == NULL)
		{
			return;
		}

		searchNameCount(n->left, name, c);

		string s1 = name;
		string s2 = n->name;
		transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
		transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

		size_t found = s2.find(s1);
		if (found != string::npos)
		{
			*c += 1;
		}

		searchNameCount(n->right, name, c);
	}

	void searchNamePrint(Contact *n, string name)
	{
		if (n == NULL)
		{
			return;
		}

		searchNamePrint(n->left, name);

		string s1 = name;
		string s2 = n->name;
		transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
		transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

		size_t found = s2.find(s1);
		if (found != string::npos)
		{
			cout << n->name << ", ";
			cout << n->phoneNumber << "\n";
		}

		searchNamePrint(n->right, name);
	}

	void searchNumberPrint(Contact *n, string phNumber)
	{
		if (n == NULL)
		{
			return;
		}

		searchNumberPrint(n->left, phNumber);

		if (n->phoneNumber == phNumber)
		{
			cout << n->name << ", ";
			cout << n->phoneNumber << "\n";
		}

		searchNumberPrint(n->right, phNumber);
	}

	string findMinNumber(Contact *n)
	{
		if (n == NULL)
		{
			return "-1";
		}

		else if (n->left == NULL)
		{
			return n->phoneNumber;
		}

		else
		{
			return findMinNumber(n->left);
		}
	}

	string findMaxNumber(Contact *n)
	{
		if (n == NULL)
		{
			return "-1";
		}

		else if (n->right == NULL)
		{
			return n->phoneNumber;
		}

		else
		{
			return findMaxNumber(n->right);
		}
	}

	bool findNumber(Contact *n, string phNumebr)
	{
		if (n == NULL)
		{
			return false;
		}

		if (n->phoneNumber == phNumebr)
		{
			return true;
		}

		else if (n->phoneNumber > phNumebr)
		{
			return findNumber(n->left, phNumebr);
		}

		else
		{
			return findNumber(n->right, phNumebr);
		}
	}

	void deleteContact(Contact *&n, string phNumber)
	{
		if (n == NULL)
		{
			return;
		}

		if (n->phoneNumber == phNumber)
		{
			if (n->left == NULL && n->right == NULL)
			{
				delete n;
				n = NULL;
			}

			else if (n->left != NULL)
			{
				string maxLNumber = findMaxNumber(n->left);
				n->phoneNumber = maxLNumber;
				deleteContact(n->left, maxLNumber);
			}

			else
			{
				string minRNumber = findMinNumber(n->right);
				n->phoneNumber = minRNumber;
				deleteContact(n->right, minRNumber);
			}
		}

		else if (n->phoneNumber < phNumber)
		{
			deleteContact(n->right, phNumber);
		}

		else
		{
			deleteContact(n->left, phNumber);
		}
	}

	void deleteAllContacts(Contact *&n)
	{
		if (n == NULL)
		{
			return;
		}

		deleteAllContacts(n->left);
		deleteAllContacts(n->right);
		delete n;
		n = NULL;
	}

	int contactCount(Contact *n)
	{
		if (n == NULL)
		{
			return 0;
		}

		return 1 + contactCount(n->left) + contactCount(n->right);
	}

public:
	ContactBook()
	{
		strt = NULL;
	}

	void AddContact(string name, string phoneNumber)
	{
		addContact(strt, name, phoneNumber);
	}

	bool noContact()
	{
		if (strt == NULL)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	void ViewAllContacts()
	{
		cout << "\n*** View Contacts ***\n";

		if (noContact())
		{
			cout << "\nContact book is empty.\n\n";
		}

		else
		{
			cout << "\nShowing " << contactCount(strt) << " contacts:\n\n";
			viewContact(strt);
			cout << "\n";
		}
	}

	bool FindNumber(string phNumber)
	{
		return findNumber(strt, phNumber);
	}

	void SearchName(string name)
	{
		int c = 0;
		searchNameCount(strt, name, &c);
		cout << "\n";
		if (c > 0)
		{
			cout << c << " matches found:\n\n";
			searchNamePrint(strt, name);
			cout << "\n";
		}

		else
		{
			cout << "No match found.\n\n";
		}
	}

	void searchNumber(string phNumber)
	{
		cout << "\nContact found:\n\n";
		searchNumberPrint(strt, phNumber);
		cout << "\n";
	}

	void DeleteContact(string phNumber)
	{
		deleteContact(strt, phNumber);
		cout << "\nContact deleted successfully.\n\n";
	}

	void DeleteAllContacts()
	{
		deleteAllContacts(strt);
	}
};

void cbMenu()
{
	ContactBook c;
	string name, phNumber;
	char m;
	char num;

	while (1)
	{
		cout << "------Menu--------";
		cout << "\n1. View all contacts";
		cout << "\n2. Add new contact";
		cout << "\n3. Search a contact by name";
		cout << "\n4. Search a contact by phone number";
		cout << "\n5. Delete a contact";
		cout << "\n6. Delete all contacts";
		cout << "\n7. Exit program";
		cout << "\n--------------------";
		cout << "\nSelect an option(1 - 7) : ";
		cin >> num;
		cout << "--------------------\n";

		switch (num)
		{
		case '1':
			c.ViewAllContacts();
			break;
		case '2':
			cout << "\n*** Add New Contact ***\n";
			cout << "\n> Enter name: ";
			cin.ignore();
			getline(cin, name);
			cout << "> Enter phone number: ";
			cin >> phNumber;

			if (c.FindNumber(phNumber))
			{
				cout << "\nError: A contact with phone number " << phNumber << " already exists.\n\n";
			}

			else
			{
				c.AddContact(name, phNumber);
				cout << "\nContact added successfully.\n\n";
			}

			break;

		case '3':
			cout << "\n*** Search Contact By Name ***\n";
			cout << "\n> Enter name: ";
			cin >> name;

			c.SearchName(name);
			break;

		case '4':
			cout << "\n*** Search Contact By Phone Number ***\n";
			cout << "\n> Enter phone number: ";
			cin >> phNumber;

			if (c.FindNumber(phNumber))
			{
				c.searchNumber(phNumber);
			}

			else
			{
				cout << "\nNo contact found.\n\n";
			}

			break;

		case '5':
			cout << "\n*** Delete Contact ***\n";
			cout << "\n> Enter phone number: ";
			cin >> phNumber;

			if (c.FindNumber(phNumber))
			{
				c.searchNumber(phNumber);

				cout << "> Delete this contact? Enter y for yes, n for no: ";
				cin >> m;
				cout << "\n";

				if (m == 'y')
				{
					c.DeleteContact(phNumber);
				}

				else if (m == 'n')
				{
					cbMenu();
				}
			}

			else
			{
				cout << "\nNo contact found.\n\n";
			}
			break;

		case '6':
			cout << "\n*** Delete All Contacts ***";
			cout << "\n\n> Are you sure? Enter y for yes, n for no: ";
			cin >> m;

			if (m == 'y')
			{
				c.DeleteAllContacts();
				cout << "\nAll contacts deleted.\n\n";
			}

			else if (m == 'n')
			{
				cbMenu();
			}
			break;

		case '7':
			cout << "\n> Are you sure? Enter y for yes, n for no: ";
			cin >> m;
			cout << "\n";

			if (m == 'n')
			{
				cbMenu();
			}

			else if (m == 'y')
			{
				cout << "*** Thank you for using Contact Book ***";
				exit(0);
			}
			break;

		default:
			cout << "\nWrong input. Try again!\n\n";
			cbMenu();
			break;
		}
	}
}

int main()
{

	cout << "********************";
	cout << "\n***CONTACT BOOK***";
	cout << "\n********************\n\n";

	cbMenu();
}