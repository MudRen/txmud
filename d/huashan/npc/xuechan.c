// xuechan.c Ѫ� ��ɽëŮ��by pian

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("Ѫ�", ({ "xue chan"}) );
	set("race", "Ұ��");
	set("age", 500);
	set("gender", "����");
	set("long", HIR"
����һֻСţ����С��ͨ���ʺ��Ѫ󸣬
��ض��������������۶����㿴������
��һ�������ͷƤֱ����! \n"NOR);

	set("max_gin",10000);
	set("max_kee",10000);
	set("max_sen",10000);

	set("str", 100);
	set("combat_exp", 10000000);
	set("bellicosity", 10000);

	set_auto_recover(1);

	set("limbs", ({ "ͷ��", "����","��" }) );
	set("verbs", ({ "bite","claw" }) );

	set_temp("apply/dodge", 900);
	set_temp("apply/unarmed",900);
	set_temp("apply/parry",900);
	set_temp("apply/damage",900);

	set_temp("apply/armor",300);
	set_temp("apply/damage",300);

	set("chat_chance", 5);
	set("chat_msg", ({
		HIR"Ѫ󸶢������۾�����һ�£����¿���ζ�� \n"NOR,
		HIR"Ѫ��ſ�������˸���Ƿ�������������㡣 \n"NOR,
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

// ���������������
/*
void die()
{
	object ob;
	message_vision(HIR"$N����һ��Ѫˮ�����ˡ�Ѫ���г���һֻ���ź������ӡ�\n"NOR, this_object());
	ob = new(__DIR__"pihuozhu");
	ob->move(environment(this_object()));
	ob=new(__DIR__"lingzhi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
*/
