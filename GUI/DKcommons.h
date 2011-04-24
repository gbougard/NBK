#ifndef DKCOMMONS_H
#define DKCOMMONS_H

#include <windows.h>
#include <gl/gl.h>
#include "DKTextureList.h"
#include "../CreatureTxtReader.h"

#define	AEM_BUILD_DOORS_WOODEN	0
#define	AEM_BUILD_DOORS_BRACED	1
#define	AEM_BUILD_DOORS_IRON	2
#define	AEM_BUILD_DOORS_MAGIC	3

/* room buttons */
#define ROOM_BUTTON_TREASURE	0
#define ROOM_BUTTON_LAIR		1
#define ROOM_BUTTON_HATCHERY	2
#define ROOM_BUTTON_TRAIN		3

#define ROOM_BUTTON_LIBRARY		4
#define ROOM_BUTTON_BRIDGE		5
#define ROOM_BUTTON_GUARD		6
#define ROOM_BUTTON_WORKSHOP	7

#define ROOM_BUTTON_PRISON		8
#define ROOM_BUTTON_TORTURE		9
#define ROOM_BUTTON_BARRACKS	10
#define ROOM_BUTTON_TEMPLE		11

#define ROOM_BUTTON_GRAVEYARD	12
#define ROOM_BUTTON_SCAVENGER	13
#define ROOM_BUTTON_EMPTY		14
#define ROOM_BUTTON_SELL		15

/* action messages for building rooms */
#define	AEM_BUILD_ROOM_TREASURE ROOM_BUTTON_TREASURE
#define	AEM_BUILD_ROOM_LAIR ROOM_BUTTON_LAIR
#define	AEM_BUILD_ROOM_HATCHERY ROOM_BUTTON_HATCHERY
#define	AEM_BUILD_ROOM_TRAIN ROOM_BUTTON_TRAIN

#define	AEM_BUILD_ROOM_LIBRARY ROOM_BUTTON_LIBRARY
#define	AEM_BUILD_ROOM_BRIDGE ROOM_BUTTON_BRIDGE
#define	AEM_BUILD_ROOM_GUARD ROOM_BUTTON_GUARD
#define	AEM_BUILD_ROOM_WORKSHOP ROOM_BUTTON_WORKSHOP

#define	AEM_BUILD_ROOM_PRISON ROOM_BUTTON_PRISON
#define	AEM_BUILD_ROOM_TORTURE ROOM_BUTTON_TORTURE
#define	AEM_BUILD_ROOM_BARRACKS ROOM_BUTTON_BARRACKS
#define	AEM_BUILD_ROOM_TEMPLE ROOM_BUTTON_TEMPLE

#define	AEM_BUILD_ROOM_GRAVEYARD ROOM_BUTTON_GRAVEYARD
#define	AEM_BUILD_ROOM_SCAVENGER ROOM_BUTTON_SCAVENGER
#define	AEM_BUILD_ROOM_EMPTY ROOM_BUTTON_EMPTY
#define	AEM_SELL ROOM_BUTTON_SELL

/* trap buttons */
#define TRAP_BUTTON_BOULDER			0
#define TRAP_BUTTON_ALARM			1
#define TRAP_BUTTON_POISON			2
#define TRAP_BUTTON_LIGHTNING		3
#define TRAP_BUTTON_WORD_OF_POWER	4
#define TRAP_BUTTON_LAVA			5

/* action messages for building traps */
#define	AEM_BUILD_TRAP_BOULDER TRAP_BUTTON_BOULDER
#define	AEM_BUILD_TRAP_ALARM TRAP_BUTTON_ALARM
#define	AEM_BUILD_TRAP_POISON TRAP_BUTTON_POISON
#define	AEM_BUILD_TRAP_LIGHTNING TRAP_BUTTON_LIGHTNING
#define	AEM_BUILD_TRAP_LAVA TRAP_BUTTON_LAVA
#define	AEM_BUILD_TRAP_WORD_OF_POWER TRAP_BUTTON_WORD_OF_POWER

/* door buttons */
#define DOOR_BUTTON_WOODEN	0
#define DOOR_BUTTON_BRACED	1
#define DOOR_BUTTON_IRON	2
#define DOOR_BUTTON_MAGIC	3

/* action messages for building doors */
#define	AEM_BUILD_DOOR_WOODEN DOOR_BUTTON_WOODEN
#define	AEM_BUILD_DOOR_BRACED DOOR_BUTTON_BRACED
#define	AEM_BUILD_DOOR_IRON DOOR_BUTTON_IRON
#define	AEM_BUILD_DOOR_MAGIC DOOR_BUTTON_MAGIC

