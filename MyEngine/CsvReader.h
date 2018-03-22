#pragma once
#include <vector>

/**************************************
�@CSV�t�@�C���������N���X
 ***************************************/
class CsvReader
{
	//�ǂݍ��񂾃f�[�^�����Ă���2�����z��
	std::vector<std::vector<char*>> _data;

public:
	//�R���X�g���N�^
	CsvReader();

	//�f�X�g���N�^
	~CsvReader();

	//CSV�t�@�C���̃��[�h
	//�����FfileName�@�t�@�C����
	//�ߒl�F������true�@���s��false
	bool Load(char* fileName);

	//�u,�v���u���s�v�܂ł̕�������擾
	//�����Freuult	���ʂ�����A�h���X
	//�����Fdata[]�@���Ƃ̕�����f�[�^
	//�����Findex	�������ڂ��璲�ׂ邩
	//�ߒl�F�Ȃ�
	void GetToComma(char* result,char data[], int* index);

	//�w�肵���ʒu�̃f�[�^�𕶎���Ŏ擾
	//�����Fx,y�@�擾�������ʒu
	//�ߒl�F�擾����������
	char* GetString(int x, int y);

	//�w�肵���ʒu�̃f�[�^�𐮐��Ŏ擾
	//�����Fx,y�@�擾�������ʒu
	//�ߒl�F�擾�����l
	int GetValue(int x, int y);

	//�t�@�C���̗񐔂��擾
	//�����F�Ȃ�
	//�ߒl�F��
	int GetWidth();

	//�t�@�C���̍s�����擾
	//�����F�Ȃ�
	//�ߒl�F�s��
	int GetHeight();
};

