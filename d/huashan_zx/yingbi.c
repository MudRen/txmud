// Room: longbi1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "紫云影壁");
	set("long", @LONG
迎面一堵雕着紫云的影壁墙(yingbi)，影壁并不太高，但是
人站在这里，就算个子再高，也只能看见院子里房屋的顶子而矣。
就算是大门洞开，外面的人也丝毫看不见院子里面的情况。
    这里一片紫红，四周隐隐有一股强烈而炽热的力量。
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"doorgd",
  "west" : __DIR__"guodaow",
  "east" : __DIR__"guodaoe",
]));

	set("item_desc", ([ /* sizeof() == 1 */
  "yingbi" : HIR"    一条紫龙盘旋云端，四下里祥云缭绕。
  
    下面有一行字：以气御剑，气为剑锋，是为剑气。
"NOR,
]));

	set("valid_startroom", 1);
	set("outdoors", "huashan_zx");
	setup();
	load_board("board_huashan");
}
