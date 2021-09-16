//full.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	int heal,heal1;
	object ob;

	if(arg)
		ob = LOGIN_D->find_body(arg);
	else
		ob = me;
	if(ob)
	{
		if(!wizardp(ob))
			sys_log("full",sprintf("%s full %s at %s\n",capitalize(geteuid(me)),
				capitalize(geteuid(ob)),ctime(time())));
		me = ob;
	}
	else return notify_fail("ʹ�ô���\n");

	heal = (int)me->query("max_kee") - (int)me->query("kee");
	heal1 = (int)me->query("max_kee") - (int)me->query("eff_kee");
	me->add("eff_kee",heal1);
	me->add("kee",heal);

	heal = (int)me->query("max_sen") - (int)me->query("sen");
	heal1 = (int)me->query("max_sen") - (int)me->query("eff_sen");
	me->add("eff_sen",heal1);
	me->add("sen",heal);

	heal = (int)me->query("max_gin") - (int)me->query("gin");
	heal1 = (int)me->query("max_gin") - (int)me->query("eff_gin");
	me->add("eff_gin",heal1);
	me->add("gin",heal);

	heal = me->max_water_capacity();
	heal1 = me->max_food_capacity();
	me->set("food",heal1);
	me->set("water",heal);

	message_vision(HIY+"$N������⣬���Ϸ���������â��"+NOR"\n", me);
	return 1;
}

int help(object me)
{
	if(wizardp(me))
       write( @TEXT
ָ���ʽ��full

���ָ���������������
TEXT
       );
       return 1 ;
}