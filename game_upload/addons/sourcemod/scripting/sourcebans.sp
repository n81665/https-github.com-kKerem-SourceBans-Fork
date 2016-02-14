// *************************************************************************
//  This file is part of SourceBans++.
//
//  Copyright (C) 2014-2016 Sarabveer Singh <me@sarabveer.me>
//  
//  SourceBans++ is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, per version 3 of the License.
//  
//  SourceBans++ is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with SourceBans++. If not, see <http://www.gnu.org/licenses/>.
//
// *************************************************************************

#include <sourcemod>

#define SB_VERSION "2.0F-dev"
#define SBR_VERSION "2.0-dev"

public Plugin myinfo = {
	name        = "SourceBans++",
	author      = "SourceBans++ Dev Team",
	description = "Global Server Management Plugin for the Source Engine",
	version     = SBR_VERSION,
	url         = "https://sarabveer.github.io/SourceBans-Fork/"
};

public void OnPluginStart()
{
	CreateConVar("sb_version", SB_VERSION, _, FCVAR_PLUGIN | FCVAR_SPONLY | FCVAR_REPLICATED | FCVAR_NOTIFY);
	CreateConVar("sbr_version", SBR_VERSION, _, FCVAR_PLUGIN | FCVAR_SPONLY | FCVAR_REPLICATED | FCVAR_NOTIFY);
	PrintToServer("Hello, World!");
}
