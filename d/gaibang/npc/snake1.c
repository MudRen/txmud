// snake1.c
// by dicky

inherit ITEM;
int decayed;

void create()
{
        set_name("毒蛇", ({ "snake"}) );
	set("long", "一条凶狠的毒蛇，此时正卷成一团。\n");
	set("unit", "条" );
        if( clonep() )
                set_default_object(__FILE__);
		call_out("decay", 300, 1);
}

void decay(int phase)
{
	object me=this_object();
	decayed = phase;

	if(!environment())
	{
		destruct(me);
		return;
	}

	tell_object(environment(), "" + me->query("name") + "突然" +me->query("name")+ "窜去草丛不见了，你想去抓他，可是已经来不及！\n\n" );
        destruct(me);
}