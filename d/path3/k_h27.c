// Room: /d/path3/k_h27.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "���˶�");
	set("long", @LONG
����������˶��ˣ��ǹ���������Ҫ�ڰ�֮һ�����ڵ���λ
�õ�ԭ������ڶɣ�yell�����շѿɲ����ˡ������Ǹ���ʮ��
����ˣ�����������ʵ������������������ʲô���е������
Ȼ������ô���Ǯ�类�����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_h26",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(4);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫ������������\n");

	set("outdoors", "path3");
	setup();
}
