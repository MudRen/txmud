// Room: /u/w/wangs/b/kai50.c

inherit ROOM;

void create()
{
	set("short", "山南街");
	set("long", @LONG
相较而言，山南街比开封府的其它几条大街窄一点，这是因
为这一带原先是一片贫民窟，只是到最近几年，开封人民生活殷
实了这里才改成街道。如今这里早已经找不到一点当初平民窟的
影子了，青石铺成的大道笔直的伸向远处，两边都是鳞次栉比的
店铺。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"kai53",
  "north" : __DIR__"kai47",
  "west" : __DIR__"kai51",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
