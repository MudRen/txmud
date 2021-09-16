// beg.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	seteuid(getuid());

	if ( (!(myfam = me->query("family")) || myfam["family_name"] != "ؤ��") )
		return notify_fail("ֻ����ؤ�������֣�\n");

	if( environment(me)->query(SAFE_ENV) )
		return notify_fail("���ﲻ����л��������ַ��ĵط���\n");

        if( environment(me)->query("no_beg") )
                return notify_fail("�л��Ӳ������������֣�����ȥ�����ĵط��ɡ\n");

	if( me->query_temp("begging") )
		return notify_fail("���������˼������أ���̫̰�ˡ�\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("ָ���ʽ��beg <��Ʒ> from <����>\n");

	victim = present(who, environment(me));

	if( !victim || victim == me) return notify_fail("�������ֵĶ��������\n");

	if( !victim->is_character() || !living(victim) )
		return notify_fail("��Ҫ��˭���֣�\n");

	if( (vtfam = victim->query("family")) && vtfam["family_name"] == "ؤ��" )
		return notify_fail("�㲻������ؤ���֣�\n");

	if( wizardp(victim) )
		return notify_fail("��������ʦ���֡�\n");

	if( me->is_fighting() )
		return notify_fail("һ�ߴ��һ��Ҫ���������ǻ����ˣ�\n");

	if( victim->is_fighting() ) 
		return notify_fail(victim->name() + "���ڴ�ܣ�������û�����㣡\n");

	if(victim->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(victim->query("gender"))+"���ϰ���"+
		gender_pronoun(victim->query("gender"))+"����أ���һ����ٿ���"+
		gender_pronoun(victim->query("gender"))+"��ͬ���İɡ�\n"); // by Find.

	if (in_edit(victim) || in_input(victim) || victim->query_temp("netdead"))
		return notify_fail ("�����ѹ�����Ҫ��.\n");

	if( !ob = present(what, victim) )
	{
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "���Ͽ�����û��ʲ���������Ȥ�Ķ�����\n");
		ob = inv[random(sizeof(inv))];
	}

	if( ob->query("equipped") || ob->query("no_drop") )
		return notify_fail(ob->name()+"�����˵�����һ�϶�������㡣\n");

	sp = (int)me->query_skill("begging")*5+(int)me->query("kar")*5-(int)me->query("begger") * 2;
	if( sp < 1 ) sp = 1;
	dp = (int)victim->query("gin") + (int)victim->query("bellicosity")/20 - (int)victim->query("per")*5;
	if(dp <1) dp = 1;

	tell_object(me, "��װ�������Ͱ͵����ӣ���������" + victim->name() + "�߹�ȥ�����˫�֣���Ҫ"
		+ ob->query("unit") + ob->name() +"...\n\n");

	tell_object(victim, me->name() + "�����Ͱ͵����������߹���������֣�˵����" + RANK_D->query_respect(victim) + "���кã�����" 
		+ ob->query("unit") + ob->name() + "�� ...��\n\n");

	message("vision", "ֻ��" + me->name() + "װ�������Ͱ͵����ӣ���������" 
		+ victim->name() + "�߹�ȥ��\n���˫�֣�˵����"
		+ RANK_D->query_respect(victim) + "�����кð� ...\n\n", environment(me), ({ me, victim }) );

	me->set_temp("begging", 1);

	call_out( "compelete_beg", 3, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;
	object where = environment(me);

	me->delete_temp("begging");

	if( environment(victim) != environment(me) )
	{
		tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�\n");
		return;
	}

	if( living(victim) && (random(sp+dp) > dp) ) 
	{
		if ( ob->query("money_id") )
		{
			amount = ob->query_amount();
			if( amount < 5 )
			{
				tell_object(me, "���������߰ɣ���һ������Ѿ�û�ж�����ˮ��ե�ˡ�\n");
				return;
			}

			ob->set_amount(amount - amount/5);
			ob1=new("/obj/money/" + ob->query("money_id"));
			ob1->set_amount(amount/5);
			ob1->move(me);
		}

		else if( !ob->move(me) )
		{
			ob->move(where);
			tell_object(me, "���ֵ�һ" + ob->query("unit") + ob->name() 
				 + "�����Ƕ������̫���ˣ����ö��ڵ��¡�\n");
			ob->set("begging_object",1);
			return;
		}

		tell_object(me, victim->name() + "��ͷ����һ�ᣬ�ֿ��˿��㣬ҡҡͷ��̾�˿�����������һ" 
			 + ob->query("unit") + ob->name() + "��\n");
		tell_object(victim, "�㿴��" +  me->name() +"�Ŀ�������̾�˿�����������һ" 
			 + ob->query("unit") + ob->name() + "��\n");

		me->improve_skill("begging", 10+random(me->query("int"))+random(me->query_skill("begging",1)));
		me->add("combat_exp",10);
		me->add("potential",10);
		me->add_shimen_gongji(2);
		

		if( random(sp) < dp/2 )
		message("vision", "�㿴��" + victim->name() + "����" + me->name() + "������м��ҡҡͷ��"
			+ "������һ" + ob->query("unit")
			+ ob->name() + "��\n", environment(me), ({ me, victim }) );
		ob->set("begging_object",1);
		
		me->start_busy(3);
	}

	else 
	{
		if( random(sp) > dp/2 )
		{
			message_vision(victim->name() + "�ݺݵص���$Nһ�ۣ��ȵ������� $N����һ������æŤͷ��������߿��ˡ�\n", me);
			me->improve_skill("begging", 3);
			me->add("combat_exp",10);
			me->add("potential",3);
			return;
		}

		tell_object(me, victim->name() + "Ť��ͷȥ������������\n");
		tell_object(victim, "��Ť��ͷȥ����" + me->name() + "������\n");
		message("vision", victim->name() + "Ť��ͷȥ����" + me->name() + "������\n", 
			environment(me), ({ me, victim }) );
			me->improve_skill("begging", 2);
			me->add("combat_exp",6);
			me->add("potential",2);
		me->start_busy(2);
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : beg <ĳ��> from <ĳ��>
ֻ����ؤ���ܽ������֡�

HELP
    );
    return 1;
}
