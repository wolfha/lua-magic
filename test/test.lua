package.cpath = package.path..";../src/?.so;"

--
-- simple test for lua-magic
--

local magic = require 'magic'

local m = magic.mimetype("test.lua")

local e = magic.encoding("test.lua")

print("mimetype: "..m)

print("encoding: " ..e)
