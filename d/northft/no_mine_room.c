// Room: /wiz/find/no_mine_room.c

#include <mine_def.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һƬ�޴�Ŀ���������һ���Ĵ��Ǿ޴����ʯ���ܶ�
��ʯ�ϻ����б������ҹ��ĺۼ������ϻ�ɢ����һЩ��ʯͷ��
LONG
	);

	setup();
}

int cmd_dig_function(object me, string arg)
{
	if(!me || (environment(me) != this_object()))
		return 0;

	if( me->query("kee") <= 20 )
		return notify_fail("���Ѿ��۵�û��һ�������ˡ�\n");

	message_vision("$N�������е�ʮ�ָ�ݺݵ�������ȥ��\n", me);
	me->start_busy(10);
	call_out("finish_dig", 3+random(3), me);
	return 1;
}

protected void finish_dig(object me)
{
	object stone;

	if(!me || (environment(me) != this_object()))
		return 0;

	me->stop_busy();

	if( me->query("kee") <= 20 )
	{
		tell_object(me, "���Ѿ��۵�û��һ�������ˡ�\n");
		return;
	}

	me->add("kee", -20);

	if((random(10) <= 3) || !objectp(stone = new(MINE_STONE)))
	{
		tell_object(me, "���ʲôҲû����������\n");
		return;
	}

	if(!stone->move(this_object()))
	{
		destruct(stone);
		return;
	}
	message_vision(sprintf("$N������һ��%s��\n", stone->name()), me);
}
