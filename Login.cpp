#include <iostream>
using namespace std;


string name[10] = { "Jason Thomas", "Ray Koval", "Jackie Hunt", "Joe Reeves", "Mark Heard", "Lorin Finn", "Gabriel Wilson", "Jackson Lee", "Martin Perez", "Parker Collins" };
string userName[10] = { "Jason1", "Ray1", "Jackie1", "Joe1", "Mark1", "Lorin1", "Gabriel1", "Jackson1", "Martin1", "Parker1" };
string password1[10] = { "Harshly22@", "Libra22/", "Maniacs66[", "Cabs33?", "Sludge33#", "Longing4&4", "Gowns00[", "Peep5_5", "Apparel66?", "Stunts8:8" };
string password2[10] = { "Alum9/9", "Leopard3<3", "Sweets2$", "Minnie1^1", "Verily6:6", "Carte4.4", "Vividly5/5", "Pare8]9", "Censure3*6", "Pretext7}9" };
string password3[10] = { "Detract8#9", "Classy4)9", "Thorpe0.9", "Caddy7#9", "Dazed5^6", "Bran3>6", "Smacks2&6", "Spurt49*", "Canary0(6", "Warms2#6" };


int menu() {
	int choice;
	cout << "\n1. Log in\n";
	cout << "2. Change Password\n";
	cout << "3. Exit\n";
	cout << "Enter one of the menu options above: ";
	cin >> choice;
	return choice;
}
void strongVsSecure(string pass) {
	int numCount = 0;
	int specialCharacter = 0;
	int lengthStr = pass.length();
	int lowerCase = 0;
	int	upperCase = 0;
	for (int i = 0; i < lengthStr; i++) {
		if (isupper(pass[i]))
			upperCase++;
		if (islower(pass[i]))
			lowerCase++;
	}
	for (int x = 0; x < lengthStr; x++) {
		if (isdigit((unsigned char)pass[x])) {
			numCount += 1;
		}
	}
	for (int x = 0; x < lengthStr; x++) {
		if ((pass[x] >= 48 && pass[x] <= 57) ||
			(pass[x] >= 65 && pass[x] <= 90) ||
			(pass[x] >= 97 && pass[x] <= 122)) {

		}
		else specialCharacter++;

	}
	if (lengthStr >= 6 && specialCharacter < 2)
		cout << "\nYour password is Strong.";
	if (lengthStr >= 8 && specialCharacter >= 2)
		cout << "\nYour password is Very Secure";
	cout << "\nHere is the output of data for your password: ";
	cout << "\nThere is " << lengthStr << " Characters.";
	cout << "\nThere is " << numCount << " numbers.";
	cout << "\nThere is " << upperCase << " uppercase letters.";
	cout << "\nThere is " << lowerCase << " lowercase letters.";
	cout << "\nThere is " << specialCharacter << " symbols.";
}
bool checkPassword(string pass) {
	int numCount = 0;
	bool specialCharacter = false;
	int lengthStr = pass.length();
	int lowerCase = 0;
	int	upperCase = 0;
	for (int i = 0; i < lengthStr; i++) {
		if (isupper(pass[i]))
			upperCase++;
		if (islower(pass[i]))
			lowerCase++;
	}
	for (int x = 0; x < lengthStr; x++) {
		if (isdigit((unsigned char)pass[x])) {
			numCount += 1;
		}
	}
	for (int x = 0; x < lengthStr; x++) {
		if ((pass[x] >= 48 && pass[x] <= 57) ||
			(pass[x] >= 65 && pass[x] <= 90) ||
			(pass[x] >= 97 && pass[x] <= 122)) {
			specialCharacter = false;
		}
		else {
			specialCharacter = true;
			break;
		}
	}
	if (lengthStr >= 6 && lengthStr <= 45 && lowerCase >= 1 && upperCase >= 1 && numCount >= 2 && specialCharacter == true)
		return true;
	if (lengthStr < 6)
		cout << "You entered a password of less than 6 characters";
	if (lowerCase < 1)
		cout << "\nYou need to have at least 1 lowercase letter in the password.";
	if (upperCase < 1)
		cout << "\nYou need to have at least 1 uppercase letter in the password.";
	if (numCount < 2)
		cout << "\n You need to have at least 2 numbers in the password.";
	if (specialCharacter == false)
		cout << "\n You need to have at least 1 special character.";
	if (lengthStr >= 46)
		cout << "You entered a password greater than 45 characters";
	return false;
}
void changePassword() {
	string username, password;
	cout << "Enter User Id: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	int userEntry = -10;
	for (int i = 0; i < 10; i++) {
		if (username == userName[i] && password == password1[i]) {
			userEntry = i;
			break;
		}
	}
	if (userEntry != -10) {
		string newPassword;
		cout << "Succesfully logged in";
		while (true)
		{
			cout << "\nEnter new password: ";
			cin >> newPassword;
			while (username == newPassword) {
				cout << "Your password can not be the same as your User Id. Enter another password: ";
				cin >> newPassword;
			}
			while (newPassword == password1[userEntry] || newPassword == password2[userEntry] || newPassword == password3[userEntry]) {
				cout << "You can not use a password you have used within the past three resets try again: ";
				cin >> newPassword;
			}
			if (checkPassword(newPassword))
				break;

		}
		strongVsSecure(newPassword);
		string verify;
		cout << "\nConfirm new password:";
		cin >> verify;
		if (verify == newPassword) {
			cout << "\nYour password is set.";
			password1[userEntry] = newPassword;
		}
		else
			cout << "You entered a wrong username or password.";
	}
	if (userEntry == -10) {
		cout << "You entered a wrong username or password.";
	}
}
void login() {
	string username, password;
	cout << "Enter User Id: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	int userEntry = -10;
	for (int i = 0; i < 10; i++) {
		if (username == userName[i] && password == password1[i]) {
			userEntry = i;
			break;
		}
	}
	if (userEntry != -10)
		cout << "Welcome " + username;
	else
		cout << "Wrong password or Wrong username: try again";
}
int main() {

	while (true)
	{
		int choice = menu();
		switch (choice) {
		case 1:
			login();
			break;
		case 2:
			changePassword();
			break;
		case 3:
			cout << "Exiting program...";
			return 0;
		default:
			cout << "You entered a number not in the menu.";
			break;
		}

	}
}