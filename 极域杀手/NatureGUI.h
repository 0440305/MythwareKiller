#pragma once
#include"framework.h"
#include <commctrl.h>
#include <shellapi.h>
#include <libloaderapi.h>
#include <stdio.h>
namespace NatureGUI {
    // 创建按钮
    HWND CreateButton(HWND hWndParent, // 父窗口句柄
        LPCWSTR lpWindowName, // 按钮标题
        WORD nID, // 控件ID
        int x, // 按钮左上角x坐标
        int y, // 按钮左上角y坐标
        int nWidth, // 按钮宽度
        int nHeight) { // 按钮高度
        return CreateWindowEx(0, L"BUTTON", lpWindowName, WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            x, y, nWidth, nHeight, hWndParent, (HMENU)nID, GetModuleHandle(NULL), NULL);
    }

    // 创建文本框
    HWND CreateEdit(HWND hWndParent, // 父窗口句柄
        WORD nID, // 控件ID
        int x, // 文本框左上角x坐标
        int y, // 文本框左上角y坐标
        int nWidth, // 文本框宽度
        int nHeight) { // 文本框高度
        return CreateWindowEx(0, L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER,
            x, y, nWidth, nHeight, hWndParent, (HMENU)nID, GetModuleHandle(NULL), NULL);
    }

    // 创建进度条
    HWND CreateProgressBar(HWND hWndParent, // 父窗口句柄
        int x, // 进度条左上角x坐标
        int y, // 进度条左上角y坐标
        int nWidth, // 进度条宽度
        int nHeight) { // 进度条高度
        return CreateWindowEx(0, PROGRESS_CLASS, NULL, WS_CHILD | WS_VISIBLE | PBS_SMOOTH,
            x, y, nWidth, nHeight, hWndParent, NULL, GetModuleHandle(NULL), NULL);
    }

    // 创建输入框（只读文本框）
    HWND CreateReadOnlyEdit(HWND hWndParent, // 父窗口句柄
        WORD nID, // 控件ID
        int x, // 输入框左上角x坐标
        int y, // 输入框左上角y坐标
        int nWidth, // 输入框宽度
        int nHeight) { // 输入框高度
        return CreateWindowEx(0, L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY,
            x, y, nWidth, nHeight, hWndParent, (HMENU)nID, GetModuleHandle(NULL), NULL);
    }
}

int NatureInit(void) {
    MessageBox(NULL, TEXT("此应用使用NatureGUI！"), TEXT("提示"), MB_OK | MB_ICONASTERISK | MB_DEFBUTTON1);
    return 0;
}
void NSudo() {
    HMODULE hNSudoDevilMode = LoadLibrary(L"NSudoDevilMode.dll");
    if (hNSudoDevilMode == NULL) {
        MessageBox(NULL, L"NSudoDM.dll文件错误", L"NSudo.dll文件错误", MB_OK);
        return;
    }
    system("taskkill /f /im StudentMain.exe /t");
    FreeLibrary(hNSudoDevilMode);
    return;
}