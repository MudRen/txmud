// Room: /d/path2/hou_t10.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "�ɿ�");
	set("long", @LONG
�����ǻƺ����ζ����Ķɿڣ���ӿ�ĺ�ˮ�Ĵ��Ű��ߣ���ʱ
�����������졣һ����ֵ������������������һ����������
���εĺ�ˮЯ���Ź�����ɳ���۶��������ӵĻ�ֻ�ܺ�(yell)��
�ҹ������㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hou_t9",
]));

	set_boat_file(__DIR__"duchuan2");
	set_max_passenger(4);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫ���ƺӣ�����\n");

	set("outdoors", "path2");
	setup();
}
