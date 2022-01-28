#include "pch.h"
#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

TEST(FirstTestCase, Punctuation)
{
	char* filename = "data.txt";
	char* inputFilePath = "AfterPunctuation.txt";
	char* outputFilePath = "output.txt";

	readInputFile(filename);

	removePunctuationMarks();

	writingTransactionLLToFile(outputFilePath);


	ifstream outputFile(outputFilePath);
	ifstream inputFile(inputFilePath);
	if (!outputFile.is_open() || !inputFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!inputFile.is_open()) {
			cout << inputFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (!inputFile.eof() || !outputFile.eof())
		{
			//If one of the file reaches eof before other that means a wrong output
			//Failing the test
			if (outputFile.eof() || inputFile.eof())
			{
				EXPECT_TRUE(false);
			}
			getline(inputFile, org);
			getline(outputFile, res);
			EXPECT_EQ(org, res);
		}

	}
	inputFile.close();
	outputFile.close();
}

TEST(SecondTestCase, UpperToLowerCase)
{
	char* filename = "data.txt";
	char* inputFilePath = "AfterUpperToLower.txt";
	char* outputFilePath = "output.txt";

	readInputFile(filename);

	convertUpperToLowerCase();

	writingTransactionLLToFile(outputFilePath);


	ifstream outputFile(outputFilePath);
	ifstream inputFile(inputFilePath);
	if (!outputFile.is_open() || !inputFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!inputFile.is_open()) {
			cout << inputFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (!inputFile.eof() || !outputFile.eof())
		{
			//If one of the file reaches eof before other that means a wrong output
			//Failing the test
			if (outputFile.eof() || inputFile.eof())
			{
				EXPECT_TRUE(false);
			}
			getline(inputFile, org);
			getline(outputFile, res);
			EXPECT_EQ(org, res);
		}

	}
	inputFile.close();
	outputFile.close();
}

TEST(ThirdTestCase, PunctuationUpperToLowerCase)
{
	char* filename = "data.txt";
	char* inputFilePath = "AfterPunctuationUpperToLower.txt";
	char* outputFilePath = "output.txt";

	readInputFile(filename);

	removePunctuationMarks();
	convertUpperToLowerCase();
	writingTransactionLLToFile(outputFilePath);


	ifstream outputFile(outputFilePath);
	ifstream inputFile(inputFilePath);
	if (!outputFile.is_open() || !inputFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!inputFile.is_open()) {
			cout << inputFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (!inputFile.eof() || !outputFile.eof())
		{
			//If one of the file reaches eof before other that means a wrong output
			//Failing the test
			if (outputFile.eof() || inputFile.eof())
			{
				EXPECT_TRUE(false);
			}
			getline(inputFile, org);
			getline(outputFile, res);
			EXPECT_EQ(org, res);
		}

	}
	inputFile.close();
	outputFile.close();
}


TEST(FourthTestCase, generateFirstItemSet)
{
	char* filename = "data.txt";
	char* inputFilePath = "afterFirstItemSet.txt";
	char* outputFilePath = "output.txt";
	char* frequency_test_file = "FrequencyItemSet.txt";
	char* frequency_output_file = "output1.txt";

	readInputFile(filename);

	removePunctuationMarks();
	convertUpperToLowerCase();

	generateFirstItemSet(frequency_output_file);

	writingTransactionLLToFile(outputFilePath);

	//Linked list matching
	ifstream outputFile;
	ifstream inputFile;
	outputFile.open(outputFilePath);
	inputFile.open(inputFilePath);
	if (!outputFile.is_open() || !inputFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!inputFile.is_open()) {
			cout << inputFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (!inputFile.eof() || !outputFile.eof())
		{
			//If one of the file reaches eof before other that means a wrong output
			//Failing the test
			if (outputFile.eof() || inputFile.eof())
			{
				EXPECT_TRUE(false);
			}
			getline(inputFile, org);
			getline(outputFile, res);
			EXPECT_EQ(org, res);
		}

	}
	inputFile.close();
	outputFile.close();

	//Frequency matching


	outputFile.open(frequency_output_file);
	if (!outputFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << frequency_output_file << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string res;
		vector<string> inputFileData;
		vector<string> outputFileData;
		inputFileData.push_back("bread(5)");
		inputFileData.push_back("juice(5)");
		for (int i = 0; i < inputFileData.size(); i++)
		{
			if (getline(outputFile, res)) {
				outputFileData.push_back(res);
			}
			else {
				//Failed to read data from file so test case failed
				ASSERT_TRUE(false);
			}
		}
		sort(inputFileData.begin(), inputFileData.end());
		sort(outputFileData.begin(), outputFileData.end());
		for (int i = 0; i < inputFileData.size(); i++)
		{
			EXPECT_EQ(inputFileData[i], outputFileData[i]);
		}
		if (getline(outputFile, res)) {
			EXPECT_EQ("cheese(4)", res);
		}
		else {
			//Failed to read data from file so test case failed
			ASSERT_TRUE(false);
		}
		if (getline(outputFile, res)) {
			EXPECT_EQ("milk(3)", res);
		}
		else {
			//Failed to read data from file so test case failed
			ASSERT_TRUE(false);
		}
	}
	outputFile.close();
}
bool cmp(pair<vector<string>, int>& a, pair<vector<string>, int>& b)
{
	if (a.first.size() != b.first.size())
	{
		return true;
	}
	for (int i = 0; i < a.first.size(); i++)
	{
		if (a.first[i] < b.first[i])
		{
			return true;
		}
	}
	return false;
}

