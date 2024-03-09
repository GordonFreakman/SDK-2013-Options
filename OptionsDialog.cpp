//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: Client DLL Options
//
// $NoKeywords: $
//=============================================================================//

//#include "BasePanel.h"
#include "cbase.h"
#include "OptionsDialog.h"
#include "ienginevgui.h"
#include "vgui_controls/Button.h"
#include "vgui_controls/CheckButton.h"
#include "vgui_controls/PropertySheet.h"
#include "vgui_controls/Label.h"
#include "vgui_controls/QueryBox.h"

#include "vgui/ILocalize.h"
#include "vgui/ISurface.h"
#include "vgui/ISystem.h"
#include "vgui/IVGui.h"

#include "KeyValues.h"
#include "OptionsSubKeyboard.h"
#include "OptionsSubMouse.h"
#include "OptionsSubAudio.h"
#include "OptionsSubVideo.h"
//#include "OptionsSubVoice.h"
//#include "OptionsSubMultiplayer.h"
#include "OptionsSubDifficulty.h"
#ifdef PORTAL
//#include "OptionsSubPortal.h"
#endif


using namespace vgui;

// memdbgon must be the last include file in a .cpp file!!!
#include <tier0/memdbgon.h>
COptionsDialog *g_OpenDialog = null;
//-----------------------------------------------------------------------------
// Purpose: Basic help dialog
//-----------------------------------------------------------------------------
COptionsDialog::COptionsDialog(vgui::Panel *parent) : PropertyDialog(parent, "OptionsDialog")
{
	SetDeleteSelfOnClose(true);
	SetBounds(0, 0, 512, 406);

	MoveToCenterOfScreen();
	SetSizeable( false );
	SetVisible(true);
	SetScheme(vgui::scheme()->LoadSchemeFromFile("resource/SourceScheme.res", "SourceScheme"));
	VPANEL toolParent = enginevgui->GetPanel(PANEL_GAMEUIDLL);
	SetParent(toolParent);
	SetTitle("#GameUI_Options", true);

	// debug timing code, this function takes too long
//	double s4 = system()->GetCurrentTime();

#ifndef PORTAL
	AddPage(new COptionsSubDifficulty(this), "#GameUI_Difficulty");
#else
	//AddPage(new COptionsSubPortal(this), "#GameUI_Portal");
#endif

	AddPage(new COptionsSubKeyboard(this), "#GameUI_Keyboard");
	AddPage(new COptionsSubMouse(this), "#GameUI_Mouse");

	m_pOptionsSubAudio = new COptionsSubAudio(this);
	AddPage(m_pOptionsSubAudio, "#GameUI_Audio");
	m_pOptionsSubVideo = new COptionsSubVideo(this);
	AddPage(m_pOptionsSubVideo, "#GameUI_Video");



//	double s5 = system()->GetCurrentTime();
//	Msg("COptionsDialog::COptionsDialog(): %.3fms\n", (float)(s5 - s4) * 1000.0f);

	SetApplyButtonVisible(true);
	GetPropertySheet()->SetTabWidth(84);
}

void COptionsDialog::OnClose()
{
	g_OpenDialog = null;
	BaseClass::OnClose();
}

//-----------------------------------------------------------------------------
// Purpose: Destructor
//-----------------------------------------------------------------------------
COptionsDialog::~COptionsDialog()
{

}

//-----------------------------------------------------------------------------
// Purpose: Brings the dialog to the fore
//-----------------------------------------------------------------------------
void COptionsDialog::Activate()
{
	BaseClass::Activate();
	EnableApplyButton(false);
}

//-----------------------------------------------------------------------------
// Purpose: Opens the dialog
//-----------------------------------------------------------------------------
void COptionsDialog::Run()
{
	SetTitle("#GameUI_Options", true);
	Activate();
}

//-----------------------------------------------------------------------------
// Purpose: Called when the GameUI is hidden
//-----------------------------------------------------------------------------
void COptionsDialog::OnGameUIHidden()
{
	// tell our children about it
	for ( int i = 0 ; i < GetChildCount() ; i++ )
	{
		Panel *pChild = GetChild( i );
		if ( pChild )
		{
			PostMessage( pChild, new KeyValues( "GameUIHidden" ) );
		}
	}
}

CON_COMMAND(cl_openoptionsdialog, "Options")
{
	if (g_OpenDialog == null)
		g_OpenDialog = new COptionsDialog(null);
}

