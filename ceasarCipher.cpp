// Gabe Mersy
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	char encrypt;
	int cipherValue;
	string message;
	cout << "Encrypt (e/E) or Decrypt (d/D)?" << endl;
	cin >> encrypt;

	if (encrypt == 'e' || encrypt == 'E')
	{
		// Checking for validity of cipher rotation value
		cout << "What is the cipher roation?" << endl;
		cin >> cipherValue;
		if (cipherValue <= 25 && cipherValue >= 0)
		{
			// Inputting message
			cout << "What is the message?" << endl;
			cin.ignore();
			getline(cin, message);
			int length = message.length();
			// Removing non-alphabetic characters
			for(int i = 0; i < length; i++)
			{
				char character = message.at(i);
				if (int(character) < 65)
				{
					// Remove this character
					message.erase(i,1);
					length--;
					i--;
				}

				else if (character == ' ')
				{
					message.erase(i,1);
					length--;
					i--;
				}

				else if(int(character) > 90 && int(character) < 97)
				{
					message.erase(i,1);
					length--;
					i--;

				}
				else if(int(character) > 122)
				{
					message.erase(i,1);
					length--;
					i--;

				}
			}
			// Converting to uppercase
			string testStr = "";
			for (int j = 0; j < length; j++)
			{
			char character = message.at(j);
			if (character >= 97 && character <= 122)
				{
					//Converting using the ASCII chart
					character = character-32;
					testStr += character;
				}
			else
				{
					character = character;
					testStr += character;
				}

			}
			message = testStr;



			// Encryption
			string result = "";
			length = message.length();
			for(int k = 0; k < length; k++)
			{
				int character = message.at(k);
				character = (int(character) - 65 + cipherValue)%26 + 65;
				result += character;
			}
			cout << "Translated message: " << result;
		}
		else
		{
			cout << "INVALID CIPHER ROTATION VALUE" << endl;
			return 0;
		}

	}
	else if (encrypt == 'd' || encrypt == 'D')
	{
		cout << "What is the cipher rotation value?" << endl;
		cin >> cipherValue;
		if (cipherValue <= 25 && cipherValue >= 0)
		{
			// Inputting message
			cout << "What is the message?" << endl;
			cin.ignore();
			getline(cin, message);
			int length = message.length();
			// Removing non-alphabetic characters
			for(int i = 0; i < length; i++)
			{
				char character = message.at(i);
				if (int(character) < 65)
				{
					// Remove this character
					message.erase(i,1);
					length--;
					i--;
				}

				else if (int(character) < 32)
				{
					// Remove this character
					message.erase(i,1);
					length--;
					i--;
				}

				else if(int(character) > 90 && int(character) < 97)
				{
					message.erase(i,1);
					length--;
					i--;

				}
				else if(int(character) > 122)
				{
					message.erase(i,1);
					length--;
					i--;

				}
			}
			// Converting to uppercase
			string testStr = "";
			for (int j = 0; j < length; j++)
			{
			char character = message.at(j);
			if (character >= 97 && character <= 122)
				{
					//Converting using the ASCII chart
					character = character-32;
					testStr += character;
				}
				else
				{
					character = character;
					testStr += character;
				}
			}
			message = testStr;

			// Decryption
			string result = "";
			length = message.length();
			for(int k = 0; k < length; k++)
			{
				int character = message.at(k);
				character = (int(character) + 65 - cipherValue)%26 + 65;
				result += character;
			}
			cout << "Translated message: " << result;
		}
		else
		{
			cout << "INVALID CIPHER ROTATION VALUE" << endl;
			return 0;
		}
	}
}
