// Room: /d/huashan/keng2.c

#include <ansi.h>

inherit ROOM;
inherit __DIR__"kuangkeng";

void create()
{
	set("short",HIC"���"NOR);
	set("long",@LONG
����һ���޴�Ŀ�ӣ���ɽ�����õ�����ʯ���Ǵ����￪�ɵġ�
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"keng3",
  "west" : __DIR__"keng1",
]));

	setup();
}
