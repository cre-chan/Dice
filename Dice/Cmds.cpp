#include "CmdParser.h"



using namespace std;
using namespace Dice;

namespace CmdParser {
	typedef unsigned int uint;

	void Bot::run(DiceMsg dice_msg, bool& block_msg) {
		dice_msg.Reply("我是cre，我的结构验证成功了");
	}
	

	//自定义字符串切片
	class str_slice {
		const char *ptr;//用于访问字符串
		size_t  length;

	public:
		//将整个字符串转化为切片
		str_slice(const string& src):
			length(src.length()),ptr(src.c_str())
		{
		}

		//仅给出起始索引的情况
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

		//对切片进行切片
		str_slice(const str_slice src, size_t start) {
			if (start <= src.length) {
				length = src.length - start;
				ptr = src.ptr + start;
			}
			else {
				throw string("Starting index larger than total length");
			}
		}

		//判断某切片是否以pattern开头
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
			return unique_ptr<Cmd>(new Bot());//返回Bot
		}
		else {
			return unique_ptr<Cmd>();//返回空
		}
	}

}