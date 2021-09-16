// Room: /wiz/louth/c/guangbaosi.c

inherit ROOM;

void create()
{
	set("short", "宝光寺");
	set("long", @LONG
这是位于成都市北新都城内的宝光寺。它是我国南方四大佛
寺之一，始建于东汉，历经战火，几度重修，终成今日之规模。
全寺殿宇深幽，古木葱茏，五殿十六院层层递进，大雄宝殿东侧
的罗汉堂内有五百尊高约两米的彩绘贴金罗汉塑像，栩栩如生，
形神各异，绝无雷同，堪称艺术精品。南面是十字路口。
LONG
);

	set(SAFE_ENV, 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shizi",
]));
        set("objects",([
        __DIR__"npc/bonze" : 1,
]));

	setup();
	replace_program(ROOM);
}
