// whisper.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg, deny_id;
	object ob;

	if(me->query("channel/chat_block")
	&& (time()-me->query("channel/chat_block"))<0 )
		return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("��Ҫ��˭����Щʲ�᣿\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("��Ҫ��˭���\n");

	deny_id = (string)ob->query("env/no_tell");
	if( userp(me) && !wizardp(me) && (deny_id == "all" || deny_id == (string)me->query("id")) )
		return notify_fail(wizardp(ob)?"�Է����ڷ�չ���״̬���������� chat ������ϵ��\n":
			"�Է��� TELL Ƶ���ѹرա�\n");

	write( GRN "����" + ob->name() + "�Ķ�������˵����" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "��" + ob->name()
		+ "����С����˵��Щ����\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "����Ķ�������˵����" + msg + "\n" NOR);
	return 1;
}

int help(object me)
{
	write( @TEXT
ָ���ʽ��whisper <ĳ��> <ѶϢ>

���ָ�����������ͬһ�����е��˶������ NPC ���ڡ�
TEXT
	);
	return 1;
}