/* spell buttons */
#define SPELL_BUTTON_POSSESS_MONSTER	0
#define SPELL_BUTTON_SUMMON_IMP			1
#define SPELL_BUTTON_SIGHT_OF_EVIL		2
#define SPELL_BUTTON_SPEED_MONSTER		3

#define SPELL_BUTTON_MUST_OBEY			4
#define SPELL_BUTTON_CALL_TO_ARMS		5
#define SPELL_BUTTON_CONCEAL_MONSTER	6
#define SPELL_BUTTON_HOLD_AUDIENCE		7

#define SPELL_BUTTON_CAVE_IN			8
#define SPELL_BUTTON_HEAL				9
#define SPELL_BUTTON_LIGHTNING			10
#define SPELL_BUTTON_PROTECT_MONSTER	11

#define SPELL_BUTTON_CHICKEN			12
#define SPELL_BUTTON_DISEASE			13
#define SPELL_BUTTON_ARMAGEDDON			14
#define SPELL_BUTTON_DESTROY_WALL		15

#define MINIMAP_BUTTON_ZOOM_IN			16
#define MINIMAP_BUTTON_ZOOM_OUT			17

#define WOODEN_DOORS_NAME		0
#define BRACED_DOORS_NAME		1
#define IRON_DOORS_NAME			2
#define MAGIC_DOORS_NAME		3
#define SELL_EVENT_NAME			4
#define TOP_MINIMAP_NAME		5
#define PAYDAY_WAGE_VALUE_LABEL 6
#define WILDCARD				666

#define AEM_MINIMAP_BUTTON_ZOOM_IN	MINIMAP_BUTTON_ZOOM_IN
#define AEM_MINIMAP_BUTTON_ZOOM_OUT	MINIMAP_BUTTON_ZOOM_OUT

#define	AEM_QUERY				200
#define	AEM_ROOMS				201
#define	AEM_SPELLS				202
#define	AEM_ITEMS				203
#define	AEM_CREATURES			204

#define AEM_SPEED_BUTTON_CHICKEN	SPEED_BUTTON_CHICKEN
#define AEM_SPEED_BUTTON_PRISON		SPEED_BUTTON_PRISON
#define AEM_SPEED_BUTTON_QUERY		SPEED_BUTTON_QUERY
#define	AEM_NONE				10

#define	AEMG_BUILD_DOORS		0
#define	AEMG_BUILD_ROOMS		1
#define	AEMG_BUILD_TRAPS		2
#define	AEMG_TAB_CONTROL		3
#define	AEMG_LOCATE_ROOM		4
#define	AEMG_LOCATE_TRAP		5
#define	AEMG_LOCATE_DOOR		6
#define	AEMG_EXECUTE_SPELL		7
#define	AEMG_NONE				8
#define AEMG_MINIMAP_CONTROL	9

struct ACTION_EVENT
{
	GLint message;
	GLint message_group;
	GLvoid *sender;

	bool	click,
			event;

	ACTION_EVENT()
	{
		message=AEM_NONE;
		message_group=AEMG_NONE;
		click=event=false;
	}

	GLvoid set(bool click, bool event, GLint message, GLint message_group, GLvoid *sender)
	{
		this->click=click;
		this->event=event;
		this->message=message;
		this->message_group=message_group;
		this->sender=sender;
	}

	GLvoid set(ACTION_EVENT *ae)
	{
		click=ae->click;
		event=ae->event;
		message=ae->message;
		message_group=ae->message_group;
		sender=ae->sender;
	}

	GLvoid reset()
	{
		set(false,false,AEM_NONE,AEMG_NONE,NULL);	
	}
};

#define MAX_BUTTONS			16

#define MONEY_LABEL	"MONEY_LABEL"

#define NUMBER_TEXTURE_0	"NUMBER_TEXTURE_0"
#define NUMBER_TEXTURE_1	"NUMBER_TEXTURE_1"
#define NUMBER_TEXTURE_2	"NUMBER_TEXTURE_2"
#define NUMBER_TEXTURE_3	"NUMBER_TEXTURE_3"
#define NUMBER_TEXTURE_4	"NUMBER_TEXTURE_4"
#define NUMBER_TEXTURE_5	"NUMBER_TEXTURE_5"
#define NUMBER_TEXTURE_6	"NUMBER_TEXTURE_6"
#define NUMBER_TEXTURE_7	"NUMBER_TEXTURE_7"
#define NUMBER_TEXTURE_8	"NUMBER_TEXTURE_8"
#define NUMBER_TEXTURE_9	"NUMBER_TEXTURE_9"

