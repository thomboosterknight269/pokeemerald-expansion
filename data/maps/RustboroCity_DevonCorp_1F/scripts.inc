RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_1F_OnFrame
	.byte 0

RustboroCity_DevonCorp_1F_OnFrame:
	map_script_2 VAR_RUSTBORO_CITY_STATE, 0, RustboroCity_DevonCorp_1F_EventScript_Cutscene
	.2byte 0

RustboroCity_DevonCorp_1F_EventScript_Cutscene::
	lockall
	applymovement Grunt1, Common_Movement_FaceDown
	waitmovement 0
	applymovement Grunt2, Common_Movement_FaceDown
	waitmovement 0
	applymovement Grunt1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement Grunt2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement Grunt1, Common_Movement_Delay48
	waitmovement 0
	applymovement Grunt2, moveUp
	waitmovement 0
	applymovement Grunt1, goToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_1F_Text_Hey, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_JOSH, crud
	applymovement Grunt1, BackOff
	waitmovement 0
	msgbox RustboroCity_DevonCorp_1F_Text_ohCrud
	applymovement Grunt1, Flee
	waitmovement 0
	removeObject Grunt1
	applymovement Grunt2, goToPlayer2
	waitmovement 0
	msgbox RustboroCity_DevonCorp_1F_Text_Hey2, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_TOMMY, crud2
	msgbox RustboroCity_DevonCorp_1F_Text_ohCrud2
	applymovement Grunt2, Flee
	waitmovement 0
	removeObject Grunt2
	setvar VAR_RUSTBORO_CITY_STATE, 1
	closemessage
	releaseall
	end

RustboroCity_DevonCorp_1F_EventScript_Grunt1::
	lock
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Grunt2::
	lock
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_Hey:
	.string "Hey, what are you doing here?!\n"
	.string "You better think twice before coming\l"
	.string "around to mess with Team Nyx!$"

RustboroCity_DevonCorp_1F_Text_ohCrud:
	.string "Oh crud...they beat me...\p"
	.string "They beat me!!!$"

RustboroCity_DevonCorp_1F_Text_Hey2:
	.string "You'll pay for messing with my\n"
	.string "buddy and with our operations!$"

RustboroCity_DevonCorp_1F_Text_ohCrud2:
	.string "Grr...you may have beaten us...\p"
	.string "But once you face against our captain\n"
	.string "You'll be sorry!$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "It sounds like they've recovered\n"
	.string "the ripped-off DEVON GOODS.$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Samples of rocks and metal are\n"
	.string "displayed in the glass case.$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototypes and test products fill\n"
	.string "the glass display case.$"

crud:
	.string "Agghh!$"

crud2:
	.string "Uooooooh......$"

goToPlayer:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	face_player
	step_end

moveUp:
	walk_faster_up
	face_player
	step_end

BackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

Flee:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

goToPlayer2:
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	face_player
	step_end
