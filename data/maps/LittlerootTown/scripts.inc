LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverbloomPath_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverbloomPath_OnWarp
	.byte 0

EverbloomPath_OnFrame:
	map_script_2 VAR_AMNESIA, 1, EverbloomPath_Cutscene
	.2byte 0

EverbloomPath_OnWarp::
	map_script_2 VAR_AMNESIA, 1, EverbloomPath_FaceUp
	.2byte 0

EverbloomPath_FaceUp:
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverbloomPath_Cutscene:
	msgbox EverbloomPath_Text_GladYoureAwake, MSGBOX_NPC
	closemessage
	applymovement LOCALID_PLAYER, TalkUp
	waitmovement 0
	msgbox EverbloomPath_Text_WOah, MSGBOX_DEFAULT 
	closemessage
	msgbox EverbloomPath_Text_huh, MSGBOX_DEFAULT
	closemessage
	msgbox EverbloomPath_Text_Where, MSGBOX_DEFAULT 
	closemessage
	msgbox EverbloomPath_Text_YouDontRemember, MSGBOX_DEFAULT
	closemessage
	msgbox EverbloomPath_Text_PokeHarbor, MSGBOX_DEFAULT 
	applymovement LOCALID_PLAYER, TalkUp
	waitmovement 0
	closemessage
	msgbox EverbloomPath_Text_ImEllie, MSGBOX_DEFAULT
	closemessage
	msgbox EverbloomPath_Text_WhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TalkUp
	waitmovement 0
	msgbox EverbloomPath_Text_AmIInGame, MSGBOX_DEFAULT 
	closemessage
	msgbox EverbloomPath_Text_Sure, MSGBOX_DEFAULT
	closemessage	
	msgbox EverbloomPath_Text_Dropped, MSGBOX_DEFAULT
	closemessage
	msgbox EverbloomPath_Text_Wow, MSGBOX_DEFAULT 
	closemessage
	msgbox EverbloomPath_Text_OhNo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TalkUp
	waitmovement 0
	msgbox EverbloomPath_Text_JustLevel, MSGBOX_DEFAULT 
	closemessage
	msgbox EverbloomPath_Test_Yes, MSGBOX_DEFAULT
	closemessage
	msgbox EverbloomPath_Test_Letsgo, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Spin
	waitmovement 0
	setflag FLAG_HIDE_ELLIE
	removeobject 2
	setvar VAR_AMNESIA, 2
	end

EverBloomPath_HealPoint_Script::
	call Common_EventScript_OutOfCenterPartyHeal
	setrespawn HEAL_LOCATION_EVERBLOOMPATH
	msgbox gText_OutOfCenterPartyHeal, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UsePC_Script
	closemessage
	end

TalkUp:
	walk_in_place_up
	step_end
	
Spin::
	face_down
	delay_4
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_player
	delay_4
	face_down
	delay_4
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

EverbloomPath_Text_GladYoureAwake::
	.string "Fairy Ellie: You survived...\n"
	.string "I thought you were a goner...$"

EverbloomPath_Text_WOah::
	.string "Woah! A fairy!$"

EverbloomPath_Text_huh::
	.string "Huh?{PAUSE 25}?\p"
	.string "You already knew that!!$"

EverbloomPath_Text_Where::
	.string "What do you mean?\n"
	.string "Where am I?$"

EverbloomPath_Text_YouDontRemember::
	.string "Wait...\n"
	.string "You don't remember anything?$"

EverbloomPath_Text_PokeHarbor::
	.string "...{PAUSE 25}\p"
	.string "Well all I remembered was downloading\n"
	.string "a POKéMON romhack from POKéHARBOR...$"

EverbloomPath_Text_ImEllie::
	.string "Oh I see...\n"
	.string "Let me introduce myself! Again...\l"
	.string "I'm Ellie the fairy!$"

EverbloomPath_Text_WhoAreYou::
	.string "Do you remember who you are?$"

EverbloomPath_Text_AmIInGame::
	.string "Yes...I'm {PLAYER}{KUN}.\p"
	.string "Am I...inside the game?$"

EverbloomPath_Text_Sure::
	.string "...{PAUSE 25}sure...\n"
	.string "You could say that! Your partner\l"
	.string "POKéMON has chosen you to be\l"
	.string "the hero of this world and friend!$"

EverbloomPath_Text_Dropped::
	.string "Seems like you dropped its ball there.$"

EverbloomPath_Text_Wow::
	.string "Wow...a real POKéBALL!$"

EverbloomPath_Text_OhNo::
	.string "Oh no... the POKéMON I gave you\n"
	.string "was way weaker than I thought...$"

EverbloomPath_Text_JustLevel::
	.string "Well of course it's weak. I just\n"
	.string "have to level it up.$"

EverbloomPath_Test_Yes::
	.string "Yes...level up...$"

EverbloomPath_Test_Letsgo::
	.string "Well anyways looks like we're\n"
	.string "gonna have to keep going if we wanna\l"
	.string "save this world!\p"
	.string "Let's go!$"