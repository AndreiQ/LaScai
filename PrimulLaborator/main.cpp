#include <windows.h>
#include <tchar.h>
#include <string>
typedef std::basic_string<TCHAR> ustring;
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
inline int ErrMsg(const ustring&);
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR pStr,int nCmd)
{
ustring classname=_T("SIMPLEWND");
WNDCLASSEX wcx={0};

wcx.cbSize         = sizeof(WNDCLASSEX);
wcx.lpfnWndProc    = WndProc;
wcx.hInstance      = hInst;
wcx.hIcon         = reinterpret_cast<HICON>(LoadImage(0,IDI_APPLICATION,
                                            IMAGE_ICON,0,0,LR_SHARED));
wcx.hCursor       = reinterpret_cast<HCURSOR>(LoadImage(0,IDC_ARROW,
                                              IMAGE_CURSOR,0,0,LR_SHARED));
wcx.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BTNFACE+1);
wcx.lpszClassName = classname.c_str();
if (!RegisterClassEx(&wcx))
  {
  ErrMsg(_T("Failed to register wnd class"));
  return -1;
  }

int desktopwidth=GetSystemMetrics(SM_CXSCREEN);
int desktopheight=GetSystemMetrics(SM_CYSCREEN);

HWND hwnd=CreateWindowEx(0,
                         classname.c_str(),
                         _T("Simple Window"),
                         WS_OVERLAPPEDWINDOW,
                         desktopwidth/4,
                         desktopheight/4,
                         desktopwidth/2,
                         desktopheight/2,
                         0,
                         0,
                         hInst,
                         0);
if (!hwnd)
  {
  ErrMsg(_T("Failed to create wnd"));
  return -1;
  }

ShowWindow(hwnd,nCmd);
UpdateWindow(hwnd);
MSG msg;
while (GetMessage(&msg,0,0,0)>0)
  {
  TranslateMessage(&msg);
  DispatchMessage(&msg);
  }
return static_cast<int>(msg.wParam);
}
LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
switch (uMsg)
  {
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  default:
    return DefWindowProc(hwnd,uMsg,wParam,lParam);
  }
}
inline int ErrMsg(const ustring& s)
{
return MessageBox(0,s.c_str(),_T("ERROR"),MB_OK|MB_ICONEXCLAMATION);
}
