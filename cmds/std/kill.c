// kill.c
// Modified by Find.

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string callname;
	object *guards,ride;
	int i,num;
	mapping ey;

	if(environment(me)->query(SAFE_ENV))
		return notify_fail("���ﲻ׼ս����\n");
	if( !arg )
		return notify_fail("����ɱ˭��\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ� :P��\n");

	if( userp(obj) )
	{
		if(userp(me) && (me->query("age") <= PROTECT_AGE))
			return notify_fail("��ôС����������ɱ�ˣ��������˰ɡ�\n");
		if( obj->query("age") <= PROTECT_AGE )
			return notify_fail("��ôС�ĺ�����Ҳɱѽ�����Ƿ���һ����·�ɡ�\n");
	}

	if(mapp(ey = me->query("enyi_class"))
	&& sizeof(ey)
	&& (geteuid(obj) != ey["id"]) )
		return notify_fail("�����縺������ׯ�����У�ûʱ������������ء�\n");

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

        if(obj->query_temp("netdead"))
                return notify_fail("��С�Ӷ�����������������˵�ɡ�\n");

	if(obj->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(obj->query("gender"))+"���ϰ���"+
		gender_pronoun(obj->query("gender"))+"����أ���һ����ٺ�"+
		gender_pronoun(obj->query("gender"))+"ƴ���ɡ�\n"); // by Find.

	if(in_edit(obj) || in_input(obj) || obj->query_temp("netdead"))
		return notify_fail ("�����ѹ����ٿ���.\n");

	if(obj->query(NO_KILL) || obj->is_master())
		return notify_fail("��һ��㲻�ܶ����ǲ��ܶ���\n");

	if( ride = obj->query_temp("have_been_rided"))
	{
		if(ride == me)
			return notify_fail("���Լ������ﶼҪɱ��������ĳԲ��Ϸ��˰ɣ�\n");
	}

	if( !userp(obj) && !obj->accept_kill(me))
		return 0;

	callname = RANK_D->query_rude(obj);
	message_vision("\n$N����$n�ȵ�����" + callname + "�����ղ������������һ��\n\n", me, obj);

	me->kill_ob(obj);

/*
	if(userp(me)	// ��npc�� kill ����ᱻ׷��ɱ.
	&& !userp(obj)
	&& obj->query("race") == "����"
	&& !obj->is_master())
		obj->set_leader(me);
*/

	if(objectp(ride) && !userp(ride))
	{			
		message_vision("$N��$n�󺰣����Ҷ��ҵ�����������������\n",ride,me);
		ride->kill_ob(me);
                me->fight_ob(ride);
		ride->accept_first_kill(me);
	}

        if( arrayp(obj->query_temp("guarded")) )
        {
                num = sizeof(guards);
                if(num > 4)
                        num = 4;

                for(i=0;i<num;i++)
                {
                        if( guards[i]
                        && living(guards[i])
                        && (environment(guards[i]) == environment(obj)) )
                        {
                        if(guards[i]->query("gender") == "����")
                                message_vision( "$N��$n������"+( (obj->query("can_speak")) ?
                                                "���۸��ˣ�̫�������ӷ��������ˣ�\n\n" :
                                                "�򹷻�Ҫ�����ˣ����ӵĶ���Ҳ�Ҷ���\n\n")
                                                ,guards[i],me);
                        else
                                message_vision( "$N��$n������"+( (obj->query("can_speak")) ?
                                                "���۸��ˣ�̫����������������ˣ�\n\n" :
                                                "�򹷻�Ҫ�����ˣ�����Ķ���Ҳ�Ҷ���\n\n")
                                                ,guards[i],me);
                        me->kill_ob(guards[i]);
                        guards[i]->kill_ob(me);
			me->accept_first_kill(guards[i]);
                        }
                }
        }

	if(me->in_team())
	{
		object *all = me->query_team_member();

		all -= ({me});

		foreach(object ttt in all)
		{
			ttt->kill_ob(obj);
			obj->kill_ob(ttt);
		}
	}

	obj->kill_ob(me);
	if(userp(me) && userp(obj))
		obj->accept_first_kill(me);
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ��������ҡ���ɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
