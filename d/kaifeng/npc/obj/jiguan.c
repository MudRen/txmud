// jiguan.c

inherit ITEM;

private int last = 0;

void create()
{
        set_name("公鸡冠", ({ "ji guan"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "个");
		set("long", "公鸡冠\n");
	}
}

void init()
{
	if( (environment() == this_player()) && !last)
	{
		last = 1;
		remove_call_out("do_lasting");
		call_out("do_lasting",240);
	}
}

void do_lasting()
{
	if(environment())
		tell_object(environment(),"公鸡冠放的时间太长，变干了。\n");
	set("name","变干的公鸡冠");
}
