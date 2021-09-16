// gudi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山谷底");
        set("long",@LONG
这里是峭壁下面的谷底，这里阳光稀少，脚下是一片很厚的草地，走
在上面软绵绵的。四周看上去高不可攀，怪石嶙峋，你心中不由一惊，要
不是这片厚厚的草堆垫着，再好的轻功也会摔得变成一堆肉泥。见到这里
这样的情景，你也不禁机伶伶打了几个冷颤。
LONG);

	set("outdoors","taxue");

	set("exits",([
                "west" : __DIR__"gudi1",
                "east" : __DIR__"gudi2",
	]));

	setup();
	replace_program(ROOM);
}