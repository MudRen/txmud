// Room: /d/path2/hou_t11.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "�ɿ�");
	set("long", @LONG
�����ǻƺ����������Ķɿڣ���ӿ�ĺ�ˮ�Ĵ��Ű��ߣ���ʱ
�����������졣һ����ֵ������������������һ����������
���εĺ�ˮЯ���Ź�����ɳ���۶��������ӵĻ�ֻ�ܺ�(yell)��
�ҹ������㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hou_t12",
]));

	set_boat_file(__DIR__"duchuan2");
	set_max_passenger(4);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫ���ƺӣ�����\n");

	set("outdoors", "path2");
	setup();
}
