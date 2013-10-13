//MATT WALSH and Elbert Dockery
//10/10/2012
//Program 3: Best Boggle
//CS 
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <string.h>


using namespace std;



const int BoardSize = 6;
const int DictSize = 263533;
const int MaxWordLength = 18;
const int WordSize = 5;
const int MinWordSize = 3;
const int MaxWordSize = 16;



//PRINTS CURRENT BOARD GIVEN AS PARAMATER
void printBoard(char board[BoardSize][BoardSize])
{
	for(int i = 0; i < BoardSize; i++)
	{
		for(int j = ; j < BoardSize; j++)
		{
			cout << board[i][j] << "  ";
		}

		cout << endl;

	}
	cout << endl;
}

//CHECKS IF WORDTOFIND IS IN BOARDSINGLE
//EACH FOR LOOP CHECKS EVERY POSSIB
bool findWord(char wordToFind[], char boardSingle[])  
   {                                                  
	int length = strlen(wordToFind);

	for(int i = 7; i < 36; i++)
	{

		if(wordToFind[0] == boardSingle[i])
		{


			boardSingle[i] = toupper(boardSingle[i]);

			for(int j = i-7; j < i + 7; j++)
			{
				if(wordToFind[1] == boardSingle[j])
				{
					boardSingle[j] = toupper(boardSingle[j]);

					for(int k = j-7; k < j + 7; k++)
					{
						if(wordToFind[2] == boardSingle[k] && length == 3)
						{
							return true;
						}
						if(wordToFind[2] == boardSingle[k])
						{
							boardSingle[k] = toupper(boardSingle[k]);



							for(int l = k-7; l < k + 7; l++)
							{
								if(wordToFind[3] == boardSingle[l] && length == 4)
								{
									return true;
								}
								if(wordToFind[3] == boardSingle[l])
								{
									for(int m = l-7; m < l + 7; m++)
									{
										if(wordToFind[4] == boardSingle[m] && length == 5)
										{
											return true;
										}
										if(wordToFind[4] == boardSingle[m])
										{
											for(int n = m-7; n < m + 7; n++)
											{
												if(wordToFind[5] == boardSingle[n] && length == 6)
												{
													return true;
												}
												if(wordToFind[5] == boardSingle[n])
												{
													for(int o = n-7; o < n + 7; o++)
													{
														if(wordToFind[6] == boardSingle[o] && length == 7)
														{
															return true;
														}
														if(wordToFind[6] == boardSingle[o])
														{


														}

														if(o == n-5 || o == n+1)
														{
															o = o + 3;
														}

													}
													boardSingle[n] = tolower(boardSingle[n]);

												}

												if(n == m-5 || n == m+1)
												{
													n = n + 3;
												}

											}
											boardSingle[m] = tolower(boardSingle[m]);

										}

										if(m == l-5 || m == l+1)
										{
											m = m + 3;
										}

									}
									boardSingle[l] = tolower(boardSingle[l]);

								}

								if(l == k-5 || l == k+1)
								{
									l = l + 3;
								}

							}
							boardSingle[k] = tolower(boardSingle[k]);
						}

						if(k == j-5 || k == j+1)
						{
							k = k + 3;
						}
						boardSingle[k] = tolower(boardSingle[k]);

					}
					boardSingle[j] = tolower(boardSingle[j]);
				}

				if(j == i-5 || j == i+1)
				{
					j = j + 3;
				}
				boardSingle[j] = tolower(boardSingle[j]);
			}


			boardSingle[i] = tolower(boardSingle[i]);
		}




	}

	for(int a = 0; a <37; a++)
	{
		boardSingle[a] = tolower(boardSingle[a]);
	}
	return false;

}






