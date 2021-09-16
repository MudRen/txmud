// Room: /u/w/wangs/b/kai175.c

inherit ROOM;

void create()
{
    set("short", "小酒馆");
	set("long", @LONG
要提起胡同里的这家小酒馆，几乎无人不知，无人不晓，尤
其那些在工地讨生活的年轻人，更是每天非到这家小酒馆打个转
不可，连他们自己也搞不清究竟是为了喝酒，还是为了去欣赏柜
台里老板娘那个标致的女儿。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai174",
]));

        set("objects",([
        __DIR__"npc/tbboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
