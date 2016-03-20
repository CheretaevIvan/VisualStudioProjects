#include "MyForm.h"

#include <Windows.h>
using namespace System;
using namespace System::Windows::Forms;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew LogExample::MyForm());

	return 0;
}
