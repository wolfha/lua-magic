/**
  Copyright (c) 2014 Wolfgang Hauptfleisch <wh@augmentedlogic.com>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
 **/

#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <magic.h>

#define luaL_reg luaL_Reg

static int l_encoding(lua_State *L)
{
    size_t l;
    const char *target_file = luaL_checklstring(L, 1, &l);
    const char *magic_result;
    magic_t magic_cookie;
    magic_cookie = magic_open(MAGIC_MIME_ENCODING);
    if (magic_cookie == NULL) {
        lua_pushboolean(L, 0);
        return 1;
    }
    if (magic_load(magic_cookie, NULL) != 0) {
        lua_pushboolean(L, 0);
        magic_close(magic_cookie);
        return 1;
    }
    magic_result = magic_file(magic_cookie, target_file);
    lua_pushstring(L, magic_result);
    magic_close(magic_cookie);
    return 1;
}


static int l_mime(lua_State *L)
{
    size_t l;
    const char *target_file = luaL_checklstring(L, 1, &l);
    const char *magic_result;
    magic_t magic_cookie;
    magic_cookie = magic_open(MAGIC_MIME_TYPE);
    if (magic_cookie == NULL) {
        lua_pushboolean(L, 0);
        return 1;
    }
    if (magic_load(magic_cookie, NULL) != 0) {
        lua_pushboolean(L, 0);
        magic_close(magic_cookie);
        return 1;
    }
    magic_result = magic_file(magic_cookie, target_file);
    lua_pushstring(L, magic_result);
    magic_close(magic_cookie);
    return 1;
}

static const luaL_Reg lib[] = {
    {"mimetype", l_mime},
    {"encoding", l_encoding},
    {NULL, NULL}
};


LUALIB_API int luaopen_magic(lua_State *L) {
    luaL_register(L, "magic", lib);
    //luaL_openlib(L, "magic", lib, 0);
    return 1;
}

