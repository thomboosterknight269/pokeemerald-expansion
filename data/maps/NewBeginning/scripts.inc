NewBeginning_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBeginning_OnFrame
	.byte 0

NewBeginning_OnFrame::
	map_script_2 VAR_FINAL_BOSS_AREA, 0, NewBeginning_EventScript_FadeIn
	.2byte 0

NewBeginning_EventScript_FadeIn::
	setflag FLAG_HIDE_ELLIE
	removeobject LOCALID_ELLIE
	fadescreenspeed FADE_TO_WHITE, -1
	fadescreenspeed FADE_FROM_WHITE, 26
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_FINAL_BOSS_LOSS
	setvar VAR_FINAL_BOSS_AREA, 1
	msgbox NewBeginning_Text_WhatHappened, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	fadescreen FADE_FROM_WHITE
	clearflag FLAG_HIDE_ELLIE
	addobject LOCALID_ELLIE
	applymovement LOCALID_ELLIE, GoDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, TalkUp
	waitmovement 0
	msgbox NewBeginning_Text_ImEllie, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, TalkUp
	waitmovement 0
	msgbox NewBeginning_Text_WhereAmI, MSGBOX_DEFAULT 
	applymovement LOCALID_ELLIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox NewBeginning_Text_FightFinalBoss, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, TalkUp
	msgbox NewBeginning_Text_wat, MSGBOX_DEFAULT 
	closemessage
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 5  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	delay 5
	setvar VAR_0x8004, 10  @ vertical pan
	setvar VAR_0x8005, 5  @ horizontal pan
	setvar VAR_0x8006, 25  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	waitstate
	delay 10
	setvar VAR_0x8004, 20  @ vertical pan
	setvar VAR_0x8005, 30  @ horizontal pan
	setvar VAR_0x8006, 30  @ num shakes
	setvar VAR_0x8007, 1  @ shake delay
	special ShakeCamera
	waitstate
	delay 15
	fadescreen FADE_TO_WHITE
	fadescreen FADE_FROM_WHITE
	applymovement LOCALID_ELLIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox NewBeginning_Text_NoTime, MSGBOX_DEFAULT
	setflag FLAG_SYS_POKEMON_GET
	special ChooseStarter
	waitstate
	msgbox NewBeggining_Text_Corrupt, MSGBOX_DEFAULT
	applymovement LOCALID_ELLIE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox NewBeggining_Text_GetBehindMe, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 10  @ vertical pan
	setvar VAR_0x8005, 20  @ horizontal pan
	setvar VAR_0x8006, 30  @ num shakes
	setvar VAR_0x8007, 1  @ shake delay
	special ShakeCamera
	waitstate
	delay 2
	setvar VAR_0x8004, 10  @ vertical pan
	setvar VAR_0x8005, 20  @ horizontal pan
	setvar VAR_0x8006, 30  @ num shakes
	setvar VAR_0x8007, 1  @ shake delay
	special ShakeCamera
	waitstate
	delay 2
	setvar VAR_0x8004, 10  @ vertical pan
	setvar VAR_0x8005, 20  @ horizontal pan
	setvar VAR_0x8006, 30  @ num shakes
	setvar VAR_0x8007, 1  @ shake delay
	special ShakeCamera
	waitstate
	delay 2
	fadescreenspeed FADE_TO_WHITE, 40
	special HealPlayerParty
	clearflag FLAG_FINAL_BOSS_LOSS
	warp MAP_LITTLEROOT_TOWN, 15, 10
	setvar VAR_AMNESIA, 1
	waitstate
	end

NewBeginning_Text_WhatHappened::
	.string "What...{PAUSE 30}happened...? {PAUSE 50}Where am I?\p"
	.string "What is this place? $"

NewBeginning_Text_ImEllie::
	.string "Ellie: Hi! I'm Ellie! The elemental fairy!$"

NewBeginning_Text_WhereAmI::
	.string "A real fairy?! Where am I?\p"
	.string "Why did you bring me here?$"

NewBeginning_Text_FightFinalBoss::
	.string "Before I answer you, I need you to\n"
	.string "beat the final boss!$"

NewBeginning_Text_wat::
	.string "Wait what?!$"

NewBeginning_Text_Roar::
	.string "WROOOOAAAAR!!!$"

NewBeginning_Text_NoTime::
	.string "There's no time to waste!\p"
	.string "Hurry up and pick one of these POKeMON!$"

NewBeggining_Text_Corrupt::
	.string "WRAAAAR!!!!\p"
	.string "EVERYTHING SHALL BE REDUCED TO NOTHING!$"

NewBeggining_Text_GetBehindMe::
	.string "Get behind me!$"

GoDown:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

