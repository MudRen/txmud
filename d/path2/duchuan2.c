// Room: /d/path2/duchuan2.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "小渡船");
	set("long", @LONG
这是一条很小的渡船。木头结构，可以容纳五六个人的样子
。站在上面遥遥晃晃，让人感觉很不塌实。
LONG
	);

	set(SAFE_ENV,1);
	set("no_clean_up",1);

	set_boat_master(__DIR__"npc/chuanjia");
	set_boat_bank1(__DIR__"hou_t10");
	set_boat_bank2(__DIR__"hou_t11");
	set_bank1_desc("黄河东岸");
	set_bank2_desc("黄河西岸");
	set_cross_msg("过黄河");

	setup();
}
