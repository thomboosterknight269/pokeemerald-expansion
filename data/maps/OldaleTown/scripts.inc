OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	goto_if_eq	VAR_OLDALE_RIVAL_STATE, 0, OldaleTown_EventScript_HideRival
	goto_if_eq VAR_OLDALE_RIVAL_STATE, 1, OldaleTown_EventScript_ShowRival
	goto_if_eq VAR_ROUTE_102_STATE, 1, OldaleTown_EventScript_HideRival
	end

OldaleTown_EventScript_HideRival::
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	removeobject LOCALID_RIVAL
	return

OldaleTown_EventScript_ShowRival::
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	addobject LOCALID_RIVAL
	return

OldaleTown_EventScript_SetOldaleState::
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_TownSign::
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_QuestBoy::
	goto_if_eq VAR_OLDALE_RIVAL_STATE, 1, OldaleTown_EventScript_FoundItem
	goto_if_eq VAR_OLDALE_RIVAL_STATE, 2, OldaleTown_EventScript_THanksForFindingItem
	msgbox OldaleTown_Text_GachaRoboBroke, MSGBOX_NPC
	end

OldaleTown_EventScript_FoundItem::
	msgbox OldaleTown_Text_Thanks, MSGBOX_NPC
	delay 30
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	giveitem ITEM_POKE_BALL, 5
	setflag FLAG_SYS_POKEDEX_GET
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setvar VAR_OLDALE_TOWN_STATE, 1
	special SetUnlockedPokedexFlags
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_ADVENTURE_STARTED
	releaseall
	end

OldaleTown_EventScript_THanksForFindingItem::
	msgbox OldaleTown_Text_Thanksagain, MSGBOX_NPC
	end

OldaleTown_EventScript_Rival::
	msgbox OldaleTown_Text_Ohhai, MSGBOX_NPC
	applymovement LOCALID_RIVAL, Common_Movement_FaceOriginalDirection
	end

OldaleTown_EventScript_Psychic::
	msgbox OldaleTown_Text_Psychic, MSGBOX_NPC
	end

OldaleTown_EventScript_Camper::
	msgbox OldaleTown_Text_Camper, MSGBOX_NPC
	end

OldaleTown_EventScript_Hiker::
	msgbox OldaleTown_Text_Hiker, MSGBOX_NPC
	end

OldaleTown_Mart_EventScript_Salesman::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

DawnaTown_HealPoint_Script::
	call Common_EventScript_OutOfCenterPartyHeal
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	msgbox gText_OutOfCenterPartyHeal, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UsePC_Script
	closemessage
	end

UsePC_Script::
	call EventScript_PC
	end

OldaleTown_EventScript_BlockedPath::
	lockall
	msgbox OldaleTown_Text_GoBack, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerStepBack
	waitmovement LOCALID_PLAYER
	releaseall
	end

OldaleTown_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

OldaleTown_Movement_BackUp:
	walk_fast_up
	walk_in_place_faster_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition:
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress:
	.string "I want to take a rest, so I'm saving my\n"
	.string "progress.\p"
	.string "I heard that there's been some meddling\n"
	.string "over at the next town, so I'm\l"
	.string "recuperating and planning ahead.$"

OldaleTown_Text_GoBack:
	.string "There's something going on.\p"
	.string "I'm sure it won't affect us...$"

OldaleTown_Text_DiscoveredFootprints:
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_FinishedSketchingFootprints:
	.string "I finished sketching the footprints of\n"
	.string "a rare POKéMON.\p"
	.string "But it turns out they were only my\n"
	.string "own footprints…$"

OldaleTown_Text_TownSign:
	.string "ASTER TOWN\n"
	.string "“Guiding star of Ahren.”$"

OldaleTown_Text_Psychic:
	.string "Be careful young warrior... \p"
	.string "I sense a dangerous presence ahead...$"

OldaleTown_Text_Camper:
	.string "Finally I can see the sun!$"

OldaleTown_Text_Hiker:
	.string "Whew! My son and I just \n"
	.string "Cameback from the Midnight Forest.\l"
	.string "You would not believe how much \l"
	.string "It was raining there!\p"
	.string "Hope ya brought supplies... \p"
	.string "Cuz it's a real dooozy...$"


OldaleTown_Text_GachaRoboBroke: 
	.string "Um....excuse me?\p"
	.string "Do you think you could help me?\p"
	.string "I've been waiting for someone to\n"
	.string "deliver some parts to\l"
	.string "my GACHA ROBO, but they haven't\n"
	.string "shown up yet, and I don't know what to do!\p"
	.string "Could you go check on the delivery for me?\p"
	.string "If you did, I promise I will\n"
	.string "give you something worthwhile!\p"
	.string "They might be in the route above.$"

gText_OutOfCenterPartyHeal::
	.string "POKéMON healed. Want to access\n"
	.string "the POKéMON Compedium?$\p"

OldaleTown_Text_Thanks::
	.string "Oh, thank you so much!\n"
	.string "I really appreciate it!\p"
	.string "I hope you find this useful!$"

OldaleTown_Text_Thanksagain::
	.string "Thank you so much!$"

OldaleTown_Text_Ohhai::
	.string "Oh, hi there!\n"
	.string "It's you again...$"