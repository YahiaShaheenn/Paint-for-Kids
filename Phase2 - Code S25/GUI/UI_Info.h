#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	ITM_RECT,		//Recangle item in menu
	ITM_SQU,
	ITM_TRI,
	ITM_HEX,
	ITM_CIRC,
	ITM_SELECT,
	ITM_SWAP,
	ITM_ROTATE_FIG,
	ITM_DELETE_FIG,
	ITM_CLEAR_ALL,
	ITM_COPY_FIG,
	ITM_CUT_FIG,
	ITM_PASTE_FIG,
	ITM_SAVE_GRAPH,
	ITM_LOAD_GRAPH,
	ITM_DRAW_UNDO,
	ITM_DRAW_REDO,
	ITM_TO_PLAY,
	ITM_DRAW_EXIT,		//Exit item

	DRAW_ITM_COUNT
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	ITM_MATCHING_PAIRS,
	ITM_MISSING_SHAPES,
	ITM_PLAY_UNDO,
	ITM_PLAY_REDO,
	ITM_TO_DRAW,
	ITM_PLAY_EXIT,

	PLAY_ITM_COUNT
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,
		LineUnderTBWidth,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;

#endif