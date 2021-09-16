// Room: /wiz/louth/a/slroom1.c

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里
别无他物，只有中间放着一张收拾得舒舒服服的大床，看着
就让人想睡觉。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yu45",
]));
        set("sleep_room", 1);
        set(SAFE_ENV,1);

	setup();
	replace_program(ROOM);
}
