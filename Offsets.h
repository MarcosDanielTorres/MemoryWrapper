#pragma once
#include <cstdint>

namespace Offsets
{
	//signatures

	constexpr ptrdiff_t dwClientState = 0x589D9C;
	constexpr ptrdiff_t dwClientState_GetLocalPlayer = 0x180;
	constexpr ptrdiff_t dwClientState_IsHLTV = 0x4D40;
	constexpr ptrdiff_t dwClientState_Map = 0x28C;
	constexpr ptrdiff_t dwClientState_MapDirectory = 0x188;
	constexpr ptrdiff_t dwClientState_MaxPlayer = 0x388;
	constexpr ptrdiff_t dwClientState_PlayerInfo = 0x52B8;
	constexpr ptrdiff_t dwClientState_State = 0x108;
	constexpr ptrdiff_t dwClientState_ViewAngles = 0x4D88;
	constexpr ptrdiff_t clientstate_delta_ticks = 0x174;
	constexpr ptrdiff_t clientstate_last_outgoing_command = 0x4D24;
	constexpr ptrdiff_t clientstate_choked_commands = 0x4D28;
	constexpr ptrdiff_t clientstate_net_channel = 0x9C;
	constexpr ptrdiff_t dwEntityList = 0x4D44A04;
	constexpr ptrdiff_t dwForceAttack = 0x3175FA8;
	constexpr ptrdiff_t dwForceAttack2 = 0x3175FB4;
	constexpr ptrdiff_t dwForceBackward = 0x3175FE4;
	constexpr ptrdiff_t dwForceForward = 0x3175FC0;
	constexpr ptrdiff_t dwForceJump = 0x51EE660;
	constexpr ptrdiff_t dwForceLeft = 0x3175FD8;
	constexpr ptrdiff_t dwForceRight = 0x3175FFC;
	constexpr ptrdiff_t dwGameDir = 0x628578;
	constexpr ptrdiff_t dwGameRulesProxy = 0x526193C;
	constexpr ptrdiff_t dwGetAllClasses = 0xD56E6C;
	constexpr ptrdiff_t dwGlobalVars = 0x589AA0;
	constexpr ptrdiff_t dwGlowObjectManager = 0x528C8B8;
	constexpr ptrdiff_t dwInput = 0x5195F90;
	constexpr ptrdiff_t dwInterfaceLinkList = 0x8FAD34;
	constexpr ptrdiff_t dwLocalPlayer = 0xD30B84;
	constexpr ptrdiff_t dwMouseEnable = 0xD36728;
	constexpr ptrdiff_t dwMouseEnablePtr = 0xD366F8;
	constexpr ptrdiff_t dwPlayerResource = 0x317434C;
	constexpr ptrdiff_t dwRadarBase = 0x5179774;
	constexpr ptrdiff_t dwSensitivity = 0xD365C4;
	constexpr ptrdiff_t dwSensitivityPtr = 0xD36598;
	constexpr ptrdiff_t dwSetClanTag = 0x89E00;
	constexpr ptrdiff_t dwViewMatrix = 0x4D36344;
	constexpr ptrdiff_t dwWeaponTable = 0x5196A54;
	constexpr ptrdiff_t dwWeaponTableIndex = 0x324C;
	constexpr ptrdiff_t dwYawPtr = 0xD36388;
	constexpr ptrdiff_t dwZoomSensitivityRatioPtr = 0xD3B5D0;
	constexpr ptrdiff_t dwbSendPackets = 0xD39DA;
	constexpr ptrdiff_t dwppDirect3DDevice9 = 0xA6030;
	constexpr ptrdiff_t m_pStudioHdr = 0x294C;
	constexpr ptrdiff_t m_yawClassPtr = 0xD36388;
	constexpr ptrdiff_t m_pitchClassPtr = 0x5179A18;
	constexpr ptrdiff_t interface_engine_cvar = 0x3E9EC;
	constexpr ptrdiff_t convar_name_hash_table = 0x2F0F8;
	constexpr ptrdiff_t m_bDormant = 0xED;
	constexpr ptrdiff_t model_ambient_min = 0x58CDBC;
	constexpr ptrdiff_t set_abs_angles = 0x1CF110;
	constexpr ptrdiff_t set_abs_origin = 0x1CEF50;
	constexpr ptrdiff_t is_c4_owner = 0x3A59A0;
	constexpr ptrdiff_t force_update_spectator_glow = 0x3991D2;
	constexpr ptrdiff_t anim_overlays = 0x2980;
	constexpr ptrdiff_t m_flSpawnTime = 0xA360;
	constexpr ptrdiff_t find_hud_element = 0x2D21C270;
	constexpr ptrdiff_t entitySize= 0x10;

	//netvars

