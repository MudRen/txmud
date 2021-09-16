// Room: /d/jinghai/moon12.c

inherit ROOM;

void create()
{
	set("short", "士卒营房");
	set("long", @LONG
你轻轻走进来，休息室的鼾声此起彼伏。因为水勇们轮班值
守，所以无论什么时候这里都有人在睡觉。为了安全起见，这里
没有一件兵器，以前就因为大家的兵器都随身携带，在这里为了
争床铺发生了多起流血事件。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"moon6",
]));
        set("objects",([
        __DIR__"npc/yong1" : 4,
        __DIR__"npc/duizhang" : 1,
]));


	setup();
	replace_program(ROOM);
}
