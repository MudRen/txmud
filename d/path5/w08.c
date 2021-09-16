// Room: /d/path5/w08.c

inherit ROOM;

void create()
{
	set("short", "澜沧江边");
	set("long", @LONG
这里就是著名的澜沧江了。你站在江西岸，看着滔滔的江水，
心中思绪万千。隔江望去，是一遍荒凉的高原小路。过了江，就
是川中的南坪镇了。岸边有一个木桩，上面紧紧的绑着一道绳索
通向江东岸。
LONG
	);
	set("item_desc",([
          "绳索":"
这是一条不知用什么做材料的绳索，但看上去十分结实。
过往金沙江的人们都是靠拉(pull)这条绳索，经过风吹日晒，
它的颜色已显得暗黑。 \n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "westup" : __DIR__"w09",
]));

        set("outdoors", "path5");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
