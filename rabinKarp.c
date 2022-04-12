#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to implement the Rabin Karp algorithm
void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt


	// Calculate the hash value of pattern and first window of text
	for (i = 0; i < M; i++) {
		p = (int)(p+pat[i]*pow(4,M-i-1)) % q;
		t = (int)(t+txt[i]*pow(4,M-i-1)) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++) {

		//If the hash values match then only check for characters on by one
		if (p == t) {
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j])
					break;
			}

			if (j == M)
				printf("Pattern found at index %d \n", i);
		}

		// Calculate hash value for next window of text
		if (i < N - M) {
			t = (int)(4 * (t - txt[i] * pow(4,M-1)) + txt[i + M]) % q;

			// We might get negative value of t, converting it
			// to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

/* Driver program to test implement Rabin Karp function */
int main()
{
	char txt[] = "ATGCATA";
	char pat[] = "ATA";
	int q = 101; // A prime number
	search(pat, txt, q);
	return 0;
}
