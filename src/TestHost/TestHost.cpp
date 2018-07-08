// TestHost.cpp : Defines the entry point for the console application.
//

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <HidCerberus.h>
#include <stdio.h>
#include <iostream>

EVT_HC_PROCESS_ACCESS_REQUEST ProcessAccessRequest;

int main()
{
    auto handle = hc_init();

    hc_register_access_request_event(handle, ProcessAccessRequest);

    getchar();

    hc_shutdown(handle);

    return 0;
}

BOOL ProcessAccessRequest(
    PCSTR HardwareId,
    PCSTR DeviceId,
    PCSTR InstanceId,
    DWORD ProcessId,
    BOOL *bIsAllowed,
    BOOL *bIsPermanent
)
{
    std::cout << HardwareId << " " << DeviceId << " " << InstanceId << " " << ProcessId << std::endl;

    *bIsAllowed = *bIsPermanent = TRUE;

    return TRUE;
}
