RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelped, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_EventScript_LassCutNotHere::
	msgbox RustboroCity_CuttersHouse_Text_DadHere, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Well well…from that battle earlier,\n"
	.string "it's pretty obvious that \l"
	.string "you're a skilled TRAINER.\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "HIDDEN MACHINE to good use$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "That HIDDEN MACHINE, or HM for\n"
	.string "short, is CUT.\p"
	.string "It can target both foes in a\n"
	.string "double battle and can flinch!\p"
	.string "Use that move wisely.$"

RustboroCity_CuttersHouse_Text_DadHelped:
	.string "Oh? You're looking for my father?\p"
	.string "He's currently trying to fight off\n"
	.string "those NYX grunts in the forest.\l"
	.string "next to the Trainer School.$"

RustboroCity_CuttersHouse_Text_DadHere:
	.string "My dad always yammers on about\n"
	.string "how he was a part of a group of\l"
	.string "ninjas that protected the region.\p"
	.string "I mean he is skilled at martial arts,\n"
	.string "but ninjas?!$"
