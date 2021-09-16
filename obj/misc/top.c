// top.c

inherit ITEM;

protected string top_exp, top_rich, top_force, top_bang;

protected void read_msg()
{
	if(!top_exp = read_file(__DIR__"top_exp"))
		top_exp = "无信息\n";
	if(!top_rich = read_file(__DIR__"top_rich"))
		top_rich = "无信息\n";
	if(!top_force = read_file(__DIR__"top_force"))
		top_force = "无信息\n";
	if(!top_bang = read_file(__DIR__"top_bang"))
		top_bang = "无信息\n";
}

protected void create()
{
	set_name("《江湖花名册》", ({ "ming ce" }) );
	set_weight(100);
	if( clonep() )
	{
		read_msg();
		set("value", 1000);
		set_default_object(__FILE__);
	} else {
		set("unit", "本");
		set("long", "
这是一本江湖花名册，封面写着：
    武功前十名         yuedu exp
    财富前十名         yuedu rich
    内功前十名         yuedu force
    仁义榜悬赏前十名   yuedu renyi
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
			return notify_fail("你要阅读哪篇内容？\n");
	}

	return 1;
}
