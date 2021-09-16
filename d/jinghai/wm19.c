// Room: /d/jinghai/wm19.c

inherit ROOM;

void create()
{
	set("short", "兵器房");
	set("long", @LONG
这里是靖海派的兵器场，地下铺的是裁剪整齐的木块，踩在
上面吱吱做响。场子的右侧有一个兵器架。架子上面十八般兵刃
样样齐全。架子旁挂着数十副闪闪发光的盔甲，腰带，和战靴等
物。南边有一条小路，不知通到何方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wm10",
]));
        set("objects", ([
            __DIR__"obj/changmao"       : 2,
            __DIR__"obj/blade"       : 2,
            __DIR__"obj/sword"       : 2,
        ]));


	setup();
	replace_program(ROOM);
}
