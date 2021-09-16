// Room: /d/death/road2.c
 
inherit ROOM;
 
void create()
{
        set("short", "阎罗殿");
        set("long", @LONG
你现在正位於一间充满鬼气的大殿上，这里的光线十分阴暗，
但是你仍然可以很清楚地看见周遭的事物，大殿的北面是一张桌
案，上面堆满了厚大的书，桌案后面端坐一位绿脸的凶神。两旁
林立著数十根双人合抱的火红色圆柱，圆柱后面站著两排不知是
人还是鬼的黑影。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/death/road1",
]));

	set("objects",([
	__DIR__"npc/yanluo" : 1,
]));
	set("no_magic", 1);
        setup();
}