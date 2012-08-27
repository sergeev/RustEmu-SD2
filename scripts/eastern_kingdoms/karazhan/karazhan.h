/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_KARAZHAN_H
#define DEF_KARAZHAN_H

enum
{
    MAX_ENCOUNTER                   = 11,
    MAX_OZ_OPERA_MOBS               = 4,

    TYPE_ATTUMEN                    = 0,
    TYPE_MOROES                     = 1,
    TYPE_MAIDEN                     = 2,
    TYPE_OPERA                      = 3,
    TYPE_CURATOR                    = 4,
    TYPE_TERESTIAN                  = 5,
    TYPE_ARAN                       = 6,
    TYPE_NETHERSPITE                = 7,
    TYPE_CHESS                      = 8,
    TYPE_MALCHEZZAR                 = 9,
    TYPE_NIGHTBANE                  = 10,
    TYPE_OPERA_PERFORMANCE          = 11,               // no regular encounter - just store one random opera event

    DATA_OPERA_OZ_DEATHCOUNT        = 12,

    NPC_ATTUMEN                     = 15550,
    NPC_MIDNIGHT                    = 16151,
    NPC_MOROES                      = 15687,
    NPC_BARNES                      = 16812,
    // NPC_TERESTIAN                = 15688,
    NPC_NIGHTBANE                   = 17225,

    // Moroes event related
    NPC_LADY_KEIRA_BERRYBUCK        = 17007,
    NPC_LADY_CATRIONA_VON_INDI      = 19872,
    NPC_LORD_CRISPIN_FERENCE        = 19873,
    NPC_BARON_RAFE_DREUGER          = 19874,
    NPC_BARONESS_DOROTHEA_MILLSTIPE = 19875,
    NPC_LORD_ROBIN_DARIS            = 19876,

    // Opera event
    NPC_DOROTHEE                    = 17535,
    NPC_ROAR                        = 17546,
    NPC_TINHEAD                     = 17547,
    NPC_STRAWMAN                    = 17543,
    NPC_GRANDMOTHER                 = 17603,
    NPC_JULIANNE                    = 17534,
    NPC_ROMULO                      = 17533,

    GO_STAGE_CURTAIN                = 183932,
    GO_STAGE_DOOR_LEFT              = 184278,
    GO_STAGE_DOOR_RIGHT             = 184279,
    GO_PRIVATE_LIBRARY_DOOR         = 184517,
    GO_MASSIVE_DOOR                 = 185521,
    GO_GAMESMANS_HALL_DOOR          = 184276,
    GO_GAMESMANS_HALL_EXIT_DOOR     = 184277,
    GO_NETHERSPACE_DOOR             = 185134,
    GO_SIDE_ENTRANCE_DOOR           = 184275,
    GO_DUST_COVERED_CHEST           = 185119,
    GO_MASTERS_TERRACE_DOOR_1       = 184274,
    GO_MASTERS_TERRACE_DOOR_2       = 184280,

    // Opera event stage decoration
    GO_OZ_BACKDROP                  = 183442,
    GO_OZ_HAY                       = 183496,
    GO_HOOD_BACKDROP                = 183491,
    GO_HOOD_TREE                    = 183492,
    GO_HOOD_HOUSE                   = 183493,
    GO_RAJ_BACKDROP                 = 183443,
    GO_RAJ_MOON                     = 183494,
    GO_RAJ_BALCONY                  = 183495,
};

enum OperaEvents
{
    OPERA_EVENT_WIZARD_OZ           = 1,
    OPERA_EVENT_RED_RIDING_HOOD     = 2,
    OPERA_EVENT_ROMULO_AND_JUL      = 3
};

struct OperaSpawns
{
    uint32 uiEntry;
    float fX, fY, fZ, fO;
};

static const OperaSpawns aOperaLocOz[MAX_OZ_OPERA_MOBS]=
{
    {NPC_DOROTHEE,  -10896.65f, -1757.62f, 90.55f, 4.86f},
    {NPC_ROAR,      -10889.53f, -1758.10f, 90.55f, 4.57f},
    {NPC_TINHEAD,   -10883.84f, -1758.85f, 90.55f, 4.53f},
    {NPC_STRAWMAN,  -10902.11f, -1756.45f, 90.55f, 4.66f},
};

static const OperaSpawns aOperaLocWolf = {NPC_GRANDMOTHER, -10892.0f, -1758.0f, 90.55f, 4.738f};
static const OperaSpawns aOperaLocJul  = {NPC_JULIANNE,    -10900.0f, -1758.0f, 90.55f, 4.738f};

class MANGOS_DLL_DECL instance_karazhan : public ScriptedInstance
{
    public:
        instance_karazhan(Map* pMap);
        ~instance_karazhan() {}

        void Initialize();
        bool IsEncounterInProgress() const;

        void OnPlayerEnter(Player* pPlayer);
        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        void DoPrepareOperaStage(Creature* pOrganizer);

        void Load(const char* chrIn);
        const char* Save() { return m_strInstData.c_str(); }

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;

        uint32 m_uiOperaEvent;
        uint32 m_uiOzDeathCount;

        GuidList m_lOperaTreeGuidList;
        GuidList m_lOperaHayGuidList;
};

class MANGOS_DLL_DECL npc_fiendish_portalAI : public ScriptedAI
{
    public:
        npc_fiendish_portalAI(Creature* pCreature);
        ~npc_fiendish_portalAI() {}

        void Reset();
        void JustSummoned(Creature* pSummoned);
        void UpdateAI(const uint32 uiDiff);

        uint32 m_uiSummonTimer;
};

#endif
