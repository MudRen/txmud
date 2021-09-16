// /cmds/std/xiadu.c
// ������������FOOD LIQUIT �͹�����ˮ����ˮ���¶�
// by Find.

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string poison,where,skill;
	int level,flag = 0;
	object target,ski_ob;

	if(!stringp(arg) || sscanf(arg,"%s in %s",poison,where) != 2)
		return notify_fail("��Ҫ��ʲô����ʲô����\n");

	if(where == "here")
	{
		target = environment(me);
		if(!target)
			return notify_fail("��Ҫ��ʲô�����¶���\n");
		// Ŀǰֻ�ǹ�ˮ�ĵط������¶���
		// ��ˮ�ĵط�һ�㶼�����ɵĳ���
		// ���ǹ��������õģ���ʱ�����¶���
		if(!target->query("resource/water"))
			return notify_fail("����"+target->query("short")+
				"�����¿��˿���û���ҵ������¶��ĵط���\n");
	}
	else
	{
		target = present(where,me);
		if(!target)
		{
			target = present(where,environment(me));
			flag = 1;
		}
		if(!target)
			return notify_fail("��Ҫ��ʲô�����¶���\n");
		if(!target->is_food() && !target->is_liquid())
			return notify_fail("��Ҫ��ʲô�����¶���\n");

		if(target->is_food())
		{
			if(!target->query("food_remaining"))
				return notify_fail(target->name()+"�Ѿ�ûʲô�ɳԵ��ˣ����˶�Ҳ�ǰ��¡�\n");
		}
		if(target->is_liquid())
		{
			if(!target->query("liquid/remaining"))
				return notify_fail(target->name()+"�Ѿ��Ѿ����ȿ��ˣ����˶�Ҳ�ǰ��¡�\n");
		}
	}

	if(!ski_ob = present(poison,me))
	{
		if(!skill = SKILL_D(poison))
			return notify_fail("��Ҫ��ʲô����\n");

		if(!ski_ob = find_object(skill))
			ski_ob = load_object(skill);
		if(!objectp(ski_ob))
			return notify_fail("��Ҫ��ʲô����\n");

		if(!level = me->query_skill(poison,1))
			return notify_fail("�㻹����"+to_chinese(poison)+"�����书��\n");
		if(!function_exists("drug_in_object",ski_ob))
			return notify_fail(to_chinese(poison)+"������������Ʒ���¶���\n");
		// �ڹ��¶���Ҫһ����������
		if(me->query("force") < 300 || me->query("max_force") < 300)
			return notify_fail("��������������޷������ڱƳ����ء�\n");
		me->add("force",-150);
		me->add("max_force",-20);
	}

	else
	{
		if(!function_exists("drug_in_object",ski_ob))
			return notify_fail(ski_ob->name()+"������������Ʒ���¶���\n");
		// ��Ʒ�Ķ��������޵ģ��¹����ξ�û�ж����ˡ�
		// query_poison() �����������ش���Ʒ��ǰ�Ƿ��ж��ԡ�
		if(!ski_ob->query_poison())
			return notify_fail(ski_ob->name()+"�����Ѿ�û��ʲô�����ˡ�\n");
	}

	// �� skill �����д������������¶��߽����ж�
	// �����Ƿ����ʸ��¶�����Դ��˵��¶�������һ
	// Щ������������书�ȼ���Ρ�
	notify_fail("���"+to_chinese(poison)+"��Ϊ������û���¶���\n");
	if(function_exists("valid_xiadu",ski_ob)
	&& !ski_ob->valid_xiadu(me,level))
		return 0;

	if(target->is_room())
	{
		target->set("no_clean_up",1);
		// ����ˮԴ�ǻ�ˮ���µĶ���һ����ʱ�ޡ�

		if(!level)
			level = 50;
		target->set("drug/effect_time",time()+600+level*5);
		tell_object(me,"��Ѹ�ٵ���ˮ������һЩ����Ȼ��װ��һ���������µ����ӡ�\n");
	}

	else
	{
		target->stop_decay();	// �¶���ֹͣ decay
		tell_object(me,"��Ѹ�ٵ���"+target->name()+
			"������һЩ����Ȼ��װ��һ���������µ����ӡ�\n");
		if(flag)
			tell_room(environment(me),me->name()+"����"+target->name()+"���˿��ַ��˻�ȥ��\n");
	}

	target->set("drug/effect_func",(: call_other,base_name(ski_ob),"drug_in_object" :));
	return 1;
}

int help(object me)
{
	write(@HELP

ָ���ʽ�� xiadu <��> in <�ط�>

�����������ĳ�ֶ������ѧ��ĳ���ж����ڹ���
����ָ�����������ʳ�װˮ�����������Թ�
ˮ�ĵط��¶���

������Ϊ����ʹ�õĶ����������ѧ���ڹ�����

���磺
	�������º׶���Ķ�
	����Ȼ������Ҫ���к׶���(he dinghong)��
	xiadu he dinghong in leg

	��������ڵĵط����Թ�ˮ��
	��ѧ�д������ڹ�---�ƶ�(tangforce)��
	xiadu tangforce in here

���ڹ��Ŷ���Ҫ�й���һЩ���ڵĶ��رƳ�����
���¶�����������Ҫ��һЩ�𺦡�

HELP
);
	return 1;
}