#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,	//Draw Rectangle
	DRAW_SQU,
	TO_DRAW,
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	DRAW_TRI,
	DRAW_HEX,
	DRAW_CIRC,
	SELECT,
	SWAP,
	ROTATE_FIG,
	DELETE_FIG,
	CLEAR_ALL,
	COPY_FIG,
	CUT_FIG,
	PASTE_FIG,
	SAVE_GRAPH,
	LOAD_GRAPH,

	MATCHING_PAIRS,
	MISSING_SHAPES,
	UNDO,
	REDO,


	EXIT,
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif