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
       set_name(HIG "���굤" NOR, ({"huanhun dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"����һ��" HIG"��ɫ"NOR "�ĵ��裬���˲�֪����......\n");
		set("unit", "��");
	}
}

int do_eat(string arg)
{
	int i,lvl=1;
	mapping skills;
	string *sk;

	object me = this_player();
	if (!living(me)) return notify_fail("�뵱����\n");
	if (!id(arg)) return 0;

	skills = me->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			if (SKILL_D(sk[i])->type() == "martial")
				skills[sk[i]]+=lvl;
	}
	i = me->query("death_count") - 1;
	if (i < 0) i = 0;
	me->set("death_count", i);
	if (i < me->query("death_times")) me->set("death_times", i);
	if (lvl<4) {
		message_vision(HIG "$NС�ĵس���һ��"
		+this_object()->query("name")+
          HIG "��һ˿˿�����ֻص����ڣ����û��������������\n"
		NOR,me);
		"/adm/daemons/emoted"->do_emote(me,"taste");
	}
	else {
		message_vision(HIG "$N�ݺݵ�����һ��"
		+this_object()->query("name")+
		HIG "��һ˿˿�����ֻص����ڣ��书������\n"
		"$N���˵�������������У�ζ���ü��ˣ���Ҫ��\n" NOR
		HIY "���$N���˵ع���ͷ��\n" NOR,me);
		remove_action("do_eat", "eat");
		remove_action("do_eat", "chi");
		remove_action("do_eat", "yan");
		remove_action("do_eat", "tun");
		me->unconcious();
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
