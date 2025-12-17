#include <string>
#include <vector>

enum class ToyType {TalkingBear, GlowingRabbit, DancingPenguin, SingingBird};

class Toy {
public:
    Toy(const std::string& name, const std::string& type);
    virtual ~Toy() = default;
    
    virtual void showInfo() const;
    virtual void play() const = 0;  
    
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    int getBatteryLevel() const { return battery_level; }
    
    // 充电功能
    virtual void charge(int minutes);

protected:
    std::string name;
    std::string type;
    int battery_level;  // 电池电量 0-100
    bool is_charged;    // 是否已充电
};

// 会说话的熊
class TalkingBear : public Toy {
public:
    TalkingBear(const std::string& name);
    void play() const override;
    void setPhrase(const std::string& phrase);
    
private:
    std::string phrase;
};

// 发光兔子
class GlowingRabbit : public Toy {
public:
    GlowingRabbit(const std::string& name);
    void play() const override;
    void setColor(const std::string& color);
    void charge(int minutes) override;  // 特殊充电逻辑
    
private:
    std::string light_color;
    int brightness;  // 亮度级别
};

// 跳舞企鹅
class DancingPenguin : public Toy {
public:
    DancingPenguin(const std::string& name);
    void play() const override;
    void setDanceStyle(const std::string& style);
    
private:
    std::string dance_style;
    int dance_duration;  // 舞蹈时长
};

// 唱歌小鸟
class SingingBird : public Toy {
public:
    SingingBird(const std::string& name);
    void play() const override;
    void setSong(const std::string& song);
    
private:
    std::string song;
    int volume;  // 音量级别
};

class ToyFactory {
public:
    ToyFactory();
    ~ToyFactory();

    void addToy(const std::string& type, const std::string& name);
    
    void showAllToys() const;
    
    void testAllFunctions() const;
    
    void chargeAllToys(int minutes);
    
    Toy* findToy(const std::string& name) const;
    
    void showStatistics() const;

private:
    std::vector<Toy*> toys;
    int total_toys;
};

// 4. 工具函数
ToyType str_to_ToyType(const std::string& s);  // 字符串转枚举类型
Toy* make_toy(const std::string& type, const std::string& name);  // 创建玩具，返回堆对象指针