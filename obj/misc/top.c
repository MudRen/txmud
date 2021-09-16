// top.c

inherit ITEM;

protected string top_exp, top_rich, top_force, top_bang;

protected void read_msg()
{
	if(!top_exp = read_file(__DIR__"top_exp"))
		top_exp = "����Ϣ\n";
	if(!top_rich = read_file(__DIR__"top_rich"))
		top_rich = "����Ϣ\n";
	if(!top_force = read_file(__DIR__"top_force"))
		top_force = "����Ϣ\n";
	if(!top_bang = read_file(__DIR__"top_bang"))
		top_bang = "����Ϣ\n";
}

protected void create()
{
	set_name("�����������ᡷ", ({ "ming ce" }) );
	set_weight(100);
	if( clonep() )
	{
		read_msg();
		set("value", 1000);
		set_default_object(__FILE__);
	} else {
		set("unit", "��");
		set("long", "
����һ�����������ᣬ����д�ţ�
    �书ǰʮ��         yuedu exp
    �Ƹ�ǰʮ��         yuedu rich
    �ڹ�ǰʮ��         yuedu force
    ���������ǰʮ��   yuedu renyi
\n");
	}
}

void init()
{
	object env;
	if(objectp(env = environment()) && userp(env))
		delete("value");

	add_action("do_read", "yuedu");
}

int do_read(string arg)
{
	switch(arg)
	{
		case "exp":
			write(top_exp);
			break;
		case "rich":
			write(top_rich);
			break;
		case "force":
			write(top_force);
			break;
		case "renyi":
			write(top_bang);
			break;
		default:
			return notify_fail("��Ҫ�Ķ���ƪ���ݣ�\n");
	}

	return 1;
}
