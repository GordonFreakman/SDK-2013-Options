# SDK-2013-Options

Direct port of the Half-Life 2 styled options menu from GameUI.dll.


## How to use.

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
