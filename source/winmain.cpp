#include <windows.h>


const char *gMainWindowClass = "MainWindowClass";
const char* gWindowTitle = "4ying";


LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {   
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);        
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


void CreateMainWindow(HINSTANCE instance, int cmdShow)
{
    WNDCLASS wc;
    wc.hInstance = instance;
    wc.style = CS_HREDRAW | CS_VREDRAW;    
    wc.lpfnWndProc = MainWindowProc;    
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.lpszClassName = gMainWindowClass;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    RegisterClass( &wc );

    HWND wnd = CreateWindow(gMainWindowClass, gWindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, instance, nullptr);
    ShowWindow(wnd, cmdShow);
    UpdateWindow(wnd);

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}


int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstanceHandle, PSTR cmdLine, int cmdShow)
{
    CreateMainWindow(instance, cmdShow);    
    return 0;
}
