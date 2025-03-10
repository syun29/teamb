#include"Game/Player.h"
#include"System/TaskManager.h"
#include"Game/Enemy.h"
#include "Game/EnemyManager.h"
#include"Game/Field.h"
#include"UI/Score.h"
#include"System/Nomal.h"
#include "Game/SterManager.h"
Enemy* g_enemy = nullptr;

void MainLoop(void) {
	//--------------------------------------------------------------
	//�Q�[�����̓����͂����ɏ���
	//�Q�[�����͂��̊֐�_��1�b�Ԃ�60��Ăяo���Ă���
	//--------------------------------------------------------------
	//�[�[�[�[���[�[�[�[
	//ADD_RESOURCE("field", CImage::CreateImage("Image/Field.png" ));
	











	//�[�[�[�[�叟�[�[�[�[

	//�S�^�X�N���X�V
	TaskManager::Instance()->Update();

	//�S�Ẵ^�X�N��`��
	TaskManager::Instance()->Render();

	TaskManager::Instance()->Collision();












}

void Init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//�u�����h�̗L����
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//�Œ�V�F�[�_�[�p
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	CFPS::SetFPS(DEFAULT_FPS);
	//�t���[�����䏉����
	CFPS::Init();
	//�{�^���̐ݒ�
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'C');
	CInput::SetButton(0, CInput::eButton4, VK_LSHIFT);
	CInput::SetButton(0, CInput::eButton5, VK_SPACE);
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, 'W');
	CInput::SetButton(0, CInput::eDown, 'S');
	CInput::SetButton(0, CInput::eLeft, 'A');
	CInput::SetButton(0, CInput::eRight, 'D');
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);

	//�}�E�X��\��
//	CInput::ShowCursor(false);
//	CInput::SetMouseInside(true);
	CInput::Update();
	CInput::Update();


	//���C�g�ݒ�
	CLight::SetType(0, CLight::eLight_Direction);
	CLight::SetPos(0, CVector3D(0, 200, 200));
	CLight::SetDir(0, CVector3D(0, -1, 0.5).GetNormalize());
	CLight::SetColor(1, CVector3D(0.4f, 0.4f, 0.4f), CVector3D(0.6f, 0.6f, 0.6f));



	CLight::SetFogParam(CVector4D(1, 1, 1, 1), 1200, 1400);

	//�J����������
	CCamera::GetCamera()->LookAt(CVector3D(5, 5, 5),
		CVector3D(0, 0, 0),
		CVector3D(0.0, 1.0, 0.0));

	SetCurrentDirectory("data");



	CShader::GetInstance("StaticMesh");
	CShader::GetInstance("SkinMesh");
	CSound::GetInstance();
	CLight::Init();


	//-----------------------------------------------------
	//�������̖��߂�����
	//�Q�[���N�����Ɉ�x�����Ă΂��
	//-----------------------------------------------------
	//----���----
	
	 
	ADD_RESOURCE("tri", CImage::CreateImage("Image/tri02.png"));
	ADD_RESOURCE("quad", CImage::CreateImage("Image/quad02.png"));
	ADD_RESOURCE("penta", CImage::CreateImage("Image/penta02.png"));

	ADD_RESOURCE("Score", CImage::CreateImage("Image/Score01.png"));
	new Score(CVector2D(1700,300));

	ADD_RESOURCE("Enemy", CImage::CreateImage("Image/UFO.25.png"));
	
	new Enemy(
		CVector3D(2500.0f, 100.0f, 0.0f), CVector3D(20.0f, 20.0f, 20.0f));
	//new EnemyManager;

	new SterManager;











	//----�叟----

	ADD_RESOURCE("Player", CImage::CreateImage("Image/player.png",Player::ANIM_DATA,260,260));

	ADD_RESOURCE("Nomal", CImage::CreateImage("Image/nomal.png",Nomal::ANIM_DATA,137,137));

	ADD_RESOURCE("BackGround", CImage::CreateImage("Image/background.png"));
	ADD_RESOURCE("Ground", CImage::CreateImage("Image/ground.png"));

	//�v���C���[�𐶐�
	new Player(
	CVector3D(150.0f, 100.0f, 0.0f),CVector3D(20.0f,20.0f,20.0f));

	new Nomal(
		CVector3D(160.0f, 100.0f, 0.0f));

	new Field(
		CVector3D(100.0f, 100.0f, 0.0f));




}


void Release()
{

	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//��ʉ𑜓x�ϓ�
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//��ʉ𑜓x�Œ�
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, (float)w, (float)h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 0.5, 1000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//�t���X�N���[��?�E�C���h�E���[�h�̐؂�ւ�
//Alt+Enter�Ő؂�ւ���
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// ���������[�N���o
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//�@.dll�̃p�X�w��
	char path[256];
	GetCurrentDirectory(256, path);
	strcat_s(path, 255, "\\dll");
	SetDllDirectory(path);

	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(VSYNC);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);
	
	//�O�ʃ{�[�_�[����
	//SetWindowLong(GL::hWnd, GWL_STYLE, WS_POPUP);
	//SetWindowPos(GL::hWnd, HWND_TOP, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_SHOWWINDOW);
	Init();


	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	LARGE_INTEGER time_buf;
	QueryPerformanceCounter(&time_buf);
	float fps = 0;
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();
		CInput::Update();
		//�e�o�b�t�@�[���N���A
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();
		//FONT_T()->Draw(0, 32, 1, 0, 0, "fps:%3d", (int)CFPS::GetFPS(), (int)fps);



		glfwSwapBuffers(GL::window);
		CFPS::Wait();

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			GL::isQuit = true;
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();

	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}
