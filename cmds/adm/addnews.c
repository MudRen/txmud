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
�������ͣ�

��ʦ����(w)	�������(p)	ͨ��(g)

��ѡ����Ҫ���ӵ���������(w,p,g | q �˳�)��
TISHI
);
	input_to("confirm_type");
	return 1;
}

void confirm_type(string type)
{
	if(stringp(type) && (type[0] == 'q'))
	{
		write("�˳���\n");
		return;
	}

	if(type != "w" && type != "p" && type != "g")
	{
		write("ѡ�����ʹ��󣡣�\n");
		write("��ѡ����Ҫ���ӵ���������(w,p,g | q �˳�)��\n");
		input_to("confirm_type");
		return;
	}

	write("���趨�������ŵ��Ķ�����(0 ������Զ��Ч | q �˳�)\n");
	input_to("get_num",type);
}

void get_num(string n,string type)
{
	int num;

	if(stringp(n) && (n[0] == 'q'))
	{
		write("�˳���\n");
		return;
	}

	if(!sscanf(n,"%d",num) || num < 0)	// ʹ��Ĭ��ֵ
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

	write("���������ŵ����ݣ�\n");
	this_player(1)->edit( (:call_other, this_object(), ({ "do_content",num,type }) :) );
}

void do_content(int num, string type, string content)
{
	if(!stringp(content) || content == "")
	{
		write("������������Ϊ�գ�Ϊ��Ч���š�\nok.\n");
		return;
	}

	if(!(NEWS_D->add_news_item(content, type, num)))
	{
		write("����д��ʧ�ܡ�\n");
		return;
	}

	else
	{
		write("����д��ɹ���\n");
		return;
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ : addnews

����һ�����š�

HELP
    );
    return 1;
}
 
