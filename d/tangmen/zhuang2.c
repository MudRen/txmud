// Room: /d/tangmen/zhuang2.c

inherit __DIR__"zhuang";

void create()
{
	set("short", "÷��׮һ");
	set("long", @LONG
һ�˶�ߵ�÷��׮��������ȥ�������ľ�������
LONG
	);

	set("exits", ([
	"down" : __DIR__"lianwu",
	"west" : __DIR__"zhuang3",
	"southeast" : __DIR__"zhuang2",
]));
	set(SAFE_ENV, 1);
	setup();
}
