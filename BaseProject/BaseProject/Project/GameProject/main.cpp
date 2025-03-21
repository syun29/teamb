#include"Game/Player.h"
#include"System/TaskManager.h"
#include"Game/Enemy.h"
#include "Game/EnemyManager.h"
#include"Game/Field.h"
#include"UI/Score.h"
#include"Game/Nomal.h"
#include "Game/SterManager.h"
#include "Game/Constellation_Star.h"
#include"UI/Timer.h"
#include"UI/Effect.h"
#include"Title/Title.h"
#include "Game/Constellation_Star.h"
#include "Game/Game.h"
#include"Game/Constellation.h"
Enemy* g_enemy = nullptr;

void MainLoop(void) {
	//--------------------------------------------------------------
	//ゲーム中の動きはここに書く
	//ゲーム中はこの関数_を1秒間に60回呼び出している
	//--------------------------------------------------------------
	//ーーーー矢代ーーーー
	//ADD_RESOURCE("field", CImage::CreateImage("Image/Field.png" ));
	











	//ーーーー大勝ーーーー

	TaskManager::Instance()->DeleteKilledTasks();

	//全タスクを更新
	TaskManager::Instance()->Update();

	//全てのタスクを描画
	TaskManager::Instance()->Render();

	TaskManager::Instance()->Collision();












}

void Init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	CFPS::SetFPS(DEFAULT_FPS);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
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

	//マウス非表示
//	CInput::ShowCursor(false);
//	CInput::SetMouseInside(true);
	CInput::Update();
	CInput::Update();


	//ライト設定
	CLight::SetType(0, CLight::eLight_Direction);
	CLight::SetPos(0, CVector3D(0, 200, 200));
	CLight::SetDir(0, CVector3D(0, -1, 0.5).GetNormalize());
	CLight::SetColor(1, CVector3D(0.4f, 0.4f, 0.4f), CVector3D(0.6f, 0.6f, 0.6f));



	CLight::SetFogParam(CVector4D(1, 1, 1, 1), 1200, 1400);

	//カメラ初期化
	CCamera::GetCamera()->LookAt(CVector3D(5, 5, 5),
		CVector3D(0, 0, 0),
		CVector3D(0.0, 1.0, 0.0));

	SetCurrentDirectory("data");



	CShader::GetInstance("StaticMesh");
	CShader::GetInstance("SkinMesh");
	CSound::GetInstance();
	CLight::Init();


	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------
	//----矢代----
	SOUND("Title")->Load("Sound/Star003.wav", 1);
	SOUND("Game")->Load("Sound/Star001.wav", 1);
	SOUND("Result")->Load("Sound/Star002.wav", 1);
	SOUND("Get")->Load("Sound/StarGet.wav", 1);
	SOUND("Constellation")->Load("Sound/ReStar.wav", 1);
	SOUND("Jump")->Load("Sound/Jump.wav", 1);
	SOUND("Hit")->Load("Sound/Hit.wav", 1);
	SOUND("StarGet")->Load("Sound/Get.wav", 1);
	SOUND("StarGet2")->Load("Sound/Get2.wav", 1);

	 
	ADD_RESOURCE("tri", CImage::CreateImage("Image/tri00.png", Constellation_Star::ANIM_DATA, 280, 280));
	ADD_RESOURCE("quad", CImage::CreateImage("Image/quad00.png", Constellation_Star::ANIM_DATA, 280, 280));
	ADD_RESOURCE("penta", CImage::CreateImage("Image/penta00.png",Constellation_Star::ANIM_DATA,280,280));

	ADD_RESOURCE("Score", CImage::CreateImage("Image/Score01.png"));
	ADD_RESOURCE("TitleEffect", CImage::CreateImage("Image/starmove.png"));

	ADD_RESOURCE("Enemy", CImage::CreateImage("Image/Enemy.png", Enemy::ANIM_DATA, 256, 256));
	
	/*new Enemy(
		CVector3D(2500.0f, 0.0f, 100.0f), CVector3D(20.0f, 20.0f, 20.0f), CVector3D(20.0f, 20.0f, 20.0f));*/
	
	ADD_RESOURCE("Effect_Get", CImage::CreateImage("Image/09.png",Effect::ANIM_DATA, 32, 32));
	//new SterManager;
	ADD_RESOURCE("Cons_Tri", CImage::CreateImage("Image/Tri3.png"));
	ADD_RESOURCE("Cons_Quad", CImage::CreateImage("Image/Quad4.png"));
	ADD_RESOURCE("Cons_Penta", CImage::CreateImage("Image/Penta5.png"));
	ADD_RESOURCE("Result", CImage::CreateImage("Image/ReResult.png"));
	ADD_RESOURCE("MiniStar", CImage::CreateImage("Image/nomal1.png"));


	//----大勝----

	ADD_RESOURCE("Player", CImage::CreateImage("Image/charactor1.png",Player::ANIM_DATA,260,260));

	ADD_RESOURCE("Nomal", CImage::CreateImage("Image/Nomalstar2.png",Nomal::ANIM_DATA,137,137));

	ADD_RESOURCE("Timer", CImage::CreateImage("Image/gauge2.png"));

	ADD_RESOURCE("BackGround", CImage::CreateImage("Image/background1.png"));
	ADD_RESOURCE("Ground", CImage::CreateImage("Image/ground1.png"));

	ADD_RESOURCE("Title", CImage::CreateImage("Image/ReTitle.png"));
	ADD_RESOURCE("Load", CImage::CreateImage("Image/Load.png"));

	//プレイヤーを生成
	
	
	

	new Title();
	


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

	//画面解像度変動
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//画面解像度固定
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

//フルスクリーン?ウインドウモードの切り替え
//Alt+Enterで切り替える
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//　.dllのパス指定
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
	
	//前面ボーダー無し
	SetWindowLong(GL::hWnd, GWL_STYLE, WS_POPUP);
	SetWindowPos(GL::hWnd, HWND_TOP, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_SHOWWINDOW);
	Init();


	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	LARGE_INTEGER time_buf;
	QueryPerformanceCounter(&time_buf);
	float fps = 0;
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();
		CInput::Update();
		//各バッファーをクリア
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
