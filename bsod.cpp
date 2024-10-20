#include <iostream>
#include "Lesson.h"
#include "LessonManager.h"
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <gdiplus.h> 
#include "utils.h"

using namespace std;
using namespace Gdiplus;  // Use GDI+ namespace

#pragma comment (lib,"Gdiplus.lib")  // Link GDI+ library

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CLOSE:
        // Handle Alt+F4 or window close
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // Set background color to BSOD blue
        SetBkColor(hdc, RGB(0, 120, 215));  // BSOD blue color
        SetTextColor(hdc, RGB(255, 255, 255));  // White text color

        // Create the font for the sad face emoji (Larger Font)
        HFONT hEmojiFont = CreateFont(300, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_SWISS, L"Segoe UI");

        // Select the larger font into the device context
        SelectObject(hdc, hEmojiFont);

        // Draw the sad face emoji
        RECT rect;
        GetClientRect(hwnd, &rect);
        rect.top += 150;  // Adjust vertical position
        rect.left += 150; // Adjust horizontal position
        DrawText(hdc, L":D", -1, &rect, DT_TOP | DT_LEFT | DT_NOCLIP);

        // Create the font for BSOD text (Smaller Font)
        HFONT hFont = CreateFont(60, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_SWISS, L"Segoe UI");

        // Select the smaller font into the device context
        SelectObject(hdc, hFont);

        // Move text down for the BSOD message
        rect.top += 300;

        // Create a message for the fake BSOD
        wstring bsodMessage =
            L"Радик, тут в общем сообщение об твоем поздравлении с др.\n"
            L"С др крч!\n\n";

        // Draw the BSOD message
        DrawText(hdc, bsodMessage.c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK);

        // Load and draw the QR code image using GDI+
        Graphics graphics(hdc);
        Image qrCode(L"qr.png");  // Replace with the path to your QR code image

        // Set position for the QR code (bottom of the window)
        int qrCodeX = rect.left;  // Adjust X coordinate to align QR code to the right
        int qrCodeY = rect.top + 300; // Adjust Y coordinate to position near the bottom
        graphics.DrawImage(&qrCode, qrCodeX, qrCodeY, 200, 200);  // Draw the QR code (200x200 pixels)

        // Create the font for BSOD text (Smaller Font)
        HFONT hSmallFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_SWISS, L"Segoe UI");

        SelectObject(hdc, hSmallFont);

        // Create a message for the fake BSOD
        wstring bsodAdditionalMessage =
            L"Для дополнительной информации и возможных исправлений посетите https://natribu.org/\n\n"
            L"Еще раз с др!\n\n";

        rect.top += 300;
        rect.left += 220;

        // Draw the BSOD message
        DrawText(hdc, bsodAdditionalMessage.c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK);

        // Clean up
        DeleteObject(hEmojiFont);
        DeleteObject(hFont);

        EndPaint(hwnd, &ps);
        break;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

static void drawBsod() {
    // Initialize GDI+
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    // Get the instance handle for the application
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // Define a window class
    const wchar_t className[] = L"FakeBSODClass";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 120, 215)); // Set background to BSOD blue

    // Register the window class
    RegisterClass(&wc);

    // Create a full-screen window
    HWND hwnd = CreateWindowEx(
        WS_EX_TOPMOST,          // Topmost window
        className,              // Window class name
        L"Fake BSOD",           // Window title
        WS_POPUP | WS_VISIBLE,  // Popup with no border and visible
        0, 0,                   // Position: top-left corner of the screen
        GetSystemMetrics(SM_CXSCREEN), // Width: full screen width
        GetSystemMetrics(SM_CYSCREEN), // Height: full screen height
        NULL,                   // No parent window
        NULL,                   // No menu
        hInstance,              // Instance handle
        NULL                    // No additional application data
    );

    // Display the window (fake BSOD)
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Shutdown GDI+
    GdiplusShutdown(gdiplusToken);
}

static void _runLessonBsod() {
    typeWithDelay("Initializing\nTesting delaying text...\nError...");
    this_thread::sleep_for(chrono::milliseconds(1000)); // Delay
    drawBsod();
}

// Initialization function for Lesson BSOD
void initializeLessonBsod() {
    // Create the lesson and add it to LessonManager
    Lesson* lessonBsod = new Lesson("Lesson delayed typing starting...", _runLessonBsod);
    LessonManager::addLesson(lessonBsod);
}
