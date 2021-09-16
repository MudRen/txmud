// quest.c
// by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string clas;
	mapping quest;

	if(mapp(quest = me->query("enyi_class")) && sizeof(quest))
	{
		if( !quest["finish"] || (quest["finish"] != quest["id"]) )
		{
			write(sprintf("��Ŀǰ�ѽ����ˡ�����ɽׯ����ί��ȥ׷ɱ%s(%s)������\n",
				quest["name"], quest["id"]));
			return 1;
		}
		else
			return notify_fail(sprintf("���Ѿ�����ˡ�����ɽׯ��ί����׷ɱ%s�����Σ���ȥ����ɡ�\n", quest["name"]));
	}


	if(!(clas = me->query("class"))
	|| !mapp(quest = me->query(sprintf("quest/%s_quest",clas))) )
		return notify_fail("\n������û����Ҫȥ��������\n\n");

	write(sprintf("\n��Ŀǰ��������ȥ%s��%s����\n%s\n\n",
		quest["quest"],quest["name"],
		!undefinedp(quest["hint"])?sprintf("��ʾ��%s",quest["hint"]):"" ));

	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : quest
 
���ָ�������ʾ���㵱ǰ������
HELP
        );
        return 1;
}
