--
-------------------------------------------------------------------------------
function temp_call(arg1, arg2)
	return arg1 + arg2
end
-------------------------------------------------------------------------------
function add_number(arg1, arg2)
	return arg1 + arg2
end
-------------------------------------------------------------------------------
function test_table(arg)

	print(arg)
	print(arg.value)
	print(arg.inside)
	print(arg.inside.value)
	
	arg.test = "input from lua"
	
end
-------------------------------------------------------------------------------
function raise_error()

	raise_error_1()
end

function raise_error_1()

	raise_error_2()
end

function raise_error_2()

	-- calling unknwon funtion
	-- error occur and callstack is generated
	raise_error_3()
end

-------------------------------------------------------------------------------

print(g_test)					-- 전역 g_test 를 출력한다
print(g_test._test)				-- 전역 g_test 의 멤버 변수 _test 를 출력한다
print(g_test:is_test())			-- const char* test::is_test() 함수를 호출한다
print(g_test:ret_int())			-- test::ret_int() 함수를 호출한다
temp = test(4)					-- temp 에 새 test 객체를 넣는다
print(temp._test)				-- test 의 멤버 변수 _test 값을 출력한다
a = g_test:get()				-- lua 에서 정의되지 않은 A를 받음
temp:set(a)						-- A 를 g_test 에 넣음
print(temp._test)				-- A 를 넘겨 받음으로 _test 값이 변함
print(temp:is_base())			-- 부모의 함수 호출
print(temp:is_test())			-- 자신의 함수 호출
parent = GetChild(0)			-- 부모를 받는다
print("--------------------------")
dir(parent)						-- parent 의 정보를 출력한다
child = GetChild(1)				-- 자식을 받는다
print("--------------------------")
dir(child)						-- child 의 정보를 출력한다
grandchild = GetChild(2)		-- 손자를 받는다
print("--------------------------")
dir(grandchild)					-- grandchild 의 정보를 출력한다

