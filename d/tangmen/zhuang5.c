// Room: /d/tangmen/zhuang5.c

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
	"northwest" : __DIR__"zhuang4",
	"east" : __DIR__"zhuang6",
]));
	set(SAFE_ENV, 1);
	setup();
}
