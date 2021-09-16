// skills.c changed by hero

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��������" NOR,
	HIB "������" NOR,
	HIB "�������" NOR,
	CYN "�������" NOR,
	CYN "����似" NOR,
	CYN "�����뻯" NOR,
	HIC "�Ƿ��켫" NOR,
	HIC "һ����ʦ" NOR,
	HIW "��ɲ�" NOR,
	HIY "���ӹ���" NOR,
});

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "�����ž�" NOR,
	HIB "��֪һ��" NOR,
	HIB "������" NOR,
	HIB "����С��" NOR,
	CYN "�������" NOR,
	CYN "��Ȼ���" NOR,
	CYN "��Ȼ��ͨ" NOR,
	HIC "������˫" NOR,
	HIC "������" NOR,
	HIW "��ɲ�" NOR,
	HIY "������" NOR,
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob,couple_ob;
	mapping skl, lrn, map,marry;
	string *sname, *mapped;
	int i, canskills=0;

	seteuid(getuid());

	if(!arg)
		ob = me;
	else
	{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
	}

	if( mapp(marry = me->query("marry"))
	&& stringp(marry["id"]) && userp(ob) && ob!=me)
	{
		if(objectp(couple_ob = find_player(marry["id"])))
			canskills=1;
	}

	if( (ob != me)
	&& !wizardp(me)
	&& !ob->is_apprentice_of(me)
	&& !ob->query("skill_public")
	&& !me->is_apprentice_of(ob)
	&& (ob != couple_ob) )
		return notify_fail("ֻ��ʦͽ�������ϵ�����ܲ쿴���˵ļ��ܡ�\n");

	skl = ob->query_skills();

	if(!sizeof(skl))
	{
		write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}

	write( (ob==me ? "��" : ob->name()) +"Ŀǰ��ѧ���ļ��ܣ�\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );

	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++)
	{
		printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": CYN"��"NOR),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			(skl[sname[i]]+ob->modify_skill(sname[i])), (int)lrn[sname[i]],
		);
	}
	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 25;

	switch(type)
	{
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ : skills [<ĳ��>]

���ָ����������ѯ����ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ�������ϵ�Ķ���
�� skills ���Բ�֪�Է��ļ���״����

HELP
    );
    return 1;
}
