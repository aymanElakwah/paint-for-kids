// Change in remote repository
#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	SELECT_DRAW_CLR,
	CHNG_FILL_CLR,	//Change the filling color
	SELECT_FILL_CLR,
	SELECT,
	COPY,
	CUT,
	PASTE,
	ROTATE,
	RESIZE,
	DEL,			//Delete a figure(s)
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	PICK_TYPE,
	PICK_FILL,
	PICK_TYPE_AND_FILL,

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
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
