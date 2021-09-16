// muou.c

inherit ITEM;

void create()
{
	set_name("ľż",({"muou"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	    set("long",
		"����һ���������۵�ľż,���ǿ���(apply) ��\n");
	    set("unit","��");
	    set("value", 10000);
	}
}

void init()
{
	add_action("do_apply","apply");
}


void remove_use(object ob)
{
	ob->delete_temp("in_use");
}

int do_apply(string arg)
{
	object me,ob,weapon,obj;
	string attack_skill;
	int attack,dodge,parry,def;

	if (arg!="muou")
	{
		return 0;
	}

	obj=this_object();
	if (obj->query_temp("in_use"))
	{
		write("���������.\n");
		return 1;
	}
	me=this_player();
	if (me->query("combat_exp")<30000)
	{
		write("��ľ��鲻��.\n");
		return 1;
	}
	ob=new("/obj/prize/muren.c");
//	me=this_player();

	weapon=me->query_temp("weapon");
	if( objectp(weapon) )
		attack_skill = weapon->query("skill_type");
	else
		attack_skill = "unarmed";

	attack=me->query_skill(attack_skill)+me->query_temp("apply/attack");
	dodge=me->query_skill("dodge")+me->query_temp("apply/defense");
	parry=me->query_skill("parry")+me->query_temp("apply/defense");
	def=dodge;

	ob->set_temp("apply/attack",def*11/10);
	ob->set_temp("apply/dodge",attack*11/10);
	ob->set("combat_exp",me->query("combat_exp")*12/10);
	ob->set("str",20+random(me->query("combat_exp")/3000));
	ob->move(environment(me));

	write("��Ȼ����һ��ľ��.\n");

	obj->set_temp("in_use",1);
	call_out("remove_use",180,obj);
	destruct (this_object());
	return 1;

}


