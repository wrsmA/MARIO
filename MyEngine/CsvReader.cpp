#include <Windows.h>
#include "CsvReader.h"


//�R���X�g���N�^
CsvReader::CsvReader()
{
	_data.clear();
}

//�f�X�g���N�^
CsvReader::~CsvReader()
{
	//�S�f�[�^���J��
	for (int y = 0; y < _data.size(); y++)
	{
		for (int x = 0; x < _data[y].size(); x++)
		{
			delete[] _data[y][x];
		}
	}
}

//CSV�t�@�C���̃��[�h
bool CsvReader::Load(char* fileName)
{
	//�t�@�C�����J��
	HANDLE hFile;
	hFile = CreateFile(fileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//�J���Ȃ�����
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	//�t�@�C���̃T�C�Y�i�������j�𒲂ׂ�
	DWORD fileSize = GetFileSize(hFile, NULL);

	//���ׂĂ̕�����������z���p��
	char* temp;
	temp = new char[fileSize];

	//�t�@�C���̒��g��z��ɓǂݍ���
	DWORD dwBytes = 0;
	ReadFile(hFile,	temp,(DWORD)strlen(temp),&dwBytes,NULL);

	//�J�����t�@�C�������
	CloseHandle(hFile);

	//1�s�̃f�[�^������z��
	std::vector<char*>	line;

	//���ׂ镶���̈ʒu
	int index = 0;

	//�Ō�̕����܂ŌJ��Ԃ�
	while (index < fileSize)
	{
		//index�����ڂ���u,�v���u���s�v�܂ł̕�������擾

		char val[4];
		GetToComma(val, temp, &index);

		//��������0�������Ƃ������Ƃ͍s��
		if (strlen(val) == 0)
		{
			//_data��1�s���ǉ�
			_data.push_back(line);

			//1�s�f�[�^���N���A
			line.clear();
			continue;
		}

		//1�̃f�[�^�i������j������ϐ���p�ӂ���
		char* str = new char[strlen(val) + 1];

		//�����ɓ����
		strcpy(str, val);

		//1�s���̃f�[�^�ɒǉ�
		line.push_back(str);
	}

	//�ǂݍ��񂾃f�[�^�͊J������
	delete[] temp;

	//����
	return true;
}

//�u,�v���u���s�v�܂ł̕�������擾
void CsvReader::GetToComma(char* result, char data[], int* index)
{
	int i = 0;

	//�u,�v�܂ňꕶ������chr�ɓ����
	while (data[*index] != ',' && data[*index] != '\n'&& data[*index] != '\r')
	{
		result[i] = data[*index];
		i++;
		(*index)++;
	}

	//�Ō�Ɂu\0�v��t����
	result[i] = '\0';
	i++;
	(*index)++;
}

//�w�肵���ʒu�̃f�[�^�𕶎���Ŏ擾
char* CsvReader::GetString(int x, int y)
{
	if (x < 0 || x >= GetWidth() || y < 0 || y >= GetHeight())
		return "";

	return _data[y][x];
}

//�w�肵���ʒu�̃f�[�^�𐮐��Ŏ擾
int CsvReader::GetValue(int x, int y)
{
	return atoi(GetString(x, y));
}

//�t�@�C���̗񐔂��擾
int CsvReader::GetWidth()
{
	return _data[0].size();
}

//�t�@�C���̍s�����擾
int CsvReader::GetHeight()
{
	return _data.size();
}