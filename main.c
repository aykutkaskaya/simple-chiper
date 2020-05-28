#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

//global variables throughout the app
char selection[SIZE];
char input[SIZE];
char key[SIZE];

int inpLenWoBlank = 0;
int keyLenWoBlank = 0;

char table[][26] = {

  {
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   },
  {
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   },
  {
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   },
  {
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   },
  {
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   },
  {
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   },
  {
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   },
  {
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   },
  {
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   },
  {
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   },
  {
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   },
  {
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   },
  {
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   },
  {
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   },
  {
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   },
  {
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   },
  {
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   },
  {
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   },
  {
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   },
  {
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   },
  {
   'U',
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   },
  {
   'X',
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   },
  {
   'W',
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   },
  {
   'V',
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   },
  {
   'Y',
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   },
  {
   'A',
   'M',
   'B',
   'C',
   'D',
   'F',
   'E',
   'G',
   'H',
   'K',
   'J',
   'I',
   'S',
   'Z',
   'N',
   'O',
   'P',
   'Q',
   'R',
   'L',
   'T',
   'U',
   'X',
   'W',
   'V',
   'Y',
   },

};

int Menu ();
int Encrypt ();
int Decrypt ();

void ConvertToUpper (char[]);
void RemoveSpacesInput (char[]);
void RemoveSpacesKey (char[]);
void KeyGenislet (char[], int);
void KeyDaralt (char[], int);

int
main (void)
{

  int result = 0;
  do
    {
      result = Menu ();
    }
  while (result != 3);

  return -1;
}

int
Menu ()
{
  char temp;

  printf ("Simple Chiper:\n");
  printf ("[1] Encrypt\n[2] Decrypt\n[3] Exit\nSelection:");

  //get the selection
  scanf ("%[^\n]", selection);
  scanf ("%c", &temp);	
  

  if (selection[0] == '1')
    {

      //get the input
      printf ("\nEnter text: ");
      scanf ("%[^\n]", input);
      scanf ("%c", &temp);

      //get the key
      printf ("Enter key: ");
      scanf ("%[^\n]", key);

      ConvertToUpper (input);
      RemoveSpacesInput (input);
      ConvertToUpper (key);
      RemoveSpacesKey (key);

      Encrypt ();
      return 1;
    }

  else if (selection[0] == '2')
    {
      //get the input
      printf ("\nEnter ciphertext: ");
      scanf ("%[^\n]", input);
      scanf ("%c", &temp);	

      //get the key
      printf ("Enter key: ");
      scanf ("%[^\n]", key);

      ConvertToUpper (input);
      RemoveSpacesInput (input);
      ConvertToUpper (key);
      RemoveSpacesKey (key);

      Decrypt ();
      return 2;
    }

  else
    {
      return 3;
    }

  Menu ();
  return 0;
}

int
Encrypt ()
{
  char cipher[SIZE] = { };
  char cipher_final[SIZE] = { };

  if (inpLenWoBlank > keyLenWoBlank)
    {
      //keyi input karakter sayisina esitle
      KeyGenislet (key, inpLenWoBlank);
    }
  if (keyLenWoBlank > inpLenWoBlank)
    {
      //keyden input karakter sayisi kadar al
      KeyDaralt (key, inpLenWoBlank);
    }

  printf ("\n******************** Encryption ********************\n\n");

  printf ("Encryption Phase-1\n");
  printf ("\nPlaintext: %s", input);
  printf ("\nKey: %s", key);

  int col = 0, row = 0;

  for (int i = 0; i < inpLenWoBlank; i++)
    {
      col = (input[i] - 65);
      row = (key[i] - 65);

      char ch = table[row][col];
      cipher[i] = ch;
    }

  printf ("\nOutput (Phase-1): %s\n", cipher);

  printf ("\n\nEncryption Phase-2\n");

  int cipher_len = strlen (cipher);

  if (cipher_len % 2 != 0)
    {
      cipher[cipher_len] = '0';
      cipher[cipher_len + 1] = '\0';
    }
  cipher_len = strlen (cipher);

  printf ("Inputtext: %s\n", cipher);

  char group1[SIZE] = { }, group2[SIZE] =
  {
  };


  for (int i = 0; i < cipher_len / 2; i++)
    {
      group1[i] = cipher[i];
      group2[i] = cipher[i + (cipher_len / 2)];
    }

  printf ("\nGroup-1: %s", group1);
  printf ("\nGroup-2: %s", group2);
  for (int i = 0, j = 0; i < strlen (group1) * 2; i = i + 2)
    {
      cipher_final[i] = group1[j];
      cipher_final[i + 1] = group2[j++];
    }

  printf ("\n\nCipher Text: %s\n", cipher_final);
  printf ("\n****************************************************\n\n");
  getchar ();
  return 0;
}

