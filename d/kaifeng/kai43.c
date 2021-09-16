// Room: /u/w/wangs/b/kai43.c

inherit ROOM;

void create()
{
	set("short", "山南街");
	set("long", @LONG
相较而言，山南街比开封府的其它几条大街窄一点，这是因
为这一带原先是一片贫民窟，只是到最近几年，开封人民生活殷
实了这里才改成街道。如今这里早已经找不到一点当初平民窟的
影子了，青石铺成的大道笔直的伸向远处，两边都是鳞次栉比的
店铺。只听一声呼喝，几名少年骑着马从马店里直冲出来，霎时
间便去得远了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai47",
  "north" : __DIR__"kai40",
  "east" : __DIR__"kai45",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
