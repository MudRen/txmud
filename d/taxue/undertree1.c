// undertree.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "����֮��");
  set ("long", @LONG
һ�ø������ɵĴ�������ɡ�����ס����գ������ϴ�����������ܸ���
���м�����ЩС������������һ��ʯ̨���������һ��Χ���̣�ʯ̨��������
ʯ�ʡ���������һʯ����ʯ���Ͽ��š��Z��ڣ���������֡�
LONG);

        set("outdoors", "taxue");

        set("exits", ([
               "south" : __DIR__"chitang",
	]));
         
        setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_touch", "touch");
}

int do_touch(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="shibei" && arg!="bei") )
		return notify_fail("��Ҫ����ʲô��\n");
	if(me->is_busy())
		return notify_fail("���æ�����������������飡\n");
	if(me->query("class")!="taxue")	
		return notify_fail("���к�Ŀ�ģ��ܵ�̤ѩɽׯ��ʲô��\n");
	if(me->query("combat_exp") < 100000)	
		return notify_fail("�����ڹ������������ǻ�ȥ��̤ʵ�ص���ϰ�ɣ�\n");

	message_vision(HIG"ͻȻһ�������ķ紵����$N����Ϊ֮һ�����ڳ��������������\n"NOR, me);
        me->set("gin", me->query("max_gin"));
        me->set("kee", me->query("max_kee"));
        me->set("sen", me->query("max_sen"));

	me->start_busy(3);

	return 1;
}
