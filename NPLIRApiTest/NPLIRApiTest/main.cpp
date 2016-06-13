#include "NLPIR.h"
#include "KeyExtract.h"
#include "LJSummary.h"
#pragma comment(lib, "NLPIR.lib")
#pragma comment(lib, "KeyExtract.lib")
#pragma comment(lib, "LJSummary.lib")

#include <io.h>
#include <direct.h>
#include <assert.h>
#include <conio.h>
#include <string>
#include <vector>

#include <string>
#include <iostream>

using namespace std;

const string DataPath = "";
int main(int argc, char *argv[])
{
	// initialize NLPIR
	if (NLPIR_Init(DataPath.c_str(), 0, ""))
	{
		cout << "initialized successfully\n" << endl;
	}
	else
	{
		cout << "failed to initialize" << endl << "press any key to exit" << endl;
		getchar();
		return 0;
	}

	// initialze a sentence
	string sSrc = "Bill Clinton是美国总统, 好像没来过北京理工大学, 喜欢吃小尾羊! ";
	cout << "origianl sentence: " << sSrc << endl << endl;
	// parse test
	//NLPIR_AddUserWord("小尾羊");
	//if (NLPIR_DelUsrWord("小尾羊") == -1)
	//{
	//	cout << "no" << endl;
	//}
	//else
	//	cout << "yes" << endl;
	string cutWord = NLPIR_ParagraphProcess(sSrc.c_str(), 1);
	cout << "original parse output: " << cutWord << endl;
	//cout << NLPIR_GetParagraphProcessAWordCount(sSrc.c_str())<<endl;
	//NLPIR_FileProcess("test.txt", "test_result.txt", 1);
	
	//// import user dict 
	//cout << "after importing user dict" << endl;
	//int nCount = NLPIR_ImportUserDict("userdic.txt");
	//cout << "imported " << nCount << " user word" << endl;
	//cutWord = NLPIR_ParagraphProcess(sSrc.c_str(), 1);
	//cout << "now the parse output: " << cutWord << endl;
	//NLPIR_AddUserWord("小尾羊");
	//cout << "after importing user dict2" << endl;
	//int nCount2 = NLPIR_ImportUserDict("userdic2.txt");
	//cout << "imported " << nCount2 << " user word" << endl;
	//cutWord = NLPIR_ParagraphProcess(sSrc.c_str(), 1);
	//cout << "now the parse output: " << cutWord << endl;

	//int count = 0;
	//const result_t * result = NLPIR_ParagraphProcessA(sSrc.c_str(), &count);
	//for (size_t i = 0; i < count; i++)
	//{
	//	printf("%d %d %s %d %d %d %d\n", result[i].start, result[i].length, result[i].sPOS,
	//		result[i].iPOS, result[i].word_ID, result[i].word_type, result[i].weight);
	//}

	// key word extract
	if (!KeyExtract_Init())
		cout << "keyextract initializes failed" << endl;
	else
		cout << "successfully initilized keyextract" << endl;

	const char* sKeyword = KeyExtract_GetKeyWords(sSrc.c_str());
	cout << sKeyword << endl;
	KeyExtract_Exit();

	if (!DS_Init("",GBK_CODE))
	{
		cout << "failed to initialize component" << endl;
	}
	else
		cout << "yes" << endl;

	NLPIR_Exit();
	getchar();
	return 0;
}