RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 2, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 12
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 2, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_GoToBoss
	map_script_2 VAR_DEVON_CORP_3F_STATE, 2, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_GoToBoss::
	setobjectxyperm Prez, 10, 2
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_GoToBoss
	waitmovement 0
	applymovement Jessie, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIsThem, MSGBOX_AUTOCLOSE
	applymovement Jessie, lemmeAtEm
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	msgbox RustboroCity_DevonCorp_3F_Text_JessiePrepareYourself, MSGBOX_AUTOCLOSE
	applymovement guard1, StandDown
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_StandDown, MSGBOX_AUTOCLOSE
	applymovement Jessie, StandDown
	waitmovement 0
	applymovement Jessie, Common_Movement_FacePlayer
	msgbox RustboroCity_DevonCorp_3F_Text_Grumble, MSGBOX_AUTOCLOSE
	applymovement Davy, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox RustboroCity_DevonCorp_3F_Text_CaptainSpeaking, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_DAVY_JONES_1, Gulp
	msgbox RustboroCity_DevonCorp_3F_Text_RunAwayCaptainDefeated, MSGBOX_AUTOCLOSE
	message RustboroCity_Gym_Text_ReceivedAtlasBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_DEFEATED_SOLAS_GYM
	setflag FLAG_BADGE01_GET
	msgbox RustboroCity_DevonCorp_3F_Text_Scream, MSGBOX_DEFAULT
	applymovement Davy, Retreat
	waitmovement 0
	removeObject Davy
	applymovement guard1, Common_Movement_FaceDown
	waitmovement 0
	applymovement guard2, Common_Movement_FaceDown
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_dot, MSGBOX_AUTOCLOSE
	applymovement guard1, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_GetOut, MSGBOX_AUTOCLOSE
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject guard1
	removeobject guard2
	setflag FLAG_HIDE_CREW
	fadescreenswapbuffers FADE_FROM_BLACK
	applymovement Prez, Common_Movement_Delay48
	waitmovement 0
	applymovement Prez , DevonCorpThank
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForYourHelp, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox RustboroCity_DevonCorp_3F_Text_WaterPulse, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	clearflag FLAG_HIDE_CIVS_SOLAS
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 2
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 3
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_GoToBoss:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

lemmeAtEm:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_right
	step_end

StandDown:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end

Retreat:
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

DevonCorpThank:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Oh its you, {PLAYER}{KUN}!\p"
	.string "You saved our staff not just once,\n"
	.string "but twice!\p"
	.string "I hope you don't mind me asking,\n"
	.string "but I understand that you're delivering\l"
	.string "a package to SLATEPORT's SHIPYARD.\p"
	.string "Well, on the way, could you stop off in\n"
	.string "DEWFORD TOWN?\p"
	.string "I was hoping that you'd deliver a\n"
	.string "letter to someone.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "President: Now, you should know that\n"
	.string "I am a great PRESIDENT.\p"
	.string "So, I'd never be so cheap as to ask\n"
	.string "a favor for nothing in return.\p"
	.string "That's why I want you to have this!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} received a POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "President: That device…\n"
	.string "I'm sure you know what it does.\p"
	.string "It'd be best if you rested\n"
	.string "up before you go on your way.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "President: Well, then, {PLAYER}{KUN},\n"
	.string "go with caution and care!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "President: I can't thank you enough!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "President: You delivered my LETTER?\n"
	.string "Thank you kindly!\p"
	.string "This is my way of thanking you.\n"
	.string "It should help you, a TRAINER.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "President: For some reason I have\n"
	.string "a sneaking feeling that you might\l"
	.string "be able to change the world...\p"
	.string "Farewell, {PLAYER}{KUN}.$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "I can't tell you how much I'm\n"
	.string "grateful for what you've done.\p"
	.string "Um… By the way, that parcel\n"
	.string "you got back for us…\p"
	.string "Could I trouble you to deliver that to\n"
	.string "the SHIPYARD in SLATEPORT?\p"
	.string "It would be awful if those robbers\n"
	.string "tried to take it again.\p"
	.string "Uh… Hehehe, so, uh, could I count\n"
	.string "on you to do that for me?\p"
	.string "Oh, that's right.\n"
	.string "Could you wait here a second?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Our PRESIDENT would like to have\n"
	.string "a word with you.\p"
	.string "Please come with me.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Please, go ahead.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "We're counting on you.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "DEVON's new products, the REPEAT BALL\n"
	.string "and TIMER BALL, have become hugely\l"
	.string "popular among TRAINERS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by the PRESIDENT.$"

RustboroCity_DevonCorp_3F_Text_ThisIsThem:
	.string "Jessie: It's them! It's that\n"
	.string "pest who defeated me back in \l"
	.string "Midnight Forest!$"

RustboroCity_DevonCorp_3F_Text_JessiePrepareYourself:
	.string "This time I'm not gonna let you\n"
	.string "win so easily! Prepare yourself!$"

RustboroCity_DevonCorp_3F_Text_StandDown:
	.string "Stand down Jessie! There's no\n"
	.string "way you could ever be a match\l"
	.string "for them!\p"
	.string "Let the captain handle this!$"

RustboroCity_DevonCorp_3F_Text_Grumble:
	.string "Jessie: Grr... Fine...$"

RustboroCity_DevonCorp_3F_Text_CaptainSpeaking:
	.string "Davy: G-gulp! I am NYX CAPTAIN, \n"
	.string "D-Davy Jones!\p"
	.string "S-so you are the TRAINER who\n"
	.string "defeated my mateys!!\l"
	.string "NO matter!!!!\p"
	.string "I-I won't lose to you!\p"
	.string "Y-Y-YAAAAAAAAAR!!!!!!$"

Gulp:
	.string "I give up!!! I surrender!!!$"

RustboroCity_DevonCorp_3F_Text_RunAwayCaptainDefeated:
	.string "Davy: I-I'm done playing this act!\n"
	.string "You win!!! I'm n-nothing more than\l"
	.string "a coward and a fraud!\p"
	.string "J-just take this cursed badge and\n"
	.string "let me go!!!$"

RustboroCity_DevonCorp_3F_Text_Scream:
	.string "AAAAAAAAAAAHHH!!!$"

RustboroCity_DevonCorp_3F_Text_dot:
	.string ".{PAUSE 30}.{PAUSE 30}.$"

RustboroCity_DevonCorp_3F_Text_GetOut:
	.string "Team Nyx, Retreat!!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForYourHelp:
	.string "President: Oh thank you!\p"
	.string "Thank you for freeing my employees\n"
	.string "and saving this city from those\l"
	.string "hooligans!\p"
	.string "I am deeply in your debt.\p"
	.string "Please accept this as\n"
	.string "a token of my gratitude.$"

RustboroCity_DevonCorp_3F_Text_WaterPulse:
	.string "That's Water Pulse.\p"
	.string "In use, it will occasionally confuse\n"
	.string "the target with ultrasonic waves.$"

