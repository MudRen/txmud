// shedan.c

inherit ITEM;

void create()
{
	set_name("七步蛇胆", ({ "she dan"}) );
        set_weight(50);
        if( clonep() )
	{
		set_default_object(__FILE__);
		call_out("do_decay",300);
	}
        else
	{
		set("unit", "个");
		set("long", "这是一个墨绿色的七步蛇胆。\n");
	}
}

protected void do_decay()
{
	object env;

	if(!objectp(env = environment()))
	{
		destruct(this_object());
		return;
	}
	tell_object(env,sprintf("%s慢慢开始腐烂了。\n",name()));
	set("name","腐烂的七步蛇胆");
	set("long", "这是一个腐烂的七步蛇胆，正散发着刺鼻的恶臭。\n");
}
