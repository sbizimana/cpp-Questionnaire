#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int factualQuestions(string fullName, double age);
int sortingQuestions();
int iqQuestions(double age, int favNum);
int iqQuestions(double age, double favNum);
int highOrLow(double age);
int recall(string sex, string fullName, double age);

int main() {
	start:
	string fullName, sex, stopStart;
	int totalScore = 0, favNumI = 0, totalScoreAvg;
	char gender, yesOrNo, yesOrNo1;
	double age, favNumD = 0;

	cout << "Hello. My name is Winston. Welcome to The Questionnaire.\n" <<
		"Here I will test your mental capacity with a series of challenges, tasks, and quesitons.\n" <<
		"There will be five different tests in which you will be graded 0-100.\n" <<
		"Your overall score will be the average of all the tests.\n" <<
		"Please read carefully. Follow the directions specifically. And good luck.\n" <<
		"Press the enter key to continue.\n";
	cin.ignore();
	do {
		cout << "\nBefore we begin, please input your full name followed by the enter key.\nFull Name: ";
		getline(cin, fullName);
		cout << "\nPlease enter your age followed by the enter key.\nAge: ";
		cin >> age;
		while (age <= 0 || age > 122) {
			cout << "I find it extremely hard to believe you are that age... please try again taking the truthful route.\nAge: ";
			cin >> age;
		}
		cout << "\nNext we will attain your favorite number. Does your favorite number contain a decimal point? \n'Y' or 'N': ";
		cin >> yesOrNo1;
		while (yesOrNo1 != 'Y' && yesOrNo1 != 'y' && yesOrNo1 != 'n' && yesOrNo1 != 'N') {
			cout << "You must enter 'Y' or 'N'. All other characters are invalid.\n";
			cout << "Enter 'Y' for yes or 'N' for no: ";
			cin >> yesOrNo;
		}
		cout << "\nOkay, now please enter your favorite number. \nFavorite Number: ";
		if (yesOrNo1 == 'Y' || yesOrNo1 == 'y') {
			cin >> favNumD;
		}
		else {
			cin >> favNumI;
		}
		cout << "\nThank you. Lastly, please enter your gender. 'M' for male or 'F' for female.\nGender: ";
		cin >> gender;
		if (gender != 'M' && gender != 'F' && gender != 'f' && gender != 'm') {
		one:
			cout << "Sorry but the character you've entered doesn't correspond to either genders. Please try again.\nGender: ";
			cin >> gender;
			while (gender != 'M' && gender != 'F' && gender != 'f' && gender != 'm') {
				goto one;
			}
		}
		if (gender == 'M' || gender == 'm') {
			sex = "male";
		}
		else {
			sex = "female";
		}
		if (yesOrNo1 == 'y' || yesOrNo1 == 'Y') {
			cout << "\nOkay " << fullName << ", you are " << age << " years old, your favorite number is " << favNumD << ", and your gender is " << sex << ".\n";
		}
		else {
			cout << "\nOkay " << fullName << ", you are " << age << " years old, your favorite number is " << favNumI << ", and your gender is " << sex << ".\n";
		}
		cout << "\nWould you like to change any of the information you've given so far?\nEnter 'Y' for yes or 'N' for no: ";
		cin >> yesOrNo;
		while (yesOrNo != 'Y' && yesOrNo != 'y' && yesOrNo != 'n' && yesOrNo != 'N') {
			cout << "You must enter 'Y' or 'N'. All other characters are invalid.\n";
			cout << "Enter 'Y' for yes or 'N' for no: ";
			cin >> yesOrNo;
		}
	} while (yesOrNo == 'Y' || yesOrNo == 'y');

	cout << "\nNow that we have that squared out, press enter to begin.\n\n";
	cin.get();
	cin.ignore();
	
	totalScore += factualQuestions(fullName, age);
	totalScore += sortingQuestions();
	if (yesOrNo == 'y' || yesOrNo1 == 'Y') {
		totalScore += iqQuestions(age, favNumD);
	}
	else {
		totalScore += iqQuestions(age, favNumI);
	}
	totalScore += highOrLow(age);
	totalScore += recall(sex, fullName, age);

	totalScoreAvg = totalScore / 5;
	cout << "\n\n\Congratualtions " << fullName << " for completing The Questionnaire!\n\n";
	cout << "Your total score is... " << totalScoreAvg << "!\n\n";
	cout << "Score rankings are shown below\n\n";
	cout << "0-9   = Terrible" << endl;
	cout << "10-19 = Horrible" << endl;
	cout << "20-29 = Bad" << endl;
	cout << "30-39 = Close" << endl;
	cout << "40-49 = Almost" << endl;
	cout << "50-59 = Nice" << endl;
	cout << "60-69 = Good" << endl;
	cout << "70-79 = Great" << endl;
	cout << "80-89 = Amazing" << endl;
	cout << "90-99 = Spectacular" << endl;
	cout << "100-  = God-Like" << endl;

	cout << "\n\nEnter 'Start' to go back to the beginning or 'Stop' to finish: ";
	cin >> stopStart;
	if (stopStart == "Start" || stopStart == "start") {
		goto start;
	}
	else if (stopStart == "Stop" || stopStart == "stop") {
		cout << "\n\nI've been Winston and thank you for participating in The Questionairre!\n\n";
	}
	system("pause");
	return 0;
}

