// Room: /d/shaolin/fangzhang1.c

inherit ROOM;

void create()
{
	set("short", "方丈禅房");
	set("long", @LONG
这里是少林寺的方丈禅房，一进门有一幅对联，屋中很是简
朴，除了一炉香和一个蒲团，空空如也。对面的墙上有一幅方丈
大师亲手写的“禅”字。从这里向南是青石甬道。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "couplet" : "      松室夜灯禅影静\n      莎庭春雨道心空\n",
  "对联" : "      松室夜灯禅影静\n      莎庭春雨道心空\n",
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yongdao4",
]));

	set("objects",([
	__DIR__"npc/fangzhang" : 1,
]));

	setup();
	replace_program(ROOM);
}
