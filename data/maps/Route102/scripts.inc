Route102_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route102_OnTransition
	.byte 0

Route102_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call_if_unset FLAG_RUN_TO_NERO, Route102_EventScript_UnawareTiana
	end

Route102_EventScript_UnawareTiana::
	setobjectxyperm 4, 23, 5
	return

Route102_EventScript_Tiana::
	goto_if_set FLAG_RUN_TO_NERO, Route102_EventScript_SaveMe
	msgbox Route102_Text_TianaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TIANA, Route102_Text_TianaDefeated
	goto Route102_EventScript_AfterTianaBattle
	end

Route102_EventScript_AfterTianaBattle::
	lockall
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	applymovement 4, flee
	waitmovement
	setflag FLAG_RUN_TO_NERO
	releaseall
	end

Route102_EventScript_SaveMe::
	msgbox Route102_Text_TianaSaveMe, MSGBOX_AUTOCLOSE
	goto Route102_EventScript_Rival
	end


Route102_EventScript_Rival::
	bufferleadmonspeciesname STR_VAR_1
	msgbox Route102_Text_RivalIntro,  MSGBOX_AUTOCLOSE
	goto Route102_EventScript_TianaFlees
	lockall
	end

Route102_EventScript_TianaFlees::
	lockall
	applymovement 4, GoAwayT
	removeobject 4
	setflag FLAG_HIDE_ROUTE_102_TIANA
	goto Route102_EventScript_RivalBattle
	end

Route102_EventScript_RivalBattle::
	applymovement 10, Common_Movement_FacePlayer
	delay 20
	msgbox Route102_Text_Rival, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route102_EventScript_StartNeroBattleTreecko
	case 1, Route102_EventScript_StartNeroBattleTorchic
	case 2, Route102_EventScript_StartNeroBattleMudkip
	end

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

Route102_EventScript_AfterNeroBattle::
	lockall
	msgbox Route102_Text_NeroSpeech, MSGBOX_AUTOCLOSE
	closemessage
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
	msgbox Route102_Text_WeirdGuy, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	msgbox Route102_Text_CalvinIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CALVIN_1, Route102_Text_CalvinDefeated
	goto Route102_EventScript_AfterCalvinBattle
	end

Route102_EventScript_AfterCalvinBattle::
	lockall
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 2
	setflag FLAG_HIDE_CALVIN_ROUTE_102
	fadescreenswapbuffers FADE_FROM_BLACK
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
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

Route102_Text_WeirdGuy:
	.string "Hey if you see Calvin...\p"
	.string "Please remember you didn't ok? \p"
	.string "I heard it's a ghost pretending \n"
	.string "to be him...$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"

Route102_Text_RouteSignFlower:
	.string "RIP Calvin. 20XX - 20XX \n"
	.string "Was once an aspiring trainer,\l"
	.string "but has since gone missing.$"

Route102_Text_TianaSaveMe:
	.string "TIANA: Oh my handsome prince!\n"
	.string "Please save me from this meanie! \p"
	.string "They were about to ruthlessly-$"

Route102_Text_RivalIntro:
	.string "???: SHUT UP!!\n"
	.string "CHATTERBOXES LIKE YOU PISS ME OFF!\p"

Route102_Text_Rival:
	.string "...\p"
	.string "You...\p"
	.string "You DARE try to get in my way?!\p"
	.string "You are nothing without \n"
	.string "that weak POKéMON of yours.\p"
	.string "I have no choice.\p"
	.string "Your journey shall end here \n"
	.string "along with your {STR_VAR_1}! $"

Route102_Text_NeroDefeated:
	.string "tch...$"

Route102_Text_NeroSpeech :
	.string "You think you're SOOOOOOO \n"
	.string "much better, huh?\p"
	.string "This is merely just the beginning...\p"
	.string "I'll show this world \n"
	.string "what happens without their \l"
	.string "precious rules...$"
	end

GoAway :
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoAwayT :
	jump_in_place_up_down
	delay_16
	emote_exclamation_mark
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

flee :
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	face_up
	step_end
