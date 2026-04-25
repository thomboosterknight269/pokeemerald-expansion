Route101_MapScripts::
	.byte 0

Route101_EventScript::
	setvar VAR_ROUTE101_STATE, 1
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "Grr...\p"
	.string "My friend seriously thinks Team NYX\n"
	.string "is saving the region.\p"
	.string "How dumb! Team LUX are our true\n"
	.string "heroes.$"

Route101_Text_WildPokemonInTallGrass:
	.string "Grr...\p"
	.string "My friend seriously thinks Team LUX\n"
	.string "is in the right.\p"
	.string "What an idiot! Doesn't he know that\n"
	.string "Team NYX is in the right?$"

Route101_Text_RouteSign:
	.string "ROUTE 101\n"
	.string "{UP_ARROW} ASTER TOWN$"

