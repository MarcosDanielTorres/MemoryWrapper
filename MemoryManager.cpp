#pragma once
#include "MemoryManager.h"

MemoryManager::MemoryManager(const wchar_t* processName, const wchar_t* moduleName)
	: processName{ processName }, moduleName{ moduleName }, processID{ ProcessID() }, moduleBaseAddress{ ModuleBaseAddress() }
{

	if (processID) {
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, processID);
	}
}


uintptr_t MemoryManager::ProcessID() {
	uintptr_t processID = NULL;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 processEntry;

		processEntry.dwSize = sizeof(PROCESSENTRY32);

		if (Process32First(hSnap, &processEntry)) {
			do {
				if (!_wcsicmp(processEntry.szExeFile, processName)) {
					processID = processEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &processEntry));
		}
		CloseHandle(hSnap);
		return processID;
	}
	else {
		return processID;
	}
}


uintptr_t MemoryManager::ModuleBaseAddress() {
	uintptr_t moduleBaseAddress = -1;
	if (!processID) return NULL;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processID);

	if (hSnap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 moduleEntry;

		moduleEntry.dwSize = sizeof(MODULEENTRY32);

		if (Module32First(hSnap, &moduleEntry)) {
			do {
				if (!_wcsicmp(moduleEntry.szModule, moduleName)) {
					moduleBaseAddress = (uintptr_t)moduleEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &moduleEntry));
		}
		CloseHandle(hSnap);
		return moduleBaseAddress;
	}
	else {
		return moduleBaseAddress;
	}
}

uintptr_t MemoryManager::FindDMAAddr(uintptr_t address, std::vector<int> offsets) {
	uintptr_t newAddress = address;

	for (int i = 0; i < offsets.size(); i++) {
		ReadProcessMemory(hProcess, (LPCVOID)newAddress, &newAddress, sizeof(uintptr_t), nullptr);
		newAddress += offsets[i];
	}
	return newAddress;
}

// Este metodo probablemente tenga que estar en otro lado
void MemoryManager::LoadEntity(std::vector<Entity>& ent, uintptr_t address) {
	ent.emplace_back( Read<int>(address, { Offsets::m_iHealth }), Read<int>(address, { Offsets::m_iTeamNum }));
}