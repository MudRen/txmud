// xiting.c ����
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
        set("long",@LONG
������̤ѩɽׯ�Ӵ�������ѵĵط�����ͷ�輸�Ϸ�����ʱ�ʹ�����
ϸ��㣬͸�����˵�ϸ���ܵ����ٽ�̤ѩɽׯ����䣬�������װ��Ļ�
Ȼһ�¡����˺�Ѿ�߶���æ��æ����Ĵ����ߡ�
LONG);

	set("exits",([
		"east" : __DIR__"zoulang3",
		"westdown" : __DIR__"xilang2",
		"southwest" : __DIR__"shufang",
		"north" : __DIR__"xixiangfang",
	]));

        set("objects", ([
               __DIR__"npc/dizi2" : 1,
        ]));

	setup();
	replace_program(ROOM);
}