#define SPEED_BUTTON_QUERY		100
#define SPEED_BUTTON_PRISON		101
#define SPEED_BUTTON_CHICKEN	102

#define MINIMAP_ZOOM_IN_CLASS_NAME	"MINIMAP_ZOOM_IN_CLASS_NAME"
#define MINIMAP_ZOOM_OUT_CLASS_NAME	"MINIMAP_ZOOM_OUT_CLASS_NAME"

#define MINIMAP_ZOOM_IN_TEXTURE_NORMAL "MINIMAP_ZOOM_IN_TEXTURE_NORMAL"
#define MINIMAP_ZOOM_IN_TEXTURE_PRESSED "MINIMAP_ZOOM_IN_TEXTURE_PRESSED"

#define MINIMAP_ZOOM_OUT_TEXTURE_NORMAL "MINIMAP_ZOOM_OUT_TEXTURE_NORMAL"
#define MINIMAP_ZOOM_OUT_TEXTURE_PRESSED "MINIMAP_ZOOM_OUT_TEXTURE_PRESSED"

/* properities */
#define PROPERTY_ROOM_NUMBER	0
#define PROPERTY_ROOM_COST		1
#define PROPERTY_ROOM_HEALTH	2

/* some class names */
#define	CLASS_NAME_ROOM_TREASURE	"ROOM_TREASURE_ROOM"
#define	CLASS_NAME_ROOM_LAIR		"ROOM_LAIR"
#define	CLASS_NAME_ROOM_HATCHERY	"ROOM_HATCHERY"
#define	CLASS_NAME_ROOM_TRAIN		"ROOM_TRAINING_AREA"

#define	CLASS_NAME_ROOM_LIBRARY		"ROOM_RESEARCH_ROOM"
#define	CLASS_NAME_ROOM_BRIDGE		"ROOM_BRIDGE"
#define	CLASS_NAME_ROOM_GUARD		"ROOM_GUARD_POST"
#define	CLASS_NAME_ROOM_WORKSHOP	"ROOM_WORKSHOP_ROOM"

#define	CLASS_NAME_ROOM_PRISON		"ROOM_PRISON_ROOM"
#define	CLASS_NAME_ROOM_TORTURE		"ROOM_TORTURE_ROOM"
#define	CLASS_NAME_ROOM_BARRACKS	"ROOM_BARRACK_ROOM"
#define	CLASS_NAME_ROOM_TEMPLE		"ROOM_TEMPLE"

#define	CLASS_NAME_ROOM_GRAVEYARD	"ROOM_GRAVEYARD"
#define	CLASS_NAME_ROOM_SCAVENGER	"SCAVENGER_ROOM"

#define	CLASS_NAME_ROOM_HEART		"ROOM_DUNGEON_HEART"
#define	CLASS_NAME_ROOM_PORTAL		"ROOM_ENTRANCE"

#define	CLASS_NAME_TRAP_BOULDER			"BOULDER_TRAP"
#define	CLASS_NAME_TRAP_ALARM			"ALARM_TRAP"
#define	CLASS_NAME_TRAP_POISON			"POISON_TRAP"
#define	CLASS_NAME_TRAP_LIGHTNING		"LIGHTNING_TRAP"
#define	CLASS_NAME_TRAP_LAVA			"LAVA_TRAP"
#define	CLASS_NAME_TRAP_WORD_OF_POWER	"WORD_OF_POWER_TRAP"

static char *room_class_names[]=
{
	CLASS_NAME_ROOM_TREASURE,
	CLASS_NAME_ROOM_LAIR,
	CLASS_NAME_ROOM_HATCHERY,
	CLASS_NAME_ROOM_TRAIN,
	CLASS_NAME_ROOM_LIBRARY,
	CLASS_NAME_ROOM_BRIDGE,
	CLASS_NAME_ROOM_GUARD,
	CLASS_NAME_ROOM_WORKSHOP,
	CLASS_NAME_ROOM_PRISON,
	CLASS_NAME_ROOM_TORTURE,
	CLASS_NAME_ROOM_BARRACKS,
	CLASS_NAME_ROOM_TEMPLE,
	CLASS_NAME_ROOM_GRAVEYARD,
	CLASS_NAME_ROOM_SCAVENGER
};

