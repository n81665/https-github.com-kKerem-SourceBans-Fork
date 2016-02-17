// *************************************************************************
//  This file is part of SourceBans++
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
//  This file is based off of work covered by the following copyright(s): 
//
//   SourceBans 2.0.0
//   Copyright (C) 2007-2016 GameConnect.net
//   Licensed under GNU GPL version 3, or later.
//   Page: <http://www.sourcebans.net/> - <https://github.com/GameConnect/sourcebansv1>  
//
// *************************************************************************

#if defined _sb_bans_included
  #endinput
#endif
#define _sb_bans_included

/**
 * Reports a player to SourceBans
 *
 * @param client	The index of the reporting client
 * @param target	The index of the reported client
 * @param reason	The reason for reporting the player
 */
native void SB_ReportPlayer(int client, int target, const char[] reason);

public SharedPlugin __pl_sb_bans =
{
    name = "sb_bans",
    file = "sb_bans.smx",
    #if defined REQUIRE_PLUGIN
    required = 1
    #else
    required = 0
    #endif
};

#if !defined REQUIRE_PLUGIN
public __pl_sourcebans_SetNTVOptional()
{
    MarkNativeAsOptional("SB_SubmitBan");
}
#endif
