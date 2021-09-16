// hhd.c

#include <ansi.h>

inherit ITEM;

void init()
{
	if (present(this_object(), this_player())) {
		add_action("do_eat", "eat");
		add_action("do_eat", "chi");
		add_action("do_eat", "yan");
		add_action("do_eat", "tun");
	}
}

void create()
{
       set_name(HIG "还魂丹" NOR, ({"huanhun dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"这是一颗" HIG"绿色"NOR "的丹丸，吃了不知道会......\n");
		set("unit", "颗");
	}
}

int do_eat(string arg)
{
	int i;
	string *skills;

	object me = this_player();
	if (!living(me)) return notify_fail("想当机吗？\n");
	if (!id(arg)) return 0;

	if(!me)
		return;
	skills = me->query_skills_name();
	if(skills && arrayp(skills))
	{
		for(i=0;i<sizeof(skills);i++)
		{
			me->delete_skill(skills[i]);
		}
	}

	me->reincarnate();
        me->set("kee", me->query("max_kee"));
        me->set("gin", me->query("max_gin"));
        me->set("sen", me->query("max_sen"));
        me->set("force", me->query("max_force"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
       	destruct(this_object());
	return 1;
}
