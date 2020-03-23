# lua-magic

Lua binding to libmagic to recognize the type of data in a file using "magic" numbers

## Build Dependencies

libmagic-dev liblua5.1-dev

## Usage Example

```lua
local magic = require 'magic'

local m = magic.mimetype("test.lua")

local e = magic.encoding("test.lua")

print("mimetype: "..m)

print("encoding: " ..e)
```


