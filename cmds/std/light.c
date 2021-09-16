// /cmds/std/light.c
// by Find.

int main(object me,string arg)
{
	object env,ob;
	string light_verb,name;
	int i;

	if(!arg)
                return notify_fail("��Ҫ��ʲô��ȼ��\n");
	if(!(ob = present(arg,me)) || !ob->is_light_ob())
                return notify_fail("��Ҫ��ʲô��ȼ��\n");

	light_verb = ob->query("light_verb");
	if(!light_verb)
		light_verb = "��ȼ";

	i = ob->is_lighting();

	name = ob->query("name");
	if(i==1)
	{
		name = replace_string(name,light_verb+"��","");

		return notify_fail("�����е�"+name+"�Ѿ�"+light_verb+"�ˡ�\n");
	}

	if(i == -1)
		return notify_fail("�����е�"+name+"�Ѿ��������ˡ�\n");

	message_vision(sprintf("$N%s�����е�%s��\n",light_verb,name),me);

	if(!ob->do_light())
		return notify_fail("�����е�"+name+"�Ѿ��������ˡ�\n");

	env = environment(me);
	if(env->is_lightroom())
		env->add_dark_level(-1);

	name = ob->query("name");
	ob->set("long", sprintf("����һ%s�Ѿ�%s��%s��\n",
		ob->query("unit"),light_verb,name));
	ob->set("name",light_verb+"��"+name);
	ob->set("base_cname",name);

	if(me->is_fighting())
		me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : light <��Ʒ>
 
���ָ����������ȼ���ϵ���������ѡ��͵Ƶȡ�
 
HELP
    );
    return 1;
}
