# SDK-2013-Options

Direct port of the Half-Life 2 styled options menu from GameUI.dll to the client.


## How to compile.

1. Create a folder in the client folder named "gameui"
2. Copy all of the contents of this repository into it
3. Insert this VPC snippet anywhere in client_base.vpc
```
	$Folder	"Options"
	{
		$File 	"gameui\CvarSlider.h"
		$File	"gameui\CvarSlider.cpp"
		$File 	"gameui\URLButton.h"
		$File	"gameui\URLButton.cpp"
		$File 	"gameui\CommandCheckButton.h"
		$File	"gameui\CommandCheckButton.cpp"
		$File 	"gameui\CommandCheckButton.h"
		$File	"gameui\CommandCheckButton.cpp"
		$File 	"gameui\CvarNegateCheckButton.h"
		$File	"gameui\CvarNegateCheckButton.cpp"
		$File 	"gameui\KeyToggleCheckButton.h"
		$File	"gameui\KeyToggleCheckButton.cpp"
		$File 	"gameui\CvarToggleCheckButton.h"
		$File	"gameui\CvarToggleCheckButton.cpp"
		$File 	"gameui\CvarTextEntry.cpp"
		$File	"gameui\CvarTextEntry.cpp"
		$File 	"gameui\vcontrolslistpanel.h"
		$File	"gameui\vcontrolslistpanel.cpp"
		$File	"gameui\OptionsDialog.cpp"
		$File	"gameui\OptionsDialog.h"
		$File	"gameui\OptionsSubAudio.cpp"
		$File	"gameui\OptionsSubAudio.h"
		$File	"gameui\OptionsSubDifficulty.cpp"
		$File	"gameui\OptionsSubDifficulty.h"
		$File	"gameui\OptionsSubGame.cpp"
		$File	"gameui\OptionsSubGame.h"
		$File	"gameui\OptionsSubKeyboard.cpp"
		$File	"gameui\OptionsSubKeyboard.h"
		$File	"gameui\OptionsSubMouse.cpp"
		$File	"gameui\OptionsSubMouse.h"
		$File	"gameui\OptionsSubVideo.cpp"
		$File	"gameui\OptionsSubVideo.h"
	}
```

## edited version of GameMenu.res for this.
```
"GameMenu"
{
	"1"
	{
		"label" "#GameUI_GameMenu_ResumeGame"
		"command" "ResumeGame"
		"InGameOrder" "10"
		"OnlyInGame" "1"
	}
	"5"	
	{
		"label" "#GameUI_GameMenu_NewGame"
		"command" "OpenNewGameDialog"
		"InGameOrder" "20"
		"notmulti" "1"
	}
	"6"
	{
		"label" "#GameUI_GameMenu_LoadGame"
		"command" "OpenLoadGameDialog"
		"InGameOrder" "30"
		"notmulti" "1"
	}
	"7"
	{
		"label" "#GameUI_GameMenu_SaveGame"
		"command" "OpenSaveGameDialog"
		"InGameOrder" "40"
		"notmulti" "1"
		"OnlyInGame" "1"
	}
	"8"
	{
		"label" "#GameUI_GameMenu_Achievements"
		"command" "OpenAchievementsDialog"
		"InGameOrder" "70"
	}
	"9"
	{
		"label" "#GameUI_Controller"
		"command" "OpenControllerDialog"
		"InGameOrder" "80"
		"ConsoleOnly" "1"
	}
	"10"
	{
		"label" "#GameUI_GameMenu_Options"
		"command" "engine cl_openoptionsdialog"
		"InGameOrder" "90"
	}
	"11"
	{
		"label" "#GameUI_GameMenu_Quit"
		"command" "Quit"
		"InGameOrder" "100"
	}
}
```
