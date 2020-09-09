#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    cout << "\t\t.....MAILSLOTS SERVER....." << endl;
    HANDLE hSlots;
    ////

    BOOL bReadfile;
    DWORD dwNoBytesRead;
    char szReadFileBuffer[1023];
    DWORD dwReadFileBufferSize = sizeof(szReadFileBuffer);

    hSlots = CreateMailslot(L"\\\\.\\mailslot\\MyMailSlots",
                            0,
                            MAILSLOT_WAIT_FOREVER,
                            NULL);
    if(hSlots == INVALID_HANDLE_VALUE)
    {
        cout<<"Mailslot creation Failed & Error No."<<GetLastError()<<endl;
    }
    cout<<"Mailslot creation success"<<endl;
    //
    bReadfile = ReadFile(hSlots, szReadFileBuffer, dwReadFileBufferSize, &dwNoBytesRead, NULL);
    if(bReadfile == FALSE)
    {
        cout<<"ReadFile Failed"<<GetLastError()<<endl;
    }
    cout<<"ReadFiel Success"<<endl;
    cout<<"data Reading From Mail Slots Client:"<<szReadFileBuffer<<endl;

    CloseHandle(hSlots);
    system("PAUSE");
    return 0;
}
