// Room: /d/path3/k_s20.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "�������α���");
	set("long", @LONG
�����ǳ������α�������ˮ���ĵ�����ܼ������˽��Ϳ���
�������ˣ����������ȥ��ȴ���������ҡ�������ֻ�м�ֻ�洬��
����һЩ���ص�������ڴ��㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_s19",
    "west" : __DIR__"k_s21",
]));

	set_boat_file("/d/path5/duchuan");
	set_max_passenger(8);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫ������������\n");

        set("cannot_build_home", 1);
        set("outdoors", "path3");
	setup();
}
