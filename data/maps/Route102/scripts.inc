Route102_MapScripts::
	.byte 0
	call Common_EventScript_SetupRivalGfxId

Route102_EventScript_Rival::
	bufferleadmonspeciesname STR_VAR_1
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	msgbox Route102_Text_Rival, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route102_EventScript_StartNeroBattleTreecko
	case 1, Route102_EventScript_StartNeroBattleTorchic
	case 2, Route102_EventScript_StartNeroBattleMudkip
	end

Route102_EventScript_AfterNeroBattle::
	lockall
	msgbox Route102_Text_NeroSpeech, MSGBOX_DEFAULT
	applymovement 10, GoAway
	waitmovement 10
	goto Route102_EventScript_RivalEnd
	end

Route102_EventScript_RivalEnd::
	removeobject 10
	setflag FLAG_HIDE_ROUTE_102_RIVAL
	releaseall
	end

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignFlower::
	msgbox Route102_Text_RouteSignFlower, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route102_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"

Route102_Text_RouteSignFlower:
	.string "Dedicated to Flora.\n"
	.string "May you rest in peace.$"

Route102_Text_Rival:
	.string "...\p"
	.string "What do you want?\p"
	.string "Hmph! You think you're tough with \n"
	.string "that weak POKéMON of yours?\p"
	.string "Fine then.\p"
	.string "Prove to me that you are worthy \n"
	.string "of your {STR_VAR_1}! $"

Route102_EventScript_StartNeroBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route102_Text_NeroDefeated
	goto Route102_EventScript_AfterNeroBattle
	end

Route102_EventScript_StartNeroBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route102_Text_NeroDefeated
	goto Route102_EventScript_AfterNeroBattle
	end

Route102_EventScript_StartNeroBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route102_Text_NeroDefeated
	goto Route102_EventScript_AfterNeroBattle
	end

Route102_Text_NeroDefeated:
	.string "tch...$"

Route102_Text_NeroSpeech :
	.string "You think you're SO \n"
	.string "much better, huh?\p"
	.string "This is merely just the beginning...\p"
	.string "I'll show what this world what \n"
	.string "it truly means when its rules \p" 
	.string "are upside down...$"
	end

GoAway :
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end