int factualQuestions(string fullName, double age) {
	int score = 0, answerOne;
	char answerTwo, answerThree, answerFour, answerFive, yOrN;

	for (int i = 1; i <= 3; i++) {
		cout << fullName << ", this first section will be a series of 5 factual questions.\nEach questions is worth 20 points.\n\n";
		cout << "Press enter to proceed. \n\n";
		cin.ignore();

		cout << "Question One: What is 32 plus your age?\n";
		cout << "Answer One: ";
		cin >> answerOne;
		if (answerOne == 32 + age) {
			score += 20;
		}
		cout << "\nQuestion Two: Which is more valuable,\nA) A pound of quarters\nor\nB) A kilogram of quarters\n\nEnter 'A' or 'B'\n";
		cout << "Answer Two: ";
		cin >> answerTwo;
		if (answerTwo == 'A' || answerTwo == 'a') {
			score += 20;
		}
		cout << "\nQuestion Three: How many months are in a decade?\n";
		cout << "A) 10 \nB) 100 \nC) 1200 \nD) 120\n";
		cout << "Answer Three: ";
		cin >> answerThree;
		if (answerThree == 'D' || answerThree == 'd') {
			score += 20;
		}
		cout << "\nQuestion Four: Which shape has the most sides?\n";
		cout << "A) Rectangle \nB) Pentagon \nC) Heptagon \nD) Triangle\n";
		cout << "Answer Four: ";
		cin >> answerFour;
		if (answerFour == 'C' || answerFour == 'c') {
			score += 20;
		}
		cout << "\nQuestion Five: What is the chemical symbol for Iron?\n";
		cout << "A) I \nB) Fe \nC) Ir \nD) Li\n";
		cout << "Answer Five: ";
		cin >> answerFive;
		if (answerFive == 'B' || answerFive == 'b') {
			score += 20;
		}
		if (i == 1) {
			cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
		if (i == 2) {
			cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
			
		}
	}
	return score;
}

int sortingQuestions() {
	int score = 0, answerOne, answerThree;
	char answerTwo, answerFour, yOrN;
	string nameOne, nameTwo, nameThree, nameFour, nameFive, one, two, three, four, five, answerFive;

	cout << "In this next section you will be asked to sort a number of items based on certain criteria. \nEach questions is worth 20 points.\n\n";
	cout << "Press enter to proceed. \n\n";
	cin.get();
	cin.ignore();

	ofstream inputFile;
	inputFile.open("List.txt");

	cout << "First, enter the first names of 5 people you know.\n";
	cout << "Name 1: ";
	cin >> nameOne;
	inputFile << nameOne << endl;
	cout << "Name 2: ";
	cin >> nameTwo;
	inputFile << nameTwo << endl;
	cout << "Name 3: ";
	cin >> nameThree;
	inputFile << nameThree << endl;
	cout << "Name 4: ";
	cin >> nameFour;
	inputFile << nameFour << endl;
	cout << "Name 5: ";
	cin >> nameFive;
	inputFile << nameFive << endl;
	inputFile.close();

	ifstream outputFile;
	outputFile.open("List.txt");
	cout << "\nNow I will ask you questions regarding the names in the order you entered them.\n\n";
	outputFile >> one >> two >> three >> four >> five;
	outputFile.close();

	for (int i = 1; i <= 3; i++) {
		cout << "Question One: Should " << three << " be in position 5, 3, or 1?\n";
		cout << "Answer One: ";
		cin >> answerOne;
		if (answerOne == 3) {
			score += 20;
		}
		cout << "\nQuestion Two: Should " << five << " be above or below " << two << "?\n";
		cout << "Enter 'A' for above or 'B' for below.\nAnswer Two: ";
		cin >> answerTwo;
		if (answerTwo == 'b' || answerTwo == 'B') {
			score += 20;
		}
		cout << "\nQuestion Three: Should " << one << " be in first or in fourth?\n";
		cout << "Enter 1 for first or 4 for fourth.\nAnswer Three: ";
		cin >> answerThree;
		if (answerThree == 1) {
			score += 20;
		}
		cout << "\nQuestion Four: Does the list of names below match the order of yours? \n'Y' or 'N'?\n";
		cout << one << endl << two << endl << three << endl << five << endl << four << endl;
		cout << "Answer Four: ";
		cin >> answerFour;
		if (answerFour == 'N' || answerFour == 'n') {
			score += 20;
		}
		cout << "\nQuestion Five: What name that you entered is missing from the list below?\n";
		if (one != "Paul" && two != "Paul" && three != "Paul" && four != "Paul" && five != "Paul") {
			cout << one << endl << two << endl << "Paul" << endl << four << endl << five;
		}
		else if (one != "Sam" && two != "Sam" && three != "Sam" && four != "Sam" && five != "Sam") {
			cout << one << endl << two << endl << "Sam" << endl << four << endl << five;
		}
		else if (one != "Troy" && two != "Troy" && three != "Troy" && four != "Troy" && five != "Troy") {
			cout << one << endl << two << endl << "Troy" << endl << four << endl << five;
		}
		else if (one != "Emily" && two != "Emily" && three != "Emily" && four != "Emily" && five != "Emily") {
			cout << one << endl << two << endl << "Emily" << endl << four << endl << five;
		}
		else if (one != "Marie" && two != "Marie" && three != "Marie" && four != "Marie" && five != "Marie") {
			cout << one << endl << two << endl << "Marie" << endl << four << endl << five;
		}
		else if (one != "Janet" && two != "Janet" && three != "Janet" && four != "Janet" && five != "Janet") {
			cout << one << endl << two << endl << "Janet" << endl << four << endl << five;
		}
		cout << "\nAnswer Five: ";
		cin >> answerFive;
		if (answerFive == three) {
			score += 20;
		}
		if (i == 1) {
			cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
		if (i == 2) {
			cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
	}
	return score;
}

int iqQuestions(double age, int favNum) {
	int score = 0, answerTwo;
	string answerThree;
	char answerFour, yOrN;
	double answerOne;
	cout << "This next section will ask you a series of questions you'd find on a typical IQ test. \nEach questions is worth 25 points.\n\n";
	cout << "Press enter to proceed. \n\n";
	cin.get();
	cin.ignore();

	for (int i = 1; i <= 3; i++) {
		cout << "Question One: What is your favorite number minus half of your favorite number? \nAnswerOne: ";
		cin >> answerOne;
		if (favNum % 2 == 0) {
			if (answerOne == favNum / 2) {
				score += 25;
			}
		}
		else {
			if (answerOne == (favNum / 2) + .5) {
				score += 25;
			}
		}
		cout << "\nQuestion Two: " << age / 2 << " is to your age as 17 is to what number? \nAnswer Two: ";
		cin >> answerTwo;
		if (answerTwo == 34) {
			score += 25;
		}
		cout << "\nQuestion Three: What word from Group 1 has the closest meaning to a word in Group 2?\n";
		cout << "\nGroup 1:" << endl;
		cout << "\tA) Talkative \n" <<
			"\tB) Job \n" <<
			"\tC) Ecstatic \n";
		cout << "Group 2:" << endl;
		cout << "\tA) Angry \n" <<
			"\tB) Wind \n" <<
			"\tC) Loquacious \n";
		cout << "\nEnter your answer as the two letters that correspond with each word.\n" <<
			"(Exapmle: Enter AA if you believe the answer is Talkative and Angry.)\n";
		cout << "Answer Three: ";
		cin >> answerThree;
		if (answerThree == "AC" || answerThree == "ac") {
			score += 25;
		}
		cout << "\nQuestion Four: Which of the following can be rearranged into a 5-letter English word?\n";
		cout << "\n1. H R G S T\n" <<
			"2. R I L S A\n" <<
			"3. T O O M T\n" <<
			"4. W Q R G S\n";
		cout << "\nIs the answer; \nA) 1 and 4 \nB) 2 and 3 \nC) Only 2 \nD) All of them \nE) None of them\n";
		cout << "Answer Four: ";
		cin >> answerFour;
		if (answerFour == 'b' || answerFour == 'B') {
			score += 25;
		}
		if (i == 1) {
			cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
		if (i == 2) {
			cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
	}
	return score;
}

int iqQuestions(double age, double favNum) {
	int score = 0, answerTwo;
	string answerThree;
	char answerFour, yOrN;
	double answerOne;
	cout << "This next section will ask you a series of questions you'd find on a typical IQ test. \nEach questions is worth 25 points.\n\n";
	cout << "Press enter to proceed. \n\n";
	cin.get();
	cin.ignore();

	for (int i = 1; i <= 3; i++) {
		cout << "Question One: What is your favorite number minus half of your favorite number? \nAnswerOne: ";
		cin >> answerOne;
		if (answerOne == favNum / 2) {
			score += 25;
		}
		cout << "\nQuestion Two: " << age / 2 << " is to your age as 17 is to what number? \nAnswer Two: ";
		cin >> answerTwo;
		if (answerTwo == 34) {
			score += 25;
		}
		cout << "\nQuestion Three: What word from Group 1 has the closest meaning to a word in Group 2?\n";
		cout << "\nGroup 1:" << endl;
		cout << "\tA) Talkative \n" <<
			"\tB) Job \n" <<
			"\tC) Ecstatic \n";
		cout << "Group 2:" << endl;
		cout << "\tA) Angry \n" <<
			"\tB) Wind \n" <<
			"\tC) Loquacious \n";
		cout << "\nEnter your answer as the two letters that correspond with each word.\n" <<
			"(Exapmle: Enter AA if you believe the answer is Talkative and Angry.)\n";
		cout << "Answer Three: ";
		cin >> answerThree;
		if (answerThree == "AC" || answerThree == "ac") {
			score += 25;
		}
		cout << "\nQuestion Four: Which of the following can be rearranged into a 5-letter English word?\n";
		cout << "\n1. H R G S T\n" <<
			"2. R I L S A\n" <<
			"3. T O O M T\n" <<
			"4. W Q R G S\n";
		cout << "\nIs the answer; \nA) 1 and 4 \nB) 2 and 3 \nC) Only 2 \nD) All of them \nE) None of them\n";
		cout << "Answer Four: ";
		cin >> answerFour;
		if (answerFour == 'b' || answerFour == 'B') {
			score += 25;
		}
		if (i == 1) {
			cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
		if (i == 2) {
			cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
	}
	return score;
}

int highOrLow(double age) {
	int score = 0;
	char hiOrLow, yOrN;
	vector<int> randomNum;

	cout << "This next section will be a simple game of high or low. \nRandom numbers from 1-1000 will be generated and you must enter 'H' " <<
		"if the next number is more likely to be higher than the previous, or 'L' if the likelihood is lower.\nIf the likelihood is equal then enter 'E'." <<
		"\nEach correct answer is worth 10 points.\n\n";
	cout << "Press enter to begin.\n\n";
	cin.get();
	cin.ignore();

	for (int i = 1; i <= 3; i++) {
		srand(time(0));
		int a = 10;
		for (int i = 0; i < a; i++) {
			int b = rand() % 1000 + 1;
			randomNum.push_back(b);
			cout << "Does the next number have a greater likelihood to be higher or lower than " << randomNum[i] <<
				"?\nAnswer " << i + 1 << ": ";
			cin >> hiOrLow;
			while (hiOrLow != 'H' && hiOrLow != 'h' && hiOrLow != 'L' && hiOrLow != 'l' && hiOrLow != 'E' && hiOrLow != 'e') {
				cout << "The only valid inputs are 'H' 'L' or 'E'.Please try again. \nAnswer " << i + 1 << ": ";
				cin >> hiOrLow;
			}
			if ((randomNum[i] - 500) < 0) {
				if (hiOrLow == 'H' || hiOrLow == 'h') {
					score += 10;
				}
			}
			if ((randomNum[i] - 500) > 0) {
				if (hiOrLow == 'L' || hiOrLow == 'l') {
					score += 10;
				}
			}
			if ((randomNum[i] - 500) == 0) {
				if (hiOrLow == 'E' || hiOrLow == 'e') {
					score += 10;
				}
			}
		}
		cout << "Bonus Question: Would the next number generated have a greater likelihood to be higher or lower than you age multiplied by 15?";
		cout << "\nAnswer 11: ";
		cin >> hiOrLow;
		while (hiOrLow != 'H' && hiOrLow != 'h' && hiOrLow != 'L' && hiOrLow != 'l' && hiOrLow != 'E' && hiOrLow != 'e') {
			cout << "The only valid inputs are 'H' 'L' or 'E'.Please try again. \nAnswer 11: ";
			cin >> hiOrLow;
		}
		if (((age * 15) - 500) < 0) {
			if (hiOrLow == 'H' || hiOrLow == 'h') {
				score += 5;
			}
		}
		if (((age * 15) - 500) > 0) {
			if (hiOrLow == 'L' || hiOrLow == 'l') {
				score += 5;
			}
		}
		if (((age * 15) - 500) == 0) {
			if (hiOrLow == 'E' || hiOrLow == 'e') {
				score += 5;
			}
		}
		if (i == 1) {
			cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
		if (i == 2) {
			cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
	}
	return score;
}

int recall(string sex, string fullName, double age) {
	int score = 0;
	string answerOne;
	char answerTwo, answerThree, answerFour, yOrN;

	cout << "This final test will require you to recall information pertaining to The Questionnaire. Each answer is worth 25 points.\n";
	cout << "Press enter to continue.\n";
	cin.get();
	cin.ignore();

	for (int i = 1; i <= 3; i++) {
		cout << "\nQuestion One: What is my name?\n";
		cout << "Answer One: ";
		cin >> answerOne;
		if (answerOne == "Winston" || answerOne == "winston") {
			score += 25;
		}
		cout << "\nQuestion Two: What word was not in the beginning introduction?\n";
		cout << "A) Tasks \nB) Trials \nC) Challenges \nD) Questions";
		cout << "\nAnswer Two: ";
		cin >> answerTwo;
		if (answerTwo == 'B' || answerTwo == 'b') {
			score += 25;
		}
		cout << "\nQuestion Three: Was " << fullName << " the first thing you entered, was " << age << " the first thing you entered," <<
			" or was " << sex << " the first thing you entered?\n";
		cout << "Enter 'A' for " << fullName << ", enter 'B' for " << age << ", or enter 'C' for " << sex << ".\n";
		cout << "Answer Three: ";
		cin >> answerThree;
		if (answerThree == 'A' || answerThree == 'a') {
			score += 25;
		}
		cout << "\nQuestion Four: Was The Questionnaire enjoyable? (Trust me, there is a right answer)\n";
		cout << "Enter 'Y' for yes or 'N' for no.\nAnswer Four: ";
		cin >> answerFour;
		if (answerFour == 'y' || answerFour == 'Y') {
			score += 25;
		}
		if (i == 1) {
			cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test two more times if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
		if (i == 2) {
			cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
			cin >> yOrN;
			while (yOrN != 'y' && yOrN != 'Y' && yOrN != 'N' && yOrN != 'n') {
				cout << "The only valid inputs are 'Y' and 'N'. Please try again.\n";
				cout << "You may retake this test one more time if you wish. Would you like to try again? \n'Y' or 'N'?\n";
				cin >> yOrN;
			}
			if (yOrN == 'N' || yOrN == 'n') {
				break;
			}
			if (yOrN == 'y' || yOrN == 'Y') {
				score = 0;
			}
		}
	}
	return score;
}