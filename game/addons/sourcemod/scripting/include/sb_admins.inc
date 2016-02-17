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

#if defined _sb_admins_included
  #endinput
#endif
#define _sb_admins_included

/**
 * Get SourceBans admin id from client
 *
 * @param	client	The index of the client
 * @return				The admin id of the client
 */
native int SB_GetAdminId(int client);

/**
 * Adds an admin to the SourceBans database
 *
 * @param client		The index of the client (person adding admin)
 * @param name			The name of the admin to add
 * @param authtype	The authentication type (AUTHMETHOD_STEAM, AUTHMETHOD_IP, AUTHMETHOD_NAME)
 * @param identity	The Steam ID, IP address or name of the admin based on authtype
 * @param password	The password for the admin (optional)
 * @param groups		The groups to assign to the admin (optional)
 * @error						Invalid authtype
 */
native void SB_AddAdmin(int client, const char[] name, const char[] authtype, const char[] identity, const char[] password = "", const char[] groups = "");

/**
 * Deletes an admin from the SourceBans database
 *
 * @param client		The index of the client (person deleting admin)
 * @param authtype	The authentication type (AUTHMETHOD_STEAM, AUTHMETHOD_IP, AUTHMETHOD_NAME)
 * @param identity	The steamid, ip, or name of admin based on authtype* @noreturn
 * @error						Invalid authtype
 */
native void SB_DeleteAdmin(int client, const char[] authtype, const char[] identity);

/**
 * Adds a group to the SourceBans database
 *
 * @param client		The index of the client (person adding group)
 * @param name			The name of the new group
 * @param flags			The flags to assign to the group
 * @param immunity	The immunity to assign to the group (optional)
 */
native void SB_AddGroup(int client, const char[] name, const char[] flags, int immunity = 0);

/**
 * Deletes a group from the SourceBans database
 *
 * @param client	The index of the client (person deleting group)
 * @param name		The name of the group to delete
 */
native void SB_DeleteGroup(int client, const char[] name);

/**
 * Sets an admin's groups in the SourceBans database
 *
 * @param client		The index of the client (person setting groups)
 * @param authtype	The authentication type of the admin (AUTHMETHOD_STEAM, AUTHMETHOD_IP, AUTHMETHOD_NAME)
 * @param identity	The steamid, ip, or name of admin based on authtype
 * @param groups		The groups to set the admin to; blank, or default is to reset groups
 * @error						Invalid authtype
 */
native void SB_SetAdminGroups(int client, const char[] authtype, const char[] identity, const char[] groups = "");

public SharedPlugin __pl_sb_admins =
{
    name = "sb_admins",
    file = "sb_admins.smx",
    #if defined REQUIRE_PLUGIN
    required = 1
    #else
    required = 0
    #endif
};

#if !defined REQUIRE_PLUGIN
public __pl_sb_admins_SetNTVOptional()
{
    MarkNativeAsOptional("SB_GetAdminId");
    MarkNativeAsOptional("SB_AddAdmin");
    MarkNativeAsOptional("SB_DeleteAdmin");
    MarkNativeAsOptional("SB_AddGroup");
    MarkNativeAsOptional("SB_DeleteGroup");
    MarkNativeAsOptional("SB_SetAdminGroups");
}
#endif
