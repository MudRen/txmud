// addnews.c
// by Find.

inherit F_CLEAN_UP;

void confirm_type(string type);
void get_number(string n,string type);

int main(object me,string arg)
{
	if(me != this_player(1))
		return 0;

	if(wiz_level(me) < wiz_level("(admin)"))
		return 0;

	write(@TISHI
新闻类型：

巫师新闻(w)	玩家新闻(p)	通告(g)

请选择你要增加的新闻类型(w,p,g | q 退出)：
TISHI
);
	input_to("confirm_type");
	return 1;
}

void confirm_type(string type)
{
	if(stringp(type) && (type[0] == 'q'))
	{
		write("退出。\n");
		return;
	}

	if(type != "w" && type != "p" && type != "g")
	{
		write("选择类型错误！！\n");
		write("请选择你要增加的新闻类型(w,p,g | q 退出)：\n");
		input_to("confirm_type");
		return;
	}

	write("请设定此条新闻的阅读次数(0 代表永远有效 | q 退出)\n");
	input_to("get_num",type);
}

void get_num(string n,string type)
{
	int num;

	if(stringp(n) && (n[0] == 'q'))
	{
		write("退出。\n");
		return;
	}

	if(!sscanf(n,"%d",num) || num < 0)	// 使用默认值
	{
		switch (type)
		{
			case "w":
				num = 2;
				break;
			case "p":
				num = 1;
				break;
			default:
				num = 3;
		}
	}

	write("请输入新闻的内容：\n");
	this_player(1)->edit( (:call_other, this_object(), ({ "do_content",num,type }) :) );
}

void do_content(int num, string type, string content)
{
	if(!stringp(content) || content == "")
	{
		write("此条新闻内容为空，为无效新闻。\nok.\n");
		return;
	}

	if(!(NEWS_D->add_news_item(content, type, num)))
	{
		write("新闻写入失败。\n");
		return;
	}

	else
	{
		write("新闻写入成功。\n");
		return;
	}
}

int help(object me)
{
	write(@HELP
指令格式 : addnews

增加一条新闻。

HELP
    );
    return 1;
}
 
