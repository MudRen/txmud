// fuji.c

// ����. By Find. (11/28/98)

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string *valid_domain;
	object who,env;
	mapping ey;

	valid_domain = ({
	"heifeng", "huashan", "mafeng", "paiyun", "path1",
	"path2", "path3", "path4", "path5", "path6", "shaowu", });

	if(!arg)
		return notify_fail("��Ҫ����˭��\n");

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(me->query("age") <= PROTECT_AGE)
		return notify_fail("��ôС������͸��������飬�Ժ���˵�ɡ�\n");

	if(!who = find_player(arg))
		return notify_fail("��Ϸ�����û����ô���ˡ�\n");
	if(who == me)
		return notify_fail("�㲻����Ҫ�������Լ��ɣ�\n");

	env = environment(me);
	if(!env)
		return notify_fail("���������Լ����Ķ���֪������ô�������ˣ�\n");

	if(env->is_player_home())
		return notify_fail("��"+((env->query("master_id") == me->query("id"))?"�Լ�":"����")
			+"�ļ�����ô�����������飿\n");

	if( env->query("invalid_fuji") )
		return notify_fail("�������Բ���\n");

	if( member_array(domain_file(base_name(env)),valid_domain) < 0 )
		return notify_fail("�˵ز��ʺϲ���������\n");

	if(!env->query("outdoors"))
		return notify_fail("�˴����Բ���������\n");

	if(who->query("age") <= PROTECT_AGE)
		return notify_fail("�Է�����̫С�������ڱ���֮�С�\n");

	if(mapp(ey = me->query("enyi_class"))
	&& sizeof(ey)
	&& (geteuid(who) != ey["id"]) )
		return notify_fail("�����縺������ׯ�����У�ûʱ������������ء�\n");

	write("����������ר���� "+who->name(1)+" �����������䲻���һ����\n");
	tell_room(env,me->name()+"���¿��˿����ߵ�·�Զ���������\n",({me}));

	me->start_busy(2);
	me->set_leader(0);
	me->delete_temp("guardling");
	me->set_temp("fuji_player",arg);
	me->set("env/invisibility",1);
	environment(me)->add("fuji/"+arg,({ me }));
	return 1;
}

int help(object me)
{
        write(@TEXT
ָ���ʽ��fuji <ĳ��>

��������������ڻĽ�Ұ�������
һ������֮������ĳ�ˣ��������
��ʱ������޷������㣬��Ϊ�˲�
��¶�Լ�Ҳ�кܶ����鲻�����ˣ�
һ�������������������ķ���Ȧ
�����������������ס�Է�ս����

������unfuji

�������� elon �ṩ���ش˸�л��
TEXT
        );
        return 1;
}