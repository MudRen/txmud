// Room: /u/w/wangs/b/kai47.c

inherit ROOM;

void create()
{
	set("short", "山南街");
	set("long", @LONG
相较而言，山南街比开封府的其它几条大街窄一点，这是因
为这一带原先是一片贫民窟，只是到最近几年，开封人民生活殷
实了这里才改成街道。如今这里早已经找不到一点当初平民窟的
影子了，青石铺成的大道笔直的伸向远处，两边都是鳞次栉比的
店铺。西面传来一阵伊伊呀呀的唱戏声，原来那里是一家戏院。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai50",
  "north" : __DIR__"kai43",
  "west" : __DIR__"kai48",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
