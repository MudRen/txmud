// selling_room.c
// by Find.

#include <ansi.h>

inherit ROOM;

#define MY_SAVE_ROOM	"/d/changan/save_room"

protected int MAX = 2000000000;
protected int valid_flag = 0, begin_time, busy, current_value, begin_value, no_accept;
protected object who_sell, selling_ob, save_room, current_buyer;
protected string channel_name = "���˽���";

int is_selling()
{
	if(no_accept)
		return 0;

	return ( who_sell && (environment(who_sell) == this_object()) && objectp(selling_ob));
}

protected void create()
{
	save_room = find_object(MY_SAVE_ROOM);
	if(!save_room)
		save_room = load_object(MY_SAVE_ROOM);
	if(!save_room)
		return;

	if(file_name(this_object()) == "/d/changan/selling_room")
		valid_flag = 1;
}

protected void refresh_objs()
{
	if(save_room)
		save_room->refresh_inv();

	if(current_buyer)
		current_buyer->delete_temp("be_in_sale_meeting_chu");
	current_buyer = 0;
	who_sell = 0;
	selling_ob = 0;
}

protected void stop_selling(int flag)
{
	switch(flag)
	{
		case 1:
			message("channel:psell",sprintf(HIY"\n��%s��������Ʒ��ʧ�����������ֹ��\n\n"NOR,
				channel_name), users());
			break;
		case 2:
			message("channel:psell",sprintf(HIY"\n��%s�����������뿪�����������ֹ��\n\n"NOR,
				channel_name), users());
			break;
		case 3:
			message("channel:psell",sprintf(HIY"\n��%s������%s�����������ֹ��\n\n"NOR,
				channel_name, current_buyer?who_sell->name()+"��ʱ���޷�����":"��ʱ������Ӧ��"),
				users());
			break;
		case 4:
			message("channel:psell",sprintf(HIY"\n��%s��������������ٿ�����ν��ױ���ֹ��\n\n"NOR,
				channel_name), users());
			break;

		default:
			message("channel:psell",sprintf(HIY"\n��%s��%sȡ��������%s�Ĵ��㡣\n\n"NOR,
				channel_name, who_sell->name(), selling_ob?selling_ob->name()+HIY:""),
				users());
	}

	if(objectp(selling_ob) && objectp(who_sell) && (environment(who_sell) == this_object()))
		selling_ob->move(who_sell);

	refresh_objs();
}

protected void do_continue()
{
	if(!selling_ob)
	{
		stop_selling(1);
		return;
	}

	if(!who_sell || (environment(who_sell) != this_object()))
	{
		stop_selling(2);
		return;
	}

	if(time() - begin_time > 120)
	{
		stop_selling(3);
		return;
	}

	call_out("do_continue",3);
}

protected int can_sell(object me)
{
	if(who_sell && (environment(who_sell) == this_object()) && objectp(selling_ob) && (me != who_sell))
		return 0;

	return 1;
}

protected int accept_sell_ob(object ob)
{
	if(!objectp(ob)
	|| !clonep(ob)
#ifdef WIZARD_FLAG
	|| ob->query_wiz_flag()
#endif
	|| is_money(ob)
	|| ob->is_food()
	|| ob->is_liquid()
	|| ob->is_corpse()
	|| ob->is_character()
	|| ob->query("no_drop")
	|| ob->query("no_sell")
	|| (base_name(ob) == "/obj/armor/cloth") )
		return 0;

	return 1;
}

protected void begin_selling(object me, object ob, int value)
{
	string msg;

	if(!save_room)
	{
		save_room = load_object(MY_SAVE_ROOM);
		if(!save_room)
		{
			tell_object(me, "�����޷��������������Ա���档\n");
			return;
		}
	}

	if(ob->is_weapon() || ob->is_armor())
		ob->unequip();
	if(!ob->move(save_room))
	{
		tell_object(me, "����������������\n");
		return;
	}

	who_sell = me;
	selling_ob = ob;
	begin_value = value;
	current_value = value;
	current_buyer = 0;
	begin_time = time();

	message("channel:psell",sprintf(HIY"\n��%s��%s��ʼ�����Լ���%s�����Ϊ %d ��������
%s�и���Ȥ������ <chu Ը����������> �����\n\n"NOR,
		channel_name, who_sell->name(1), 
		(msg = selling_ob->query_selling_msg())?sprintf("%s[%s]"+HIY,selling_ob->name(),msg):selling_ob->name()+HIY,
		begin_value, repeat_string(" ", sizeof(channel_name)+3)),
		users());

	call_out("do_continue",3);
}

void init()
{
	if(!valid_flag)
		return;
	add_action("do_sell", "sell");
	add_action("do_accept", "accept");
}