/* action messages for executing spells */
#define	AEM_EXECUTE_SPELL_POSSESS_MONSTER	SPELL_BUTTON_POSSESS_MONSTER
#define	AEM_EXECUTE_SPELL_SUMMON_IMP		SPELL_BUTTON_SUMMON_IMP
#define	AEM_EXECUTE_SPELL_SIGHT_OF_EVIL		SPELL_BUTTON_SIGHT_OF_EVIL
#define	AEM_EXECUTE_SPELL_SPEED_MONSTER		SPELL_BUTTON_SPEED_MONSTER

#define	AEM_EXECUTE_SPELL_MUST_OBEY			SPELL_BUTTON_MUST_OBEY
#define	AEM_EXECUTE_SPELL_CALL_TO_ARMS		SPELL_BUTTON_CALL_TO_ARMS
#define	AEM_EXECUTE_SPELL_CONCEAL_MONSTER	SPELL_BUTTON_CONCEAL_MONSTER
#define	AEM_EXECUTE_SPELL_HOLD_AUDIENCE		SPELL_BUTTON_HOLD_AUDIENCE

#define	AEM_EXECUTE_SPELL_CAVE_IN			SPELL_BUTTON_CAVE_IN
#define	AEM_EXECUTE_SPELL_HEAL				SPELL_BUTTON_HEAL
#define	AEM_EXECUTE_SPELL_LIGHTNING			SPELL_BUTTON_LIGHTNING
#define	AEM_EXECUTE_SPELL_PROTECT_MONSTER	SPELL_BUTTON_PROTECT_MONSTER

#define	AEM_EXECUTE_SPELL_CHICKEN			SPELL_BUTTON_CHICKEN
#define	AEM_EXECUTE_SPELL_DISEASE			SPELL_BUTTON_DISEASE
#define	AEM_EXECUTE_SPELL_ARMAGEDDON		SPELL_BUTTON_ARMAGEDDON
#define	AEM_EXECUTE_SPELL_DESTROY_WALL		SPELL_BUTTON_DESTROY_WALL

#define ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER0 "ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER0"
#define ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER1 "ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER1"
#define ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER2 "ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER2"
#define ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER3 "ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER3"
#define ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER4 "ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER4"
#define ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER5 "ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER5"
#define ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER6 "ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER6"
#define ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER7 "ANIMATED_CURSOR_TEXTURE_POSSESS_MONSTER7"

#define ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS0 "ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS0"
#define ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS1 "ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS1"
#define ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS2 "ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS2"
#define ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS3 "ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS3"
#define ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS4 "ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS4"
#define ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS5 "ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS5"
#define ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS6 "ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS6"
#define ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS7 "ANIMATED_CURSOR_TEXTURE_CALL_TO_ARMS7"

#define ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER0 "ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER0"
#define ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER1 "ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER1"
#define ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER2 "ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER2"
#define ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER3 "ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER3"
#define ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER4 "ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER4"
#define ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER5 "ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER5"
#define ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER6 "ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER6"
#define ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER7 "ANIMATED_CURSOR_TEXTURE_CONCEAL_MONSTER7"

#define ANIMATED_CURSOR_TEXTURE_CHICKEN0 "ANIMATED_CURSOR_TEXTURE_CHICKEN0"
#define ANIMATED_CURSOR_TEXTURE_CHICKEN1 "ANIMATED_CURSOR_TEXTURE_CHICKEN1"
#define ANIMATED_CURSOR_TEXTURE_CHICKEN2 "ANIMATED_CURSOR_TEXTURE_CHICKEN2"
#define ANIMATED_CURSOR_TEXTURE_CHICKEN3 "ANIMATED_CURSOR_TEXTURE_CHICKEN3"
#define ANIMATED_CURSOR_TEXTURE_CHICKEN4 "ANIMATED_CURSOR_TEXTURE_CHICKEN4"
#define ANIMATED_CURSOR_TEXTURE_CHICKEN5 "ANIMATED_CURSOR_TEXTURE_CHICKEN5"
#define ANIMATED_CURSOR_TEXTURE_CHICKEN6 "ANIMATED_CURSOR_TEXTURE_CHICKEN6"
#define ANIMATED_CURSOR_TEXTURE_CHICKEN7 "ANIMATED_CURSOR_TEXTURE_CHICKEN7"

