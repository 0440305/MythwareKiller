#pragma once
#include"framework.h"
#include <commctrl.h>
#include <shellapi.h>
#include <libloaderapi.h>
#include <stdio.h>
namespace NatureGUI {
    // ������ť
    HWND CreateButton(HWND hWndParent, // �����ھ��
        LPCWSTR lpWindowName, // ��ť����
        WORD nID, // �ؼ�ID
        int x, // ��ť���Ͻ�x����
        int y, // ��ť���Ͻ�y����
        int nWidth, // ��ť���
        int nHeight) { // ��ť�߶�
        return CreateWindowEx(0, L"BUTTON", lpWindowName, WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            x, y, nWidth, nHeight, hWndParent, (HMENU)nID, GetModuleHandle(NULL), NULL);
    }

    // �����ı���
    HWND CreateEdit(HWND hWndParent, // �����ھ��
        WORD nID, // �ؼ�ID
        int x, // �ı������Ͻ�x����
        int y, // �ı������Ͻ�y����
        int nWidth, // �ı�����
        int nHeight) { // �ı���߶�
        return CreateWindowEx(0, L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER,
            x, y, nWidth, nHeight, hWndParent, (HMENU)nID, GetModuleHandle(NULL), NULL);
    }

    // ����������
    HWND CreateProgressBar(HWND hWndParent, // �����ھ��
        int x, // ���������Ͻ�x����
        int y, // ���������Ͻ�y����
        int nWidth, // ���������
        int nHeight) { // �������߶�
        return CreateWindowEx(0, PROGRESS_CLASS, NULL, WS_CHILD | WS_VISIBLE | PBS_SMOOTH,
            x, y, nWidth, nHeight, hWndParent, NULL, GetModuleHandle(NULL), NULL);
    }

    // ���������ֻ���ı���
    HWND CreateReadOnlyEdit(HWND hWndParent, // �����ھ��
        WORD nID, // �ؼ�ID
        int x, // ��������Ͻ�x����
        int y, // ��������Ͻ�y����
        int nWidth, // �������
        int nHeight) { // �����߶�
        return CreateWindowEx(0, L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY,
            x, y, nWidth, nHeight, hWndParent, (HMENU)nID, GetModuleHandle(NULL), NULL);
    }
}

int NatureInit(void) {
    MessageBox(NULL, TEXT("��Ӧ��ʹ��NatureGUI��"), TEXT("��ʾ"), MB_OK | MB_ICONASTERISK | MB_DEFBUTTON1);
    return 0;
}
void NSudo() {
    HMODULE hNSudoDevilMode = LoadLibrary(L"NSudoDevilMode.dll");
    if (hNSudoDevilMode == NULL) {
        MessageBox(NULL, L"NSudoDM.dll�ļ�����", L"NSudo.dll�ļ�����", MB_OK);
        return;
    }
    system("taskkill /f /im StudentMain.exe /t");
    FreeLibrary(hNSudoDevilMode);
    return;
}