int do_sell(string arg)
{
	object me = this_player(), ob;
	int rtn, value;

	if(PAWN_D->query_being_meeting())
		return notify_fail("��������ڼ䲻�ܽ���˽�˽��ס�\n");

#ifdef WIZARD_FLAG
	if(wizardp(me))
		return notify_fail("��ʦ��������н��ס�\n");
#endif

	if(!can_sell(me))
		return notify_fail(sprintf("%s����������н��ף����һ�����\n", who_sell->name()));

	if(busy)
		return notify_fail("��æ���أ���һ�����\n");

	busy = 1;

	if(!stringp(arg) || !sizeof(arg))
	{
		busy = 0;
		return notify_fail("����ָ��ĸ�ʽ��sell ��Ʒ ��ʼ�۸�(��λ������)\n  ���磺sell sword 30\n  ���������Լ����ϵĽ�����ʼ�۸�Ϊ 20 ������\n\n");
	}

	if((arg == "stop") && (me == who_sell))
	{
		remove_call_out("do_continue");
		stop_selling(0);
		write("ok.\n");
		busy = 0;
		return 1;
	}

	if(me == who_sell)
	{
		busy = 0;
		return notify_fail(sprintf("�����������Լ���%s����Ҫȡ���������� sell stop��\n", selling_ob->name()));
	}

	if(sscanf(arg, "%s %d", arg, value) != 2)
	{
		busy = 0;
		return notify_fail("����ָ��ĸ�ʽ��sell ��Ʒ ��ʼ�۸�(��λ������)\n  ���磺sell sword 30\n  ���������Լ����ϵĽ�����ʼ�۸�Ϊ 20 ������\n\n");
	}

	if(value < 10)
	{
		busy = 0;
		return notify_fail("���ﲻ�ܽ�����ʼ�۸����� 10 ����������Ʒ��\n");
	}

	if(!arg || !objectp(ob = present(arg, me)))
	{
		busy = 0;
		return notify_fail("��Ҫ��ʲô��\n");
	}

	if(ob->query_credit_point_flag())	// ���õ���Ʒ
	{
		busy = 0;
		return notify_fail("�����������Ĳ�ֵ��\n");
	}

	if(!accept_sell_ob(ob))
	{
		busy = 0;
		return notify_fail("����������������\n");
	}

	if(!(rtn = player_pay(me, 200)) || (rtn == 2))
	{
		busy = 0;
		return notify_fail("ÿ�ʽ���Ҫ���� 2 �����ӵ������ѣ������ϵ�Ǯ������\n");
	}
	begin_selling(me, ob, value);

	busy = 0;
	return 1;
}

int valid_leave(object me, string dir)
{
	if(objectp(who_sell) && (me == who_sell))
	{
		remove_call_out("do_continue");
		stop_selling(2);
	}

	return 1;
}

int accept_chu(object me, int value)
{
	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID))
		return 0;

	if(!is_selling())
		return 0;

	if(me == who_sell)
		return notify_fail(sprintf("�����������Լ���%s����Ҫȡ���������� sell stop��\n", selling_ob->name()));

	if(me == current_buyer)
		return notify_fail("���ڵļ۸��������ģ���û���˳�������ߵļ۸�\n");

	if(current_buyer && (value <= current_value))
		return notify_fail(sprintf("��ĳ�������Ҫ���� %d �����������ʸ���\n", current_value));
	if(!current_buyer && (value < current_value))
		return notify_fail(sprintf("��ĳ�������Ҫ %d �����������ʸ���\n", current_value));

	if(!pay_from_bank(me,value*100,1))
		return notify_fail("��������Ŀǰû����ô���\n");

	message("channel:psell",sprintf(HIY"\n��%s��%s���� %d ����������%s��\n\n"NOR,
		channel_name, me->name(1), value, selling_ob->name()),
		users());

	if(objectp(current_buyer))
		current_buyer->delete_temp("be_in_sale_meeting_chu");

	current_buyer = me;
	current_value = value;

	return 1;
}

int do_accept()
{
	object me = this_player();

	if(!who_sell || !selling_ob || (who_sell != me))
		return 0;

	if(!current_buyer)
		return notify_fail("Ŀǰ��û���˳��۾�����Ҫȡ���������� sell stop��\n");

	no_accept = 1;

	message("channel:psell",sprintf(HIY"\n��%s��%s������%s�� %d �������ļ۸�����%s��\n\n"NOR,
		channel_name, me->name(1), selling_ob->name()+HIY, current_value, current_buyer->name(1)),
		users());

	if(!pay_from_bank(current_buyer,current_value*100,0))
	{
		no_accept = 0;
		notify_fail(sprintf("%s���д����ˡ�\n", current_buyer));
		current_buyer->delete_temp("be_in_sale_meeting_chu");
		current_buyer = 0;
		current_value = begin_value;
		return 0;
	}

	remove_call_out("do_continue");

	if(selling_ob->move(current_buyer))
		tell_object(current_buyer, "-->С����ܵ����ǰ˵��������������Ķ�����\n");
	else
	{
		selling_ob->move(environment(current_buyer));
		tell_object(current_buyer, "-->С����ܵ����ǰ˵��������������Ķ�������ŵ����ˡ�\n");
	}

	me->add("save_in_bank/silver", to_int(current_value*9/10));
	tell_object(me, sprintf("��Ķ��������� %d ����������ȥ�ٷ�֮ʮ�Ľ���˰��
������������浽��������˻����ˡ�\n", current_value));

	refresh_objs();

	no_accept = 0;
	return 1;
}

int clean_up()
{
	if(who_sell)
		return 1;

	return ::clean_up();
}

void begin_paimai_meeting()
{
	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID))
		return;

	remove_call_out("do_continue");
	stop_selling(4);
}
