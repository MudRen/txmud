// Room: /d/jinghai/jhd19.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
靖海派书房的藏书之丰是举世公认的，这里不论诸子百家、
星像占卜还是武功密籍、水陆兵法全都应有尽有，尤其特别的是
你在这里还能找到东瀛文字的书籍，据说靖海派的开山祖师邓璨
为了摸清犯海的倭寇们的生活习性，曾经数次潜进扶桑，所以他
才能在对付倭寇的战争中战无不胜。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jhd17",
]));
        set("objects",([
        __DIR__"npc/master1" : 1,
        __DIR__"npc/puren" : 1,
]));


	setup();
	replace_program(ROOM);
}
