PetalburgWoods_MapScripts::
	.byte 0

MidnightWoods_EventScript_Trap::
	pike_flashscreen
	waitstate
	random 2
	switch VAR_RESULT
	case 0,  MidnightWoods_EventScript_Trap_Sleep
	case 1,  MidnightWoods_EventScript_Trap_Poison
	releaseall
	end

MidnightWoods_EventScript_Trap_Sleep::
	msgbox MidnightWoods_Text_SleepByTrap, MSGBOX_SIGN
	closemessage
	return

MidnightWoods_EventScript_Trap_Poison::
	msgbox MidnightWoods_Text_PoisonedByTrap, MSGBOX_SIGN
	return

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

MidnightWoods_Text_SleepByTrap:
	.string "You stepped on a trap tile!\n"
	.string "Your POKéMON feel asleep!$"

MidnightWoods_Text_PoisonedByTrap:	
	.string "You stepped on a trap tile!\n"
	.string "Your POKéMON got poisoned!$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "I caught a whole bunch of POKéMON!\p"
	.string "Go, go, go!\n"
	.string "My BUG POKéMON team!$"

PetalburgWoods_Text_ICouldntWin:
	.string "I have all these POKéMON,\n"
	.string "but I couldn't win…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "I caught a bunch of POKéMON.\n"
	.string "Now I'm out of POKé BALLS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Banzai!! It's time to take you out!!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Oh...$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "...Well don't even think about\n"
	.string "hurting my queen Kuku.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Yo, there!\n"
	.string "Your POKéMON doing okay?\p"
	.string "I understand if they aren't, \n"
	.string "Team NYX has been brutal lately.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, hey! You found me!\n"
	.string "It's a miracle that you happened\l"
	.string "to stumble across me.\p"
	.string "Here! A gift from me to you!$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "It's a MIRACLE SEED.\n"
	.string "If a POKéMON holds that item, its\l"
	.string "GRASS-type moves become stronger!$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "MIDNIGHT WOODS\p"
	.string "BEWARE! In order to control the\n"
	.string "BUG type POKéMON pandemic, we\l"
	.string "implemented TRAP TILES.\p"
	.string "Stepping on them inflicts a random\n"
	.string "status condition on a random POKéMON\l"
	.string "in your party.\p"
	.string "We apologize for any inconvienience.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "{UP_ARROW} NYX DOMAIN AHEAD$"

