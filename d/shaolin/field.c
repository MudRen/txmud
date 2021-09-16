// Room: /wiz/uudd/path2/field.c

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
这里是山脚下的一片辽阔的农田，土地被田垄分成一块块一
亩见方的方块，煞是整齐。几名农民正在田里埋头耕种，一个垂
髫小童正骑在牛背上放声歌唱。北面传来一阵呼喊之声，似是那
个孩子的母亲正在唤那个孩子回家吃饭。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_s10",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
