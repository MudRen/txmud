// wear.c
// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("��Ҫ����ʲô��\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
		if(!count)
			return notify_fail("��û��ʲô���Դ����Ķ�����\n");
		if(me->is_fighting())
			me->start_busy(1);
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

	if(do_wear(me, ob))
	{
		if(me->is_fighting())
			me->start_busy(1);
		return 1;
	}
	else
		return 0;
}

int do_wear(object me, object ob)
{
	string str;
	string *item;
	mapping add_ability;
	int i;

#ifdef WIZARD_FLAG
	if(ob->query_wiz_flag() && userp(me) && !wizardp(me))
		return notify_fail(ob->name()+"����ʦ��Ʒ���㲻��װ����\n");
#endif

	if( ob->query("female_only")
	&& (string)me->query("gender") != "Ů��" )
		return notify_fail("����Ů�˴��õĶ�������һ�������˴��Ͽ��²����ʰɣ�\n");

        if(mapp(add_ability = ob->query("wear_skill")))
        {
        item = keys(add_ability);
        for(i = 0; i<sizeof(item);i++)
                {
                if(!me->query_skill(item[i],1)
                   || me->query_skill(item[i],1) < (int)add_ability[item[i]])
			return notify_fail("���"+to_chinese(item[i])+"��ûѧ�ã��޷�װ��"+ob->name()+"��\n");
                }
        }

        if(mapp(add_ability = ob->query("wear_ability")))
        {
		item = keys(add_ability);
		for(i = 0; i<sizeof(item);i++)
                {
			if(!me->query(item[i])
			|| me->query(item[i]) < (int)add_ability[item[i]] )
				return notify_fail("��Ŀǰ�����������޷�װ��"+ob->name()+"��\n");
		}
	}

	if( ob->wear() )
	{
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "waist":
					str = YEL "$N��һ" + ob->query("unit") + "$n�������䡣\n" NOR;
					break;
				default:
					str = YEL "$Nװ��$n��\n" NOR;
			}
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��wear <װ������>
 
���ָ������װ��ĳ�����ߡ�
 
HELP
    );
    return 1;
}
