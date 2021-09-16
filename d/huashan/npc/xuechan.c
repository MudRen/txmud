// xuechan.c 血蟾 华山毛女洞by pian

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("血蟾", ({ "xue chan"}) );
	set("race", "野兽");
	set("age", 500);
	set("gender", "雌性");
	set("long", HIR"
这是一只小牛犊大小，通体鲜红的血蟾，
踞地而坐，正瞪着两眼盯着你看，你心
里一阵紧缩，头皮直发麻! \n"NOR);

	set("max_gin",10000);
	set("max_kee",10000);
	set("max_sen",10000);

	set("str", 100);
	set("combat_exp", 10000000);
	set("bellicosity", 10000);

	set_auto_recover(1);

	set("limbs", ({ "头部", "身体","腿" }) );
	set("verbs", ({ "bite","claw" }) );

	set_temp("apply/dodge", 900);
	set_temp("apply/unarmed",900);
	set_temp("apply/parry",900);
	set_temp("apply/damage",900);

	set_temp("apply/armor",300);
	set_temp("apply/damage",300);

	set("chat_chance", 5);
	set("chat_msg", ({
		HIR"血蟾盯着你的眼睛闪了一下，咽下口唾味。 \n"NOR,
		HIR"血蟾张开大嘴打了个呵欠，仍死死盯着你。 \n"NOR,
}) );

	setup();
}

int remove_enemy(object ob)
{
	mapping my;

	::remove_enemy(ob);

	if(!is_fighting())
	{
		my = query_entire_dbase();
	
		my["kee"] = my["max_kee"];
		my["eff_kee"] = my["max_kee"];
		my["gin"] = my["max_gin"];
		my["eff_gin"] = my["max_gin"];
		my["sen"] = my["max_sen"];
		my["eff_sen"] = my["max_sen"];
	}

	return 1;
}

// 死后产生两个宝贝
/*
void die()
{
	object ob;
	message_vision(HIR"$N化成一堆血水，死了。血泊中出现一只闪着红光的珠子。\n"NOR, this_object());
	ob = new(__DIR__"pihuozhu");
	ob->move(environment(this_object()));
	ob=new(__DIR__"lingzhi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
*/