int
Decrypt ()
{
  char cipher[SIZE] = { };
  char cipher_final[SIZE] = { };

  if (inpLenWoBlank > keyLenWoBlank)
    {
      //keyi input karakter sayisina esitle
      KeyGenislet (key, inpLenWoBlank);
    }
  if (keyLenWoBlank > inpLenWoBlank)
    {
      //keyden input karakter sayisi kadar al
      KeyDaralt (key, inpLenWoBlank);
    }

  printf ("\n******************** Decryption ********************\n\n");
  printf ("Decryption Phase-2\n");
  printf ("\nInputtext: %s", input);
  printf ("\nKey: %s", key);

  char group1[SIZE] = { }, group2[SIZE] =
  {
  };

  for (int i = 0, j = 0; i < inpLenWoBlank; i = i + 2, j++)
    {
      group1[j] = input[i];
      group2[j] = input[i + 1];
    }
  printf ("\nGroup-1: %s", group1);
  printf ("\nGroup-2: %s", group2);

  strcat (cipher_final, group1);

//remove latest zero if exist
  if (group2[strlen (group2) - 1] == '0')
    {
      group2[strlen (group2) - 1] = '\0';
    }

  strcat (cipher_final, group2);

  printf ("\nOutput (Phase-2): %s", cipher_final);

  printf ("Decryption Phase-1\n");
  printf ("\nInputtext: %s", cipher_final);
  printf ("\nKey: %s", key);

  int col = 0, row = 0;

  char finaltext[SIZE] = { };

  for (int i = 0; i < strlen (cipher_final); i++)
    {
      row = (key[i] - 65);

      for (int j = 0; j < 26; j++)
	{
	  if (table[row][j] == cipher_final[i])
	    {
        char c=j+65;
	      finaltext[i]=c;
	    }
	}
    }

  printf ("\n\nPlaintext: %s\n", finaltext);
  printf ("\n****************************************************\n\n");
  getchar ();
  return 0;
}

void
ConvertToUpper (char text[])
{
  for (int i = 0; text[i] != '\0'; i++)
    {
      text[i] = toupper (text[i]);
    }
}

void
RemoveSpacesInput (char text[])
{
  char tempArray[SIZE];
  //bosluklari Sil
  int m = 0, n = 0;

  while (text[m] != '\0')
    {
      if (text[m] != ' ')
	{

	  tempArray[n++] = text[m];
	}

      m++;
    }
  tempArray[n] = '\0';

  for (int i = 0; i < strlen (text); i++)
    {
      text[i] = ' ';
    }

  text[0] = '\0';

  for (int i = 0; i < strlen (tempArray); i++)
    {
      text[i] = tempArray[i];
    }

  inpLenWoBlank = strlen (tempArray);
}

void
RemoveSpacesKey (char text[])
{
  char tempArray[SIZE];
  //bosluklari Sil
  int m = 0, n = 0;

  while (text[m] != '\0')
    {
      if (text[m] != ' ')
	{

	  tempArray[n++] = text[m];
	}

      m++;
    }
  tempArray[n] = '\0';

  for (int i = 0; i < strlen (text); i++)
    {
      text[i] = ' ';
    }

  text[0] = '\0';

  for (int i = 0; i < strlen (tempArray); i++)
    {
      text[i] = tempArray[i];
    }

  keyLenWoBlank = strlen (tempArray);
}

void
KeyGenislet (char text[], int new_length)
{
  int old_length = strlen (text);
  for (int i = 0; i < inpLenWoBlank; i++)
    {
      text[i] = text[i % keyLenWoBlank];
    }
  RemoveSpacesKey (text);
}

void
KeyDaralt (char text[], int new_length)
{
  char tempArray[SIZE];
  for (int i = 0; i < inpLenWoBlank; i++)
    {
      tempArray[i] = text[i];
    }

  for (int i = 0; i < strlen (text); i++)
    {
      text[i] = ' ';
    }

  text[0] = '\0';

  for (int i = 0; i < strlen (tempArray); i++)
    {
      text[i] = tempArray[i];
    }
  RemoveSpacesKey (text);
}