bool testItem(ifstream& outputFile, map<vector<string>, int>& testData)
{
	string res;
	int count;
	map<vector<string>, int> outputData;
	for (int i = 0; i < testData.size(); i++)
	{
		vector<string> tempData;
		string s;
		if (getline(outputFile, res)) {
			//2nd last characters of the string contain count
			count = res[res.length() - 2] - 48;
			//Removing last 3 characters
			res.erase(res.length() - 3, 3);
			//Tokenizing string
			stringstream ss(res);
			while (getline(ss, s, ',')) {
				tempData.push_back(s);
			}
			sort(tempData.begin(), tempData.end());
			outputData.insert(pair<vector<string>, int>(tempData, count));
			for (int i = 0; i < tempData.size(); i++)
			{
				cout << tempData[i] << " ";
			}
			cout << endl;
		}
		else {
			//Failed to read data from file so test case failed
			return false;
		}
	}
	for (map<vector<string>, int>::iterator it = outputData.begin(); it != outputData.end(); it++)
	{
		bool found = false;
		for (map<vector<string>, int>::iterator it1 = testData.begin(); it1 != testData.end(); it1++)
		{
			bool matching = true;
			if ((it->first).size() != (it1->first).size()) {
				continue;
			}
			for (int i = 0; i < (it->first).size(); i++)
			{
				if ((it->first)[i] != (it1->first)[i])
				{
					matching = false;
					break;
				}
			}
			if (matching)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			return false;
		}
	}
	return true;
}
TEST(FifthTestCase, generateSecondItemSet)
{
	char* filename = "data.txt";
	char* frequency_test_file = "FrequencyItemSet2.txt";
	char* frequency_output_file = "output2.txt";
	char* outputFilePath = "output.txt";

	readInputFile(filename);

	removePunctuationMarks();
	convertUpperToLowerCase();

	generateSecondItemSet(frequency_output_file);

	writingTransactionLLToFile(outputFilePath);


	ifstream outputFile;
	outputFile.open(frequency_output_file);
	if (!outputFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << frequency_output_file << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		map<vector<string>, int> testData;
		testData.insert(pair<vector<string>, int>({ "bread","juice" }, 4));
		testData.insert(pair<vector<string>, int>({ "cheese","juice" }, 4));
		ASSERT_TRUE(testItem(outputFile, testData));
		map<vector<string>, int> testData1;
		testData1.insert(pair<vector<string>, int>({ "bread","cheese" }, 3));
		ASSERT_TRUE(testItem(outputFile, testData1));
	}
	//inputFile.close();
	outputFile.close();

}

TEST(SixthTestCase, generateThirdItemSet)
{
	char* filename = "data.txt";
	char* frequency_test_file = "FrequencyItemSet3.txt";
	char* frequency_output_file = "output3.txt";
	char* outputFilePath = "output.txt";

	readInputFile(filename);

	removePunctuationMarks();
	convertUpperToLowerCase();

	generateThirdItemSet(frequency_output_file);

	writingTransactionLLToFile(outputFilePath);

	ifstream outputFile;
	ifstream inputFile;
	outputFile.open(frequency_output_file);
	if (!outputFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << frequency_output_file << " File Not Found" << endl;
		}
	}
	else
	{
		map<vector<string>, int> testData;
		testData.insert(pair<vector<string>, int>({ "bread","cheese","juice" }, 3));
		ASSERT_TRUE(testItem(outputFile, testData));
	}
	outputFile.close();
}

TEST(FinalTestCase, AprioriTestCase)
{
	char* filename = "data.txt";
	char* frequency_test_file = "FrequencyItemSet3.txt";
	char* frequency_output1_file = "output1.txt";
	char* frequency_output2_file = "output2.txt";
	char* frequency_output_file = "output3.txt";
	char* outputFilePath = "output.txt";

	readInputFile(filename);

	removePunctuationMarks();
	convertUpperToLowerCase();

	generateFirstItemSet(frequency_output1_file);
	generateSecondItemSet(frequency_output2_file);
	generateThirdItemSet(frequency_output_file);

	writingTransactionLLToFile(outputFilePath);

	ifstream outputFile;
	ifstream inputFile;
	outputFile.open(frequency_output_file);
	inputFile.open(frequency_test_file);
	if (!outputFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << frequency_output_file << " File Not Found" << endl;
		}
	}
	else
	{
		map<vector<string>, int> testData;
		testData.insert(pair<vector<string>, int>({ "bread","cheese","juice" }, 3));
		ASSERT_TRUE(testItem(outputFile, testData));
	}
	outputFile.close();
}
