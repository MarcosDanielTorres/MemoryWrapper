#include<iostream>
#include "MemoryManager.h"
#include "Offsets.h"
#include "Entity.h"


struct GlowStruct {
	float r;
	float g;
	float b;
	float a;
	bool rwo;
	bool rwuo;

	GlowStruct(float r, float g, float b, float a, bool rwo, bool rwuo)
		: r(r), g(g), b(b), a(a), rwo(rwo), rwuo(rwuo) {

	}
};

int main() {
	/*
	I create a Memorymanager object which is going to: 
		-Search for the process ID
		-Search for the module address
		-"Open up" the process
		-Read and write its associated process memory
		-
	
	*/

	MemoryManager mem(L"csgo.exe", L"client_panorama.dll");
	
	GlowStruct enemyTeam(1,0,0,1,true,true);
	GlowStruct myTeam(0,0,1,1,true,true);

	const uintptr_t moduleAddress = mem.GetModuleBaseAddress();

	/*
	TODO
	Create an Entity struct
		-Create a vector of entities
		-Add and remove players as time goes by.


	For now I just want to go through [moduleAddress + Offsets::dwEntityList + i * Offsets::entitySize] + Offsets::m_iHealth and show the
	players' health.
	*/

	//TODO: Verify if entityList is being initialized upon defining it.
	// DONE: It's been verified that entityList is not being initialized upon definition.

	std::vector<Entity> entityList;
	entityList.reserve(9);
	
	while (true) {
		/*
		TODO: For every cicle I should go through entityList and deal with missing IDs from previous cycles. Meaning players that are no longer playing
		shouldn't be inside the vector
		*/

		uintptr_t playerAddress = moduleAddress + Offsets::dwLocalPlayer;
		//						I SHOULD MOVE THEM OUTSIDE THIS LOOP AS CONST VALUES, AS WITH EVERY ADDRESS

		
		uintptr_t entityListAddress = moduleAddress + Offsets::dwEntityList;

		uintptr_t playerTeam;

		//ReadProcessMemory(mem.GetProcessHandle(), (LPCVOID)mem.FindDMAAddr(playerAddress, { Offsets::m_iTeamNum }), &playerTeam, sizeof(uintptr_t), nullptr);
		playerTeam = mem.Read<uintptr_t>(playerAddress, { Offsets::m_iTeamNum });

		// entityList[i - 1].push_back(Entity());    experiment with that given this: std::vector<Entity> entityList[9];
		// entityList->push_back(Entity());          given: std::vector<Entity> entityList[9];

		for (int i = 1; i < 10; i++) {
			//entityList initialization
			//Entity ent = mem.LoadEntity(entityListAddress + i * Offsets::entitySize);
//			entityList.emplace_back(mem.LoadEntity(entityListAddress + i * Offsets::entitySize));

			/*
			Option below is the better one given that there are no innecesary copies being made when adding entities to entityList
			*/
			mem.LoadEntity(entityList, entityListAddress + i * Offsets::entitySize);

		}

		int sameTeam{ 0 }, enemyTeam{ 0 };
		for (int i = 1; i < 10; i++) {
			//uintptr_t entityAddress = entityListAddress + i * Offsets::entitySize;		
		//	uintptr_t entityTeam = mem.Read<uintptr_t>(entityAddress, { Offsets::m_iTeamNum });
		//	uintptr_t entitySerialNumber = mem.Read<uintptr_t>(entityAddress + 0x04);    -> This value is incorrect. Current status: unknown.
			/*bool isEntityDoormant = mem.Read<bool>(entityAddress, { Offsets::m_bDormant });
			

			if (isEntityDoormant) {
				std::cout << "Server is not sending info from: " << entitySerialNumber << std::endl; 
			}
			else {
				std::cout << "Server is sending info from: " << entitySerialNumber<< std::endl;
			}*/
			
			if (playerTeam == entityList[i - 1].teamNumber) {
				sameTeam++;
			}
			else {
				enemyTeam++;
			}
			
		}
		
				std::cout << "Teammates: " << sameTeam << std::endl;
				std::cout << "Enemies: " << enemyTeam << std::endl;
		std::cout << "------------------" << std::endl;
		Sleep(20000);

	}
}


