// Room: /u/w/wangs/b/kai10.c

inherit ROOM;

void create()
{
	set("short", "凉亭");
	set("long", @LONG
置身于此，风景秀丽的柳中河畔尽收眼底。往东望去，蜿蜒
秀美的柳中河柔和地拐了几道弯消失在沿何而建的高脚民居之中，
碧绿的河水上几叶扁舟悠闲地荡起一道道涟漪，像雁翅般斜拍在
岸边又碎成一片杂乱的波纹慢慢归于平静。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai16",
]));

        set("objects",([
        __DIR__"npc/xianren" : 1,
]));

	setup();
	replace_program(ROOM);
}
