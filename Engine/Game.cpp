/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.EndFrame();
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{
	const unsigned int STEP_SIZE = 2; 
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= STEP_SIZE; 
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += STEP_SIZE;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= STEP_SIZE;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += STEP_SIZE;
	}

	const int BOX_WIDTH = 100; 
	const int BOX_HEIGHT = 200; //NOTE that rectangular Window dimension 
								//"offsets" this rectangular box's appearance

	for (int deltaX = 0; deltaX < BOX_WIDTH; ++deltaX)
	{
		for (int deltaY = 100; deltaY < BOX_HEIGHT; ++deltaY)
		{
			gfx.PutPixel(deltaX + x, deltaY + y, { 255, 255, 255 });
		}
	}    
	//gfx.PutPixel(1, 2, { 255, 255, 255 });
	//gfx.PutPixel(1, 2, 3, 4, 5);
}
