#pragma once

#include <string>
#include <memory>
#include <functional>
#include "EventHandler.h"

using namespace std;
using namespace Dice;

namespace CmdParser{

	

	typedef std::string::const_iterator str_iter;//为不可更改的迭代器定义别名


	//指令类型，用于作为所有指令的基类类型标记
	class Cmd {

	public:
		//纯虚函数，根据指令类型，执行不同的动作
		virtual void run(DiceMsg dice_msg, bool& block_msg) = 0;
	};

	//与Bot指令对应
	class Bot :public Cmd {
		enum {ON,OFF,VERSION_INFO} param_type;//
	public:
		virtual void run(DiceMsg dice_msg, bool& block_msg);
	};

	//掷骰指令
	class Roll :public Cmd {

	};

	//掷骰指令,输出简化
	class RollSimpl :public Cmd {

	};

	//骰池
	class DicePool :public Cmd {

	};

	//设置默认骰
	class SetDefaultDice :public Cmd {

	};

	//San check
	class SanCheck :public Cmd {

	};

	//增强检定
	class En :public Cmd {

	};

	//COC人物生成
	class COCCharGen :public Cmd {

	};

	//DND人物生成
	class DNDCharGen :public Cmd {

	};

	//COC人物生成详细版
	class DetailedCOCCharGen :public Cmd {

	};

	//疯狂发作
	class GoMad :public Cmd {

	};

	//导入人物卡
	class ImportCard :public Cmd {

	};

	//技能检定
	class SkillCheck : public Cmd {

	};

	//今日人品
	class DailyLuck :public Cmd {

	};

	//随机生成名字
	class RandName :public Cmd {

	};

	//规则查询
	class RuleQuery :public Cmd {

	};

	//显示帮助
	class Help :public Cmd {

	};

	//DnD先攻掷骰
	class RollOnFirstAttack :public Cmd {

	};

	//DnD先攻查看/清空
	class CheckFirstAttack :public Cmd {

	};

	//设置/删除昵称
	class NickName :public Cmd {

	};

	//随机设置昵称
	class RandomNickName :public Cmd {

	};

	//暗骰
	class RollHidden :public Cmd {

	};

	//旁观模式
	class Observer :public Cmd {

	};

	//以第三方视角做出动作
	class ActionProxy :public Cmd {

	};

	//欢迎提示
	class Welcome :public Cmd {

	};

	unique_ptr<Cmd> parse_msg(string const msg);

}