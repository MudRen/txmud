// Room: /u/w/wangs/b/kai104.c

inherit ROOM;

void create()
{
	set("short", "皮货店");
	set("long", @LONG
五色斑斓各种火狐大衣、紫貂风帽、白熊皮袄整齐地叠放在
店里的货架上，这些皮货都是来自东北苦寒之地，质量是绝对的
上乘，不过就是太贵了，一件平常的熊皮坎肩就要；四五十两银
子，寻常的百姓们是无缘问津了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai103",
]));
        set("objects",([
        __DIR__"npc/gaolaoban" : 1,
]));

	setup();
	replace_program(ROOM);
}
