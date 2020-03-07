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
	Creo un objeto de MemoryManager que va a:
		-Buscar el id del proceso
		-Buscar el address del modulo
		-Abrir el proceso
		-Escribir y leer en la memoria
		-
	
	*/

	MemoryManager mem(L"csgo.exe", L"client_panorama.dll");
	
	GlowStruct enemyTeam(1,0,0,1,true,true);
	GlowStruct myTeam(0,0,1,1,true,true);

	const uintptr_t moduleAddress = mem.GetModuleBaseAddress();

	/*
	TODO
	Creo una clase entidad
		-Creo un arreglo de entidades donde la posicion 0 es mi jugador
		-Agregar y remover jugadores con el transcurso del tiempo (entran y salen)


	Por ahora solo recorrer [moduleAddress + Offsets::dwEntityList + i * Offsets::entitySize] + Offsets::m_iHealth y mostrar la vida
	de todos los jugadores.
	*/

	//TODO: Verificar que este vector no esté siendo inicializado en definicion, solo cuando vaya al loop linea 70
	std::vector<Entity> entityList;
	entityList.reserve(9);
	
	while (true) {
		/*
		TODO: Por cada ciclo tengo que recorrer la entityList y chequear para todo jugador, podría remover los id que antes estaban y ahora no
		*/

		uintptr_t playerAddress = moduleAddress + Offsets::dwLocalPlayer;
		//						I SHOULD MOVE THEM OUTSIDE THIS LOOP AS CONST VALUES, AS WITH EVERY ADDRESS

		
		uintptr_t entityListAddress = moduleAddress + Offsets::dwEntityList;

		uintptr_t playerTeam;

		//ReadProcessMemory(mem.GetProcessHandle(), (LPCVOID)mem.FindDMAAddr(playerAddress, { Offsets::m_iTeamNum }), &playerTeam, sizeof(uintptr_t), nullptr);
		playerTeam = mem.Read<uintptr_t>(playerAddress, { Offsets::m_iTeamNum });

		// entityList[i - 1].push_back(Entity());    experimentar con esto dado std::vector<Entity> entityList[9];
		// entityList->push_back(Entity());          dado std::vector<Entity> entityList[9];

		for (int i = 1; i < 10; i++) {
			//Inicializo el arreglo de entidades
			//Entity ent = mem.LoadEntity(entityListAddress + i * Offsets::entitySize);
//			entityList.emplace_back(mem.LoadEntity(entityListAddress + i * Offsets::entitySize));

			/*
			Me decidi por esta opcion porque pasando la referencia del vector y llamando emplace_back
			evito que se realicen copias innecesarias. Por lo tanto la opción de abajo es la más eficiente, quizás no sea la más prolija

			*/
			mem.LoadEntity(entityList, entityListAddress + i * Offsets::entitySize);

		}

		int sameTeam{ 0 }, enemyTeam{ 0 };
		for (int i = 1; i < 10; i++) {
			//uintptr_t entityAddress = entityListAddress + i * Offsets::entitySize;				 // De acá hacia entitySerialNumber lo voy a mover a mem
		//	uintptr_t entityTeam = mem.Read<uintptr_t>(entityAddress, { Offsets::m_iTeamNum });
		//	uintptr_t entitySerialNumber = mem.Read<uintptr_t>(entityAddress + 0x04);
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


