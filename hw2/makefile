# TEAM: AMERICA

global: bankwithlist testdriver testdriver2 testdriver3
bankwithlist: bankwithlist.cpp BasicAccount.cpp
	g++ bankwithlist.cpp BasicAccount.cpp -o bankwithlist --std=c++11

testdriver: testdriver.cpp
	g++ testdriver.cpp -o testdriver --std=c++11
testdriver2: testdriver2.cpp
	g++ testdriver2.cpp BasicAccount.cpp -o testdriver2 --std=c++11
testdriver3: testdriver3.cpp
	g++ testdriver3.cpp BasicAccount.cpp -o testdriver3 --std=c++11

clean:
	rm bankwithlist testdriver testdriver2 testdriver3