#define ANIMATED_CURSOR_TEXTURE_DISEASE0 "ANIMATED_CURSOR_TEXTURE_DISEASE0"
#define ANIMATED_CURSOR_TEXTURE_DISEASE1 "ANIMATED_CURSOR_TEXTURE_DISEASE1"
#define ANIMATED_CURSOR_TEXTURE_DISEASE2 "ANIMATED_CURSOR_TEXTURE_DISEASE2"
#define ANIMATED_CURSOR_TEXTURE_DISEASE3 "ANIMATED_CURSOR_TEXTURE_DISEASE3"
#define ANIMATED_CURSOR_TEXTURE_DISEASE4 "ANIMATED_CURSOR_TEXTURE_DISEASE4"
#define ANIMATED_CURSOR_TEXTURE_DISEASE5 "ANIMATED_CURSOR_TEXTURE_DISEASE5"
#define ANIMATED_CURSOR_TEXTURE_DISEASE6 "ANIMATED_CURSOR_TEXTURE_DISEASE6"
#define ANIMATED_CURSOR_TEXTURE_DISEASE7 "ANIMATED_CURSOR_TEXTURE_DISEASE7"

#define ANIMATED_CURSOR_TEXTURE_DESTROY_WALL0 "ANIMATED_CURSOR_TEXTURE_DESTROY_WALL0"
#define ANIMATED_CURSOR_TEXTURE_DESTROY_WALL1 "ANIMATED_CURSOR_TEXTURE_DESTROY_WALL1"
#define ANIMATED_CURSOR_TEXTURE_DESTROY_WALL2 "ANIMATED_CURSOR_TEXTURE_DESTROY_WALL2"
#define ANIMATED_CURSOR_TEXTURE_DESTROY_WALL3 "ANIMATED_CURSOR_TEXTURE_DESTROY_WALL3"
#define ANIMATED_CURSOR_TEXTURE_DESTROY_WALL4 "ANIMATED_CURSOR_TEXTURE_DESTROY_WALL4"
#define ANIMATED_CURSOR_TEXTURE_DESTROY_WALL5 "ANIMATED_CURSOR_TEXTURE_DESTROY_WALL5"
#define ANIMATED_CURSOR_TEXTURE_DESTROY_WALL6 "ANIMATED_CURSOR_TEXTURE_DESTROY_WALL6"
#define ANIMATED_CURSOR_TEXTURE_DESTROY_WALL7 "ANIMATED_CURSOR_TEXTURE_DESTROY_WALL7"

#define ANIMATED_CURSOR_TEXTURE_SUMMON_IMP0 "ANIMATED_CURSOR_TEXTURE_SUMMON_IMP0"
#define ANIMATED_CURSOR_TEXTURE_SUMMON_IMP1 "ANIMATED_CURSOR_TEXTURE_SUMMON_IMP1"
#define ANIMATED_CURSOR_TEXTURE_SUMMON_IMP2 "ANIMATED_CURSOR_TEXTURE_SUMMON_IMP2"
#define ANIMATED_CURSOR_TEXTURE_SUMMON_IMP3 "ANIMATED_CURSOR_TEXTURE_SUMMON_IMP3"
#define ANIMATED_CURSOR_TEXTURE_SUMMON_IMP4 "ANIMATED_CURSOR_TEXTURE_SUMMON_IMP4"
#define ANIMATED_CURSOR_TEXTURE_SUMMON_IMP5 "ANIMATED_CURSOR_TEXTURE_SUMMON_IMP5"
#define ANIMATED_CURSOR_TEXTURE_SUMMON_IMP6 "ANIMATED_CURSOR_TEXTURE_SUMMON_IMP6"
#define ANIMATED_CURSOR_TEXTURE_SUMMON_IMP7 "ANIMATED_CURSOR_TEXTURE_SUMMON_IMP7"

#define ANIMATED_CURSOR_TEXTURE_LIGHTNING0 "ANIMATED_CURSOR_TEXTURE_LIGHTNING0"
#define ANIMATED_CURSOR_TEXTURE_LIGHTNING1 "ANIMATED_CURSOR_TEXTURE_LIGHTNING1"
#define ANIMATED_CURSOR_TEXTURE_LIGHTNING2 "ANIMATED_CURSOR_TEXTURE_LIGHTNING2"
#define ANIMATED_CURSOR_TEXTURE_LIGHTNING3 "ANIMATED_CURSOR_TEXTURE_LIGHTNING3"
#define ANIMATED_CURSOR_TEXTURE_LIGHTNING4 "ANIMATED_CURSOR_TEXTURE_LIGHTNING4"
#define ANIMATED_CURSOR_TEXTURE_LIGHTNING5 "ANIMATED_CURSOR_TEXTURE_LIGHTNING5"
#define ANIMATED_CURSOR_TEXTURE_LIGHTNING6 "ANIMATED_CURSOR_TEXTURE_LIGHTNING6"
#define ANIMATED_CURSOR_TEXTURE_LIGHTNING7 "ANIMATED_CURSOR_TEXTURE_LIGHTNING7"

