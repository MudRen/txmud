// dongting.c ����
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
        set("long",@LONG
������̤ѩɽׯ�Ķ��������붫������ֻ�����װڷ���һ����̴ľ��
�Ҿߣ���ʰ���˳���Ⱦ���Ҿ��ϰڷ���һЩ����ĹŶ����������������
�Ǹ�������������ʿ��������Ƕ����᷿��
LONG);

	set("exits",([
		"west" : __DIR__"zoulang4",
		"east" : __DIR__"donglang1",
		"north" : __DIR__"zhangfang",
		"south" : __DIR__"dongxiangfang",
	]));

        set("objects", ([
//               __DIR__"npc/jobdizi1" : 1,
        ]));

	setup();
	replace_program(ROOM);
}
