/* 
 * steins-gate: Open source implementation of Steins;Gate Visual Novel
 * Copyright (C) 2014 Mislav Blažević <krofnica996@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * */
#include "SGWindow.hpp"
#include "SGInterpreter.hpp"

SGWindow::SGWindow(ExePublisher Version) : Window("FGRE: Steins;Gate", 1024, 576)
{
    pInterpreter = new SGInterpreter(this, Version);
    pInterpreter->ExecuteLocalNSS("test.nss");
}

SGWindow::~SGWindow()
{
    delete pInterpreter;
}

void SGWindow::RunInterpreter()
{
    pInterpreter->Run(100);
}

void SGWindow::HandleEvent(SDL_Event Event)
{
    pInterpreter->HandleEvent(Event);
}
