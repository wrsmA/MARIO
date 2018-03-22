
//�萔�錾
#define GAME_TITLE		"MARIO"	//�^�C�g���o�[�̕���
#define WINDOW_WIDTH	800					//�E�B���h�E�̕�
#define WINDOW_HEIGHT	600					//�E�B���h�E�̍���
#define WINDOW_MODE		TRUE				//TRUE�F�E�B���h�E�^FALSE�F�t���X�N���[��


//�C���N���[�h
#include "DxLib.h"
#include "MyEngine\\Game.h"


//�G���g���[�|�C���g
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//�����ݒ�
	SetWindowText(GAME_TITLE);						//�^�C�g���o�[�̕���
	ChangeWindowMode(WINDOW_MODE);					//�E�B���h�E���[�h
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16);	//��ʃ��[�h�̐ݒ�
	DxLib_Init();									//DX���C�u�����̏�����


	//�Q�[���N���X�̃C���X�^���X
	Game game;

	//�Q�[���̏�����
	game.Start();

	//�Q�[�����[�v
	while (true)
	{
		//�E�C���h�E�̃��b�Z�[�W����������
		if(ProcessMessage() != 0)	break;

		//��ʂ��N���A����
		if (ClearDrawScreen() != 0)	break;

		//�Q�[���̍X�V
		game.Update();

		//�t���b�v�֐�
		if (ScreenFlip() != 0)	break;
	}


	//�I������
	DxLib_End();	// DX���C�u�����I������
	return 0;
}