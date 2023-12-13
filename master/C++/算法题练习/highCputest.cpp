#include <Windows.h>
#include <iostream>
using namespace std;

DWORD CALLBACK Func(LPVOID lpParameter) {
    while (1) {
        // cout << "subthread:" << GetCurrentThreadId() << endl;
        ;
    }

    return 0;
}

int main() {
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    DWORD CPUCores = sysinfo.dwNumberOfProcessors;

    DWORD *threadIDs = new DWORD[CPUCores];

    HANDLE *grps = new HANDLE[CPUCores];
    for (DWORD i = 0; i < CPUCores; i++)
        grps[i] = CreateThread(NULL, 0, Func, NULL, 0, &threadIDs[i]);
    WaitForMultipleObjects(CPUCores, grps, true, INFINITE);
    // DWORD ret = WaitForSingleObject(grps[0], INFINITE);

    cout << "cpu number is:" << sysinfo.dwNumberOfProcessors << endl;
    // while (1)
    //     ;

    return 0;
}