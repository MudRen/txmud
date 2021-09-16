// Room: /wiz/uudd/path2/k_s12.c

inherit ROOM;

void create()
{
	set("short", "村间叉路口");
	set("long", @LONG
这是村里的岔路口，不时有村民来来往往的走过。这里向北
延伸着一条石子小路，向西是一座小庙，向南也是一条石路隐约
可以看见路边有一两家店铺。东面可以看到一间小杂货铺。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"temple",
  "east" : __DIR__"k_s11",
  "south" : __DIR__"k_s15",
  "north" : __DIR__"k_s13",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
