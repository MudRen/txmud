// dating.c ����
// feng

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIG"����"NOR);
        set("long",@LONG
�������̤ѩɽׯ�������������ϣ�����һ�۾Ϳ��Կ���ǽ����һ��
�ֻ���������׵�<<������>>�����ɷǷ���������ĳЩϲ������ӣ�����
�ͻ��ŵƽӲʣ������ϯ��
LONG);

	set(SAFE_ENV, 1);
	set("valid_startroom",1);

	set("exits",([
		"south" : __DIR__"huayuan",
		"west"  : __DIR__"zoulang3",
		"east"  : __DIR__"zoulang4",
		"northeast" : __DIR__"zoulang2",
                 	]));

        set("objects", ([
                __DIR__"npc/master4" : 1,
        ]));

	setup();
	load_board("board_taxue");
}
