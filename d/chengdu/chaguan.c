// Room: /wiz/louth/c/chaguan.c

inherit ROOM;

void create()
{
	set("short", "茶馆");
	set("long", @LONG
这里是成都的名茶馆。这里每天都由不同种类的茶，从蒙顶
黄芽、蒙顶石花、峨眉毛峰、青城雀舌、早白尖功夫到三花牌茉
莉花茶都有，茶客们一边喝茶一边聊天。成都平民泡茶馆是有名
的，从这里整天顾客盈门就能看出来。北面出门就是万明路。
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wmlu2",
]));
        set("objects",([
        __DIR__"npc/chunxier" : 1,
]));
	setup();
	replace_program(ROOM);
}
