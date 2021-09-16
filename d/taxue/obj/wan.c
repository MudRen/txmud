// dan.c

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
        int i,lvl=1;
        mapping skills;
        string *sk;

	object me = this_player();
	if (!living(me)) return notify_fail("想当机吗？\n");
	if (!id(arg)) return 0;

	skills = me->query_skills();
        if (mapp(skills)) {
                sk = keys(skills);
                for (i=0;i<sizeof(sk);i++)
                         skills[sk[i]]+=lvl;

        }
	me->add("combat_exp",10000);
	me->add("potential",10000);


		message_vision(HIG "$N狠狠地吞下一颗"
		+this_object()->query("name")+
		HIG "，一丝丝魂魄又回到体内，武功猛增。\n"
		"$N高兴地跳了起来，大叫：味道好极了，还要！\n" NOR
		HIY "结果$N高兴地过了头。\n" NOR,me);
		remove_action("do_eat", "eat");
		remove_action("do_eat", "chi");
		remove_action("do_eat", "yan");
		remove_action("do_eat", "tun");
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
