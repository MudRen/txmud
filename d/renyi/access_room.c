// Room: /d/enyi/access_room.c
// by Find.

/*
 * ���ܣ�
 *   1���쿴���б������ˡ���ָ���������ͽ�����
 *   2����ȡ����
 *   3���˻�����
 *   4������
 */

#include <renyi.h>

#undef IN_TEST
#define LIMIT_KILLER

inherit ROOM;

inherit __DIR__"die";

protected mixed *ran_name = ({
	({ "����", "xingren" }),
	({ "·��", "luren" }),
	({ "����", "shangren" }),
	({ "�̿�", "shangke" }),
	({ "����", "qingnian" }),
	({ "������", "zhongnian" }),
});

protected void create()
{
	set("short", "����ׯ�˷�");
	set("long", @LONG
����һ����տ��ķ��䣬ӭ�����������һλ��һ�߷���
�ʱ���һ�ߴ������̡�����վ��һλ������������ˣ������⣬
��ŭ�������ű�����һ�Ÿ�ʾ(paper)���Ѿ������ˡ�
LONG
	);

	set(SAFE_ENV, 1);

	set("exits", ([
	"west" : __DIR__"renyi1",
]));

	set("objects", ([
	__DIR__"npc/zz" : 1,
]));

	set("item_desc", ([
	"paper" : "
            ������ׯ��ʾ��

    �������·���������ɱ¾��һ��ФС֮��
�û���ѹ���ƣ��޶�������а����֮�գ���
������֮ʿ���ν���֮ʱ���϶���ϧ�ౡ֮����
ɢ���Ҳƣ�����������ׯ���������Ͷ����ƣ�
��������֮���塣

   check [id] : �쿴���Ͱ��ĳ�˵���
                �����

   accept ID  �����ܳ���һ����������
                ������

   tui        ���˻�����ȡ������

   award ID   �����ʶ�ĳ�˽�������

   wancheng   : ���������ȡ����


                    ----- ����ׯ�� ��
",
	"��ʾ" : "
            ������ׯ��ʾ��

    �������·���������ɱ¾��һ��ФС֮��
�û���ѹ���ƣ��޶�������а����֮�գ���
������֮ʿ���ν���֮ʱ���϶���ϧ�ౡ֮����
ɢ���Ҳƣ�����������ׯ���������Ͷ����ƣ�
��������֮���塣

   check [id] : �쿴���Ͱ��ĳ�˵���
                �����

   accept ID  �����ܳ���һ����������
                ������

   tui        ���˻�����ȡ������

   award ID   �����ʶ�ĳ�˽�������

   wancheng   : ���������ȡ����


                    ----- ����ׯ�� ��
",
]));
	setup();
}

protected string list_on_item(mixed *one, int wiz)
{
	string out = "";

	if(one && sizeof(one))
		out = sprintf("%-24s %s\t����%d���ƽ�%s\n",
			sprintf("%s(%s)",one[1],one[0]),
			sizeof(one[2])?sprintf("����%sѧ��",one[2]):"û�ܲ����������",
			one[3],
			sizeof(one[4])?(wiz?"\t"+one[4]:"\t��"):"");

	return out;
}

protected int sort_killer_award(mixed a, mixed b)
{
	if(a[3] > b[3])
		return -1;
	return 1;
}

void init()
{
	add_action("do_check", "check");	// �쿴�ͽ����
	add_action("do_accept", "accept");	// ����������
	add_action("do_return", "tui");		// �˻�����
	add_action("do_award", "award");	// ��������
	add_action("do_wancheng", "wancheng");	// �������
}

// �쿴�ͽ����
int do_check(string arg)
{
	object me = this_player();
	string out = "";
	int flag = wizardp(me);

	if(!arg || !sizeof(arg))
	{
		mixed *all;

		if( !sizeof(all = RENYI_D->query_killer_detail()) )
			return notify_fail("Ŀǰ��ׯ�����Ͱ��ϻ�û���κ��ˡ�\n");

		else
		{
			all = sort_array(all, "sort_killer_award", this_object());

			out = "                     ������ׯ���Ͱ�\n\n";
			foreach(mixed *tmp in all)
				out += list_on_item(tmp, flag);

			out += "\n";
			this_player()->start_more(out);
			return 1;
		}
	}

	else
	{
		mixed *one;

		if( !sizeof(one = RENYI_D->query_killer_detail(arg)) )
			return notify_fail("Ŀǰ��ׯ�����Ͱ��ϻ�û�д��ˡ�\n");

		out = sprintf("                     ������ׯ���Ͱ�\n\n%s", list_on_item(one[0], flag));

		write(out+"\n");

		return 1;
	}
}

