// zoulang4.c ����4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
        set("long",@LONG
վ�������ϣ����������߼����߶�ȥ���ڶ�����һ����ӣ����洫
������߳�ȵ�������������ǻ�������������̤ѩɽׯ�ĵ��Ӷ��ڴ˴���
ϰ�似��
LONG);

	set("outdoors","taxue");

	set("exits",([
		"west" : __DIR__"dating",
		"east" : __DIR__"dongting",
	]));

	setup();
	replace_program(ROOM);
}
