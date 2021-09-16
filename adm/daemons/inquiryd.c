//	/adm/daemons/inquiryd.c

#include <ansi.h>

int parse_inquiry(object me, object ob, string topic)
{
	switch( topic )
	{
		case "name":
			message_vision( CYN "$N��$n�ʵ�������" + RANK_D->query_respect(ob)
				+ "���մ�����\n" NOR, me, ob);
			return 1;
		case "here":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "��" + RANK_D->query_self(me) + "�����󱦵أ���֪������Щʲ��������飿\n" NOR,
				me, ob);
			return 1;
		case "rumors":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "����֪�����û����˵ʲ����Ϣ��\n" NOR, me, ob);
			return 1;
		default:
			return 0;
	}
}