#define ANIMATED_CURSOR_TEXTURE_HEAL0 "ANIMATED_CURSOR_TEXTURE_HEAL0"
#define ANIMATED_CURSOR_TEXTURE_HEAL1 "ANIMATED_CURSOR_TEXTURE_HEAL1"
#define ANIMATED_CURSOR_TEXTURE_HEAL2 "ANIMATED_CURSOR_TEXTURE_HEAL2"
#define ANIMATED_CURSOR_TEXTURE_HEAL3 "ANIMATED_CURSOR_TEXTURE_HEAL3"
#define ANIMATED_CURSOR_TEXTURE_HEAL4 "ANIMATED_CURSOR_TEXTURE_HEAL4"
#define ANIMATED_CURSOR_TEXTURE_HEAL5 "ANIMATED_CURSOR_TEXTURE_HEAL5"
#define ANIMATED_CURSOR_TEXTURE_HEAL6 "ANIMATED_CURSOR_TEXTURE_HEAL6"
#define ANIMATED_CURSOR_TEXTURE_HEAL7 "ANIMATED_CURSOR_TEXTURE_HEAL7"

#define ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER0 "ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER0"
#define ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER1 "ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER1"
#define ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER2 "ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER2"
#define ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER3 "ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER3"
#define ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER4 "ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER4"
#define ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER5 "ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER5"
#define ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER6 "ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER6"
#define ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER7 "ANIMATED_CURSOR_TEXTURE_PROTECT_MONSTER7"

#define ANIMATED_CURSOR_TEXTURE_CAVE_IN0 "ANIMATED_CURSOR_TEXTURE_CAVE_IN0"
#define ANIMATED_CURSOR_TEXTURE_CAVE_IN1 "ANIMATED_CURSOR_TEXTURE_CAVE_IN1"
#define ANIMATED_CURSOR_TEXTURE_CAVE_IN2 "ANIMATED_CURSOR_TEXTURE_CAVE_IN2"
#define ANIMATED_CURSOR_TEXTURE_CAVE_IN3 "ANIMATED_CURSOR_TEXTURE_CAVE_IN3"
#define ANIMATED_CURSOR_TEXTURE_CAVE_IN4 "ANIMATED_CURSOR_TEXTURE_CAVE_IN4"
#define ANIMATED_CURSOR_TEXTURE_CAVE_IN5 "ANIMATED_CURSOR_TEXTURE_CAVE_IN5"
#define ANIMATED_CURSOR_TEXTURE_CAVE_IN6 "ANIMATED_CURSOR_TEXTURE_CAVE_IN6"
#define ANIMATED_CURSOR_TEXTURE_CAVE_IN7 "ANIMATED_CURSOR_TEXTURE_CAVE_IN7"

#define ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER0 "ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER0"
#define ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER1 "ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER1"
#define ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER2 "ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER2"
#define ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER3 "ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER3"
#define ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER4 "ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER4"
#define ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER5 "ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER5"
#define ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER6 "ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER6"
#define ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER7 "ANIMATED_CURSOR_TEXTURE_SPEED_MONSTER7"

#define ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL0 "ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL0"
#define ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL1 "ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL1"
#define ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL2 "ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL2"
#define ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL3 "ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL3"
#define ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL4 "ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL4"
#define ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL5 "ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL5"
#define ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL6 "ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL6"
#define ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL7 "ANIMATED_CURSOR_TEXTURE_SIGHT_OF_EVIL7"

inline GLint StrToIntDK(const char *str)
{
	return atoi(str);
}

inline char *IntToStrDK(GLint x)
{
	char buff[128];
	return strdup(itoa(x,buff,10));
}


/* extern game variables */
extern GLint PLAYER0_MONEY;

extern CDKTextureList			*GLOBAL_TEXTURE_LIST;
extern game_utils::CCreatureTxtReader *GLOBAL_CREATURE_TXT_READER;

#endif // DKCOMMONS_H