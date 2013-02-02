/*
When John was a little kid he didn't have much to do. There was no internet, no Facebook, and no programs to hack on. So he did the only thing he could... he evaluated the beauty of strings in a quest to discover the most beautiful string in the world.

Given a string s, little Johnny defined the beauty of the string as the sum of the beauty of the letters in it.

The beauty of each letter is an integer between 1 and 26, inclusive, and no two letters have the same beauty. Johnny doesn't care about whether letters are uppercase or lowercase, so that doesn't affect the beauty of a letter. (Uppercase 'F' is exactly as beautiful as lowercase 'f', for example.)

You're a student writing a report on the youth of this famous hacker. You found the string that Johnny considered most beautiful. What is the maximum possible beauty of this string?

Input
-----
The input file consists of a single integer m followed by m lines.

Output
------
Your output should consist of, for each test case, a line containing the string "Case #x: y" where x is the case number (with 1 being the first case in the input file, 2 being the second, etc.) and y is the maximum beauty for that test case.

Constraints
-----------
5 ≤ m ≤ 50
2 ≤ length of s ≤ 500

Example input
-------------
5
ABbCcc
Good luck in the Facebook Hacker Cup this year!
Ignore punctuation, please :)
Sometimes test cases are hard to make up.
So I just go consult Professor Dalves

Example output
--------------
Case #1: 152
Case #2: 754
Case #3: 491
Case #4: 729
Case #5: 646
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void * a, const void * b)
{
	return ( *(int*)b - *(int*)a );
}

int main()
{
	char str[501];
	int c, i, numCases, caseNum, beauty, total;
	int *counts;
	counts = (int*) malloc (sizeof(int) * 26);

	scanf("%d\n", &numCases);
	
	for(caseNum=1; caseNum <= numCases; ++caseNum)
	{	
		// Reset character count array, total, beauty
		for(i=0; i < 26; ++i)
			counts[i] = 0;
		beauty = 26;
		total = 0;

		fgets(str, 501, stdin);
		int length = strlen(str);
	
		for(i=0; i < length; ++i)
		{
			c = str[i];
			if( !isalpha(c) )
				continue;

			c = tolower(c);
			// Count occurences of each character
			counts[c - 'a']++;
		}

		// Sort character counts from highest to lowest
		qsort (counts, 26, sizeof(int), compare);

		for(i=0; i < 26; ++i)
		{
			if( counts[i] == 0 )
				break;
			total += beauty * counts[i];
			beauty--;
		}

		printf("Case #%d: %d\n", caseNum, total);
	}

	free(counts);

	return 0;
}
