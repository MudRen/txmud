// Room: /u/w/wangs/b/kai91.c

inherit ROOM;

void create()
{
	set("short", "牢房");
	set("long", @LONG
这是一间牢房，室内昏暗无光，只有借着一碗口大的小洞
射进来的余光，才使人视力模糊的依稀见物。室内并不暗潮，
甚至还有一张简陋的旧床，牢门是用一根根手臂粗的木棍做成
的，中间有许多的空隙，室外的光线可以射进来。门外却站了
两个三十左右的粗壮汉子守在门口，手持长矛。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai89",
]));

	setup();
	replace_program(ROOM);
}
