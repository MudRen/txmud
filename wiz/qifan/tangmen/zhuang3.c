// Room: /d/tangmen/zhuang3.c

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
	"east" : __DIR__"zhuang2",
	"southwest" : __DIR__"zhuang4",
]));
	set(SAFE_ENV, 1);
	setup();
}