int main()
{

	char theBoard [BoardSize][BoardSize];
	char theWords [DictSize][MaxWordLength];
	double charProb[26];
	int random;
	int wordRow = 0;
	unsigned long totalLetters = 0;
	int lastScore = 0;

	unsigned long charFrequency[26];

	for(int i = 0; i < 26; i++)
	{
		charFrequency[i] = 0;

	}

	srand( time( NULL ) );


	cout << "Matt Walsh and Elbert Dockery" << endl << "Program 3: Best Boggle" << endl << "Oct 18, 2012" << endl<<endl;




	//OPEN FILE
	ifstream inStream;
	inStream.open("words.txt");
	assert( !( inStream.fail()) );

	//READ FROM FILE AND STORE WORD BY WORD INTO ARRAY
	while ( inStream >> theWords[wordRow])
	{
		//CHECK IF THE WORD IS RIGHT LENGTH OTHERWISE OVERWRITE WITH NEXT WORD
		if(strlen(theWords[wordRow]) >= MinWordSize || strlen(theWords[wordRow]) <= MaxWordSize)
		{
			for(int i = 0; i <strlen(theWords[wordRow]);i++)
			{
				theWords[wordRow][i] = tolower(theWords[wordRow][i]);
			}
			if(strlen(theWords[wordRow]) > WordSize)
			{
				totalLetters = totalLetters + strlen(theWords[wordRow]);
			}

			wordRow++;
		}


	}



	//COUNT THE CHARACTER FREQUENCY

	for(int i =0; i < wordRow; i++)
	{
		if(strlen(theWords[i]) > 5)
		{
			for(int j = 0; j < 18; j++)
			{
				int thisChar = theWords[i][j] - 'a';

				if(thisChar >= 0 && thisChar <= 25)
				{
					charFrequency[thisChar]++;
				}

			}
		}

	}



	//CHANGE FREQUENCY USING PROBABILITY WITH ALL LETTERS IN THE WORDS


	for(int j = 0; j < 26; j++)
	{
		charProb[j] = (100*((1.0*charFrequency[j])/totalLetters))+1;
	}

	for(int h = 25; h >= 0; h--)
	{
		for(int k = 0; k < h; k++)
		{
			charProb[h] = charProb[h] + charProb[k];

		}

	}









	int timesRan = 0;

	while(timesRan < 1000)
	{





		//RANDOM BOARD USING CHAR FREQUENCY
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 6; j++)
			{
				if(i == 0 || i == 5 || j == 0 || j == 5)
				{
					theBoard[i][j] = '*';
				}

				else
				{

					random = (rand() % 126) + 1;






					for(int s = 0; s < 26; s++)
					{
						if(random < charProb[s])
						{
							random = s;

							break;
						}
					}


					theBoard[i][j] = 'a' + random;
				}
			}


		}






		//CHANGE TWO DIMINESIONAL BOARD TO SINGLE DIMENSIONAL TO MAKE IT EASIER TO SEARCH THROUGH
		char boardSingle [37];
		int iter = 0;
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 6; j++)
			{
				boardSingle[iter] = theBoard[i][j];
				iter++;
			}
		}





		//CHECK DICTIONARY AGAINST BOARD AND ADD FOUND WORDS TO WORDSFOUND ARRAY. KEEP COUNT OF WORDS FOUND
		char wordsFound[1000][18];
		int iterate = 0;
		int wordCount = 0;

		for(int k = 0; k < wordRow; k++)
		{
			if(findWord(theWords[k], boardSingle) == true)
			{


				strcpy(wordsFound[wordCount], theWords[k]);

				wordCount++;
				iterate++;

			}


		}

		//ADD UP THE SCORE

		int theScore = 0;
		for(int i = 0; i < wordCount; i++)
		{
			int theLength = strlen(wordsFound[i]);

			switch(theLength)
			{
			case 3: theScore = theScore + 1;
				break;
			case 4: theScore = theScore + 2;
				break;
			case 5: theScore = theScore + 4;
				break;


			}


		}



		//WRITE WORDS AND SCORE TO FILE IF THEY ARE THE CURRENT BEST
		if(theScore > lastScore)
		{
			printBoard(theBoard);
			cout << "Found " << wordCount << " words." << endl << endl;
			cout << "The score is: " << theScore << endl << endl;
			cout << "Words stored in results.txt" << endl << endl;

			lastScore = theScore;
			ofstream outStream;
			outStream.open( "results.txt");
			assert( ! outStream.fail() );
			for( int i=0; i<wordCount; i++) {
				outStream << wordsFound[i] << "\n";
			}
			outStream << "Points: " <<  theScore;

			outStream.close();

		}
		timesRan++;
	}








	return 0;
}