	constexpr ptrdiff_t m_ArmorValue = 0xB368;
	constexpr ptrdiff_t m_Collision = 0x320;
	constexpr ptrdiff_t m_CollisionGroup = 0x474;
	constexpr ptrdiff_t m_Local = 0x2FBC;
	constexpr ptrdiff_t m_MoveType = 0x25B;
	constexpr ptrdiff_t m_OriginalOwnerXuidHigh = 0x31B4;
	constexpr ptrdiff_t m_OriginalOwnerXuidLow = 0x31B0;
	constexpr ptrdiff_t m_aimPunchAngle = 0x70;
	constexpr ptrdiff_t m_aimPunchAngleVel = 0x7C;
	constexpr ptrdiff_t m_bGunGameImmunity = 0x3930;
	constexpr ptrdiff_t m_bHasDefuser = 0x17F8;
	constexpr ptrdiff_t m_bHasHelmet = 0x1839;
	constexpr ptrdiff_t m_bInReload = 0x3228;
	constexpr ptrdiff_t m_bIsDefusing = 0x391C;
	constexpr ptrdiff_t m_bIsScoped = 0x3914;
	constexpr ptrdiff_t m_bSpotted = 0x93D;
	constexpr ptrdiff_t m_bSpottedByMask = 0x980;
	constexpr ptrdiff_t m_dwBoneMatrix = 0x268C;
	constexpr ptrdiff_t m_fAccuracyPenalty = 0x3320;
	constexpr ptrdiff_t m_fFlags = 0x30;
	constexpr ptrdiff_t m_flFallbackWear = 0x31C0;
	constexpr ptrdiff_t m_flFlashDuration = 0xA410;
	constexpr ptrdiff_t m_flFlashMaxAlpha = 0xA40C;
	constexpr ptrdiff_t m_flNextPrimaryAttack = 0x3228;
	constexpr ptrdiff_t m_hActiveWeapon = 0x2EF8;
	constexpr ptrdiff_t m_hMyWeapons = 0x2EF8;
	constexpr ptrdiff_t m_hObserverTarget = 0x338C;
	constexpr ptrdiff_t m_hOwner = 0x30;
	constexpr ptrdiff_t m_hOwnerEntity = 0x14C;
	constexpr ptrdiff_t m_iAccountID = 0x208;
	constexpr ptrdiff_t m_iClip1 = 0x3254;
	constexpr ptrdiff_t m_iCompetitiveRanking = 0x1A84;
	constexpr ptrdiff_t m_iCompetitiveWins = 0x1B88;
	constexpr ptrdiff_t m_iCrosshairId = 0x17F8;
	constexpr ptrdiff_t m_iEntityQuality = 0x1EC;
	constexpr ptrdiff_t m_iFOVStart = 0x31E8;
	constexpr ptrdiff_t m_iFOV = 0x31E4;
	constexpr ptrdiff_t m_iGlowIndex = 0xA410;
	constexpr ptrdiff_t m_iHealth = 0x100;
	constexpr ptrdiff_t m_iItemDefinitionIndex = 0x1EA;
	constexpr ptrdiff_t m_iItemIDHigh = 0x200;
	constexpr ptrdiff_t m_iObserverMode = 0x3378;
	constexpr ptrdiff_t m_iShotsFired = 0xA380;
	constexpr ptrdiff_t m_iState = 0x3248;
	constexpr ptrdiff_t m_iTeamNum = 0xF4;
	constexpr ptrdiff_t m_lifeState = 0x25F;
	constexpr ptrdiff_t m_nFallbackPaintKit = 0x31B8;
	constexpr ptrdiff_t m_nFallbackSeed = 0x31BC;
	constexpr ptrdiff_t m_nFallbackStatTrak = 0x31C4;
	constexpr ptrdiff_t m_nForceBone = 0x268C;
	constexpr ptrdiff_t m_nTickBase = 0x3430;
	constexpr ptrdiff_t m_rgflCoordinateFrame = 0x474;
	constexpr ptrdiff_t m_szCustomName = 0x27C;
	constexpr ptrdiff_t m_szLastPlaceName = 0x35B4;
	constexpr ptrdiff_t m_vecOrigin = 0x138;
	constexpr ptrdiff_t m_vecVelocity = 0x114;
	constexpr ptrdiff_t m_vecViewOffset = 0x108;
	constexpr ptrdiff_t m_viewPunchAngle = 0x64;
	constexpr ptrdiff_t m_thirdPersonViewAngles = 0x4;
	constexpr ptrdiff_t m_clrRender = 0x70;
	constexpr ptrdiff_t m_flC4Blow = 0x2990;
	constexpr ptrdiff_t m_flTimerLength = 0x2994;
	constexpr ptrdiff_t m_flDefuseLength = 0x29A8;
	constexpr ptrdiff_t m_flDefuseCountDown = 0x29AC;
	constexpr ptrdiff_t cs_gamerules_data = 0x0;
	constexpr ptrdiff_t m_SurvivalRules = 0xCF8;
	constexpr ptrdiff_t m_SurvivalGameRuleDecisionTypes = 0x628;
	constexpr ptrdiff_t m_bIsValveDS = 0x75;
	constexpr ptrdiff_t m_bFreezePeriod = 0x20;
	constexpr ptrdiff_t m_bBombPlanted = 0x99D;
	constexpr ptrdiff_t m_bIsQueuedMatchmaking = 0x74;
	constexpr ptrdiff_t m_flSimulationTime = 0x268;
	constexpr ptrdiff_t m_flLowerBodyYawTarget = 0x3A7C;
	constexpr ptrdiff_t m_angEyeAnglesX = 0xB36C;
	constexpr ptrdiff_t m_angEyeAnglesY = 0xB370;
	constexpr ptrdiff_t m_flNextAttack = 0x2D70;
	constexpr ptrdiff_t m_iMostRecentModelBoneCounter = 0x268C;
	constexpr ptrdiff_t m_flLastBoneSetupTime = 0x28BC;
	constexpr ptrdiff_t m_bStartedArming = 0x33E0;
	constexpr ptrdiff_t m_bUseCustomBloomScale = 0x9DA;
	constexpr ptrdiff_t m_bUseCustomAutoExposureMin = 0x9D8;
	constexpr ptrdiff_t m_bUseCustomAutoExposureMax = 0x9D9;
	constexpr ptrdiff_t m_flCustomBloomScale = 0x9E4;
	constexpr ptrdiff_t m_flCustomAutoExposureMin = 0x9DC;
	constexpr ptrdiff_t m_flCustomAutoExposureMax = 0x9E0;

}
//"client_panorama.dll" + 4D44A04 + i * 10->para recorrer todos los jugadores