// ����������
int do_accept(string arg)
{
	mapping ey;
	object me = this_player();
	string *apply;
	mixed *killer;

	if(me->query("combat_exp") <= MIN_XIAKE_EXP)
		return notify_fail("�书���߾���˼�������������屾ɫ������Ϊ�˰�ȫ�����Ժ���˵�ɡ�\n");

	if( (mapp(ey = me->query("enyi_class")) && sizeof(ey))
	|| RENYI_D->query_have_killer_quest(geteuid(me)) )
		return notify_fail("�����е�����û������أ���ȥ�ɡ�\n");

	if(!sizeof(arg))
		return notify_fail("��Ҫ���ܳ����ĸ��˵�����\n");

#ifdef IN_TEST
	if(!wizardp(me))
		return notify_fail("�����ڼ䣬��������ҽ�����\n");
#else
	if(wizardp(me))
		return notify_fail("��ʽ�����ڼ䣬��������ʦ������\n");
#endif

	switch(RENYI_D->accept_xiake_quest(arg, me))
	{
		case 1:
			if( !sizeof(killer = RENYI_D->query_killer_detail(arg)[0]) )
				return notify_fail("�����������ϳ����⣬�뷢�Ÿ�����Ա������\n");
			ey = allocate_mapping(7);
			apply = ran_name[random(sizeof(ran_name))];
			ey["id"] = killer[0];
			ey["name"] = killer[1];
			ey["class"] = killer[2];
			ey["award"] = killer[3];
			ey["a_name"] = apply[0];
			ey["a_id"] = apply[1];
			ey["time"] = time();
			me->set("enyi_class", ey);
			me->set_mask_name(ey["a_name"]);
			me->set_mask_id(ey["a_id"]);
			// ����ʱ��Ϊ 60 �죬Ҳ������ʵ����һ�죬86400��
			tell_object(me, sprintf("
ׯ������˵���������黬�ޱȣ�ҪС�Ĵ��£����򲻿ɵ������ģ�
    ������%s����%s��%s��%s�գ��Ϸ���㡺60�졻��
    ʱ�䣬���������ɣ��Ϸ��ί�б����ˣ�һ�������д�����
    ��ء�Ҫ����������ڻ��������Ϸ�(wancheng)������
    �����ڼ�Ҫר����������������������Ҫ�ܵ�һЩ���ơ�\n
", MUD_NAME, chinese_number(query_year()), chinese_number(query_month()), chinese_number(query_day_in_month())) );

			tell_object(me, sprintf("ׯ���߹����軭��һ������������һλ%s��\n\n", ey["a_name"]));
			me->save();
			return 1;
		case SAME_XID_KID:
			return notify_fail("�ں޵Ķ����Լ�ɱ���Լ�����ɱ���ıȽ����ס�\n");
		case NO_THIS_KILLER:
			return notify_fail("���Ͱ���û������ˡ�\n");
		case HAVE_KQUEST:
			return notify_fail("�Ͻ�ȥ��������ڵ�����ɡ�\n");
		case QUEST_BEEN_USE:
			return notify_fail("׷ɱ���˵����������������������˵�ɡ�\n");
		case GET_MAX_XIAKE_NUM:
			return notify_fail("�����Ѿ��в���������׷ɱ���������ˣ����һ��ʱ����˵�ɡ�\n");
		default:	// ���� 0
			return notify_fail("Ŀǰ�޷����������\n");
	}
}

// �˻�����
int do_return()
{
	object me = this_player();
	mapping ey;
	string kid;

	if(!mapp(ey = me->query("enyi_class")) || !sizeof(ey))
		return notify_fail("��Ŀǰû�ге�����ׯ������\n");

	if( stringp(kid = ey["finish"]) && (ey["id"] == kid) ) // �����
	{
		int gold;

		gold = RENYI_D->finish_renyi_quest(geteuid(me), ey["id"]);
		log_file("renyi", sprintf("%s(%s) �ɹ���׷ɱ�� %s%s\n", me->name(1), geteuid(me),ey["name"], ey["id"]));
		write(sprintf("ׯ�����˵�˵������ѽ��������ô�󹦶���Ҫ���ͣ�\n�� %d ���ƽ���������ׯ�����ˡ�\n",
			gold ));
		
	}
	else
	{
		if(!RENYI_D->return_xiake_quest(geteuid(me)))
			return notify_fail("����û�������񣬵�æ���⼸����˵��\n");

		tell_object(me, "ׯ��˵������˹��ȷ�����׶Ը���ֻ�е��Ժ���˵�ɣ���������\n");
	}

	me->delete("enyi_class");
	me->remove_mask_name();
	me->remove_mask_id();
	me->set_mask_name("İ����");
	me->set_mask_id("xiake");

	return 1;
}

protected void accept_award_gold(string str, object me, string killer)
{
	int n;

	if(!me || (environment(me) != this_object()) || !sizeof(killer))
		return;

	if(!sizeof(str))
	{
		tell_object(me, "��Ҫ�Դ������Ͷ������ƽ�(q �˳�)\n");
		input_to((: accept_award_gold:), me, killer);
		return;
	}

	if((str[0] == 'q') || (str[0] == 'Q'))
	{
		tell_object(me, "ok.\n");
		return;
	}

	if(!sscanf(str, "%d", n) || (n < 5))
	{
		tell_object(me, "ÿ����������Ҫ�����ƽ�\n��Ҫ�Դ������Ͷ������ƽ�(q �˳�)\n");
		input_to((: accept_award_gold:), me, killer);
		return;
	}

	if(n > 20000)
	{
		tell_object(me, "ÿ����������������ƽ�\n��Ҫ�Դ������Ͷ������ƽ�(q �˳�)\n");
		input_to((: accept_award_gold:), me, killer);
		return;
	}

	if(!pay_from_bank(me, n*10000,1))
	{
		tell_object(me, "��������û����ô����\n��Ҫ�Դ������Ͷ������ƽ�(q �˳�)\n");
		input_to((: accept_award_gold:), me, killer);
		return;
	}

	switch(RENYI_D->accept_award_gold(killer, n))
	{
		case 1:
			if(!pay_from_bank(me, n*10000))
			{
				tell_object(me, "��������û����ô����");
				log_file("enyi", sprintf("�������� %s ���ͽ���������� %d ���ƽ�\n", killer, n));
				return;
			}
			tell_object(me, "�ͽ��ѱ����ܡ�\n");
			return;
		case AWARD_GET_MAX:
			tell_object(me, "���˵��ͽ��Ѵﵽ����ޣ������������ˡ�\n");
			return;
		case GET_MAX_KILLER_NUM:
			tell_object(me, "Ŀǰ���������Ѿ������ˣ������������ˡ�\n");
			return;
		default:
			tell_object(me, "Ŀǰ�޷��������͡�\n");
			return;
	}
}

// ��������
int do_award(string arg)
{
	object me = this_player();

	if(!stringp(arg) || !sizeof(arg))
		return notify_fail("��Ҫ��˭���ͣ�\n");

#ifdef LIMIT_KILLER
	if(me->query("my_killer") != arg)
		return notify_fail("��ֻ�ܶ���ĳ������͡�\n");
#endif

	if(geteuid(me) == arg)
		return notify_fail("��Ҫ�������Լ���\n");

#ifndef IN_TEST
	if(wizardp(me))
		return notify_fail("���������ڼ䣬��������ʦ���롣\n");
	if(wiz_level(arg) > 0)
		return notify_fail("���Ҵ����ˣ���\n");
#endif

	switch(RENYI_D->check_valid_killer(arg))
	{
		case 1:
			write("��Ҫ�Դ������Ͷ������ƽ�(q �˳�)\n");
			break;
		case NO_THIS_USER:
			return notify_fail("û����ôһ���˴��ڡ�\n");
		case IN_PROTECTED:
			return notify_fail("�Է������ڱ��������䣬�������͡�\n");
		default:
			return notify_fail("��Ҫ��˭���ͣ�\n");
	}

	input_to((: accept_award_gold:), me, arg);
	return 1;
}

// �������
int do_wancheng()
{
	object me = this_player();
	mapping ey;
	int gold, n, bank;
	string out;

	if(!mapp(ey = me->query("enyi_class")) || !sizeof(ey))
		return notify_fail("�㲢û����ȡ��ׯ������\n");

	if(!ey["finish"] || (ey["finish"] != ey["id"]))
		return notify_fail(sprintf("�㲢û��ɱ����ׯҪ��ȥɱ��%s(%s)��\n", ey["name"], ey["id"]));

	gold = RENYI_D->finish_renyi_quest(geteuid(me), ey["id"]);

	me->remove_mask_name();
	me->remove_mask_id();
	me->set_mask_name("İ����");
	me->set_mask_id("xiake");

	if(gold <= 0)
		switch(gold)
		{
			case NO_THIS_KILLER:
				me->delete("enyi_class");
				me->save();
				return notify_fail("��ׯ�����Ͱ��ϲ�û�д��ˣ���˭�����������\n");
			case QUEST_BEEN_USE:
				me->delete("enyi_class");
				me->save();
				return notify_fail("��ׯ�Ĳ�û�а�������񽻴����㡣\n");
			default:
				return notify_fail("�������쳣������ʹ���޷���ȡ�����������Ա��������\n");
		}

	if(gold > 200000000)
		n = gold/10*8;
	else
		n = gold*8/10;

	bank = me->query("save_in_bank/gold");

	out = sprintf("
ׯ��Ц�ŵ��ͷ˵������%s��ȼ����ײ�֮ͽ����������
    ��������������̽��������������壬ǰ;����������
    ���˵��ͽ�һ�� %d ���ƽ𣬱�ׯ����һ������
    ��ά�ֵ������������һ�� %d ���ƽ�", ey["name"], gold, n);

	if(2100000000 - bank < n)
	{
		out += "��������
    ���治���ˣ���֪ͨ����Ա���㴦��\n\n";
		log_file("enyi", sprintf("%s(%s) �����˻����������� %d ���ƽ��޷���ȡ��\n",
			me->name(1), geteuid(me), n));
	}

	else
	{
		out += "��ת����
    �������ˡ�\n\n";
		me->add("save_in_bank/gold", n);
	}

	log_file("renyi", sprintf("%s(%s) �ɹ���׷ɱ�� %s%s\n", me->name(1), geteuid(me),ey["name"], ey["id"]));

	tell_object(me, out);

	me->delete("enyi_class");
	me->save();

	return 1;
}
