
inherit ROOM;

void create()
{
   set("short", "土坡");
	set("long", @LONG
这里是个土坡，这里有一两个丐帮的初级师傅
西面是吃东西的，东面是练武的，北面是改帮的重地。
向北可以开发中级师傅及任务区，密题区。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/wiz/gaoqi/gaibang/xiaolu1.c",
]));	setup();
}
