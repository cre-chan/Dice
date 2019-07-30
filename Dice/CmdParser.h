#pragma once

#include <string>
#include <memory>
#include <functional>
#include "EventHandler.h"

using namespace std;
using namespace Dice;

namespace CmdParser{

	

	typedef std::string::const_iterator str_iter;//Ϊ���ɸ��ĵĵ������������


	//ָ�����ͣ�������Ϊ����ָ��Ļ������ͱ��
	class Cmd {

	public:
		//���麯��������ָ�����ͣ�ִ�в�ͬ�Ķ���
		virtual void run(DiceMsg dice_msg, bool& block_msg) = 0;
	};

	//��Botָ���Ӧ
	class Bot :public Cmd {
		enum {ON,OFF,VERSION_INFO} param_type;//
	public:
		virtual void run(DiceMsg dice_msg, bool& block_msg);
	};

	//����ָ��
	class Roll :public Cmd {

	};

	//����ָ��,�����
	class RollSimpl :public Cmd {

	};

	//����
	class DicePool :public Cmd {

	};

	//����Ĭ����
	class SetDefaultDice :public Cmd {

	};

	//San check
	class SanCheck :public Cmd {

	};

	//��ǿ�춨
	class En :public Cmd {

	};

	//COC��������
	class COCCharGen :public Cmd {

	};

	//DND��������
	class DNDCharGen :public Cmd {

	};

	//COC����������ϸ��
	class DetailedCOCCharGen :public Cmd {

	};

	//�����
	class GoMad :public Cmd {

	};

	//�������￨
	class ImportCard :public Cmd {

	};

	//���ܼ춨
	class SkillCheck : public Cmd {

	};

	//������Ʒ
	class DailyLuck :public Cmd {

	};

	//�����������
	class RandName :public Cmd {

	};

	//�����ѯ
	class RuleQuery :public Cmd {

	};

	//��ʾ����
	class Help :public Cmd {

	};

	//DnD�ȹ�����
	class RollOnFirstAttack :public Cmd {

	};

	//DnD�ȹ��鿴/���
	class CheckFirstAttack :public Cmd {

	};

	//����/ɾ���ǳ�
	class NickName :public Cmd {

	};

	//��������ǳ�
	class RandomNickName :public Cmd {

	};

	//����
	class RollHidden :public Cmd {

	};

	//�Թ�ģʽ
	class Observer :public Cmd {

	};

	//�Ե������ӽ���������
	class ActionProxy :public Cmd {

	};

	//��ӭ��ʾ
	class Welcome :public Cmd {

	};

	unique_ptr<Cmd> parse_msg(string const msg);

}