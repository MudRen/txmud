// Room: /d/path3/k_h28.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "���˶��϶�");
	set("long", @LONG
�����ǳ����ϰ�������������ͨ������������ɣ���Ȼ�ڶ�
�Ѳ������ˡ�����������Ź���������˵�Ҵ�����������������
�����⡣��Ҫ��Ҳ���ɴ˹�����yell������ֻ�д����Ĵ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_h29",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(4);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫ������������\n");

	set("outdoors", "path3");

	setup();
}
