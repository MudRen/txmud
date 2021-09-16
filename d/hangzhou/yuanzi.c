// Room: /d/hangzhou/yuanzi.c

inherit ROOM;

void create()
{
	set("short", "破旧大院");
	set("long", @LONG
这里本来是杭州林员外家的地产，因为盛传闹鬼，逐渐的荒
芜了，不知道什么时候开始，一些乞丐开始盘踞在这里。院子周
围横七竖八的堆放着一些垃圾，中间有一个大火盆，旁边还有一
口水井。
LONG
	);
	set("outdoors", "hangzhou");
	set("resource/water",1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"changane3",
]));

	setup();
	replace_program(ROOM);
}
