// ask.c
// modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$nҡҡͷ��˵����û��˵����\n",
	"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
	"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
	"$n˵������....���ҿɲ��������������ʱ��˰ɡ�\n",
	"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n"
});

int main(object me, string arg)
{
	string dest, topic;
	object ob;
	mixed msg,retn;
	mapping inquirys;

	if(me->query("channel/chat_block")
	&& (time()-me->query("channel/chat_block"))<0 )
		return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");

	seteuid(getuid());

	if( !arg
	|| ((sscanf(arg, "%s about %s", dest, topic) != 2)
	&& (sscanf(arg, "%s gy %s", dest, topic) != 2)) )
		return notify_fail("��Ҫ��˭ʲô�£�\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("����û������ˡ�\n");

	if( !ob->is_character() ) {
		message_vision("$N����$n��������....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") )
	{
		message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);

	if( !living(ob) )
	{
		message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n",
			me, ob);
		return 1;
	}

	if( userp(ob) ) return 1;

	if(topic == WILDCARD)
	{
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
		return 1;
	}

	// by Find.
	if( msg = ob->query("inquiry/" + topic,1) )
	{
		if( stringp(msg) )
		{
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}

		else if(functionp(msg))
		{
			retn = evaluate(msg,me); // �Ѷ�������Ϊ�������롣
			if(stringp(retn))
			{
				message_vision( CYN "$N˵����" + retn + "\n" NOR, ob);
				return 1;
			}
			else if(!retn)
			{
				message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
				return 1;
			}
			else
				return retn;
		}
	}

	else if( (topic == ob->name()) || topic == "name" )
		message_vision("$N����һ��$n˵�����Ҿ���$N������ʲô�£�\n",ob,me);

        else if( topic == "̤ѩ�޺�" || topic == "dicky" )
                message_vision("$N����һ��$n˵�����������������������������ʲô���أ�\n",ob,me);

	if(mapp(ob->query("family")))
	{
		if( topic == ob->query("family/family_name"))
		{
			message_vision("$N����˵��������"+topic+"����ͷ��������˭��������\n",ob);
			return 1;
		}
	}

	if( mapp(inquirys = ob->query("inquiry"))
	&& member_array(WILDCARD,keys(inquirys)) != -1 )
	{
		msg = ob->query("inquiry/" + WILDCARD,1);
		if( stringp(msg) )
		{
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}

		else if(functionp(msg))
		{
			retn = evaluate(msg,me,topic); // �Ѷ����˺�topic��Ϊ�������롣
			if(stringp(retn))
			{
				message_vision( CYN "$N˵����" + retn + "\n" NOR, ob);
				return 1;
			}
			else if(!retn)
			{
				message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
				return 1;
			}
			else
				return retn;
		}		
	}

	else
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

	return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: ask <ID> about <ĳ��>

	��ĳ�˹���ĳ�����顣
	���Լ�д��  wen <ID> gy <ĳ��>

���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
HELP
   );
   return 1;
}
