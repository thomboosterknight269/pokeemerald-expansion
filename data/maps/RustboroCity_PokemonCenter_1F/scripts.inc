RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Is TEAM NYX gone yet?\p"
	.string "I've been hiding here for almost\n"
	.string "a few hours here...$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "TEAM NYX has taken over the\n"
	.string "SOLAS SCIENCE CENTRE...\p"
	.string "If only TEAM LUX was around...\n"
	.string "They would wipe the floor with them!$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "I heard a rumor that there is a\n"
	.string "secret grotto where a Ninja teaches you\l"
	.string "how to CUT small trees.\p"
	.string "Hmm...do you think it could be behind\n"
	.string "the POKéMON TRAINER'S SCHOOL?$"

