#pragma once // 放置文件冲突导入，如果include两个同名文件，只会导入一个，并且只会检索文件名，不会检索文件内容
#include <string>
#include <string> // 因为pragma once的关系不做导入

struct User {
	std::string name;
	int age;
	std::string addr;
};