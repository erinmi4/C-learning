#include <iostream>
#include "console.h"
#include "testing/SimpleTest.h"
#include "tokenscanner.h" // At the top of your program
using namespace std;


/* We will assume that
 * this function works. It's fun to
 * implement. Try it!
 */
int syllablesIn(string word);

/* These are prototypes.
 * They let us call these functions
 * Before they're defined.
 */
bool isHaiku(string line1, string line2, string line3);
int syllablesInLine(string line);

int main() {
    string line1 = getLine("Enter the first line: ");
    string line2 = getLine("Now, enter the second line: ");
    string line3 = getLine("Enter the third line: ");

    /* Given these three lines,
     * check whether they're a haiku,
     * then show the result.
     */
    if (isHaiku(line1, line2, line3)) {
        cout << "The text you entered" << endl;
        cout << "Goes 5 - 7 - 5, so it" << endl;
        cout << "is a haiku. Yay!" << endl;
    } else {
        cout << "Though you have tried hard," << endl;
        cout << "The three lines you entered are" << endl;
        cout << "Not a haiku. Awww." << endl;
    }

    return 0;
}

/* Given a poem
 * of three lines, returns whether
 * it is a haiku.
 */
bool isHaiku(string line1, string line2, string line3) {
    return syllablesInLine(line1) == 5 &&
           syllablesInLine(line2) == 7 &&
           syllablesInLine(line3) == 5;
}

/* Counts the number of
 * syllables in a line of
 * text, then returns it.
 */
int syllablesInLine(string text) {
    /* To split apart the
     * text, make a TokenScanner
     * and configure it.
     */
    TokenScanner scanner(text);
    scanner.ignoreWhitespace();

    int numSyllables = 0;
    while (scanner.hasMoreTokens()) {
        /* If this token is
         * a word, count its syllables
         * and update total.
         */
        string token = scanner.nextToken();
        if (scanner.getTokenType(token) == TokenScanner::TokenType::WORD) {
            numSyllables += syllablesIn(token);
        }
    }

    return numSyllables;
}

/* Did you notice that
 * all the comments are haikus?
 * Same with the output!
 */
