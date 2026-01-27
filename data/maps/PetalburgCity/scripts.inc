PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	.byte 0

PetalburgCity_OnTransition:
	call_if_unset FLAG_DEFEATED_SOLAS_GYM, Storm
	call_if_set FLAG_DEFEATED_SOLAS_GYM, ResetWeather
	end

PetalburgCity_EventScript_Boy::
	lock
	faceplayer
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_Text_WaterReflection:
	.string "My face is reflected in the water.\p"
	.string "It's a shining grin full of hope…\p"
	.string "Or it could be a look of somber silence\n"
	.string "struggling with fear…\p"
	.string "What do you see reflected in your face?$"

