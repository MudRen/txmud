// Room: huashan yujiantai by pian
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "御剑台");
	set("long", @LONG
这里是一个十来丈见方黄土堆就的高台，华山派弟子平时就
在这里练剑，台子中央是华山派的大旗(qi)。东边的路穿过花丛
通向院中央的石道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "westdown" : __DIR__"huacong2",
  "eastdown" : __DIR__"huacong1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "yingbi" : HIR"    一条紫龙盘旋云端，四下里祥云缭绕。
  
    下面有一行字：以气御剑，气为剑锋，是为剑气。
"NOR,
]));
	set("no_clean_up", 0);
	set("outdoors", "huashan_p");

	setup();
	replace_program(ROOM);
}