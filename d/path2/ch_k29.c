// Room: /d/path2/ch_k29.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "�ƺӶɿ�");
	set("long", @LONG
�����ǻƺ����α����Ķɿڣ���ӿ�ĺ�ˮ�Ĵ��Ű��ߣ���ʱ
�����������졣һ����ֵ������������������һ����������
�������ڣ��뵽���ӣ���ֻ�к�(yell)���ҹ��������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"ch_k28",
  "east" : __DIR__"an2",
  "west" : __DIR__"an1",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(4);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫ���ƺӣ�����\n");

	set("outdoors", "path2");
	setup();
}
