// original version by commy2 from ACE3
#include "script_component.hpp"

private _files = [];
{
    if (_x find "a3_" != 0 && {_x find "keko_" != 0} && {!(toLower _x in (missionNamespace getVariable ["keko_Version_Whitelist", []]))}) then {
        _files pushBack _x;
    };
} forEach activatedAddons;

private _versions = [];
{
    private _version = parseNumber getText (configFile >> "CfgPatches" >> _x >> "version");
    _versions set [_forEachIndex, _version];
} forEach _files;

if (isServer) then {
    keko_Version_ServerVersions = [_files, _versions];
    publicVariable "keko_Version_ServerVersions";
} else {
    keko_Version_ClientVersions = [_files, _versions];
};

// Begin client version check
if (!isServer) then {
    // Wait for server to send the servers files and version numbers
    waitUntil {
        sleep 1;
        !isNil "keko_Version_ClientVersions" && {!isNil "keko_Version_ServerVersions"}
    };

    private _client = profileName;

    _files = keko_Version_ClientVersions select 0;
    _versions = keko_Version_ClientVersions select 1;

    private _serverFiles = keko_Version_ServerVersions select 0;
    private _serverVersions = keko_Version_ServerVersions select 1;

    // Compare client and server files and versions
    private _missingAddons = [];
    private _oldVersionsClient = [];
    private _oldVersionsServer = [];
    {
        private _serverVersion = _serverVersions select _forEachIndex;

        private _index = _files find _x;
        if (_index == -1) then {
                if (_x != "keko_server") then {_missingAddons pushBack _x;};
        } else {

            private _clientVersion = _versions select _index;

            if (_clientVersion < _serverVersion) then {
                _oldVersionsClient pushBack [_x, _clientVersion, _serverVersion];
            };

            if (_clientVersion > _serverVersion) then {
                _oldVersionsServer pushBack [_x, _clientVersion, _serverVersion];
            };
        };
    } forEach _serverFiles;

    // find client files which the server doesn't have
    private _missingAddonsServer = [];
    {
        private _index = _serverFiles find _x;
        if (_index == -1) then {
            _missingAddonsServer pushBack _x;
        }
    } forEach _files;

    // display and log error messages
    private _fnc_cutComma = {
        private _string = _this;
        _string = toArray _string;

        private _count = count _string;
        _string set [_count - 2, toArray "." select 0];
        _string set [_count - 1, -1];
        _string = _string - [-1];

        toString _string;
    };

    private _missingAddon = false;
    if (count _missingAddons > 0) then {
        _missingAddon = true;

        private _error = format ["[KEKO] %1: ERROR missing addon(s): ", _client];
        {
            _error = _error + format ["%1, ", _x];

            if (_forEachIndex > 9) exitWith {};//
        } forEach _missingAddons;

        _error = _error call _fnc_cutComma;

        diag_log text _error;
        [QGVAR(systemChatGlobal), _error] call CBA_fnc_globalEvent;
    };

    private _missingAddonServer = false;
    if (count _missingAddonsServer > 0) then {
        _missingAddonServer = true;

        private _error = format ["[KEKO] %1: ERROR missing server addon(s): ", _client];
        {
            _error = _error + format ["%1, ", _x];

            if (_forEachIndex > 9) exitWith {};//
        } forEach _missingAddonsServer;

        _error = _error call _fnc_cutComma;

        diag_log text _error;
        [QGVAR(systemChatGlobal), _error] call CBA_fnc_globalEvent;
    };

    private _oldVersionClient = false;
    if (count _oldVersionsClient > 0) then {
        _oldVersionClient = true;

        private _error = format ["[KEKO] %1: ERROR outdated addon(s): ", _client];
        {
            _error = _error + format ["%1 (client: %2, server: %3), ", _x select 0, _x select 1, _x select 2];

            if (_forEachIndex > 9) exitWith {};//
        } forEach _oldVersionsClient;

        _error = _error call _fnc_cutComma;

        diag_log text _error;
        [QGVAR(systemChatGlobal), _error] call CBA_fnc_globalEvent;
    };

    private _oldVersionServer = false;
    if (count _oldVersionsServer > 0) then {
        _oldVersionServer = true;

        private _error = format ["[KEKO] %1: ERROR outdated server addon(s): ", _client];
        {
            _error = _error + format ["%1 (client: %2, server: %3), ", _x select 0, _x select 1, _x select 2];

            if (_forEachIndex > 9) exitWith {};//
        } forEach _oldVersionsServer;

        _error = _error call _fnc_cutComma;

        diag_log text _error;
        [QGVAR(systemChatGlobal), _error] call CBA_fnc_globalEvent;
    };

    keko_Version_ClientErrors = [_missingAddon, _missingAddonServer, _oldVersionClient, _oldVersionServer];
};
