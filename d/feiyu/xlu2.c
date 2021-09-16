// Room: /wiz/louth/a/xlu2.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一条曲折的林间小路，路旁是高大的白杨树，几缕阳光
从浓密的树叶间透射而下，一阵微风吹过，树叶沙沙作响。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"xlu1",
  "south" : __DIR__"zting",
  "southwest" : __DIR__"xlu3",
]));
        set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
