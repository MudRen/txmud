// Room: /wiz/louth/c/caifengpu.c

inherit ROOM;

void create()
{
	set("short", "裁缝铺");
	set("long", @LONG
这里是与李记绸庄齐名的成都裁缝铺。这个裁缝铺的特色刺
绣就是麻柳枕头，五光十色，极为丰富，形成端庄、活泼、素雅、
明艳的多样艺术风格。每年都有许多的收藏家来这里买上几个枕
头回家珍藏。从这里出去就是府道街。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fdjie5",
]));

	setup();
	replace_program(ROOM);
}
