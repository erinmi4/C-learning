/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include <cctype>
using namespace std;

bool judgeVowel(char alphabet);

//删除输入中的元音字母，使用递归的方法，并且将剩余的内容全部都合并在一起
string onlyConnectize(string phrase) {
    if(phrase.empty()) {
        return "";
    }
    else {
        char ch = phrase[0];
        //如果输入不是字母 或者 输入的是元音，将其删除
        if(!isalpha(ch) || judgeVowel(ch)) {
            return onlyConnectize(phrase.substr(1));
        }
        else {
            std::string res(1, toupper(ch));  // Creates a string with the uppercase character
            return res + onlyConnectize(phrase.substr(1));  // Recursive call with the rest of the string

        }
    }
}

//识别一个字母是否是元音，无论大小写
bool judgeVowel(char alphabet) {
    char ch = toupper(alphabet);
    switch (ch) {
    case 'A':
        return true;
        break;
    case 'E':
        return true;
        break;
    case 'I':
        return true;
        break;
    case 'O':
        return true;
        break;
    case 'U':
        return true;
        break;
    default:
        return false;
        break;
    }
}





/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */
STUDENT_TEST("description of the test") {
    /* Put your testing code here. */
    //可能会输入空值
    EXPECT_EQUAL(onlyConnectize(""), "");
    //可能会输入非字母
    EXPECT_EQUAL(onlyConnectize("!@#$%^"), "");

}





