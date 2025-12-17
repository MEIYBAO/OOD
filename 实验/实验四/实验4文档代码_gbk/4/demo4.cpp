#include "toy.hpp"
#include <iostream>

using namespace std;

int main() {
	ToyFactory factory;

	factory.addToy("TalkingBear", "Ted");
	factory.addToy("GlowingRabbit", "Luna");
	factory.addToy("DancingPenguin", "Penny");
	factory.addToy("SingingBird", "Chirpy");

	cout << "初始化 玩具:\n";
	factory.showAllToys();

	cout << "\n玩所有玩具:\n";
	factory.testAllFunctions();

	// 定制部分：根据类型设置特有属性
	if (auto t = factory.findToy("Ted")) {
		if (auto bear = dynamic_cast<TalkingBear*>(t)) bear->setPhrase("我爱 C++！");
	}
	if (auto t = factory.findToy("Luna")) {
		if (auto rab = dynamic_cast<GlowingRabbit*>(t)) rab->setColor("紫色");
	}
	if (auto t = factory.findToy("Penny")) {
		if (auto pen = dynamic_cast<DancingPenguin*>(t)) pen->setDanceStyle("嘻哈");
	}
	if (auto t = factory.findToy("Chirpy")) {
		if (auto bird = dynamic_cast<SingingBird*>(t)) bird->setSong("小星星");
	}

	cout << "\n定制后:\n";
	factory.testAllFunctions();

	cout << "\n为所有玩具充电10分钟...\n";
	factory.chargeAllToys(10);
	factory.showAllToys();

	factory.showStatistics();

	return 0;
}

