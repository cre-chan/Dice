#include "CmdParser.h"



using namespace std;
using namespace Dice;

namespace CmdParser {
	typedef unsigned int uint;

	void Bot::run(DiceMsg dice_msg, bool& block_msg) {
		dice_msg.Reply("����cre���ҵĽṹ��֤�ɹ���");
	}
	

	//�Զ����ַ�����Ƭ
	class str_slice {
		const char *ptr;//���ڷ����ַ���
		size_t  length;

	public:
		//�������ַ���ת��Ϊ��Ƭ
		str_slice(const string& src):
			length(src.length()),ptr(src.c_str())
		{
		}

		//��������ʼ���������
		str_slice(const string& src, size_t start) {
			size_t src_len = src.length();
			if (start <= src_len) {
				length = src_len - start;
				ptr = &src[start];
			}
			else {
				throw string("Starting index larger than total length");
			}
		}

		//����Ƭ������Ƭ
		str_slice(const str_slice src, size_t start) {
			if (start <= src.length) {
				length = src.length - start;
				ptr = src.ptr + start;
			}
			else {
				throw string("Starting index larger than total length");
			}
		}

		//�ж�ĳ��Ƭ�Ƿ���pattern��ͷ
		bool starts_with(const string& pattern) {
			size_t pattern_len = pattern.length();

			if (this->length <= pattern_len) {
				return false;
			}
			else {
				for (uint i = 0; i < pattern_len; i++)
					if (ptr[i] != pattern[i]) return false;
						
				return true;
			}
		}

		str_slice skip_while(function<bool(char)> predicate) {
			uint i = 0;
			for (; i < this->length; i++)
				if (!predicate(this->ptr[i])) break;

			return str_slice(*this, i);
		}
	};


	unique_ptr<Cmd> parse_msg(string const msg) {
		str_slice cmd_str = str_slice(msg).skip_while(
			[](auto c) {return isspace(c); }
		);

		if (cmd_str.starts_with(".")) {
			return unique_ptr<Cmd>(new Bot());//����Bot
		}
		else {
			return unique_ptr<Cmd>();//���ؿ�
		}
	}

}