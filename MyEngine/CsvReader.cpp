#include <Windows.h>
#include "CsvReader.h"


//コンストラクタ
CsvReader::CsvReader()
{
	_data.clear();
}

//デストラクタ
CsvReader::~CsvReader()
{
	//全データを開放
	for (int y = 0; y < _data.size(); y++)
	{
		for (int x = 0; x < _data[y].size(); x++)
		{
			delete[] _data[y][x];
		}
	}
}

//CSVファイルのロード
bool CsvReader::Load(char* fileName)
{
	//ファイルを開く
	HANDLE hFile;
	hFile = CreateFile(fileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//開けなかった
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	//ファイルのサイズ（文字数）を調べる
	DWORD fileSize = GetFileSize(hFile, NULL);

	//すべての文字を入れられる配列を用意
	char* temp;
	temp = new char[fileSize];

	//ファイルの中身を配列に読み込む
	DWORD dwBytes = 0;
	ReadFile(hFile,	temp,(DWORD)strlen(temp),&dwBytes,NULL);

	//開いたファイルを閉じる
	CloseHandle(hFile);

	//1行のデータを入れる配列
	std::vector<char*>	line;

	//調べる文字の位置
	int index = 0;

	//最後の文字まで繰り返す
	while (index < fileSize)
	{
		//index文字目から「,」か「改行」までの文字列を取得

		char val[4];
		GetToComma(val, temp, &index);

		//文字数が0だったということは行末
		if (strlen(val) == 0)
		{
			//_dataに1行分追加
			_data.push_back(line);

			//1行データをクリア
			line.clear();
			continue;
		}

		//1つのデータ（文字列）を入れる変数を用意して
		char* str = new char[strlen(val) + 1];

		//そこに入れて
		strcpy(str, val);

		//1行分のデータに追加
		line.push_back(str);
	}

	//読み込んだデータは開放する
	delete[] temp;

	//成功
	return true;
}

//「,」か「改行」までの文字列を取得
void CsvReader::GetToComma(char* result, char data[], int* index)
{
	int i = 0;

	//「,」まで一文字ずつchrに入れる
	while (data[*index] != ',' && data[*index] != '\n'&& data[*index] != '\r')
	{
		result[i] = data[*index];
		i++;
		(*index)++;
	}

	//最後に「\0」を付ける
	result[i] = '\0';
	i++;
	(*index)++;
}

//指定した位置のデータを文字列で取得
char* CsvReader::GetString(int x, int y)
{
	if (x < 0 || x >= GetWidth() || y < 0 || y >= GetHeight())
		return "";

	return _data[y][x];
}

//指定した位置のデータを整数で取得
int CsvReader::GetValue(int x, int y)
{
	return atoi(GetString(x, y));
}

//ファイルの列数を取得
int CsvReader::GetWidth()
{
	return _data[0].size();
}

//ファイルの行数を取得
int CsvReader::GetHeight()
{
	return _data.size();
}