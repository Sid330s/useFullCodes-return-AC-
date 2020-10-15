#include<bits/stdc++.h>
using namespace std;



/*
Encryption
The plaintext(P) and key(K) are added modulo 26.
Ei = (Pi + Ki) mod 26

Decryption
Di = (Ei - Ki + 26) mod 26

https://www.cs.du.edu/~snarayan/crypt/vigenere.html

*/




string EncryptText(string str, string key)
{
	string cipher_text;
  int k = key.length();

	for (int i = 0; i < str.size(); i++)
	{

		char x = (str[i] + key[i%k]) %26;

		x += 'A';

		cipher_text.push_back(x);
	}
	return cipher_text;
}

string DecryptText(string cipher_text, string key)
{
	string orig_text;
  int k = key.length();
	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		char x = (cipher_text[i] - key[i%k] + 26) %26;

		x += 'A';
		orig_text.push_back(x);
	}
	return orig_text;
}

// Driver program to test the above function
int main()
{
  int t;

  cin>>t;

  while(t--){

    string str;
    string key;

    cin>>str;
    cin>>key;


    string cipher_text = EncryptText(str, key);

    cout << "Ciphertext : "<< cipher_text << "\n";

    cout << "Original/Decrypted Text : "<< DecryptText(cipher_text, key)<<'\n';



  }

  return 0;

}
