// Room: /d/huashan/xiaolu4.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一只赐息鸟在路边的树上冲着你吱吱地叫着，像是向你暗示
着什么。你左右看看，却什么也没发现。小路的边上长着一些紫
色的植物，中间有一条银色的东西。你仔细一看，原来是一条死
了的响尾蛇。向东有条小路通向紫霞宫的后门。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"lianhua_feng",
  "southdown" : __DIR__"juling_zu",
  "east":__DIR__"qitu1",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
