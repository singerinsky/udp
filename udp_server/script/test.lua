#!/usr/bin/lua
print "hello world"
print (b)
bTtest = true
uNumber = 1.1111111
print (bTtest)
print (type(bTtest))
print (uNumber)
print (type(uNumber))

function test_func()
    local table1 = {"1","2"}
    for k,v in pairs(table1) do
        print (k)
    end

end

test_func()
