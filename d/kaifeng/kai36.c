// Room: /u/w/wangs/b/kai36.c

inherit ROOM;

void create()
{
	set("short", "烤肉店");
	set("long", @LONG
店门口挂着一张布帘，上面用朱砂写着“铁板烤肉”四个大
字，你掀开门帘走了进来，一股诱人的油脂香气引得你食指大动，
店里的十来张桌子坐得满满的，直对着门的地方支着五个大火炉，
上面横着一块被烧得发红的铁板，烧肉的伙计在案板上飞快地把
一大块瘦肉片成巴掌般大小，扔进调料罐里滚了一滚，便倒在铁
板上烧得吱吱作响。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai64",
  "west" : __DIR__"kai34",
]));
        set("objects",([
        __DIR__"npc/rouboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
