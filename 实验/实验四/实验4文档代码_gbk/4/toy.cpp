#include "toy.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cctype>

using namespace std;

// 基类
Toy::Toy(const string& name_, const string& type_)
	: name(name_), type(type_), battery_level(50), is_charged(false) {}

void Toy::showInfo() const {
	cout << "类型: " << type << ", 名称: " << name
		 << ", 电量: " << battery_level << "%"
		 << ", 充电状态: " << (is_charged ? "是" : "否") << '\n';
}

void Toy::charge(int minutes) {
	if (minutes <= 0) return;
	battery_level = min(100, battery_level + minutes);
	is_charged = (battery_level > 0);
}

// TalkingBear
TalkingBear::TalkingBear(const string& name)
	: Toy(name, "会说话的熊"), phrase("你好！") {}

void TalkingBear::play() const {
	cout << "[会说话的熊] " << name << " 说: '" << phrase << "'\n";
}

void TalkingBear::setPhrase(const string& p) {
	phrase = p;
}


GlowingRabbit::GlowingRabbit(const string& name)
	: Toy(name, "发光兔子"), light_color("白色"), brightness(5) {}

void GlowingRabbit::play() const {
	cout << "[发光兔子] " << name << " 发光： " << light_color
		 << " ， 亮度： " << brightness << "\n";
}

void GlowingRabbit::setColor(const string& color) {
	light_color = color;
}

void GlowingRabbit::charge(int minutes) {
	if (minutes <= 0) return;
	battery_level = min(100, battery_level + minutes * 2);
	brightness = min(10, brightness + minutes / 5);
	is_charged = (battery_level > 0);
}

DancingPenguin::DancingPenguin(const string& name)
	: Toy(name, "跳舞企鹅"), dance_style("华尔兹"), dance_duration(10) {}

void DancingPenguin::play() const {
	cout << "[跳舞企鹅] " << name << " 跳舞 '" << dance_style
		 << "' 持续 " << dance_duration << " 秒" << "\n";
}

void DancingPenguin::setDanceStyle(const string& style) {
	dance_style = style;
}

SingingBird::SingingBird(const string& name)
	: Toy(name, "唱歌小鸟"), song("啦啦"), volume(5) {}

void SingingBird::play() const {
	cout << "[唱歌小鸟] " << name << " 唱歌 '" << song
		 << "' 音量 " << volume << "\n";
}

void SingingBird::setSong(const string& s) {
	song = s;
}

ToyFactory::ToyFactory() : total_toys(0) {}

ToyFactory::~ToyFactory() {
	for (auto p : toys) delete p;
	toys.clear();
}

void ToyFactory::addToy(const string& type, const string& name) {
	Toy* t = make_toy(type, name);
	if (t) {
		toys.push_back(t);
		++total_toys;
	}
}

void ToyFactory::showAllToys() const {
	cout << "--- 所有玩具 ---\n";
	for (const auto& t : toys) {
		if (t) t->showInfo();
	}
}

void ToyFactory::testAllFunctions() const {
	cout << "--- 测试所有玩具 ---\n";
	for (const auto& t : toys) {
		if (t) {
			t->showInfo();
			t->play();
		}
	}
}

void ToyFactory::chargeAllToys(int minutes) {
	for (auto& t : toys) {
		if (t) t->charge(minutes);
	}
}

Toy* ToyFactory::findToy(const string& name_) const {
	for (auto t : toys) {
		if (t && t->getName() == name_) return t;
	}
	return nullptr;
}

void ToyFactory::showStatistics() const {
	cout << "--- 统计 ---\n";
	cout << "玩具总数: " << total_toys << "\n";
	if (toys.empty()) return;
	double avg = accumulate(toys.begin(), toys.end(), 0.0,
		[](double acc, Toy* t){ return acc + (t ? t->getBatteryLevel() : 0); }) / toys.size();
	cout << "平均电量: " << avg << "%\n";
}

// Helpers
ToyType str_to_ToyType(const string& s) {
	string low;
	low.reserve(s.size());
	for (char c : s) low.push_back(tolower((unsigned char)c));
	if (low.find("talk") != string::npos || low.find("bear") != string::npos) return ToyType::TalkingBear;
	if (low.find("glow") != string::npos || low.find("rabbit") != string::npos) return ToyType::GlowingRabbit;
	if (low.find("dance") != string::npos || low.find("penguin") != string::npos) return ToyType::DancingPenguin;
	if (low.find("sing") != string::npos || low.find("bird") != string::npos) return ToyType::SingingBird;

	return ToyType::TalkingBear;
}

Toy* make_toy(const string& type, const string& name) {
	switch (str_to_ToyType(type)) {
		case ToyType::TalkingBear: return new TalkingBear(name);
		case ToyType::GlowingRabbit: return new GlowingRabbit(name);
		case ToyType::DancingPenguin: return new DancingPenguin(name);
		case ToyType::SingingBird: return new SingingBird(name);
	}
	return nullptr;
}

