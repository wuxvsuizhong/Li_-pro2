#include <Windows.h>
#include <iostream>

using namespace std;

DWORD CALLBACK TestFunc1(LPVOID lpParam) {
    while (1)
        ;
}

int main() {
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    DWORD CPUCores = sysinfo.dwNumberOfProcessors;

    cout << "CPU cores:" << CPUCores << endl;

    DWORD nID = 0;
    HANDLE *hThreads = new HANDLE[CPUCores];
    for (DWORD i = 0; i < CPUCores; i++) {
        hThreads[i] = CreateThread(NULL, 0, TestFunc1, NULL, 0, &nID);
    }
    WaitForMultipleObjects(2, hThreads, true, INFINITE);
    cout << "wait over" << endl;
    return 0;
}