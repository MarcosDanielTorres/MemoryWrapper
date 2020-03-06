#pragma once
#include<Windows.h>
#include<vector>
#include<TlHelp32.h>


class MemoryManager {
private:
	const wchar_t* processName;
	const wchar_t* moduleName;

	const uintptr_t processID;
	const uintptr_t moduleBaseAddress;

	HANDLE hProcess;

	uintptr_t ProcessID();
	uintptr_t ModuleBaseAddress();


public:
	MemoryManager(const wchar_t* processName, const wchar_t* moduleName);
	uintptr_t GetProcessID() { return processID; }
	uintptr_t GetModuleBaseAddress() { return moduleBaseAddress; }
	HANDLE GetProcessHandle() { return hProcess; }
	uintptr_t FindDMAAddr(uintptr_t address, std::vector<int> offsets);

	uintptr_t Read(uintptr_t address, std::vector<int> offsets) {
		uintptr_t result;
		ReadProcessMemory(hProcess, (LPCVOID) FindDMAAddr(address, offsets), &result, sizeof(uintptr_t), nullptr);
		return result;
	}

	template<typename T>
	T Read(uintptr_t address) {
		T result;
		ReadProcessMemory(hProcess, address, &result, sizeof(T), nullptr);
		return result;
	}
};
