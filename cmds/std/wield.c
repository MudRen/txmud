// wield.c
// Modified by Find.

#include <weapon.h>

inherit F_CLEAN_UP;

protected int do_wield(object me, object ob,int flag);

int main(object me, string arg)
{
        object ob;
        int flag = 0, left,right;

        if( !arg ) return notify_fail("��Ҫװ��ʲô������\n");

	if(sscanf(arg,"-l %s",arg))
		flag = 1;

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("������û������������\n");

	if(flag) /* ������ָ��װ�������ֵ�Ԥ�жϡ�*/
	{
		if(!(ob->query("flag") & SECONDARY))
			return notify_fail(ob->name()+"����װ�������֡�\n");
		if(me->query_temp("secondary_weapon"))
			return notify_fail("��������Ѿ�װ��������������\n");
	}

        if( ob->query("equipped") )
                return notify_fail("���Ѿ�װ��"+ob->name()+"�ˡ�\n");

	if( (left = me->query_limb_wound("����"))
	&& (right = me->query_limb_wound("����")) )
		return notify_fail("���˫�ֶ��������ˣ�û���ñ����ˡ�\n");
	if(flag && left)
		return notify_fail("��������������ˣ�����û���ñ����ˡ�\n");
	if( !flag && me->query_limb_wound("����") )
		return notify_fail("��������������ˣ�����û���ñ����ˡ�\n");
	if((ob->query("flag") & TWO_HANDED) && me->query_limb_wound("����"))
		return notify_fail("��������������ˣ�����û���ñ����ˡ�\n");

	if(do_wield(me, ob, flag))
	{
		if(me->is_fighting())
			me->start_busy(1);
		return 1;
	}
	else
		return 0;
}

protected int do_wield(object me, object ob, int flag)
{
        string str;
        string *item;
        mapping add_ability;
        int i;

#ifdef WIZARD_FLAG
	if(ob->query_wiz_flag() && userp(me) && !wizardp(me))
		return notify_fail(ob->name()+"����ʦ��Ʒ���㲻��װ����\n");
#endif

        if(mapp(add_ability = ob->query("wield_skill")))
        {
        item = keys(add_ability);
        for(i = 0; i<sizeof(item);i++)
                {
                if(!me->query_skill(item[i],1)
                   || me->query_skill(item[i],1) < (int)add_ability[item[i]])
			return notify_fail("���"+to_chinese(item[i])+"��ûѧ�ã����ܼ�Ԧ"+ob->name()+"��\n");
                }
        }

        if(mapp(add_ability = ob->query("wield_ability")))
        {
		item = keys(add_ability);
		for(i = 0; i<sizeof(item);i++)
                {
			if(!me->query(item[i])
			|| me->query(item[i]) < (int)add_ability[item[i]] )
				return notify_fail("��Ŀǰ�����������Լ�Ԧ"+ob->name()+"��\n");
		}
	}

        if( ob->wield(flag) ) /* If flag == 1,ֱ�ӽ�����װ��������. */
	{
                if( !stringp(str = ob->query("wield_msg")) )
                        str = "$Nװ��$n��������\n";
                message_vision(str, me, ob);
                return 1;
        }

	else
                return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��wield <װ������>
          wield -l <װ������>

���ָ������װ��ĳ����Ʒ������, �����Ҫӵ��������Ʒ.
�Ƚ�����������һ�㻹��Ҫ��߱���ĳЩ��������װ����
���ʹ���� '-l' ��������ָ���ı���װ�������֣�ǰ����
�������ǿյģ����ұ�����˫�ֶ���ʹ�õı�����

HELP
    );
    return 1;
}
