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
	//handle input being too fast (144 Hz, on my machine): 
	std::chrono::steady_clock::time_point currentTime =
		std::chrono::steady_clock::now(); 

	if (currentTime - timeOfLastInput < timeDelay)
	{
		return; 
	}

	//this->gfx.DrawLine(300, 100, 400, 100, Color{ 255, 255, 255 }); //white horizontal line 
	//this->gfx.DrawLine(350, 50, 350, 150, Color{ 255, 0, 255 }); // red vertical line

	////"other" line: 
	////this->gfx.DrawLine(1, 2, 100, 200, Color{ 0, 255, 0 }); //green 

	////this->gfx.DrawX(0); //0 is the "ticTacToeIndex" and corresponds to top left square 

	//gfx.DrawX(1); 

	//gfx.DrawO(5); 

	//gfx.DrawX(4);


	//gfx.DrawO(3);

	for (int i = 0x60; i < 0x60 + 10; ++i) //0x60 corresponds to numpad 0 virtual key 
	{
		if (wnd.kbd.KeyIsPressed(i))
		{
			//gfx.DrawO(0);
			if (turnCount % 2 == 0)
			{
				board[i - 0x60] = 'O'; 
			}

			else
			{
				board[i - 0x60] = 'X';
			}
			break; 
		}

	}


	for (int i = 0; i < board.size(); ++i)
	{

		if (board[i] == 'O')
		{
			gfx.DrawO(i);
		}

		else if (board[i] == 'X')
		{
			gfx.DrawX(i);
		}
	}

	timeOfLastInput = std::chrono::steady_clock::now();
	turnCount++;
}

void Game::ComposeFrame()
{


	const unsigned int STEP_SIZE = 3; 
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
